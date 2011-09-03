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

static CGColorSpaceRef			named_color_spaces[17] = {0};



/* color space constants */
CG_CONST_STRING_DECL(kCGColorSpaceDisplayGray,				"kCGColorSpaceDisplayGray");
CG_CONST_STRING_DECL(kCGColorSpaceDisplayRGB,				"kCGColorSpaceDisplayRGB");
CG_CONST_STRING_DECL(kCGColorSpaceDeviceGray,				"kCGColorSpaceDeviceGray");
CG_CONST_STRING_DECL(kCGColorSpaceDeviceRGB,				"kCGColorSpaceDeviceRGB");
CG_CONST_STRING_DECL(kCGColorSpaceDeviceCMYK,				"kCGColorSpaceDeviceCMYK");
CG_CONST_STRING_DECL(kCGColorSpaceSystemDefaultGray,		"kCGColorSpaceSystemDefaultGray");
CG_CONST_STRING_DECL(kCGColorSpaceSystemDefaultRGB,			"kCGColorSpaceSystemDefaultRGB");
CG_CONST_STRING_DECL(kCGColorSpaceSystemDefaultCMYK,		"kCGColorSpaceSystemDefaultCMYK");
CG_CONST_STRING_DECL(kCGColorSpaceCalibratedGray,			"kCGColorSpaceCalibratedGray");
CG_CONST_STRING_DECL(kCGColorSpaceCalibratedRGB,			"kCGColorSpaceCalibratedRGB");
CG_CONST_STRING_DECL(kCGColorSpaceUncalibratedGray,			"kCGColorSpaceUncalibratedGray");
CG_CONST_STRING_DECL(kCGColorSpaceUncalibratedRGB,			"kCGColorSpaceUncalibratedRGB");
CG_CONST_STRING_DECL(kCGColorSpaceUncalibratedCMYK,			"kCGColorSpaceUncalibratedCMYK");
CG_CONST_STRING_DECL(kCGColorSpaceGenericHDR,				"kCGColorSpaceGenericHDR");
CG_CONST_STRING_DECL(kCGColorSpaceGenericRGBHDR,			"kCGColorSpaceGenericRGBHDR");
CG_CONST_STRING_DECL(kCGColorSpaceUndo601,					"kCGColorSpaceUndo601");
CG_CONST_STRING_DECL(kCGColorSpaceColoredPattern,			"kCGColorSpaceColoredPattern");
CG_CONST_STRING_DECL(kCGColorSpaceGenericGray,				"kCGColorSpaceGenericGray");
CG_CONST_STRING_DECL(kCGColorSpaceLAB,						"kCGColorSpaceLAB");
CG_CONST_STRING_DECL(kCGColorSpaceIndexed,					"kCGColorSpaceIndexed");
CG_CONST_STRING_DECL(kCGColorSpaceDeviceN,					"kCGColorSpaceDeviceN");



/* color space notifications */
CG_CONST_STRING_DECL(kCGColorSpaceWillDeallocate,			"kCGColorSpaceWillDeallocate");




/* CoreFoundation runtime class for CGPath.  */
static CFRuntimeClass CGColorSpaceClass =  {
    0,							/* version */
    "CGColorSpace",				/* Name of class.  */
    0,							/* init */
    0,							/* copy  */
    cs_finalize,				/* finalize  */
	cs_equal,					/* equal  */
	0,							/* hash  */
	0,							/* copyFormattingDesc */
	cs_copy_debug_description	/* copyDebugDesc */
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
};

static CGColorSpaceCallbacks pattern_vtable =  {
	0,
	pattern_equal,
	pattern_finalize,
	pattern_get_md5,
	pattern_get_default_color_components,
	pattern_create_default_color,
	pattern_create_resolved,
};
#endif

static unsigned char device_gray_md5[16] = { 
	0x32, 0x53, 0xAB, 0x07, 0xA5, 0xC6, 0xC9, 0x79,
	0x65, 0x67, 0x94, 0x70, 0x4C, 0x2F, 0x58, 0x82
};
static CGColorSpaceCallbacks device_gray_vtable =  {
	0,
	0,
	0,
	device_gray_get_md5,
	device_get_default_color_components,
	0,
	device_create_resolved,
};


