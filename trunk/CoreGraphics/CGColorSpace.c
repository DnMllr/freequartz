/****************************************************************************
**
** Copyright (C) 2010 Smartmobili.
** All rights reserved.
** Contact: Smartmobili (contact@smartmobili.com)
**	
** This file is part of the CoreGraphics module of the freequartz Toolkit.
**
**
** GNU Lesser General Public License Usage	
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements	
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
****************************************************************************/
#include <CoreGraphics/CGColorSpace.h>
#include <pthread.h>

#include "CGBasePriv.h"
#include "CGColorSpacePriv.h"

static pthread_once_t			space_create_once = PTHREAD_ONCE_INIT;
static CFMutableDictionaryRef	name_to_index_map = NULL;



/* CGColorSpace constants */
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



/* CoreFoundation runtime class for CGPath.  */
static CFRuntimeClass CGColorSpaceClass =  {
    0,							/* version */
    "CGColorSpace",				/* Name of class.  */
    0,							/* init */
    0,							/* copy  */
    CGColorSpaceDestroy,		/* finalize  */
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

void CGColorSpaceDestroy(CFTypeRef ctf)
{

}

void create_name_to_index_map(void)
{
	
}

CFIndex CGColorSpaceGetIndexForName(CFStringRef name)
{
	CFIndex ret;

	if (name_to_index_map == NULL) {
		pthread_once(&space_create_once, create_name_to_index_map);
	}
	if (name)
		ret = (CFIndex)CFDictionaryGetValue(name_to_index_map, (const void*)name);
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