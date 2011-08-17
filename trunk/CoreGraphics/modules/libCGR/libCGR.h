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
#ifndef LIBRIP_H_
#define LIBRIP_H_

#include <CoreGraphics/CoreGraphics.h>
#include "CGBitmapContextPriv.h"



#ifdef __cplusplus

#if defined(__WIN32__)
#	if defined(CGR_EXPORT_DYNAMIC)
#		define CGR_EXTERN extern "C" DLLEXPORT
#	else
#		define CGR_EXTERN extern "C" DLLIMPORT 
#	endif
#else
#	define CGR_EXTERN extern "C"
#endif

#else
#if defined(__WIN32__)
#	if defined(CGR_EXPORT_DYNAMIC)
#		define CGR_EXTERN extern DLLEXPORT
#	else
#		define CGR_EXTERN extern DLLIMPORT 
#	endif
#else
	#define CGR_EXTERN extern
#endif
#endif /* __cplusplus */

typedef struct CGR {

	CGContextDelegateRef ctxDelegate;

} *CGRRef;

CGR_EXTERN int CGRLayerDepthForFormat(int index);

CGR_EXTERN CGContextDelegateRef __CGBitmapContextDelegateCreate(CGBitmapContextInfoRef bitmapContextInfo, 
															   CFDictionaryRef theDict);

CGR_EXTERN uint32_t cgrc_InitializeFormat(CGBitmapContextInfoRef bitmapContextInfo);

//CGR_EXTERN CGRRef cgrc_Initialize(RIPRef rip);

CGR_EXTERN CGError cgrc_DrawImage(CGContextDelegateRef ctxDelegate, 
								  CGRenderingStateRef rendering,
								  CGGStateRef state,
								  CGRect rect,
								  CGImage image);


#endif /* LIBRIP_H_ */