/* Copyright 2010 Smartmobili SARL
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include <CoreGraphics/CGImage.h>
#include <CoreGraphics/CGColorSpace.h>

#include "CGBasePriv.h"
#include "CGImagePriv.h"
#include "CGColorSpacePriv.h"

static CFTypeID _imageID = NULL;

/* CoreFoundation runtime class for CGPath.  */
static CFRuntimeClass CGImageClass =  {
    0,							/* version */
    "CGImage",					/* Name of class.  */
    0,							/* init */
    0,							/* copy  */
    CGImageDestroy,				/* finalize  */
	0,							/* equal  */
	0,							/* hash  */
	0,							/* copyFormattingDesc */
	0							/* copyDebugDesc */
  };
static CFTypeID __kCGImageID = _kCFRuntimeNotATypeID;

CFTypeID CGImageGetTypeID(void)
{	
	return CGTypeRegisterWithCallbacks(&__kCGImageID, &CGImageClass );
}

void CGImageDestroy(CFTypeRef ctf)
{
	CGImageRef image = (CGImageRef) (ctf);
	if (!image) { return ;}

	CGColorSpaceRelease(image->space);
	CGDataProviderRelease(image->provider);
	CGImageJPEGRepRelease(image->imageJPEGRep);
	CGImageEPSRepRelease(image->imageEPSRep);
	CGPathRelease(image->clipPath);
	free(image->decode);
	free(image->components);
	free(image->components2);
}

CGImageRef CGImageRetain(CGImageRef image)
{
	if (!image) { return 0; }
	return ((CGImageRef)CFRetain((CFTypeRef) image));
}

void CGImageRelease(CGImageRef image)
{
	if (!image) { return; }
	CFRelease((CFTypeRef)image);
}

void CGImageJPEGRepRelease(CGImageJPEGRepRef imageJPEG)
{
	if (!imageJPEG) { return; }
	
	imageJPEG->refcount--;
	if (imageJPEG->refcount == 0) {
	
		CGDataProviderRelease(imageJPEG->provider);
		free((void*)imageJPEG);
	}
}


CGImageJPEGRepRef CGImageJPEGRepRetain(CGImageJPEGRepRef imageJPEG)
{
	if (!imageJPEG) { return NULL; }
	imageJPEG->refcount++;
	return imageJPEG;
}


CGImageJPEGRepRef CGImageJPEGRepCreate(CGDataProviderRef provider)
{
	CGImageJPEGRepRef imageJPEG;

	imageJPEG = (CGImageJPEGRepRef)calloc(1, sizeof(CGImageJPEGRep));
	if (imageJPEG)
		imageJPEG->provider = CGDataProviderRetain(provider);

	return imageJPEG;
}

void CGImageEPSRepRelease(CGImageEPSRepRef imageEPS)
{
	if (!imageEPS) { return; }
	
	imageEPS->refcount--;
	if (imageEPS->refcount == 0) {
	
		CGDataProviderRelease(imageEPS->provider);
		CGImageRelease(imageEPS->image);
		free((void*)imageEPS);
	}
}

CGImageEPSRepRef CGImageEPSRepRetain(CGImageEPSRepRef imageEPS)
{
	if (!imageEPS) { return NULL; }
	imageEPS->refcount++;
	return imageEPS;
}

/*CFStringRef*/int32_t CGImageGetIdentifier(CGImageRef image)
{
	int32_t result;

	if (image)
		result = image->ID;
	else
		result = 0LL;

	return result;
}

int64_t CGImageGetSharedIdentifier(CGImageRef image)
{
	int64_t result;

	if (image)
		result = image->sharedID;
	else
		result = 0LL;

	return result;
}

Boolean valid_image_colorspace(CGColorSpaceRef space, CGBitmapInfo bitmapInfo)
{
	CGColorSpaceType spaceType;

	if (!space) { return FALSE; }

	spaceType = CGColorSpaceGetType(space);
	if (spaceType == 5)
		return TRUE;

	if (spaceType == 7) {
		if ((bitmapInfo & kCGBitmapAlphaInfoMask) == kCGImageAlphaPremultipliedFirst) {
			return TRUE;
		}
	}

	// ALWAYS RETURN TRUE FOR NOW
	return TRUE;
}



