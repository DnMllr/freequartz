#define CG_EXTERN extern
#define CG_INLINE inline

typedef float CGFloat;
#define CGFLOAT_MIN FLT_MIN
#define CGFLOAT_MAX FLT_MAX
#define CGFLOAT_IS_DOUBLE 0
#define CGFLOAT_DEFINED 1

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//Forward declarations
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
typedef struct CGContext *CGContextRef;
typedef struct CGAffineTransform CGAffineTransform;


//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//CGType
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
void* CGTypeCreateSingleton(CFTypeID typeID, void *memory);

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//CGFunction
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

typedef struct CGFunction *CGFunctionRef;

typedef void (*CGFunctionEvaluateCallback)(void *info, const CGFloat *in,
    CGFloat *out);
typedef void (*CGFunctionReleaseInfoCallback)(void *info);

struct CGFunctionCallbacks {
    unsigned int version;
    CGFunctionEvaluateCallback evaluate;
    CGFunctionReleaseInfoCallback releaseInfo;
};
typedef struct CGFunctionCallbacks CGFunctionCallbacks;

CG_EXTERN CFTypeID CGFunctionGetTypeID(void);
CG_EXTERN CGFunctionRef CGFunctionCreate(void *info, size_t domainDimension,
    const CGFloat *domain, size_t rangeDimension, const CGFloat *range,
    const CGFunctionCallbacks *callbacks);
CG_EXTERN CGFunctionRef CGFunctionRetain(CGFunctionRef function);
CG_EXTERN void CGFunctionRelease(CGFunctionRef function);

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//CGGeometry
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

struct CGPoint {
  CGFloat x;
  CGFloat y;
};
typedef struct CGPoint CGPoint;


struct CGSize {
  CGFloat width;
  CGFloat height;
};
typedef struct CGSize CGSize;


struct CGRect {
  CGPoint origin;
  CGSize size;
};
typedef struct CGRect CGRect;


enum CGRectEdge {
  CGRectMinXEdge, CGRectMinYEdge, CGRectMaxXEdge, CGRectMaxYEdge
};
typedef enum CGRectEdge CGRectEdge;


CG_EXTERN const CGPoint CGPointZero;
CG_EXTERN const CGSize CGSizeZero;
CG_EXTERN const CGRect CGRectZero;
CG_EXTERN const CGRect CGRectNull;
CG_EXTERN const CGRect CGRectInfinite;

CG_INLINE CGPoint CGPointMake(CGFloat x, CGFloat y);
CG_INLINE CGSize CGSizeMake(CGFloat width, CGFloat height);
CG_INLINE CGRect CGRectMake(CGFloat x, CGFloat y, CGFloat width, CGFloat height);
CG_EXTERN CGFloat CGRectGetMinX(CGRect rect);
CG_EXTERN CGFloat CGRectGetMidX(CGRect rect);
CG_EXTERN CGFloat CGRectGetMaxX(CGRect rect);
CG_EXTERN CGFloat CGRectGetMinY(CGRect rect);
CG_EXTERN CGFloat CGRectGetMidY(CGRect rect);
CG_EXTERN CGFloat CGRectGetMaxY(CGRect rect);
CG_EXTERN CGFloat CGRectGetWidth(CGRect rect);
CG_EXTERN CGFloat CGRectGetHeight(CGRect rect);
CG_EXTERN bool CGPointEqualToPoint(CGPoint point1, CGPoint point2);
CG_EXTERN bool CGSizeEqualToSize(CGSize size1, CGSize size2);
CG_EXTERN bool CGRectEqualToRect(CGRect rect1, CGRect rect2);
CG_EXTERN CGRect CGRectStandardize(CGRect rect);
CG_EXTERN bool CGRectIsEmpty(CGRect rect);
CG_EXTERN bool CGRectIsNull(CGRect rect);
CG_EXTERN bool CGRectIsInfinite(CGRect rect);
CG_EXTERN CGRect CGRectInset(CGRect rect, CGFloat dx, CGFloat dy);
CG_EXTERN CGRect CGRectIntegral(CGRect rect);
CG_EXTERN CGRect CGRectUnion(CGRect r1, CGRect r2);
CG_EXTERN CGRect CGRectIntersection(CGRect r1, CGRect r2);
CG_EXTERN CGRect CGRectOffset(CGRect rect, CGFloat dx, CGFloat dy);
CG_EXTERN void CGRectDivide(CGRect rect, CGRect *slice, CGRect *remainder,
  CGFloat amount, CGRectEdge edge);
CG_EXTERN bool CGRectContainsPoint(CGRect rect, CGPoint point);
CG_EXTERN bool CGRectContainsRect(CGRect rect1, CGRect rect2);
CG_EXTERN bool CGRectIntersectsRect(CGRect rect1, CGRect rect2);
CG_EXTERN CFDictionaryRef CGPointCreateDictionaryRepresentation(CGPoint point);
CG_EXTERN bool CGPointMakeWithDictionaryRepresentation(CFDictionaryRef dict,
  CGPoint *point);
