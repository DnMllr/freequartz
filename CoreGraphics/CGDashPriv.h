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
#ifndef CGDASHPRIV_H_
#define CGDASHPRIV_H_

#include <CoreFoundation/CFRuntime.h>
#include "CGTypesPriv.h"


CF_EXTERN_C_BEGIN

typedef  struct CGDash {

	signed long refcount;				//0x00
	CGFloat phase;						//0x04
	size_t count;						//0x08
	CGFloat* lengths;					//0x0C

} CGDash, *CGDashRef;



CG_EXTERN CGDashRef CGDashCreate(CGFloat phase, const CGFloat lengths[], size_t count);
CG_EXTERN Boolean CGDashEqualToDash(CGDashRef dash1, CGDashRef dash2);
CG_EXTERN const CGFloat* CGDashGetPattern(CGDashRef dash, CGFloat* phase, size_t* count);
CG_EXTERN CGDashRef CGDashRetain(CGDashRef dash);
CG_EXTERN void CGDashRelease(CGDashRef dash);

CF_EXTERN_C_END

#endif /* CGDASHPRIV_H_ */


