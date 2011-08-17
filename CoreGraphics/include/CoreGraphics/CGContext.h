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
#ifndef CGCONTEXT_H_
#define CGCONTEXT_H_

typedef struct CGContext *CGContextRef;

#include <CoreGraphics/CGBase.h>
#include <CoreGraphics/CGAffineTransform.h>
#include <CoreGraphics/CGColor.h>
#include <CoreGraphics/CGColorSpace.h>
#include <CoreGraphics/CGFont.h>
#include <CoreGraphics/CGGradient.h>
#include <CoreGraphics/CGImage.h>
#include <CoreGraphics/CGPath.h>
#include <CoreGraphics/CGPattern.h>
#include <CoreGraphics/CGPDFDocument.h>
#include <CoreGraphics/CGShading.h>

enum CGLineJoin {
    kCGLineJoinMiter,
    kCGLineJoinRound,
    kCGLineJoinBevel
};
typedef enum CGLineJoin CGLineJoin;

enum CGLineCap {
    kCGLineCapButt,
    kCGLineCapRound,
    kCGLineCapSquare
};
typedef enum CGLineCap CGLineCap;

enum CGPathDrawingMode {
    kCGPathFill,
    kCGPathEOFill,
    kCGPathStroke,
    kCGPathFillStroke,
    kCGPathEOFillStroke
};
typedef enum CGPathDrawingMode CGPathDrawingMode;


enum CGTextDrawingMode {
    kCGTextFill,
    kCGTextStroke,
    kCGTextFillStroke,
    kCGTextInvisible,
    kCGTextFillClip,
    kCGTextStrokeClip,
    kCGTextFillStrokeClip,
    kCGTextClip
};
typedef enum CGTextDrawingMode CGTextDrawingMode;


enum CGTextEncoding {
    kCGEncodingFontSpecific,
    kCGEncodingMacRoman
};
typedef enum CGTextEncoding CGTextEncoding;


enum CGInterpolationQuality {
    kCGInterpolationDefault,		
    kCGInterpolationNone,		
    kCGInterpolationLow,		
    kCGInterpolationHigh		
};
typedef enum CGInterpolationQuality CGInterpolationQuality;

enum CGBlendMode {

    kCGBlendModeNormal,
    kCGBlendModeMultiply,
    kCGBlendModeScreen,
    kCGBlendModeOverlay,
    kCGBlendModeDarken,
    kCGBlendModeLighten,
    kCGBlendModeColorDodge,
    kCGBlendModeColorBurn,
    kCGBlendModeSoftLight,
    kCGBlendModeHardLight,
    kCGBlendModeDifference,
    kCGBlendModeExclusion,
    kCGBlendModeHue,
    kCGBlendModeSaturation,
    kCGBlendModeColor,
    kCGBlendModeLuminosity,
    kCGBlendModeClear,			
    kCGBlendModeCopy,			
    kCGBlendModeSourceIn,		
    kCGBlendModeSourceOut,		
    kCGBlendModeSourceAtop,		
    kCGBlendModeDestinationOver,	
    kCGBlendModeDestinationIn,		
    kCGBlendModeDestinationOut,		
    kCGBlendModeDestinationAtop,	
    kCGBlendModeXOR,			
    kCGBlendModePlusDarker,		
    kCGBlendModePlusLighter,

};
typedef enum CGBlendMode CGBlendMode;

CG_EXTERN CFTypeID CGContextGetTypeID(void);

CG_EXTERN void CGContextSaveGState(CGContextRef c);

CG_EXTERN void CGContextRestoreGState(CGContextRef c);

CG_EXTERN void CGContextScaleCTM(CGContextRef c, CGFloat sx, CGFloat sy);

CG_EXTERN void CGContextTranslateCTM(CGContextRef c, CGFloat tx, CGFloat ty);
CG_EXTERN void CGContextRotateCTM(CGContextRef c, CGFloat angle);

CG_EXTERN void CGContextConcatCTM(CGContextRef c, CGAffineTransform transform);

CG_EXTERN CGAffineTransform CGContextGetCTM(CGContextRef c);

