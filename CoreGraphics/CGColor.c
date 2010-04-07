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

#include <CoreGraphics/CGColor.h>

#include "CGBasePriv.h"
#include "CGColorPriv.h"
#include "CGColorSpacePriv.h"


/* CoreFoundation runtime class for CGPath.  */
static CFRuntimeClass CGColorClass =  {
    0,							/* version */
    "CGColorClass",				/* Name of class.  */
    0,							/* init */
    0,							/* copy  */
    CGColorDestroy,				/* dealloc  */
	0,							/* equal  */
	0,							/* hash  */
	0,							/* copyFormattingDesc */
	0							/* copyDebugDesc */
  };
static CFTypeID __kCGColorID = _kCFRuntimeNotATypeID;

CFTypeID CGColorGetTypeID(void)
{	
	return CGTypeRegisterWithCallbacks(&__kCGColorID, &CGColorClass );
}

void CGColorDestroy(CFTypeRef ctf)
{

}

CGColorRef CGColorRetain(CGColorRef color)
{
	if (!color) { return 0; }
	CFRetain((CFTypeRef) color);

	return color;
}

void CGColorRelease(CGColorRef color)
{
	if (!color) { return; }
	CFRelease((CFTypeRef) color);
}

CGColorRef CGColorCreate(CGColorSpaceRef space, const CGFloat components[])
{
	CGColorRef color;
	size_t numberOfComponents;
	CFIndex size;

	if (!space || !components)	{ return 0; }

	numberOfComponents = CGColorSpaceGetNumberOfComponents(space);
	
	size = sizeof(struct CGColor) - sizeof(CFRuntimeBase);
	color = (CGColorRef) CGTypeCreateInstance( CGColorGetTypeID(), size );
	if (!color) { return 0; }

	//color->nextID = CGTypeGetNextIdentifier(__kCGColorSpaceID);
	CGColorSpaceRetain(space);
	memcpy(color->components, components, numberOfComponents);

	return color;
}

CGColorRef CGColorCreateGenericGray(CGFloat gray, CGFloat alpha)
{
	CGFloat components[2];
	CFStringRef name;
	CGColorSpaceRef space;
	CGColorRef color;

	components[0] = gray;
	components[1] = alpha;

	space = CGColorSpaceCreateWithName(name);
	color = CGColorCreate(space, components);
	CGColorSpaceRelease(space);

	return color;
}




bool CGColorEqualToColor(CGColorRef color1, CGColorRef color2)
{
	size_t numOfComponents;

	if (color1 == color2)
		return TRUE;

	numOfComponents = color1->numberOfComponents;
	if ((color1->numberOfComponents == color2->numberOfComponents) &&
		(memcmp(color1->components, color2->components, numOfComponents * sizeof(CGFloat)) == 0) &&
		 CGColorSpaceEqualToColorSpace(color1->colorSpace, color2->colorSpace))
		 return TRUE;
	
	return FALSE
}


CGFloat CGColorGetAlpha(CGColorRef color)
{
	if (!color) { return 0; }
	return color->components[color->numberOfComponents-1];
}

CGColorSpaceRef CGColorGetColorSpace(CGColorRef color)
{
	if (!color) { return NULL; }
	return color->colorSpace;
}

CGPatternRef CGColorGetPattern(CGColorRef color)
{
	if (!color) { return 0; }
	return color->pattern;
}


size_t CGColorGetNumberOfComponents(CGColorRef color)
{
	if (!color) { return 0; }
	return color->numberOfComponents;
}

const CGFloat *CGColorGetComponents(CGColorRef color)
{
	if (!color) { return 0; }
	return color->components;
}