CG_EXTERN CFDictionaryRef CGSizeCreateDictionaryRepresentation(CGSize size);
CG_EXTERN bool CGSizeMakeWithDictionaryRepresentation(CFDictionaryRef dict,
  CGSize *size);
CG_EXTERN CFDictionaryRef CGRectCreateDictionaryRepresentation(CGRect);
CG_EXTERN bool CGRectMakeWithDictionaryRepresentation(CFDictionaryRef dict,
  CGRect *rect);


CG_INLINE CGPoint
CGPointMake(CGFloat x, CGFloat y)
{
  CGPoint p; p.x = x; p.y = y; return p;
}

CG_INLINE CGSize
CGSizeMake(CGFloat width, CGFloat height)
{
  CGSize size; size.width = width; size.height = height; return size;
}

CG_INLINE CGRect
CGRectMake(CGFloat x, CGFloat y, CGFloat width, CGFloat height)
{
  CGRect rect;
  rect.origin.x = x; rect.origin.y = y;
  rect.size.width = width; rect.size.height = height;
  return rect;
}

CG_INLINE bool
__CGPointEqualToPoint(CGPoint point1, CGPoint point2)
{
  return point1.x == point2.x && point1.y == point2.y;
}
#define CGPointEqualToPoint __CGPointEqualToPoint

CG_INLINE bool
__CGSizeEqualToSize(CGSize size1, CGSize size2)
{
  return size1.width == size2.width && size1.height == size2.height;
}
#define CGSizeEqualToSize __CGSizeEqualToSize

struct CGAffineTransform {
  CGFloat a, b, c, d;
  CGFloat tx, ty;
};

CG_EXTERN const CGAffineTransform CGAffineTransformIdentity;

/* functions */
CG_EXTERN CGAffineTransform CGAffineTransformMake (CGFloat a, CGFloat b,
CGFloat c, CGFloat d, CGFloat tx, CGFloat ty);

CG_EXTERN CGAffineTransform CGAffineTransformMakeRotation(CGFloat angle);

CG_EXTERN CGAffineTransform CGAffineTransformMakeScale(CGFloat sx, CGFloat sy);

CG_EXTERN CGAffineTransform CGAffineTransformMakeTranslation(CGFloat tx, CGFloat ty);

CG_EXTERN CGAffineTransform CGAffineTransformTranslate(CGAffineTransform t, 
CGFloat tx, CGFloat ty);

CG_EXTERN CGAffineTransform CGAffineTransformScale(CGAffineTransform t,
  CGFloat sx, CGFloat sy);

CG_EXTERN CGAffineTransform CGAffineTransformRotate(CGAffineTransform t,
  CGFloat angle);

CG_EXTERN CGAffineTransform CGAffineTransformInvert(CGAffineTransform t);

CG_EXTERN CGAffineTransform CGAffineTransformConcat(CGAffineTransform t1,
  CGAffineTransform t2);
  

CG_EXTERN bool CGAffineTransformEqualToTransform(CGAffineTransform t1,
  CGAffineTransform t2);


CG_EXTERN CGPoint CGPointApplyAffineTransform(CGPoint point,
  CGAffineTransform t);


CG_EXTERN CGSize CGSizeApplyAffineTransform(CGSize size, CGAffineTransform t);


CG_EXTERN CGRect CGRectApplyAffineTransform(CGRect rect, CGAffineTransform t);


CG_EXTERN bool CGAffineTransformIsIdentity(CGAffineTransform t);

CG_INLINE CGAffineTransform __CGAffineTransformMake(CGFloat a, CGFloat b, 
 CGFloat c, CGFloat d, CGFloat tx, CGFloat ty)
{
  CGAffineTransform at;
  at.a = a; at.b = b; at.c = c; at.d = d; 
  at.tx = tx; at.ty = ty;
  return at;
}
#define CGAffineTransformMake __CGAffineTransformMake

CG_INLINE CGPoint
__CGPointApplyAffineTransform(CGPoint point, CGAffineTransform t)
{
  CGPoint pt;
  pt.x = (CGFloat)((double)pt.a * point.x + (double)pt.c * point.y + pt.tx);
  pt.y = (CGFloat)((double)pt.b * point.x + (double)pt.d * point.y + pt.ty);
  return pt;
}
#define CGPointApplyAffineTransform __CGPointApplyAffineTransform

CG_INLINE CGSize
__CGSizeApplyAffineTransform(CGSize size, CGAffineTransform at)
{
  CGSize sz;
  sz.width = (CGFloat)((double)at.a * size.width + (double)at.c * size.height);
  sz.height = (CGFloat)((double)at.b * size.width + (double)at.d * size.height);
  return sz;
}
#define CGSizeApplyAffineTransform __CGSizeApplyAffineTransform

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//CGDataProvider
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
typedef struct CGDataProvider *CGDataProviderRef;

