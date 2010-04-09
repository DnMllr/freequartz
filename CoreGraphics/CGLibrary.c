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
#include "CGDefaultsPriv.h"
#include <pthread.h>


static pthread_once_t libraryload_once = PTHREAD_ONCE_INIT;
static CFArrayRef dylib_paths = NULL;

CONST_STRING_DECL(separator,				":");

#ifdef __WIN32__
#define DYLIB_FORMAT "lib%s.dll"
#else
#define DYLIB_FORMAT "lib%s.A.dylib"
#endif

void
initialize_dylib_paths(void)
{
	Boolean bValue;
	CFStringRef strValue;

	if (!CGDefaultsGetBoolean("CGAllowDylibSearchPath", &bValue) || !bValue)
		return;

	if (!CGDefaultsCopyString("CGS_LIBRARY_PATH", &strValue) || !strValue)
		return;
	
	dylib_paths = CFStringCreateArrayBySeparatingStrings(NULL, NULL/* FIXME*/, separator);

	// FIXME
	//CFRelease();

}


void* 
CGLibraryLoadFunction(const char* libName, const char* symName)
{
	char buffer[MAX_PATH+1];

	pthread_once(&libraryload_once, initialize_dylib_paths);
	if (!strcmp(libName, "CSync"))
		return NULL;

	snprintf(buffer, MAX_PATH, DYLIB_FORMAT, libName);

	return load_function(dylib_paths, buffer, symName);
}

void*
load_function(CFArrayRef paths, const char* libPath, const char* symName)
{
	return NULL;
}