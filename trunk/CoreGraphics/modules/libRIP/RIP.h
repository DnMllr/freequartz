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
#ifndef LIBRIP_H_
#define LIBRIP_H_

#include "RIPBase.h"
#include "RIPZone.h"
#include "RIPDevice.h"
#include "RIPContext.h"
#include "RIPLayer.h"


//sizeof = 0x78
typedef struct RIPState {
									//0x4C return of ripc_Timestamp
	size_t memsize;					//0x58

} RIPState, *RIPStateRef;



RIP_EXTERN RIPStateRef RIPGlobalState();


RIP_EXTERN int CGBlt_depth(const char *encoding);



#endif /* LIBRIP_H_ */