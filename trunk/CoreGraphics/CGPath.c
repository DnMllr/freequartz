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
	//IMPLEMENT HERE

	return FALSE;
}

PathChunksRef add_chunk(CGMutablePathRef path )
{
	PathChunksRef chunk;

	chunk = (PathChunksRef)malloc(sizeof(PathChunks));
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
	//IMPLEMENT HERE

	/****************************************************************************************
	* CAPPUCCINO 
	****************************************************************************************
	CGPoint point = CGPointMake(x, y);
	int count = path->count;

	if (m != NULL)
		point = _CGPointApplyAffineTransform(point, m);

	path->start = point;
	path->current = point;

	var previous = path->elements[count - 1];

	if (count != 0 && previous.type == kCGPathElementMoveToPoint)
	{
		previous.x = point.x;
		previous.y = point.y;
	}
	else
		aPath.elements[aPath.count++] = { type:kCGPathElementMoveToPoint, x:point.x, y:point.y };
	*/
	CGPoint point;
	PathChunksRef previous;

	if (!path) { return; }

	point  = CGPointMake(x, y);
	if (m != NULL)
		point = CGPointApplyAffineTransform(point, *m);
	
	previous = path->lastChunk;
	if (previous->count != 0 && previous[previous->count-1].type == kCGPathElementMoveToPoint)
	{
		//previous.x = point.x;
		//previous.y = point.y;
	}
	else
	{

	}

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
	//IMPLEMENT HERE
}

void CGPathCloseSubpath(CGMutablePathRef path)
{
	if (!path) { return; }

	//IMPLEMENT HERE
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
	size_t i;

	if (!path || !points)
		return;
	if (count == 0)
		count = sizeof(points) / sizeof(CGPoint);
	if (count < 2)
		return;


	CGPathMoveToPoint(path, m, points[0].x, points[0].y);

	for (i = 1; i < count; ++i) 
	{
		CGPathAddLineToPoint(path, m, points[i].x, points[i].y);
	}
}

void CGPathAddEllipseInRect(CGMutablePathRef path, const CGAffineTransform *m, CGRect rect)
{
	if (!path) { return; }
	//IMPLEMENT HERE
	
}

void CGPathAddArc(CGMutablePathRef path, const CGAffineTransform *m,
				  CGFloat x, CGFloat y, CGFloat radius, CGFloat startAngle, 
				  CGFloat endAngle, bool clockwise)
{
	//IMPLEMENT HERE
}



void CGPathAddArcToPoint(CGMutablePathRef path,const CGAffineTransform *m, 
						 CGFloat x1, CGFloat y1, CGFloat x2, CGFloat y2,
						 CGFloat radius)
{
	//IMPLEMENT HERE
}


void CGPathAddPath(CGMutablePathRef path1, const CGAffineTransform *m, CGPathRef path2)
{

	/*for (var i = 0, count = anotherPath.count; i < count; ++i)
    {
        var element = anotherPath.elements[i];

        switch (element.type)
        {
            case kCGPathElementAddLineToPoint:      CGPathAddLineToPoint(aPath, aTransform, element.x, element.y);
                                                    break;

            case kCGPathElementAddCurveToPoint:     CGPathAddCurveToPoint(aPath, aTransform,
                                                                          element.cp1x, element.cp1y,
                                                                          element.cp2x, element.cp2y,
                                                                          element.x, element.y);
                                                    break;

            case kCGPathElementAddArc:              CGPathAddArc(aPath, aTransform, element.x, element.y,
                                                                 element.radius, element.startAngle,
                                                                 element.endAngle, element.isClockwise);
                                                    break;

            case kCGPathElementAddQuadCurveToPoint: CGPathAddQuadCurveToPoint(aPath, aTransform,
                                                                              element.cpx, element.cpy,
                                                                              element.x, element.y);
                                                    break;

            case kCGPathElementMoveToPoint:         CGPathMoveToPoint(aPath, aTransform, element.x, element.y);
                                                    break;

            case kCGPathElementCloseSubpath:        CGPathCloseSubpath(aPath);
                                                    break;
        }
    }*/

	//switch (element->type) 
	//{
 //   case kCGPathElementMoveToPoint:
 //       if (!CGPathIsEmpty(path)) // to silence a warning when trying to close an empty path
 //           CGPathCloseSubpath(path); // This is the only change from CGPathCreateMutableCopy
 //       CGPathMoveToPoint(path, 0, points[0].x, points[0].y);
 //       break;
 //   case kCGPathElementAddLineToPoint:
 //       CGPathAddLineToPoint(path, 0, points[0].x, points[0].y);
 //       break;
 //   case kCGPathElementAddQuadCurveToPoint:
 //       CGPathAddQuadCurveToPoint(path, 0, points[0].x, points[0].y, points[1].x, points[1].y);
 //       break;
 //   case kCGPathElementAddCurveToPoint:
 //       CGPathAddCurveToPoint(path, 0, points[0].x, points[0].y, points[1].x, points[1].y, points[2].x, points[2].y);
 //       break;
 //   case kCGPathElementCloseSubpath:
 //       CGPathCloseSubpath(path);
 //       break;
 //   }
}

bool CGPathIsEmpty(CGPathRef path)
{
	if (!path)
		return FALSE;

	return path->bIsEmpty;
}

bool CGPathIsRect(CGPathRef path, CGRect *rect)
{
	//IMPLEMENT HERE
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
	if (!path || path->bIsEmpty) {
		return CGRectZero;
	}

	return CGRectZero;
}

bool CGPathContainsPoint(CGPathRef path, const CGAffineTransform *m, 
						 CGPoint point, bool eoFill)
{
	//IMPLEMENT HERE
	return FALSE;
}






