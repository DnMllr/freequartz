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
#ifndef CGCOLORPSPACERIV_H_
#define CGCOLORPSPACERIV_H_

#include <CoreFoundation/CFRuntime.h>

#include "CGMacros.h"
#include "CGColorPriv.h"

CF_EXTERN_C_BEGIN

/* constants */
enum CGColorSpaceType {

	kCGColorSpaceTypeDeviceUnknown = 0,
	kCGColorSpaceTypeDisplayGray,
	kCGColorSpaceTypeDisplayRGB,
	kCGColorSpaceTypeDeviceGray,
	kCGColorSpaceTypeDeviceRGB,
	kCGColorSpaceTypeDeviceCMYK,
	kCGColorSpaceTypeSystemDefaultGray,
	kCGColorSpaceTypeSystemDefaultRGB,
	kCGColorSpaceTypeSystemDefaultCMYK,

	kCGColorSpaceTypePattern = 14

};
typedef enum CGColorSpaceType CGColorSpaceType;


typedef struct CGColorSpace {
	CFRuntimeBase obj;				//0x00

	CGColorSpaceType spaceType;		//0x0C
	CGColorSpaceModel spaceModel;	//0x10
	size_t numberOfComponents;		//0x18
	CGColorRef defaultColor;		//0x1C

} CGColorSpace, *CGColorSpaceRef;


/* private colorspace constants */
CG_EXTERN const CFStringRef kCGColorSpaceDisplayGray;
CG_EXTERN const CFStringRef kCGColorSpaceDisplayRGB;
CG_EXTERN const CFStringRef kCGColorSpaceDeviceGray;
CG_EXTERN const CFStringRef kCGColorSpaceDeviceRGB;
CG_EXTERN const CFStringRef kCGColorSpaceDeviceCMYK;
CG_EXTERN const CFStringRef kCGColorSpaceSystemDefaultGray;
CG_EXTERN const CFStringRef kCGColorSpaceSystemDefaultRGB;
CG_EXTERN const CFStringRef kCGColorSpaceSystemDefaultCMYK;
CG_EXTERN const CFStringRef kCGColorSpaceUncalibratedGray;
CG_EXTERN const CFStringRef kCGColorSpaceUncalibratedRGB;
CG_EXTERN const CFStringRef kCGColorSpaceUncalibratedCMYK;
CG_EXTERN const CFStringRef kCGColorSpaceGenericHDR;
CG_EXTERN const CFStringRef kCGColorSpaceGenericRGBHDR;
CG_EXTERN const CFStringRef kCGColorSpaceUndo601;
CG_EXTERN const CFStringRef kCGColorSpaceColoredPattern;



/* functions */
void create_name_to_index_map(void);
void CGColorSpaceDestroy(CFTypeRef ctf);
bool CGColorSpaceEqualToColorSpace(CGColorSpaceRef cs1, CGColorSpaceRef cs2);
CGColorRef CGColorSpaceCopyDefaultColor(CGColorSpaceRef space);
CGColorSpaceRef CGColorSpaceCreateDeviceRGB(void);
CGColorSpaceType CGColorSpaceGetType(CGColorSpaceRef space);
CGColorSpaceRef CGColorSpaceRetain(CGColorSpaceRef space);
CGColorSpaceRef CGColorSpaceCreateWithIndex(int index);
CFIndex CGColorSpaceGetIndexForName(CFStringRef name);


CF_EXTERN_C_END

#endif /* CGCOLORPSPACERIV_H_ */


