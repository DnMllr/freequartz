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
	CFTypeID nextID;				//0x08
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

CF_EXTERN_C_END

#endif /* CGIMAGEPRIV_H_ */


