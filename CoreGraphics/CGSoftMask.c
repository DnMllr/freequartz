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



static CFRuntimeClass CGSoftMaskClass = 
  {
    0,							// version
    "CGSoftMask",				// className
    0,							// init
    0,							// copy
    softMaskFinalize,			// finalize
	0,							// equal
	0,							// hash
	0,							// copyFormattingDesc
	0							// copyDebugDesc
  };
CFTypeID __kCGSoftMaskID = _kCFRuntimeNotATypeID;


CFTypeID CGSoftMaskGetTypeID(void)
{
	return CGTypeRegisterWithCallbacks(&__kCGSoftMaskID, &CGSoftMaskClass);
}

void softMaskFinalize(CFTypeRef c)
{
	CGImageRelease(((CGSoftMaskRef)c)->mask);
}

void CGSoftMaskRelease(CGSoftMaskRef softMask)
{
	if (!softMask) { return; }
	CFRelease((CFTypeRef)softMask);
}