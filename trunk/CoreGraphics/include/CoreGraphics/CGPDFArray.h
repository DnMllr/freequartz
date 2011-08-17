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
#ifndef CGPDFARRAY_H_
#define CGPDFARRAY_H_

typedef struct CGPDFArray *CGPDFArrayRef;

#include <CoreGraphics/CGPDFDictionary.h>
#include <CoreGraphics/CGPDFObject.h>
#include <CoreGraphics/CGPDFStream.h>
#include <CoreGraphics/CGPDFString.h>

CG_EXTERN size_t CGPDFArrayGetCount(CGPDFArrayRef array);

CG_EXTERN bool CGPDFArrayGetObject(CGPDFArrayRef array, size_t index, 
	CGPDFArrayRef *value);

CG_EXTERN bool CGPDFArrayGetNull(CGPDFArrayRef array, size_t index);

CG_EXTERN bool CGPDFArrayGetBoolean(CGPDFArrayRef array, size_t index,
	CGPDFBoolean *value);

CG_EXTERN bool CGPDFArrayGetInteger(CGPDFArrayRef array, size_t index,
	 CGPDFInteger *value);

CG_EXTERN bool CGPDFArrayGetNumber(CGPDFArrayRef array, size_t index,
    CGPDFReal *value);

CG_EXTERN bool CGPDFArrayGetName(CGPDFArrayRef array, size_t index,
    const char **value);

CG_EXTERN bool CGPDFArrayGetString(CGPDFArrayRef array, size_t index,
    CGPDFStringRef *value);

CG_EXTERN bool CGPDFArrayGetArray(CGPDFArrayRef array, size_t index,
    CGPDFArrayRef *value);

CG_EXTERN bool CGPDFArrayGetDictionary(CGPDFArrayRef array, size_t index,
    CGPDFDictionaryRef *value);

CG_EXTERN bool CGPDFArrayGetStream(CGPDFArrayRef array, size_t index,
    CGPDFStreamRef *value);

#endif	/* CGPDFARRAY_H_ */
