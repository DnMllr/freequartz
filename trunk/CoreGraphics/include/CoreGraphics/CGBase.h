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
#ifndef CGBASE_H_
#define CGBASE_H_

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include <float.h>

#  include <Availability.h>

#  define CG_AVAILABLE_STARTING(_mac,_iphone)
#  define CG_AVAILABLE_BUT_DEPRECATED(_mac,_macDep,_iphone,_iphoneDep)

#  if defined(_WIN32) || defined(__CYGWIN32__)
#    define __WIN32__ 1
#    define DLLEXPORT __declspec(dllexport)
#  if defined (_WIN32_WCE)
#    define DLLIMPORT
#  else
#    define DLLIMPORT __declspec(dllimport)
#  endif
#  endif



#if !defined(CG_EXTERN_C_BEGIN)
#  if defined(__cplusplus)
#    define CG_EXTERN_C_BEGIN extern "C" {
#    define CG_EXTERN_C_END	  }
#  else /* !defined(__cplusplus) */
#    define CG_EXTERN_C_BEGIN extern {
#    define CG_EXTERN_C_END  }
#  endif /* !defined(__cplusplus) */
#endif /* !defined(CG_EXTERN_C_BEGIN) */

#ifdef __cplusplus

#if defined(__WIN32__)
#	if defined(CG_EXPORT_DYNAMIC)
#		define CG_EXTERN extern "C" DLLEXPORT
#       pragma message("######### CG_EXTERN=extern \"C\" DLLEXPORT #########")
#	else
#		define CG_EXTERN extern "C" DLLIMPORT 
#       pragma message("######### CG_EXTERN=extern \"C\" DLLIMPORT #########")
#	endif
#else
#	define CG_EXTERN extern "C"
#endif

#else
#if defined(__WIN32__)
#	if defined(CG_EXPORT_DYNAMIC)
#		define CG_EXTERN extern DLLEXPORT
#       pragma message("######### CG_EXTERN=extern DLLEXPORT #########")
#	else
#		define CG_EXTERN extern DLLIMPORT 
#       pragma message("######### CG_EXTERN=extern DLLIMPORT ######### ")
#	endif
#else
	#define CG_EXTERN extern
#endif
#endif

#if !defined(CG_PRIVATE_EXTERN)
#  if defined(__GNUC__)
#    define CG_PRIVATE_EXTERN __private_extern__
#  else /* !defined(__GNUC__) */
#    define CG_PRIVATE_EXTERN CG_EXTERN
#  endif /* !defined(__GNUC__) */
#endif /* !defined(CG_PRIVATE_EXTERN) */

#if !defined(CG_LOCAL)
#  define CG_LOCAL CG_PRIVATE_EXTERN
#endif

#if !defined(CG_OBSOLETE)
#  if defined(__GNUC__)							\
    && ((__GNUC__ == 3 && __GNUC_MINOR__ >= 1) || __GNUC__ >= 4)
#      define CG_OBSOLETE __attribute__((deprecated))
#  else
#    define CG_OBSOLETE
#  endif
#endif /* !defined(CG_OBSOLETE) */

#if !defined(CG_INLINE)
#  if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
#    define CG_INLINE static inline
#  elif defined(__MWERKS__) || defined(__cplusplus)
#    define CG_INLINE static inline
#  elif defined(__GNUC__)
#    define CG_INLINE static __inline__
#  else
#    define CG_INLINE static    
#  endif
#endif /* !defined(CG_INLINE) */

#if !defined(__GNUC__) && !defined(__MWERKS__)
#  define __attribute__(attribute)
#endif

#if !defined(CGFLOAT_DEFINED)
#  if defined(__LP64__) && __LP64__
     typedef double CGFloat;
#    define CGFLOAT_MIN DBL_MIN
#    define CGFLOAT_MAX DBL_MAX
#    define CGFLOAT_IS_DOUBLE 1
#  else /* !defined(__LP64__) || !__LP64__ */
     typedef float CGFloat;
#    define CGFLOAT_MIN FLT_MIN
#    define CGFLOAT_MAX FLT_MAX
#    define CGFLOAT_IS_DOUBLE 0
#  endif /* !defined(__LP64__) || !__LP64__ */

#define CGFLOAT_DEFINED 1
#endif /* !defined(CGFLOAT_DEFINED) */

#endif /* CGBASE_H_ */
