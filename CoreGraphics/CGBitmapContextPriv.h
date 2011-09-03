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
#ifndef CGBITMAPCONTEXTPRIV_H_
#define CGBITMAPCONTEXTPRIV_H_

#include "CGBasePriv.h"
#include "CGContextPriv.h"

CG_EXTERN_C_BEGIN

typedef CGContextDelegateRef  (*CGBitmapContextDelegateCreateCallback)(
	CGBitmapContextInfoRef bitmapContextInfo, 
	CFDictionaryRef theDict);

CG_EXTERN void loadBitmapContextDelegateCreator(void);


CG_EXTERN CGBitmapContextInfoRef CGBitmapContextInfoCreate(void *data, 
														   size_t width, size_t height,
														   size_t bitsPerComponent,
														   size_t bitsPerPixel,
														   size_t bytesPerRow,
														   CGColorSpaceRef colorspace, 
														   CGBitmapInfo bitmapInfo, 
														   void* alphaData,
														   Boolean b,
														   Boolean c,
														   Boolean d,
														   Boolean e,
														   CGFloat hRes,
														   CGFloat vRes);

CG_EXTERN void CGBitmapContextInfoRelease(CGBitmapContextInfoRef bitmapInfo);

CGContextRef
CGBitmapContextCreateWithData(void *data, size_t width,
							  size_t height, size_t bitsPerComponent,
							  size_t bytesPerRow,
							  CGColorSpaceRef colorspace, 
							  CGBitmapInfo bitmapInfo, 
							  CGFloat hRes, CGFloat vRes);

CG_EXTERN CGContextRef CGBitmapContextCreateWithDictionary(void *data, 
												 size_t width, size_t height,
												 size_t bitsPerComponent,
												 size_t bitsPerPixel,
												 size_t bytesPerRow,
												 CGColorSpaceRef colorspace, 
												 CGBitmapInfo bitmapInfo,
												 CGFloat hRes, 
												 CGFloat vRes, 
												 CFDictionaryRef theDict);



CG_EXTERN void * CGBitmapAllocateData(size_t len);

CG_EXTERN void CGBitmapFreeData(void *data);


CG_EXTERN CGContextRef bitmap_context_create(CGBitmapContextInfoRef bitmapContextInfo, 
										     CFDictionaryRef theDict, const char* name);

void bitmap_context_finalize(CGContextRef context);



bool validate_gray_bitmap_info(CGBitmapContextInfoRef bitmapContextInfo);

bool validate_rgb_bitmap_info(CGBitmapContextInfoRef bitmapContextInfo);

bool validate_gray_bitmap_info(CGBitmapContextInfoRef bitmapContextInfo);

bool validate_cmyk_bitmap_info(CGBitmapContextInfoRef bitmapContextInfo);


CG_EXTERN_C_END

#endif /* CGBITMAPCONTEXTPRIV_H_ */