typedef size_t (*CGDataProviderGetBytesCallback)(void *info, void *buffer, size_t count);

typedef off_t (*CGDataProviderSkipForwardCallback)(void *info, off_t count);

typedef void (*CGDataProviderRewindCallback)(void *info);

typedef void (*CGDataProviderReleaseInfoCallback)(void *info);

struct CGDataProviderSequentialCallbacks {
    unsigned int version;
    CGDataProviderGetBytesCallback getBytes;
    CGDataProviderSkipForwardCallback skipForward;
    CGDataProviderRewindCallback rewind;
    CGDataProviderReleaseInfoCallback releaseInfo;
};
typedef struct CGDataProviderSequentialCallbacks
    CGDataProviderSequentialCallbacks;


typedef const void *(*CGDataProviderGetBytePointerCallback)(void *info);


typedef void (*CGDataProviderReleaseBytePointerCallback)(void *info,
    const void *pointer);


typedef size_t (*CGDataProviderGetBytesAtPositionCallback)(void *info,
    void *buffer, off_t position, size_t count);


struct CGDataProviderDirectCallbacks {
    unsigned int version;
    CGDataProviderGetBytePointerCallback getBytePointer;
    CGDataProviderReleaseBytePointerCallback releaseBytePointer;
    CGDataProviderGetBytesAtPositionCallback getBytesAtPosition;
    CGDataProviderReleaseInfoCallback releaseInfo;
};
typedef struct CGDataProviderDirectCallbacks CGDataProviderDirectCallbacks;


CG_EXTERN CFTypeID CGDataProviderGetTypeID(void);

CG_EXTERN CGDataProviderRef	CGDataProviderCreateWithCopyOfData(void *data, size_t size);

CG_EXTERN CGDataProviderRef CGDataProviderCreateSequential(void *info,
    const CGDataProviderSequentialCallbacks *callbacks);

CG_EXTERN CGDataProviderRef CGDataProviderCreateDirect(void *info, off_t size,
    const CGDataProviderDirectCallbacks *callbacks);
    
typedef void (*CGDataProviderReleaseDataCallback)(void *info, const void *data,
    size_t size);
    
CG_EXTERN CGDataProviderRef CGDataProviderCreateWithData(void *info,
    const void *data, size_t size,
    CGDataProviderReleaseDataCallback releaseData);

CG_EXTERN CGDataProviderRef CGDataProviderCreateWithCFData(CFDataRef data);

//CG_EXTERN CGDataProviderRef CGDataProviderCreateWithURL(CFURLRef url);

CG_EXTERN CGDataProviderRef
    CGDataProviderCreateWithFilename(const char *filename);

CG_EXTERN CGDataProviderRef CGDataProviderRetain(CGDataProviderRef provider);

CG_EXTERN void CGDataProviderRelease(CGDataProviderRef provider);

//CG_EXTERN CFDataRef CGDataProviderCopyData(CGDataProviderRef provider);

typedef void (*CGDataProviderSkipBytesCallback)(void *info, size_t count);

struct CGDataProviderCallbacks {
    CGDataProviderGetBytesCallback getBytes;
    CGDataProviderSkipBytesCallback skipBytes;
    CGDataProviderRewindCallback rewind;
    CGDataProviderReleaseInfoCallback releaseProvider;
};
typedef struct CGDataProviderCallbacks CGDataProviderCallbacks;


typedef size_t (*CGDataProviderGetBytesAtOffsetCallback)(void *info,
    void *buffer, size_t offset, size_t count);

struct CGDataProviderDirectAccessCallbacks {
    CGDataProviderGetBytePointerCallback getBytePointer;
    CGDataProviderReleaseBytePointerCallback releaseBytePointer;
    CGDataProviderGetBytesAtOffsetCallback getBytes;
    CGDataProviderReleaseInfoCallback releaseProvider;
};
typedef struct CGDataProviderDirectAccessCallbacks
    CGDataProviderDirectAccessCallbacks;


CG_EXTERN CGDataProviderRef CGDataProviderCreate(void *info,
    const CGDataProviderCallbacks *callbacks);


CG_EXTERN CGDataProviderRef CGDataProviderCreateDirectAccess(void *info,
    size_t size, const CGDataProviderDirectAccessCallbacks *callbacks);

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//CGDefaults
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$


//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//CGLibrary
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
CG_EXTERN void initialize_dylib_paths(void);
CG_EXTERN void* CGLibraryLoadFunction(const char* libName, const char* symName);
CG_EXTERN void* load_function(CFArrayRef paths, const char* fullLibName, const char* symName);

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//CGPattern
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

