/*  gnu4wince: Windows CE C Runtime Library "compatibility" library.
 *
 *  Copyright (C) 2007-2008 smartmobili.com.  All rights reserved.
 *  Author : Vincent Richomme - http://www.smartmobili.com
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


#ifndef _GNU4WINCE_UNISTD_H
#define _GNU4WINCE_UNISTD_H

#include "posix4win.h"

#include <stdio.h>
#ifndef _WIN32_WCE
 #include <io.h>
#endif

/* Should be defined in stdio */
#define snprintf	_snprintf

/* Normally defined in stdio */
#define STDIN_FILENO	0
#define STDOUT_FILENO	1
#define STDERR_FILENO	2

/* Values for the second argument to access.
   These may be OR'd together.  */
#define R_OK    4               /* Test for read permission.  */
#define W_OK    2               /* Test for write permission.  */
#define X_OK    1               /* Test for execute permission.  */
#define F_OK    0               /* Test for existence.  */


#ifdef __cplusplus
extern "C" {
#endif

#undef _access
#undef access

GNU4WINCE_API int __cdecl		_access(const char *pathname, int mode);
GNU4WINCE_API int __cdecl		_waccess(const wchar_t *pathname, int mode);

#ifdef _WIN32_WCE

GNU4WINCE_API char * __cdecl	_getcwd(char * _DstBuf, int _SizeInBytes);
GNU4WINCE_API char * __cdecl	_getdcwd(int _Drive, char * _DstBuf, int _SizeInBytes);

GNU4WINCE_API int	__cdecl		_chdir(const char * _Path);
GNU4WINCE_API int	__cdecl		_mkdir(const char *pathname, mode_t mode);
GNU4WINCE_API int	__cdecl		_rmdir(const char * _Path);

GNU4WINCE_API mode_t __cdecl	getmode(const void *set, mode_t mode);
GNU4WINCE_API int	 __cdecl	setmode( int handle, mode_t mode );
GNU4WINCE_API ssize_t __cdecl	_read(int fd, void *buf, size_t nbyte);
GNU4WINCE_API ssize_t __cdecl	_write(int fildes, const void *buf, size_t nbyte);
GNU4WINCE_API int  __cdecl		_close(int fildes);

#endif

//GNU4WINCE_API ssize_t __cdecl	_pread(int fd, void *buf, size_t nbyte, off_t offset);
GNU4WINCE_API ssize_t __cdecl	_pwrite(int fildes, const void *buf, size_t nbyte, off_t offset);
GNU4WINCE_API int	  __cdecl	_fsync(int fildes);

#define access	_access
#define waccess	_waccess
#define fsync	_fsync
//#define pread	_pread
#define pwrite	_pwrite

#ifdef _WIN32_WCE

#define getcwd	_getcwd
#define getdcwd _getdcwd
#define chdir	_chdir
#define wchdir	_wchdir
#define mkdir	_mkdir
#define rmdir	_rmdir
#define read	_read
#define write	_write
#define close	_close

#endif




#ifdef __cplusplus
}
#endif


#endif // _GNU4WINCE_UNISTD_H
