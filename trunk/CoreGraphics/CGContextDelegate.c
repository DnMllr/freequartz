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
#include <CoreGraphics/CGContext.h>

#include "CGBasePriv.h"
#include "CGContextPriv.h"
#include "CGContextDelegatePriv.h"
#include "CGGStatePriv.h"



//static CGCallback rendering_callbacks[] = 


static CFRuntimeClass CGContextDelegateClass = 
  {
    0,							// version
    "CGContextDelegate",		// className
    0,							// init
    0,							// copy
    delegate_finalize,			// finalize
	0,							// equal
	0,							// hash
	0,							// copyFormattingDesc
	0							// copyDebugDesc
  };
CFTypeID __kCGContextDelegateID = _kCFRuntimeNotATypeID;


CFTypeID CGContextDelegateGetTypeID(void)
{
	return CGTypeRegisterWithCallbacks(&__kCGContextDelegateID, &CGContextDelegateClass);
}


CGContextDelegateRef CGContextDelegateCreate(void* info)
{
	CGContextDelegateRef ctxDelegate;
	CFIndex size;

	size = sizeof(CGContextDelegate) - sizeof(CFRuntimeBase);
	ctxDelegate = (CGContextDelegateRef) CGTypeCreateInstance( CGContextDelegateGetTypeID(), size );
	if (!ctxDelegate) { return 0; }
	ctxDelegate->info = (CGContextDelegateInfoRef)info;

	return ctxDelegate;
}

void CGContextDelegateFinalize(CGContextDelegateRef ctxDelegate)
{
	if (!ctxDelegate) { 
		return; 
	}
	//CGContextDelegateRelease(ctxDelegate->delegates);
}

void delegate_finalize(CFTypeRef c)
{
	CGContextDelegateRef cdt = (CGContextDelegateRef) (c);
}

CGContextDelegateRef CGContextDelegateRetain(CGContextDelegateRef ctxDelegate)
{
	if (!ctxDelegate) { return NULL; }
	CFRetain((CFTypeRef)ctxDelegate);

	return ctxDelegate;
}

void CGContextDelegateRelease(CGContextDelegateRef ctxDelegate)
{
	if (!ctxDelegate) { return; }
	CFRelease((CFTypeRef)ctxDelegate);
}


CGContextDelegateInfoRef CGContextDelegateGetInfo(CGContextDelegateRef ctxDelegate)
{
	if (!ctxDelegate) { return NULL; }
	return ctxDelegate->info;
}


void CGContextDelegateSetCallbacks(CGContextDelegateRef ctxDelegate, const CGCallback* dlArray, int count)
{
	int i;
	if (!ctxDelegate) { return; }
	
	for (i = 0; i < count; i++) {
		CGContextDelegateSetCallback(ctxDelegate, dlArray[i].type, dlArray[i].delegateAddr);
	}

}


void CGContextDelegateSetCallback(CGContextDelegateRef ctxDelegate, CGContextDelegateType type, void* callback)
{
	CGFunctionPtr* addr;

	if (!ctxDelegate)
		return;
	
	addr = get_callback_address(ctxDelegate, type, "CGContextDelegateSetCallback");
	if (addr) {
		*addr = (CGFunctionPtr) callback;
	}
}


