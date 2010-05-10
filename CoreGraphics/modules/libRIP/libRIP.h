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

typedef struct RIP {

	CGContextDelegateRef ctxDelegate;

} *RIPRef;

RIP_EXTERN int RIPLayerDepthForFormat(int index);

RIP_EXTERN CGContextDelegateRef __CGBitmapContextDelegateCreate(CGBitmapContextInfoRef bitmapContextInfo, 
															   CFDictionaryRef theDict);

RIP_EXTERN uint32_t ripc_InitializeFormat(CGBitmapContextInfoRef bitmapContextInfo);

RIP_EXTERN RIPRef ripc_Initialize(RIPRef rip);

RIP_EXTERN CGError ripc_DrawImage(CGContextDelegateRef ctxDelegate, 
								  CGRenderingStateRef rendering,
								  CGGStateRef state,
								  CGRect rect,
								  CGImage image);

//RIP_EXTERN Boolean RIPLayerInitialize();

#endif /* LIBRIP_H_ */