typedef struct CGPattern *CGPatternRef;

enum CGPatternTiling {
    kCGPatternTilingNoDistortion,
    kCGPatternTilingConstantSpacingMinimalDistortion,
    kCGPatternTilingConstantSpacing
};
typedef enum CGPatternTiling CGPatternTiling;

typedef void (*CGPatternDrawPatternCallback)(void *info, CGContextRef c);
typedef void (*CGPatternReleaseInfoCallback)(void *info);

struct CGPatternCallbacks {
    unsigned int version;
    CGPatternDrawPatternCallback drawPattern;
    CGPatternReleaseInfoCallback releaseInfo;
};
typedef struct CGPatternCallbacks CGPatternCallbacks;


CG_EXTERN CFTypeID CGPatternGetTypeID(void);

CG_EXTERN CGPatternRef CGPatternCreate(void *info, CGRect bounds,
    CGAffineTransform matrix, CGFloat xStep, CGFloat yStep,
    CGPatternTiling tiling, bool isColored,
    const CGPatternCallbacks *callbacks);

CG_EXTERN CGPatternRef CGPatternRetain(CGPatternRef pattern);

CG_EXTERN void CGPatternRelease(CGPatternRef pattern);

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//CGColorSpace
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
typedef struct CGColorSpace *CGColorSpaceRef;

/* constants. */
CG_EXTERN CFStringRef kCGColorSpaceGenericGray;
CG_EXTERN CFStringRef kCGColorSpaceGenericRGB;
CG_EXTERN CFStringRef kCGColorSpaceGenericCMYK;
CG_EXTERN CFStringRef kCGColorSpaceGenericRGBLinear;
CG_EXTERN CFStringRef kCGColorSpaceAdobeRGB1998;
CG_EXTERN CFStringRef kCGColorSpaceSRGB;
CG_EXTERN CFStringRef kCGColorSpaceGenericGrayGamma2_2;

enum CGColorSpaceModel {
    kCGColorSpaceModelUnknown = -1,
    kCGColorSpaceModelMonochrome,
    kCGColorSpaceModelRGB,
    kCGColorSpaceModelCMYK,
    kCGColorSpaceModelLab,
    kCGColorSpaceModelDeviceN,
    kCGColorSpaceModelIndexed,
    kCGColorSpaceModelPattern
};
typedef enum CGColorSpaceModel CGColorSpaceModel;


enum CGColorRenderingIntent {
    kCGRenderingIntentDefault,
    kCGRenderingIntentAbsoluteColorimetric,
    kCGRenderingIntentRelativeColorimetric,
    kCGRenderingIntentPerceptual,
    kCGRenderingIntentSaturation
};
typedef enum CGColorRenderingIntent CGColorRenderingIntent;


CG_EXTERN CGColorSpaceRef CGColorSpaceCreateDeviceGray(void);

CG_EXTERN CGColorSpaceRef CGColorSpaceCreateDeviceRGB(void);

CG_EXTERN CGColorSpaceRef CGColorSpaceCreateDeviceCMYK(void);

CG_EXTERN CGColorSpaceRef CGColorSpaceCreateCalibratedGray(const CGFloat
    whitePoint[3], const CGFloat blackPoint[3], CGFloat gamma);

CG_EXTERN CGColorSpaceRef CGColorSpaceCreateCalibratedRGB(const CGFloat
    whitePoint[3], const CGFloat blackPoint[3], const CGFloat gamma[3],
    const CGFloat matrix[9]);
    
CG_EXTERN CGColorSpaceRef CGColorSpaceCreateLab(const CGFloat whitePoint[3],
    const CGFloat blackPoint[3], const CGFloat range[4]);

CG_EXTERN CGColorSpaceRef CGColorSpaceCreateICCBased(size_t nComponents,
    const CGFloat *range, CGDataProviderRef profile,
    CGColorSpaceRef alternate);

CG_EXTERN CGColorSpaceRef CGColorSpaceCreateIndexed(CGColorSpaceRef baseSpace,
    size_t lastIndex, const unsigned char *colorTable);

CG_EXTERN CGColorSpaceRef CGColorSpaceCreatePattern(CGColorSpaceRef baseSpace);

CG_EXTERN CGColorSpaceRef CGColorSpaceCreateWithPlatformColorSpace(void *ref);

CG_EXTERN CGColorSpaceRef CGColorSpaceCreateWithName(CFStringRef name);

CG_EXTERN CGColorSpaceRef CGColorSpaceRetain(CGColorSpaceRef space);

CG_EXTERN void CGColorSpaceRelease(CGColorSpaceRef space);

CG_EXTERN CFTypeID CGColorSpaceGetTypeID(void);

CG_EXTERN size_t CGColorSpaceGetNumberOfComponents(CGColorSpaceRef space);

