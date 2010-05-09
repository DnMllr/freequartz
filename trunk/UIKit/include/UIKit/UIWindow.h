#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIView.h>
#import <UIKit/UIApplication.h>
#import <UIKit/UIKitDefines.h>

typedef CGFloat UIWindowLevel;

@class UIEvent, NSUndoManager;

UIKIT_EXTERN_CLASS @interface UIWindow : UIView {
  
    struct {
  
    } _uiwindowFlags;
    
    
}

- (void)becomeKeyWindow;                               
- (void)resignKeyWindow;                               
- (void)makeKeyWindow;
- (void)makeKeyAndVisible;                             
- (void)sendEvent:(UIEvent *)event;                    
- (CGPoint)convertPoint:(CGPoint)point toWindow:(UIWindow *)window;    
- (CGPoint)convertPoint:(CGPoint)point fromWindow:(UIWindow *)window;  
- (CGRect)convertRect:(CGRect)rect toWindow:(UIWindow *)window;
- (CGRect)convertRect:(CGRect)rect fromWindow:(UIWindow *)window;

#ifdef OBJC2
@property(nonatomic) UIWindowLevel windowLevel;                   
@property(nonatomic,readonly,getter=isKeyWindow) BOOL keyWindow;
#else  /* OBJC2 */
// TODO
#endif /* OBJC2 */

@end

UIKIT_EXTERN const UIWindowLevel UIWindowLevelNormal;
UIKIT_EXTERN const UIWindowLevel UIWindowLevelAlert;
UIKIT_EXTERN const UIWindowLevel UIWindowLevelStatusBar;
UIKIT_EXTERN NSString *const UIWindowDidBecomeVisibleNotification; 
UIKIT_EXTERN NSString *const UIWindowDidBecomeHiddenNotification;  
UIKIT_EXTERN NSString *const UIWindowDidBecomeKeyNotification;     
UIKIT_EXTERN NSString *const UIWindowDidResignKeyNotification;     
UIKIT_EXTERN NSString *const UIKeyboardWillShowNotification;
UIKIT_EXTERN NSString *const UIKeyboardDidShowNotification; 
UIKIT_EXTERN NSString *const UIKeyboardWillHideNotification; 
UIKIT_EXTERN NSString *const UIKeyboardDidHideNotification;
UIKIT_EXTERN NSString *const UIKeyboardCenterBeginUserInfoKey;  
UIKIT_EXTERN NSString *const UIKeyboardCenterEndUserInfoKey;    
UIKIT_EXTERN NSString *const UIKeyboardBoundsUserInfoKey;       
UIKIT_EXTERN NSString *const UIKeyboardAnimationDurationUserInfoKey ; 
UIKIT_EXTERN NSString *const UIKeyboardAnimationCurveUserInfoKey ; 
