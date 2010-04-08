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
#ifndef CGLAYERPRIV_H_
#define CGLAYERPRIV_H_

#include "CoreFoundation/CFRuntime.h"
#include "CGTypesPriv.h"
#include "CGNotificationCenterPriv.h"

CF_EXTERN_C_BEGIN

//sizeof = 0x0C + 0x08 = 0x14
typedef  struct CGLayer {

	CFRuntimeBase obj;					//0x00
	CGContextRef ctx;					//0x08

} CGLayer, *CGLayerRef;



CG_EXTERN CGNotificationCenterRef CGLayerNotificationCenter(CGLayerRef layer);



void layerFinalize(CFTypeRef c);




CF_EXTERN_C_END

#endif /* CGLAYERPRIV_H_ */


