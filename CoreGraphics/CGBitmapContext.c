/****************************************************************************
**
** Copyright (C) 2010 Smartmobili.
** All rights reserved.
** Contact: Smartmobili (contact@smartmobili.com)
**	
** This file is part of the CoreGraphics module of the freequartz Toolkit.
**
**
** GNU Lesser General Public License Usage	
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements	
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
****************************************************************************/
#include <CoreGraphics/CGBitmapContext.h>
#include <pthread.h>
#include "CGBitmapContextPriv.h"
#include "CGDataProviderPriv.h"
#include "CGLibraryPriv.h"

static pthread_once_t	bitmap_delegate_once = PTHREAD_ONCE_INIT;
static _CGBitmapContextDelegateCreate CGBitmapContextDelegateCreate = NULL;


void 
loadBitmapContextDelegateCreator(void)
{
	_CGBitmapContextDelegateCreate bitmapContextDelegate;

	CGBitmapContextDelegateCreate = 
		(_CGBitmapContextDelegateCreate)(void *)CGLibraryLoadFunction("RIP", "__CGBitmapContextDelegateCreate");
	
	if (CGBitmapContextDelegateCreate) {
		CGBitmapContextDelegateCreate = bitmapContextDelegate;
	}
	else {
		CGPostError("Failed to load bitmap context.");
	}
}

static CGContextDelegateRef 
__CGBitmapContextDelegateCreate(CGBitmapContextInfoRef bitmapContextInfo, 
								CFDictionaryRef theDict)
{
	CGContextDelegateRef ctxDelegate;

	if (CGBitmapContextDelegateCreate == NULL)
		pthread_once(&bitmap_delegate_once, loadBitmapContextDelegateCreator);
	
	if (CGBitmapContextDelegateCreate)
		ctxDelegate = CGBitmapContextDelegateCreate(bitmapContextInfo, theDict);
	else
		ctxDelegate = NULL;
	
	return ctxDelegate;
}

CGBitmapContextInfoRef
CGBitmapContextInfoCreate(void *data, size_t width, size_t height, size_t bitsPerComponent, 
						  size_t bitsPerPixel, size_t bytesPerRow,
						  CGColorSpaceRef colorspace, CGBitmapInfo bitmapInfo, 
						  void* alphaData, Boolean b, Boolean c, Boolean d,Boolean e,
						  CGFloat hRes, CGFloat vRes)
{
	CGBitmapContextInfoRef bitmapCtxInfo;
	CGColorSpaceType csType;
	bool isValid; 
	size_t numberOfComponents;

	bitmapCtxInfo = (CGBitmapContextInfoRef)calloc(1, sizeof(CGBitmapContextInfo));
	if (!bitmapCtxInfo) { 
		goto Error; 
	}
	
	bitmapCtxInfo->refcount = 1;

	if ((bitmapInfo & kCGBitmapAlphaInfoMask) != kCGImageAlphaOnly) {
		bitmapCtxInfo->colorspace = CGColorSpaceRetain(colorspace);
	}
	else {
		bitmapCtxInfo->colorspace = NULL;
	}
	bitmapCtxInfo->bitmapInfo = bitmapInfo;
	bitmapCtxInfo->dataAllocated = FALSE;
	bitmapCtxInfo->data = NULL;
	bitmapCtxInfo->bytesPerRow = CGBitmapGetAlignedBytesPerRow((width * bitsPerPixel + 7) / 8);

	csType = CGColorSpaceGetType(bitmapCtxInfo->colorspace);
	switch(csType)
	{
	case kCGColorSpaceTypeDeviceUnknown: 

		break;
	
	case kCGColorSpaceTypeDisplayGray:
	case kCGColorSpaceTypeDeviceGray:
		isValid = validate_gray_bitmap_info(bitmapCtxInfo);
		break;

	case kCGColorSpaceTypeDisplayRGB:
	case kCGColorSpaceTypeDeviceRGB:
		isValid = validate_rgb_bitmap_info(bitmapCtxInfo);
		break;
	
	case kCGColorSpaceTypeDeviceCMYK:
		isValid = validate_cmyk_bitmap_info(bitmapCtxInfo);
		break;

	case kCGColorSpaceTypePattern:
		numberOfComponents = CGColorSpaceGetNumberOfComponents(bitmapCtxInfo->colorspace);
		if (numberOfComponents == 3)
			isValid = validate_rgb_bitmap_info(bitmapCtxInfo);
		else if (numberOfComponents == 4)
			isValid = validate_cmyk_bitmap_info(bitmapCtxInfo);
		else if (numberOfComponents == 1)
			isValid = validate_gray_bitmap_info(bitmapCtxInfo);
		break;
	};

	bitmapCtxInfo->data = CGBitmapAllocateData(bitmapCtxInfo->bytesPerRow * height);
	if (bitmapCtxInfo->data == NULL) {
		CGPostError("%s: unable to allocate %zu bytes for bitmap data",
			"CGBitmapContextInfoCreate", bitmapCtxInfo->bytesPerRow * height);
		goto Error;
	}
	bitmapCtxInfo->dataAllocated = TRUE;

	return bitmapCtxInfo;
Error:
	release_bitmap_info(bitmapCtxInfo);
	return NULL;
}


