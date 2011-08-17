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