CG_EXTERN void CGContextClear(CGContextRef c);

CG_EXTERN void CGContextSetLineWidth(CGContextRef c, CGFloat width);

CG_EXTERN void CGContextSetLineCap(CGContextRef c, CGLineCap cap);

CG_EXTERN void CGContextSetLineJoin(CGContextRef c, CGLineJoin join);

CG_EXTERN void CGContextSetMiterLimit(CGContextRef c, CGFloat limit);

CG_EXTERN void CGContextSetLineDash(CGContextRef c, CGFloat phase,
    const CGFloat lengths[], size_t count);

CG_EXTERN void CGContextSetFlatness(CGContextRef c, CGFloat flatness);

CG_EXTERN void CGContextSetAlpha(CGContextRef c, CGFloat alpha);

CG_EXTERN void CGContextSetBlendMode(CGContextRef context, CGBlendMode mode);

CG_EXTERN void CGContextBeginPath(CGContextRef c);

CG_EXTERN void CGContextMoveToPoint(CGContextRef c, CGFloat x, CGFloat y);

CG_EXTERN void CGContextAddLineToPoint(CGContextRef c, CGFloat x, CGFloat y);

CG_EXTERN void CGContextAddCurveToPoint(CGContextRef c, CGFloat cp1x,
    CGFloat cp1y, CGFloat cp2x, CGFloat cp2y, CGFloat x, CGFloat y);

CG_EXTERN void CGContextAddQuadCurveToPoint(CGContextRef c, CGFloat cpx,
    CGFloat cpy, CGFloat x, CGFloat y);

CG_EXTERN void CGContextClosePath(CGContextRef c);

CG_EXTERN void CGContextAddRect(CGContextRef c, CGRect rect);

CG_EXTERN void CGContextAddRects(CGContextRef c, const CGRect rects[], size_t count);

CG_EXTERN void CGContextAddLines(CGContextRef c, const CGPoint points[], size_t count);

CG_EXTERN void CGContextAddEllipseInRect(CGContextRef context, CGRect rect);

CG_EXTERN void CGContextAddArc(CGContextRef c, CGFloat x, CGFloat y,
    CGFloat radius, CGFloat startAngle, CGFloat endAngle, int clockwise);

CG_EXTERN void CGContextAddArcToPoint(CGContextRef c, CGFloat x1, CGFloat y1,
    CGFloat x2, CGFloat y2, CGFloat radius);

CG_EXTERN void CGContextAddPath(CGContextRef context, CGPathRef path);

CG_EXTERN void CGContextReplacePathWithStrokedPath(CGContextRef c);

CG_EXTERN bool CGContextIsPathEmpty(CGContextRef c);

CG_EXTERN CGPoint CGContextGetPathCurrentPoint(CGContextRef c);

CG_EXTERN CGRect CGContextGetPathBoundingBox(CGContextRef c);

CG_EXTERN bool CGContextPathContainsPoint(CGContextRef context, CGPoint point,
    CGPathDrawingMode mode);

CG_EXTERN void CGContextDrawPath(CGContextRef c, CGPathDrawingMode mode);

CG_EXTERN void CGContextFillPath(CGContextRef c);

CG_EXTERN void CGContextEOFillPath(CGContextRef c);

CG_EXTERN void CGContextStrokePath(CGContextRef c);

CG_EXTERN void CGContextFillRect(CGContextRef c, CGRect rect);

CG_EXTERN void CGContextFillRects(CGContextRef c, const CGRect rects[], size_t count);

CG_EXTERN void CGContextStrokeRect(CGContextRef c, CGRect rect);

CG_EXTERN void CGContextStrokeRectWithWidth(CGContextRef c, CGRect rect, CGFloat width);

CG_EXTERN void CGContextClearRect(CGContextRef c, CGRect rect);

CG_EXTERN void CGContextFillEllipseInRect(CGContextRef context, CGRect rect);

CG_EXTERN void CGContextStrokeEllipseInRect(CGContextRef context, CGRect rect);

