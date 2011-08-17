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
#	if defined(RIP_EXPORT_DYNAMIC)
#		define RIP_EXTERN extern "C" DLLEXPORT
#	else
#		define RIP_EXTERN extern "C" DLLIMPORT 
#	endif
#else
#	define RIP_EXTERN extern "C"
#endif

#else
#if defined(__WIN32__)
#	if defined(RIP_EXPORT_DYNAMIC)
#		define RIP_EXTERN extern DLLEXPORT
#	else
#		define RIP_EXTERN extern DLLIMPORT 
#	endif
#else
	#define RIP_EXTERN extern
#endif
#endif /* __cplusplus */

typedef struct RIP {

	CGContextDelegateRef ctxDelegate;

} *RIPRef;

RIP_EXTERN int RIPLayerDepthForFormat(int index);

RIP_EXTERN CGContextDelegateRef __CGBitmapContextDelegateCreate(CGBitmapContextInfoRef bitmapContextInfo, 
															   CFDictionaryRef theDict);

RIP_EXTERN uint32_t ripc_InitializeFormat(CGBitmapContextInfoRef bitmapContextInfo);

RIP_EXTERN RIPRef ripc_Initialize(RIPRef rip);

RIP_EXTERN int CGBlt_depth(const char *encoding);

RIP_EXTERN CGError ripc_DrawImage(CGContextDelegateRef ctxDelegate, 
								  CGRenderingStateRef rendering,
								  CGGStateRef state,
								  CGRect rect,
								  CGImage image);

//RIP_EXTERN Boolean RIPLayerInitialize();

#endif /* LIBRIP_H_ */