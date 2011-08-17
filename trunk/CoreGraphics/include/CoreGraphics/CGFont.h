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
#ifndef CGFONT_H_
#define CGFONT_H_


typedef struct CGFont *CGFontRef;

typedef unsigned short CGFontIndex;
typedef CGFontIndex CGGlyph;

enum CGFontPostScriptFormat {
    kCGFontPostScriptFormatType1 = 1,
    kCGFontPostScriptFormatType3 = 3,
    kCGFontPostScriptFormatType42 = 42
};
typedef enum CGFontPostScriptFormat CGFontPostScriptFormat;

#include <CoreGraphics/CGBase.h>
#include <CoreGraphics/CGDataProvider.h>
#include <CoreGraphics/CGGeometry.h>
#include <CoreFoundation/CFArray.h>
#include <CoreFoundation/CFData.h>
#include <CoreFoundation/CFDictionary.h>

enum {

    kCGFontIndexMax = ((1 << 16) - 2),
    kCGFontIndexInvalid = ((1 << 16) - 1),

    kCGGlyphMax = kCGFontIndexMax
};

CG_EXTERN CFTypeID CGFontGetTypeID(void);
CG_EXTERN CGFontRef CGFontCreateWithPlatformFont(void *platformFontReference);
CG_EXTERN CGFontRef CGFontCreateWithDataProvider(CGDataProviderRef provider);
CG_EXTERN CGFontRef CGFontCreateWithFontName(CFStringRef name);
CG_EXTERN CGFontRef CGFontCreateCopyWithVariations(CGFontRef font, CFDictionaryRef variations);
CG_EXTERN CGFontRef CGFontRetain(CGFontRef font);
CG_EXTERN void CGFontRelease(CGFontRef font);
CG_EXTERN size_t CGFontGetNumberOfGlyphs(CGFontRef font);
CG_EXTERN int CGFontGetUnitsPerEm(CGFontRef font);
CG_EXTERN CFStringRef CGFontCopyPostScriptName(CGFontRef font);
CG_EXTERN CFStringRef CGFontCopyFullName(CGFontRef font);
CG_EXTERN int CGFontGetAscent(CGFontRef font);
CG_EXTERN int CGFontGetDescent(CGFontRef font);
CG_EXTERN int CGFontGetLeading(CGFontRef font);
CG_EXTERN int CGFontGetCapHeight(CGFontRef font);
CG_EXTERN int CGFontGetXHeight(CGFontRef font);
CG_EXTERN CGRect CGFontGetFontBBox(CGFontRef font);
CG_EXTERN CGFloat CGFontGetItalicAngle(CGFontRef font);
CG_EXTERN CGFloat CGFontGetStemV(CGFontRef font);
CG_EXTERN CFArrayRef CGFontCopyVariationAxes(CGFontRef font);
CG_EXTERN CFDictionaryRef CGFontCopyVariations(CGFontRef font);
CG_EXTERN bool CGFontGetGlyphAdvances(CGFontRef font, const CGGlyph glyphs[],size_t count, int advances[]);
CG_EXTERN bool CGFontGetGlyphBBoxes(CGFontRef font, const CGGlyph glyphs[],
    size_t count, CGRect bboxes[]);
CG_EXTERN CGGlyph CGFontGetGlyphWithGlyphName(CGFontRef font, CFStringRef name);
CG_EXTERN CFStringRef CGFontCopyGlyphNameForGlyph(CGFontRef font, CGGlyph glyph);
CG_EXTERN bool CGFontCanCreatePostScriptSubset(CGFontRef font, CGFontPostScriptFormat format);
CG_EXTERN CFDataRef CGFontCreatePostScriptSubset(CGFontRef font,
    CFStringRef subsetName, CGFontPostScriptFormat format,
    const CGGlyph glyphs[], size_t count, const CGGlyph encoding[256]);
CG_EXTERN CFDataRef CGFontCreatePostScriptEncoding(CGFontRef font, const CGGlyph encoding[256]);
CG_EXTERN CFArrayRef CGFontCopyTableTags(CGFontRef font);
CG_EXTERN CFDataRef CGFontCopyTableForTag(CGFontRef font, uint32_t tag);
CG_EXTERN const CFStringRef kCGFontVariationAxisName;
CG_EXTERN const CFStringRef kCGFontVariationAxisMinValue;
CG_EXTERN const CFStringRef kCGFontVariationAxisMaxValue;
CG_EXTERN const CFStringRef kCGFontVariationAxisDefaultValue;

enum {
    CGGlyphMin = 0,
    CGGlyphMax = kCGGlyphMax
};

#endif	/* CGFONT_H_ */
