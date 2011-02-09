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
//#include <mach/mach_time.h>
#include "libOGLES.h"



#if 0
CGCallback _OGLESCallbacks[] =
{
	{	kCGContextDelegateFinalize,				ogles_Finalize				},
	{	kCGContextDelegateGetColorTransform,	ogles_GetColorTransform		},
	{	kCGContextDelegateGetBounds,			ogles_GetBounds				},		
	{	kCGContextDelegateDrawLines,			ogles_DrawLines				},		
	{	kCGContextDelegateDrawRects,			ogles_DrawRects				},		
	{	kCGContextDelegateDrawPath,				ogles_DrawPath				},		
	{	kCGContextDelegateDrawImage,			ogles_DrawImage				},		
	{	kCGContextDelegateDrawImages,			ogles_DrawImages			},
	{	kCGContextDelegateDrawGlyphs,			ogles_DrawGlyphs			},		
	{	kCGContextDelegateDrawShading,			ogles_DrawShading			},
	{	kCGContextDelegateOperation,			ogles_Operation				},
	{	kCGContextDelegateDrawWindowContents,	ogles_DrawWindowContents	},
	{	kCGContextDelegateDirtyWindowContents,	ogles_DirtyWindowContents	},		
	{	kCGContextDelegateBeginLayer,			ogles_BeginLayer			},		
	{	kCGContextDelegateEndLayer,				ogles_EndLayer				},		
	{	kCGContextDelegateGetLayer,				ogles_GetLayer				},		
	{	kCGContextDelegateDrawLayer,			ogles_DrawLayer				},		
															
};
#endif




int CGBlt_depth(const char *encoding)
{
	return 0;
}

bool OGLESLayerInitialize()
{
	return TRUE;
}

int OGLESLayerDepthForFormat(int index)
{
	int depth = 0; 
	int g_depth = 0;

	/*depth = 0;
	if ( index <= 23 )
	{
		g_depth = _ripl_globals[index]->unknow18;
		if ( g_depth )
		{
			if ( g_depth != -1 )
				depth = g_depth;
		}
		else
		{
			result = CGBlt_depth( _ripl_encoding[index] );
			if ( depth && *(_DWORD *)(depth + 16) )
			{
				_ripl_globals[index]->unknow18 = depth;
			}
			else
			{
				_ripl_globals[index]->unknow18 = -1;
				depth = 0;
			}
		}
	}*/
	return depth;
}


uint32_t 
ogles_InitializeFormat(CGBitmapContextInfoRef bitmapContextInfo)
{
	size_t numOfComponents;

	numOfComponents = CGColorSpaceGetNumberOfComponents(bitmapContextInfo->colorspace);

	//if (bitmapContextInfo->bitmapInfo & kCGBitmapByteOrderMask)

	return ((uint32_t)-1);
}

OGLESRef 
ogles_Initialize(OGLESRef rip)
{
	CGContextDelegateRef ctxDelegate;

	rip->ctxDelegate = CGContextDelegateCreate(NULL/*FIXME*/);
	if (rip->ctxDelegate == NULL) {

	}
	else {
		//CGContextDelegateSetCallbacks(ctxDelegate, _kCGCallbacks2, sizeof(_kCGCallbacks2)/sizeof(_kCGCallbacks2[0])
	}

	return NULL;
}





CGContextDelegateRef 
__CGBitmapContextDelegateCreate(CGBitmapContextInfoRef bitmapContextInfo, 
								CFDictionaryRef theDict)
{
	CGContextDelegateRef ctxDelegate;
	uint32_t format, depth;
	size_t numOfComponents;
	OGLESRef ogles;

	format = ogles_InitializeFormat(bitmapContextInfo);
	depth = OGLESLayerDepthForFormat(format);
	
	if (format == -1 || depth == 0) {
		numOfComponents = CGColorSpaceGetNumberOfComponents(bitmapContextInfo->colorspace);
		CGPostError("Unsupported pixel description - %lu components, %lu bits-per-com",
			numOfComponents, bitmapContextInfo->bitsPerComponent);
		return NULL;
	}

#if 0
	ripc = ripc_Initialize();
	if (ripc == NULL) {
		CGPostError("Failed to create bitmap context delegate");
		return NULL;
	}

	if (bitmapContextInfo->data == NULL) {
		
		//RIPLayer(ripc);
	}
	else {

	}
#endif


	return ctxDelegate;
}


CGError ogles_DrawImage(CGContextDelegateRef ctxDelegate, 
					   CGRenderingStateRef rendering,
					   CGGStateRef state,
					   CGRect rect,
					   CGImage image)
{
	return kCGErrorNotImplemented;
}


CGError ogles_Operation(CGContextDelegateRef ctxDelegate,
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