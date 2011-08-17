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
#ifndef CGGRADIENT_H_
#define CGGRADIENT_H_

typedef struct CGGradient *CGGradientRef;

enum {
    kCGGradientDrawsBeforeStartLocation = (1 << 0),
    kCGGradientDrawsAfterEndLocation = (1 << 1)
};
typedef enum CGGradientDrawingOptions CGGradientDrawingOptions;

#include <CoreGraphics/CGBase.h>
#include <CoreGraphics/CGColorSpace.h>
#include <CoreGraphics/CGContext.h>


CG_EXTERN CFTypeID CGGradientGetTypeID(void);

CG_EXTERN CGGradientRef CGGradientCreateWithColorComponents(CGColorSpaceRef
    space, const CGFloat components[], const CGFloat locations[], size_t count);

CG_EXTERN CGGradientRef CGGradientCreateWithColors(CGColorSpaceRef space,
    CFArrayRef colors, const CGFloat locations[]);

CG_EXTERN CGGradientRef CGGradientRetain(CGGradientRef gradient);

CG_EXTERN void CGGradientRelease(CGGradientRef gradient);

#endif	/* CGGRADIENT_H_ */
