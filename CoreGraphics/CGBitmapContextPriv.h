#ifndef CGBITMAPCONTEXTPRIV_H_
#define CGBITMAPCONTEXTPRIV_H_

#include "CGBasePriv.h"
#include "CGContextPriv.h"

CG_EXTERN_C_BEGIN

typedef CGContextDelegateRef  (*_CGBitmapContextDelegateCreate)(
	CGBitmapContextInfoRef bitmapContextInfo, 
	CFDictionaryRef theDict);

CG_EXTERN void loadBitmapContextDelegateCreator(void);


CG_EXTERN CGBitmapContextInfoRef CGBitmapContextInfoCreate(size_t bitsPerComponent,
												 size_t bytesPerRow,
												 CGColorSpaceRef colorspace, 
												 CGBitmapInfo bitmapInfo, 
												 CGFloat hRes,
												 Boolean a,
												 Boolean b,
												 Boolean c,
												 Boolean d,
												 Boolean e,
												 CGFloat vRes,
												 CFDictionaryRef theDict);

CG_EXTERN CGContextRef CGBitmapContextCreateWithDictionary(void *data, 
												 size_t width, size_t height, 
												 size_t bitsPerComponent, 
												 size_t bytesPerRow,
												 CGColorSpaceRef colorspace, 
												 CGBitmapInfo bitmapInfo,
												 CGFloat hRes, 
												 CGFloat vRes, 
												 CFDictionaryRef theDict);



CG_EXTERN void * CGBitmapAllocateData(size_t len);

CG_EXTERN void CGBitmapFreeData(void *data);

CG_EXTERN size_t CGBitmapGetAlignedBytesPerRow(size_t len);


CG_EXTERN CGContextRef createBitmapContext(CGBitmapContextInfoRef bitmapContextInfo, 
										   CFDictionaryRef theDict, const char* name);

void finalize_bitmap_context(CGContextRef context);

void release_bitmap_info(CGBitmapContextInfoRef bitmapInfo);

bool validate_gray_bitmap_info(CGBitmapContextInfoRef bitmapContextInfo);

bool validate_rgb_bitmap_info(CGBitmapContextInfoRef bitmapContextInfo);

bool validate_gray_bitmap_info(CGBitmapContextInfoRef bitmapContextInfo);

bool validate_cmyk_bitmap_info(CGBitmapContextInfoRef bitmapContextInfo);


CG_EXTERN_C_END

#endif /* CGBITMAPCONTEXTPRIV_H_ */


