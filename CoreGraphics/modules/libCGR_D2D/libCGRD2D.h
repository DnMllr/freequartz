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
#ifndef LIBCGRD2D_H_
#define LIBCGRD2D_H_

#include <CoreGraphics/CoreGraphics.h>
#include "CGBitmapContextPriv.h"



#ifdef __cplusplus

#if defined(__WIN32__)
#	if defined(CGRD2D_EXPORT_DYNAMIC)
#		define CGRD2D_EXTERN extern "C" DLLEXPORT
#	else
#		define CGRD2D_EXTERN extern "C" DLLIMPORT 
#	endif
#else
#	define CGRD2D_EXTERN extern "C"
#endif

#else
#if defined(__WIN32__)
#	if defined(CGRD2D_EXPORT_DYNAMIC)
#		define CGRD2D_EXTERN extern DLLEXPORT
#	else
#		define CGRD2D_EXTERN extern DLLIMPORT 
#	endif
#else
	#define CGRD2D_EXTERN extern
#endif
#endif /* __cplusplus */


typedef struct RIP {

	CGContextDelegateRef ctxDelegate;

} *RIPRef;

CGRD2D_EXTERN CGContextDelegateRef 
__CGBitmapContextDelegateCreate(CGBitmapContextInfoRef bitmapContextInfo, CFDictionaryRef theDict);

uint32_t	d2d_InitializeFormat(CGBitmapContextInfoRef bitmapContextInfo);
RIPRef		d2d_Initialize(RIPRef rip);

CGError		d2d_Operation(CGContextDelegateRef ctxDelegate,
						  CGRenderingStateRef rendering, 
						  CGGStateRef state,
						  CFStringRef op, 
						  void* tmp);


int			D2DLayerDepthForFormat(int index);

#endif /* LIBCGRD2D_H_ */