#import <Foundation/Foundation.h>
#import <UIKit/UIControl.h>
#import <UIKit/UIGeometry.h>
#import <UIKit/UIStringDrawing.h>
#import <UIKit/UIKitDefines.h>

@class UIImage, UIFont, UIColor, UIImageView, UILabel;

typedef enum {
    UIButtonTypeCustom = 0,           
    UIButtonTypeRoundedRect,          

    UIButtonTypeDetailDisclosure,
    UIButtonTypeInfoLight,
    UIButtonTypeInfoDark,
    UIButtonTypeContactAdd,
} UIButtonType;

UIKIT_EXTERN_CLASS @interface UIButton : UIControl <NSCoding> {
  
    struct {
  
    } _uibuttonFlags;
}

+ (id)buttonWithType:(UIButtonType)buttonType;

- (void)setTitle:(NSString *)title forState:(UIControlState)state;
- (void)setTitleColor:(UIColor *)color forState:(UIControlState)state;
- (void)setTitleShadowColor:(UIColor *)color forState:(UIControlState)state;
- (void)setImage:(UIImage *)image forState:(UIControlState)state;         
- (void)setBackgroundImage:(UIImage *)image forState:(UIControlState)state;
- (NSString *)titleForState:(UIControlState)state;          
- (UIColor *)titleColorForState:(UIControlState)state;
- (UIColor *)titleShadowColorForState:(UIControlState)state;
- (UIImage *)imageForState:(UIControlState)state;
- (UIImage *)backgroundImageForState:(UIControlState)state;
- (CGRect)backgroundRectForBounds:(CGRect)bounds;
- (CGRect)contentRectForBounds:(CGRect)bounds;
- (CGRect)titleRectForContentRect:(CGRect)contentRect;
- (CGRect)imageRectForContentRect:(CGRect)contentRect;

#ifdef OBJC2
@property(nonatomic)        UIEdgeInsets    contentEdgeInsets;              
@property(nonatomic)        UIEdgeInsets    titleEdgeInsets;                
@property(nonatomic)        BOOL            reversesTitleShadowWhenHighlighted; 
@property(nonatomic)        UIEdgeInsets    imageEdgeInsets;                
@property(nonatomic)        BOOL            adjustsImageWhenHighlighted;    
@property(nonatomic)        BOOL            adjustsImageWhenDisabled;       
@property(nonatomic)        BOOL            showsTouchWhenHighlighted;      
@property(nonatomic,readonly) UIButtonType buttonType;
@property(nonatomic,readonly,retain) NSString *currentTitle;             
@property(nonatomic,readonly,retain) UIColor  *currentTitleColor;        
@property(nonatomic,readonly,retain) UIColor  *currentTitleShadowColor;  
@property(nonatomic,readonly,retain) UIImage  *currentImage;             
@property(nonatomic,readonly,retain) UIImage  *currentBackgroundImage;   
@property(nonatomic,readonly,retain) UILabel     *titleLabel;
@property(nonatomic,readonly,retain) UIImageView *imageView;
#else  /* OBJC2 */
// TODO
#endif /* OBJC2 */

@end

@interface UIButton(UIButtonDeprecated)

@property(nonatomic,retain) UIFont         *font;
@property(nonatomic)        UILineBreakMode lineBreakMode;
@property(nonatomic)        CGSize          titleShadowOffset;

@end
