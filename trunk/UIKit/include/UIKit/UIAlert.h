#import <Foundation/Foundation.h>
#import <UIKit/UIKitDefines.h>
#import <UIKit/UITextField.h>
#import <UIKit/UIView.h>

@protocol UIActionSheetDelegate, UIAlertViewDelegate;
@class UILabel, UIToolbar, UITabBar, UIWindow;

typedef enum {
    UIActionSheetStyleAutomatic        = -1,
    UIActionSheetStyleDefault          = UIBarStyleDefault,
    UIActionSheetStyleBlackTranslucent = UIBarStyleBlackTranslucent,
    UIActionSheetStyleBlackOpaque      = UIBarStyleBlackOpaque,
} UIActionSheetStyle;

UIKIT_EXTERN_CLASS @interface UIActionSheet : UIView {
  
    struct {
        
    } _uiactionsheetFlags;
}

- (id)initWithTitle:(NSString *)title delegate:(id<UIActionSheetDelegate>)delegate cancelButtonTitle:(NSString *)cancelButtonTitle destructiveButtonTitle:(NSString *)destructiveButtonTitle otherButtonTitles:(NSString *)otherButtonTitles, ...;
- (NSInteger)addButtonWithTitle:(NSString *)title; 
- (NSString *)buttonTitleAtIndex:(NSInteger)buttonIndex;
- (void)showFromToolbar:(UIToolbar *)view;
- (void)showFromTabBar:(UITabBar *)view;
- (void)showInView:(UIView *)view;
- (void)dismissWithClickedButtonIndex:(NSInteger)buttonIndex animated:(BOOL)animated;

#ifdef OBJC2
@property(nonatomic,assign) id<UIActionSheetDelegate> delegate;
@property(nonatomic,copy) NSString *title;
@property(nonatomic) UIActionSheetStyle actionSheetStyle;
@property(nonatomic,readonly) NSInteger numberOfButtons;
@property(nonatomic) NSInteger cancelButtonIndex;      
@property(nonatomic) NSInteger destructiveButtonIndex; 
@property(nonatomic,readonly) NSInteger firstOtherButtonIndex;
@property(nonatomic,readonly,getter=isVisible) BOOL visible;
#else /*OBJC2*/
//- (id<UIActionSheetDelegate>)delegate;
- (NSString *)title;
- (void)setTitle:(NSString *)theTitle;
- (UIActionSheetStyle)actionSheetStyle;
- (void)setActionSheetStyle:(UIActionSheetStyle)theActionSheetStyle;
- (NSInteger)numberOfButtons;
- (NSInteger)cancelButtonIndex;
- (void)setCancelButtonIndex:(NSInteger)theCancelButtonIndex;
- (NSInteger)destructiveButtonIndex;
- (void)setDestructiveButtonIndex:(NSInteger)theDestructiveButtonIndex;
- (NSInteger)firstOtherButtonIndex;
- (BOOL)isVisible;
#endif /*OBJC2*/

@end

#ifdef OBJC2
@protocol UIActionSheetDelegate <NSObject>
@optional


- (void)actionSheet:(UIActionSheet *)actionSheet clickedButtonAtIndex:(NSInteger)buttonIndex;
- (void)actionSheetCancel:(UIActionSheet *)actionSheet;
- (void)willPresentActionSheet:(UIActionSheet *)actionSheet; 
- (void)didPresentActionSheet:(UIActionSheet *)actionSheet;  
- (void)actionSheet:(UIActionSheet *)actionSheet willDismissWithButtonIndex:(NSInteger)buttonIndex; 
- (void)actionSheet:(UIActionSheet *)actionSheet didDismissWithButtonIndex:(NSInteger)buttonIndex; 

@end
#else
@interface NSObject (UIActionSheetDelegate)
- (void)actionSheet:(UIActionSheet *)actionSheet clickedButtonAtIndex:(NSInteger)buttonIndex;
- (void)actionSheetCancel:(UIActionSheet *)actionSheet;
- (void)willPresentActionSheet:(UIActionSheet *)actionSheet; 
- (void)didPresentActionSheet:(UIActionSheet *)actionSheet;  
- (void)actionSheet:(UIActionSheet *)actionSheet willDismissWithButtonIndex:(NSInteger)buttonIndex; 
- (void)actionSheet:(UIActionSheet *)actionSheet didDismissWithButtonIndex:(NSInteger)buttonIndex;
@end
#endif




UIKIT_EXTERN_CLASS @interface UIAlertView : UIView {
  
    struct {
  
    } _uialertViewFlags;
}

- (id)initWithTitle:(NSString *)title message:(NSString *)message delegate:(id /*<UIAlertViewDelegate>*/)delegate cancelButtonTitle:(NSString *)cancelButtonTitle otherButtonTitles:(NSString *)otherButtonTitles, ...;
- (NSInteger)addButtonWithTitle:(NSString *)title; 
- (NSString *)buttonTitleAtIndex:(NSInteger)buttonIndex;
- (void)show;
- (void)dismissWithClickedButtonIndex:(NSInteger)buttonIndex animated:(BOOL)animated;

#ifdef OBJC2
@property(nonatomic,assign) id /*<UIAlertViewDelegate>*/ delegate;    
@property(nonatomic,copy) NSString *title;
@property(nonatomic,copy) NSString *message;
@property(nonatomic,readonly) NSInteger numberOfButtons;
@property(nonatomic) NSInteger cancelButtonIndex; 
@property(nonatomic,readonly) NSInteger firstOtherButtonIndex;
@property(nonatomic,readonly,getter=isVisible) BOOL visible;
#else /* OBJC2 */
- (id)delegate;
- (void)setDelegate:(id)theDelegate;
- (NSString *)title;
- (void)setTitle:(NSString *)theTitle;
- (NSString *)message;
- (void)setMessage:(NSString *)theMessage;
- (NSInteger)cancelButtonIndex;
- (void)setCancelButtonIndex:(NSInteger)theCancelButtonIndex;
- (NSInteger)firstOtherButtonIndex;
- (BOOL)isVisible;
- (void)setVisible:(BOOL)visibleFlag;
#endif /* OBJC2 */

@end

#ifdef OBJC2
@protocol UIAlertViewDelegate <NSObject>
@optional

- (void)alertView:(UIAlertView *)alertView clickedButtonAtIndex:(NSInteger)buttonIndex;
- (void)alertViewCancel:(UIAlertView *)alertView;
- (void)willPresentAlertView:(UIAlertView *)alertView;  
- (void)didPresentAlertView:(UIAlertView *)alertView;  
- (void)alertView:(UIAlertView *)alertView willDismissWithButtonIndex:(NSInteger)buttonIndex; 
- (void)alertView:(UIAlertView *)alertView didDismissWithButtonIndex:(NSInteger)buttonIndex; 

@end
#else /* OBJC2 */
@interface NSObject (UIAlertViewDelegate)
- (void)alertView:(UIAlertView *)alertView clickedButtonAtIndex:(NSInteger)buttonIndex;
- (void)alertViewCancel:(UIAlertView *)alertView;
- (void)willPresentAlertView:(UIAlertView *)alertView;  
- (void)didPresentAlertView:(UIAlertView *)alertView;  
- (void)alertView:(UIAlertView *)alertView willDismissWithButtonIndex:(NSInteger)buttonIndex; 
- (void)alertView:(UIAlertView *)alertView didDismissWithButtonIndex:(NSInteger)buttonIndex;
@end
#endif /* OBJC2 */
