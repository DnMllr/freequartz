#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIView.h>
#import <UIKit/UIStringDrawing.h>
#import <UIKit/UIKitDefines.h>

@class UIColor, UIFont;

UIKIT_EXTERN_CLASS @interface UILabel : UIView <NSCoding>
{
    struct {
 
    } _uiLabelFlags;
}

- (CGRect)textRectForBounds:(CGRect)bounds limitedToNumberOfLines:(NSInteger)numberOfLines;
- (void)drawTextInRect:(CGRect)rect;

#ifdef OBJC2
@property(nonatomic,copy)   NSString       *text;            
@property(nonatomic,retain) UIFont         *font;            
@property(nonatomic,retain) UIColor        *textColor;       
@property(nonatomic,retain) UIColor        *shadowColor;     
@property(nonatomic)        CGSize          shadowOffset;    
@property(nonatomic)        UITextAlignment textAlignment;   
@property(nonatomic)        UILineBreakMode lineBreakMode;   
@property(nonatomic,retain) UIColor *highlightedTextColor; 
@property(nonatomic,getter=isHighlighted) BOOL     highlighted;          
@property(nonatomic,getter=isUserInteractionEnabled) BOOL userInteractionEnabled;  
@property(nonatomic,getter=isEnabled)                BOOL enabled;                 
@property(nonatomic) NSInteger numberOfLines;
@property(nonatomic) BOOL adjustsFontSizeToFitWidth;          
@property(nonatomic) CGFloat minimumFontSize;                 
@property(nonatomic) UIBaselineAdjustment baselineAdjustment; 
#else  /* OBJC2 */
// TODO
#endif /* OBJC2 */




@end