CG_EXTERN void CGContextStrokeLineSegments(CGContextRef c, const CGPoint points[], size_t count);

CG_EXTERN void CGContextClip(CGContextRef c);

CG_EXTERN void CGContextEOClip(CGContextRef c);

CG_EXTERN void CGContextClipToMask(CGContextRef c, CGRect rect, CGImageRef mask);

CG_EXTERN CGRect CGContextGetClipBoundingBox(CGContextRef c);

CG_EXTERN void CGContextClipToRect(CGContextRef c, CGRect rect);

CG_EXTERN void CGContextClipToRects(CGContextRef c, const CGRect rects[], size_t count);

CG_EXTERN void CGContextSetFillColorWithColor(CGContextRef c, CGColorRef color);

CG_EXTERN void CGContextSetStrokeColorWithColor(CGContextRef c, CGColorRef color);

CG_EXTERN void CGContextSetFillColorSpace(CGContextRef context, CGColorSpaceRef space);

CG_EXTERN void CGContextSetStrokeColorSpace(CGContextRef context, CGColorSpaceRef space);

CG_EXTERN void CGContextSetFillColor(CGContextRef context, const CGFloat components[]);

CG_EXTERN void CGContextSetStrokeColor(CGContextRef context, const CGFloat components[]);

CG_EXTERN void CGContextSetFillPattern(CGContextRef context, CGPatternRef pattern, const CGFloat components[]);

CG_EXTERN void CGContextSetStrokePattern(CGContextRef context, CGPatternRef pattern, const CGFloat components[]);

CG_EXTERN void CGContextSetPatternPhase(CGContextRef context, CGSize phase);

CG_EXTERN void CGContextSetGrayFillColor(CGContextRef context, CGFloat gray, CGFloat alpha);

CG_EXTERN void CGContextSetGrayStrokeColor(CGContextRef context, CGFloat gray, CGFloat alpha);

CG_EXTERN void CGContextSetRGBFillColor(CGContextRef context, CGFloat red,
    CGFloat green, CGFloat blue, CGFloat alpha);

CG_EXTERN void CGContextSetRGBStrokeColor(CGContextRef context, CGFloat red,
    CGFloat green, CGFloat blue, CGFloat alpha);

CG_EXTERN void CGContextSetCMYKFillColor(CGContextRef context, CGFloat cyan,
    CGFloat magenta, CGFloat yellow, CGFloat black, CGFloat alpha);

CG_EXTERN void CGContextSetCMYKStrokeColor(CGContextRef context, CGFloat cyan,
    CGFloat magenta, CGFloat yellow, CGFloat black, CGFloat alpha);

CG_EXTERN void CGContextSetRenderingIntent(CGContextRef context,
    CGColorRenderingIntent intent);

CG_EXTERN void CGContextDrawImage(CGContextRef c, CGRect rect, CGImageRef image);

CG_EXTERN void CGContextDrawTiledImage(CGContextRef c, CGRect rect, CGImageRef image);

CG_EXTERN CGInterpolationQuality CGContextGetInterpolationQuality(CGContextRef
    context);

CG_EXTERN void CGContextSetInterpolationQuality(CGContextRef context,
    CGInterpolationQuality quality);

CG_EXTERN void CGContextSetShadowWithColor(CGContextRef context, CGSize offset,
    CGFloat blur, CGColorRef color);

CG_EXTERN void CGContextSetShadow(CGContextRef context, CGSize offset, CGFloat blur);

CG_EXTERN void CGContextDrawLinearGradient(CGContextRef context,
    CGGradientRef gradient, CGPoint startPoint, CGPoint endPoint,
    CGGradientDrawingOptions options);

CG_EXTERN void CGContextDrawRadialGradient(CGContextRef context,
    CGGradientRef gradient, CGPoint startCenter, CGFloat startRadius,
    CGPoint endCenter, CGFloat endRadius, CGGradientDrawingOptions options);

CG_EXTERN void CGContextDrawShading(CGContextRef context, CGShadingRef shading);

