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
//#include <mach/mach_time.h>

#include <CoreGraphics/CoreGraphicsPrivate.h>
#include <stdint.h>
#include "RIPContext.h"
#include "RIPLayer.h"
#include "RIPDevice.h"


#if 0
CGCallback _RIPCallbacks[] =
{
	{	kCGContextDelegateFinalize,				ripc_Finalize			},
	{	kCGContextDelegateGetColorTransform,	ripc_GetColorTransform	},
	{	kCGContextDelegateGetBounds,			ripc_GetBounds			},		
	{	kCGContextDelegateDrawLines,			ripc_DrawLines			},		
	{	kCGContextDelegateDrawRects,			ripc_DrawRects			},		
	{	kCGContextDelegateDrawPath,				ripc_DrawPath			},		
	{	kCGContextDelegateDrawImage,			ripc_DrawImage			},		
	{	kCGContextDelegateDrawImages,			ripc_DrawImages			},
	{	kCGContextDelegateDrawGlyphs,			ripc_DrawGlyphs			},		
	{	kCGContextDelegateDrawShading,			ripc_DrawShading		},
	{	kCGContextDelegateOperation,			ripc_Operation			},
	{	kCGContextDelegateDrawWindowContents,	ripc_DrawWindowContents	},
	{	kCGContextDelegateDirtyWindowContents,	ripc_DirtyWindowContents},		
	{	kCGContextDelegateBeginLayer,			ripc_BeginLayer			},		
	{	kCGContextDelegateEndLayer,				ripc_EndLayer			},		
	{	kCGContextDelegateGetLayer,				ripc_GetLayer			},		
	{	kCGContextDelegateDrawLayer,			ripc_DrawLayer			},		
															
};
#endif

CGContextDelegateRef 
_CGWindowContextDelegateCreate(CGBitmapContextInfoRef bitmapContextInfo, 
								CFDictionaryRef theDict)
{
	RIPContextRef ripc; 
	RIPDeviceRef ripd;
	CGColorSpaceRef colorSpace;

	ripc = ripc_Initialize();
	if ( !ripc )
	{
		CGPostError("Failed to create window context delegate");
		goto Exit;
	}
	ripd = RIPDeviceCreate(bitmapContextInfo->refcount, bitmapContextInfo->width, bitmapContextInfo->height, 0, 0);
	ripc->ripd = ripd;
	if (!ripd )
	{
		CGPostError("Failed to create window context device");
		goto Release_Exit;
	}
	//
	// TODO RIPDeviceGetResolution(ripd)
	//   
	colorSpace = RIPDeviceGetColorSpace(ripc->ripd);
	if ( !colorSpace )
	{
		CGPostError("Failed to create window context color space");
		goto Release_Exit;
	}

	ripc->colorTransform = CGColorTransformCreate(colorSpace, theDict);
	if (!ripc->colorTransform )
	{
		CGPostError("Failed to create window context color transform");
		goto Release_Exit;
	}

Release_Exit:
	CGContextDelegateRelease(ripc->ctxDelegate);
	ripc->ctxDelegate = NULL;

Exit:
	return ripc->ctxDelegate;
}


