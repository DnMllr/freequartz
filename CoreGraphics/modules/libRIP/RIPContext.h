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
#ifndef RIPCONTEXT_H_
#define RIPCONTEXT_H_

#include <mach/mach_time.h>
#include "RIPBase.h"
#include "RIPDevice.h"

typedef struct RIPContext {

	CGContextDelegateRef ctxDelegate;		//+8
	CGColorTransformRef colorTransform;		//+20
	mach_timebase_info_data_t info;			//0x1C
	RIPDeviceRef ripd;						//+36

} RIPContext, *RIPContextRef;


RIP_EXTERN CGContextDelegateRef _CGBitmapContextDelegateCreate(CGBitmapContextInfoRef bitmapContextInfo, 
															   CFDictionaryRef theDict);

RIP_EXTERN CGContextDelegateRef _CGWindowContextDelegateCreate(CGBitmapContextInfoRef bitmapContextInfo, 
															   CFDictionaryRef theDict);

RIP_EXTERN RIPContextRef ripc_Initialize();


RIP_EXTERN CGError	ripc_DrawPath(CGContextDelegateRef ctxDelegate, CGRenderingStateRef rendering,
								  CGGStateRef state, CGPathDrawingMode mode, CGMutablePathRef path);

RIP_EXTERN CGError	ripc_DrawLines(CGContextDelegateRef ctxDelegate, CGRenderingStateRef rendering, 
								  CGGStateRef state, const CGPoint points[], size_t count);

RIP_EXTERN bool		ripc_GetRenderingState(CGContextDelegateInfoRef info, CGRenderingStateRef rendering, CGGStateRef state);


RIP_EXTERN uint32_t ripc_InitializeFormat(CGBitmapContextInfoRef bitmapContextInfo);





#endif /* RIPCONTEXT_H_ */