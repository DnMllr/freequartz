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
#ifndef CGNOTIFICATIONCENTERPRIV_H_
#define CGNOTIFICATIONCENTERPRIV_H_

#include <CoreFoundation/CFRuntime.h>
#include "CGContextPriv.h"

CF_EXTERN_C_BEGIN


//sizeof = 0x38 + 0x08 = 0x40(64)
typedef struct CGNotificationCenter {

	CFRuntimeBase obj;					//0x00
	
	//pthread_mutex_t* mutex;				//0x08


} CGNotificationCenter, *CGNotificationCenterRef;


CG_EXTERN CFTypeID CGNotificationCenterGetTypeID(void);

CG_EXTERN CGNotificationCenterRef CGNotificationCenterCreate();

CG_EXTERN void CGNotificationCenterPostNotification(CGNotificationCenterRef notifCenter, 
													CFStringRef ref, 
													CFTypeRef cftype,
													void* unknown);

void center_finalize(CFTypeRef cf);

Boolean CGRegistryEntryRelease();


CF_EXTERN_C_END

#endif /* CGNOTIFICATIONCENTERPRIV_H_ */


