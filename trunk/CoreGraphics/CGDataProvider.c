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
#include <CoreFoundation/CFURLAccess.h>
#include <CoreGraphics/CGDataProvider.h>
#include <CoreGraphics/CGColorSpace.h>

#include "CGBasePriv.h"
#include "CGDataProviderPriv.h"
#include "CGColorSpacePriv.h"

//TODO : provide implementation

static pthread_once_t	get_root_dev_once = PTHREAD_ONCE_INIT;
static _dev_t			root_dev = (unsigned int)-1;
static pthread_mutex_t get_byte_ptr_count_lock;

/* CoreFoundation runtime class for CGDataProvider.  */
static CFRuntimeClass CGDataProviderClass =  {
    0,							/* version */
    "CGDataProvider",			/* Name of class.  */
    0,							/* init */
    0,							/* copy  */
    CGDataProviderDestroy,		/* finalize  */
	0,							/* equal  */
	0,							/* hash  */
	0,							/* copyFormattingDesc */
	0							/* copyDebugDesc */
  };
static CFTypeID __kCGDataProviderID = _kCFRuntimeNotATypeID;


#ifdef WIN32

//static void *  mmap(void *start, size_t length, int prot , int flags, int fd, off_t offset)
//{ 
//	return  NULL;
//}
//
//
//static int munmap(void *, size_t)
//{ 
//	return  0;
//}

static ssize_t pread (int fd, void *buf, size_t count, off_t offset)
{
	DWORD written;
	HANDLE handle;
	OVERLAPPED olap;
	int ret;
	ULARGE_INTEGER ulioffset;

	handle = (HANDLE)(intptr_t)_get_osfhandle (fd);
	if (handle == INVALID_HANDLE_VALUE)
		return -1;

	memset(&olap, 0, sizeof(olap));
	ulioffset.QuadPart = offset;
	olap.Offset = ulioffset.LowPart;
	olap.OffsetHigh = ulioffset.HighPart;
	
	ret = ReadFile (handle, buf, count, &written, &olap);
	if (!ret) {
        ret = GetOverlappedResult(handle, &olap, &written, TRUE);
        if (!ret)
            return -EIO;
        else
            return written;
    }

	return written;
}
#endif


static const void *getCFDataBytePointer(void *info) 
{ 
	return  CFDataGetBytePtr((CFDataRef)info); 
}

static void releaseCFData(void *info) 
{ 
	CFRelease((CFDataRef)info); 
}

void dataReleaseInfo(void *info)
{
	CGProviderDataRef data = (CGProviderDataRef)info;
	if (data->releaseData != NULL) {
		data->releaseData(data->info, data->data, data->size);
	}

	free(info);
}

const void* dataGetBytePointer(void *info)
{
	return ((CGProviderDataRef)info)->data;
}


int decrement_get_byte_ptr_count(CGDataProviderRef provider)
{
	int result;

	pthread_mutex_lock(&get_byte_ptr_count_lock); // Who init get_byte_ptr_count_lock ?
	provider->byte_ptr_count--;
	result = pthread_mutex_unlock(&get_byte_ptr_count_lock);
	
	return result;
}




void get_root_dev()
{
	/*struct stat buf;
	
	if (stat("\\", &buf) == 0) 
		root_dev = buf.st_rdev;*/
	root_dev = 0;

	return;
}



CFTypeID CGDataProviderGetTypeID(void)
{	
	return CGTypeRegisterWithCallbacks(&__kCGDataProviderID, &CGDataProviderClass );
}

void CGDataProviderDestroy(CFTypeRef ctf)
{
	CGDataProviderRef provider = (CGDataProviderRef) (ctf);
}

CGDataProviderRef CGDataProviderRetain(CGDataProviderRef provider)
{
	if (!provider) { return 0; }
	return ((CGDataProviderRef)CFRetain((CFTypeRef) provider));
}

void CGDataProviderRelease(CGDataProviderRef provider)
{
	if (!provider) { return; }
	CFRelease((CFTypeRef)provider);
}



CGDataProviderRef create_provider(void *info, Boolean bThreadSafe)
{
	CGDataProviderRef provider;
	int size;

	size = sizeof(CGDataProvider) - sizeof(CFRuntimeBase);
	provider = (CGDataProviderRef) CGTypeCreateInstance( CGDataProviderGetTypeID(), size );
	if (provider) 
	{
		provider->isThreadSafe = TRUE;
		provider->info = info;
		provider->size = -1;
		provider->directCalls = NULL;
		provider->byte_ptr_count = 0;
		pthread_mutex_init(&(provider->mutex), NULL); 
	}
	else
	{
		provider = NULL;
	}

	return provider;
}

