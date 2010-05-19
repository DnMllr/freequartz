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
#ifndef LIBRIP_H_
#define LIBRIP_H_

#include <CoreGraphics/CoreGraphics.h>
#include "CGBitmapContextPriv.h"



#ifdef __cplusplus

#if defined(__WIN32__)
#	if defined(CGR_EXPORT_DYNAMIC)
#		define CGR_EXTERN extern "C" DLLEXPORT
#	else
#		define CGR_EXTERN extern "C" DLLIMPORT 
#	endif
#else
#	define CGR_EXTERN extern "C"
#endif

#else
#if defined(__WIN32__)
#	if defined(CGR_EXPORT_DYNAMIC)
#		define CGR_EXTERN extern DLLEXPORT
#	else
#		define CGR_EXTERN extern DLLIMPORT 
#	endif
#else
	#define CGR_EXTERN extern
#endif
#endif /* __cplusplus */

typedef struct CGR {

	CGContextDelegateRef ctxDelegate;

} *CGRRef;

CGR_EXTERN int CGRLayerDepthForFormat(int index);

CGR_EXTERN CGContextDelegateRef __CGBitmapContextDelegateCreate(CGBitmapContextInfoRef bitmapContextInfo, 
															   CFDictionaryRef theDict);

CGR_EXTERN uint32_t cgrc_InitializeFormat(CGBitmapContextInfoRef bitmapContextInfo);

//CGR_EXTERN CGRRef cgrc_Initialize(RIPRef rip);

CGR_EXTERN CGError cgrc_DrawImage(CGContextDelegateRef ctxDelegate, 
								  CGRenderingStateRef rendering,
								  CGGStateRef state,
								  CGRect rect,
								  CGImage image);


#endif /* LIBRIP_H_ */