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