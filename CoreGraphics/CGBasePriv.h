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
#ifndef CGBASEPRIV_H_
#define CGBASEPRIV_H_

#define HAVE_COREFOUNDATION 1

#if HAVE_COREFOUNDATION
#include <CoreFoundation/CoreFoundation.h>
#include "CFInternal.h"
#else
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#endif /* HAVE_COREFOUNDATION */
#include "posix4win.h"
#include "CGTypesPriv.h"
#include "CGErrorPriv.h"

#ifdef __CONSTANT_CFSTRINGS__
	#define CG_CONST_STRING_DECL(S, V) const CFStringRef S = (const CFStringRef)__builtin___CFStringMakeConstantString("" V "");
#else 
	#if __CF_BIG_ENDIAN__
		#define CG_CONST_STRING_DECL(S, V)			\
		static struct CF_CONST_STRING __ ## S ## __ = {{(uintptr_t)&__CFConstantStringClassReference, {0x00, 0x00, 0x07, 0xc8}}, (uint8_t *)V, sizeof(V) - 1}; \
		const CFStringRef S = (CFStringRef) & __ ## S ## __;
	#elif !DEPLOYMENT_TARGET_WINDOWS || (DEPLOYMENT_TARGET_WINDOWS && defined(__GNUC__) &&!defined(__MINGW32__))
		#define CG_CONST_STRING_DECL(S, V)			\
		static struct CF_CONST_STRING __ ## S ## __ = {{(uintptr_t)&__CFConstantStringClassReference, {0xc8, 0x07, 0x00, 0x00}}, (uint8_t *)V, sizeof(V) - 1}; \
		const CFStringRef S = (CFStringRef) & __ ## S ## __;
	#elif DEPLOYMENT_TARGET_WINDOWS
		#define CG_CONST_STRING_DECL(S, V)			\
		static struct CF_CONST_STRING __ ## S ## __ = {{(uintptr_t)&__CFConstantStringClassReference, {0xc8, 0x07, 0x00, 0x00}},(uint8_t *) V, sizeof(V) - 1}; \
		CG_EXTERN const CFStringRef S = (CFStringRef) & __ ## S ## __;

		#define CG_CONST_STRING_DECL_EXPORT(S, V)			\
		struct CF_CONST_STRING __ ## S ## __ = {{___WindowsConstantStringClassReference, {0xc8, 0x07, 0x00, 0x00}}, (uint8_t *)V, sizeof(V) - 1}; \
		CG_EXTERN const CFStringRef S = (CFStringRef) & __ ## S ## __;
	#else
		#define CG_CONST_STRING_DECL(S, V)			\
		static struct CF_CONST_STRING __ ## S ## __ = {{(uintptr_t)NULL, {0xc8, 0x07, 0x00, 0x00}},(uint8_t *) V, sizeof(V) - 1}; \
		const CFStringRef S = (CFStringRef) & __ ## S ## __;

		#define CG_CONST_STRING_DECL_EXPORT(S, V)			\
		struct CF_CONST_STRING __ ## S ## __ = {{(uintptr_t)NULL, {0xc8, 0x07, 0x00, 0x00}}, (uint8_t *)V, sizeof(V) - 1}; \
		CG_EXTERN const CFStringRef S = (CFStringRef) & __ ## S ## __;

	#endif /* __BIG_ENDIAN__ */
#endif /* __CONSTANT_CFSTRINGS__ */

#define CHK( x ) do{ if( ( x ) == 0) { goto Cleanup; }} while( FALSE );

#endif /* CGBASEPRIV_H_ */