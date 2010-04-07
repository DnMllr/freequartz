/****************************************************************************
**
** Copyright (C) 2010 Smartmobili.
** All rights reserved.
** Contact: Smartmobili (contact@smartmobili.com)
**	
** This file is part of the CoreGraphics module of the Coconuts Toolkit.
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
#ifndef CGBITMAPCONTEXT_H_
#define CGBITMAPCONTEXT_H_

#include <CoreGraphics/CGBase.h>
#include <CoreGraphics/CGContext.h>

CG_EXTERN CGContextRef 
CGBitmapContextCreate(void *data, size_t width,
					  size_t height, size_t bitsPerComponent, size_t bytesPerRow,
					  CGColorSpaceRef colorspace, CGBitmapInfo bitmapInfo);

CG_EXTERN void *
CGBitmapContextGetData(CGContextRef c);

CG_EXTERN size_t 
CGBitmapContextGetWidth(CGContextRef c);

CG_EXTERN size_t 
CGBitmapContextGetHeight(CGContextRef c);

CG_EXTERN size_t 
CGBitmapContextGetBitsPerComponent(CGContextRef c);

CG_EXTERN size_t 
CGBitmapContextGetBitsPerPixel(CGContextRef c);

CG_EXTERN size_t 
CGBitmapContextGetBytesPerRow(CGContextRef c);

CG_EXTERN CGColorSpaceRef 
CGBitmapContextGetColorSpace(CGContextRef c);

CG_EXTERN CGImageAlphaInfo 
CGBitmapContextGetAlphaInfo(CGContextRef c);

CG_EXTERN CGBitmapInfo 
CGBitmapContextGetBitmapInfo(CGContextRef c);

CG_EXTERN CGImageRef 
CGBitmapContextCreateImage(CGContextRef c);



#endif	/* CGBITMAPCONTEXT_H_ */
