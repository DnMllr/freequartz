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

static CGColorSpaceRef			named_color_spaces[16] = {0};



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


#if 0
static CGColorSpaceCallbacks indexed_vtable =  {
	0,
	indexed_equal,
	indexed_finalize,
	indexed_get_md5,
	indexed_get_default_color_components,
	0,
	indexed_create_resolved,
	0
};

static CGColorSpaceCallbacks pattern_vtable =  {
	0,
	pattern_equal,
	pattern_finalize,
	pattern_get_md5,
	pattern_get_default_color_components,
	pattern_create_default_color,
	pattern_create_resolved,
	0
};

static CGColorSpaceCallbacks device_gray_vtable =  {
	0,
	0,
	0,
	device_gray_get_md5,
	device_get_default_color_components,
	0,
	device_create_resolved,
	0
};

static CGColorSpaceCallbacks device_rgb_vtable =  {
	0,
	0,
	0,
	device_rgb_get_md5,
	device_get_default_color_components,
	0,
	device_create_resolved,
	0
};

static CGColorSpaceCallbacks device_cmyk_vtable =  {
	0,
	0,
	0,
	device_cmyk_get_md5,
	device_get_default_color_components,
	0,
	device_create_resolved,
	0
};
#endif

CFTypeID CGColorSpaceGetTypeID(void)
{	
	return CGTypeRegisterWithCallbacks(&__kCGColorSpaceID, &CGColorSpaceClass );
}

void csFinalize(CFTypeRef ctf)
{
	/*CGColorSpaceRef cs;
	bool isSingleton;
	CGNotificationCenterRef csNotifCenter;

	cs = (CGColorSpaceRef)ctf;
	isSingleton = cs->isSingleton;
	assert( isSingleton == FALSE );

	csNotifCenter = getNotificationCenter(FALSE);
	if (csNotifCenter) {

		CGNotificationCenterPostNotification(csNotifCenter, kCGColorSpaceWillDeallocate, ctf, isSingleton);
	}*/
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

	return color_space_state_equal(cs1->state, cs2->state);
}

bool color_space_state_equal(CGColorSpaceStateRef state1, CGColorSpaceStateRef state2)
{
	return false;
}



CGColorSpaceType CGColorSpaceGetType(CGColorSpaceRef space)
{
	if (!space)
		return kCGColorSpaceTypeDeviceUnknown;

	return space->state->spaceType;
}

CGFloat* CGColorSpaceGetDefaultColorComponents(CGColorSpaceRef space)
{
	return NULL;
}

CGColorRef CGColorSpaceCopyDefaultColor(CGColorSpaceRef space)
{
	CGColorRef color;
	/*float* components;

	if (!space)
		return NULL;
	
	components = CGColorSpaceGetDefaultColorComponents(space);
	if (!components || CGColorSpaceGetType(space) == kCGColorSpaceTypeDeviceUnknown)
		return space->defaultColor; 

	color = CGColorCreate(space, components);*/

	return color;
}


CGColorSpaceRef CGColorSpaceCreateDisplayGray()			{ return CGColorSpaceCreateWithIndex((int) 1); }
CGColorSpaceRef CGColorSpaceCreateDisplayRGB()			{ return CGColorSpaceCreateWithIndex((int) 2); }
CGColorSpaceRef CGColorSpaceCreateDeviceGray()			{ return CGColorSpaceCreateWithIndex((int) 3); }
CGColorSpaceRef CGColorSpaceCreateDeviceRGB()			{ return CGColorSpaceCreateWithIndex((int) 4); }
CGColorSpaceRef CGColorSpaceCreateDeviceCMYK()			{ return CGColorSpaceCreateWithIndex((int) 5); }
CGColorSpaceRef CGColorSpaceCreateSystemDefaultGray()	{ return CGColorSpaceCreateWithIndex((int) 6); }
CGColorSpaceRef CGColorSpaceCreateSystemDefaultRGB()	{ return CGColorSpaceCreateWithIndex((int) 7); }
CGColorSpaceRef CGColorSpaceCreateSystemDefaultCMYK()	{ return CGColorSpaceCreateWithIndex((int) 8); }


