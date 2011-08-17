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
#ifndef CGPDFOBJECT_H_
#define CGPDFOBJECT_H_

#include <CoreGraphics/CGBase.h>

typedef unsigned char CGPDFBoolean;

typedef long int CGPDFInteger;

typedef CGFloat CGPDFReal;

typedef union CGPDFObject *CGPDFObjectRef;


enum CGPDFObjectType {

	kCGPDFObjectTypeNull = 1,
    kCGPDFObjectTypeBoolean,
    kCGPDFObjectTypeInteger,
    kCGPDFObjectTypeReal,
    kCGPDFObjectTypeName,
    kCGPDFObjectTypeString,
    kCGPDFObjectTypeArray,
    kCGPDFObjectTypeDictionary,
    kCGPDFObjectTypeStream
};
typedef enum CGPDFObjectType CGPDFObjectType;

CG_EXTERN CGPDFObjectType CGPDFObjectGetType(CGPDFObjectRef object);

CG_EXTERN bool CGPDFObjectGetValue(CGPDFObjectRef object, CGPDFObjectType type,
    void *value);

#endif	/* CGPDFOBJECT_H_ */
