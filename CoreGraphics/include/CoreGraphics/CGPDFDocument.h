/* Copyright 2010 Smartmobili SARL
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
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
