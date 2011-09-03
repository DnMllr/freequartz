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
