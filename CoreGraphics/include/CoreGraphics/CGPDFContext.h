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
#ifndef CGPDFCONTEXT_H_
#define CGPDFCONTEXT_H_

#include <CoreGraphics/CGBase.h>
#include <CoreGraphics/CGContext.h>
#include <CoreGraphics/CGDataConsumer.h>
#include <CoreFoundation/CFDictionary.h>

CG_EXTERN CGContextRef CGPDFContextCreate(CGDataConsumerRef consumer,
    const CGRect *mediaBox, CFDictionaryRef auxiliaryInfo);

CG_EXTERN CGContextRef CGPDFContextCreateWithURL(CFURLRef url,
    const CGRect *mediaBox, CFDictionaryRef auxiliaryInfo);

CG_EXTERN void CGPDFContextClose(CGContextRef context);

CG_EXTERN void CGPDFContextBeginPage(CGContextRef context,
    CFDictionaryRef pageInfo);

CG_EXTERN void CGPDFContextEndPage(CGContextRef context);

CG_EXTERN void CGPDFContextSetURLForRect(CGContextRef context, CFURLRef url,
    CGRect rect);

CG_EXTERN void CGPDFContextAddDestinationAtPoint(CGContextRef context,
    CFStringRef name, CGPoint point);

CG_EXTERN void CGPDFContextSetDestinationForRect(CGContextRef context,
    CFStringRef name, CGRect rect);

CG_EXTERN const CFStringRef kCGPDFContextMediaBox;
CG_EXTERN const CFStringRef kCGPDFContextCropBox;
CG_EXTERN const CFStringRef kCGPDFContextBleedBox;
CG_EXTERN const CFStringRef kCGPDFContextTrimBox;
CG_EXTERN const CFStringRef kCGPDFContextArtBox;
CG_EXTERN const CFStringRef kCGPDFContextTitle;
CG_EXTERN const CFStringRef kCGPDFContextAuthor;
CG_EXTERN const CFStringRef kCGPDFContextSubject;
CG_EXTERN const CFStringRef kCGPDFContextKeywords;
CG_EXTERN const CFStringRef kCGPDFContextCreator;
CG_EXTERN const CFStringRef kCGPDFContextOwnerPassword;
CG_EXTERN const CFStringRef kCGPDFContextUserPassword;
CG_EXTERN const CFStringRef kCGPDFContextEncryptionKeyLength;
CG_EXTERN const CFStringRef kCGPDFContextAllowsPrinting;
CG_EXTERN const CFStringRef kCGPDFContextAllowsCopying;
CG_EXTERN const CFStringRef kCGPDFContextOutputIntent;
CG_EXTERN const CFStringRef kCGPDFXOutputIntentSubtype;
CG_EXTERN const CFStringRef kCGPDFXOutputConditionIdentifier;
CG_EXTERN const CFStringRef kCGPDFXOutputCondition;
CG_EXTERN const CFStringRef kCGPDFXRegistryName;
CG_EXTERN const CFStringRef kCGPDFXInfo;
CG_EXTERN const CFStringRef kCGPDFXDestinationOutputProfile;
CG_EXTERN const CFStringRef kCGPDFContextOutputIntents;

#endif	/* CGPDFCONTEXT_H_ */