bool
validate_rgb_bitmap_info(CGBitmapContextInfoRef bitmapContextInfo)
{
	return TRUE;
}

bool
validate_gray_bitmap_info(CGBitmapContextInfoRef bitmapContextInfo)
{
	return TRUE;
}

bool
validate_cmyk_bitmap_info(CGBitmapContextInfoRef bitmapContextInfo)
{
	return TRUE;
}

void 
finalize_bitmap_context(CGContextRef context)
{
	if (!context || context->contextType != kCGContextTypeBitmap)
		return;

	release_bitmap_info(context->bitmapContextInfo);
}

void
release_bitmap_info(CGBitmapContextInfoRef bitmapInfo)
{
	if (!bitmapInfo || !bitmapInfo->refcount )
		return;

	bitmapInfo->refcount--;
	if (bitmapInfo->refcount == 0)
	{
		CGColorSpaceRelease(bitmapInfo->colorspace);
		
		if (bitmapInfo->dataAllocated == TRUE)
			CGBitmapFreeData(bitmapInfo->data);
		
		if (bitmapInfo->alphaAllocated == TRUE)
			CGBitmapFreeData(bitmapInfo->alphaData);

		free(bitmapInfo);
	}

	return;
}

void
CGBitmapFreeData(void *data)
{
	if (!data)  { return; }

#if defined(DEPLOYMENT_TARGET_WINDOWS)

	VirtualFree(data, 0, MEM_RELEASE);

#else

#endif
}


void * 
CGBitmapAllocateData(size_t len)
{
	void* data;

#if defined(DEPLOYMENT_TARGET_WINDOWS)

	data = VirtualAlloc(NULL, len, MEM_RESERVE, PAGE_READWRITE);

#elif defined

	//#define VM_MAKE_TAG(tag) ((tag) << 24)
	//0x34000000 = VM_MAKE_TAG(VM_MEMORY_CGIMAGE)
	//void *  mmap(void *addr, size_t len, int prot, int flags, int fildes, off_t offset);
	//data = mmap(NULL, len, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, 0, 0);

#endif

	return data;
}


CGContextRef 
CGBitmapContextCreate(void *data, size_t width,
					  size_t height, size_t bitsPerComponent, 
					  size_t bytesPerRow,
					  CGColorSpaceRef colorspace, 
					  CGBitmapInfo bitmapInfo)
{
	

	size_t numberOfComponents; 
	size_t bitsPerPixel;
	CFDictionaryRef dict = NULL;

	bitsPerPixel = 16;

	// Here for once we want to know numberOfComponents + alpha if there is one
	numberOfComponents = CGColorSpaceGetNumberOfComponents(colorspace);
	if (((bitmapInfo & kCGBitmapAlphaInfoMask) != kCGImageAlphaNone) &&
		((bitmapInfo & kCGBitmapAlphaInfoMask) != kCGImageAlphaOnly) )
		numberOfComponents += 1;

	if ( bitsPerComponent != 5 )
	{
		bitsPerPixel= bitsPerComponent;
		if ( numberOfComponents )
			bitsPerPixel = numberOfComponents * bitsPerComponent;
	}

	return CGBitmapContextCreateWithDictionary(
		data,
		width,
		height,
		bitsPerComponent,
		bitsPerPixel,
		bytesPerRow,
		colorspace,
		bitmapInfo,
		72.0,
		72.0,
		dict);
}


CGContextRef
CGBitmapContextCreateWithDictionary(void *data, size_t width,
									size_t height, size_t bitsPerComponent,
									size_t bitsPerPixel, size_t bytesPerRow,
									CGColorSpaceRef colorspace, 
									CGBitmapInfo bitmapInfo, 
									CGFloat hRes, CGFloat vRes, 
									CFDictionaryRef theDict)
{

	CGContextRef context;
	CGBitmapContextInfoRef bitmapCtxInfo;

	bitmapCtxInfo = CGBitmapContextInfoCreate( data, width, height, bitsPerComponent, 
		bitsPerPixel, bytesPerRow, colorspace, bitmapInfo, 0,0,0,0,0, hRes, vRes);
	if (bitmapCtxInfo)
	{
		context = createBitmapContext(bitmapCtxInfo, theDict, "CGBitmapContextCreateWithDictionary");
	}
	else
	{
		context = 0;
	}

	return context;
}


