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

#include <CoreGraphics/CoreGraphicsPrivate.h>
#include <pthread.h>


static pthread_mutex_t cacheMutex	= PTHREAD_MUTEX_INITIALIZER;
static CFArrayRef baseCache	= NULL;


/* CoreFoundation runtime class for CGPath.  */
static CFRuntimeClass CGColorTransformClass =  {
    0,							/* version */
    "CGColorTransformClass",	/* Name of class.  */
    0,							/* init */
    0,							/* copy  */
    colortransformFinalize,		/* finalize  */
	0,							/* equal  */
	0,							/* hash  */
	0,							/* copyFormattingDesc */
	0							/* copyDebugDesc */
  };
static CFTypeID __kCGColorTransformID = _kCFRuntimeNotATypeID;

CFTypeID CGColorTransformGetTypeID(void)
{	
	return CGTypeRegisterWithCallbacks(&__kCGColorTransformID, &CGColorTransformClass );
}

void colortransformFinalize(CFTypeRef ctf)
{

}

CGColorTransformRef CGColorTransformRetain(CGColorTransformRef colorTransform)
{
	if (!colorTransform) { return 0; }
	CFRetain((CFTypeRef) colorTransform);

	return colorTransform;
}

void CGColorTransformRelease(CGColorTransformRef colorTransform)
{
	if (!colorTransform) { return; }
	CFRelease((CFTypeRef) colorTransform);
}

int CGColorTransformGetIdentifier(CGColorTransformRef colorTransform)
{
	if (!colorTransform) { return 0; }
	return colorTransform->identifier;
}


CGColorTransformRef CGColorTransformCreate(CGColorSpaceRef space, CFDictionaryRef theDict)
{
	CGColorTransformRef colorTransform;
	CGColorTransformRef colTransformTmp;
	size_t numComponents;
	CGColorSpaceType spaceType;
	CFIndex extraBytes;
	CGColorSpaceRef space2;
	unsigned char* md5;

	if (!space || !CGColorSpaceSupportsOutput(space))
		return NULL;

	numComponents = CGColorSpaceGetNumberOfComponents(space);
	extraBytes = (numComponents <= 4) ? 328 : 16; // 0x148 : 0x10
	
	colorTransform = (CGColorTransformRef)_CFRuntimeCreateInstance(NULL, CGColorTransformGetTypeID(), extraBytes, NULL);
	if (!colorTransform)
		return NULL;

	spaceType = CGColorSpaceGetType(space);
	switch(spaceType)
	{
	case kCGColorSpaceTypeDeviceGray:
		space2 = CGColorSpaceCreateDisplayGray();
		break;
	case kCGColorSpaceTypeDeviceRGB:
		space2 = CGColorSpaceCreateDisplayRGB();
		break;
	case kCGColorSpaceTypeDeviceCMYK:
		space2 = CGColorSpaceCreateSystemDefaultCMYK();
		break;
	}

	if (space2)
	{
		pthread_mutex_lock(&cacheMutex);
		if (baseCache)
		{
			md5 = CGColorSpaceGetMD5Digest(space2);
			for (int i=0; i < CFArrayGetCount(baseCache); i++)
			{
				/*colTransformTmp = (CGColorTransformRef) CFArrayGetValueAtIndex(baseCache, i);
				 if (!memcmp((unsigned char *)CFArrayGetValueAtIndex(baseCache, i), md5, 16))
				 {

				 }*/
			}
		}
	}
	else
	{
		CFRelease(colorTransform);
		colorTransform = NULL;
	}

	return colorTransform;
}