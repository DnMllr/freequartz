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


#ifndef _GNU4WINCE_SYS_TYPES_H__
#define _GNU4WINCE_SYS_TYPES_H__

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
// Posix
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
/* Old compatibility names for C types.  */
typedef unsigned long int ulong;
typedef unsigned short int ushort;
typedef unsigned int uint;





//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
// WIN
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

#if !defined(_W64)
#if !defined(__midl) && (defined(_X86_) || defined(_M_IX86)) && _MSC_VER >= 1300
#define _W64 __w64
#else
#define _W64
#endif
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


#ifndef _INO_T_DEFINED

typedef unsigned short _ino_t;          /* i-node number (not used on DOS) */

#if     !__STDC__
/* Non-ANSI name for compatibility */
typedef unsigned short ino_t;
#endif

#define _INO_T_DEFINED
#endif


#ifndef _DEV_T_DEFINED

typedef unsigned int _dev_t;            /* device code */

#if     !__STDC__
/* Non-ANSI name for compatibility */
typedef unsigned int dev_t;
#endif

#define _DEV_T_DEFINED
#endif


#ifndef _OFF_T_DEFINED

typedef long _off_t;                    /* file offset value */

#if     !__STDC__
/* Non-ANSI name for compatibility */
typedef long off_t;
#endif

#define _OFF_T_DEFINED
#endif

typedef int		mode_t;
typedef int		ssize_t;


////$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//// _WIN32_WCE
////$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//#elif _WIN32_WCE
//
//#ifndef _SIZE_T_DEFINED
//typedef unsigned int size_t;
//#define _SIZE_T_DEFINED
//#endif
//
//#ifndef _OFF_T_DEFINED
//typedef long off_t;                    /* file offset value */
//typedef long _off_t;
//#define _OFF_T_DEFINED
//#endif
//
//#ifndef _DEV_T_DEFINED
//typedef unsigned int _dev_t;
//#define _DEV_T_DEFINED
//#endif
//
//#ifndef _INO_T_DEFINED
//typedef unsigned short _ino_t;
//#define _INO_T_DEFINED
//#endif
//
//typedef int		mode_t;
//typedef int		ssize_t;
//
//#endif //_WIN32_WCE

#endif // _GNU4WINCE_SYS_TYPES_H__
