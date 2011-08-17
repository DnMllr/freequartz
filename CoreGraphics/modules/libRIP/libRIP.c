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
#include "libRIP.h"

/*
http://.../DOCUMENTATION/GraphicsImaging/Conceptual/drawingwithquartz2d/dq_context/dq_context.html

-----------------------------------------------------------------------------------------------
CS    |  Pixel format and bitmap information constant                            | Availability
-----------------------------------------------------------------------------------------------
Gray	8 bpp,	 8 bpc,  kCGImageAlphaNone											10.0
Null	8 bpp,	 8 bpc,  kCGImageAlphaOnly											10.3
RGB		16 bpp,	 5 bpc,  kCGImageAlphaNoneSkipFirst									10.0
RGB		32 bpp,  8 bpc,  kCGImageAlphaNoneSkipFirst									10.0
RGB		32 bpp,  8 bpc,  kCGImageAlphaNoneSkipLast									10.0
RGB		32 bpp,  8 bpc,  kCGImageAlphaPremultipliedFirst							10.0
RGB		32 bpp,  8 bpc,  kCGImageAlphaPremultipliedLast								10.0
CMYK	32 bpp,  8 bpc,  kCGImageAlphaNone											10.3
Gray	32 bpp,  32 bpc, kCGImageAlphaNone|kCGBitmapFloatComponents					10.4
RGB		128 bpp, 32 bpc, kCGImageAlphaNoneSkipLast |kCGBitmapFloatComponents		10.4
RGB		128 bpp, 32 bpc, kCGImageAlphaPremultipliedLast |kCGBitmapFloatComponents	10.4
CMYK	128 bpp, 32 bpc, kCGImageAlphaNone |kCGBitmapFloatComponents				10.4
Gray	16 bpp,  16 bpc, kCGImageAlphaNone											10.5
RGB		64 bpp,  16 bpc, kCGImageAlphaPremultipliedLast								10.5
RGB		64 bpp,  16 bpc, kCGImageAlphaNoneSkipLast									10.5
CMYK	64 bpp,  16 bpc, kCGImageAlphaNone											10.5
*/


//NULL
//8
//kCGImageAlphaOnly
//Alpha_8
//AAAAAAAA
//8 bits per pixel alpha only destination. Color data is thrown away. Useful for generating alpha channels and masks
//
//Gray
//8
//kCGImageAlphaNone
//Gray_8
//WWWWWWWW
//8 bits per pixel greyscale channel.
//
//RGB
//5
//kCGImageAlphaNoneSkipFirst
//RGB555
//-RRRRRGGGGGBBBBBB
//16 bits per pixel, 5 bit per RGB component
//
//RGB
//8
//kCGImageAlphaNoneSkipFirst
//XRGB_32
//--------RRRRRRRRGGGGGGGGBBBBBBBB
//32 bits per pixel RGB format where first byte is ignored
//
//RGB
//8
//kCGImageAlphaNoneSkipLast
//RGBX_32
//RRRRRRRRGGGGGGGGBBBBBBBB--------
//32 bits per pixel RGB format where last byte is skipped
//
//RGB
//8
//kCGImageAlphaPremultipliedFirst
//ARGB_32
//AAAAAAAARRRRRRRRRGGGGGGGGBBBBBBBB
//32 bits per pixel ARGB format with premultiplied alpha
//
//RGB
//8
//kCGImageAlphaPremultipliedLast
//RGBA_32
//RRRRRRRRGGGGGGGGBBBBBBBBAAAAAAAA
//32 bits per pixel RGBA format with premultiplied alpha
//
//CMYK
//8
//kCGImageAlphaNone
//CMYK_32
//CCCCCCCCMMMMMMMMYYYYYYYYKKKKKKKK
//32 bits per pixel CMYK format without alpha

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

