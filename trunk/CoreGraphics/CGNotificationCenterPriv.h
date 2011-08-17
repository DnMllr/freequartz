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
#ifndef CGNOTIFICATIONCENTERPRIV_H_
#define CGNOTIFICATIONCENTERPRIV_H_

#include <CoreFoundation/CFRuntime.h>
#include "CGContextPriv.h"

CF_EXTERN_C_BEGIN


//sizeof = 0x38 + 0x08 = 0x40(64)
typedef struct CGNotificationCenter {

	CFRuntimeBase obj;					//0x00
	
	//pthread_mutex_t* mutex;				//0x08


} CGNotificationCenter, *CGNotificationCenterRef;


CG_EXTERN CFTypeID CGNotificationCenterGetTypeID(void);

CG_EXTERN CGNotificationCenterRef CGNotificationCenterCreate();

CG_EXTERN void CGNotificationCenterPostNotification(CGNotificationCenterRef notifCenter, 
													CFStringRef ref, 
													CFTypeRef cftype,
													bool isSingleton);

void center_finalize(CFTypeRef cf);

Boolean CGRegistryEntryRelease();


CF_EXTERN_C_END

#endif /* CGNOTIFICATIONCENTERPRIV_H_ */


