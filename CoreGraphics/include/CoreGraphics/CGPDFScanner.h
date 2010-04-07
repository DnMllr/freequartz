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
#ifndef CGPDFSCANNER_H_
#define CGPDFSCANNER_H_

typedef struct CGPDFScanner *CGPDFScannerRef;

#include <CoreGraphics/CGPDFContentStream.h>
#include <CoreGraphics/CGPDFOperatorTable.h>

CG_EXTERN CGPDFScannerRef CGPDFScannerCreate(CGPDFContentStreamRef cs,
    CGPDFOperatorTableRef table, void *info);

CG_EXTERN CGPDFScannerRef CGPDFScannerRetain(CGPDFScannerRef scanner);

CG_EXTERN void CGPDFScannerRelease(CGPDFScannerRef scanner);

CG_EXTERN bool CGPDFScannerScan(CGPDFScannerRef scanner);

CG_EXTERN CGPDFContentStreamRef CGPDFScannerGetContentStream(CGPDFScannerRef
    scanner);

CG_EXTERN bool CGPDFScannerPopObject(CGPDFScannerRef scanner,
    CGPDFObjectRef *value);

CG_EXTERN bool CGPDFScannerPopBoolean(CGPDFScannerRef scanner,
    CGPDFBoolean *value);

CG_EXTERN bool CGPDFScannerPopInteger(CGPDFScannerRef scanner,
    CGPDFInteger *value);

CG_EXTERN bool CGPDFScannerPopNumber(CGPDFScannerRef scanner, CGPDFReal *value);


CG_EXTERN bool CGPDFScannerPopName(CGPDFScannerRef scanner, const char **value);

CG_EXTERN bool CGPDFScannerPopString(CGPDFScannerRef scanner,
    CGPDFStringRef *value);


CG_EXTERN bool CGPDFScannerPopArray(CGPDFScannerRef scanner,
    CGPDFArrayRef *value);



CG_EXTERN bool CGPDFScannerPopDictionary(CGPDFScannerRef scanner,
    CGPDFDictionaryRef *value);

CG_EXTERN bool CGPDFScannerPopStream(CGPDFScannerRef scanner,
    CGPDFStreamRef *value);

#endif	/* CGPDFSCANNER_H_ */
