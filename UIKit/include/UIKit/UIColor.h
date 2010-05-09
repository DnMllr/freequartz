#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIKitDefines.h>

@class UIImage;

UIKIT_EXTERN_CLASS @interface UIColor : NSObject <NSCoding>

+ (UIColor *)colorWithWhite:(CGFloat)white alpha:(CGFloat)alpha;
+ (UIColor *)colorWithHue:(CGFloat)hue saturation:(CGFloat)saturation brightness:(CGFloat)brightness alpha:(CGFloat)alpha;
+ (UIColor *)colorWithRed:(CGFloat)red green:(CGFloat)green blue:(CGFloat)blue alpha:(CGFloat)alpha;
+ (UIColor *)colorWithCGColor:(CGColorRef)cgColor;
+ (UIColor *)colorWithPatternImage:(UIImage *)image;

- (UIColor *)initWithWhite:(CGFloat)white alpha:(CGFloat)alpha;
- (UIColor *)initWithHue:(CGFloat)hue saturation:(CGFloat)saturation brightness:(CGFloat)brightness alpha:(CGFloat)alpha;
- (UIColor *)initWithRed:(CGFloat)red green:(CGFloat)green blue:(CGFloat)blue alpha:(CGFloat)alpha;
- (UIColor *)initWithCGColor:(CGColorRef)cgColor;
- (UIColor *)initWithPatternImage:(UIImage*)image;

+ (UIColor *)blackColor;      
+ (UIColor *)darkGrayColor;    
+ (UIColor *)lightGrayColor;   
+ (UIColor *)whiteColor;       
+ (UIColor *)grayColor;       
+ (UIColor *)redColor;         
+ (UIColor *)greenColor;       
+ (UIColor *)blueColor;        
+ (UIColor *)cyanColor;        
+ (UIColor *)yellowColor;      
+ (UIColor *)magentaColor;     
+ (UIColor *)orangeColor;      
+ (UIColor *)purpleColor;      
+ (UIColor *)brownColor;       
+ (UIColor *)clearColor;       


- (void)set;
- (void)setFill;
- (void)setStroke;

- (UIColor *)colorWithAlphaComponent:(CGFloat)alpha;

#ifdef OBJC2
@property(nonatomic,readonly) CGColorRef CGColor;
#else  /* OBJC2 */
- (CGColorRef)CGColor;
#endif /* OBJC2 */

@end
