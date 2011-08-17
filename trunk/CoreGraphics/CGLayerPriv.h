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
#ifndef CGLAYERPRIV_H_
#define CGLAYERPRIV_H_

#include "CoreFoundation/CFRuntime.h"
#include "CGTypesPriv.h"
#include "CGNotificationCenterPriv.h"

CF_EXTERN_C_BEGIN

//sizeof = 0x0C + 0x08 = 0x14
typedef  struct CGLayer {

	CFRuntimeBase obj;					//0x00
	CGContextRef ctx;					//0x08

} CGLayer, *CGLayerRef;



CG_EXTERN CGNotificationCenterRef CGLayerNotificationCenter(CGLayerRef layer);



void layerFinalize(CFTypeRef c);




CF_EXTERN_C_END

#endif /* CGLAYERPRIV_H_ */


