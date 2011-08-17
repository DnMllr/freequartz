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
