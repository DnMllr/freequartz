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
#ifndef CGPDFOPERATORTABLE_H_
#define CGPDFOPERATORTABLE_H_

typedef struct CGPDFOperatorTable *CGPDFOperatorTableRef;

#include <CoreGraphics/CGPDFScanner.h>

typedef void (*CGPDFOperatorCallback)(CGPDFScannerRef scanner, void *info);

CG_EXTERN CGPDFOperatorTableRef CGPDFOperatorTableCreate(void);

CG_EXTERN CGPDFOperatorTableRef CGPDFOperatorTableRetain(CGPDFOperatorTableRef
    table);

CG_EXTERN void CGPDFOperatorTableRelease(CGPDFOperatorTableRef table);

CG_EXTERN void CGPDFOperatorTableSetCallback(CGPDFOperatorTableRef table,
    const char *name, CGPDFOperatorCallback callback);

#endif	/* CGPDFOPERATORTABLE_H_ */
