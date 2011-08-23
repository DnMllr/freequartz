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

//#include <libkern/OSAtomic.h>
#include "libCGRD2D.h"




static RIPRef _ripc_globals = 0;
static int32_t _ripc_globals_lock = 0;

#if 0
CGCallback _CGRD2DCallbacks[] =
{
	{	kCGContextDelegateFinalize,				d2d_Finalize				},
	{	kCGContextDelegateGetColorTransform,	d2d_GetColorTransform		},
	{	kCGContextDelegateGetBounds,			d2d_GetBounds				},		
	{	kCGContextDelegateDrawLines,			d2d_DrawLines				},		
	{	kCGContextDelegateDrawRects,			d2d_DrawRects				},		
	{	kCGContextDelegateDrawPath,				d2d_DrawPath				},		
	{	kCGContextDelegateDrawImage,			d2d_DrawImage				},		
	{	kCGContextDelegateDrawImages,			d2d_DrawImages				},
	{	kCGContextDelegateDrawGlyphs,			d2d_DrawGlyphs				},		
	{	kCGContextDelegateDrawShading,			d2d_DrawShading				},
	{	kCGContextDelegateOperation,			d2d_Operation				},
	{	kCGContextDelegateDrawWindowContents,	d2d_DrawWindowContents		},
	{	kCGContextDelegateDirtyWindowContents,	d2d_DirtyWindowContents		},		
	{	kCGContextDelegateBeginLayer,			d2d_BeginLayer				},		
	{	kCGContextDelegateEndLayer,				d2d_EndLayer				},		
	{	kCGContextDelegateGetLayer,				d2d_GetLayer				},		
	{	kCGContextDelegateDrawLayer,			d2d_DrawLayer				},		
															
};
#endif

CGCallback _CGRD2DCallbacks[] =
{		
	{	kCGContextDelegateOperation,			d2d_Operation				},
};


RIPRef RIPGlobalState()
{
	RIPRef rip;

	if (_ripc_globals == NULL)
	{
		//OSSpinLockLock(&_ripc_globals_lock);
		_ripc_globals = (RIPRef)malloc(sizeof(RIP));
	}

	return _ripc_globals;
}


CGContextDelegateRef 
__CGBitmapContextDelegateCreate(CGBitmapContextInfoRef bitmapContextInfo, 
								CFDictionaryRef theDict)
{
	uint32_t format, depth;
	size_t numOfComponents;

	format = d2d_InitializeFormat(bitmapContextInfo);
	depth = D2DLayerDepthForFormat(format);
	
	if (format == -1 || depth == 0) {
		numOfComponents = CGColorSpaceGetNumberOfComponents(bitmapContextInfo->colorspace);
		CGPostError("Unsupported pixel description - %lu components, %lu bits-per-com",
			numOfComponents, bitmapContextInfo->bitsPerComponent);
		return NULL;
	}

	d2d_Initialize(NULL);

	return _ripc_globals->ctxDelegate;
}

int CGBlt_depth(const char *encoding)
{
	return 16;
}

bool D2DLayerInitialize()
{
	return TRUE;
}

int D2DLayerDepthForFormat(int index)
{
	int depth = 0; 
	int g_depth = 0;

	
	return depth;
}


uint32_t 
d2d_InitializeFormat(CGBitmapContextInfoRef bitmapContextInfo)
{
	size_t numOfComponents;

	numOfComponents = CGColorSpaceGetNumberOfComponents(bitmapContextInfo->colorspace);

	//if (bitmapContextInfo->bitmapInfo & kCGBitmapByteOrderMask)

	return ((uint32_t)0);
}

RIPRef 
d2d_Initialize(RIPRef arip)
{
	RIPRef rip;
	
	rip = RIPGlobalState();

	rip->ctxDelegate = CGContextDelegateCreate(NULL/*FIXME*/);
	if (rip->ctxDelegate == NULL) 
	{

	}
	else 
	{
		CGContextDelegateSetCallbacks(rip->ctxDelegate, _CGRD2DCallbacks, sizeof(_CGRD2DCallbacks)/sizeof(_CGRD2DCallbacks[0]));
	}

	return rip;
}








CGError d2d_DrawImage(CGContextDelegateRef ctxDelegate, 
					   CGRenderingStateRef rendering,
					   CGGStateRef state,
					   CGRect rect,
					   CGImage image)
{
	return kCGErrorNotImplemented;
}


CGError d2d_Operation(CGContextDelegateRef ctxDelegate,
					   CGRenderingStateRef rendering,
					   CGGStateRef state,
					   CFStringRef op,
					   void* tmp)

{
	CGContextDelegateInfoRef delegateInfo;

	delegateInfo = CGContextDelegateGetInfo(ctxDelegate);
	if ( tmp != NULL)
		return kCGErrorNotImplemented;


	return kCGErrorNotImplemented; 
}