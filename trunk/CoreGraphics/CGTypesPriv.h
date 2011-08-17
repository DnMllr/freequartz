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
#ifndef CGTYPES_H_
#define CGTYPES_H_

#include "CGMacros.h"

CF_EXTERN_C_BEGIN

// include issues because in this file CG_EXTERN and DLLEXPORT are not properly
// defined that's why I am explicitely putting __declspec.
// TODO : need to find why !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//CG_EXTERN const CFStringRef kCGCTypeCopyDescFormat;
extern __declspec(dllexport) const CFStringRef kCGCTypeCopyDescFormat;

CFStringRef copy_description(CFTypeRef cf, CFDictionaryRef formatOptions);
CFStringRef copy_debug_description(CFTypeRef cf);

CFTypeID CGTypeRegisterWithCallbacks(CFTypeID* typeID, CFRuntimeClass* rtclass);
CFTypeRef CGTypeCreateInstance(CFTypeID id, CFIndex size);
CFTypeRef CGTypeCreateInstanceWithAllocator(CFAllocatorRef allocator, CFTypeID id, CFIndex size);
CFTypeID CGTypeGetNextIdentifier(CFTypeID* id);
CFTypeRef CGTypeCreateSingleton(CFTypeID typeID, void *memory, CFIndex size);

CF_EXTERN_C_END

#endif /* CGTYPES_H_ */


