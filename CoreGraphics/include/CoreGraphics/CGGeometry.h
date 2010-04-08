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
#ifndef CGGEOMETRY_H_
#define CGGEOMETRY_H_

#include <CoreGraphics/CGBase.h>
#include <CoreFoundation/CFDictionary.h>

struct CGPoint {
  CGFloat x;
  CGFloat y;
};
typedef struct CGPoint CGPoint;


struct CGSize {
  CGFloat width;
  CGFloat height;
};
typedef struct CGSize CGSize;


struct CGRect {
  CGPoint origin;
  CGSize size;
};
typedef struct CGRect CGRect;


enum CGRectEdge {
  CGRectMinXEdge, CGRectMinYEdge, CGRectMaxXEdge, CGRectMaxYEdge
};
typedef enum CGRectEdge CGRectEdge;


CG_EXTERN const CGPoint CGPointZero;
CG_EXTERN const CGSize CGSizeZero;
CG_EXTERN const CGRect CGRectZero;
CG_EXTERN const CGRect CGRectNull;
CG_EXTERN const CGRect CGRectInfinite;

CG_INLINE CGPoint CGPointMake(CGFloat x, CGFloat y);
CG_INLINE CGSize CGSizeMake(CGFloat width, CGFloat height);
CG_INLINE CGRect CGRectMake(CGFloat x, CGFloat y, CGFloat width, CGFloat height);
CG_EXTERN CGFloat CGRectGetMinX(CGRect rect);
CG_EXTERN CGFloat CGRectGetMidX(CGRect rect);
CG_EXTERN CGFloat CGRectGetMaxX(CGRect rect);
CG_EXTERN CGFloat CGRectGetMinY(CGRect rect);
CG_EXTERN CGFloat CGRectGetMidY(CGRect rect);
CG_EXTERN CGFloat CGRectGetMaxY(CGRect rect);
CG_EXTERN CGFloat CGRectGetWidth(CGRect rect);
CG_EXTERN CGFloat CGRectGetHeight(CGRect rect);
CG_EXTERN bool CGPointEqualToPoint(CGPoint point1, CGPoint point2);
CG_EXTERN bool CGSizeEqualToSize(CGSize size1, CGSize size2);
CG_EXTERN bool CGRectEqualToRect(CGRect rect1, CGRect rect2);
CG_EXTERN CGRect CGRectStandardize(CGRect rect);
CG_EXTERN bool CGRectIsEmpty(CGRect rect);
CG_EXTERN bool CGRectIsNull(CGRect rect);
CG_EXTERN bool CGRectIsInfinite(CGRect rect);
CG_EXTERN CGRect CGRectInset(CGRect rect, CGFloat dx, CGFloat dy);
CG_EXTERN CGRect CGRectIntegral(CGRect rect);
CG_EXTERN CGRect CGRectUnion(CGRect r1, CGRect r2);
CG_EXTERN CGRect CGRectIntersection(CGRect r1, CGRect r2);
CG_EXTERN CGRect CGRectOffset(CGRect rect, CGFloat dx, CGFloat dy);
CG_EXTERN void CGRectDivide(CGRect rect, CGRect *slice, CGRect *remainder,
  CGFloat amount, CGRectEdge edge);
CG_EXTERN bool CGRectContainsPoint(CGRect rect, CGPoint point);
CG_EXTERN bool CGRectContainsRect(CGRect rect1, CGRect rect2);
CG_EXTERN bool CGRectIntersectsRect(CGRect rect1, CGRect rect2);
CG_EXTERN CFDictionaryRef CGPointCreateDictionaryRepresentation(CGPoint point);
CG_EXTERN bool CGPointMakeWithDictionaryRepresentation(CFDictionaryRef dict,
  CGPoint *point);
CG_EXTERN CFDictionaryRef CGSizeCreateDictionaryRepresentation(CGSize size);
CG_EXTERN bool CGSizeMakeWithDictionaryRepresentation(CFDictionaryRef dict,
  CGSize *size);
CG_EXTERN CFDictionaryRef CGRectCreateDictionaryRepresentation(CGRect);
CG_EXTERN bool CGRectMakeWithDictionaryRepresentation(CFDictionaryRef dict,
  CGRect *rect);


CG_INLINE CGPoint
CGPointMake(CGFloat x, CGFloat y)
{
  CGPoint p; p.x = x; p.y = y; return p;
}

CG_INLINE CGSize
CGSizeMake(CGFloat width, CGFloat height)
{
  CGSize size; size.width = width; size.height = height; return size;
}

CG_INLINE CGRect
CGRectMake(CGFloat x, CGFloat y, CGFloat width, CGFloat height)
{
  CGRect rect;
  rect.origin.x = x; rect.origin.y = y;
  rect.size.width = width; rect.size.height = height;
  return rect;
}

CG_INLINE bool
__CGPointEqualToPoint(CGPoint point1, CGPoint point2)
{
  return point1.x == point2.x && point1.y == point2.y;
}
#define CGPointEqualToPoint __CGPointEqualToPoint

CG_INLINE bool
__CGSizeEqualToSize(CGSize size1, CGSize size2)
{
  return size1.width == size2.width && size1.height == size2.height;
}
#define CGSizeEqualToSize __CGSizeEqualToSize

#endif /* CGGEOMETRY_H_ */
