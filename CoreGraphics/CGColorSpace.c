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
#include <CoreGraphics/CGColorSpace.h>
#include <pthread.h>

#include "CGBasePriv.h"
#include "CGColorSpacePriv.h"
#include "CGNotificationCenterPriv.h"

static pthread_once_t			__space_create_once = PTHREAD_ONCE_INIT;
static CFMutableDictionaryRef	__name_to_index_map = NULL;

static pthread_once_t			__csNotifCenter_create_once = PTHREAD_ONCE_INIT;
static CGNotificationCenterRef  __csNotifCenter = NULL;


/* color space constants */
CG_CONST_STRING_DECL(kCGColorSpaceDisplayGray,				"kCGColorSpaceDisplayGray");
CG_CONST_STRING_DECL(kCGColorSpaceDisplayRGB,				"kCGColorSpaceDisplayRGB");
CG_CONST_STRING_DECL(kCGColorSpaceDeviceGray,				"kCGColorSpaceDeviceGray");
CG_CONST_STRING_DECL(kCGColorSpaceDeviceRGB,				"kCGColorSpaceDeviceRGB");
CG_CONST_STRING_DECL(kCGColorSpaceDeviceCMYK,				"kCGColorSpaceDeviceCMYK");
CG_CONST_STRING_DECL(kCGColorSpaceSystemDefaultGray,		"kCGColorSpaceSystemDefaultGray");
CG_CONST_STRING_DECL(kCGColorSpaceSystemDefaultRGB,			"kCGColorSpaceSystemDefaultRGB");
CG_CONST_STRING_DECL(kCGColorSpaceSystemDefaultCMYK,		"kCGColorSpaceSystemDefaultCMYK");
CG_CONST_STRING_DECL(kCGColorSpaceUncalibratedGray,			"kCGColorSpaceUncalibratedGray");
CG_CONST_STRING_DECL(kCGColorSpaceUncalibratedRGB,			"kCGColorSpaceUncalibratedRGB");
CG_CONST_STRING_DECL(kCGColorSpaceUncalibratedCMYK,			"kCGColorSpaceUncalibratedCMYK");
CG_CONST_STRING_DECL(kCGColorSpaceGenericHDR,				"kCGColorSpaceGenericHDR");
CG_CONST_STRING_DECL(kCGColorSpaceGenericRGBHDR,			"kCGColorSpaceGenericRGBHDR");
CG_CONST_STRING_DECL(kCGColorSpaceUndo601,					"kCGColorSpaceUndo601");
CG_CONST_STRING_DECL(kCGColorSpaceColoredPattern,			"kCGColorSpaceColoredPattern");
CG_CONST_STRING_DECL(kCGColorSpaceGenericGray,				"kCGColorSpaceGenericGray");

/* color space notifications */
CG_CONST_STRING_DECL(kCGColorSpaceWillDeallocate,			"kCGColorSpaceWillDeallocate");




/* CoreFoundation runtime class for CGPath.  */
static CFRuntimeClass CGColorSpaceClass =  {
    0,							/* version */
    "CGColorSpace",				/* Name of class.  */
    0,							/* init */
    0,							/* copy  */
    csFinalize,					/* finalize  */
	0,							/* equal  */
	0,							/* hash  */
	0,							/* copyFormattingDesc */
	0							/* copyDebugDesc */
  };
CFTypeID __kCGColorSpaceID = _kCFRuntimeNotATypeID;

CFTypeID CGColorSpaceGetTypeID(void)
{	
	return CGTypeRegisterWithCallbacks(&__kCGColorSpaceID, &CGColorSpaceClass );
}

void csFinalize(CFTypeRef ctf)
{
	CGColorSpaceRef cs;
	bool isSingleton;
	CGNotificationCenterRef csNotifCenter;

	cs = (CGColorSpaceRef)ctf;
	isSingleton = cs->isSingleton;
	assert( isSingleton == FALSE );

	csNotifCenter = getNotificationCenter(FALSE);
	if (csNotifCenter) {

		CGNotificationCenterPostNotification(csNotifCenter, kCGColorSpaceWillDeallocate, ctf, isSingleton);
	}
	//.....
}

void csNotificationCenterCreate(void)
{
	__csNotifCenter = CGNotificationCenterCreate();
}

CGNotificationCenterRef getNotificationCenter(bool notFinalize)
{
	if (__csNotifCenter == NULL && notFinalize == TRUE) {
		pthread_once(&__csNotifCenter_create_once, csNotificationCenterCreate);
	}

	return __csNotifCenter;
}


void create_name_to_index_map(void)
{
	
}

CFIndex CGColorSpaceGetIndexForName(CFStringRef name)
{
	CFIndex ret;

	if (__name_to_index_map == NULL) {
		pthread_once(&__space_create_once, create_name_to_index_map);
	}
	if (name)
		ret = (CFIndex)CFDictionaryGetValue(__name_to_index_map, (const void*)name);
	else
		ret = 0;

	return ret;
}



bool CGColorSpaceEqualToColorSpace(CGColorSpaceRef cs1, CGColorSpaceRef cs2)
{
	if (cs1 == cs2)
		return TRUE;

	if (cs1->spaceType == cs2->spaceType) {

	}


	return FALSE;
}

CGColorSpaceType CGColorSpaceGetType(CGColorSpaceRef space)
{
	if (!space)
		return kCGColorSpaceTypeDeviceUnknown;

	return space->spaceType;
}

CGFloat* CGColorSpaceGetDefaultColorComponents(CGColorSpaceRef space)
{
	return NULL;
}

CGColorRef CGColorSpaceCopyDefaultColor(CGColorSpaceRef space)
{
	CGColorRef color;
	float* components;

	if (!space)
		return NULL;
	
	components = CGColorSpaceGetDefaultColorComponents(space);
	if (!components || CGColorSpaceGetType(space) == kCGColorSpaceTypeDeviceUnknown)
		return space->defaultColor; 

	color = CGColorCreate(space, components);

	return color;
}

CGColorSpaceRef CGColorSpaceCreateDeviceGray(void)
{
	return CGColorSpaceCreateWithIndex(3);
}


CGColorSpaceRef CGColorSpaceCreateDeviceRGB(void)
{
	return CGColorSpaceCreateWithIndex(4);
}

CGColorSpaceRef CGColorSpaceCreateWithName(CFStringRef name)
{
	CFIndex index;

	index = CGColorSpaceGetIndexForName(name);
	return CGColorSpaceCreateWithIndex(index);
}



CGColorSpaceRef CGColorSpaceCreateWithIndex(int index)
{
	return NULL;
}


void CGColorSpaceRelease(CGColorSpaceRef space)
{
	if (!space) { return; }
	CFRelease((CFTypeRef) space);
}

CGColorSpaceRef CGColorSpaceRetain(CGColorSpaceRef space)
{
	if (!space) { return 0; }
	
	CFRetain((CFTypeRef) space);

	return space;
}

CGColorSpaceModel CGColorSpaceGetModel(CGColorSpaceRef space)
{
	if (!space) { return kCGColorSpaceModelUnknown; }
	return space->spaceModel;
}

size_t CGColorSpaceGetNumberOfComponents(CGColorSpaceRef space)
{
	if (!space) { return 0; }
	return space->numberOfComponents;
}