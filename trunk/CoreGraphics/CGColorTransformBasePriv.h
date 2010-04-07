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
#ifndef CGCOLORTRANSFORMBASEPRIV_H_
#define CGCOLORTRANSFORMBASEPRIV_H_

#include <CoreFoundation/CFRuntime.h>
#include <CoreGraphics/CGColorSpace.h>
#include <CoreGraphics/CGPattern.h>

#include "CGMacros.h"

CF_EXTERN_C_BEGIN

typedef struct CGColorTransformBase {
	CFRuntimeBase obj;

} CGColorTransformBase, *CGColorTransformBaseRef;

CG_EXTERN void colortransformBaseFinalize(CFTypeRef ctf);
CG_EXTERN CGColorTransformBaseRef CGColorTransformBaseRetain(CGColorTransformBaseRef colorTransform);
CG_EXTERN void CGColorTransformBaseRelease(CGColorTransformBaseRef colorTransform);
CG_EXTERN CFTypeID CGColorTransformBaseGetTypeID(void);


CF_EXTERN_C_END

#endif /* CGCOLORTRANSFORMBASEPRIV_H_ */


