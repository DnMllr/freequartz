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
#ifndef CGCONTEXTPRIV_H_
#define CGCONTEXTPRIV_H_

#include <CoreFoundation/CFRuntime.h>
#include "CGTypesPriv.h"
#include "CGContextDelegatePriv.h"
#include "CGPathPriv.h"
#include "CGGStatePriv.h"
#include "CGColorSpacePriv.h"
#include "CGRenderingStatePriv.h"

CF_EXTERN_C_BEGIN

CG_EXTERN const CFStringRef kCGContextFilterInfo;
CG_EXTERN const CFStringRef kCGContextErase;	   
CG_EXTERN const CFStringRef kCGContextClear; 
CG_EXTERN const CFStringRef kCGContextWait;		   
CG_EXTERN const CFStringRef kCGContextSynchronize;
CG_EXTERN const CFStringRef kCGContextFlush;

#if 0
typedef struct _ContextEGL {
	EGLDisplay eglDisplay;
	EGLSurface eglSurface;
} ContextEGL, *ContextEGLRef;


typedef struct _ContextOpenVG {
	VGPath path;
	VGPaint paintFill;
	float rgbaFill[4];
	VGPaint paintStroke;
	float rgbaStroke[4];

	VGImageFormat vgImgFmt;
	VGImage vgImg;

} ContextOpenVG, *ContextOpenVGRef;
#endif



//// Thanks to cairo
//typedef enum {
//
//	kPrivateCGCompositeSourceOver = 0,
//	kPrivateCGCompositeSourceIn,
//	kPrivateCGCompositeSourceOut,
//	kPrivateCGCompositeSourceAtop,
//	kPrivateCGCompositeCopy,
//	kPrivateCGCompositeDestinationOver,
//	kPrivateCGCompositeDestinationIn,
//	kPrivateCGCompositeDestinationOut,
//	kPrivateCGCompositeDestinationAtop,
//	kPrivateCGCompositeXOR, 
//	kPrivateCGCompositeXOR,
//	kPrivateCGCompositePlusLighter,
//	kPrivateCGCompositePlusDarker,
//
//} kCGCompositeOperation;

typedef enum {
	
	kSolidPattern,
	kLinearGradientPattern,
	kRadialGradientPattern,
	kTexturePattern,
	/* TODO : handle dashed, dotted, ... */

} KBrushStyle;

typedef enum {
	kCGContextGeneric = 0,
	kCGContextPDF = 1,
	kCGContextBitmap = 4,
	kCGContextDisplayList = 6
	

} CGContextType;


typedef struct CGBitmapContextInfo {
	
	signed long refcount;						//0x00
	size_t	width;								//0x04
	size_t	height;								//0x08
	void* dataWithAlpha;						//0x0C 
	CGFloat alpha;								//0x10 
	CGColorSpaceRef colorspace;					//0x14
	CGBitmapInfo bitmapInfo;					//0x18
	CGFloat horzRes;							//0x1C 
	CGFloat vertRes;							//0x20 
	void* data;									//0x24
	size_t bitsPerPixel;						//0x28
	size_t bitsPerComponent;					//0x2C
	size_t bytesPerRow;							//0x30
	bool unknown_34;							//0x34 ??
	void* unknown_38;							//0x38 ??
	bool unknown_3C;							//0x3C ??
	bool unknown_40;							//0x40 ??
	bool unknown_44;							//0x44 ??
	bool unknown_48;							//0x48 ??

} CGBitmapContextInfo, *CGBitmapContextInfoRef;

//sizeof(struct CGContext) = 0x5C;
typedef struct CGContext {

	CFRuntimeBase obj;								//0x00

	size_t magic;									//0x08
	CGContextType contextType;						//0x0C
	CGBitmapContextInfoRef bitmapContextInfo;		//0x10
	void* finalize;									//0x14
	CGGStackRef stack;								//0x2C
	CGRenderingStateRef rendering;					//0x30
	CGGStateRef state;								//0x34
	CGAffineTransform ctm;							//0x38
	CGMutablePathRef path;							//0x50
	CGContextDelegateRef ctxDelegate;				//0x54
	Boolean isFlushed;								//0x58

} CGContext, *CGContextRef;




void CGContextCreatePaths(CGContextRef c);

CG_EXTERN CGContextRef CGContextCreate();

CG_EXTERN CGContextRef CGContextCreateWithDelegate(CGContextDelegateRef ctxDelegate, 
												   CGRenderingStateRef renderState,
												   CGGStateRef gState);

CG_EXTERN void CGContextSetDelegate(CGContextRef c, 
									CGContextDelegateRef ctxDelegate);

CG_EXTERN CGContextRef CGContextAddFilter(CGContextRef c, void* unknown1, void* unknown2);

CG_EXTERN void		CGContextDestroy(CFTypeRef c);
CG_EXTERN void		CGContextResetState(CGContextRef c);
CG_EXTERN void		CGContextSetRenderingResolution(CGContextRef c);
CG_EXTERN void		CGContextSetStrokeAdjust(CGContextRef c, CGFloat strokeAdjust);
CG_EXTERN void		CGContextSetBlackGeneration(CGContextRef c, CGFunctionRef blackGeneration);
CG_EXTERN void		CGContextSetUndercolorRemoval(CGContextRef c, CGFunctionRef underColorRemoval);


CF_EXTERN_C_END

#endif /* CGCONTEXTPRIV_H_ */


