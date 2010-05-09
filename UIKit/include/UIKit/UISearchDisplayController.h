#import <Foundation/Foundation.h>
#import <UIKit/UIView.h>
#import <UIKit/UIKitDefines.h>
#import <UIKit/UILabel.h>

@class UISearchBar, UITableView, UIViewController;
@protocol UITableViewDataSource, UITableViewDelegate, UISearchDisplayDelegate;

UIKIT_EXTERN_CLASS @interface UISearchDisplayController : NSObject {

    struct {
        
    } _uisearchDisplayControllerFlags;
}

- (id)initWithSearchBar:(UISearchBar *)searchBar contentsController:(UIViewController *)viewController;
- (void)setActive:(BOOL)visible animated:(BOOL)animated;       

#ifdef OBJC2
@property(nonatomic,assign) id<UISearchDisplayDelegate> delegate;
@property(nonatomic,getter=isActive) BOOL active;  
@property(nonatomic,readonly) UISearchBar                *searchBar;
@property(nonatomic,readonly) UIViewController           *searchContentsController; 
@property(nonatomic,readonly) UITableView                *searchResultsTableView;   
@property(nonatomic,assign)   id<UITableViewDataSource>   searchResultsDataSource;  
@property(nonatomic,assign)   id<UITableViewDelegate>     searchResultsDelegate;    
#else  /* OBJC2 */
// TODO
#endif /* OBJC2 */

@end

@protocol UISearchDisplayDelegate <NSObject>

@optional

- (void) searchDisplayControllerWillBeginSearch:(UISearchDisplayController *)controller;
- (void) searchDisplayControllerDidBeginSearch:(UISearchDisplayController *)controller;
- (void) searchDisplayControllerWillEndSearch:(UISearchDisplayController *)controller;
- (void) searchDisplayControllerDidEndSearch:(UISearchDisplayController *)controller;
- (void)searchDisplayController:(UISearchDisplayController *)controller didLoadSearchResultsTableView:(UITableView *)tableView;
- (void)searchDisplayController:(UISearchDisplayController *)controller willUnloadSearchResultsTableView:(UITableView *)tableView;
- (void)searchDisplayController:(UISearchDisplayController *)controller willShowSearchResultsTableView:(UITableView *)tableView;
- (void)searchDisplayController:(UISearchDisplayController *)controller didShowSearchResultsTableView:(UITableView *)tableView;
- (void)searchDisplayController:(UISearchDisplayController *)controller willHideSearchResultsTableView:(UITableView *)tableView;
- (void)searchDisplayController:(UISearchDisplayController *)controller didHideSearchResultsTableView:(UITableView *)tableView;
- (BOOL)searchDisplayController:(UISearchDisplayController *)controller shouldReloadTableForSearchString:(NSString *)searchString;
- (BOOL)searchDisplayController:(UISearchDisplayController *)controller shouldReloadTableForSearchScope:(NSInteger)searchOption;

@end

#endif
