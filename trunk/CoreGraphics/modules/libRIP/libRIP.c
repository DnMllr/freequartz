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
#include "libRIP.h"


//NULL
//8
//kCGImageAlphaOnly
//Alpha_8
//AAAAAAAA
//8 bits per pixel alpha only destination. Color data is thrown away. Useful for generating alpha channels and masks
//
//Gray
//8
//kCGImageAlphaNone
//Gray_8
//WWWWWWWW
//8 bits per pixel greyscale channel.
//
//RGB
//5
//kCGImageAlphaNoneSkipFirst
//RGB555
//-RRRRRGGGGGBBBBBB
//16 bits per pixel, 5 bit per RGB component
//
//RGB
//8
//kCGImageAlphaNoneSkipFirst
//XRGB_32
//--------RRRRRRRRGGGGGGGGBBBBBBBB
//32 bits per pixel RGB format where first byte is ignored
//
//RGB
//8
//kCGImageAlphaNoneSkipLast
//RGBX_32
//RRRRRRRRGGGGGGGGBBBBBBBB--------
//32 bits per pixel RGB format where last byte is skipped
//
//RGB
//8
//kCGImageAlphaPremultipliedFirst
//ARGB_32
//AAAAAAAARRRRRRRRRGGGGGGGGBBBBBBBB
//32 bits per pixel ARGB format with premultiplied alpha
//
//RGB
//8
//kCGImageAlphaPremultipliedLast
//RGBA_32
//RRRRRRRRGGGGGGGGBBBBBBBBAAAAAAAA
//32 bits per pixel RGBA format with premultiplied alpha
//
//CMYK
//8
//kCGImageAlphaNone
//CMYK_32
//CCCCCCCCMMMMMMMMYYYYYYYYKKKKKKKK
//32 bits per pixel CMYK format without alpha


//http://developer.apple.com/mac/library/qa/qa2001/qa1037.html
//0x17(23) encodings
static const char* _ripl_encoding[] = {

	"AAAAAAAA",	//kCGImageAlphaOnly Alpha_8							
	"WWWWWWWW",	//kCGImageAlphaNone Gray_8							
	"PPPPPPPP",
	"-RRRRRGGGGGBBBBB", //kCGImageAlphaNoneSkipFirst RGB555
	"-rrrrrgggggbbbbb", //kCGImageAlphaNoneSkipFirst RGB555
	"--------RRRRRRRRGGGGGGGGBBBBBBBB", //kCGImageAlphaNoneSkipFirst XRGB_32
	"--------rrrrrrrrggggggggbbbbbbbb", //kCGImageAlphaNoneSkipFirst XRGB_32
	"RRRRRRRRGGGGGGGGBBBBBBBB--------", //kCGImageAlphaNoneSkipLast RGBX_32
	"rrrrrrrrggggggggbbbbbbbb--------", //kCGImageAlphaNoneSkipLast RGBX_32 
	"CCCCCCCCMMMMMMMMYYYYYYYYKKKKKKKK", //kCGImageAlphaNone CMYK_32
	"ccccccccmmmmmmmmyyyyyyyykkkkkkkk", //kCGImageAlphaNone CMYK_32
	"WWWWWWWWWWWWWWWW", //kCGImageAlphaNone Alpha_16
	"wwwwwwwwwwwwwwww", //kCGImageAlphaNone Alpha_16
	"RRRRRRRRRRRRRRRRGGGGGGGGGGGGGGGGBBBBBBBBBBBBBBBB----------------", //kCGImageAlphaNoneSkipLast RGBX_64
	"rrrrrrrrrrrrrrrrggggggggggggggggbbbbbbbbbbbbbbbb----------------", //kCGImageAlphaNoneSkipLast RGBX_64
	"CCCCCCCCCCCCCCCCMMMMMMMMMMMMMMMMYYYYYYYYYYYYYYYYKKKKKKKKKKKKKKKK", //kCGImageAlphaNone CMYK_64
	"ccccccccccccccccmmmmmmmmmmmmmmmmyyyyyyyyyyyyyyyykkkkkkkkkkkkkkkk", //kCGImageAlphaNone CMYK_64
	"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW", //kCGImageAlphaNone Gray_32
	"wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww", //kCGImageAlphaNone Gray_32
	"RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB--------------------------------", //kCGImageAlphaNoneSkipLast RGBX_128
	"rrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrggggggggggggggggggggggggggggggggbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb--------------------------------", //kCGImageAlphaNoneSkipLast RGBX_128
	"CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKK", //kCGImageAlphaNone CMYK_128
	"ccccccccccccccccccccccccccccccccmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyykkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk", //kCGImageAlphaNone CMYK_128
	NULL
};



int RIPLayerDepthForFormat(int index)
{
	return 0;
}

uint32_t 
ripc_InitializeFormat(CGBitmapContextInfoRef bitmapContextInfo)
{
	size_t numOfComponents;

	numOfComponents = CGColorSpaceGetNumberOfComponents(bitmapContextInfo->colorspace);

	//if (bitmapContextInfo->bitmapInfo & kCGBitmapByteOrderMask)

	return ((uint32_t)-1);
}

RIPRef 
ripc_Initialize(RIPRef rip)
{
	//CGContextDelegateRef ctxDelegate;

	rip->ctxDelegate = CGContextDelegateCreate(NULL/*FIXME*/);
	if (rip->ctxDelegate == NULL) {

	}

	return NULL;
}


#if 0
CGRect
ripc_GetBounds(CGContextDelegateRef ctxDelegate)
{
	CGContextDelegateInfoRef delegateInfo;

	delegateInfo = CGContextDelegateGetInfo(ctxDelegate);
	if (delegateInfo->ctxDelegate->getBounds == NULL) {
		return CGRectNull;
	}
}
#endif

CGContextDelegateRef 
__CGBitmapContextDelegateCreate(CGBitmapContextInfoRef bitmapContextInfo, 
								CFDictionaryRef theDict)
{
	CGContextDelegateRef ctxDelegate;
	uint32_t ret, depth;
	size_t numOfComponents;

	ret = ripc_InitializeFormat(bitmapContextInfo);
	//depth = RIPLayerDepthForFormat();
	
	if (ret == -1 || depth == 0) {
		numOfComponents = CGColorSpaceGetNumberOfComponents(bitmapContextInfo->colorspace);
		CGPostError("Unsupported pixel description - %lu components, %lu bits-per-com",
			numOfComponents, bitmapContextInfo->bitsPerComponent);
		return NULL;
	}

	//ripc_Initialize();


	return ctxDelegate;
}