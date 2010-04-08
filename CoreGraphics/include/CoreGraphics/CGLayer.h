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
#ifndef CGLAYER_H_
#define CGLAYER_H_

typedef struct CGLayer *CGLayerRef;

#include <CoreGraphics/CGBase.h>
#include <CoreGraphics/CGContext.h>

CG_EXTERN CGLayerRef CGLayerCreateWithContext(CGContextRef context,
    CGSize size, CFDictionaryRef auxiliaryInfo);

CG_EXTERN CGLayerRef CGLayerRetain(CGLayerRef layer);

CG_EXTERN void CGLayerRelease(CGLayerRef layer);

CG_EXTERN CGSize CGLayerGetSize(CGLayerRef layer);

CG_EXTERN CGContextRef CGLayerGetContext(CGLayerRef layer);

CG_EXTERN void CGContextDrawLayerInRect(CGContextRef context, CGRect rect,
    CGLayerRef layer);

CG_EXTERN void CGContextDrawLayerAtPoint(CGContextRef context, CGPoint point,
    CGLayerRef layer);

CG_EXTERN CFTypeID CGLayerGetTypeID(void);

#endif	/* CGLAYER_H_ */
