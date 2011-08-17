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

	color->nextID = CGTypeGetNextIdentifier(&__kCGColorSpaceID);
	CGColorSpaceRetain(space);
	memcpy(color->components, components, numberOfComponents);

	return color;
}

CGColorRef CGColorCreateGenericGray(CGFloat gray, CGFloat alpha)
{
	CGFloat components[2];
	CGColorSpaceRef space;
	CGColorRef color;

	components[0] = gray;
	components[1] = alpha;

	space = CGColorSpaceCreateWithName(kCGColorSpaceGenericGray);
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
	
	return FALSE;
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