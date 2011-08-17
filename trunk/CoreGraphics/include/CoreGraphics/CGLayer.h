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
#ifndef CGLAYER_H_
#define CGLAYER_H_

typedef struct CGLayer *CGLayerRef;

#include <CoreGraphics/CGBase.h>
#include <CoreGraphics/CGContext.h>

CG_EXTERN CGLayerRef CGLayerCreateWithContext(CGContextRef context,
    CGSize size, CFDictionaryRef auxiliaryInfo);

CG_EXTERN CGLayerRef CGLayerRetain(CGLayerRef layer);

CG_EXTERN void CGLayerRelease(CGLayerRef layer);

CG_EXTERN CGSize CGLayerGetSize(CGLayerRef layer);

CG_EXTERN CGContextRef CGLayerGetContext(CGLayerRef layer);

CG_EXTERN void CGContextDrawLayerInRect(CGContextRef context, CGRect rect,
    CGLayerRef layer);

CG_EXTERN void CGContextDrawLayerAtPoint(CGContextRef context, CGPoint point,
    CGLayerRef layer);

CG_EXTERN CFTypeID CGLayerGetTypeID(void);

#endif	/* CGLAYER_H_ */
