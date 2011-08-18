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
#ifndef CGPDFDICTIONARY_H_
#define CGPDFDICTIONARY_H_

typedef struct CGPDFDictionary *CGPDFDictionaryRef;

#include <CoreGraphics/CGPDFArray.h>
#include <CoreGraphics/CGPDFObject.h>
#include <CoreGraphics/CGPDFStream.h>
#include <CoreGraphics/CGPDFString.h>

CG_EXTERN size_t CGPDFDictionaryGetCount(CGPDFDictionaryRef dict);

CG_EXTERN bool CGPDFDictionaryGetObject(CGPDFDictionaryRef dict,
    const char *key, CGPDFObjectRef *value);

CG_EXTERN bool CGPDFDictionaryGetBoolean(CGPDFDictionaryRef dict,
    const char *key, CGPDFBoolean *value);

CG_EXTERN bool CGPDFDictionaryGetInteger(CGPDFDictionaryRef dict,
    const char *key, CGPDFInteger *value);

CG_EXTERN bool CGPDFDictionaryGetNumber(CGPDFDictionaryRef dict,
    const char *key, CGPDFReal *value);

CG_EXTERN bool CGPDFDictionaryGetName(CGPDFDictionaryRef dict, const char *key,
    const char **value);

CG_EXTERN bool CGPDFDictionaryGetString(CGPDFDictionaryRef dict,
    const char *key, CGPDFStringRef *value);

CG_EXTERN bool CGPDFDictionaryGetArray(CGPDFDictionaryRef dict,
    const char *key, CGPDFArrayRef *value);

CG_EXTERN bool CGPDFDictionaryGetDictionary(CGPDFDictionaryRef dict,
    const char *key, CGPDFDictionaryRef *value);

CG_EXTERN bool CGPDFDictionaryGetStream(CGPDFDictionaryRef dict,
    const char *key, CGPDFStreamRef *value);

typedef void (*CGPDFDictionaryApplierFunction)(const char *key,
    CGPDFObjectRef value, void *info);

CG_EXTERN void CGPDFDictionaryApplyFunction(CGPDFDictionaryRef dict,
    CGPDFDictionaryApplierFunction function, void *info);

#endif	/* CGPDFDICTIONARY_H_ */
