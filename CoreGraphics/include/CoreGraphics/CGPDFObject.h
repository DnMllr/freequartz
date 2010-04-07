/****************************************************************************
**
** Copyright (C) 2010 Smartmobili.
** All rights reserved.
** Contact: Smartmobili (contact@smartmobili.com)
**	
** This file is part of the CoreGraphics module of the Coconuts Toolkit.
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
