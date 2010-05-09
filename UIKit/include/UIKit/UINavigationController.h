#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIViewController.h>
#import <UIKit/UIKitDefines.h>
#import <UIKit/UIInterface.h>
#import <UIKit/UIGeometry.h>



UIKIT_EXTERN const CGFloat UINavigationControllerHideShowBarDuration;

@class UIView, UINavigationBar, UINavigationItem, UIToolbar;
@protocol UINavigationControllerDelegate;

UIKIT_EXTERN_CLASS @interface UINavigationController : UIViewController {
  
    
    struct {
       
    } _uinavigationControllerFlags;
}

- (id)initWithRootViewController:(UIViewController *)rootViewController; 
- (void)pushViewController:(UIViewController *)viewController animated:(BOOL)animated; 
- (UIViewController *)popViewControllerAnimated:(BOOL)animated; 
- (NSArray *)popToViewController:(UIViewController *)viewController animated:(BOOL)animated;
- (NSArray *)popToRootViewControllerAnimated:(BOOL)animated; 
- (void)setViewControllers:(NSArray *)viewControllers animated:(BOOL)animated; 
- (void)setNavigationBarHidden:(BOOL)hidden animated:(BOOL)animated; 
- (void)setToolbarHidden:(BOOL)hidden animated:(BOOL)animated;

#ifdef OBJC2
@property(nonatomic,readonly,retain) UIViewController *topViewController; 
@property(nonatomic,readonly,retain) UIViewController *visibleViewController; 
@property(nonatomic,copy) NSArray *viewControllers; 
@property(nonatomic,getter=isNavigationBarHidden) BOOL navigationBarHidden;
@property(nonatomic,readonly) UINavigationBar *navigationBar;
@property(nonatomic,getter=isToolbarHidden) BOOL toolbarHidden;
@property(nonatomic,readonly) UIToolbar *toolbar;
@property(nonatomic, assign) id<UINavigationControllerDelegate> delegate;
#else  /* OBJC2 */
// TODO
#endif /* OBJC2 */

@end

@protocol UINavigationControllerDelegate <NSObject>

@optional


- (void)navigationController:(UINavigationController *)navigationController willShowViewController:(UIViewController *)viewController animated:(BOOL)animated;
- (void)navigationController:(UINavigationController *)navigationController didShowViewController:(UIViewController *)viewController animated:(BOOL)animated;

@end

@interface UIViewController (UINavigationControllerItem)

#ifdef OBJC2
@property(nonatomic,readonly,retain) UINavigationItem *navigationItem; 
@property(nonatomic) BOOL hidesBottomBarWhenPushed; 
@property(nonatomic,readonly,retain) UINavigationController *navigationController; 
#else  /* OBJC2 */
// TODO
#endif /* OBJC2 */
@end

@interface UIViewController (UINavigationControllerContextualToolbarItems)

- (void)setToolbarItems:(NSArray *)toolbarItems animated:(BOOL)animated;

#ifdef OBJC2
@property (nonatomic, retain) NSArray *toolbarItems;
#else  /* OBJC2 */
// TODO
#endif /* OBJC2 */

@end
