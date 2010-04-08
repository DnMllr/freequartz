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
