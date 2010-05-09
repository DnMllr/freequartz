#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIKitDefines.h>

@class UIView;

UIKIT_EXTERN_CLASS @interface UIMenuController : NSObject {

}

+ (UIMenuController *)sharedMenuController;

- (void)setMenuVisible:(BOOL)menuVisible animated:(BOOL)animated;
- (void)setTargetRect:(CGRect)targetRect inView:(UIView *)targetView;
- (void)update;	

#ifdef OBJC2
@property(nonatomic,getter=isMenuVisible) BOOL menuVisible;
@property(nonatomic,readonly) CGRect menuFrame;
#else  /* OBJC2 */
// TODO
#endif /* OBJC2 */

@end

UIKIT_EXTERN NSString *const UIMenuControllerWillShowMenuNotification;
UIKIT_EXTERN NSString *const UIMenuControllerDidShowMenuNotification;
UIKIT_EXTERN NSString *const UIMenuControllerWillHideMenuNotification;
UIKIT_EXTERN NSString *const UIMenuControllerDidHideMenuNotification;
UIKIT_EXTERN NSString *const UIMenuControllerMenuFrameDidChangeNotification;