CGColorSpaceRef CGColorSpaceCreateWithName(CFStringRef name)
{
	CFIndex index;

	index = CGColorSpaceGetIndexForName(name);
	return CGColorSpaceCreateWithIndex(index);
}



CGColorSpaceRef CGColorSpaceCreateWithIndex(int index)
{
	CGColorSpaceRef colorSpace;
	CGColorSpaceModel colorModel;
	//CFStringRef profilePath;
	
	if (index < 0 || index > 5)
		return NULL;

	if (named_color_spaces[index] != 0)
	{
		colorSpace = named_color_spaces[index];
	}
	else
	{
		//pthread_once(&create_named_color_spaces_mutex, loadBitmapContextDelegateCreator);
		switch(index)
		{
		/* display space type */
		case 1: { colorSpace = create_display_color_space(1); break; } //CGColorSpaceCreateDisplayGray
		case 2: { colorSpace = create_display_color_space(3); break; } //CGColorSpaceCreateDisplayRGB
		/* device space type */
		case 3: { colorSpace = create_device_color_space(1); break; } // CGColorSpaceCreateDeviceGray
		case 4: { colorSpace = create_device_color_space(3); break; } // CGColorSpaceCreateDeviceRGB
		case 5: { colorSpace = create_device_color_space(4); break; } // CGColorSpaceCreateDeviceCMYK

		default:
			colorSpace = NULL;
			break;

		}
	}
	CGColorSpaceRetain(colorSpace);
	
	return colorSpace;
}

CGColorSpaceRef create_display_color_space(size_t numComponents)
{
	CGColorSpaceRef colorSpace;

	if (numComponents == 1)
	{
		colorSpace = CGColorSpaceCreateDisplayGrayWithID(0);
	}
	else if (numComponents == 3)
	{
		colorSpace = CGColorSpaceCreateDisplayRGBWithID(0);
	}

	return NULL;
}

CGColorSpaceRef CGColorSpaceCreateDisplayGrayWithID(int id)
{
	return create_display_space_with_id(1, id);
}

CGColorSpaceRef CGColorSpaceCreateDisplayRGBWithID(int id)
{
	return create_display_space_with_id(3, id);
}

CGColorSpaceRef create_display_space_with_id(size_t numComponents, int id)
{
	CGColorSpaceRef colorSpace;

	colorSpace = CGColorSpaceCreate(kCGColorSpaceTypeICC, numComponents);
	if (colorSpace)
	{
		colorSpace->state->id = id;
		if (numComponents == 1)
		{
			colorSpace = CGColorSpaceCreate(kCGColorSpaceTypeDeviceGray, 3);
		}
	}

	return colorSpace;
}


CGColorSpaceRef create_device_color_space(size_t numComponents)
{
	CGColorSpaceRef colorSpace;
	
	if (numComponents == 1)
	{
		colorSpace = CGColorSpaceCreate(kCGColorSpaceTypeDeviceGray, 3);
	}
	else if (numComponents == 3)
	{
		colorSpace = CGColorSpaceCreate(kCGColorSpaceTypeDeviceRGB, 3);
	}
	else if (numComponents == 4)
	{
		colorSpace = CGColorSpaceCreate(kCGColorSpaceTypeDeviceCMYK, 3);
	}
	else
	{
		abort();
	}

	return colorSpace;
}

