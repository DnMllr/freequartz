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

#include "CGMacros.h"

CF_EXTERN_C_BEGIN

// include issues because in this file CG_EXTERN and DLLEXPORT are not properly
// defined that's why I am explicitely putting __declspec.
// TODO : need to find why !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//CG_EXTERN const CFStringRef kCGCTypeCopyDescFormat;
extern __declspec(dllexport) const CFStringRef kCGCTypeCopyDescFormat;

CFStringRef copy_description(CFTypeRef cf, CFDictionaryRef formatOptions);
CFStringRef copy_debug_description(CFTypeRef cf);

CFTypeID CGTypeRegisterWithCallbacks(CFTypeID* typeID, CFRuntimeClass* rtclass);
CFTypeRef CGTypeCreateInstance(CFTypeID id, CFIndex size);
CFTypeRef CGTypeCreateInstanceWithAllocator(CFAllocatorRef allocator, CFTypeID id, CFIndex size);
CFTypeID CGTypeGetNextIdentifier(CFTypeID id);
CFTypeRef CGTypeCreateSingleton(CFTypeID typeID, void *memory, CFIndex size);

CF_EXTERN_C_END

#endif /* CGTYPES_H_ */


