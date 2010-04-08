/*  gnu4wince: Windows CE C Runtime Library "compatibility" library.
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


#if     _MSC_VER > 1000
#pragma once
#endif

#include <crtdefs.h>

#ifndef _GNU4WINCE_UTIME_H
#define _GNU4WINCE_UTIME_H

#if     !defined(_WIN32)
#error ERROR: Only Win32 target supported!
#endif

#include <crtdefs.h>


#ifdef  _MSC_VER
#pragma pack(push,_CRT_PACKING)
#endif  /* _MSC_VER */

#ifdef  __cplusplus
extern "C" {
#endif

#ifdef  _USE_32BIT_TIME_T
#ifdef  _WIN64
#include <crtwrn.h>
#pragma _CRT_WARNING( _NO_32BIT_TIME_T )
#undef  _USE_32BIT_TIME_T
#endif
#else
#if     _INTEGRAL_MAX_BITS < 64
#define _USE_32BIT_TIME_T
#endif
#endif

#ifndef _TIME32_T_DEFINED
typedef _W64 long __time32_t;   /* 32-bit time value */
#define _TIME32_T_DEFINED
#endif

#ifndef _TIME64_T_DEFINED
#if     _INTEGRAL_MAX_BITS >= 64
typedef __int64 __time64_t;     /* 64-bit time value */
#endif
#define _TIME64_T_DEFINED
#endif

#ifndef _TIME_T_DEFINED
#ifdef _USE_32BIT_TIME_T
typedef __time32_t time_t;      /* time value */
#else
typedef __time64_t time_t;      /* time value */
#endif
#define _TIME_T_DEFINED         /* avoid multiple def's of time_t */
#endif

/* define struct used by _utime() function */

#ifndef _UTIMBUF_DEFINED

struct _utimbuf {
        time_t actime;          /* access time */
        time_t modtime;         /* modification time */
        };

struct __utimbuf32 {
        __time32_t actime;      /* access time */
        __time32_t modtime;     /* modification time */
        };

#if     _INTEGRAL_MAX_BITS >= 64
struct __utimbuf64 {
        __time64_t actime;      /* access time */
        __time64_t modtime;     /* modification time */
        };
#endif

#if     !__STDC__
/* Non-ANSI name for compatibility */
struct utimbuf {
        time_t actime;          /* access time */
        time_t modtime;         /* modification time */
        };
        
struct utimbuf32 {
        __time32_t actime;      /* access time */
        __time32_t modtime;     /* modification time */
        };

#endif /* !__STDC__ */

#define _UTIMBUF_DEFINED
#endif


/* Function Prototypes */

GNU4WINCE_API int __cdecl _utime32(const char * _Filename, struct __utimbuf32 * _Time);

GNU4WINCE_API int __cdecl _futime32(int _FileDes, struct __utimbuf32 * _Time);

/* Wide Function Prototypes */
GNU4WINCE_API int __cdecl _wutime32(const wchar_t * _Filename, struct __utimbuf32 * _Time);

#if     _INTEGRAL_MAX_BITS >= 64
GNU4WINCE_API int __cdecl _utime64(const char * _Filename, struct __utimbuf64 * _Time);
GNU4WINCE_API int __cdecl _futime64(int _FileDes, struct __utimbuf64 * _Time);
GNU4WINCE_API int __cdecl _wutime64(const wchar_t * _Filename, struct __utimbuf64 * _Time);
#endif

#ifdef  __cplusplus
}
#endif

#ifdef  _MSC_VER
#pragma pack(pop)
#endif  /* _MSC_VER */

#endif  /* _GNU4WINCE_UTIME_H */
