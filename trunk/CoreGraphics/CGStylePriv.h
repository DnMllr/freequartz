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
#ifndef CGSTYLEPRIV_H_
#define CGSTYLEPRIV_H_

#include <CoreFoundation/CFRuntime.h>
#include "CGTypesPriv.h"


CF_EXTERN_C_BEGIN

typedef  struct CGStyle {

	signed long refcount;				//0x00
	CFTypeID nexID;						//0x08

} CGStyle, *CGStyleRef;


CG_EXTERN void styleFinalize(CFTypeRef ctf);
CG_EXTERN CGStyleRef CGStyleRetain(CGStyleRef style);
CG_EXTERN void CGStyleRelease(CGStyleRef style);
CG_EXTERN CFTypeID CGStyleGetTypeID(void);



CF_EXTERN_C_END

#endif /* CGSTYLEPRIV_H_ */


