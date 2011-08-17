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
#ifndef CGDASHPRIV_H_
#define CGDASHPRIV_H_

#include <CoreFoundation/CFRuntime.h>
#include "CGTypesPriv.h"


CF_EXTERN_C_BEGIN

typedef  struct CGDash {

	signed long refcount;				//0x00
	CGFloat phase;						//0x04
	size_t count;						//0x08
	CGFloat* lengths;					//0x0C

} CGDash, *CGDashRef;



CG_EXTERN CGDashRef CGDashCreate(CGFloat phase, const CGFloat lengths[], size_t count);
CG_EXTERN Boolean CGDashEqualToDash(CGDashRef dash1, CGDashRef dash2);
CG_EXTERN const CGFloat* CGDashGetPattern(CGDashRef dash, CGFloat* phase, size_t* count);
CG_EXTERN CGDashRef CGDashRetain(CGDashRef dash);
CG_EXTERN void CGDashRelease(CGDashRef dash);

CF_EXTERN_C_END

#endif /* CGDASHPRIV_H_ */