CG_EXTERN CGColorSpaceModel CGColorSpaceGetModel(CGColorSpaceRef space);

CG_EXTERN CGColorSpaceRef CGColorSpaceGetBaseColorSpace(CGColorSpaceRef space);

CG_EXTERN size_t CGColorSpaceGetColorTableCount(CGColorSpaceRef space);

CG_EXTERN void CGColorSpaceGetColorTable(CGColorSpaceRef space, uint8_t *table);

CG_EXTERN CFDataRef CGColorSpaceCopyICCProfile(CGColorSpaceRef space);

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//CGColor
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
typedef struct CGColor *CGColorRef;

CG_EXTERN const CFStringRef kCGColorWhite;
CG_EXTERN const CFStringRef kCGColorBlack;
CG_EXTERN const CFStringRef kCGColorClear;
CG_EXTERN CGColorRef CGColorGetConstantColor(CFStringRef colorName);
CG_EXTERN void CGColorRelease(CGColorRef color);
CG_EXTERN CGColorRef CGColorRetain(CGColorRef color);
CG_EXTERN CGColorRef CGColorCreate(CGColorSpaceRef space,
    const CGFloat components[]);
CG_EXTERN CGColorRef CGColorCreateCopy(CGColorRef color);
CG_EXTERN CGColorRef CGColorCreateGenericGray(CGFloat gray, CGFloat alpha);
CG_EXTERN CGColorRef CGColorCreateGenericRGB(CGFloat red, CGFloat green,
    CGFloat blue, CGFloat alpha);
CG_EXTERN CGColorRef CGColorCreateGenericCMYK(CGFloat cyan, CGFloat magenta,
    CGFloat yellow, CGFloat black, CGFloat alpha);
CG_EXTERN CGColorRef CGColorCreateCopyWithAlpha(CGColorRef color,
    CGFloat alpha);
CG_EXTERN CGColorRef CGColorCreateWithPattern(CGColorSpaceRef space,
    CGPatternRef pattern, const CGFloat components[]);
CG_EXTERN bool CGColorEqualToColor(CGColorRef color1, CGColorRef color2);
CG_EXTERN CGFloat CGColorGetAlpha(CGColorRef color);
CG_EXTERN CGColorSpaceRef CGColorGetColorSpace(CGColorRef color);
CG_EXTERN const CGFloat *CGColorGetComponents(CGColorRef color);
CG_EXTERN size_t CGColorGetNumberOfComponents(CGColorRef color);
CG_EXTERN CGPatternRef CGColorGetPattern(CGColorRef color);
CG_EXTERN CFTypeID CGColorGetTypeID(void);



//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//CGFont
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

typedef struct CGFont *CGFontRef;

typedef unsigned short CGFontIndex;

typedef CGFontIndex CGGlyph;

enum CGFontPostScriptFormat {
    kCGFontPostScriptFormatType1 = 1,
    kCGFontPostScriptFormatType3 = 3,
    kCGFontPostScriptFormatType42 = 42
};
typedef enum CGFontPostScriptFormat CGFontPostScriptFormat;

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
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//CGGradient
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
typedef struct CGGradient *CGGradientRef;

enum {
    kCGGradientDrawsBeforeStartLocation = (1 << 0),
    kCGGradientDrawsAfterEndLocation = (1 << 1)
};
typedef uint32_t CGGradientDrawingOptions;

CG_EXTERN CFTypeID CGGradientGetTypeID(void);
CG_EXTERN CGGradientRef CGGradientCreateWithColorComponents(CGColorSpaceRef
    space, const CGFloat components[], const CGFloat locations[], size_t count);
CG_EXTERN CGGradientRef CGGradientCreateWithColors(CGColorSpaceRef space,
    CFArrayRef colors, const CGFloat locations[]);
CG_EXTERN CGGradientRef CGGradientRetain(CGGradientRef gradient);
CG_EXTERN void CGGradientRelease(CGGradientRef gradient);

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//CGImage
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
typedef struct CGImage *CGImageRef;

enum CGImageAlphaInfo {
    kCGImageAlphaNone,               /* For example, RGB. */
    kCGImageAlphaPremultipliedLast,  /* For example, premultiplied RGBA */
    kCGImageAlphaPremultipliedFirst, /* For example, premultiplied ARGB */
    kCGImageAlphaLast,               /* For example, non-premultiplied RGBA */
    kCGImageAlphaFirst,              /* For example, non-premultiplied ARGB */
    kCGImageAlphaNoneSkipLast,       /* For example, RBGX. */
    kCGImageAlphaNoneSkipFirst,      /* For example, XRGB. */
    kCGImageAlphaOnly                /* No color data, alpha data only */
};
typedef enum CGImageAlphaInfo CGImageAlphaInfo;

enum {
    kCGBitmapAlphaInfoMask = 0x1F,
    kCGBitmapFloatComponents = (1 << 8),
    
