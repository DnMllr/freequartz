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
#ifndef CGAFFINETRANSFORM_H_
#define CGAFFINETRANSFORM_H_

typedef struct CGAffineTransform CGAffineTransform;

#include <CoreGraphics/CGBase.h>
#include <CoreGraphics/CGGeometry.h>

struct CGAffineTransform {
  CGFloat a, b, c, d;
  CGFloat tx, ty;
};

/* constants */
CG_EXTERN const CGAffineTransform CGAffineTransformIdentity;

/* functions */
CG_EXTERN CGAffineTransform CGAffineTransformMake (
	CGFloat a, CGFloat b,
	CGFloat c, CGFloat d, CGFloat tx, CGFloat ty);

CG_EXTERN CGAffineTransform CGAffineTransformMakeRotation(CGFloat angle);

CG_EXTERN CGAffineTransform CGAffineTransformMakeScale(CGFloat sx, CGFloat sy);

CG_EXTERN CGAffineTransform CGAffineTransformMakeTranslation(CGFloat tx, CGFloat ty);

/* Modifying Affine Transformations */ 
CG_EXTERN CGAffineTransform CGAffineTransformTranslate(CGAffineTransform t, 
CGFloat tx, CGFloat ty);

CG_EXTERN CGAffineTransform CGAffineTransformScale(CGAffineTransform t,
  CGFloat sx, CGFloat sy);

CG_EXTERN CGAffineTransform CGAffineTransformRotate(CGAffineTransform t,
  CGFloat angle);

CG_EXTERN CGAffineTransform CGAffineTransformInvert(CGAffineTransform t);

CG_EXTERN CGAffineTransform CGAffineTransformConcat(CGAffineTransform t1,
  CGAffineTransform t2);
  
/* Applying Affine Transformations */

CG_EXTERN bool CGAffineTransformEqualToTransform(CGAffineTransform t1,
  CGAffineTransform t2);


CG_EXTERN CGPoint CGPointApplyAffineTransform(CGPoint point,
  CGAffineTransform t);


CG_EXTERN CGSize CGSizeApplyAffineTransform(CGSize size, CGAffineTransform t);


CG_EXTERN CGRect CGRectApplyAffineTransform(CGRect rect, CGAffineTransform t);

/* Evaluating Affine Transforms */

CG_EXTERN bool CGAffineTransformIsIdentity(CGAffineTransform t);

/* inline functions */
CG_INLINE CGAffineTransform __CGAffineTransformMake(CGFloat a, CGFloat b, 
 CGFloat c, CGFloat d, CGFloat tx, CGFloat ty)
{
  CGAffineTransform at;
  at.a = a; at.b = b; at.c = c; at.d = d; 
  at.tx = tx; at.ty = ty;
  return at;
}
#define CGAffineTransformMake __CGAffineTransformMake

CG_INLINE CGPoint
__CGPointApplyAffineTransform(CGPoint point, CGAffineTransform t)
{
  CGPoint p;
  p.x = (CGFloat)((double)t.a * point.x + (double)t.c * point.y + t.tx);
  p.y = (CGFloat)((double)t.b * point.x + (double)t.d * point.y + t.ty);
  return p;
}
#define CGPointApplyAffineTransform __CGPointApplyAffineTransform

CG_INLINE CGSize
__CGSizeApplyAffineTransform(CGSize size, CGAffineTransform t)
{
  CGSize s;
  s.width  = (CGFloat)((double)t.a * size.width + (double)t.c * size.height);
  s.height = (CGFloat)((double)t.b * size.width + (double)t.d * size.height);
  return s;
}
#define CGSizeApplyAffineTransform __CGSizeApplyAffineTransform

#endif /* CGAFFINETRANSFORM_H_ */
