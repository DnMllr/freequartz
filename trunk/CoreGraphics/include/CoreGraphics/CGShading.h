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
#ifndef CGSHADING_H_
#define CGSHADING_H_

#include <CoreGraphics/CGBase.h>
#include <CoreGraphics/CGColorSpace.h>
#include <CoreGraphics/CGFunction.h>
#include <CoreGraphics/CGGeometry.h>
#include <CoreFoundation/CFBase.h>

typedef struct CGShading *CGShadingRef;

CG_EXTERN CFTypeID CGShadingGetTypeID(void);

CG_EXTERN CGShadingRef CGShadingCreateAxial(CGColorSpaceRef space,
    CGPoint start, CGPoint end, CGFunctionRef function, bool extendStart,
    bool extendEnd);

CG_EXTERN CGShadingRef CGShadingCreateRadial(CGColorSpaceRef space,
    CGPoint start, CGFloat startRadius, CGPoint end, CGFloat endRadius,
    CGFunctionRef function, bool extendStart, bool extendEnd);

CG_EXTERN CGShadingRef CGShadingRetain(CGShadingRef shading);

CG_EXTERN void CGShadingRelease(CGShadingRef shading)
    CG_AVAILABLE_STARTING(__MAC_10_2, __IPHONE_2_0);

#endif	/* CGSHADING_H_ */
