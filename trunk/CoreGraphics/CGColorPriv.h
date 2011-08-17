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
#ifndef CGCOLORPRIV_H_
#define CGCOLORPRIV_H_

#include <CoreFoundation/CFRuntime.h>
#include <CoreGraphics/CGColorSpace.h>
#include <CoreGraphics/CGPattern.h>

#include "CGMacros.h"

extern CFTypeID __kCGColorSpaceID;

CF_EXTERN_C_BEGIN

typedef struct CGColor {
	CFRuntimeBase obj;				//0x00

	CFTypeID nextID;				//0x08
	CGColorSpaceRef colorSpace;		//0x10
	CGPatternRef pattern;			//0x14
	size_t numberOfComponents;		//0x1C
	CGFloat *components;			//0x20	

} *CGColorRef;

void CGColorDestroy(CFTypeRef ctf);



CF_EXTERN_C_END

#endif /* CGCOLORPRIV_H_ */


