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
#include "CGDefaultsPriv.h"

static pthread_once_t	allow_debug_once = PTHREAD_ONCE_INIT;
static Boolean			allowDebuggingDefaults = FALSE;


CG_CONST_STRING_DECL(Com_apple_core,				"Com_apple_core");
CG_CONST_STRING_DECL(Yes,							"Yes");
CG_CONST_STRING_DECL(No,							"No");
CG_CONST_STRING_DECL(True,							"True");
CG_CONST_STRING_DECL(False,							"False");
CG_CONST_STRING_DECL(CGAllowDebuggingDefaults,		"CGAllowDebuggingDefaults");



CFStringRef
CGCFStringCreate(const char* cStr)
{
	return CFStringCreateWithCString(NULL, cStr, kCFStringEncodingASCII);
}




void
loadAllowDebuggingDefaults(void)
{
	CFPropertyListRef debugPref;

	debugPref = CFPreferencesCopyValue(CGAllowDebuggingDefaults, 
		kCFPreferencesAnyApplication, 
		kCFPreferencesCurrentUser,
		kCFPreferencesAnyHost);

	if (getBool(debugPref, &allowDebuggingDefaults) == FALSE) {
		allowDebuggingDefaults = FALSE;
	}

	if (debugPref)
		CFRelease((CFTypeRef)debugPref);
}


CFTypeRef
copyDefaultValue(const char* propName)
{
	char* p;
	CFStringRef str;
	CFPropertyListRef pref;

	pthread_once(&allow_debug_once, loadAllowDebuggingDefaults);

	if (allowDebuggingDefaults == FALSE)
		return 0;

	p  = getenv(propName);
	if (p) {
		str = CGCFStringCreate((const char*)p);
		return ((CFTypeRef)str);
	}
	else {
		str = CGCFStringCreate(propName);
		if (str) {
			pref = CFPreferencesCopyValue(str,
				kCFPreferencesCurrentApplication, 
				kCFPreferencesCurrentUser,
				kCFPreferencesAnyHost);
			
			if (pref == NULL) {
				pref = CFPreferencesCopyValue(str,
					Com_apple_core,
					kCFPreferencesCurrentUser,
					kCFPreferencesAnyHost);
			}

			CFRelease((CFTypeRef)str);
		}
		else {
			pref = NULL;
		}
		
	}

	return pref;
}

//////////////////////////////////////////////////////////////////////////
//Boolean 
//////////////////////////////////////////////////////////////////////////
Boolean
getBool(CFTypeRef preference, Boolean* boolean)
{
	Boolean ret = FALSE;

	if (!preference)
		return FALSE;

	if (CFGetTypeID(preference) == CFBooleanGetTypeID()) {
		ret = TRUE;
		*boolean = CFBooleanGetValue((CFBooleanRef) preference);
	}
	else if (CFGetTypeID(preference) == CFStringGetTypeID()) {
		if (!CFStringCompare((CFStringRef)preference, Yes, kCFCompareCaseInsensitive)) {
			ret = TRUE;
			*boolean = TRUE;
		}
		else if (!CFStringCompare((CFStringRef)preference, No, kCFCompareCaseInsensitive)) {
			ret = TRUE;
			*boolean = FALSE;
		}
		else if (!CFStringCompare((CFStringRef)preference, True, kCFCompareCaseInsensitive)) {
			ret = TRUE;
			*boolean = TRUE;
		}
		else if (!CFStringCompare((CFStringRef)preference, False, kCFCompareCaseInsensitive)) {
			ret = TRUE;
			*boolean = FALSE;
		}
	}

	return ret;
}

Boolean 
getBooleanProperty(const char* propName, copyDefVal fnCopyVal, Boolean* boolean)
{
	CFTypeRef cftype;
	Boolean bValue;
	Boolean bRet;

	cftype = fnCopyVal(propName);

	if (bRet = getBool(cftype, &bValue)) {
		if (boolean)
			*boolean = bValue;
	}
	
	if (cftype)
		CFRelease(cftype);

	return bRet;
}

Boolean 
CGDefaultsGetBoolean(const char* propName, Boolean* boolean)
{
	return getBooleanProperty(propName, copyDefaultValue, boolean);
}

Boolean
CGCFDictionaryGetBoolean(CFDictionaryRef theDict, CFStringRef key, Boolean* boolean)
{
	Boolean ret;
	CFTypeRef type;

	if (!theDict || !key)
		return FALSE;

	type = (CFTypeRef)CFDictionaryGetValue(theDict, (const void*)key);
	if (type && CFGetTypeID(type) == CFBooleanGetTypeID())
	{
		ret = TRUE;
		if (boolean)
		{
			*boolean = CFBooleanGetValue((CFBooleanRef)type) != 0;
		}
	}
	else
	{
		ret = FALSE;
	}
}


//////////////////////////////////////////////////////////////////////////
//Integer 
//////////////////////////////////////////////////////////////////////////
Boolean
getIntegerProperty(const char* propName, copyDefVal fnCopyVal, int* number)
{

	return FALSE;
}

Boolean
CGDefaultsGetInteger(const char* propName, int* number)
{
	return getIntegerProperty(propName, copyDefaultValue, number);
}

//////////////////////////////////////////////////////////////////////////
//Strings 
//////////////////////////////////////////////////////////////////////////


Boolean 
copyStringProperty(const char* cStr, copyDefVal fnCopyVal, CFStringRef* strDst)
{
	Boolean bRet;
	CFTypeRef cftype;
	
	cftype = fnCopyVal(cStr);
	if (cftype && (CFGetTypeID(cftype) == CFStringGetTypeID())) {
		if (strDst)
			*strDst = (CFStringRef)cftype;
		bRet = TRUE;
	}
	else {
		bRet = FALSE;
	}

	return bRet;
}

Boolean 
CGDefaultsCopyString(const char* cStr, CFStringRef* strDst)
{
	return copyStringProperty(cStr, copyDefaultValue, strDst);
}