static unsigned char device_rgb_md5[16] = { 
	0x1B, 0x84, 0x38, 0x33, 0xBC, 0xA1, 0xF9, 0xF8,
	0x75, 0x60, 0xC5, 0xBA, 0x33, 0x90, 0xDB, 0x62
};

static CGColorSpaceCallbacks device_rgb_vtable =  {
	0,
	0,
	0,
	device_rgb_get_md5,
	device_get_default_color_components,
	0,
	device_create_resolved,
};

#if 0
static CGColorSpaceCallbacks device_cmyk_vtable =  {
	0,
	0,
	0,
	device_cmyk_get_md5,
	device_get_default_color_components,
	0,
	device_create_resolved,
};
#endif

CFTypeID CGColorSpaceGetTypeID(void)
{	
	return CGTypeRegisterWithCallbacks(&__kCGColorSpaceID, &CGColorSpaceClass );
}


void device_gray_get_md5(unsigned char* md5)
{
	memcpy(md5, device_gray_md5, 16);
}

void device_rgb_get_md5(unsigned char* md5)
{
	memcpy(md5, device_rgb_md5, 16);
}

CGFloat* device_get_default_color_components(CGColorSpaceRef cs)
{
	// IMPLEMENT HERE
	return NULL;
}

CGColorSpaceRef device_create_resolved(CGColorSpaceRef cs)
{
	// IMPLEMENT HERE
	return NULL;
}


void cs_finalize(CFTypeRef ctf)
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

Boolean cs_equal(CFTypeRef cf1, CFTypeRef cf2)
{
	return CGColorSpaceEqualToColorSpace((CGColorSpaceRef)cf1, (CGColorSpaceRef)cf2);
}

CFHashCode cs_hash(CFTypeRef cf)
{
	CFHashCode hash;
	CGColorSpaceRef cs;

	cs = (CGColorSpaceRef)cf;
	if (!cs | !cs->state) 
		return 0;

	/*if (cs->state->callbacks)
		hash = cs->state->callbacks->getMD5(*/
	
	return hash;
}