CGImageRef CGImageCreate(size_t width, size_t height,
						 size_t bitsPerComponent, size_t bitsPerPixel, size_t bytesPerRow,
						 CGColorSpaceRef space, CGBitmapInfo bitmapInfo, CGDataProviderRef provider,
						 const CGFloat decode[], bool shouldInterpolate,
						 CGColorRenderingIntent intent)
{
	CGImageRef image;
	size_t numComponents;
	int nSize;
	size_t i;

	if (!width || !height) {
		CGPostError("%s: invalid image size: %d x %d.", "CGImageCreate", width, height);
		return NULL;
	}

	if (bitsPerComponent == 32) {
		return NULL;
	}
	if (bitsPerPixel == 31) {
		return NULL;
	}

	// Check colorspace
	if (valid_image_colorspace(space, bitmapInfo)) {
		//invalid image colorspace
		return NULL;
	}
	numComponents = CGColorSpaceGetNumberOfComponents(space);
	if ((bitmapInfo & kCGBitmapAlphaInfoMask) >= kCGImageAlphaOnly) {
		return NULL;
	}
	
	if ((bitsPerComponent * numComponents != bitsPerPixel) ||
		(bytesPerRow != (width * bitsPerComponent * numComponents + 7)/8)) {
			CGPostError("%s: invalid image bits/pixel or bytes/row", "CGImageCreate");
			return NULL;
	}

	if (!provider) {
		CGPostError("%s: invalid image provider: NULL.", "CGImageCreate");
		return NULL;
	}
	
	nSize = sizeof(struct CGImage) - sizeof(CFRuntimeBase);
	image = (CGImageRef)CGTypeCreateInstance(CGImageGetTypeID(), nSize);
	if (!image) return NULL;
	
	image->ID = CGTypeGetNextIdentifier(&_imageID);
	image->width = width;
	image->height = height;
	image->bitsPerComponent = bitsPerComponent;
	image->bitsPerPixel = bitsPerPixel;
	image->bytesPerRow = bytesPerRow;
	image->space = CGColorSpaceRetain(space);
	image->bitmapInfo = bitmapInfo;
	image->provider = CGDataProviderRetain(provider);
	image->intent = intent;
	//image->flags = ?????????;

	if (decode) {
		image->decode = (CGFloat*)malloc(numComponents * 2 * sizeof(CGFloat));
		for (i = 0; i <  numComponents * 2; i++) {
			image->decode[i] = decode[i];
		}
	}

	return image;
}


CGImageRef CGImageCreateCopyWithJPEGSource(CGImageRef image, CGDataProviderRef provider)
{
	CGImageRef imageCopy;

	if (!image || !provider)
		return NULL;

	imageCopy = CGImageCreateCopy(image);
	if (imageCopy) {

		if (imageCopy->imageJPEGRep) 
			CGImageJPEGRepRelease(imageCopy->imageJPEGRep);
		
		imageCopy->imageJPEGRep = CGImageJPEGRepCreate(provider);	
	}

	return imageCopy;
}

CGImageRef CGImageMaskCreate(size_t width, size_t height,
							 size_t bitsPerComponent, size_t bitsPerPixel, size_t bytesPerRow,
							 CGDataProviderRef provider, const CGFloat decode[], bool shouldInterpolate)
{
	CGImageRef image;
	int nSize;

	if (bitsPerComponent >= 8) {
		return NULL;
	}
	if (bitsPerPixel < bitsPerComponent) {
		return NULL;
	}
	if (bytesPerRow != (((width * bitsPerPixel) + 7)/8)) {
		return NULL;
	}
	if (!provider) {
		return NULL;
	}

	nSize = sizeof(struct CGImage) - sizeof(CFRuntimeBase);
	image = (CGImageRef)CGTypeCreateInstance(CGImageGetTypeID(), nSize);
	if (!image) return NULL;

	image->ID = CGTypeGetNextIdentifier(&_imageID);
	image->width = width;
	image->height = height;
	image->bitsPerComponent = bitsPerComponent;
	image->bitsPerPixel = bitsPerPixel;
	image->bytesPerRow = bytesPerRow;
	image->space = NULL;
	image->bitmapInfo = 0;
	image->provider = CGDataProviderRetain(provider);
	image->intent = kCGRenderingIntentDefault;
	//image->flags = ?????????;

	if (decode) {
		image->decode = (CGFloat*)malloc(2 * sizeof(CGFloat));
		image->decode[0] = decode[0];
		image->decode[1] = decode[1];
	}

	return image;
}

CGImageRef CGImageCreateCopy(CGImageRef image)
{
	CGImageRef imageCopy;
	size_t numComponents;
	size_t i;

	if (!image)
		return NULL;

	if (CGImageIsMask(image) == TRUE) {

		imageCopy = CGImageMaskCreate(image->width, image->height, 
			image->bitsPerComponent, image->bitsPerPixel, 
			image->bytesPerRow,
			image->provider, 
			image->decode,
			(image->flags & kCGImageInterpolate));
	}
	else {

		imageCopy = CGImageCreate(image->width, image->height,
			image->bitsPerComponent,
			image->bitsPerPixel,
			image->bytesPerRow,
			image->space,
			image->bitmapInfo,
			image->provider,
			image->decode,
			(image->flags & kCGImageInterpolate),
			image->intent);
		if (imageCopy == NULL) { return NULL; }

		imageCopy->flags = image->flags;
		imageCopy->refs = CGImageRetain(image->refs);

		if (image->components != NULL) {

			numComponents = CGColorSpaceGetNumberOfComponents(imageCopy->space);
			imageCopy->components = (CGFloat*)malloc(numComponents*sizeof(float));
			for (i = 0; i < numComponents; i++) {
				imageCopy->components[i] = image->components[i];
			}
		}
		
		if (image->components2 != NULL) {
			numComponents = CGColorSpaceGetNumberOfComponents(imageCopy->space);
			imageCopy->components2 = (CGFloat*)malloc(numComponents*sizeof(float));
			if (!imageCopy->components2) {
				CGImageRelease(imageCopy);
				return NULL;
			}
			for (i = 0; i < numComponents; i++) {
				imageCopy->components2[i] = image->components2[i];
			}
		}
		
		imageCopy->imageJPEGRep = CGImageJPEGRepRetain(image->imageJPEGRep);
		imageCopy->imageEPSRep  = CGImageEPSRepRetain(image->imageEPSRep);
		imageCopy->clipPath = CGPathRetain(image->clipPath);
	}

	

	return imageCopy;
}

