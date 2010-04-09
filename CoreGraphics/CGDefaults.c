/****************************************************************************
**
** Copyright (C) 2010 Smartmobili.
** All rights reserved.
** Contact: Smartmobili (contact@smartmobili.com)
**	
** This file is part of the CoreGraphics module of the freequartz Toolkit.
**
**
** GNU Lesser General Public License Usage	
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements	
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
****************************************************************************/
#include <pthread.h>

#include "CGBasePriv.h"
#include "CGDefaultsPriv.h"

static pthread_once_t	allow_debug_once = PTHREAD_ONCE_INIT;
static Boolean			allowDebuggingDefaults = FALSE;


CONST_STRING_DECL(Com_apple_core,				"Com_apple_core");
CONST_STRING_DECL(Yes,							"Yes");
CONST_STRING_DECL(No,							"No");
CONST_STRING_DECL(True,							"True");
CONST_STRING_DECL(False,						"False");
CONST_STRING_DECL(CGAllowDebuggingDefaults,		"CGAllowDebuggingDefaults");

typedef CFTypeRef (*copyDefVal) (const char* propName);

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

Boolean
getBool(CFPropertyListRef preference, Boolean* boolean)
{
	Boolean ret;

	if (!preference)
		return FALSE;

	if (CFGetTypeID(preference) == CFBooleanGetTypeID()) {
		ret = *boolean = CFBooleanGetValue((CFBooleanRef) preference);
	}
	else if (CFGetTypeID(preference) == CFStringGetTypeID()) {
		if (!CFStringCompare((CFStringRef)preference, Yes, kCFCompareCaseInsensitive)) {
			*boolean = ret = TRUE;
		}
		else if (!CFStringCompare((CFStringRef)preference, No, kCFCompareCaseInsensitive)) {
			ret = *boolean = FALSE;
		}
		else if (!CFStringCompare((CFStringRef)preference, True, kCFCompareCaseInsensitive)) {
			ret = *boolean = TRUE;
		}
		else if (!CFStringCompare((CFStringRef)preference, False, kCFCompareCaseInsensitive)) {
			ret = *boolean = FALSE;
		}
	}

	return ret;
}

Boolean 
getBooleanProperty(void* boolRef)
{
	return FALSE;
}

Boolean
CGDefaultsGetInteger(const char* propName/*, ... */)
{
	return FALSE;
}

Boolean 
CGDefaultsGetBoolean(const char* propName /*, ... */)
{
	return FALSE;
}