CG_EXTERN void CGContextSetCharacterSpacing(CGContextRef context, CGFloat spacing);

CG_EXTERN void CGContextSetTextPosition(CGContextRef c, CGFloat x, CGFloat y);

CG_EXTERN CGPoint CGContextGetTextPosition(CGContextRef context);

CG_EXTERN void CGContextSetTextMatrix(CGContextRef c, CGAffineTransform t);

CG_EXTERN CGAffineTransform CGContextGetTextMatrix(CGContextRef c);

CG_EXTERN void CGContextSetTextDrawingMode(CGContextRef c, CGTextDrawingMode mode);

CG_EXTERN void CGContextSetFont(CGContextRef c, CGFontRef font);

CG_EXTERN void CGContextSetFontSize(CGContextRef c, CGFloat size);

CG_EXTERN void CGContextSelectFont(CGContextRef c, const char *name,
    CGFloat size, CGTextEncoding textEncoding);

CG_EXTERN void CGContextShowGlyphsAtPositions(CGContextRef context,
    const CGGlyph glyphs[], const CGPoint positions[], size_t count);

CG_EXTERN void CGContextShowText(CGContextRef c, const char *string,
    size_t length) ;
CG_EXTERN void CGContextShowTextAtPoint(CGContextRef c, CGFloat x, CGFloat y,
    const char *string, size_t length);

CG_EXTERN void CGContextShowGlyphs(CGContextRef c, const CGGlyph g[],
    size_t count);

CG_EXTERN void CGContextShowGlyphsAtPoint(CGContextRef context, CGFloat x,
    CGFloat y, const CGGlyph glyphs[], size_t count);

CG_EXTERN void CGContextShowGlyphsWithAdvances(CGContextRef c,
    const CGGlyph glyphs[], const CGSize advances[], size_t count);

CG_EXTERN void CGContextDrawPDFPage(CGContextRef c, CGPDFPageRef page);

CG_EXTERN void CGContextDrawPDFDocument(CGContextRef c, CGRect rect,
    CGPDFDocumentRef document, int page);

CG_EXTERN void CGContextBeginPage(CGContextRef c, const CGRect *mediaBox);

CG_EXTERN void CGContextEndPage(CGContextRef c);

CG_EXTERN CGContextRef CGContextRetain(CGContextRef c);

CG_EXTERN void CGContextRelease(CGContextRef c);

CG_EXTERN void CGContextFlush(CGContextRef c);

CG_EXTERN void CGContextSynchronize(CGContextRef c);

CG_EXTERN void CGContextSetShouldAntialias(CGContextRef c, bool shouldAntialias);

CG_EXTERN void CGContextSetAllowsAntialiasing(CGContextRef context, bool allowsAntialiasing);

CG_EXTERN void CGContextSetShouldSmoothFonts(CGContextRef c, bool shouldSmoothFonts);

CG_EXTERN void CGContextBeginTransparencyLayer(CGContextRef context, CFDictionaryRef auxiliaryInfo);

CG_EXTERN void CGContextBeginTransparencyLayerWithRect(CGContextRef context, CGRect rect, CFDictionaryRef auxiliaryInfo);

CG_EXTERN void CGContextEndTransparencyLayer(CGContextRef context);

CG_EXTERN CGAffineTransform CGContextGetUserSpaceToDeviceSpaceTransform(CGContextRef context);

CG_EXTERN CGPoint CGContextConvertPointToDeviceSpace(CGContextRef context, CGPoint point);

CG_EXTERN CGPoint CGContextConvertPointToUserSpace(CGContextRef context, CGPoint point);

CG_EXTERN CGSize CGContextConvertSizeToDeviceSpace(CGContextRef context, CGSize size);

CG_EXTERN CGSize CGContextConvertSizeToUserSpace(CGContextRef context, CGSize size);

CG_EXTERN CGRect CGContextConvertRectToDeviceSpace(CGContextRef context, CGRect rect);

CG_EXTERN CGRect CGContextConvertRectToUserSpace(CGContextRef context, CGRect rect);

#endif	/* CGCONTEXT_H_ */
