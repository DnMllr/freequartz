/****************************************************************************
**
** Copyright (C) 2010 Smartmobili.
** All rights reserved.
** Contact: Smartmobili (contact@smartmobili.com)
**	
** This file is part of the CoreGraphics module of the Coconuts Toolkit.
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
#include "CGBasePriv.h"
#include "CGRenderingStatePriv.h"



CGRenderingStateRef CGRenderingStateCreate()
{
	CGRenderingStateRef rendering;

	rendering = (CGRenderingStateRef)calloc(1, sizeof(CGRenderingState));
	if (!rendering)
		return NULL;

	rendering->refcount = 1;
	
	CGRenderingStateReset(rendering);

	return rendering;
}

CGRenderingStateRef	CGRenderingStateCreateCopy(CGRenderingStateRef rendering)
{
	return NULL;
}

void CGRenderingStateRelease(CGRenderingStateRef rendering)
{
	if (!rendering) { return; }
	rendering->refcount--;

	if (rendering->refcount == 0) { 
		free(rendering);
	}
}

void CGRenderingStateReset(CGRenderingStateRef rendering)
{
	rendering->baseCTM = CGAffineTransformIdentity;
	rendering->minInterpolQuality = 0;
	rendering->maxInterpolQuality = 0;	
	rendering->allowAcceleration = true;		
	rendering->allowAntialias = true;		
	rendering->allowDithering = true;		
	rendering->allowFontAntialias = true;	
	rendering->allowFontSmoothing = true;	
	rendering->allowFontSubPos = true;		
	rendering->allowFontSubQuant = true;		
}

void CGRenderingStateSetRenderingResolution(CGSize resolution)
{

}