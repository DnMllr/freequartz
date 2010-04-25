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
#ifndef CGBITMAPCONTEXTPRIV_H_
#define CGBITMAPCONTEXTPRIV_H_

#include "CGBasePriv.h"
#include "CGContextPriv.h"

CG_EXTERN_C_BEGIN

typedef CGContextDelegateRef  (*_CGBitmapContextDelegateCreate)(
	CGBitmapContextInfoRef bitmapContextInfo, 
	CFDictionaryRef theDict);

CG_EXTERN void loadBitmapContextDelegateCreator(void);


CG_EXTERN CGBitmapContextInfoRef CGBitmapContextInfoCreate(size_t bitsPerComponent,
														   size_t bitsPerAlpha,
														   size_t bytesPerRow,
														   CGColorSpaceRef colorspace, 
														   CGBitmapInfo bitmapInfo, 
														   Boolean a,
														   Boolean b,
														   Boolean c,
														   Boolean d,
														   Boolean e,
														   CGFloat hRes,
														   CGFloat vRes);

CG_EXTERN CGContextRef CGBitmapContextCreateWithDictionary(void *data, 
												 size_t width, size_t height,
												 size_t bitsPerComponent,
												 size_t bitsPerAlpha,
												 size_t bytesPerRow,
												 CGColorSpaceRef colorspace, 
												 CGBitmapInfo bitmapInfo,
												 CGFloat hRes, 
												 CGFloat vRes, 
												 CFDictionaryRef theDict);



CG_EXTERN void * CGBitmapAllocateData(size_t len);

CG_EXTERN void CGBitmapFreeData(void *data);

CG_EXTERN size_t CGBitmapGetAlignedBytesPerRow(size_t len);


CG_EXTERN CGContextRef createBitmapContext(CGBitmapContextInfoRef bitmapContextInfo, 
										   CFDictionaryRef theDict, const char* name);

void finalize_bitmap_context(CGContextRef context);

void release_bitmap_info(CGBitmapContextInfoRef bitmapInfo);

bool validate_gray_bitmap_info(CGBitmapContextInfoRef bitmapContextInfo);

bool validate_rgb_bitmap_info(CGBitmapContextInfoRef bitmapContextInfo);

bool validate_gray_bitmap_info(CGBitmapContextInfoRef bitmapContextInfo);

bool validate_cmyk_bitmap_info(CGBitmapContextInfoRef bitmapContextInfo);


CG_EXTERN_C_END

#endif /* CGBITMAPCONTEXTPRIV_H_ */


