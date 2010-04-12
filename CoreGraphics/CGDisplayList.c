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
#include "CGDisplayListPriv.h"



CGCallback _kCGCallbacks[] =
{
	{	kCGContextDelegateFinalize,			dlr_Finalize		},		//_kCGCallbacks[0]	//0x10 = GetColorTransform
	{	kCGContextDelegateGetBounds,		dlr_GetBounds		},		//_kCGCallbacks[1]	//0x14
	{	kCGContextDelegateDrawLines,		dlr_DrawLines		},		//_kCGCallbacks[2]	//0x18
	{	kCGContextDelegateDrawRects,		dlr_DrawRects		},		//_kCGCallbacks[3]	//0x1C
	{	kCGContextDelegateDrawPath,			dlr_DrawPath		},		//_kCGCallbacks[4]	//0x20
	{	kCGContextDelegateDrawImage,		dlr_DrawImage		},		//_kCGCallbacks[5]	//0x24
	{	kCGContextDelegateDrawGlyphs,		dlr_DrawGlyphs		},		//_kCGCallbacks[6]	//0x28
	{	kCGContextDelegateDrawShading,		dlr_DrawShading		},		//_kCGCallbacks[7]	//0x2C
	{	kCGContextDelegateDrawDisplayList,	dlr_DrawDisplayList	},		//_kCGCallbacks[8]	//0x30
	{	kCGContextDelegateBeginPage,		dlr_BeginPage		},		//_kCGCallbacks[9]	//0x38
	{	kCGContextDelegateEndPage,			dlr_EndPage			},		//_kCGCallbacks[10]	//0x3C
	{	kCGContextDelegateOperation,		dlr_Operation		},		//_kCGCallbacks[11]	//0x40
	{	kCGContextDelegateBeginLayer,		dlr_BeginLayer		},		//_kCGCallbacks[12] //0x4C
	{	kCGContextDelegateEndLayer,			dlr_EndLayer		},		//_kCGCallbacks[13] //0x50
	{	kCGContextDelegateGetLayer,			dlr_GetLayer		},		//_kCGCallbacks[14]	//0x54
	{	kCGContextDelegateDrawLayer,		dlr_DrawLayer		},		//_kCGCallbacks[15]	//0x58
															
};

static CFRuntimeClass CGDisplayListClass = 
  {
    0,							// version
    "CGDisplayList",			// className
    0,							// init
    0,							// copy
    dl_Finalize,				// finalize
	0,							// equal
	0,							// hash
	0,							// copyFormattingDesc
	0							// copyDebugDesc
  };
CFTypeID __kCGDisplayListID = _kCFRuntimeNotATypeID;


CFTypeID CGDisplayListGetTypeID(void)
{
	return CGTypeRegisterWithCallbacks(&__kCGDisplayListID, &CGDisplayListClass);
}

void dl_Finalize(CFTypeRef cf)
{

}

CGContextRef CGDisplayListContextCreate(void* dummy)
{
	CGContextRef ctx;

	ctx = CGContextCreate();
	if (!ctx) {
		CGPostError("Unable to create display list context");
		return NULL;
	}
	
	ctx->ctxDelegate = CGDisplayListContextDelegateCreate(dummy);
	if (!ctx->ctxDelegate) {
		CGContextRelease(ctx);
		CGPostError("Unable to create display list context delegate");
		return NULL;
	}

	ctx->contextType = kCGContextTypeDisplayList;

	return ctx;
}

CGContextDelegateRef CGDisplayListContextDelegateCreate(void* dummy)
{
	return NULL;
}

CGDisplayListDataRef dlr_create(void* zobby)
{
	return NULL;
}


void dlr_InitializeDelegateCallbacks(CGContextDelegateRef ctxDelegate)
{
	CGContextDelegateSetCallbacks(ctxDelegate, _kCGCallbacks, sizeof(_kCGCallbacks)/sizeof(_kCGCallbacks[0]));
}

void dlr_Finalize(CGContextDelegateRef ctxDelegate)
{

}

CGRect dlr_GetBounds(CGContextDelegateRef ctxDelegate)
{
	return CGRectNull;
}

void dlr_DrawLines(CGContextDelegateRef ctxDelegate)
{
}

void dlr_DrawRects(CGContextDelegateRef ctxDelegate)
{
}
void dlr_DrawPath(CGContextDelegateRef ctxDelegate)
{
}
void dlr_DrawImage(CGContextDelegateRef ctxDelegate)
{
}
void dlr_DrawGlyphs(CGContextDelegateRef ctxDelegate)
{
}
void dlr_DrawShading(CGContextDelegateRef ctxDelegate)
{
}
void dlr_DrawDisplayList(CGContextDelegateRef ctxDelegate)
{
}
void dlr_BeginPage(CGContextDelegateRef ctxDelegate)
{
}
void dlr_EndPage(CGContextDelegateRef ctxDelegate)
{
}

void dlr_Operation(CGContextDelegateRef ctxDelegate)
{
}
void dlr_BeginLayer(CGContextDelegateRef ctxDelegate)
{
}
void dlr_EndLayer(CGContextDelegateRef ctxDelegate)
{
}
void dlr_GetLayer(CGContextDelegateRef ctxDelegate)
{
}
void dlr_DrawLayer(CGContextDelegateRef ctxDelegate)
{
}