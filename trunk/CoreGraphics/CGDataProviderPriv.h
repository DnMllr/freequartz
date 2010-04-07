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
#ifndef CGDATAPROVIDERPRIV_H_
#define CGDATAPROVIDERPRIV_H_

#include <CoreFoundation/CFRuntime.h>
#include "CGMacros.h"

CF_EXTERN_C_BEGIN


struct CGProviderData {
	void* info;
	off_t size;
	const void* data;
	CGDataProviderReleaseDataCallback releaseData;
};
typedef struct CGProviderData CGProviderData, *CGProviderDataRef;

//////////////////////////////////////////////////////
// sizeof = 0x88
//////////////////////////////////////////////////////
struct CGDataProvider {

	CFRuntimeBase obj;												//0x00

	Boolean isThreadSafe;											//0x08
	void* info;														//0x0C
	off_t size;														//0x10
	CGDataProviderDirectCallbacks *directCalls;						//0x14
	CGDataProviderGetBytesCallback getBytes;						//0x18
	CGDataProviderSkipForwardCallback skipForward;					//0x1C
	uint32_t field20;												//0x20
	CGDataProviderRewindCallback rewind;							//0x24
	CGDataProviderReleaseInfoCallback releaseInfo;					//0x28
	CGDataProviderGetBytePointerCallback getBytePointer;			//0x2C
	unsigned int version;											//0x30
	CGDataProviderReleaseBytePointerCallback releaseBytePointer;	//0x34
	CGDataProviderGetBytesAtPositionCallback getBytesAtPosition;	//0x38
	//...
	//pthread_mutex_t* mutex;										//0x40
	//...
	uint32_t field6C;												//0x6C
	const void* data;												//0x70;
	
};
typedef struct CGDataProvider CGDataProvider, *CGDataProviderRef;


void				CGDataProviderDestroy(CFTypeRef ctf);
CGDataProviderRef	CGDataProviderCreateWithCopyOfData(void *data, size_t size);
CGDataProviderRef	create_provider(void *info, Boolean bThreadSafe);
void				dataReleaseInfo(void *info);
const void*			dataGetBytePointer(void *info);


CF_EXTERN_C_END

#endif /* CGDATAPROVIDERPRIV_H_ */


