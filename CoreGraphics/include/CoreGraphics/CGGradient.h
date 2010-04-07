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
#ifndef CGGRADIENT_H_
#define CGGRADIENT_H_

typedef struct CGGradient *CGGradientRef;

enum {
    kCGGradientDrawsBeforeStartLocation = (1 << 0),
    kCGGradientDrawsAfterEndLocation = (1 << 1)
};
typedef enum CGGradientDrawingOptions CGGradientDrawingOptions;

#include <CoreGraphics/CGBase.h>
#include <CoreGraphics/CGColorSpace.h>
#include <CoreGraphics/CGContext.h>


CG_EXTERN CFTypeID CGGradientGetTypeID(void);

CG_EXTERN CGGradientRef CGGradientCreateWithColorComponents(CGColorSpaceRef
    space, const CGFloat components[], const CGFloat locations[], size_t count);

CG_EXTERN CGGradientRef CGGradientCreateWithColors(CGColorSpaceRef space,
    CFArrayRef colors, const CGFloat locations[]);

CG_EXTERN CGGradientRef CGGradientRetain(CGGradientRef gradient);

CG_EXTERN void CGGradientRelease(CGGradientRef gradient);

#endif	/* CGGRADIENT_H_ */
