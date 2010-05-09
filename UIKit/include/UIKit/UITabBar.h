#import <Foundation/Foundation.h>
#import <UIKit/UIKitDefines.h>
#import <UIKit/UIView.h>

@class UITabBarItem;
@protocol UITabBarDelegate;

UIKIT_EXTERN_CLASS @interface UITabBar : UIView {
 
    struct {
 
    } _uitabBarFlags;
    
}

- (BOOL)isCustomizing;
- (void)beginCustomizingItems:(NSArray *)items;   
- (BOOL)endCustomizingAnimated:(BOOL)animated;    
- (void)setItems:(NSArray *)items animated:(BOOL)animated;

#ifdef OBJC2
@property(nonatomic,assign) id<UITabBarDelegate> delegate;     
@property(nonatomic,copy)   NSArray             *items;        
@property(nonatomic,assign) UITabBarItem        *selectedItem; 
#else  /* OBJC2 */
// TODO
#endif /* OBJC2 */

@end


@protocol UITabBarDelegate<NSObject>
@optional

- (void)tabBar:(UITabBar *)tabBar didSelectItem:(UITabBarItem *)item; 
- (void)tabBar:(UITabBar *)tabBar willBeginCustomizingItems:(NSArray *)items;
- (void)tabBar:(UITabBar *)tabBar didBeginCustomizingItems:(NSArray *)items; 
- (void)tabBar:(UITabBar *)tabBar willEndCustomizingItems:(NSArray *)items changed:(BOOL)changed; 
- (void)tabBar:(UITabBar *)tabBar didEndCustomizingItems:(NSArray *)items changed:(BOOL)changed;  

@end
