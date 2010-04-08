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
#ifndef CGPDFSTRING_H_
#define CGPDFSTRING_H_

typedef struct CGPDFString *CGPDFStringRef;

#include <CoreGraphics/CGBase.h>
#include <CoreFoundation/CFDate.h>
#include <CoreFoundation/CFString.h>


CG_EXTERN size_t CGPDFStringGetLength(CGPDFStringRef string);

CG_EXTERN const unsigned char *CGPDFStringGetBytePtr(CGPDFStringRef string);

CG_EXTERN CFStringRef CGPDFStringCopyTextString(CGPDFStringRef string);

CG_EXTERN CFDateRef CGPDFStringCopyDate(CGPDFStringRef string);

#endif	/* CGPDFSTRING_H_ */