CGContextRef
createBitmapContext(CGBitmapContextInfoRef bitmapContextInfo, CFDictionaryRef theDict, const char* name)
{
	CGContextRef context;
	void* filterInfo;

	context = CGContextCreate();
	if (!context) {
		CGPostError("%s: failed to create bitmap context.", name);
		release_bitmap_info(bitmapContextInfo);
		goto Error;
	}

	context->contextType = kCGContextTypeBitmap;
	context->bitmapContextInfo = bitmapContextInfo;
	context->finalize = finalize_bitmap_context;

	CGRenderingStateSetRenderingResolution(
		context->rendering, 
		context->bitmapContextInfo->horzRes,
		context->bitmapContextInfo->vertRes);

	context->ctxDelegate = __CGBitmapContextDelegateCreate(bitmapContextInfo, theDict);
	if (!context->ctxDelegate) {
		CGPostError("%s: failed to create delegate.", "createBitmapContext");
		CGContextRelease(context);
		goto Error;
	}

	if (theDict != NULL) {

		filterInfo = (void*)CFDictionaryGetValue(theDict, kCGContextFilterInfo);
		if (filterInfo){
			context = CGContextAddFilter(context, filterInfo, 0);
		}
	}

	return context;
Error:
	return NULL;
}

size_t CGBitmapGetFastestAlignment()
{
	return 128;
}

size_t CGBitmapGetAlignedRowBytes(size_t bytesPerRow)
{
	return CGBitmapGetAlignedBytesPerRow(bytesPerRow);
}

size_t CGBitmapGetAlignedBytesPerRow(size_t bytesPerRow)
{
	return ((bytesPerRow+31)&~0x1f);
}

void *CGBitmapContextGetData(CGContextRef c)
{
	void* data;

	if (!c || c->contextType != kCGContextTypeBitmap) { 
		CGPostError("%s: invalid context", "CGBitmapContextGetData");	
		return NULL; 
	}
	
	if (c->bitmapContextInfo->dataAllocated == FALSE)
		data = c->bitmapContextInfo->data;
	else
		data = NULL;

	return data;
}

size_t CGBitmapContextGetWidth(CGContextRef c)
{
	if (!c || c->contextType != kCGContextTypeBitmap) { return 0; }
	return c->bitmapContextInfo->width;
}


size_t CGBitmapContextGetHeight(CGContextRef c)
{
	if (!c || c->contextType != kCGContextTypeBitmap) { return 0; }
	return c->bitmapContextInfo->height;
}


size_t CGBitmapContextGetBitsPerComponent(CGContextRef c)
{
	if (!c || c->contextType != kCGContextTypeBitmap) { return 0; }
	return c->bitmapContextInfo->bitsPerComponent;
}


size_t CGBitmapContextGetBitsPerPixel(CGContextRef c)
{
	if (!c || c->contextType != kCGContextTypeBitmap) { return 0; }
	return c->bitmapContextInfo->bitsPerPixel;
}


size_t CGBitmapContextGetBytesPerRow(CGContextRef c)
{
	if (!c || c->contextType != kCGContextTypeBitmap) { return 0; }
	return c->bitmapContextInfo->bytesPerRow;
}

CGColorSpaceRef CGBitmapContextGetColorSpace(CGContextRef c)
{
	if (!c || c->contextType != kCGContextTypeBitmap) { return 0; }
	return c->bitmapContextInfo->colorspace;
}


void* CGBitmapContextGetAlphaData(CGContextRef c)
{
	void* alphaData;

	if (!c || c->contextType != kCGContextTypeBitmap) { 
		CGPostError("%s: invalid context", "CGBitmapContextGetAlphaData");	
		return NULL; 
	}

	if (c->bitmapContextInfo->alphaAllocated == FALSE)
		alphaData = c->bitmapContextInfo->alphaData;
	else
		alphaData = NULL;

	return alphaData;
}


CGImageAlphaInfo CGBitmapContextGetAlphaInfo(CGContextRef c)
{
	CGImageAlphaInfo alphaInfo;

	if (!c || c->contextType != kCGContextTypeBitmap) { 
		return kCGImageAlphaNone; 
	}

	alphaInfo = (CGImageAlphaInfo)(c->bitmapContextInfo->bitmapInfo & kCGBitmapAlphaInfoMask);
	return alphaInfo;
}

CGBitmapInfo CGBitmapContextGetBitmapInfo(CGContextRef c)
{
	if (!c) { return 0; }
	return c->bitmapContextInfo->bitmapInfo;
}


CGImageRef CGBitmapContextCreateImage(CGContextRef c)
{
	size_t dataLen;

	if (!c || c->contextType != kCGContextTypeBitmap) { 
		CGPostError("");
		return NULL; 
	}

	dataLen = c->bitmapContextInfo->height * c->bitmapContextInfo->bytesPerRow;
	CGDataProviderCreateWithCopyOfData(c->bitmapContextInfo->data, dataLen);


	return 0;
}


