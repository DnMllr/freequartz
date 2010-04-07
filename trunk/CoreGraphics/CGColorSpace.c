/****************************************************************************
**
** Copyright (C) 2010 Smartmobili.
** All rights reserved.
** Contact: Smartmobili (contact@smartmobili.com)
**	
** This file is part of the CoreGraphics module of the Coconuts Toolkit.
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

#include "CGBasePriv.h"
#include "CGColorSpacePriv.h"


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


bool CGColorSpaceEqualToColorSpace(CGColorSpaceRef cs1, CGColorSpaceRef cs2)
{
	if (cs1 == cs2)
		return TRUE;

	if (cs1->spaceDevice == cs2->spaceDevice) {

	}


	return FALSE;
}

CGColorSpaceDevice CGColorSpaceGetType(CGColorSpaceRef space)
{
	if (!space)
		return kCGColorSpaceDeviceUnknown;

	return space->spaceDevice;
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
	if (!components || CGColorSpaceGetType(space) == kCGColorSpaceDeviceUnknown)
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

CFIndex CGColorSpaceGetIndexForName(CFStringRef name)
{
	return 0;
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