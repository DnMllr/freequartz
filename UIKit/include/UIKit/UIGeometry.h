#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIKitDefines.h>

typedef struct UIEdgeInsets {

    CGFloat left;
    CGFloat bottom;
    CGFloat right;
} UIEdgeInsets;

UIKIT_STATIC_INLINE UIEdgeInsets UIEdgeInsetsMake(CGFloat top, CGFloat left, CGFloat bottom, CGFloat right) {
    UIEdgeInsets insets = {top, left, bottom, right};
    return insets;
}

UIKIT_STATIC_INLINE CGRect UIEdgeInsetsInsetRect(CGRect rect, UIEdgeInsets insets) {
    rect.origin.x    += insets.left;
    rect.origin.y    += insets.top;
    rect.size.width  -= (insets.left + insets.right);
    rect.size.height -= (insets.top  + insets.bottom);
    return rect;
}

UIKIT_STATIC_INLINE BOOL UIEdgeInsetsEqualToEdgeInsets(UIEdgeInsets insets1, UIEdgeInsets insets2) {
    return insets1.left == insets2.left && insets1.top == insets2.top && insets1.right == insets2.right && insets1.bottom == insets2.bottom;
}

UIKIT_EXTERN const UIEdgeInsets UIEdgeInsetsZero;

UIKIT_EXTERN NSString *NSStringFromCGPoint(CGPoint point);
UIKIT_EXTERN NSString *NSStringFromCGSize(CGSize size);
UIKIT_EXTERN NSString *NSStringFromCGRect(CGRect rect);
UIKIT_EXTERN NSString *NSStringFromCGAffineTransform(CGAffineTransform transform);
UIKIT_EXTERN NSString *NSStringFromUIEdgeInsets(UIEdgeInsets insets);

UIKIT_EXTERN CGPoint CGPointFromString(NSString *string);
UIKIT_EXTERN CGSize CGSizeFromString(NSString *string);
UIKIT_EXTERN CGRect CGRectFromString(NSString *string);
UIKIT_EXTERN CGAffineTransform CGAffineTransformFromString(NSString *string);
UIKIT_EXTERN UIEdgeInsets UIEdgeInsetsFromString(NSString *string);

@interface NSValue (NSValueUIGeometryExtensions)

+ (NSValue *)valueWithCGPoint:(CGPoint)point;
+ (NSValue *)valueWithCGSize:(CGSize)size;
+ (NSValue *)valueWithCGRect:(CGRect)rect;
+ (NSValue *)valueWithCGAffineTransform:(CGAffineTransform)transform;
+ (NSValue *)valueWithUIEdgeInsets:(UIEdgeInsets)insets;

- (CGPoint)CGPointValue;
- (CGSize)CGSizeValue;
- (CGRect)CGRectValue;
- (CGAffineTransform)CGAffineTransformValue;
- (UIEdgeInsets)UIEdgeInsetsValue;

@end
    
@interface NSCoder (UIGeometryKeyedCoding)

- (void)encodeCGPoint:(CGPoint)point forKey:(NSString *)key;
- (void)encodeCGSize:(CGSize)size forKey:(NSString *)key;
- (void)encodeCGRect:(CGRect)rect forKey:(NSString *)key;
- (void)encodeCGAffineTransform:(CGAffineTransform)transform forKey:(NSString *)key;
- (void)encodeUIEdgeInsets:(UIEdgeInsets)insets forKey:(NSString *)key;

- (CGPoint)decodeCGPointForKey:(NSString *)key;
- (CGSize)decodeCGSizeForKey:(NSString *)key;
- (CGRect)decodeCGRectForKey:(NSString *)key;
- (CGAffineTransform)decodeCGAffineTransformForKey:(NSString *)key;
- (UIEdgeInsets)decodeUIEdgeInsetsForKey:(NSString *)key;

@end
