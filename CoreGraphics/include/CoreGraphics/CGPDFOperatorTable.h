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
