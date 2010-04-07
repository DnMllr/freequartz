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
#ifndef CGFUNCTIONPRIV_H_
#define CGFUNCTIONPRIV_H_

#include <CoreFoundation/CFRuntime.h>
#include "CGTypesPriv.h"


CF_EXTERN_C_BEGIN

//sizeof = 
typedef  struct CGFuction {

	CFRuntimeBase obj;					//0x00

} CGFuction, *CGFuctionRef;


void functionFinalize(CFTypeRef c);


CF_EXTERN_C_END

#endif /* CGFUNCTIONPRIV_H_ */