    kCGBitmapByteOrderMask = 0x7000,
    kCGBitmapByteOrderDefault = (0 << 12),
    kCGBitmapByteOrder16Little = (1 << 12),
    kCGBitmapByteOrder32Little = (2 << 12),
    kCGBitmapByteOrder16Big = (3 << 12),
    kCGBitmapByteOrder32Big = (4 << 12)
};
typedef uint32_t CGBitmapInfo;

#ifdef __BIG_ENDIAN__
#define kCGBitmapByteOrder16Host kCGBitmapByteOrder16Big
#define kCGBitmapByteOrder32Host kCGBitmapByteOrder32Big
#else 
#define kCGBitmapByteOrder16Host kCGBitmapByteOrder16Little
#define kCGBitmapByteOrder32Host kCGBitmapByteOrder32Little
#endif

CG_EXTERN CFTypeID CGImageGetTypeID(void);
CG_EXTERN CGImageRef CGImageCreate(size_t width, size_t height,
    size_t bitsPerComponent, size_t bitsPerPixel, size_t bytesPerRow,
    CGColorSpaceRef space, CGBitmapInfo bitmapInfo, CGDataProviderRef provider,
    const CGFloat decode[], bool shouldInterpolate,
    CGColorRenderingIntent intent);
CG_EXTERN CGImageRef CGImageMaskCreate(size_t width, size_t height,
    size_t bitsPerComponent, size_t bitsPerPixel, size_t bytesPerRow,
    CGDataProviderRef provider, const CGFloat decode[], bool shouldInterpolate);
CG_EXTERN CGImageRef CGImageCreateCopy(CGImageRef image);
CG_EXTERN CGImageRef CGImageCreateWithJPEGDataProvider(CGDataProviderRef
    source, const CGFloat decode[], bool shouldInterpolate,
    CGColorRenderingIntent intent);
CG_EXTERN CGImageRef CGImageCreateWithPNGDataProvider(CGDataProviderRef source,
    const CGFloat decode[], bool shouldInterpolate,
    CGColorRenderingIntent intent);
CG_EXTERN CGImageRef CGImageCreateWithImageInRect(CGImageRef image, CGRect rect);
CG_EXTERN CGImageRef CGImageCreateWithMask(CGImageRef image, CGImageRef mask);
CG_EXTERN CGImageRef CGImageCreateWithMaskingColors(CGImageRef image,
    const CGFloat components[]);
CG_EXTERN CGImageRef CGImageCreateCopyWithColorSpace(CGImageRef image,
    CGColorSpaceRef space);
CG_EXTERN CGImageRef CGImageRetain(CGImageRef image);
CG_EXTERN void CGImageRelease(CGImageRef image);
CG_EXTERN bool CGImageIsMask(CGImageRef image);
CG_EXTERN size_t CGImageGetWidth(CGImageRef image);
CG_EXTERN size_t CGImageGetHeight(CGImageRef image);
CG_EXTERN size_t CGImageGetBitsPerComponent(CGImageRef image);
CG_EXTERN size_t CGImageGetBitsPerPixel(CGImageRef image);
CG_EXTERN size_t CGImageGetBytesPerRow(CGImageRef image);
CG_EXTERN CGColorSpaceRef CGImageGetColorSpace(CGImageRef image);
CG_EXTERN CGImageAlphaInfo CGImageGetAlphaInfo(CGImageRef image);
CG_EXTERN CGDataProviderRef CGImageGetDataProvider(CGImageRef image);
CG_EXTERN const CGFloat *CGImageGetDecode(CGImageRef image);
CG_EXTERN bool CGImageGetShouldInterpolate(CGImageRef image);
CG_EXTERN CGColorRenderingIntent CGImageGetRenderingIntent(CGImageRef image);
CG_EXTERN CGBitmapInfo CGImageGetBitmapInfo(CGImageRef image);

//Private
typedef struct CGImage CGImage, *CGImageRef;
typedef struct CGImageJPEGRep CGImageJPEGRep, *CGImageJPEGRepRef;
typedef struct CGImageEPSRep CGImageEPSRep, *CGImageEPSRepRef;

struct CGImageJPEGRep {

	signed long refcount;			     //0x00
	CGDataProviderRef provider;		 //0x04
};

struct CGImageEPSRep {

	signed long refcount;			    //0x00
	CGDataProviderRef provider;		//0x04
	CGImageRef image;				      //0x08
};

