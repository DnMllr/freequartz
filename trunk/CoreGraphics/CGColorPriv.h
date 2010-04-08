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
#ifndef CGCOLORPRIV_H_
#define CGCOLORPRIV_H_

#include <CoreFoundation/CFRuntime.h>
#include <CoreGraphics/CGColorSpace.h>
#include <CoreGraphics/CGPattern.h>

#include "CGMacros.h"

extern CFTypeID __kCGColorSpaceID;

CF_EXTERN_C_BEGIN

typedef struct CGColor {
	CFRuntimeBase obj;				//0x00

	CFTypeID nextID;				//0x08
	CGColorSpaceRef colorSpace;		//0x10
	CGPatternRef pattern;			//0x14
	size_t numberOfComponents;		//0x1C
	CGFloat *components;			//0x20	

} *CGColorRef;

void CGColorDestroy(CFTypeRef ctf);



CF_EXTERN_C_END

#endif /* CGCOLORPRIV_H_ */


