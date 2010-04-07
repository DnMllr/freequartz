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
#include "CGTypesPriv.h"


CFTypeID CGTypeRegisterWithCallbacks(CFTypeID* typeID, CFRuntimeClass* rtclass)
{
	CFTypeID id;

	if (*typeID != _kCFRuntimeNotATypeID) { return *typeID; }

	
	id = _CFRuntimeRegisterClass(rtclass);
	*typeID = id;

	return id;
}


CFTypeRef CGTypeCreateInstance(CFTypeID id, CFIndex size)
{
	return CGTypeCreateInstanceWithAllocator(0, id, size);
}

//pthread_mutex_t _mutex;

CFTypeID CGTypeGetNextIdentifier(CFTypeID id)
{
	//pthread_mutex_lock(&_mutex);
	id++;
	//pthread_mutex_unlock(&_mutex);

	return id;
}

CFTypeRef CGTypeCreateInstanceWithAllocator(CFAllocatorRef allocator, CFTypeID id, CFIndex size)
{
	CFTypeRef type;
	char* ptr;
	

	/* Create the CFType */
	//
	type = _CFRuntimeCreateInstance(allocator, id, size, NULL);
	if (!type) goto Cleanup;

	///* Init with zero values all fields except our base object */
	ptr = (char*)type;
	memset((void*)(ptr + sizeof(CFRuntimeBase)), 0, size);
	
	return type;

Cleanup:
	return NULL;
}