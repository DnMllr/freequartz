#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIKitDefines.h>
#import <UIKit/UIControl.h>
#import <UIKit/UIFont.h>
#import <UIKit/UIStringDrawing.h>
#import <UIKit/UITextInputTraits.h>

@class UIImage, UIImageView, UILabel, UIColor;
@class UITextFieldAtomBackgroundView;
@class UITextFieldBackgroundView;
@class UITextFieldBorderView;
@class UITextFieldLabel;
@class UITextInputTraits;
@class UITextSelectionView;
@class UITextInteractionAssistant;
@protocol UITextFieldDelegate;
@protocol UITextSelecting;

typedef enum {
    UITextBorderStyleNone,
    UITextBorderStyleLine,
    UITextBorderStyleBezel,
    UITextBorderStyleRoundedRect
} UITextBorderStyle;

typedef enum {
    UITextFieldViewModeNever,
    UITextFieldViewModeWhileEditing,
    UITextFieldViewModeUnlessEditing,
    UITextFieldViewModeAlways
} UITextFieldViewMode;

UIKIT_EXTERN_CLASS @interface UITextField : UIControl <UITextInputTraits, NSCoding> {

    struct {

    } _uitextFieldFlags;
}

- (CGRect)borderRectForBounds:(CGRect)bounds;
- (CGRect)textRectForBounds:(CGRect)bounds;
- (CGRect)placeholderRectForBounds:(CGRect)bounds;
- (CGRect)editingRectForBounds:(CGRect)bounds;
- (CGRect)clearButtonRectForBounds:(CGRect)bounds;
- (CGRect)leftViewRectForBounds:(CGRect)bounds;
- (CGRect)rightViewRectForBounds:(CGRect)bounds;
- (void)drawTextInRect:(CGRect)rect;
- (void)drawPlaceholderInRect:(CGRect)rect;

#ifdef OBJC2
@property(nonatomic,copy)   NSString               *text;                 
@property(nonatomic,retain) UIColor                *textColor;            
@property(nonatomic,retain) UIFont                 *font;                 
@property(nonatomic)        UITextAlignment         textAlignment;        
@property(nonatomic)        UITextBorderStyle       borderStyle;          
@property(nonatomic,copy)   NSString               *placeholder;          
@property(nonatomic)        BOOL                    clearsOnBeginEditing; 
@property(nonatomic)        BOOL                    adjustsFontSizeToFitWidth; 
@property(nonatomic)        CGFloat                 minimumFontSize;      
@property(nonatomic,assign) id<UITextFieldDelegate> delegate;             
@property(nonatomic,retain) UIImage                *background;           
@property(nonatomic,retain) UIImage                *disabledBackground;   
@property(nonatomic,readonly,getter=isEditing) BOOL editing;
@property(nonatomic)        UITextFieldViewMode  clearButtonMode; 
@property(nonatomic,retain) UIView              *leftView;        
@property(nonatomic)        UITextFieldViewMode  leftViewMode;    
@property(nonatomic,retain) UIView              *rightView;       
@property(nonatomic)        UITextFieldViewMode  rightViewMode;   
#else /*OBJC2*/
- (NSString *)text;
- (UIColor *)textColor;
- (UIFont *)font;
- (UITextAlignment)textAlignment;
- (UITextBorderStyle)borderStyle;
- (NSString *)placeholder;
- (BOOL)clearsOnBeginEditing;
- (BOOL)adjustsFontSizeToFitWidth;
- (CGFloat)minimumFontSize;
//- (id<UITextFieldDelegate>)delegate;
- (UIImage *)background;
- (UIImage *)disabledBackground;
- (BOOL)isEditing;
- (UITextFieldViewMode)clearButtonMode;
- (UIView *)leftView;
- (UITextFieldViewMode)leftViewMode;
- (UIView *)rightView;
- (UITextFieldViewMode)rightViewMode;
#endif /*OBJC2*/

@end

@interface UIView (UITextField)
- (BOOL)endEditing:(BOOL)force; 
@end

#ifdef OBJC2
@protocol UITextFieldDelegate <NSObject>

@optional

- (BOOL)textFieldShouldBeginEditing:(UITextField *)textField;        
- (void)textFieldDidBeginEditing:(UITextField *)textField;           
- (BOOL)textFieldShouldEndEditing:(UITextField *)textField;          
- (void)textFieldDidEndEditing:(UITextField *)textField;             
- (BOOL)textField:(UITextField *)textField shouldChangeCharactersInRange:(NSRange)range replacementString:(NSString *)string;   
- (BOOL)textFieldShouldClear:(UITextField *)textField;               
- (BOOL)textFieldShouldReturn:(UITextField *)textField;              

@end
#else /*OBJC2*/
@interface NSObject (UITextFieldDelegate)
- (BOOL)textFieldShouldBeginEditing:(UITextField *)textField;        
- (void)textFieldDidBeginEditing:(UITextField *)textField;           
- (BOOL)textFieldShouldEndEditing:(UITextField *)textField;          
- (void)textFieldDidEndEditing:(UITextField *)textField;             
- (BOOL)textField:(UITextField *)textField shouldChangeCharactersInRange:(NSRange)range replacementString:(NSString *)string;   
- (BOOL)textFieldShouldClear:(UITextField *)textField;               
- (BOOL)textFieldShouldReturn:(UITextField *)textField;
@end
#endif /*OBJC2*/

UIKIT_EXTERN NSString *const UITextFieldTextDidBeginEditingNotification;
UIKIT_EXTERN NSString *const UITextFieldTextDidEndEditingNotification;
UIKIT_EXTERN NSString *const UITextFieldTextDidChangeNotification;

