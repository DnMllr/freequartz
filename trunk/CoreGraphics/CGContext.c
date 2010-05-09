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
#include "CGGStatePriv.h"


/* PUT THIS INTO COMPAT4MSVC */
#ifndef M_PI
#define M_PI       3.14159265358979323846
#endif

#define DEG_FROM_GRAD(rad)   ((rad)*180.0/M_PI)

#ifdef _WIN32_WCE
double rint(double x)
{

	double      f,
				n = 0.;

	f = modf(x, &n);

	if (x > 0.)
	{
		if (f > .5)
			n += 1.;
	}
	else if (x < 0.)
	{
		if (f < -.5)
			n -= 1.;
	}
	return n;
}
#endif

static CFRuntimeClass CGContextClass = 
  {
    0,							// version
    "CGContext",				// className
    0,							// init
    0,							// copy
    CGContextDestroy,			// finalize
	0,							// equal
	0,							// hash
	0,							// copyFormattingDesc
	0							// copyDebugDesc
  };
CFTypeID __kCGContextID = _kCFRuntimeNotATypeID;


CG_CONST_STRING_DECL(kCGContextDisplayList,					"kCGContextDisplayList");
CG_CONST_STRING_DECL(kCGContextLog,							"kCGContextLog");
CG_CONST_STRING_DECL(kCGContextBackgroundColor,				"kCGContextBackgroundColor");
CG_CONST_STRING_DECL(kCGContextBoundingBox,					"kCGContextBoundingBox");
CG_CONST_STRING_DECL(kCGContextColorSpace,					"kCGContextColorSpace");
CG_CONST_STRING_DECL(kCGContextGroup,						"kCGContextGroup");
CG_CONST_STRING_DECL(kCGContextResolution,					"kCGContextResolution");

CG_CONST_STRING_DECL(kCGContextFilterInfo,					"kCGContextFilterInfo");
CG_CONST_STRING_DECL(kCGContextFilterOptionsData,			"kCGContextFilterOptionsData");
CG_CONST_STRING_DECL(kCGContextFilterOptionsURL,			"kCGContextFilterOptionsURL");
CG_CONST_STRING_DECL(kCGContextFilterOptionsName,			"kCGContextFilterOptionsName");
CG_CONST_STRING_DECL(kCGCFilterPrintingDomain,				"kCGCFilterPrintingDomain");
CG_CONST_STRING_DECL(kCGCFilterApplicationDomain,			"kCGCFilterApplicationDomain");
CG_CONST_STRING_DECL(kCGTransparencyLayerContentBounds,		"kCGTransparencyLayerContentBounds");

CG_CONST_STRING_DECL(kCGContextErase,						"kCGContextErase");
CG_CONST_STRING_DECL(kCGContextClear,						"kCGContextClear");
CG_CONST_STRING_DECL(kCGContextWait,						"kCGContextWait");
CG_CONST_STRING_DECL(kCGContextSynchronize,					"kCGContextSynchronize");
CG_CONST_STRING_DECL(kCGContextFlush,						"kCGContextFlush");



CFTypeID CGContextGetTypeID(void)
{
	return CGTypeRegisterWithCallbacks(&__kCGContextID, &CGContextClass);
}

void CGContextRelease(CGContextRef c)
{
	if (!c) { return; }
	CFRelease((CFTypeRef)c);
}

void CGContextDestroy(CFTypeRef c)
{
	CGContextRef ct = (CGContextRef) (c);

	CGPathRelease(ct->path);
}

void _CGContextResetModes(CGContextRef c)
{
}   

int _InitEGL(CGContextRef c, HWND hWnd)
{
	return 0;
}

CGContextRef CGContextCreate()
{
	return CGContextCreateWithDelegate(0,0,0);
}

