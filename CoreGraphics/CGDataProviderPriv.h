/* Copyright 2010 Smartmobili SARL
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef CGDATAPROVIDERPRIV_H_
#define CGDATAPROVIDERPRIV_H_

#include <CoreFoundation/CFRuntime.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/stat.h>

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
	CGDataProviderGetBytePointerCallback getInfoBytePointer;		//0x30
	CGDataProviderReleaseBytePointerCallback releaseBytePointer;	//0x34
	CGDataProviderGetBytesAtPositionCallback getBytesAtPosition;	//0x38
	pthread_mutex_t mutex;											//0x40
	size_t byte_ptr_count;											//0x6C
	const void* data;												//0x70;
	CGDataProviderRef session;										//0x74
};
typedef struct CGDataProvider CGDataProvider, *CGDataProviderRef;


struct CGAccessSession {


};
typedef struct CGAccessSession CGAccessSession, *CGAccessSessionRef;




void				CGDataProviderDestroy(CFTypeRef ctf);
CGDataProviderRef	CGDataProviderCreateWithCopyOfData(void *data, size_t size);

/* AccessSession */
CGAccessSessionRef	CGAccessSessionCreate(CGDataProviderRef provider);
CGAccessSessionRef	CGAccessSessionRewind(CGDataProviderRef provider);
void *				CGAccessSessionGetBytePointer(CGAccessSessionRef session);
size_t				CGAccessSessionGetBytes(CGAccessSessionRef session,void *buffer,size_t bytes);
void				CGAccessSessionRelease(CGAccessSessionRef session);


CGDataProviderRef	create_provider(void *info, Boolean bThreadSafe);
static void			dataReleaseInfo(void *info);
static const void*	dataGetBytePointer(void *info);
static void			release_info(void *info);
static size_t		get_bytes_at_position(void *info, void *buf, off_t pos, size_t count);

CF_EXTERN_C_END

#endif /* CGDATAPROVIDERPRIV_H_ */