CGContextDelegateRef 
_CGBitmapContextDelegateCreate(CGBitmapContextInfoRef bitmapContextInfo, 
								CFDictionaryRef theDict)
{
	CGContextDelegateRef ctxDelegate = NULL;
	uint32_t format, depth;
	size_t numOfComponents;
	RIPContextRef ripc;

	format = ripc_InitializeFormat(bitmapContextInfo);
	depth = RIPLayerDepthForFormat(format);
	
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

uint32_t 
ripc_InitializeFormat(CGBitmapContextInfoRef bitmapContextInfo)
{
	size_t numOfComponents;

	numOfComponents = CGColorSpaceGetNumberOfComponents(bitmapContextInfo->colorspace);

	//if (bitmapContextInfo->bitmapInfo & kCGBitmapByteOrderMask)

	return ((uint32_t)-1);
}



bool ripc_GetRenderingState(CGContextDelegateInfoRef info, CGRenderingStateRef rendering, CGGStateRef state)
{
	return NULL;
}

CGError ripc_DrawPath(CGContextDelegateRef ctxDelegate, 
					  CGRenderingStateRef rendering,
					  CGGStateRef state,
					  CGPathDrawingMode mode,
					  CGMutablePathRef path)
{
	CGError error;
	CGContextDelegateInfoRef info = CGContextDelegateGetInfo(ctxDelegate);
	CGFloat flatness;
	int tmp;

	switch(mode)
	{
	case kCGTextFill:		{ tmp = 2; break; }
	case kCGTextStroke:		{ tmp = 4; break; }
	case kCGTextFillStroke: { tmp = 1; break; }
	case kCGTextInvisible:	{ tmp = 3; break; }
	case kCGTextFillClip:	{ tmp = 5; break; }
	default:				{ error = kCGErrorFailure; break; }
	}

	if (ripc_GetRenderingState(info, rendering, state))
	{
		flatness = CGGStateGetFlatness(state);

	}

	return error;
}


CGError ripc_DrawLines(CGContextDelegateRef ctxDelegate, 
					   CGRenderingStateRef rendering, 
					   CGGStateRef state,
					   const CGPoint points[],
					   size_t count)
{
	CGError error;

	return error;
}

void ripc_GetRenderStroke(CGGStateRef state)
{

}



RIPContextRef 
ripc_Initialize()
{
	//CGContextDelegateSetCallbacks(*(_DWORD *)(v3 + 8), &callbacks_81802, 18);
	return NULL;
}


CGError
ripc_DrawWindowContents()
{
	return kCGErrorFailure;
}

 //// get the timebase info -- different on phone and OSX
 //   mach_timebase_info_data_t info;
 //   mach_timebase_info(&info);

 //   // get the time
 //   uint64_t absTime = mach_absolute_time();

 //   // apply the timebase info
 //   absTime *= info.numer;
 //   absTime /= info.denom;

 //   // convert nanoseconds into seconds and return
 //   return (NSTimeInterval) ((double) absTime / 1000000000.0);
double ripc_Timestamp(RIPContextRef ripc)
{
	/*mach_timebase_info_data_t info;
	uint64_t absTime;

	if (ripc->info.denom == 0)
	{
		 if (mach_timebase_info(&info))
			 abort();

	}
	absTime = mach_absolute_time();
	absTime *= info.numer;
	absTime /= info.denom;

	 return (double) ((double) absTime / 1000000000.0);*/
	return 0;
}





#if 0
//http://crisscross.googlecode.com/svn/trunk/source/system.cpp
static double             timeShift = 0.0;
double GetHighResTime_MacOS()
{
	double retval;
	uint64_t      elapsed = mach_absolute_time() - __m_start;
	retval = double( elapsed ) * (__m_timebase.numer / __m_timebase.denom) / 1000000000.0;
	return retval - timeShift;
}

uint32_t ripc_Timeshift(RIPGlobal + 0x1C)
{
	uint32_t result;
	signed int v2; 
	uint64_t v3; 
	mach_timebase_info_data_t info;

	if ( mach_timebase_info(&info) )
		abort();

	v3 = 10000000 * (uint64_t)info.denom / info.numer;
	v2 = 31;
	result = 0;
	do
	{
		if ( (1 << v2) & v3 )
		{
			result = v2;
			if ( 2 * (1 << v2) - v3 < (unsigned int)(v3 - (1 << v2)) )
				result = v2 + 1;
		}
		--v2;
	}
	while ( v2 && !result );
	if ( !result )
		result = 1;
	*(_DWORD *)(ctxDelegate + 28) = result;

	return result;
}
#endif


CGError ripc_Operation(CGContextDelegateRef ctxDelegate,
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

CGError ripc_DrawImage(CGContextDelegateRef ctxDelegate, 
					   CGRenderingStateRef rendering,
					   CGGStateRef state,
					   CGRect rect,
					   CGImage image)
{
	return kCGErrorNotImplemented;
}

//CGRect
//ripc_GetBounds(CGRect *bounds, CGContextDelegateRef ctxDelegate)
//{
//	CGContextDelegateInfoRef delegateInfo;
//
//	delegateInfo = CGContextDelegateGetInfo(ctxDelegate);
//	if (delegateInfo->ctxDelegate->getBounds == NULL) {
//		return CGRectNull;
//	}
//  return delegateInfo->ctxDelegate->getBounds(bounds);
//}