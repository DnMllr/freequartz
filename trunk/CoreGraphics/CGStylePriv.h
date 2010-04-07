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
#ifndef CGSTYLEPRIV_H_
#define CGSTYLEPRIV_H_

#include <CoreFoundation/CFRuntime.h>
#include "CGTypesPriv.h"


CF_EXTERN_C_BEGIN

typedef  struct CGStyle {

	signed long refcount;				//0x00
	CFTypeID nexID;						//0x08

} CGStyle, *CGStyleRef;


CG_EXTERN void styleFinalize(CFTypeRef ctf);
CG_EXTERN CGStyleRef CGStyleRetain(CGStyleRef style);
CG_EXTERN void CGStyleRelease(CGStyleRef style);
CG_EXTERN CFTypeID CGStyleGetTypeID(void);



CF_EXTERN_C_END

#endif /* CGSTYLEPRIV_H_ */


