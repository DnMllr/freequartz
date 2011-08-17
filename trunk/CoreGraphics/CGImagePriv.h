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
#ifndef CGIMAGEPRIV_H_
#define CGIMAGEPRIV_H_

#include <CoreFoundation/CFRuntime.h>
#include <CoreGraphics/CGPath.h>

#include "CGMacros.h"
#include "CGColorSpacePriv.h"

CF_EXTERN_C_BEGIN

enum {
    kCGImageInterpolate = 0x01,
    kCGImageMask		= 0x10,
};

/* forward declarations */
typedef struct CGImage CGImage, *CGImageRef;
typedef struct CGImageJPEGRep CGImageJPEGRep, *CGImageJPEGRepRef;
typedef struct CGImageEPSRep CGImageEPSRep, *CGImageEPSRepRef;

struct CGImageJPEGRep {

	signed long refcount;			//0x00
	CGDataProviderRef provider;		//0x04
};

struct CGImageEPSRep {

	signed long refcount;			//0x00
	CGDataProviderRef provider;		//0x04
	CGImageRef image;				//0x08
};


struct CGImage {

	CFRuntimeBase obj;				//0x00
	CFTypeID ID;					//0x08
	size_t width;					//0x0C
	size_t height;					//0x10
	size_t bitsPerComponent;		//0x14
	size_t bitsPerPixel;			//0x18
	size_t bytesPerRow;				//0x1C
	CGColorSpaceRef space;			//0x20
	CGBitmapInfo bitmapInfo;		//0x24
	CGDataProviderRef provider;		//0x28
	CGColorRenderingIntent intent;	//0x2C
	CGFloat* decode;				//0x30
	uint32_t flags;					//0x34
	CGFloat* components;			//0x38
	CGImageRef refs;				//0x3C
	CGFloat* components2;			//0x40
	CGImageJPEGRepRef imageJPEGRep;	//0x44
	CGImageEPSRepRef imageEPSRep;	//0x48
	CGPathRef clipPath;				//0x4C
	int64_t sharedID;				//0x50

};






void	CGImageDestroy(CFTypeRef ctf);
Boolean valid_image_colorspace(CGColorSpaceRef space, CGBitmapInfo bitmapInfo);

CGImageRef CGImageCreateCopyWithJPEGSource(CGImageRef image, CGDataProviderRef provider);

CGImageJPEGRepRef CGImageJPEGRepRetain(CGImageJPEGRepRef imageJPEG);
void CGImageJPEGRepRelease(CGImageJPEGRepRef imageJPEG);
CGImageJPEGRepRef CGImageJPEGRepCreate(CGDataProviderRef provider);

CGImageEPSRepRef CGImageEPSRepRetain(CGImageEPSRepRef imageEPS);
void CGImageEPSRepRelease(CGImageEPSRepRef imageEPS);

CGPathRef CGImageGetClipPath(CGImageRef image);

int64_t CGImageGetSharedIdentifier(CGImageRef image);

CF_EXTERN_C_END

#endif /* CGIMAGEPRIV_H_ */


