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

#include <CoreFoundation/CoreFoundation.h>
#include <CoreGraphics/CoreGraphicsPrivate.h>

//#include <CoreGraphics/CGContext.h>
//#include <CoreGraphics/CGBitmapContext.h>
//#include <CoreGraphics/CGDirectDisplay.h>
//#include "CGWindowContextPriv.h"



CGSConnection _CGSDefaultConnection()
{
	return 0;
}

CGContextRef CGDisplayGetDrawingContext (CGDirectDisplayID display)
{
	CGContextRef context;

	context = CGWindowContextCreate(_CGSDefaultConnection(), 0,0);
	

	return context;
}


CGContextRef CGWindowContextCreate(CGSConnection cid, CGSWindow wid, CFDictionaryRef theDict)
{
	CGContextRef context;
	CGContextDelegateRef ctxDelegate;
	CGWindowContextInfoRef window_info;
	CGWindowContextDelegateCreateCallback CGWindowContextDelegateCreate;
	void *filterInfo;
	Boolean bValue;

	context = CGContextCreate();
	if (!context) {
		CGPostError("%s: failed to create window context.", "CGWindowContextCreate");	
		goto CGWindowContextCreate_Exit;
	}

	window_info = (CGWindowContextInfoRef)calloc(1, sizeof(CGWindowContextInfo));
	if (!window_info) {
		CGContextRelease(context);
		context = NULL;
		goto CGWindowContextCreate_Exit;
	}

	if (CGDefaultsGetBoolean("CG_USE_CA_WINDOW_CONTEXT", &bValue) || 
		CGDefaultsGetBoolean("CGWindowContextShouldUseCA", &bValue) ||
		CGCFDictionaryGetBoolean(theDict, CFSTR("CGWindowContextShouldUseCA"), &bValue))
	{

	}
	else
	{
		CGWindowContextDelegateCreate = 
			(CGWindowContextDelegateCreateCallback)CGLibraryLoadFunction("CGRD2D", "_CGWindowContextDelegateCreate");
	
		if (!CGWindowContextDelegateCreate) {
			CGPostError("Failed to load RIP CGWindowContext.");
		}
	}

	ctxDelegate = CGWindowContextDelegateCreate(window_info, theDict);
	if (!ctxDelegate) {
		CGContextRelease(context); 
		context = NULL;
		CGPostError("Failed to load RIP CGWindowContext.");
		goto CGWindowContextCreate_Exit;
	}

	CGContextSetDelegate(context, ctxDelegate);
	CGContextDelegateRelease(ctxDelegate);
	if ( theDict )
	{
		filterInfo = (void*) CFDictionaryGetValue(theDict, kCGContextFilterInfo);
		if ( filterInfo )
			context = CGContextAddFilter(context, filterInfo, 0);
	}

CGWindowContextCreate_Exit:
	return context;
}