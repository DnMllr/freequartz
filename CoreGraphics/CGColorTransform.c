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
#include <CoreGraphics/CGColor.h>

#include "CGBasePriv.h"
#include "CGColorTransformPriv.h"


/* CoreFoundation runtime class for CGPath.  */
static CFRuntimeClass CGColorTransformClass =  {
    0,							/* version */
    "CGColorTransformClass",	/* Name of class.  */
    0,							/* init */
    0,							/* copy  */
    colortransformFinalize,		/* finalize  */
	0,							/* equal  */
	0,							/* hash  */
	0,							/* copyFormattingDesc */
	0							/* copyDebugDesc */
  };
static CFTypeID __kCGColorTransformID = _kCFRuntimeNotATypeID;

CFTypeID CGColorTransformGetTypeID(void)
{	
	return CGTypeRegisterWithCallbacks(&__kCGColorTransformID, &CGColorTransformClass );
}

void colortransformFinalize(CFTypeRef ctf)
{

}

CGColorTransformRef CGColorTransformRetain(CGColorTransformRef colorTransform)
{
	if (!colorTransform) { return 0; }
	CFRetain((CFTypeRef) colorTransform);

	return colorTransform;
}

void CGColorTransformRelease(CGColorTransformRef colorTransform)
{
	if (!colorTransform) { return; }
	CFRelease((CFTypeRef) colorTransform);
}

int CGColorTransformGetIdentifier(CGColorTransformRef colorTransform)
{
	if (!colorTransform) { return 0; }
	return colorTransform->identifier;
}