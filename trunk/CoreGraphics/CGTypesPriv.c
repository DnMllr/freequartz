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
#include <pthread.h>
#include "CGBasePriv.h"
#include "CGTypesPriv.h"



static pthread_mutex_t type_register_lock	= PTHREAD_MUTEX_INITIALIZER;
static pthread_mutex_t nextID_lock			= PTHREAD_MUTEX_INITIALIZER;

CG_CONST_STRING_DECL(kCGCTypeCopyDescFormat,	"<%s %p>");



CFStringRef copy_description(CFTypeRef cf, CFDictionaryRef formatOptions)
{
	CFStringRef ret;
	const CFRuntimeClass* cfclass;

	if (!cf)
		return NULL;

	cfclass = _CFRuntimeGetClassWithTypeID(CFGetTypeID(cf));
	if (cfclass) {

		ret = CFStringCreateWithFormat(CFGetAllocator(cf),
			formatOptions,
			kCGCTypeCopyDescFormat,
			cfclass->className,
			cf);
	}
	else
		ret = NULL;

	return ret;
}

CFStringRef copy_debug_description(CFTypeRef cf)
{
	return copy_description(cf, NULL);
}


CFTypeID CGTypeRegisterWithCallbacks(CFTypeID* typeID, CFRuntimeClass* rtc)
{
	CFRuntimeClass* l_rtc;

	if (*typeID != _kCFRuntimeNotATypeID) { return *typeID; }

	pthread_mutex_lock(&type_register_lock);

	l_rtc = (CFRuntimeClass*) malloc(sizeof(CFRuntimeClass));
	l_rtc->version = 0;
	l_rtc->className = rtc->className;
	l_rtc->init = rtc->init;
	l_rtc->copy = rtc->copy;
	l_rtc->finalize = rtc->finalize;
	l_rtc->equal = rtc->equal;
	l_rtc->hash = rtc->hash;
	l_rtc->copyFormattingDesc = (!rtc->copyFormattingDesc) ? copy_description : rtc->copyFormattingDesc;
	l_rtc->copyDebugDesc = (!rtc->copyDebugDesc) ? copy_debug_description : rtc->copyDebugDesc;
	l_rtc->reclaim = rtc->reclaim;
	if (rtc->reclaim)
		l_rtc->version = 4;

	*typeID = _CFRuntimeRegisterClass(l_rtc);

	pthread_mutex_unlock(&type_register_lock);

	return *typeID;
}


CFTypeRef CGTypeCreateInstance(CFTypeID id, CFIndex size)
{
	return CGTypeCreateInstanceWithAllocator(0, id, size);
}


CFTypeID CGTypeGetNextIdentifier(CFTypeID* id)
{
	CFTypeID ret;

	pthread_mutex_lock(&nextID_lock);
	ret = *id + 1;
	*id = ret;
	pthread_mutex_unlock(&nextID_lock);

	return ret;
}

CFTypeRef CGTypeCreateInstanceWithAllocator(CFAllocatorRef allocator, CFTypeID id, CFIndex size)
{
	CFTypeRef type;
	char* ptr;
	

	/* Create the CFType */
	//
	type = _CFRuntimeCreateInstance(allocator, id, size, NULL);
	if (!type) goto Cleanup;

	///* Init with zero values all fields except our base object */
	ptr = (char*)type;
	memset((void*)(ptr + sizeof(CFRuntimeBase)), 0, size);
	
	return type;

Cleanup:
	return NULL;
}

CFTypeRef CGTypeCreateSingleton(CFTypeID typeID, void *memory, CFIndex size)
{
	if (memory == NULL) {
		memory = malloc(size + sizeof(CFRuntimeBase));
		if (!memory) {
			CGPostError("%s: failed to create instance of type %jd", 
				CGTypeCreateSingleton, typeID);
			return NULL;
		}
	}

	memset(memory, 0, size + sizeof(CFRuntimeBase));
	_CFRuntimeInitStaticInstance(memory, typeID);

	return memory;
}


//CFMutableDictionaryRef CGCFDictionaryCreate()