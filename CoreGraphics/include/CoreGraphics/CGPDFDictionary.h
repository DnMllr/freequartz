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
