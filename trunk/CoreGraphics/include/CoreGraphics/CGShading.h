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
#ifndef CGSHADING_H_
#define CGSHADING_H_

#include <CoreGraphics/CGBase.h>
#include <CoreGraphics/CGColorSpace.h>
#include <CoreGraphics/CGFunction.h>
#include <CoreGraphics/CGGeometry.h>
#include <CoreFoundation/CFBase.h>

typedef struct CGShading *CGShadingRef;

CG_EXTERN CFTypeID CGShadingGetTypeID(void);

CG_EXTERN CGShadingRef CGShadingCreateAxial(CGColorSpaceRef space,
    CGPoint start, CGPoint end, CGFunctionRef function, bool extendStart,
    bool extendEnd);

CG_EXTERN CGShadingRef CGShadingCreateRadial(CGColorSpaceRef space,
    CGPoint start, CGFloat startRadius, CGPoint end, CGFloat endRadius,
    CGFunctionRef function, bool extendStart, bool extendEnd);

CG_EXTERN CGShadingRef CGShadingRetain(CGShadingRef shading);

CG_EXTERN void CGShadingRelease(CGShadingRef shading)
    CG_AVAILABLE_STARTING(__MAC_10_2, __IPHONE_2_0);

#endif	/* CGSHADING_H_ */
