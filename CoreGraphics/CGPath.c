/****************************************************************************
**
** Copyright (C) 2010 Smartmobili.
** All rights reserved.
** Contact: Smartmobili (contact@smartmobili.com)
**	
** This file is part of the CoreGraphics module of the Coconuts Toolkit.
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
#include <CoreGraphics/CGPath.h>

#include "CGBasePriv.h"
#include "CGPathPriv.h"


/* CoreFoundation runtime class for CGPath.  */
static CFRuntimeClass CGPathClass =  {
    0,							/* version */
    "CGPath",					/* Name of class.  */
    0,							/* init */
    0,							/* copy  */
    CGPathDestroy,				/* finalize  */
	0,							/* equal  */
	0,							/* hash  */
	0,							/* copyFormattingDesc */
	0							/* copyDebugDesc */
  };
static CFTypeID __kCGPathID = _kCFRuntimeNotATypeID;

CFTypeID CGPathGetTypeID(void)
{	
	return CGTypeRegisterWithCallbacks(&__kCGPathID, &CGPathClass );
}

void CGPathDestroy(CFTypeRef ctf)
{
	CGMutablePathRef ct = (CGMutablePathRef) (ctf);
	
}

CGMutablePathRef CGPathCreateMutable(void)
{
	CGMutablePathRef pathref;
	CFIndex size;

	size = sizeof(struct CGPath) - sizeof(CFRuntimeBase);
	pathref = (CGMutablePathRef) CGTypeCreateInstance( CGPathGetTypeID(), size );
	CHK (pathref);

	pathref->bIsEmpty = TRUE;

	return (CGMutablePathRef) pathref;
Cleanup:
	return NULL;
}

CGPathRef CGPathCreateCopy(CGPathRef path)
{
	return ((CGPathRef)CGPathCreateMutableCopy(path));
}


CGMutablePathRef CGPathCreateMutableCopy(CGPathRef path)
{
	CGMutablePathRef pathMutableCopy;
	
	if (!path)
		return NULL;

	pathMutableCopy = CGPathCreateMutable();
	if (!pathMutableCopy) { return NULL; }

	CGPathAddPath(pathMutableCopy, NULL, path);

	return pathMutableCopy;
}

CGPathRef CGPathRetain(CGPathRef path)
{
	if (!path) { return NULL; }
	CFRetain((CFTypeRef)path);

	return path;
}

void CGPathRelease(CGPathRef path)
{
	if (!path) { return; }
	CFRelease((CFTypeRef)path);
}

bool CGPathEqualToPath(CGPathRef path1, CGPathRef path2)
{
	if (path1 == path2)
		return TRUE;
	// TODO

}

CGPathElementsRef add_chunk(CGMutablePathRef path )
{
	CGPathElementsRef chunk;

	chunk = (CGPathElementsRef)malloc(sizeof(CGPathElements));
	if (chunk == NULL)
		return NULL;

	chunk->nextChunk = NULL;
	chunk->count = 0;
	path->lastChunk->nextChunk = chunk;
	path->lastChunk = chunk;
	
	return chunk;
}

void CGPathMoveToPoint(CGMutablePathRef path, const CGAffineTransform *m, CGFloat x, CGFloat y)
{
	CGPoint point;

	if (!path) { return; }

	point  = CGPointMake(x, y);
	 if (m != NULL)
		 point = CGPointApplyAffineTransform(point, *m);
}

void CGPathAddLineToPoint(CGMutablePathRef path, const CGAffineTransform *m, CGFloat x, CGFloat y)
{
	CGPoint point;

	if (!path) { return; }

	 point  = CGPointMake(x, y);
	 if (m != NULL)
		 point = CGPointApplyAffineTransform(point, *m);

}

void CGPathAddQuadCurveToPoint(CGMutablePathRef path,
							   const CGAffineTransform *m, CGFloat cpx, CGFloat cpy, CGFloat x, CGFloat y)
{
	CGPoint cp, end;

	if (!path) { return; }

	cp = CGPointMake(cpx, cpy);
	end = CGPointMake(x, y);

	if (m) {
		cp	 = CGPointApplyAffineTransform(cp, *m);
		end = CGPointApplyAffineTransform(end, *m);
	}

}

void CGPathAddCurveToPoint(CGMutablePathRef path, 
						   const CGAffineTransform *m, CGFloat cp1x, CGFloat cp1y,
						   CGFloat cp2x, CGFloat cp2y, CGFloat x, CGFloat y)
{
	if (!path) { return; }
}

void CGPathCloseSubpath(CGMutablePathRef path)
{
	if (!path) { return; }


	path->bIsEmpty = FALSE;

}

void CGPathAddRect(CGMutablePathRef path, const CGAffineTransform *m, CGRect rect) 
{
	CGPathAddRects(path, m, &rect, 1);
}

void CGPathAddRects(CGMutablePathRef path, const CGAffineTransform *m, const CGRect rects[], size_t count)
{
	size_t i;

	if (!path || !rects)
		return; 
	if (count == 0)
		count = sizeof(rects) / sizeof(CGRect);

	for (i = 0; i < count; ++i) {

		CGPathMoveToPoint(path, m, CGRectGetMinX(rects[i]), CGRectGetMinY(rects[i]));
		CGPathAddLineToPoint(path, m, CGRectGetMaxX(rects[i]), CGRectGetMinY(rects[i]));
		CGPathAddLineToPoint(path, m, CGRectGetMaxX(rects[i]), CGRectGetMaxY(rects[i]));
		CGPathAddLineToPoint(path, m, CGRectGetMinX(rects[i]), CGRectGetMaxY(rects[i]));

		CGPathCloseSubpath(path);
	}
}

void CGPathAddLines(CGMutablePathRef path, const CGAffineTransform *m, const CGPoint points[], size_t count)
{
	size_t i = 1;

	if (!path || !points)
		return;
	if (count == 0)
		count = sizeof(points) / sizeof(CGPoint);
	if (count < 2)
		return;

	CGPathMoveToPoint(path, m, points[0].x, points[0].y);

	for (; i < count; ++i) {

		CGPathAddLineToPoint(path, m, points[i].x, points[i].y);
	}
}

void CGPathAddEllipseInRect(CGMutablePathRef path, const CGAffineTransform *m, CGRect rect)
{
	if (!path) { return; }

	
}

void CGPathAddArc(CGMutablePathRef path, const CGAffineTransform *m,
				  CGFloat x, CGFloat y, CGFloat radius, CGFloat startAngle, 
				  CGFloat endAngle, bool clockwise)
{

}



void CGPathAddArcToPoint(CGMutablePathRef path,const CGAffineTransform *m, 
						 CGFloat x1, CGFloat y1, CGFloat x2, CGFloat y2,
						 CGFloat radius)
{

}


void CGPathAddPath(CGMutablePathRef path1, const CGAffineTransform *m, CGPathRef path2)
{

}

bool CGPathIsEmpty(CGPathRef path)
{
	return FALSE;
}

bool CGPathIsRect(CGPathRef path, CGRect *rect)
{
	return FALSE;
}

CGPoint CGPathGetCurrentPoint(CGPathRef path)
{
	CGPoint point;

	if (!path || path->bIsEmpty) {
		return CGPointZero;
	}

	point = path->current;

	return point;
}

CGRect CGPathGetBoundingBox(CGPathRef path)
{
	return CGRectZero;
}

bool CGPathContainsPoint(CGPathRef path, const CGAffineTransform *m, 
						 CGPoint point, bool eoFill)
{
	return FALSE;
}






