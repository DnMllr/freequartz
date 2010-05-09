#import <Foundation/Foundation.h>
#import <UIKit/UIKitDefines.h>
#import <UIKit/UIApplication.h>

@class UIView;
@class UIBarButtonItem, UITabBarItem;
@class UISearchDisplayController;


typedef enum {

	UIModalTransitionStyleCoverVertical = 0,
	UIModalTransitionStyleFlipHorizontal,
    UIModalTransitionStyleCrossDissolve
} UIModalTransitionStyle;

UIKIT_EXTERN_CLASS @interface UIViewController : UIResponder <NSCoding> {
    
    struct {

    } _uiviewControllerFlags;
}


- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil;
- (void)loadView; 
- (void)viewDidLoad; 
- (void)viewDidUnload;
- (BOOL)isViewLoaded;
- (void)viewWillAppear:(BOOL)animated;    
- (void)viewDidAppear:(BOOL)animated;     
- (void)viewWillDisappear:(BOOL)animated; 
- (void)viewDidDisappear:(BOOL)animated;  
- (void)didReceiveMemoryWarning; 
- (void)presentModalViewController:(UIViewController *)modalViewController animated:(BOOL)animated; 
- (void)dismissModalViewControllerAnimated:(BOOL)animated; 

#ifdef OBJC2
@property(nonatomic,retain) UIView *view; 
@property(nonatomic, readonly, copy) NSString *nibName;     
@property(nonatomic, readonly, retain) NSBundle *nibBundle; 
@property(nonatomic,copy) NSString *title;  
@property(nonatomic,readonly) UIViewController *modalViewController;
@property(nonatomic,assign) UIModalTransitionStyle modalTransitionStyle ;
@property(nonatomic,assign) BOOL wantsFullScreenLayout;
@property(nonatomic,readonly) UIViewController *parentViewController; 
#else  /* OBJC2 */
// TODO
#endif /* OBJC2 */

@end


@interface UIViewController (UIViewControllerRotation)

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)toInterfaceOrientation; 
- (UIView *)rotatingHeaderView;     
- (UIView *)rotatingFooterView;     
- (void)willRotateToInterfaceOrientation:(UIInterfaceOrientation)toInterfaceOrientation duration:(NSTimeInterval)duration;
- (void)didRotateFromInterfaceOrientation:(UIInterfaceOrientation)fromInterfaceOrientation;
- (void)willAnimateRotationToInterfaceOrientation:(UIInterfaceOrientation)toInterfaceOrientation duration:(NSTimeInterval)duration;
- (void)willAnimateFirstHalfOfRotationToInterfaceOrientation:(UIInterfaceOrientation)toInterfaceOrientation duration:(NSTimeInterval)duration;
- (void)didAnimateFirstHalfOfRotationToInterfaceOrientation:(UIInterfaceOrientation)toInterfaceOrientation; 
- (void)willAnimateSecondHalfOfRotationFromInterfaceOrientation:(UIInterfaceOrientation)fromInterfaceOrientation duration:(NSTimeInterval)duration; 

#ifdef OBJC2
@property(nonatomic,readonly) UIInterfaceOrientation interfaceOrientation;
#else  /* OBJC2 */
// TODO
#endif /* OBJC2 */

@end

@interface UIViewController (UIViewControllerEditing)

- (void)setEditing:(BOOL)editing animated:(BOOL)animated; 
- (UIBarButtonItem *)editButtonItem; 

#ifdef OBJC2
@property(nonatomic,getter=isEditing) BOOL editing;
#else  /* OBJC2 */
// TODO
#endif /* OBJC2 */

@end

@interface UIViewController (UISearchDisplayControllerSupport)

#ifdef OBJC2
@property(nonatomic, readonly, retain) UISearchDisplayController *searchDisplayController;
#else  /* OBJC2 */
// TODO
#endif /* OBJC2 */

@end
