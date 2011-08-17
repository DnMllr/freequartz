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
#ifndef LIBOGLES_H_
#define LIBOGLES_H_

#include <CoreGraphics/CoreGraphics.h>
#include "CGBitmapContextPriv.h"



#ifdef __cplusplus

#if defined(__WIN32__)
#	if defined(OGLES_EXPORT_DYNAMIC)
#		define OGLES_EXTERN extern "C" DLLEXPORT
#	else
#		define OGLES_EXTERN extern "C" DLLIMPORT 
#	endif
#else
#	define OGLES_EXTERN extern "C"
#endif

#else
#if defined(__WIN32__)
#	if defined(OGLES_EXPORT_DYNAMIC)
#		define OGLES_EXTERN extern DLLEXPORT
#	else
#		define OGLES_EXTERN extern DLLIMPORT 
#	endif
#else
	#define OGLES_EXTERN extern
#endif
#endif /* __cplusplus */

typedef struct OGLES {

	CGContextDelegateRef ctxDelegate;

} *OGLESRef;

//OGLES_EXTERN Boolean OGLESLayerInitialize();

#endif /* LIBOGLES_H_ */