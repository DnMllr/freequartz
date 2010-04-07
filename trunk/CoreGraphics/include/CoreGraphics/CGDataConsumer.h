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
#ifndef CGDATACONSUMER_H_
#define CGDATACONSUMER_H_

typedef struct CGDataConsumer *CGDataConsumerRef;

#include <CoreGraphics/CGBase.h>
#include <CoreFoundation/CFURL.h>
#include <stddef.h>

typedef size_t (*CGDataConsumerPutBytesCallback)(void *info,
    const void *buffer, size_t count);

typedef void (*CGDataConsumerReleaseInfoCallback)(void *info);

struct CGDataConsumerCallbacks {
    CGDataConsumerPutBytesCallback putBytes;
    CGDataConsumerReleaseInfoCallback releaseConsumer;
};
typedef struct CGDataConsumerCallbacks CGDataConsumerCallbacks;

CG_EXTERN CFTypeID CGDataConsumerGetTypeID(void);

CG_EXTERN CGDataConsumerRef CGDataConsumerCreate(void *info,
    const CGDataConsumerCallbacks *callbacks);

CG_EXTERN CGDataConsumerRef CGDataConsumerCreateWithURL(CFURLRef url);

CG_EXTERN CGDataConsumerRef CGDataConsumerCreateWithCFData(CFMutableDataRef
    data);

CG_EXTERN CGDataConsumerRef CGDataConsumerRetain(CGDataConsumerRef consumer);

CG_EXTERN void CGDataConsumerRelease(CGDataConsumerRef consumer);

#endif	/* CGDATACONSUMER_H_ */
