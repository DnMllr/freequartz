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
#include "RIPLayer.h"


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