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
#include "CGBasePriv.h"
#include "CGDefaultsPriv.h"
#include "CGLibraryPriv.h"

#include <sys/stat.h>
#include <pthread.h>
#include <dlfcn.h>

static CFArrayRef dylib_paths = NULL;
static CFMutableDictionaryRef handles = NULL;
static pthread_once_t  libraryload_once		= PTHREAD_ONCE_INIT;
static pthread_mutex_t functionload_mutex	= PTHREAD_MUTEX_INITIALIZER;


CG_CONST_STRING_DECL(separator,				":");

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

	if (CGDefaultsGetBoolean("CGAllowDylibSearchPath", &bValue) && bValue)
	{
		if (CGDefaultsCopyString("CGS_LIBRARY_PATH", &strValue) && strValue)
		{
			dylib_paths = CFStringCreateArrayBySeparatingStrings(NULL, strValue, separator);
			CFRelease((CFTypeRef)strValue);
		}
	}
}

void*
open_handle_to_dylib_path(const char* libname)
{
	return dlopen(libname, RTLD_LOCAL|RTLD_LAZY);
}

void*
load_function(CFArrayRef paths, const char* fullLibName, const char* symName)
{
	CFStringRef cStr, cStr2;
	void* funcaddr;
	void* libhandle;
	char buffer[MAX_PATH+1];
	char fullpath[MAX_PATH+1];
	Boolean bRet;
	struct stat finfo;

	pthread_mutex_lock(&functionload_mutex);
	if (!handles) {
		handles = CFDictionaryCreateMutable(0,0, &kCFTypeDictionaryKeyCallBacks, 0);
	}
	
	cStr = CFStringCreateWithFileSystemRepresentation(NULL, fullLibName);
	if (cStr)
	{
		libhandle = (void *)CFDictionaryGetValue(handles, cStr);
		if (libhandle == NULL)
		{
			if (paths != NULL)
			{
				for (int i = 0; i < CFArrayGetCount(paths); i++)
				{
					cStr2 = (CFStringRef)CFArrayGetValueAtIndex(paths, i);
					bRet = CFStringGetFileSystemRepresentation(cStr2, buffer, MAX_PATH); 
					if (bRet)
					{
						snprintf(fullpath, MAX_PATH, "%s/%s", buffer, fullLibName);
						if (!stat(fullpath, &finfo))
						{
							libhandle = open_handle_to_dylib_path(fullpath);
							if (libhandle)
							{
								CFDictionarySetValue(handles, cStr,libhandle);
							}
						}
					}
				}//for
			}
			else
			{
				snprintf(fullpath, MAX_PATH, "%s/System/Library/Frameworks/CoreGraphics/%s", getenv("NEXT_ROOT"), fullLibName); 
				libhandle = open_handle_to_dylib_path(fullpath);
			}
		}

		CFRelease(cStr);
		funcaddr = dlsym(libhandle, symName);
	}
	else
	{
		funcaddr = NULL;
	}

	pthread_mutex_unlock(&functionload_mutex);

	return funcaddr;
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

