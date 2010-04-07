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
#ifndef CGPDFSTREAM_H_
#define CGPDFSTREAM_H_

typedef struct CGPDFStream *CGPDFStreamRef;

enum CGPDFDataFormat {
    CGPDFDataFormatRaw, CGPDFDataFormatJPEGEncoded, CGPDFDataFormatJPEG2000
};
typedef enum CGPDFDataFormat CGPDFDataFormat;

#include <CoreGraphics/CGPDFDictionary.h>
#include <CoreGraphics/CGPDFStream.h>
#include <CoreFoundation/CFData.h>

CG_EXTERN CGPDFDictionaryRef CGPDFStreamGetDictionary(CGPDFStreamRef stream);

CG_EXTERN CFDataRef CGPDFStreamCopyData(CGPDFStreamRef stream,
    CGPDFDataFormat *format);

#endif	/* CGPDFSTREAM_H_ */
