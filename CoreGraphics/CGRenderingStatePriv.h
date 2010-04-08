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
#ifndef CGRENDERINGSTATE_H_
#define CGRENDERINGSTATE_H_

#include <CoreGraphics/CGAffineTransform.h>
#include "CGMacros.h"
#include "CGStylePriv.h"
#include "CGSoftMaskPriv.h"



CF_EXTERN_C_BEGIN

////////////////////////////////////////////
//CGGStateRendering - sizeof = 0x34
typedef struct CGRenderingState {
	signed long refcount;		//0x00

	CGFloat hRes;				//0x04
	CGFloat vRes;				//0x04
	CGAffineTransform baseCTM;	//0x0C
	int	 minInterpolQuality;	//0x24
	int	 maxInterpolQuality;	//0x28 
	Boolean allowAcceleration;	//0x2C
	Boolean allowAntialias;		//0x2D
	Boolean allowDithering;		//0x2E
	Boolean allowFontAntialias;	//0x2F
	Boolean allowFontSmoothing;	//0x30
	Boolean allowFontSubPos;	//0x31
	Boolean allowFontSubQuant;	//0x32

} CGRenderingState, *CGRenderingStateRef;


CG_EXTERN CGRenderingStateRef		CGRenderingStateCreate();
CG_EXTERN CGRenderingStateRef		CGRenderingStateCreateCopy(CGRenderingStateRef rendering);
CG_EXTERN void						CGRenderingStateReset(CGRenderingStateRef rendering);
CG_EXTERN void						CGRenderingStateRelease(CGRenderingStateRef rendering);
CG_EXTERN void						CGRenderingStateSetRenderingResolution(CGRenderingStateRef rendering, CGFloat hRes, CGFloat vRes);

CF_EXTERN_C_END

#endif /* CGRENDERINGSTATE_H_ */