CGContextRef CGContextCreateWithDelegate(CGContextDelegateRef ctxDelegate, 
										 CGRenderingStateRef renderState,
										 CGGStateRef gState)
{
	CGContextRef cxtRef;
	CFIndex size;

	/* create context */
	size = sizeof(struct CGContext) - sizeof(CFRuntimeBase);
	cxtRef = (CGContextRef) CGTypeCreateInstance( CGContextGetTypeID(), size );
	if (!cxtRef) { return 0; }

	cxtRef->contextType = kCGContextTypeGeneric;

	/* create rendering context*/
	if (renderState)
		cxtRef->rendering = CGRenderingStateCreateCopy(renderState);
	else
		cxtRef->rendering = CGRenderingStateCreate();

	/* Create a stack to store graphic context */
	if (gState)
		cxtRef->stack = CGGStackCreateWithGState(gState);
	else
		cxtRef->stack = CGGStackCreate();

	if (!cxtRef->rendering || !cxtRef->stack) {
		CGContextRelease(cxtRef);
		return NULL;
	}

	/* Set current graphic state */
	cxtRef->state = CGGStackGetGState(cxtRef->stack);

	cxtRef->ctm = CGAffineTransformIdentity;
	cxtRef->path = NULL;

	/* Set delegate */
	if (ctxDelegate)
		CGContextSetDelegate(cxtRef, ctxDelegate);

	return NULL;
}

CGContextRef CGContextAddFilter(CGContextRef c, void* unknown1, void* unknown2)
{
	//CGContextDelegateRef delegate;

	if (!c) {
		CGPostError("%s: invalid context", "CGContextAddFilter");
		goto Error;
	}

	/*
	if (c->ctxDelegate) {
		delegate = CGContextFilterContextDelegate(c->ctxDelegate);
		CGContextSetDelegate(c, delegate);
		CGContextDelegateRelease(delegate);
	}
	*/

	return c;
Error:
	return NULL;
}

void CGContextSetDelegate(CGContextRef c, CGContextDelegateRef ctxDelegate)
{
	if (!c) { return; }

	if (c->ctxDelegate != ctxDelegate) {
		CGContextDelegateRetain(ctxDelegate);
		CGContextDelegateRelease(c->ctxDelegate);
		c->ctxDelegate = ctxDelegate;
	}
}

void CGContextResetState(CGContextRef c)
{
	if (!c) { return; }

	CGGStackReset(c->stack);
	c->state = CGGStackGetGState(c->stack);
	CGRenderingStateReset(c->rendering);
}


void CGContextSaveGState(CGContextRef c)
{
	if (!c) { return; }

	c->state = CGGStackSave(c->stack);
}


void CGContextRestoreGState(CGContextRef c)
{
	if (!c) { return; }

	c->state = CGGStackRestore(c->stack);
}

__inline
void CGContextScaleCTM(CGContextRef c, CGFloat sx, CGFloat sy)
{
	if (!c) { return; }
	CGAffineTransformScale(CGGStateGetCTM(c->state), sx, sy);
}

__inline
void CGContextTranslateCTM(CGContextRef c, CGFloat tx, CGFloat ty)
{
	CGAffineTransform ctm;

	if (!c) { 
		CGPostError("%s: invalid context", "CGContextTranslateCTM");
		return; 
	}

	ctm = CGAffineTransformTranslate(CGGStateGetCTM(c->state), tx, ty);
	CGGStateSetCTM(c->state, ctm);
}

__inline
void CGContextRotateCTM(CGContextRef c, CGFloat angle)
{
	CGAffineTransform ctm;

	if (!c) { 
		CGPostError("%s: invalid context", "CGContextRotateCTM");
		return; 
	}

	ctm = CGAffineTransformRotate(CGGStateGetCTM(c->state), angle);
	CGGStateSetCTM(c->state, ctm);
}

void CGContextConcatCTM(CGContextRef c, CGAffineTransform transform)
{
	if (!c) { return; }
	
	/* { sx, shy, w0, shx, sy, w1, tx, ty, w2 } */
	
}

CGAffineTransform CGContextGetCTM(CGContextRef c)
{
	if (!c) { return CGAffineTransformIdentity; }

	return CGGStateGetCTM(c->state);
}

void CGContextSetFillColorWithColor(CGContextRef c, CGColorRef color)
{
	if (!c) { return; }

	CGGStateSetFillColor(c->state, color);
}


void CGContextSetLineWidth(CGContextRef c, CGFloat width)
{
	if (!c) {
		return;
	}
	if (width < 0) {
		return;
	}

	CGGStateSetLineWidth(c->state, width);
	
}

