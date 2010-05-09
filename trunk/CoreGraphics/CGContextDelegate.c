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
#include <CoreGraphics/CGContext.h>

#include "CGBasePriv.h"
#include "CGContextPriv.h"
#include "CGContextDelegatePriv.h"
#include "CGGStatePriv.h"



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
	void* addr;

	if (!ctxDelegate)
		return;
	
	addr = get_callback_address(ctxDelegate, type);
	if (addr) {
		//*addr = callback;
	}
}


void* get_callback_address(CGContextDelegateRef ctxDelegate, CGContextDelegateType type)
{
	if (type > kCGContextDelegateDrawLayer) {
		CGPostError("%s: Unsupported delegate callback: %d.", "CGContextDelegateSetCallback", (int)type);
		return NULL;
	}



	switch(type) {

		case kCGContextDelegateFinalize:			{ return ctxDelegate->finalize;  }
		case kCGContextDelegateGetColorTransform:	{ return ctxDelegate->getColorTransform; }
		case kCGContextDelegateGetBounds:			{ return ctxDelegate->getBounds; }
		case kCGContextDelegateDrawLines:			{ return ctxDelegate->drawLines; }
		case kCGContextDelegateDrawRects:			{ return ctxDelegate->drawRects; }
		case kCGContextDelegateDrawPath:			{ return ctxDelegate->drawPath; }
		case kCGContextDelegateDrawImage:			{ return ctxDelegate->drawImage; }
		case kCGContextDelegateDrawGlyphs:			{ return ctxDelegate->drawGlyphs; }
		case kCGContextDelegateDrawShading:			{ return ctxDelegate->drawShading; }
		case kCGContextDelegateDrawDisplayList:		{ return ctxDelegate->drawDisplayList; }
		case kCGContextDelegateDrawImages:			{ return ctxDelegate->drawImages; }
		case kCGContextDelegateBeginPage:			{ return ctxDelegate->beginPage; }
		case kCGContextDelegateEndPage:				{ return ctxDelegate->endPage; }
		case kCGContextDelegateOperation:			{ return ctxDelegate->operation; }
		case kCGContextDelegateDrawWindowContents:	{ return ctxDelegate->drawWindowContents; }
		case kCGContextDelegateDirtyWindowContents:	{ return ctxDelegate->dirtyWindowContents; }
		case kCGContextDelegateBeginLayer:			{ return ctxDelegate->beginLayer; }
		case kCGContextDelegateEndLayer:			{ return ctxDelegate->endLayer; }
		case kCGContextDelegateGetLayer:			{ return ctxDelegate->getLayer; }
		case kCGContextDelegateDrawLayer:			{ return ctxDelegate->drawLayer; }
		default:    {
				CGPostError("%s: Unsupported delegate callback: %d.", "CGContextDelegateSetCallback");
			}
	};

	return NULL;
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


void 
CGContextDelegateOperation(void* delegate1, void* delegate2, CFStringRef op)
{
	return;
}