#import <Foundation/Foundation.h>
#import <UIKit/UIViewController.h>
#import <UIKit/UITableView.h>
#import <UIKit/UIKitDefines.h>



UIKIT_EXTERN_CLASS @interface UITableViewController : UIViewController <UITableViewDelegate, UITableViewDataSource> {

}

- (id)initWithStyle:(UITableViewStyle)style;

#ifdef OBJC2
@property(nonatomic,retain) UITableView *tableView;
#else  /* OBJC2 */
// TODO
#endif /* OBJC2 */

@end