void CGContextSetLineCap(CGContextRef c, CGLineCap cap)
{
	if (!c) { 
		return; 
	}
	CGGStateSetLineCap(c->state, (cap <= kCGLineCapSquare) ? cap : kCGLineCapButt);
}

void CGContextSetLineJoin(CGContextRef c, CGLineJoin join)
{

	if (!c) { 
		return; 
	}

	CGGStateSetLineJoin(c->state, (join <= kCGLineJoinBevel) ? join : kCGLineJoinMiter);
}

void CGContextSetMiterLimit(CGContextRef c, CGFloat limit)
{
	if (!c) { return; }

	CGGStateSetMiterLimit(c->state, limit);
}


void CGContextSetLineDash(CGContextRef c, CGFloat phase, const CGFloat lengths[], size_t count)
{
	CGDashRef dash;
	size_t i;

	if (!c || !count || !lengths) { return; }

	// Check lengths are positive
	for ( i = 0; i < count; i++) {
		if (lengths[i] < 0) {
			return;
		}
	}
	
	dash = CGDashCreate(phase, lengths, count);
	CGGStateSetLineDash(c->state, dash);
	CGDashRelease(dash);
}

void CGContextSetFlatness(CGContextRef c, CGFloat flatness)
{
	if (!c) { 
		return; 
	}
	
	CGGStateSetFlatness(c->state, flatness);
}

void CGContextSetFontSize(CGContextRef c, CGFloat size)
{
	CGGStateSetFontSize(c->state, size);
}


void CGContextSetStrokeAdjust(CGContextRef c, CGFloat strokeAdjust)
{
	if (!c) {
		return;
	}

	CGGStateSetStrokeAdjust(c->state, strokeAdjust);
}

void CGContextSetAlpha(CGContextRef c, CGFloat alpha)
{
	if (!c) { return; }

	CGGStateSetAlpha(c->state, alpha);
}

void CGContextSetBlendMode(CGContextRef c, CGBlendMode mode)
{
	if (!c) { return; }
	
	if (mode <= kCGBlendModePlusLighter)
	{
		CGGStateSetCompositeOperation(c->state, (CGCompositeMode)mode);
	}
	
}

void CGContextSetBlackGeneration(CGContextRef c, CGFunctionRef blackGeneration)
{
	if (!c) {
		return;
	}

	CGGStateSetBlackGeneration(c->state, blackGeneration);
}

void CGContextSetUndercolorRemoval(CGContextRef c, CGFunctionRef underColorRemoval)
{
	if (!c) {
		return;
	}

	CGGStateSetUndercolorRemoval(c->state, underColorRemoval);
}

void CGContextFlush(CGContextRef c)
{
	if (!c) { return; }

	if (c->isFlushed == FALSE)
	{
		CGContextDelegateOperation(
			c->ctxDelegate->drawDisplayList,
			c->ctxDelegate->drawImages,
			kCGContextFlush);
	}
}


void CGContextBeginPath(CGContextRef c)
{
	if (!c) { return; }

	if (c->path) { CGPathRelease(c->path); c->path = NULL; }

}

void CGContextAddPath(CGContextRef c, CGPathRef path)
{
	CGAffineTransform ctm;

	if (!c || c->magic != 0x43545854){
		CGPostError("%s: invalid context", "CGContextAddPath");
		return;
	}

	if (c->path == NULL) {
		c->path = CGPathCreateMutable();
	}
	ctm = CGGStateGetCTM(c->state);
	CGPathAddPath( c->path, &ctm, path);
}

void CGContextMoveToPoint(CGContextRef c, CGFloat x, CGFloat y)
{
	CGAffineTransform ctm;

	if (!c) { return; }
	if (!c->path) { c->path = CGPathCreateMutable(); }
	
	ctm = CGGStateGetCTM(c->state);
	CGPathMoveToPoint(c->path, &ctm, x, y);
}

void CGContextAddLineToPoint(CGContextRef c, CGFloat x, CGFloat y)
{
	CGAffineTransform ctm;

	if (!c ) { return; }
	if (CGPathIsEmpty(c->path)) { return; }

	ctm = CGGStateGetCTM(c->state);
	CGPathAddLineToPoint(c->path, &ctm, x, y);
}

