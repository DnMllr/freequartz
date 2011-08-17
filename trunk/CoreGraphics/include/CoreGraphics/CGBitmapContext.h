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

#ifndef CGBITMAPCONTEXT_H_
#define CGBITMAPCONTEXT_H_

#include <CoreGraphics/CGBase.h>
#include <CoreGraphics/CGContext.h>

CG_EXTERN CGContextRef 
CGBitmapContextCreate(void *data, size_t width,
					  size_t height, size_t bitsPerComponent, size_t bytesPerRow,
					  CGColorSpaceRef colorspace, CGBitmapInfo bitmapInfo);

CG_EXTERN 
size_t CGBitmapGetAlignedBytesPerRow(size_t len);

CG_EXTERN void *
CGBitmapContextGetData(CGContextRef c);

CG_EXTERN size_t 
CGBitmapContextGetWidth(CGContextRef c);

CG_EXTERN size_t 
CGBitmapContextGetHeight(CGContextRef c);

CG_EXTERN size_t 
CGBitmapContextGetBitsPerComponent(CGContextRef c);

CG_EXTERN size_t 
CGBitmapContextGetBitsPerPixel(CGContextRef c);

CG_EXTERN size_t 
CGBitmapContextGetBytesPerRow(CGContextRef c);

CG_EXTERN CGColorSpaceRef 
CGBitmapContextGetColorSpace(CGContextRef c);

CG_EXTERN CGImageAlphaInfo 
CGBitmapContextGetAlphaInfo(CGContextRef c);

CG_EXTERN CGBitmapInfo 
CGBitmapContextGetBitmapInfo(CGContextRef c);

CG_EXTERN CGImageRef 
CGBitmapContextCreateImage(CGContextRef c);



#endif	/* CGBITMAPCONTEXT_H_ */