void* CGDataProviderGetBytePtr(CGDataProviderRef provider)
{
	void* data = NULL;

	// IMPLEMENT HERE
	/*if (!provider || !provider->getBytePointer)
		return NULL;
	
	if (provider->releaseBytePointer)
	{
		pthread_mutex_lock(&get_byte_ptr_count_lock);
		provider->byte_ptr_count--;
		pthread_mutex_unlock(&get_byte_ptr_count_lock);
	}

	if (!provider->data)
	{
		pthread_mutex_lock(&get_byte_ptr_count_lock);
		provider->data = provider->getBytePointer(provider->info);
	}
	else
	{
		if (provider->getInfoBytePointer != NULL)
			provider->getBytePointer(provider->info);
	}*/

	return data;
}

size_t CGDataProviderGetSize(CGDataProviderRef provider)
{
	//size_t size;

	if (!provider || provider->size < 0) 
	{
		CGPostError("%s: size is too large for this function", "CGDataProviderGetSize");
		return -1;
	}

	return provider->size;
}

size_t CGDataProviderGetSize2(CGDataProviderRef provider)
{
	if (!provider)
		return -1;

	return provider->size;
}


CGDataProviderRef CGDataProviderCreateSequential(void *info,
												 const CGDataProviderSequentialCallbacks *callbacks)
{
	CGDataProviderRef provider;

	if (!info || !callbacks) 
		return NULL;

	provider = create_provider(info, TRUE);
	if (!provider) 
		return NULL;

	provider->getBytes = callbacks->getBytes;
	provider->skipForward = callbacks->skipForward;
	provider->rewind = callbacks->rewind;
	provider->releaseInfo = callbacks->releaseInfo;

	return provider;
}


CGDataProviderRef CGDataProviderCreateDirect(void *info, off_t size,
											 const CGDataProviderDirectCallbacks *callbacks)
{

	/* 
	* Due to gcc optimization I think that : R0 = info, R2 =? , R1 = size, R3 = callbacks
	*/

	CGDataProviderRef provider;

	if (!callbacks || callbacks->version != 0)
		return NULL;

	provider = create_provider(info, FALSE);
	if (!provider) 
		return NULL;
	
	provider->getInfoBytePointer = NULL;
	provider->size = size;
	provider->directCalls = (CGDataProviderDirectCallbacks *)callbacks;

	provider->getBytesAtPosition = callbacks->getBytesAtPosition;
	provider->getBytePointer = callbacks->getBytePointer;
	provider->releaseBytePointer = callbacks->releaseBytePointer;
	provider->releaseInfo = callbacks->releaseInfo;

	return provider;
}





CGDataProviderRef CGDataProviderCreateWithData(void *info,
											   const void *data, size_t size,
											   CGDataProviderReleaseDataCallback releaseData)
{
	CGDataProviderRef provider;
	CGProviderDataRef providerData;
	CGDataProviderDirectCallbacks directCallBacks;
		
	providerData = (CGProviderDataRef) malloc(sizeof(CGProviderData));
	if (providerData) {
		providerData->info = info;
		providerData->size = (off_t)size;
		providerData->data = data;
		providerData->releaseData = releaseData;

		directCallBacks.version = 0;
		directCallBacks.getBytesAtPosition = NULL;
		directCallBacks.releaseBytePointer = NULL;
		directCallBacks.getBytePointer = dataGetBytePointer;
		directCallBacks.releaseInfo = dataReleaseInfo;

		provider = CGDataProviderCreateDirect(providerData, (off_t)size, &directCallBacks);
		if (!provider) {
			free(providerData);
		}
		else {
			provider->data = data;
		}
	}
	
	return provider;
}	



CGDataProviderRef CGDataProviderCreateWithCFData(CFDataRef data)
{
	CGDataProviderRef provider;
	CFIndex length;

	static const CGDataProviderDirectCallbacks callbacks = { 
		0,							/* version */
		&getCFDataBytePointer,		/* getBytePointer */
		NULL,						/* releaseBytePointer */
		NULL,						/* getBytesAtPosition */
		&releaseCFData,				/* releaseInfo */
	};	

	if (!data)
		return NULL;

	CFRetain(data);
	length = CFDataGetLength(data);

	// Don't understand in arm asm callbacks seem to be null (MOV.W   R2, #0)
	provider = CGDataProviderCreateDirect((void*)data, length, &callbacks);
	if (provider != NULL) 
	{
		provider->data = CFDataGetBytePtr(data);
	}
	else 
	{
		CFRelease(data);
	}
	
	return provider;
}