void CGContextAddCurveToPoint(CGContextRef c, CGFloat cp1x,
    CGFloat cp1y, CGFloat cp2x, CGFloat cp2y, CGFloat x, CGFloat y)
{
	CGAffineTransform ctm;

	if (!c) { return; }
	if (CGPathIsEmpty(c->path)) { return; }

	ctm = CGGStateGetCTM(c->state);
	CGPathAddCurveToPoint(c->path, &ctm, cp1x, cp1y, cp2x, cp2y, x, y);
}


void CGContextAddQuadCurveToPoint(CGContextRef c, CGFloat cpx, CGFloat cpy, CGFloat x, CGFloat y)
{
	CGAffineTransform ctm;

	if (!c) { return; }
	if (CGPathIsEmpty(c->path)) { return; }

	ctm = CGGStateGetCTM(c->state);
	CGPathAddQuadCurveToPoint(c->path, &ctm, cpx, cpy, x, y);
}


void CGContextClosePath(CGContextRef c)
{
	if (!c || !c->path) { return; }
	
	CGPathCloseSubpath(c->path);
}

void CGContextSetRGBFillColor (CGContextRef c, CGFloat r, CGFloat g, CGFloat b, CGFloat a)
{
	CGColorSpaceRef colorSpace;
	CGColorRef color;
	CGFloat rgba[4];

	if (!c) { return; }
	
	colorSpace = CGColorSpaceCreateDeviceRGB();
	if (!colorSpace) {
		color = CGGStateGetFillColor(c->state);
		colorSpace = CGColorGetColorSpace(color);
		if (!colorSpace) { return; }
		
		rgba[0] = r; 
		rgba[1] = g; 
		rgba[2] = b; 
		rgba[3] = a;
		color = CGColorCreate(colorSpace, rgba);
		CGContextSetFillColorWithColor(c, color);
		CGColorRelease(color);
	}
	else {

	}
	
	/* 
	* http://lists.apple.com/archives/Quartzcomposer-dev/2007/Oct/msg00135.html 
	* CGColorSpaceGetType is defined
	*/
	
	CGColorSpaceRelease(colorSpace);
}


void CGContextFillRects(CGContextRef c, const CGRect rects[], size_t count)
{
	if (!c || !rects || !count) { return; }

	if (c->path) { CGPathRelease(c->path); c->path = NULL; }

	CGContextAddRects(c, rects, count);
	CGContextFillPath(c);
}

void CGContextFillRect(CGContextRef c, CGRect rect)
{
	if (!c) { return; }

	CGContextFillRects(c, &rect, 1);
	return;
}

void CGContextStrokeRect(CGContextRef c, CGRect rect)
{
	if (!c) { return; }

	CGContextAddRect(c, rect);
	CGContextStrokePath(c);
}

void CGContextStrokeRectWithWidth(CGContextRef c, CGRect rect, CGFloat width)
{
	if (!c) { return; }

	CGContextStrokeRect(c, rect);
}


void CGContextFillEllipseInRect(CGContextRef c, CGRect rect)
{

	if (!c) { return; }
	if (c->path) { CGPathRelease(c->path); c->path = 0; }

	CGContextAddEllipseInRect(c, rect);
	CGContextFillPath(c);
}


void CGContextStrokeEllipseInRect(CGContextRef c, CGRect rect)
{

	if (!c) { return; }
	if (c->path) { CGPathRelease(c->path); c->path = 0; }

	CGContextAddEllipseInRect(c, rect);
	CGContextStrokePath(c);
}

void CGContextStrokeLineSegments(CGContextRef c, const CGPoint points[], size_t count)
{
	size_t i;

	if (!c) { return; }

	CGContextBeginPath(c);
     
	for (i = 0; i < count; i += 2) {
       CGContextMoveToPoint(c, points[i].x, points[i].y);
       CGContextAddLineToPoint(c, points[i+1].x, points[i+1].y);
     }
	
	CGContextStrokePath(c);
}

void CGContextAddRect(CGContextRef c, CGRect rect)
{
	if (!c) { return; }

	CGContextAddRects(c, &rect, 1);
}

void CGContextAddRects(CGContextRef c, const CGRect rects[], size_t count)
{
	CGAffineTransform ctm;

	if (!c || !rects || !count) { return; }
	if (!c->path) { c->path = CGPathCreateMutable(); }
	
	ctm = CGGStateGetCTM(c->state);

	CGPathAddRects(c->path, &ctm, rects, count);
}