CFStringRef cs_copy_debug_description(CFTypeRef cf)
{
	CGColorSpaceRef cs;
	CFMutableStringRef msg;
	CFStringRef csTypeString = NULL;

	cs = (CGColorSpaceRef)cf;
	if (cs)
	{
		msg = CFStringCreateMutable(CFGetAllocator(cf), 0);
		switch(cs->state->spaceType)
		{
		case kCGColorSpaceTypeDeviceGray: { csTypeString = kCGColorSpaceDeviceGray; break; }
		case kCGColorSpaceTypeDeviceRGB: { csTypeString = kCGColorSpaceDeviceRGB; break; }
		case kCGColorSpaceTypeDeviceCMYK: { csTypeString = kCGColorSpaceDeviceCMYK; break; }
		case kCGColorSpaceTypeCalibratedGray: { csTypeString = kCGColorSpaceCalibratedGray; break; }
		case kCGColorSpaceTypeCalibratedRGB: { csTypeString = kCGColorSpaceCalibratedRGB; break; }
		case kCGColorSpaceTypeLab: { csTypeString = kCGColorSpaceLAB; break; }
		case kCGColorSpaceTypeIndexed: { csTypeString = kCGColorSpaceIndexed; break; }
		case kCGColorSpaceTypeDeviceN: { csTypeString = kCGColorSpaceDeviceN; break; }
		}

		//CFStringAppendFormat(CF
	}

	return csTypeString;
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

bool cs_equal(CGColorSpaceRef cs1, CGColorSpaceRef cs2)
{
	// IMPLEMENT HERE
	return FALSE;
}


bool CGColorSpaceEqualToColorSpace(CGColorSpaceRef cs1, CGColorSpaceRef cs2)
{
	if (cs1 == cs2)
		return TRUE;

	return color_space_state_equal(cs1->state, cs2->state);
}

bool color_space_state_equal(CGColorSpaceStateRef state1, CGColorSpaceStateRef state2)
{
	// IMPLEMENT HERE
	return false;
}


unsigned char* CGColorSpaceGetMD5Digest(CGColorSpaceRef space)
{
	unsigned char* digest;

	if (!space || !space->state)
		return NULL;

	if (space->state->md5)
	{
		digest = space->state->md5;
	}
	else
	{
		space->state->md5 = (unsigned char*) malloc(0x16);
		space->state->callbacks->getMD5(space->state->md5);
	}

	return digest;
}

CGColorSpaceType CGColorSpaceGetType(CGColorSpaceRef space)
{
	if (!space)
		return kCGColorSpaceTypeDeviceUnknown;

	return space->state->spaceType;
}

CGFloat* CGColorSpaceGetDefaultColorComponents(CGColorSpaceRef cs)
{
	return NULL;
}

CGColorRef CGColorSpaceCopyDefaultColor(CGColorSpaceRef space)
{
	CGColorRef color = NULL;
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
	CGColorSpaceRef cs;
	//CGColorSpaceModel colorModel;
	//CFStringRef profilePath;
	
	if (index > 17)
		return NULL;

	if (named_color_spaces[index] != 0)
	{
		cs = named_color_spaces[index];
	}
	else
	{
		switch(index)
		{
		/* display space type */
		case 1: { cs = create_display_color_space(1); break; } //CGColorSpaceCreateDisplayGray
		case 2: { cs = create_display_color_space(3); break; } //CGColorSpaceCreateDisplayRGB
		/* device space type */
		case 3: { cs = create_device_color_space(1); break; } // CGColorSpaceCreateDeviceGray
		case 4: { cs = create_device_color_space(3); break; } // CGColorSpaceCreateDeviceRGB
		case 5: { cs = create_device_color_space(4); break; } // CGColorSpaceCreateDeviceCMYK
        /* system default space type */
		case 6: { cs = create_generic_color_space(1); break; } //CGColorSpaceCreateSystemDefaultGray
		case 7: { cs = create_generic_color_space(3); break; } //CGColorSpaceCreateSystemDefaultGray
		case 8: { cs = create_generic_color_space(4); break; } //CGColorSpaceCreateSystemDefaultGray
		/* uncalibrated space type */
		case 9:  { cs = create_uncalibrated_color_space(1); break; } 
		case 10: { cs = create_uncalibrated_color_space(3); break; } 
		case 11: { cs = create_uncalibrated_color_space(4); break; } 
		/* pattern */
		case 14: { cs = CGColorSpaceCreate(kCGColorSpaceTypePattern, 0); cs->state->isSingleton = TRUE; break; }
		/* ICC profile */
		case 15: { cs = create_color_space_with_path(CFSTR("ColorSync/Profiles/AdobeRGB1998.icc")); break; } 
		case 16: { cs = create_color_space_with_path(CFSTR("ColorSync/Profiles/sRGB Profile.icc")); break; } 
		case 17: { cs = create_color_space_with_path(CFSTR("ColorSync/Profiles/Generic Gray Gamma 2.2 Profile.icc")); break; } 
		default: { cs = NULL; break; }
		}

		if (cs == NULL)
		{
			// Add some semphare/memory barrier/spin lock here - 
			cs = named_color_spaces[index];
		}
		else
		{
			// DISCREPANCY HERE !!!!!!!!!!!!!!!!!!!!!!!!!!!
			// Sometimes it's index and sometimes a float *
			//cs->state->index = index;
		}
	}

	



	CGColorSpaceRetain(cs);
	
	return cs;
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

CGColorSpaceRef CGColorSpaceCreateWithICCData()
{
	CGColorSpaceRef colorSpace = NULL;


	return colorSpace;
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
	CGColorSpaceRef csGray;
	CGColorSpaceStateICCRef csStateICC;

	colorSpace = CGColorSpaceCreate(kCGColorSpaceTypeICC, numComponents);
	if (colorSpace)
	{
		csStateICC = ((CGColorSpaceStateICCRef)(colorSpace->state));
		csStateICC->id = id;
		if (numComponents == 1)
		{
			csStateICC->state.spaceModel = kCGColorSpaceModelMonochrome;
			csStateICC->state.processColorModel = kCGColorSpaceModelMonochrome;
			csGray = CGColorSpaceCreateDeviceGray();
			if (csGray != NULL)
			{
				colorSpace->state->unknown07 = TRUE;
			}
			else
			{
				CGColorSpaceRelease(colorSpace);
				colorSpace = NULL;
			}

		}
	}

	return colorSpace;
}


CGColorSpaceRef create_device_color_space(size_t numComponents)
{
	CGColorSpaceRef colorSpace;
	
	if (numComponents == 1)
	{
		colorSpace = CGColorSpaceCreate(kCGColorSpaceTypeDeviceGray, numComponents);
	}
	else if (numComponents == 3)
	{
		colorSpace = CGColorSpaceCreate(kCGColorSpaceTypeDeviceRGB, numComponents);
	}
	else if (numComponents == 4)
	{
		colorSpace = CGColorSpaceCreate(kCGColorSpaceTypeDeviceCMYK, numComponents);
	}
	else
	{
		abort();
	}

	return colorSpace;
}


CGColorSpaceRef create_color_space_with_path(CFStringRef path)
{
	CGColorSpaceRef colorSpace = NULL;
	CFArrayRef paths;
	CGDataProviderRef provider;
	CFURLRef url, urlCopy;

	paths = CFCopySearchPathForDirectoriesInDomains(kCFLibraryDirectory, kCFSystemDomainMask, TRUE);
	if (paths)
	{
		for (int i=0; i < CFArrayGetCount(paths); i++)
		{
			url = (CFURLRef)CFArrayGetValueAtIndex(paths, i);
			urlCopy = CFURLCreateCopyAppendingPathComponent(NULL, url, path, FALSE);
			provider = CGDataProviderCreateWithURL(urlCopy);
			
			//IMPLEMENT HERE
		}

		//CFRelease(paths);
		//colorSpace = CGColorSpaceCreateWithICCData();
		//CGDataProviderRelease
	}


	return colorSpace;
}

CGColorSpaceRef create_generic_color_space(size_t numComponents)
{
	CGColorSpaceRef colorSpace;
	
	if (numComponents == 1)
		colorSpace = CGColorSpaceCreateDeviceGray();
	else if (numComponents == 3)
		colorSpace = CGColorSpaceCreateDeviceRGB();
	else if (numComponents == 4)
		colorSpace = CGColorSpaceCreateDeviceCMYK();
	else
		colorSpace = NULL;

	return colorSpace;
}

CGColorSpaceRef create_uncalibrated_color_space(size_t numComponents)
{
	CGColorSpaceRef colorSpace;

	colorSpace = create_device_color_space(numComponents);
	colorSpace->state->isUncalibrated = TRUE;

	return colorSpace;
}


CGColorSpaceRef CGColorSpaceCreate(CGColorSpaceType type, size_t numberOfComponents)
{
	CGColorSpaceRef colorSpace;
	CGColorSpaceStateRef csState;
	CGColorSpaceModel spaceModel;
	CGColorSpaceModel processColorModel;
	CGColorSpaceCallbacks *callbacks;
	int size;
	
	switch(type)
	{
	case kCGColorSpaceTypeDeviceGray:
		size = 0x34;
		spaceModel = kCGColorSpaceModelMonochrome;
		callbacks = &device_gray_vtable;
		processColorModel = kCGColorSpaceModelMonochrome;
		break;
	case kCGColorSpaceTypeDeviceRGB:
		size = 0x34;
		spaceModel = kCGColorSpaceModelRGB;
		callbacks = &device_rgb_vtable;
		processColorModel = kCGColorSpaceModelRGB;
		break;
	case kCGColorSpaceTypeDeviceCMYK:
		size = 0x34;
		spaceModel = kCGColorSpaceModelCMYK;
		processColorModel = kCGColorSpaceModelCMYK;
		//callbacks = &device_cmyk_vtable;
		break;
	case kCGColorSpaceTypeCalibratedGray:
		size = 0x50;
		spaceModel = kCGColorSpaceModelMonochrome;
		processColorModel = kCGColorSpaceModelMonochrome;
		//callbacks = &calibrated_gray_vtable;
		break;
	case kCGColorSpaceTypeCalibratedRGB:
		size = 0x7C;
		spaceModel = kCGColorSpaceModelRGB;
		processColorModel = kCGColorSpaceModelRGB;
		//callbacks = &calibrated_rgb_vtable;
		break;
	case kCGColorSpaceTypeLab:
		size = 0x5C;
		spaceModel = kCGColorSpaceModelLab;
		processColorModel = kCGColorSpaceModelLab;
		//callbacks = &lab_vtable;
		break;
	case kCGColorSpaceTypeICC:
		size = 0x60;
		spaceModel = kCGColorSpaceModelUnknown;
		processColorModel = kCGColorSpaceModelUnknown;
		//callbacks = &icc_vtable;
		break;
	case kCGColorSpaceTypeIndexed:
		size = 0x40;
		spaceModel = kCGColorSpaceModelIndexed;
		processColorModel = kCGColorSpaceModelUnknown;
		//callbacks = &indexed_vtable;
		
		break;
	case kCGColorSpaceTypeDeviceN:
		size = 0x44;
		spaceModel = kCGColorSpaceModelDeviceN;
		processColorModel = kCGColorSpaceModelDeviceN;
		//callbacks = &deviceN_vtable;
		
	case kCGColorSpaceTypePattern:
		size = 0x38;
		spaceModel = kCGColorSpaceModelPattern;
		processColorModel = kCGColorSpaceModelUnknown;
		//callbacks = &pattern_vtable;
		break;
	default:
		break;
	}

	csState = (CGColorSpaceStateRef) calloc(1, size);
	csState->isSingleton = FALSE;
	csState->isUncalibrated = FALSE;
	csState->supportsOuput = TRUE;
	csState->unknown07 = FALSE;
	csState->unknown08 = FALSE;
	csState->spaceType = type;
	csState->spaceModel = spaceModel;
	csState->processColorModel= processColorModel;
	csState->numberOfComponents = numberOfComponents;
	csState->components = NULL; //STR     R6, [R0,#0x28]
	csState->callbacks = callbacks;
	
	if (csState->spaceType == kCGColorSpaceTypeICC)
	{
		csState->components = (float *)malloc(numberOfComponents * sizeof(float));
		for (size_t i; i < numberOfComponents; i++)
		{
			//IMPLEMENT HERE
		}
	}
	else
	{
		if (csState->spaceType == kCGColorSpaceTypePattern)
		{
			((CGColorSpaceStatePatternRef)csState)->baseColorSpace = NULL;
			csState->supportsOuput = FALSE;
		}
	}

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


CGColorSpaceStateRef color_space_state_retain(CGColorSpaceStateRef colorSpaceState)
{
	if (!colorSpaceState) { return NULL; }

	_CFAtomicIncrement32(&colorSpaceState->refcount);

	return colorSpaceState;
}

void color_space_state_release(CGColorSpaceStateRef colorSpaceState)
{
	if (!colorSpaceState) { return; }

	_CFAtomicDecrement32(&colorSpaceState->refcount);
	if (colorSpaceState->refcount == 0)
	{
		color_space_state_dealloc(colorSpaceState);
	}
}

void color_space_state_dealloc(CGColorSpaceStateRef csState)
{
	if (!csState) { return; }

	if (csState->isSingleton == FALSE)
	{
		if (csState->associate)
			CFRelease((CFTypeRef)csState->associate);
		if (csState->callbacks->finalize)
			csState->callbacks->finalize((CFTypeRef)csState);
		
		CGColorRelease(csState->color1C);
		free(csState->field20);
		free(csState->md5);
	}

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

bool CGColorSpaceSupportsOutput(CGColorSpaceRef space)
{
	if (!space) { return 0; }

	return space->state->supportsOuput;
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
		baseColorSpace = ((CGColorSpaceStatePatternRef)cs->state)->baseColorSpace;
	}
	else
	{
		baseColorSpace = NULL;
	}

	return baseColorSpace;
}

size_t CGColorSpaceGetColorTableCount(CGColorSpaceRef cs)
{
	size_t count;

	if (cs && cs->state->spaceModel == kCGColorSpaceModelIndexed) 
		count = ((CGColorSpaceStateIndexedRef)cs->state)->lastIndex + 1;
	else
		count = 0;

	return count;
}

void CGColorSpaceGetColorTable(CGColorSpaceRef space, uint8_t *table)
{
	size_t numComponents, count;
	CGColorSpaceStateIndexedRef csStateIndexed;

	if (space && space->state->spaceModel == kCGColorSpaceModelIndexed && table)
	{
		csStateIndexed = (CGColorSpaceStateIndexedRef)space->state;
		numComponents = CGColorSpaceGetNumberOfComponents(csStateIndexed->baseColorSpace);
		count = csStateIndexed->lastIndex + 1;
		memmove(table, csStateIndexed->indexes, numComponents * count);
	}
}