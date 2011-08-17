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
#ifndef CGIMAGE_H_
#define CGIMAGE_H_

typedef struct CGImage *CGImageRef;

#include <CoreGraphics/CGColorSpace.h>
#include <CoreGraphics/CGDataProvider.h>
#include <CoreGraphics/CGGeometry.h>

enum CGImageAlphaInfo {
    kCGImageAlphaNone,               
    kCGImageAlphaPremultipliedLast,  
    kCGImageAlphaPremultipliedFirst, 
    kCGImageAlphaLast,               
    kCGImageAlphaFirst,              
    kCGImageAlphaNoneSkipLast,       
    kCGImageAlphaNoneSkipFirst,      
    kCGImageAlphaOnly                
};
typedef enum CGImageAlphaInfo CGImageAlphaInfo;

enum {
    kCGBitmapAlphaInfoMask = 0x1F,
    kCGBitmapFloatComponents = (1 << 8),
    
    kCGBitmapByteOrderMask = 0x7000,
    kCGBitmapByteOrderDefault = (0 << 12),
    kCGBitmapByteOrder16Little = (1 << 12),
    kCGBitmapByteOrder32Little = (2 << 12),
    kCGBitmapByteOrder16Big = (3 << 12),
    kCGBitmapByteOrder32Big = (4 << 12)
};
typedef uint32_t CGBitmapInfo;

#ifdef __BIG_ENDIAN__
#define kCGBitmapByteOrder16Host kCGBitmapByteOrder16Big
#define kCGBitmapByteOrder32Host kCGBitmapByteOrder32Big
#else    /* Little endian. */
#define kCGBitmapByteOrder16Host kCGBitmapByteOrder16Little
#define kCGBitmapByteOrder32Host kCGBitmapByteOrder32Little
#endif

CG_EXTERN CFTypeID CGImageGetTypeID(void);

CG_EXTERN CGImageRef CGImageCreate(size_t width, size_t height,
    size_t bitsPerComponent, size_t bitsPerPixel, size_t bytesPerRow,
    CGColorSpaceRef space, CGBitmapInfo bitmapInfo, CGDataProviderRef provider,
    const CGFloat decode[], bool shouldInterpolate,
    CGColorRenderingIntent intent);

CG_EXTERN CGImageRef CGImageMaskCreate(size_t width, size_t height,
    size_t bitsPerComponent, size_t bitsPerPixel, size_t bytesPerRow,
    CGDataProviderRef provider, const CGFloat decode[], bool shouldInterpolate);

CG_EXTERN CGImageRef CGImageCreateCopy(CGImageRef image);

CG_EXTERN CGImageRef CGImageCreateWithJPEGDataProvider(CGDataProviderRef
    source, const CGFloat decode[], bool shouldInterpolate,
    CGColorRenderingIntent intent);

CG_EXTERN CGImageRef CGImageCreateWithJPEGDataProvider2(CGDataProviderRef
    source, CGColorSpaceRef space, const CGFloat decode[], bool shouldInterpolate,
    CGColorRenderingIntent intent);

CG_EXTERN CGImageRef CGImageCreateWithPNGDataProvider(CGDataProviderRef source,
    const CGFloat decode[], bool shouldInterpolate,
    CGColorRenderingIntent intent);

CG_EXTERN CGImageRef CGImageCreateWithImageInRect(CGImageRef image, CGRect rect);

CG_EXTERN CGImageRef CGImageCreateWithMask(CGImageRef image, CGImageRef mask);

CG_EXTERN CGImageRef CGImageCreateWithMaskingColors(CGImageRef image,
    const CGFloat components[]);

CG_EXTERN CGImageRef CGImageCreateCopyWithColorSpace(CGImageRef image,
    CGColorSpaceRef space);

CG_EXTERN CGImageRef CGImageRetain(CGImageRef image);

CG_EXTERN void CGImageRelease(CGImageRef image);

CG_EXTERN bool CGImageIsMask(CGImageRef image);

CG_EXTERN size_t CGImageGetWidth(CGImageRef image);

CG_EXTERN size_t CGImageGetHeight(CGImageRef image);

CG_EXTERN size_t CGImageGetBitsPerComponent(CGImageRef image);

CG_EXTERN size_t CGImageGetBitsPerPixel(CGImageRef image);

CG_EXTERN size_t CGImageGetBytesPerRow(CGImageRef image);

CG_EXTERN CGColorSpaceRef CGImageGetColorSpace(CGImageRef image);

CG_EXTERN CGImageAlphaInfo CGImageGetAlphaInfo(CGImageRef image);

CG_EXTERN CGDataProviderRef CGImageGetDataProvider(CGImageRef image);

CG_EXTERN const CGFloat *CGImageGetDecode(CGImageRef image);

CG_EXTERN bool CGImageGetShouldInterpolate(CGImageRef image);

CG_EXTERN CGColorRenderingIntent CGImageGetRenderingIntent(CGImageRef image);

CG_EXTERN CGBitmapInfo CGImageGetBitmapInfo(CGImageRef image);

#endif	/* CGIMAGE_H_ */
