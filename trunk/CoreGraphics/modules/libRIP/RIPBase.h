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
#ifndef RIPBASE_H_
#define RIPBASE_H_

#include <CoreGraphics/CoreGraphicsPrivate.h>


#ifdef __cplusplus

#if defined(__WIN32__)
#	if defined(RIP_EXPORT_DYNAMIC)
#		define RIP_EXTERN extern "C" DLLEXPORT
#	else
#		define RIP_EXTERN extern "C" DLLIMPORT 
#	endif
#else
#	define RIP_EXTERN extern "C"
#endif

#else
#if defined(__WIN32__)
#	if defined(RIP_EXPORT_DYNAMIC)
#		define RIP_EXTERN extern DLLEXPORT
#	else
#		define RIP_EXTERN extern DLLIMPORT 
#	endif
#else
	#define RIP_EXTERN extern
#endif
#endif /* __cplusplus */



#endif /* RIPBASE_H_ */