CG_EXTERN CGImageRef CGImageCreateCopyWithJPEGSource(CGImageRef image, CGDataProviderRef provider);
CG_EXTERN CGImageJPEGRepRef CGImageJPEGRepRetain(CGImageJPEGRepRef imageJPEG);
CG_EXTERN void CGImageJPEGRepRelease(CGImageJPEGRepRef imageJPEG);
CG_EXTERN CGImageJPEGRepRef CGImageJPEGRepCreate(CGDataProviderRef provider);
CG_EXTERN CGImageEPSRepRef CGImageEPSRepRetain(CGImageEPSRepRef imageEPS);
CG_EXTERN void CGImageEPSRepRelease(CGImageEPSRepRef imageEPS);

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//CGPath
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
typedef struct CGPath *CGMutablePathRef;
typedef const struct CGPath *CGPathRef;

CG_EXTERN CFTypeID CGPathGetTypeID(void);
CG_EXTERN CGMutablePathRef CGPathCreateMutable(void);
CG_EXTERN CGPathRef CGPathCreateCopy(CGPathRef path);
CG_EXTERN CGMutablePathRef CGPathCreateMutableCopy(CGPathRef path);
CG_EXTERN CGPathRef CGPathRetain(CGPathRef path);
CG_EXTERN void CGPathRelease(CGPathRef path);
CG_EXTERN bool CGPathEqualToPath(CGPathRef path1, CGPathRef path2);
CG_EXTERN void CGPathMoveToPoint(CGMutablePathRef path,
    const CGAffineTransform *m, CGFloat x, CGFloat y);
CG_EXTERN void CGPathAddLineToPoint(CGMutablePathRef path,
    const CGAffineTransform *m, CGFloat x, CGFloat y);
CG_EXTERN void CGPathAddQuadCurveToPoint(CGMutablePathRef path,
    const CGAffineTransform *m, CGFloat cpx, CGFloat cpy, CGFloat x, CGFloat y);
CG_EXTERN void CGPathAddCurveToPoint(CGMutablePathRef path,
    const CGAffineTransform *m, CGFloat cp1x, CGFloat cp1y,
    CGFloat cp2x, CGFloat cp2y, CGFloat x, CGFloat y);
CG_EXTERN void CGPathCloseSubpath(CGMutablePathRef path);
CG_EXTERN void CGPathAddRect(CGMutablePathRef path, const CGAffineTransform *m,
    CGRect rect);
CG_EXTERN void CGPathAddRects(CGMutablePathRef path,
    const CGAffineTransform *m, const CGRect rects[], size_t count);
CG_EXTERN void CGPathAddLines(CGMutablePathRef path,
    const CGAffineTransform *m, const CGPoint points[], size_t count);
CG_EXTERN void CGPathAddEllipseInRect(CGMutablePathRef path,
    const CGAffineTransform *m, CGRect rect);
CG_EXTERN void CGPathAddArc(CGMutablePathRef path, const CGAffineTransform *m,
    CGFloat x, CGFloat y, CGFloat radius, CGFloat startAngle, CGFloat endAngle,
    bool clockwise);
CG_EXTERN void CGPathAddArcToPoint(CGMutablePathRef path,
    const CGAffineTransform *m, CGFloat x1, CGFloat y1, CGFloat x2, CGFloat y2,
    CGFloat radius);
CG_EXTERN void CGPathAddPath(CGMutablePathRef path1,
    const CGAffineTransform *m, CGPathRef path2);
CG_EXTERN bool CGPathIsEmpty(CGPathRef path);
CG_EXTERN bool CGPathIsRect(CGPathRef path, CGRect *rect);
CG_EXTERN CGPoint CGPathGetCurrentPoint(CGPathRef path);
CG_EXTERN CGRect CGPathGetBoundingBox(CGPathRef path);
CG_EXTERN bool CGPathContainsPoint(CGPathRef path,
    const CGAffineTransform *m, CGPoint point, bool eoFill);

enum CGPathElementType {
    kCGPathElementMoveToPoint,
    kCGPathElementAddLineToPoint,
    kCGPathElementAddQuadCurveToPoint,
    kCGPathElementAddCurveToPoint,
    kCGPathElementCloseSubpath
};
typedef enum CGPathElementType CGPathElementType;

struct CGPathElement {
    CGPathElementType type;
    CGPoint *points;
};
typedef struct CGPathElement CGPathElement;


typedef void (*CGPathApplierFunction)(void *info,
    const CGPathElement *element);

CG_EXTERN void CGPathApply(CGPathRef path, void *info,
    CGPathApplierFunction function);
    
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//CGPattern
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
typedef struct CGPattern *CGPatternRef;

enum CGPatternTiling {
    kCGPatternTilingNoDistortion,
    kCGPatternTilingConstantSpacingMinimalDistortion,
    kCGPatternTilingConstantSpacing
};
typedef enum CGPatternTiling CGPatternTiling;

typedef void (*CGPatternDrawPatternCallback)(void *info, CGContextRef c);
typedef void (*CGPatternReleaseInfoCallback)(void *info);

struct CGPatternCallbacks {
    unsigned int version;
    CGPatternDrawPatternCallback drawPattern;
    CGPatternReleaseInfoCallback releaseInfo;
};
typedef struct CGPatternCallbacks CGPatternCallbacks;


