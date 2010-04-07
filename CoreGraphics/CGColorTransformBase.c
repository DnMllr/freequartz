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
#include <CoreGraphics/CGColor.h>

#include "CGBasePriv.h"
#include "CGColorTransformBasePriv.h"


/* CoreFoundation runtime class for CGPath.  */
static CFRuntimeClass CGColorTransformBaseClass =  {
    0,							/* version */
    "CGColorTransformBaseClass",	/* Name of class.  */
    0,							/* init */
    0,							/* copy  */
    colortransformBaseFinalize,	/* finalize  */
	0,							/* equal  */
	0,							/* hash  */
	0,							/* copyFormattingDesc */
	0							/* copyDebugDesc */
  };
static CFTypeID __kCGColorTransformBaseID = _kCFRuntimeNotATypeID;

CFTypeID CGColorTransformBaseGetTypeID(void)
{	
	return CGTypeRegisterWithCallbacks(&__kCGColorTransformBaseID, &CGColorTransformBaseClass );
}

void colortransformBaseFinalize(CFTypeRef ctf)
{

}

CGColorTransformBaseRef CGColorTransformBaseRetain(CGColorTransformBaseRef colorTransform)
{
	if (!colorTransform) { return 0; }
	CFRetain((CFTypeRef) colorTransform);

	return colorTransform;
}

void CGColorTransformBaseRelease(CGColorTransformBaseRef colorTransform)
{
	if (!colorTransform) { return; }
	CFRelease((CFTypeRef) colorTransform);
}