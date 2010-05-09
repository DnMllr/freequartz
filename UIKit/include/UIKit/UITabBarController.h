#import <Foundation/Foundation.h>
#import <UIKit/UIViewController.h>
#import <UIKit/UIKitDefines.h>
#import <UIKit/UITabBar.h>

@class UIView, UIImage, UINavigationController, UITabBarItem;
@protocol UITabBarControllerDelegate;

UIKIT_EXTERN_CLASS @interface UITabBarController : UIViewController <UITabBarDelegate, NSCoding> {

    struct {

    } _uitabBarControllerFlags;
}

- (void)setViewControllers:(NSArray *)viewControllers animated:(BOOL)animated;


#ifdef OBJC2
@property(nonatomic,copy) NSArray *viewControllers;
@property(nonatomic,assign) UIViewController *selectedViewController;
@property(nonatomic) NSUInteger selectedIndex;
@property(nonatomic,readonly) UINavigationController *moreNavigationController; 
@property(nonatomic,copy) NSArray *customizableViewControllers; 
@property(nonatomic,readonly) UITabBar *tabBar; 
@property(nonatomic,assign) id<UITabBarControllerDelegate> delegate;
#else  /* OBJC2 */
// TODO
#endif /* OBJC2 */


@end

@protocol UITabBarControllerDelegate <NSObject>
@optional

- (BOOL)tabBarController:(UITabBarController *)tabBarController shouldSelectViewController:(UIViewController *)viewController;
- (void)tabBarController:(UITabBarController *)tabBarController didSelectViewController:(UIViewController *)viewController;
- (void)tabBarController:(UITabBarController *)tabBarController willBeginCustomizingViewControllers:(NSArray *)viewControllers;
- (void)tabBarController:(UITabBarController *)tabBarController willEndCustomizingViewControllers:(NSArray *)viewControllers changed:(BOOL)changed;
- (void)tabBarController:(UITabBarController *)tabBarController didEndCustomizingViewControllers:(NSArray *)viewControllers changed:(BOOL)changed;

@end

@interface UIViewController (UITabBarControllerItem)

#ifdef OBJC2
@property(nonatomic,retain) UITabBarItem *tabBarItem; 
@property(nonatomic,readonly,retain) UITabBarController *tabBarController; 
#else  /* OBJC2 */
// TODO
#endif /* OBJC2 */

@end