CGColorSpaceRef CGColorSpaceCreate(CGColorSpaceType type, size_t numberOfComponents)
{
	CGColorSpaceRef colorSpace;
	CGColorSpaceStateRef csState;
	int size;

	switch(type)
	{
	case kCGColorSpaceTypeDeviceGray:
		size = 0x34;
		/*R1 = 0x34; R12 = 0; R3 = device_gray_vtable; R11 = 0;*/
		break;
	case kCGColorSpaceTypeDeviceRGB:
		size = 0x34;
		/*R1 = 0x34; R12 = 1; R3 = device_rgb_vtable; R11 = 1;*/
		break;
	case kCGColorSpaceTypeDeviceCMYK:
		size = 0x34;
		/*R1 = 0x34; R12 = 2; R3 = device_cmyk_vtable; R11 = 2;*/
		break;
	case kCGColorSpaceTypeCalibratedGray:
		size = 0x50;
		/*R1 = 0x50; R12 = 0; R3 = calibrated_gray_vtable; R11 = 0;*/
		break;
	case kCGColorSpaceTypeCalibratedRGB:
		size = 0x7C;
		/*R1 = 0x7C; R12 = 1; R3 = calibrated_rgb_vtable; R11 = 1;*/
		break;
	case kCGColorSpaceTypeLab:
		size = 0x5C;
		/*R1 = 0x5C; R12 = 3; R3 = lab_vtable; R11 = 3;*/
		break;
	case kCGColorSpaceTypeICC:
		size = 0x60;
		/*R1 = 0x60; R12 = -1; R3 = icc_vtable; R11 = -1;*/
		break;
	case kCGColorSpaceTypeIndexed:
		size = 0x40;
		/*R1 = 0x40; R12 = -1; R3 = indexed_vtable; R11 = 5;*/
		break;
	case kCGColorSpaceTypeDeviceN:
		size = 0x44;
		/*R1 = 0x44; R12 = 4; R3 = deviceN_vtable; R11 = 4;*/
	case kCGColorSpaceTypePattern:
		size = 0x38;
		/*R1 = 0x38; R12 = -1; R3 = pattern_vtable; R11 = 6;*/
		break;
	default:
		break;
	}

	csState = (CGColorSpaceStateRef) calloc(1, size);
	csState->unknown04 = FALSE;
	csState->isUncalibrated = FALSE;
	csState->supportsOuput = TRUE;
	csState->unknown07 = FALSE;
	csState->unknown08 = FALSE;


	colorSpace = CGColorSpaceCreateWithState(csState);

	return colorSpace;
}


CGColorSpaceRef CGColorSpaceCreateWithState(CGColorSpaceStateRef colorSpaceState)
{
	CGColorSpaceRef colorSpace;

	colorSpace = (CGColorSpaceRef)CGTypeCreateInstance(CGColorSpaceGetTypeID(), sizeof(CGColorSpace) - sizeof(CFRuntimeBase));
	colorSpace->state = color_space_state_retain(colorSpaceState);

	return colorSpace;
}

void color_space_state_release(CGColorSpaceStateRef colorSpaceState)
{

}

CGColorSpaceStateRef color_space_state_retain(CGColorSpaceStateRef colorSpaceState)
{
	if (!colorSpaceState) { return NULL; }

	// TODO
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
	if (!space || !space->state) { return kCGColorSpaceModelUnknown; }
	return space->state->spaceModel;
}

size_t CGColorSpaceGetNumberOfComponents(CGColorSpaceRef space)
{
	if (!space || !space->state) { return 0; }
	return space->state->numberOfComponents;
}

CGColorSpaceRef CGColorSpaceGetBaseColorSpace(CGColorSpaceRef cs)
{
	CGColorSpaceRef baseColorSpace;

	if (cs->state->spaceModel == kCGColorSpaceModelIndexed ||
		cs->state->spaceModel == kCGColorSpaceModelPattern)
	{
		baseColorSpace = cs->state->baseColorSpace;
	}
	else
	{
		baseColorSpace = NULL;
	}

	return baseColorSpace;
}

size_t CGColorSpaceGetColorTableCount(CGColorSpaceRef cs)
{
  return 0;
}

void CGColorSpaceGetColorTable(CGColorSpaceRef space, uint8_t *table)
{

}