void CGContextAddEllipseInRect(CGContextRef c, CGRect rect)
{
	CGAffineTransform ctm;

	if (!c) { return; }
	if (!c->path) { c->path = CGPathCreateMutable(); }
	
	ctm = CGGStateGetCTM(c->state);

	CGPathAddEllipseInRect(c->path, &ctm, rect);
}

void CGContextAddLines(CGContextRef c, const CGPoint points[], size_t count)
{
	CGAffineTransform ctm;

	if (!c || !points || !count) { return; }
	
	if (!c->path) { c->path = CGPathCreateMutable(); }
	
	ctm = CGContextGetCTM(c);

	CGPathAddLines(c->path, &ctm, points, count);
}

void CGContextStrokePath(CGContextRef c)
{
	CGContextDrawPath(c, kCGPathStroke);
}

void CGContextFillPath(CGContextRef c)
{
	CGContextDrawPath(c, kCGPathFill);
}



CGPathDrawingMode adjustModeForLineWidth(CGPathDrawingMode mode, CGFloat lineWidth)
{
	return kCGPathFill;
}

void CGContextDrawPath(CGContextRef c, CGPathDrawingMode mode)
{
	CGPathRef path;

	if (!c || c->magic != 0x43545854) { 
		 CGPostError("%s: invalid context", "CGContextDrawPath");
		return; 
	}
	
	if ( c->path )
    {
      if ( CGPathIsEmpty(c->path) == FALSE)
      {
        path = (CGPathRef) c->path;
        c->path = NULL;

		mode = adjustModeForLineWidth(mode, CGGStateGetLineWidth(c->state));
		if (mode != -1 )
			CGContextDelegateDrawPath(c->ctxDelegate, c->rendering, c->state, mode, c->path);
        
		CGPathRelease(path);
	  }
    }
}


void doClip(CGContextRef c, CGPathDrawingMode mode);
void CGContextClip(CGContextRef c)
{
	doClip(c, kCGPathFill);
	
}

void doClip(CGContextRef c, CGPathDrawingMode mode)
{
	if (!c ) {
		return;
	}

	if (CGPathIsEmpty(c->path)) {
		return;
	}

	CGGStateClipToPath(c->state, c->path, mode);
	if (c->path) {  CGPathRelease(c->path);  c->path = NULL; }


}

void CGContextEOClip(CGContextRef c)
{
	doClip(c, kCGPathEOFill);
}

void CGContextDrawImage(CGContextRef c, CGRect rect, CGImageRef image)
{
	//CGImageRef imgTmp; 
	CGPathRef clipPath;

	if (!c || c->magic != 0x43545854){
		CGPostError("%s: invalid context", "CGContextDrawImage");
		return;
	}

	if ( image )
	{
		clipPath = (const struct CGPath *)CGImageGetClipPath(image);
		if ( clipPath )
		{
			CGContextSaveGState(c);
			CGContextSaveGState(c);
			CGContextTranslateCTM(c, rect.origin.x, rect.origin.y);
			CGContextScaleCTM(c, rect.size.width, rect.size.height);
			CGContextBeginPath(c);
			CGContextAddPath(c, clipPath);
			CGContextRestoreGState(c);
			CGContextEOClip(c);
		}
#if 0
		if ( [x86]*((_DWORD *)c + 6); [arm]c->0x18 )
		{
			CGContextSaveGState(c);
			imgTmp = (struct CGImage *)(*((int (__cdecl **)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))c + 6))(
				c,
				(_DWORD)rect.origin.x,
				LODWORD(rect.origin.y),
				LODWORD(rect.size.width),
				LODWORD(rect.size.height),
				image,
				*((_DWORD *)c + 7));

			if ( imgTmp )
			{
				CGContextDelegateDrawImage(c->ctxDelegate, c->rendering, c->state, rect, imgTmp);
				CGImageRelease(imgTmp);
			}
			CGContextRestoreGState(c);
		}
		else
		{
			CGContextDelegateDrawImage(c->ctxDelegate, c->rendering, c->state, rect, image);
		}
#endif
		if ( clipPath )
			CGContextRestoreGState(c);
	}

}

