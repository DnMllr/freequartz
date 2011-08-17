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
