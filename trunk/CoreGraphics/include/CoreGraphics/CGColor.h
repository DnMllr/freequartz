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

#ifndef CGCOLOR_H_
#define CGCOLOR_H_

typedef struct CGColor *CGColorRef;

#include <CoreGraphics/CGBase.h>
#include <CoreGraphics/CGColorSpace.h>
#include <CoreGraphics/CGPattern.h>

/* constants */
CG_EXTERN const CFStringRef kCGColorWhite;
CG_EXTERN const CFStringRef kCGColorBlack;
CG_EXTERN const CFStringRef kCGColorClear;


/* Getting a Constant Color */
CG_EXTERN CGColorRef CGColorGetConstantColor(CFStringRef colorName);

/* Retaining and Releasing Color Objects */
CG_EXTERN void CGColorRelease(CGColorRef color);

CG_EXTERN CGColorRef CGColorRetain(CGColorRef color);

/* Creating Quartz Colors */
CG_EXTERN CGColorRef CGColorCreate(CGColorSpaceRef space,
    const CGFloat components[]);

CG_EXTERN CGColorRef CGColorCreateCopy(CGColorRef color);

CG_EXTERN CGColorRef CGColorCreateGenericGray(CGFloat gray, CGFloat alpha);

CG_EXTERN CGColorRef CGColorCreateGenericRGB(CGFloat red, CGFloat green,
    CGFloat blue, CGFloat alpha);

CG_EXTERN CGColorRef CGColorCreateGenericCMYK(CGFloat cyan, CGFloat magenta,
    CGFloat yellow, CGFloat black, CGFloat alpha);

CG_EXTERN CGColorRef CGColorCreateCopyWithAlpha(CGColorRef color,
    CGFloat alpha);

CG_EXTERN CGColorRef CGColorCreateWithPattern(CGColorSpaceRef space,
    CGPatternRef pattern, const CGFloat components[]);

/* Getting Information about Quartz Colors */

CG_EXTERN bool CGColorEqualToColor(CGColorRef color1, CGColorRef color2);

CG_EXTERN CGFloat CGColorGetAlpha(CGColorRef color);

CG_EXTERN CGColorSpaceRef CGColorGetColorSpace(CGColorRef color);

CG_EXTERN const CGFloat *CGColorGetComponents(CGColorRef color);

CG_EXTERN size_t CGColorGetNumberOfComponents(CGColorRef color);

CG_EXTERN CGPatternRef CGColorGetPattern(CGColorRef color);

CG_EXTERN CFTypeID CGColorGetTypeID(void);

#endif	/* CGCOLOR_H_ */
