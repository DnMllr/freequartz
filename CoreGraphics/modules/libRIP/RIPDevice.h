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
#ifndef RIPDEVICE_H_
#define RIPDEVICE_H_

#include "RIPBase.h"

typedef struct RIPDevice {



} RIPDevice, *RIPDeviceRef;


RIP_EXTERN RIPDeviceRef RIPDeviceCreate(int count, size_t width, size_t height, void* a4, void* a5);

RIP_EXTERN CGColorSpaceRef RIPDeviceGetColorSpace(RIPDeviceRef ripd);



#endif /* RIPDEVICE_H_ */