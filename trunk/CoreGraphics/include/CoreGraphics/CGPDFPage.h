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
#ifndef CGPDFPAGE_H_
#define CGPDFPAGE_H_

typedef struct CGPDFPage *CGPDFPageRef;

#include <CoreGraphics/CGAffineTransform.h> 
#include <CoreGraphics/CGPDFDictionary.h> 
#include <CoreGraphics/CGPDFDocument.h> 

enum CGPDFBox {
    kCGPDFMediaBox = 0,
    kCGPDFCropBox = 1,
    kCGPDFBleedBox = 2,
    kCGPDFTrimBox = 3,
    kCGPDFArtBox = 4
};
typedef enum CGPDFBox CGPDFBox;

CG_EXTERN CGPDFPageRef CGPDFPageRetain(CGPDFPageRef page);

CG_EXTERN void CGPDFPageRelease(CGPDFPageRef page);

CG_EXTERN CGPDFDocumentRef CGPDFPageGetDocument(CGPDFPageRef page);

CG_EXTERN size_t CGPDFPageGetPageNumber(CGPDFPageRef page);

CG_EXTERN CGRect CGPDFPageGetBoxRect(CGPDFPageRef page, CGPDFBox box);

CG_EXTERN int CGPDFPageGetRotationAngle(CGPDFPageRef page);

CG_EXTERN CGAffineTransform CGPDFPageGetDrawingTransform(CGPDFPageRef page,
    CGPDFBox box, CGRect rect, int rotate, bool preserveAspectRatio);

CG_EXTERN CGPDFDictionaryRef CGPDFPageGetDictionary(CGPDFPageRef page);

CG_EXTERN CFTypeID CGPDFPageGetTypeID(void);

#endif	/* CGPDFPAGE_H_ */
