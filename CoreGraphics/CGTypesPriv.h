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
#ifndef CGTYPES_H_
#define CGTYPES_H_

#include <CoreFoundation/CFRuntime.h>
#include "CGMacros.h"

CF_EXTERN_C_BEGIN

CFTypeID CGTypeRegisterWithCallbacks(CFTypeID* typeID, CFRuntimeClass* rtclass);
CFTypeRef CGTypeCreateInstance(CFTypeID id, CFIndex size);
CFTypeRef CGTypeCreateInstanceWithAllocator(CFAllocatorRef allocator, CFTypeID id, CFIndex size);
CFTypeID CGTypeGetNextIdentifier(CFTypeID id);

CF_EXTERN_C_END

#endif /* CGTYPES_H_ */


