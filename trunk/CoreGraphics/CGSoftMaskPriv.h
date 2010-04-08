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
#ifndef CGSOFTMASKPRIV_H_
#define CGSOFTMASKPRIV_H_

#include <CoreFoundation/CFRuntime.h>
#include "CGTypesPriv.h"
#include "CGImagePriv.h"


CF_EXTERN_C_BEGIN

typedef  struct CGSoftMask {

	CFRuntimeBase obj;				//0x00

	CGImageRef mask;				//0x44
	
} CGSoftMask, *CGSoftMaskRef;


CG_EXTERN void softMaskFinalize(CFTypeRef ctf);
CG_EXTERN CGSoftMaskRef CGSoftMaskRetain(CGSoftMaskRef softMask);
CG_EXTERN void CGSoftMaskRelease(CGSoftMaskRef softMask);
CG_EXTERN CFTypeID CGSoftMaskGetTypeID(void);



CF_EXTERN_C_END

#endif /* CGSOFTMASKPRIV_H_ */