CGDataProviderRef CGDataProviderCreateWithURL(CFURLRef url)
{
	CGDataProviderRef provider = NULL;

	CFStringRef urlScheme;
	CFDataRef resData;
	//CFDictionaryRef *properties;
	CFArrayRef desiredProperties = NULL;
	SInt32 err;
	//Boolean bRet;
	UInt8 buffer[MAX_PATH+1];


	urlScheme = CFURLCopyScheme(url);
	if (CFStringCompare(urlScheme, CFSTR("file"), 0) == 0) {
		
		CFRelease(urlScheme);
		if (CFURLGetFileSystemRepresentation(url, true, buffer, MAX_PATH)) {

			provider = CGDataProviderCreateWithFilename((const char*)buffer);
		}
	}
	
	if (!urlScheme || !provider) {
	
		if (CFURLCreateDataAndPropertiesFromResource(NULL, url, &resData, 
			NULL, desiredProperties, &err) == false) {
				CGPostError("CFURLCreateDataAndPropertiesFromResource: failed with error code %d.", err);
				return NULL;
		}
		else {
			provider = CGDataProviderCreateWithCFData(resData);
			CFRelease(resData);
		}
	}

	return provider;
}


static const CGDataProviderDirectCallbacks file_callbacks = { 
	0,							/* version */
	NULL,						/* getBytePointer */
	NULL,						/* releaseBytePointer */
	&get_bytes_at_position,		/* getBytesAtPosition */
	&release_info,				/* releaseInfo */
};


static void release_info(void *info)
{ 
	int fd;
	fd = *((int*)info);
	close(fd);
	return;
}

static size_t get_bytes_at_position(void *info, void *buf, off_t pos, size_t count) 
{ 
	ssize_t size;
	size = pread(*((int*)info), buf, count, pos);	
	return size;
}

static void free_data(void *info, const void *data, size_t size)
{
	free((char *) data);
}



void unmap_file(void *info, const void *data, size_t size)
{
	int result;

	result = munmap((void*)data, size);
	if (result < 0)
	{
		CGPostError("Failed to unmap data (%p; 0x%lx): %s.\n", 
			data, size, strerror(NULL));
	}

	return;
}



CGDataProviderRef CGDataProviderCreateWithCopyOfData(void *data, size_t size)
{
	// Allow to determine if address was otained through mmap or normall allocation
	//SIZE_T WINAPI VirtualQuery( __in_opt  LPCVOID lpAddress, __out     PMEMORY_BASIC_INFORMATION lpBuffer, __in      SIZE_T dwLength);

	return NULL;
}


CGDataProviderRef CGDataProviderCreateWithFilename(const char *filename)
{
	CGDataProviderRef provider = NULL;
	int fd, result;
	struct stat file_info;
	void* ptr;
	void* buf;

	fd = open(filename, 0);
	if (fd >=  0)
	{
		result = fstat(fd, &file_info);
		if ((result < 1) || ((file_info.st_mode & _S_IFMT) != _S_IFREG)) 
		{
			close(fd);
			return NULL;
		}

		if (root_dev == (unsigned int)-1)
			pthread_once(&get_root_dev_once, get_root_dev);


		if ((file_info.st_size > 0) && (file_info.st_size <= 10485760))
		{
			if (root_dev == file_info.st_rdev)
			{
				ptr = mmap((void*)0, file_info.st_size, PROT_EXEC, MAP_PRIVATE, fd, 0);
				if ((ptr != MAP_FAILED && ptr != NULL))
				{
					close(fd);
					provider = CGDataProviderCreateWithData(0,ptr, file_info.st_size, unmap_file);
					return provider;
				}
			}
			
			buf = malloc(file_info.st_size);
			if (buf != NULL)
			{
				result = read(fd, buf, file_info.st_size);
				if ((result == -1) || (result != file_info.st_size))
				{
					CGPostError("%s: warning: failed to read entire file", "read_file");
					if (result > 0)
					{
						memset(((char*)buf+result), 0, file_info.st_size - result);
						close(fd);
						provider = CGDataProviderCreateWithData(0, buf, result, free_data);
					}
				}
			}
			else
			{
				provider = CGDataProviderCreateDirect((void*)&fd, file_info.st_size, &file_callbacks);
			}
		}
		else
		{
			provider = CGDataProviderCreateDirect((void*)&fd, file_info.st_size, &file_callbacks);
		}
	}	

	return provider;
}

CGAccessSessionRef	CGAccessSessionCreate(CGDataProviderRef provider)
{
	CGAccessSessionRef session;

	if (provider) 
	{
		pthread_mutex_lock(&(provider->mutex));
		provider->session = provider;
		if (provider->releaseBytePointer)
		{
			//IMPLEMENT HERE
		}

		session = CGAccessSessionRewind(provider);
	}
	else
	{
		session = NULL;
	}

	return session;
}


CGAccessSessionRef	CGAccessSessionRewind(CGDataProviderRef provider)
{
	//IMPLEMENT HERE
	return NULL;
}

void *	CGAccessSessionGetBytePointer(CGAccessSessionRef session)
{
	//IMPLEMENT HERE
	return NULL;
}

size_t	CGAccessSessionGetBytes(CGAccessSessionRef session,void *buffer,size_t bytes)
{
	//IMPLEMENT HERE
	return 0;
}

void CGAccessSessionRelease(CGAccessSessionRef session)
{
	//IMPLEMENT HERE
	return;
}