CGFunctionPtr* get_callback_address(CGContextDelegateRef ctxDelegate, CGContextDelegateType type, const char* callerName)
{
	switch(type) {

		case kCGContextDelegateFinalize:			{ return (CGFunctionPtr*)&ctxDelegate->finalize;  }
		case kCGContextDelegateGetColorTransform:	{ return (CGFunctionPtr*)&ctxDelegate->getColorTransform; }
		case kCGContextDelegateGetBounds:			{ return (CGFunctionPtr*)&ctxDelegate->getBounds; }
		case kCGContextDelegateDrawLines:			{ return (CGFunctionPtr*)&ctxDelegate->drawLines; }
		case kCGContextDelegateDrawRects:			{ return (CGFunctionPtr*)&ctxDelegate->drawRects; }
		case kCGContextDelegateDrawPath:			{ return (CGFunctionPtr*)&ctxDelegate->drawPath; }
		case kCGContextDelegateDrawImage:			{ return (CGFunctionPtr*)&ctxDelegate->drawImage; }
		case kCGContextDelegateDrawGlyphs:			{ return (CGFunctionPtr*)&ctxDelegate->drawGlyphs; }
		case kCGContextDelegateDrawShading:			{ return (CGFunctionPtr*)&ctxDelegate->drawShading; }
		case kCGContextDelegateDrawDisplayList:		{ return (CGFunctionPtr*)&ctxDelegate->drawDisplayList; }
		case kCGContextDelegateDrawImages:			{ return (CGFunctionPtr*)&ctxDelegate->drawImages; }
		case kCGContextDelegateBeginPage:			{ return (CGFunctionPtr*)&ctxDelegate->beginPage; }
		case kCGContextDelegateEndPage:				{ return (CGFunctionPtr*)&ctxDelegate->endPage; }
		case kCGContextDelegateOperation:			{ return (CGFunctionPtr*)&ctxDelegate->operation; }
		case kCGContextDelegateDrawWindowContents:	{ return (CGFunctionPtr*)&ctxDelegate->drawWindowContents; }
		case kCGContextDelegateDirtyWindowContents:	{ return (CGFunctionPtr*)&ctxDelegate->dirtyWindowContents; }
		case kCGContextDelegateBeginLayer:			{ return (CGFunctionPtr*)&ctxDelegate->beginLayer; }
		case kCGContextDelegateEndLayer:			{ return (CGFunctionPtr*)&ctxDelegate->endLayer; }
		case kCGContextDelegateGetLayer:			{ return (CGFunctionPtr*)&ctxDelegate->getLayer; }
		case kCGContextDelegateDrawLayer:			{ return (CGFunctionPtr*)&ctxDelegate->drawLayer; }
		default:    {
				CGPostError("%s: Unsupported delegate callback: %d.", callerName, (int)type);
				abort();
			}
	};

	return NULL;
}


CGError CGContextDelegateDrawLines(CGContextDelegateRef ctxDelegate,
								   CGRenderingStateRef rendering,
								   CGGStateRef state,
								   const CGPoint points[], size_t count)
{
	if (ctxDelegate == NULL)
		return kCGErrorSuccess;
	if (ctxDelegate->drawLines == NULL)
		return kCGErrorNotImplemented;

	return ctxDelegate->drawLines(ctxDelegate, rendering, state, points, count);
}


CGError CGContextDelegateDrawPath(CGContextDelegateRef ctxDelegate, 
								  CGRenderingStateRef rendering, 
								  CGGStateRef state,
								  CGPathDrawingMode mode,
								  CGMutablePathRef path)
{
	if (ctxDelegate == NULL)
		return kCGErrorSuccess;
	if (ctxDelegate->drawPath == NULL)
		return kCGErrorNotImplemented;

	return ctxDelegate->drawPath(ctxDelegate, rendering, state, mode, path);
}


CGError CGContextDelegateDrawImage(CGContextDelegateRef ctxDelegate, 
								  CGRenderingStateRef rendering,
								  CGGStateRef state,
								  CGRect rect,
								  CGImageRef image)
{
	if (ctxDelegate == NULL)
		return kCGErrorSuccess;
	if (ctxDelegate->drawImage == NULL)
		return kCGErrorNotImplemented;

	return ctxDelegate->drawImage(ctxDelegate, rendering, state, rect, image);
}


CGError 
CGContextDelegateOperation(CGContextDelegateRef ctxDelegate,
						   CGRenderingStateRef rendering,
						   CGGStateRef state,
						   CFStringRef op,
						   void* tmp)
{
	if (ctxDelegate == NULL)
		return kCGErrorSuccess;
	if (ctxDelegate->operation == NULL)
		return kCGErrorNotImplemented;

	return ctxDelegate->operation(ctxDelegate, rendering, state, op, tmp);
}