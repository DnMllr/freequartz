#import <Foundation/Foundation.h>
#import <UIKit/UIKitDefines.h>
#import <UIKit/UIColor.h>
#import <UIKit/UIFont.h>



typedef enum {
    UIBarStyleDefault          = 0,
    UIBarStyleBlack            = 1,
    
    UIBarStyleBlackOpaque      = 1, 
    UIBarStyleBlackTranslucent = 2, 
} UIBarStyle;

@interface UIColor (UIColorSystemColors)
+ (UIColor *)lightTextColor;                
+ (UIColor *)darkTextColor;             
+ (UIColor *)groupTableViewBackgroundColor;
+ (UIColor *)viewFlipsideBackgroundColor;
@end

@interface UIFont (UIFontSystemFonts)
+ (CGFloat)labelFontSize;
+ (CGFloat)buttonFontSize;
+ (CGFloat)smallSystemFontSize;
+ (CGFloat)systemFontSize;
@end
