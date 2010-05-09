#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIScrollView.h>
#import <UIKit/UIStringDrawing.h>
#import <UIKit/UITextInputTraits.h>
#import <UIKit/UIKitDefines.h>
#import <UIKit/UIDataDetectors.h>

@class DOMHTMLElement;
@class UIDelayedAction;
@class UIEvent, UITouch, UIFont, UIColor;
@class UITextInputTraits;
@class UITextInteractionAssistant;
@class UIWebDocumentView;
@class WebCoreFrameBridge;
@class WebFrame;
@protocol UITextViewDelegate;
@class UITextInteractionAssistant;
@class UITextSelectionView;

UIKIT_EXTERN_CLASS @interface UITextView : UIScrollView <UITextInputTraits> 
{

}

- (BOOL)hasText;
- (void)scrollRangeToVisible:(NSRange)range;

#ifdef OBJC2
@property(nonatomic,assign) id<UITextViewDelegate> delegate;
@property(nonatomic,copy) NSString *text;
@property(nonatomic,retain) UIFont *font;
@property(nonatomic,retain) UIColor *textColor;
@property(nonatomic) UITextAlignment textAlignment;    
@property(nonatomic) NSRange selectedRange;            
@property(nonatomic,getter=isEditable) BOOL editable;
@property(nonatomic) UIDataDetectorTypes dataDetectorTypes;
#else  /* OBJC2 */
// TODO
#endif /* OBJC2 */

@end

@protocol UITextViewDelegate <NSObject>

@optional

- (BOOL)textViewShouldBeginEditing:(UITextView *)textView;
- (BOOL)textViewShouldEndEditing:(UITextView *)textView;
- (void)textViewDidBeginEditing:(UITextView *)textView;
- (void)textViewDidEndEditing:(UITextView *)textView;
- (BOOL)textView:(UITextView *)textView shouldChangeTextInRange:(NSRange)range replacementText:(NSString *)text;
- (void)textViewDidChange:(UITextView *)textView;
- (void)textViewDidChangeSelection:(UITextView *)textView;

@end

UIKIT_EXTERN NSString * const UITextViewTextDidBeginEditingNotification;
UIKIT_EXTERN NSString * const UITextViewTextDidChangeNotification;
UIKIT_EXTERN NSString * const UITextViewTextDidEndEditingNotification;
