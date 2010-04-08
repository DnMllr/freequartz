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
#ifndef CGPATTERN_H_
#define CGPATTERN_H_

typedef struct CGPattern *CGPatternRef;

#include <CoreGraphics/CGBase.h>
#include <CoreGraphics/CGContext.h>
#include <CoreFoundation/CFBase.h>

enum CGPatternTiling {
    kCGPatternTilingNoDistortion,
    kCGPatternTilingConstantSpacingMinimalDistortion,
    kCGPatternTilingConstantSpacing
};
typedef enum CGPatternTiling CGPatternTiling;

typedef void (*CGPatternDrawPatternCallback)(void *info, CGContextRef c);
typedef void (*CGPatternReleaseInfoCallback)(void *info);

struct CGPatternCallbacks {
    unsigned int version;
    CGPatternDrawPatternCallback drawPattern;
    CGPatternReleaseInfoCallback releaseInfo;
};
typedef struct CGPatternCallbacks CGPatternCallbacks;

CG_EXTERN CFTypeID CGPatternGetTypeID(void);

CG_EXTERN CGPatternRef CGPatternCreate(void *info, CGRect bounds,
    CGAffineTransform matrix, CGFloat xStep, CGFloat yStep,
    CGPatternTiling tiling, bool isColored,
    const CGPatternCallbacks *callbacks);

CG_EXTERN CGPatternRef CGPatternRetain(CGPatternRef pattern);

CG_EXTERN void CGPatternRelease(CGPatternRef pattern);

#endif	/* CGPATTERN_H_ */
