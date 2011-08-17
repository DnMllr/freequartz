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
#include <pthread.h>

#include "CGBasePriv.h"
#include "CGContextPriv.h"
#include "CGLayerPriv.h"



static CFRuntimeClass CGLayerClass = 
  {
    0,							// version
    "CGLayer",					// className
    0,							// init
    0,							// copy
    layerFinalize,				// finalize
	0,							// equal
	0,							// hash
	0,							// copyFormattingDesc
	0							// copyDebugDesc
  };
CFTypeID __kCGLayerID = _kCFRuntimeNotATypeID;

//constants
#if 0
// NEED TO ADD DEPENDENCY TO COREFOUNDATION
CONST_STRING_DECL(kCGLayerWillDeallocate,   "kCGLayerWillDeallocate");
#endif

static pthread_once_t layer_once = PTHREAD_ONCE_INIT;
static CGNotificationCenterRef layerNotificationCenter = NULL;



CFTypeID CGLayerGetTypeID(void)
{
	return CGTypeRegisterWithCallbacks(&__kCGLayerID, &CGLayerClass);
}

void layerFinalize(CFTypeRef layer)
{
	CGNotificationCenterRef notifCenter;

	notifCenter = CGLayerNotificationCenter((CGLayerRef)layer);
	//CGNotificationCenterPostNotification(notifCenter, kCGLayerWillDeallocate, layer, 0);

	CGContextRelease(((CGLayerRef)layer)->ctx);
}


static void
layerCreateNotificationCenter(void)
{
	layerNotificationCenter = CGNotificationCenterCreate();
}

CGNotificationCenterRef CGLayerNotificationCenter(CGLayerRef layer)
{
	CGNotificationCenterRef notifCenter;

	if (layerNotificationCenter == NULL) {
		notifCenter = layerNotificationCenter;
		pthread_once(&layer_once, layerCreateNotificationCenter);
	}
	else {
		notifCenter = layerNotificationCenter;
	}

	return notifCenter;
}






