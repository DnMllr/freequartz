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
#ifndef CGPDFDOCUMENT_H_
#define CGPDFDOCUMENT_H_

typedef struct CGPDFDocument *CGPDFDocumentRef;

#include <CoreGraphics/CGDataProvider.h> 
#include <CoreGraphics/CGGeometry.h> 
#include <CoreGraphics/CGPDFPage.h> 
#include <CoreFoundation/CFURL.h>

CG_EXTERN CGPDFDocumentRef CGPDFDocumentCreateWithProvider(CGDataProviderRef
    provider);

CG_EXTERN CGPDFDocumentRef CGPDFDocumentCreateWithURL(CFURLRef url);

CG_EXTERN CGPDFDocumentRef CGPDFDocumentRetain(CGPDFDocumentRef document);

CG_EXTERN void CGPDFDocumentRelease(CGPDFDocumentRef document);

CG_EXTERN void CGPDFDocumentGetVersion(CGPDFDocumentRef document,
    int *majorVersion, int *minorVersion);

CG_EXTERN bool CGPDFDocumentIsEncrypted(CGPDFDocumentRef document);

CG_EXTERN bool CGPDFDocumentUnlockWithPassword(CGPDFDocumentRef document,
    const char *password);

CG_EXTERN bool CGPDFDocumentIsUnlocked(CGPDFDocumentRef document);

CG_EXTERN bool CGPDFDocumentAllowsPrinting(CGPDFDocumentRef document);

CG_EXTERN bool CGPDFDocumentAllowsCopying(CGPDFDocumentRef document);

CG_EXTERN size_t CGPDFDocumentGetNumberOfPages(CGPDFDocumentRef document);

CG_EXTERN CGPDFPageRef CGPDFDocumentGetPage(CGPDFDocumentRef document,
    size_t pageNumber);

CG_EXTERN CGPDFDictionaryRef CGPDFDocumentGetCatalog(CGPDFDocumentRef document);

CG_EXTERN CGPDFDictionaryRef CGPDFDocumentGetInfo(CGPDFDocumentRef document);

CG_EXTERN CGPDFArrayRef CGPDFDocumentGetID(CGPDFDocumentRef document);

CG_EXTERN CFTypeID CGPDFDocumentGetTypeID(void);

/* DEPRECATED */
CG_EXTERN CGRect CGPDFDocumentGetMediaBox(CGPDFDocumentRef document, int page);

CG_EXTERN CGRect CGPDFDocumentGetCropBox(CGPDFDocumentRef document, int page);

CG_EXTERN CGRect CGPDFDocumentGetBleedBox(CGPDFDocumentRef document, int page);

CG_EXTERN CGRect CGPDFDocumentGetTrimBox(CGPDFDocumentRef document, int page);

CG_EXTERN CGRect CGPDFDocumentGetArtBox(CGPDFDocumentRef document, int page);

CG_EXTERN int CGPDFDocumentGetRotationAngle(CGPDFDocumentRef document,
    int page);

#endif	/* CGPDFDOCUMENT_H_ */
