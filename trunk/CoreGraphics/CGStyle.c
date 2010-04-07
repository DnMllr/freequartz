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
#include <CoreGraphics/CGContext.h>

#include "CGBasePriv.h"
#include "CGContextPriv.h"
#include "CGStylePriv.h"


static CFRuntimeClass CGStyleClass = 
  {
    0,							// version
    "CGStyle",					// className
    0,							// init
    0,							// copy
    styleFinalize,				// finalize
	0,							// equal
	0,							// hash
	0,							// copyFormattingDesc
	0							// copyDebugDesc
  };
CFTypeID __kCGStyleID = _kCFRuntimeNotATypeID;


CFTypeID CGStyleGetTypeID(void)
{
	return CGTypeRegisterWithCallbacks(&__kCGStyleID, &CGStyleClass);
}

void styleFinalize(CFTypeRef c)
{

}

void CGStyleRelease(CGStyleRef style)
{
	if (!style) { return; }
	CFRelease((CFTypeRef)style);
}