CG_EXTERN CFTypeID CGPatternGetTypeID(void);
CG_EXTERN CGPatternRef CGPatternCreate(void *info, CGRect bounds,
    CGAffineTransform matrix, CGFloat xStep, CGFloat yStep,
    CGPatternTiling tiling, bool isColored,
    const CGPatternCallbacks *callbacks);
CG_EXTERN CGPatternRef CGPatternRetain(CGPatternRef pattern);
CG_EXTERN void CGPatternRelease(CGPatternRef pattern);

typedef struct CGShading *CGShadingRef;

CG_EXTERN CFTypeID CGShadingGetTypeID(void);
CG_EXTERN CGShadingRef CGShadingCreateAxial(CGColorSpaceRef space,
    CGPoint start, CGPoint end, CGFunctionRef function, bool extendStart,
    bool extendEnd);
CG_EXTERN CGShadingRef CGShadingCreateRadial(CGColorSpaceRef space,
    CGPoint start, CGFloat startRadius, CGPoint end, CGFloat endRadius,
    CGFunctionRef function, bool extendStart, bool extendEnd);
CG_EXTERN CGShadingRef CGShadingRetain(CGShadingRef shading);
CG_EXTERN void CGShadingRelease(CGShadingRef shading);

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//CGContext
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
typedef struct CGContext *CGContextRef;

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
    /* Available in Mac OS X 10.4 & later. */
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
    kCGBlendModeClear,			/* R = 0 */
    kCGBlendModeCopy,			/* R = S */
    kCGBlendModeSourceIn,		/* R = S*Da */
    kCGBlendModeSourceOut,		/* R = S*(1 - Da) */
    kCGBlendModeSourceAtop,		/* R = S*Da + D*(1 - Sa) */
    kCGBlendModeDestinationOver,	/* R = S*(1 - Da) + D */
    kCGBlendModeDestinationIn,		/* R = D*Sa */
    kCGBlendModeDestinationOut,		/* R = D*(1 - Sa) */
    kCGBlendModeDestinationAtop,	/* R = S*(1 - Da) + D*Sa */
    kCGBlendModeXOR,			/* R = S*(1 - Da) + D*(1 - Sa) */
    kCGBlendModePlusDarker,		/* R = MAX(0, (1 - D) + (1 - S)) */
    kCGBlendModePlusLighter		/* R = MIN(1, S + D) */
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
#if 0
CG_EXTERN void CGContextDrawPDFPage(CGContextRef c, CGPDFPageRef page);
CG_EXTERN void CGContextDrawPDFDocument(CGContextRef c, CGRect rect,
    CGPDFDocumentRef document, int page);
#endif
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

//PRIVATE
CG_EXTERN CGContextRef CGContextCreate();

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//CGBitmapContext
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$



CG_EXTERN CGContextRef 
CGBitmapContextCreate(void *data, size_t width,
					  size_t height, size_t bitsPerComponent, size_t bytesPerRow,
					  CGColorSpaceRef colorspace, CGBitmapInfo bitmapInfo);

CG_EXTERN void *
CGBitmapContextGetData(CGContextRef c);

CG_EXTERN size_t 
CGBitmapContextGetWidth(CGContextRef c);

CG_EXTERN size_t 
CGBitmapContextGetHeight(CGContextRef c);

CG_EXTERN size_t 
CGBitmapContextGetBitsPerComponent(CGContextRef c);

CG_EXTERN size_t 
CGBitmapContextGetBitsPerPixel(CGContextRef c);

CG_EXTERN size_t 
CGBitmapContextGetBytesPerRow(CGContextRef c);

CG_EXTERN CGColorSpaceRef 
CGBitmapContextGetColorSpace(CGContextRef c);

CG_EXTERN CGImageAlphaInfo 
CGBitmapContextGetAlphaInfo(CGContextRef c);

CG_EXTERN CGBitmapInfo 
CGBitmapContextGetBitmapInfo(CGContextRef c);

CG_EXTERN CGImageRef 
CGBitmapContextCreateImage(CGContextRef c);

//PRIVATE
typedef struct CGBitmapContextInfo *CGBitmapContextInfoRef;

CG_EXTERN CGBitmapContextInfoRef
CGBitmapContextInfoCreate(void *data, size_t width, size_t height,
              size_t bitsPerComponent, size_t bitsPerAlpha,
						  size_t bytesPerRow, CGColorSpaceRef colorspace, 
              CGBitmapInfo bitmapInfo, Boolean a, Boolean b, Boolean c,
						  Boolean d,Boolean e, CGFloat hRes, CGFloat vRes);
						  
CG_EXTERN CGContextRef
createBitmapContext(CGBitmapContextInfoRef bitmapContextInfo, CFDictionaryRef theDict, const char* name);

