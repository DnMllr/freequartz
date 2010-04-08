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
#ifndef CGFUNCTION_H_
#define CGFUNCTION_H_

typedef struct CGFunction *CGFunctionRef;

#include <CoreGraphics/CGBase.h>
#include <CoreFoundation/CFBase.h>

typedef void (*CGFunctionEvaluateCallback)(void *info, const CGFloat *in,
    CGFloat *out);

typedef void (*CGFunctionReleaseInfoCallback)(void *info);

struct CGFunctionCallbacks {
    unsigned int version;
    CGFunctionEvaluateCallback evaluate;
    CGFunctionReleaseInfoCallback releaseInfo;
};
typedef struct CGFunctionCallbacks CGFunctionCallbacks;


CG_EXTERN CFTypeID CGFunctionGetTypeID(void);

CG_EXTERN CGFunctionRef CGFunctionCreate(void *info, size_t domainDimension,
    const CGFloat *domain, size_t rangeDimension, const CGFloat *range,
    const CGFunctionCallbacks *callbacks);

CG_EXTERN CGFunctionRef CGFunctionRetain(CGFunctionRef function);

CG_EXTERN void CGFunctionRelease(CGFunctionRef function);

#endif	/* CGFUNCTION_H_ */
