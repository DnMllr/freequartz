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
#ifndef CGDATACONSUMER_H_
#define CGDATACONSUMER_H_

typedef struct CGDataConsumer *CGDataConsumerRef;

#include <CoreGraphics/CGBase.h>
#include <CoreFoundation/CFURL.h>
#include <stddef.h>

typedef size_t (*CGDataConsumerPutBytesCallback)(void *info,
    const void *buffer, size_t count);

typedef void (*CGDataConsumerReleaseInfoCallback)(void *info);

struct CGDataConsumerCallbacks {
    CGDataConsumerPutBytesCallback putBytes;
    CGDataConsumerReleaseInfoCallback releaseConsumer;
};
typedef struct CGDataConsumerCallbacks CGDataConsumerCallbacks;

CG_EXTERN CFTypeID CGDataConsumerGetTypeID(void);

CG_EXTERN CGDataConsumerRef CGDataConsumerCreate(void *info,
    const CGDataConsumerCallbacks *callbacks);

CG_EXTERN CGDataConsumerRef CGDataConsumerCreateWithURL(CFURLRef url);

CG_EXTERN CGDataConsumerRef CGDataConsumerCreateWithCFData(CFMutableDataRef
    data);

CG_EXTERN CGDataConsumerRef CGDataConsumerRetain(CGDataConsumerRef consumer);

CG_EXTERN void CGDataConsumerRelease(CGDataConsumerRef consumer);

#endif	/* CGDATACONSUMER_H_ */