/*
http://developer.apple.com/mac/library/qa/qa2001/qa1037.html
//0x17(23) encodings
TODO : CHECK comment below with help of tab above
*/
static const char* _ripl_encoding[] = {

	"AAAAAAAA",							//kCGImageAlphaOnly Alpha_8							
	"WWWWWWWW",							//kCGImageAlphaNone Gray_8							
	"PPPPPPPP",
	"-RRRRRGGGGGBBBBB",					//kCGImageAlphaNoneSkipFirst RGB555
	"-rrrrrgggggbbbbb",					//kCGImageAlphaNoneSkipFirst RGB555
	"--------RRRRRRRRGGGGGGGGBBBBBBBB", //kCGImageAlphaNoneSkipFirst XRGB_32
	"--------rrrrrrrrggggggggbbbbbbbb", //kCGImageAlphaNoneSkipFirst XRGB_32
	"RRRRRRRRGGGGGGGGBBBBBBBB--------", //kCGImageAlphaNoneSkipLast RGBX_32
	"rrrrrrrrggggggggbbbbbbbb--------", //kCGImageAlphaNoneSkipLast RGBX_32 
	"CCCCCCCCMMMMMMMMYYYYYYYYKKKKKKKK", //kCGImageAlphaNone CMYK_32
	"ccccccccmmmmmmmmyyyyyyyykkkkkkkk", //kCGImageAlphaNone CMYK_32
	"WWWWWWWWWWWWWWWW",					//kCGImageAlphaNone Alpha_16
	"wwwwwwwwwwwwwwww",					//kCGImageAlphaNone Alpha_16
	"RRRRRRRRRRRRRRRRGGGGGGGGGGGGGGGGBBBBBBBBBBBBBBBB----------------", //kCGImageAlphaNoneSkipLast RGBX_64
	"rrrrrrrrrrrrrrrrggggggggggggggggbbbbbbbbbbbbbbbb----------------", //kCGImageAlphaNoneSkipLast RGBX_64
	"CCCCCCCCCCCCCCCCMMMMMMMMMMMMMMMMYYYYYYYYYYYYYYYYKKKKKKKKKKKKKKKK", //kCGImageAlphaNone CMYK_64
	"ccccccccccccccccmmmmmmmmmmmmmmmmyyyyyyyyyyyyyyyykkkkkkkkkkkkkkkk", //kCGImageAlphaNone CMYK_64
	"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW", //kCGImageAlphaNone Gray_32
	"wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww", //kCGImageAlphaNone Gray_32
	"RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB--------------------------------", //kCGImageAlphaNoneSkipLast RGBX_128
	"rrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrggggggggggggggggggggggggggggggggbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb--------------------------------", //kCGImageAlphaNoneSkipLast RGBX_128
	"CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKK", //kCGImageAlphaNone CMYK_128
	"ccccccccccccccccccccccccccccccccmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyykkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk", //kCGImageAlphaNone CMYK_128
	NULL
};


int CGBlt_depth(const char *encoding)
{
	return 0;
}

bool RIPLayerInitialize()
{
	return TRUE;
}

int RIPLayerDepthForFormat(int index)
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
ripc_InitializeFormat(CGBitmapContextInfoRef bitmapContextInfo)
{
	size_t numOfComponents;

	numOfComponents = CGColorSpaceGetNumberOfComponents(bitmapContextInfo->colorspace);

	//if (bitmapContextInfo->bitmapInfo & kCGBitmapByteOrderMask)

	return ((uint32_t)-1);
}

RIPRef 
ripc_Initialize(RIPRef rip)
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


CGError
ripc_DrawWindowContents()
{
	return kCGErrorFailure;
}

void *
RIPZoneDataBarrier(void *memory)
{
	return memory;
}

bool
RIPZoneDataSeed()
{
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


CGContextDelegateRef 
__CGBitmapContextDelegateCreate(CGBitmapContextInfoRef bitmapContextInfo, 
								CFDictionaryRef theDict)
{
	CGContextDelegateRef ctxDelegate;
	uint32_t format, depth;
	size_t numOfComponents;
	RIPRef ripc;

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


CGError ripc_DrawImage(CGContextDelegateRef ctxDelegate, 
					   CGRenderingStateRef rendering,
					   CGGStateRef state,
					   CGRect rect,
					   CGImage image)
{
	return kCGErrorNotImplemented;
}


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