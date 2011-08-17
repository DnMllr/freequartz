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
#include "CGContextPriv.h"
#include "CGFontPriv.h"


static CFRuntimeClass CGFontClass = 
  {
    0,							// version
    "CGFont",					// className
    0,							// init
    0,							// copy
    font_Finalize,				// finalize
	0,							// equal
	0,							// hash
	0,							// copyFormattingDesc
	0							// copyDebugDesc
  };
CFTypeID __kCGFontID = _kCFRuntimeNotATypeID;


CFTypeID CGFontGetTypeID(void)
{
	return CGTypeRegisterWithCallbacks(&__kCGFontID, &CGFontClass);
}

void font_Finalize(CFTypeRef c)
{

}

void CGFontRelease(CGFontRef font)
{
	if (!font) { return; }
	CFRelease((CFTypeRef)font);
}

CGFontRef CGFontRetain(CGFontRef font)
{
	if (!font) { return 0; }
	return ((CGFontRef)CFRetain(font));
}





