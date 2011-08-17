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