CGImageRef CGImageCreateWithJPEGDataProvider2(CGDataProviderRef source, 
											  CGColorSpaceRef space,
											  const CGFloat decode[], 
											  bool shouldInterpolate,
											  CGColorRenderingIntent intent)
{
	return NULL;
}

CGImageRef CGImageCreateWithJPEGDataProvider(CGDataProviderRef source, 
											 const CGFloat decode[], 
											 bool shouldInterpolate,
											 CGColorRenderingIntent intent)
{
	return CGImageCreateWithJPEGDataProvider2(source, NULL, decode, shouldInterpolate, intent);
}

CGImageRef CGImageCreateWithPNGDataProvider(CGDataProviderRef source,
											const CGFloat decode[],
											bool shouldInterpolate,
											CGColorRenderingIntent intent)
{
	return NULL;
}

CGImageRef CGImageCreateWithImageInRect(CGImageRef image, CGRect rect)
{
	if (!image || !image->imageEPSRep)
		return NULL;

	return NULL;
}


CGImageRef CGImageCreateWithMask(CGImageRef image, CGImageRef mask)
{
	return NULL;
}

CGImageRef CGImageCreateWithMaskingColors(CGImageRef image,const CGFloat components[])
{
	return NULL;
}

CGImageRef CGImageCreateCopyWithColorSpace(CGImageRef image,CGColorSpaceRef space)
{
	CGImageRef imageRef;

	if (!image || !space)
		return NULL;
	
	if ((image->flags & kCGImageMask))
		return NULL;
	
	if (CGColorSpaceGetNumberOfComponents(image->space) != CGColorSpaceGetNumberOfComponents(space))  {
		return NULL;
	}
	
	if (valid_image_colorspace(space, image->bitmapInfo) == FALSE) {
		return NULL;
	}

	if (image->space == space) {
		imageRef = CGImageRetain(image);
	}
	else {
		imageRef = CGImageCreateCopy(image);
		if (imageRef) {
			CGColorSpaceRelease(imageRef->space);
			imageRef->space = CGColorSpaceRetain(space);
		}	
	}

	return imageRef;
}


CGPathRef CGImageGetClipPath(CGImageRef image)
{
	if (!image) { return 0; }
	return image->clipPath;
}


bool CGImageIsMask(CGImageRef image)
{
	if (!image) { return 0; }
	return (image->flags & kCGImageMask);
}

size_t CGImageGetWidth(CGImageRef image)
{
	if (!image) { return 0; }
	return (image->width);
}

size_t CGImageGetHeight(CGImageRef image)
{
	if (!image) { return 0; }
	return (image->height);
}

size_t CGImageGetBitsPerComponent(CGImageRef image)
{
	if (!image) { return 0; }
	return (image->bitsPerComponent);
}



size_t CGImageGetBitsPerPixel(CGImageRef image)
{
	if (!image) { return 0; }
	return (image->bitsPerPixel);
}

size_t CGImageGetBytesPerRow(CGImageRef image)
{
	if (!image) { return 0; }
	return (image->bytesPerRow);
}

CGColorSpaceRef CGImageGetColorSpace(CGImageRef image)
{
	if (!image) { return 0; }
	return (image->space);
}

CGImageAlphaInfo CGImageGetAlphaInfo(CGImageRef image)
{
	if (!image) { return kCGImageAlphaNone; }
	return ((CGImageAlphaInfo)(image->bitmapInfo & kCGBitmapAlphaInfoMask)); 
}

CGDataProviderRef CGImageGetDataProvider(CGImageRef image)
{
	if (!image) { return 0; }
	return (image->provider); 
}

const CGFloat *CGImageGetDecode(CGImageRef image)
{
	if (!image) { return 0; }
	return (image->decode);
}

bool CGImageGetShouldInterpolate(CGImageRef image)
{
	if (!image) { return 0; }
	return (image->flags & kCGImageInterpolate);
}

CGColorRenderingIntent CGImageGetRenderingIntent(CGImageRef image)
{
	if (!image) { return kCGRenderingIntentDefault; }
	return (image->intent);
}

CGBitmapInfo CGImageGetBitmapInfo(CGImageRef image)
{
	if (!image) { return 0; }
	return (image->bitmapInfo);
}