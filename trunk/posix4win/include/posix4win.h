/*  posix4win: Windows/CE C Runtime Library "compatibility" library.
 *
 *  Copyright (C) 2007-2008 smartmobili.com.  All rights reserved.
 *  http://www.smartmobili.com
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef _POSIX4WIN_H
#define _POSIX4WIN_H

#define __STDC__ 0

#ifdef _USRDLL
#ifdef GNU4WINCE_EXPORTS
	#define GNU4WINCE_API  __declspec(dllexport)
#else
	#define GNU4WINCE_API  __declspec(dllimport)
#endif
#else
	#define GNU4WINCE_API
#endif

#ifdef _WIN32_WCE

#include <ceconfig.h>
#if defined(WIN32_PLATFORM_PSPC) || defined(WIN32_PLATFORM_WFSP)
#define SHELL_AYGSHELL
#endif

#ifdef SHELL_AYGSHELL
#include <aygshell.h>
#pragma comment(lib, "aygshell.lib")
#endif // SHELL_AYGSHELL

#include <altcecrt.h>
#include <sys/types.h>
#include <stdlib.h>
#include <fcntl.h>
#include <tchar.h>

#else

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>
#include <wchar.h>

#endif //_WIN32_WCE


//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
// Functions normally found in GNU header
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
#include <sys/types.h>
#include <sys/mman.H>
#include "posix4win_unistd.h"






#endif //_POSIX4WIN_H
