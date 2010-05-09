#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIKitDefines.h>

UIKIT_EXTERN_CLASS @interface UIFont : NSObject {
}

+ (UIFont *)fontWithName:(NSString *)fontName size:(CGFloat)fontSize;
+ (NSArray *)familyNames;
+ (NSArray *)fontNamesForFamilyName:(NSString *)familyName;
+ (UIFont *)systemFontOfSize:(CGFloat)fontSize;
+ (UIFont *)boldSystemFontOfSize:(CGFloat)fontSize;
+ (UIFont *)italicSystemFontOfSize:(CGFloat)fontSize;

#ifdef OBJC2
@property(nonatomic,readonly,retain) NSString *familyName;
@property(nonatomic,readonly,retain) NSString *fontName;
@property(nonatomic,readonly)        CGFloat   pointSize;
@property(nonatomic,readonly)        CGFloat   ascender;
@property(nonatomic,readonly)        CGFloat   descender;
@property(nonatomic,readonly)        CGFloat   leading;
@property(nonatomic,readonly)        CGFloat   capHeight;
@property(nonatomic,readonly)        CGFloat   xHeight;
#else  /* OBJC2 */
- (NSString *)familyName;
- (NSString *)fontName;
- (CGFloat)pointSize;
- (CGFloat)ascender;
- (CGFloat)descender;
- (CGFloat)leading;
- (CGFloat)capHeight;
- (CGFloat)xHeight;
#endif /*OBJC2*/


- (UIFont *)fontWithSize:(CGFloat)fontSize;

@end
