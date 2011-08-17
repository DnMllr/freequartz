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
#ifndef CGFUNCTION_H_
#define CGFUNCTION_H_

typedef struct CGFunction *CGFunctionRef;

#include <CoreGraphics/CGBase.h>
#include <CoreFoundation/CFBase.h>

typedef void (*CGFunctionEvaluateCallback)(void *info, const CGFloat *in,
    CGFloat *out);

typedef void (*CGFunctionReleaseInfoCallback)(void *info);

struct CGFunctionCallbacks {
    unsigned int version;
    CGFunctionEvaluateCallback evaluate;
    CGFunctionReleaseInfoCallback releaseInfo;
};
typedef struct CGFunctionCallbacks CGFunctionCallbacks;


CG_EXTERN CFTypeID CGFunctionGetTypeID(void);

CG_EXTERN CGFunctionRef CGFunctionCreate(void *info, size_t domainDimension,
    const CGFloat *domain, size_t rangeDimension, const CGFloat *range,
    const CGFunctionCallbacks *callbacks);

CG_EXTERN CGFunctionRef CGFunctionRetain(CGFunctionRef function);

CG_EXTERN void CGFunctionRelease(CGFunctionRef function);

#endif	/* CGFUNCTION_H_ */
