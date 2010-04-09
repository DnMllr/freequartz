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
#include "CGBasePriv.h"
#include <pthread.h>

static pthread_once_t allow_debug_once = PTHREAD_ONCE_INIT;
static Boolean allowDebuggingDefaults = FALSE;

#if 0
CONST_STRING_DECL(Yes,							"Yes");
CONST_STRING_DECL(No,							"No");
CONST_STRING_DECL(True,							"True");
CONST_STRING_DECL(False,						"False");
CONST_STRING_DECL(CGAllowDebuggingDefaults,		"CGAllowDebuggingDefaults");
#endif

typedef CFTypeRef (*copyDefVal) (const char* propName);

void
loadAllowDebuggingDefaults(void)
{
#if 0
	CFPropertyListRef debugPref;

	debugPref = CFPreferencesCopyValue(Cgallowdebuggi, 
		kCFPreferencesAnyApplication, 
		kCFPreferencesCurrentUser,
		kCFPreferencesAnyHost);

	if (getBool(debugPrefs, &allowDebuggingDefaults) == FALSE) {
		allowDebuggingDefaults = FALSE;
	}

	if (debugPref)
		CFRelease((CFTypeRef)debugPref);
#endif
}


CFTypeRef
copyDefaultValue(const char* propName)
{
	pthread_once(&allow_debug_once, loadAllowDebuggingDefaults);

	return 0;
}

Boolean
getBool(CFPropertyListRef preference, Boolean* boolean)
{
	Boolean ret;
#if 0
	CFTypeID cftype;
	CFTypeID cfbooltype;

	if (!preference)
		return FALSE;

	if (CFGetTypeID(preference) == CFBooleanGetTypeID()) {
		ret = *boolean = CFBooleanGetValue((CFBooleanRef) preference));
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
#endif
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



