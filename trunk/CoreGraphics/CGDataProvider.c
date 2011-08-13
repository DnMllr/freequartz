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
#include <CoreFoundation/CFURLAccess.h>
#include <CoreGraphics/CGDataProvider.h>
#include <CoreGraphics/CGColorSpace.h>

#include "CGBasePriv.h"
#include "CGDataProviderPriv.h"
#include "CGColorSpacePriv.h"



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


static const void *getCFDataBytePointer(void *info) 
{ 
	return  CFDataGetBytePtr((CFDataRef)info); 
}

static void releaseCFData(void *info) 
{ 
	CFRelease((CFDataRef)info); 
}


static pthread_once_t	get_root_dev_once = PTHREAD_ONCE_INIT;
static _dev_t			root_dev = (unsigned int)-1;

void get_root_dev()
{
	int result;
	struct _stat buf;

	result = _stat("\\", &buf);
	if (result == 0)
		root_dev = buf.st_rdev;

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
	if (!provider) return NULL;
	
	if (bThreadSafe == TRUE) {

	}

	return provider;
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
	
	provider->version = 0;
	provider->size = size;
	provider->directCalls = (CGDataProviderDirectCallbacks *)callbacks;

	provider->getBytesAtPosition = callbacks->getBytesAtPosition;
	provider->getBytePointer = callbacks->getBytePointer;
	provider->releaseBytePointer = callbacks->releaseBytePointer;
	provider->releaseInfo = callbacks->releaseInfo;

	return provider;
}

CGDataProviderRef	
CGDataProviderCreateWithCopyOfData(const void *data, size_t size)
{
	return NULL;
}

CGDataProviderRef CGDataProviderCreateWithData(void *info,
											   const void *data, size_t size,
											   CGDataProviderReleaseDataCallback releaseData)
{
	CGDataProviderRef provider;
	CGProviderDataRef providerData;
	CGDataProviderDirectCallbacks directCallBacks;
		
	providerData = (CGProviderDataRef) malloc(sizeof(CGProviderData));
	if (!providerData) {
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

void dataReleaseInfo(void *info)
{

}



const void* dataGetBytePointer(void *info)
{
	return NULL;
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

#if 1
	CFStringRef urlScheme;
	CFDataRef resData;
	//CFDictionaryRef *properties;
	CFArrayRef desiredProperties;
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
#endif
	return provider;
}


CGDataProviderRef CGDataProviderCreateWithFilename(const char *filename)
{
	CGDataProviderRef provider = NULL;
	int fd, result;
	struct _stat buf;

	fd = open(filename, 0);
	if (fd >=  0)
	{
		result = _fstat(fd, &buf);
		if ((result < 1) || ((buf.st_mode & _S_IFMT) != _S_IFREG))
			goto err_close_before_exit;

		if (root_dev == (unsigned int)-1)
			pthread_once(&get_root_dev_once, get_root_dev);
		
		if (root_dev == buf.st_rdev)
		{

		}
		else
		{

		}
	}

err_close_before_exit:
	close(fd);

err_return:
	return provider;
}

CGDataProviderRef CGDataProviderCreateWithCopyOfData(void *data, size_t size)
{
	return NULL;
}

