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
#ifndef CGFUNCTIONPRIV_H_
#define CGFUNCTIONPRIV_H_

#include <CoreFoundation/CFRuntime.h>
#include "CGTypesPriv.h"


CF_EXTERN_C_BEGIN

//sizeof = 
typedef  struct CGFuction {

	CFRuntimeBase obj;					//0x00

} CGFuction, *CGFuctionRef;


void functionFinalize(CFTypeRef c);


CF_EXTERN_C_END

#endif /* CGFUNCTIONPRIV_H_ */


