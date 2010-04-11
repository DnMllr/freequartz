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
#ifndef CGCOLORSPACE_H_
#define CGCOLORSPACE_H_

typedef struct CGColorSpace *CGColorSpaceRef;

#include <CoreGraphics/CGBase.h>
#include <CoreGraphics/CGDataProvider.h>

/* constants. */
CG_EXTERN const CFStringRef kCGColorSpaceGenericGray;
CG_EXTERN const CFStringRef kCGColorSpaceGenericRGB;
CG_EXTERN const CFStringRef kCGColorSpaceGenericCMYK;
CG_EXTERN const CFStringRef kCGColorSpaceGenericRGBLinear;
CG_EXTERN const CFStringRef kCGColorSpaceAdobeRGB1998;
CG_EXTERN const CFStringRef kCGColorSpaceSRGB;
CG_EXTERN const CFStringRef kCGColorSpaceGenericGrayGamma2_2;

enum CGColorSpaceModel {
    kCGColorSpaceModelUnknown = -1,
    kCGColorSpaceModelMonochrome,
    kCGColorSpaceModelRGB,
    kCGColorSpaceModelCMYK,
    kCGColorSpaceModelLab,
    kCGColorSpaceModelDeviceN,
    kCGColorSpaceModelIndexed,
    kCGColorSpaceModelPattern
};
typedef enum CGColorSpaceModel CGColorSpaceModel;


enum CGColorRenderingIntent {
    kCGRenderingIntentDefault,
    kCGRenderingIntentAbsoluteColorimetric,
    kCGRenderingIntentRelativeColorimetric,
    kCGRenderingIntentPerceptual,
    kCGRenderingIntentSaturation
};
typedef enum CGColorRenderingIntent CGColorRenderingIntent;


CG_EXTERN void create_name_to_index_map();

CG_EXTERN CGColorSpaceRef CGColorSpaceCreateDeviceGray(void);

CG_EXTERN CGColorSpaceRef CGColorSpaceCreateDeviceRGB(void);

CG_EXTERN CGColorSpaceRef CGColorSpaceCreateDeviceCMYK(void);

CG_EXTERN CGColorSpaceRef CGColorSpaceCreateCalibratedGray(const CGFloat
    whitePoint[3], const CGFloat blackPoint[3], CGFloat gamma);

CG_EXTERN CGColorSpaceRef CGColorSpaceCreateCalibratedRGB(const CGFloat
    whitePoint[3], const CGFloat blackPoint[3], const CGFloat gamma[3],
    const CGFloat matrix[9]);
    
CG_EXTERN CGColorSpaceRef CGColorSpaceCreateLab(const CGFloat whitePoint[3],
    const CGFloat blackPoint[3], const CGFloat range[4]);

CG_EXTERN CGColorSpaceRef CGColorSpaceCreateICCBased(size_t nComponents,
    const CGFloat *range, CGDataProviderRef profile,
    CGColorSpaceRef alternate);

CG_EXTERN CGColorSpaceRef CGColorSpaceCreateIndexed(CGColorSpaceRef baseSpace,
    size_t lastIndex, const unsigned char *colorTable);

CG_EXTERN CGColorSpaceRef CGColorSpaceCreatePattern(CGColorSpaceRef baseSpace);

CG_EXTERN CGColorSpaceRef CGColorSpaceCreateWithPlatformColorSpace(void *ref);

CG_EXTERN CGColorSpaceRef CGColorSpaceCreateWithName(CFStringRef name);

CG_EXTERN CGColorSpaceRef CGColorSpaceRetain(CGColorSpaceRef space);

CG_EXTERN void CGColorSpaceRelease(CGColorSpaceRef space);

CG_EXTERN CFTypeID CGColorSpaceGetTypeID(void);

CG_EXTERN size_t CGColorSpaceGetNumberOfComponents(CGColorSpaceRef space);

CG_EXTERN CGColorSpaceModel CGColorSpaceGetModel(CGColorSpaceRef space);

CG_EXTERN CGColorSpaceRef CGColorSpaceGetBaseColorSpace(CGColorSpaceRef space);

CG_EXTERN size_t CGColorSpaceGetColorTableCount(CGColorSpaceRef space);

CG_EXTERN void CGColorSpaceGetColorTable(CGColorSpaceRef space, uint8_t *table);

CG_EXTERN CFDataRef CGColorSpaceCopyICCProfile(CGColorSpaceRef space);

#endif	/* CGCOLORSPACE_H_ */
