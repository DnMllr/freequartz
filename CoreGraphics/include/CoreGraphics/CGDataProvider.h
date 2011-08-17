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
#ifndef CGDATAPROVIDER_H_
#define CGDATAPROVIDER_H_

typedef struct CGDataProvider *CGDataProviderRef;

#include <CoreGraphics/CGBase.h>
#include <CoreFoundation/CFURL.h>
#include <stddef.h>
#include <unistd.h>

typedef size_t (*CGDataProviderGetBytesCallback)(void *info, void *buffer, size_t count);

typedef off_t (*CGDataProviderSkipForwardCallback)(void *info, off_t count);

typedef void (*CGDataProviderRewindCallback)(void *info);

typedef void (*CGDataProviderReleaseInfoCallback)(void *info);

struct CGDataProviderSequentialCallbacks {
    unsigned int version;
    CGDataProviderGetBytesCallback getBytes;
    CGDataProviderSkipForwardCallback skipForward;
    CGDataProviderRewindCallback rewind;
    CGDataProviderReleaseInfoCallback releaseInfo;
};
typedef struct CGDataProviderSequentialCallbacks
    CGDataProviderSequentialCallbacks;


typedef const void *(*CGDataProviderGetBytePointerCallback)(void *info);


typedef void (*CGDataProviderReleaseBytePointerCallback)(void *info,
    const void *pointer);


typedef size_t (*CGDataProviderGetBytesAtPositionCallback)(void *info,
    void *buffer, off_t position, size_t count);


struct CGDataProviderDirectCallbacks {
    unsigned int version;
    CGDataProviderGetBytePointerCallback getBytePointer;
    CGDataProviderReleaseBytePointerCallback releaseBytePointer;
    CGDataProviderGetBytesAtPositionCallback getBytesAtPosition;
    CGDataProviderReleaseInfoCallback releaseInfo;
};
typedef struct CGDataProviderDirectCallbacks CGDataProviderDirectCallbacks;


CG_EXTERN CFTypeID CGDataProviderGetTypeID(void);


CG_EXTERN CGDataProviderRef CGDataProviderCreateSequential(void *info,
    const CGDataProviderSequentialCallbacks *callbacks);

CG_EXTERN CGDataProviderRef CGDataProviderCreateDirect(void *info, off_t size,
    const CGDataProviderDirectCallbacks *callbacks);
    
typedef void (*CGDataProviderReleaseDataCallback)(void *info, const void *data,
    size_t size);
    
CG_EXTERN CGDataProviderRef CGDataProviderCreateWithData(void *info,
    const void *data, size_t size,
    CGDataProviderReleaseDataCallback releaseData);

CG_EXTERN CGDataProviderRef CGDataProviderCreateWithCFData(CFDataRef data);

CG_EXTERN CGDataProviderRef CGDataProviderCreateWithURL(CFURLRef url);

CG_EXTERN CGDataProviderRef
    CGDataProviderCreateWithFilename(const char *filename);

CG_EXTERN CGDataProviderRef CGDataProviderRetain(CGDataProviderRef provider);

CG_EXTERN void CGDataProviderRelease(CGDataProviderRef provider);

CG_EXTERN CFDataRef CGDataProviderCopyData(CGDataProviderRef provider);

typedef void (*CGDataProviderSkipBytesCallback)(void *info, size_t count);

struct CGDataProviderCallbacks {
    CGDataProviderGetBytesCallback getBytes;
    CGDataProviderSkipBytesCallback skipBytes;
    CGDataProviderRewindCallback rewind;
    CGDataProviderReleaseInfoCallback releaseProvider;
};
typedef struct CGDataProviderCallbacks CGDataProviderCallbacks;


typedef size_t (*CGDataProviderGetBytesAtOffsetCallback)(void *info,
    void *buffer, size_t offset, size_t count);

struct CGDataProviderDirectAccessCallbacks {
    CGDataProviderGetBytePointerCallback getBytePointer;
    CGDataProviderReleaseBytePointerCallback releaseBytePointer;
    CGDataProviderGetBytesAtOffsetCallback getBytes;
    CGDataProviderReleaseInfoCallback releaseProvider;
};
typedef struct CGDataProviderDirectAccessCallbacks
    CGDataProviderDirectAccessCallbacks;


CG_EXTERN CGDataProviderRef CGDataProviderCreate(void *info,
    const CGDataProviderCallbacks *callbacks);


CG_EXTERN CGDataProviderRef CGDataProviderCreateDirectAccess(void *info,
    size_t size, const CGDataProviderDirectAccessCallbacks *callbacks);

#endif	/* CGDATAPROVIDER_H_ */
