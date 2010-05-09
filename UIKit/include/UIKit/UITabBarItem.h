#import <Foundation/Foundation.h>
#import <UIKit/UIBarItem.h>
#import <UIKit/UIGeometry.h>
#import <UIKit/UIKitDefines.h>

typedef enum {

    UITabBarSystemItemMore,
    UITabBarSystemItemFavorites,
    UITabBarSystemItemFeatured,
    UITabBarSystemItemTopRated,
    UITabBarSystemItemRecents,
    UITabBarSystemItemContacts,
    UITabBarSystemItemHistory,
    UITabBarSystemItemBookmarks,
    UITabBarSystemItemSearch,
    UITabBarSystemItemDownloads,
    UITabBarSystemItemMostRecent,
    UITabBarSystemItemMostViewed,
} UITabBarSystemItem;

@class UIView, UIImage;

UIKIT_EXTERN_CLASS @interface UITabBarItem : UIBarItem {

    struct {

    } _uitabBarItemFlags;
}

- (id)initWithTitle:(NSString *)title image:(UIImage *)image tag:(NSInteger)tag; 
- (id)initWithTabBarSystemItem:(UITabBarSystemItem)systemItem tag:(NSInteger)tag;

#ifdef OBJC2
@property(nonatomic,copy) NSString *badgeValue;    
#else  /* OBJC2 */
// TODO
#endif /* OBJC2 */

@end
