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
#ifndef CGPDFCONTENTSTREAM_H_
#define CGPDFCONTENTSTREAM_H_

typedef struct CGPDFContentStream *CGPDFContentStreamRef;

#include <CoreGraphics/CGPDFPage.h>

CG_EXTERN CGPDFContentStreamRef CGPDFContentStreamCreateWithPage(CGPDFPageRef
    page);

CG_EXTERN CGPDFContentStreamRef CGPDFContentStreamCreateWithStream
    (CGPDFStreamRef stream, CGPDFDictionaryRef streamResources,
	CGPDFContentStreamRef parent);

CG_EXTERN CGPDFContentStreamRef CGPDFContentStreamRetain(CGPDFContentStreamRef
    cs);

CG_EXTERN void CGPDFContentStreamRelease(CGPDFContentStreamRef cs);

CG_EXTERN CFArrayRef CGPDFContentStreamGetStreams(CGPDFContentStreamRef cs);

CG_EXTERN CGPDFObjectRef CGPDFContentStreamGetResource(CGPDFContentStreamRef
    cs, const char *category, const char *name);

#endif	/* CGPDFCONTENTSTREAM_H_ */
