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
#include <CoreGraphics/CGContext.h>

#include "CGBasePriv.h"
#include "CGNotificationCenterPriv.h"

static CFRuntimeClass CGNotificationCenterClass = 
 {
    0,							// version
    "CGNotificationCenter",		// className
    0,							// init
    0,							// copy
    center_finalize,			// finalize
	0,							// equal
	0,							// hash
	0,							// copyFormattingDesc
	0							// copyDebugDesc
  };
CFTypeID __kCGNotificationCenterID = _kCFRuntimeNotATypeID;


CFTypeID CGNotificationCenterGetTypeID(void)
{
	return CGTypeRegisterWithCallbacks(&__kCGNotificationCenterID, &CGNotificationCenterClass);
}


CGNotificationCenterRef CGNotificationCenterCreate()
{
	return NULL;
}

void center_finalize(CFTypeRef cf)
{
	CGNotificationCenterRef center = (CGNotificationCenterRef) cf;

	//CGNotificationCenterRemoveCallbacks(center, NULL);
	//pthread_mutex_destroy()
}


void 
CGNotificationCenterPostNotification(CGNotificationCenterRef notifCenter, CFStringRef ref, 
													CFTypeRef cftype, bool isSingleton)
{

}