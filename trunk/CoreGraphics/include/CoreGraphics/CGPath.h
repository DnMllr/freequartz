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
#ifndef CGPATH_H_
#define CGPATH_H_

typedef struct CGPath *CGMutablePathRef;
typedef const struct CGPath *CGPathRef;

#include <CoreGraphics/CGBase.h>
#include <CoreGraphics/CGAffineTransform.h>
#include <CoreFoundation/CFBase.h>

CG_EXTERN CFTypeID CGPathGetTypeID(void);

CG_EXTERN CGMutablePathRef CGPathCreateMutable(void);

CG_EXTERN CGPathRef CGPathCreateCopy(CGPathRef path);

CG_EXTERN CGMutablePathRef CGPathCreateMutableCopy(CGPathRef path);

CG_EXTERN CGPathRef CGPathRetain(CGPathRef path);

CG_EXTERN void CGPathRelease(CGPathRef path);

CG_EXTERN bool CGPathEqualToPath(CGPathRef path1, CGPathRef path2);

CG_EXTERN void CGPathMoveToPoint(CGMutablePathRef path,
    const CGAffineTransform *m, CGFloat x, CGFloat y);

CG_EXTERN void CGPathAddLineToPoint(CGMutablePathRef path,
    const CGAffineTransform *m, CGFloat x, CGFloat y);

CG_EXTERN void CGPathAddQuadCurveToPoint(CGMutablePathRef path,
    const CGAffineTransform *m, CGFloat cpx, CGFloat cpy, CGFloat x, CGFloat y);

CG_EXTERN void CGPathAddCurveToPoint(CGMutablePathRef path,
    const CGAffineTransform *m, CGFloat cp1x, CGFloat cp1y,
    CGFloat cp2x, CGFloat cp2y, CGFloat x, CGFloat y);

CG_EXTERN void CGPathCloseSubpath(CGMutablePathRef path);

CG_EXTERN void CGPathAddRect(CGMutablePathRef path, const CGAffineTransform *m,
    CGRect rect);

CG_EXTERN void CGPathAddRects(CGMutablePathRef path,
    const CGAffineTransform *m, const CGRect rects[], size_t count);

CG_EXTERN void CGPathAddLines(CGMutablePathRef path,
    const CGAffineTransform *m, const CGPoint points[], size_t count);

CG_EXTERN void CGPathAddEllipseInRect(CGMutablePathRef path,
    const CGAffineTransform *m, CGRect rect);

CG_EXTERN void CGPathAddArc(CGMutablePathRef path, const CGAffineTransform *m,
    CGFloat x, CGFloat y, CGFloat radius, CGFloat startAngle, CGFloat endAngle,
    bool clockwise);

CG_EXTERN void CGPathAddArcToPoint(CGMutablePathRef path,
    const CGAffineTransform *m, CGFloat x1, CGFloat y1, CGFloat x2, CGFloat y2,
    CGFloat radius);

CG_EXTERN void CGPathAddPath(CGMutablePathRef path1,
    const CGAffineTransform *m, CGPathRef path2);

CG_EXTERN bool CGPathIsEmpty(CGPathRef path);

CG_EXTERN bool CGPathIsRect(CGPathRef path, CGRect *rect);

CG_EXTERN CGPoint CGPathGetCurrentPoint(CGPathRef path);

CG_EXTERN CGRect CGPathGetBoundingBox(CGPathRef path);

CG_EXTERN bool CGPathContainsPoint(CGPathRef path,
    const CGAffineTransform *m, CGPoint point, bool eoFill);



enum CGPathElementType {
    kCGPathElementMoveToPoint,
    kCGPathElementAddLineToPoint,
    kCGPathElementAddQuadCurveToPoint,
    kCGPathElementAddCurveToPoint,
    kCGPathElementCloseSubpath
};
typedef enum CGPathElementType CGPathElementType;

struct CGPathElement {
    CGPathElementType type;
    CGPoint *points;
};
typedef struct CGPathElement CGPathElement;


typedef void (*CGPathApplierFunction)(void *info,
    const CGPathElement *element);

CG_EXTERN void CGPathApply(CGPathRef path, void *info,
    CGPathApplierFunction function);

#endif	/* CGPATH_H_ */
