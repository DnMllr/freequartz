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
#include "CGDisplayListPriv.h"



CGCallback _kCGCallbacks[] =
{
	{	kCGContextDelegateFinalize,			dlr_Finalize		},		//_kCGCallbacks[0]	//0x10
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
	CGContextDelegateRef ctxDelegate;
	void* dlr;

	if (!dummy || (!(dlr = dlr_create(dummy))) ) {
		CGPostError("Unable to create display list recorder");
		return NULL;
	}
	
	ctxDelegate = CGContextDelegateCreate(dlr);
	if (ctxDelegate == NULL) {
		dlr_destroy(dlr);
		CGPostError("Unable to create display list recorder delegate");
		return NULL;
	}

	dlr_InitializeDelegateCallbacks(ctxDelegate);

	return ctxDelegate;
}

CGDisplayListDataRef dlr_create(void* zobby)
{
	return NULL;
}

void dlr_destroy(void* dlr)
{
	if (!dlr)
		return;


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


void dle_ExecuteDisplayList(CGContextDelegateRef ctxDelegate, 
							CGRenderingStateRef rendering, 
							CGGStackRef stack)
{
	//CGGStackGetGState
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