#import <Foundation/Foundation.h>
#import <UIKit/UIView.h>
#import <UIKit/UIInterface.h>
#import <UIKit/UIGeometry.h>
#import <UIKit/UITextField.h>
#import <UIKit/UIKitDefines.h>

@protocol UISearchBarDelegate;
@class UITextField, UILabel, UIButton, UIColor;

UIKIT_EXTERN_CLASS @interface UISearchBar : UIView { 

    struct {

    } _uisearchBarFlags;
}

- (void)setShowsCancelButton:(BOOL)showsCancelButton animated:(BOOL)animated;

#ifdef OBJC2
@property(nonatomic,assign) id<UISearchBarDelegate> delegate;
@property(nonatomic) UIBarStyle barStyle;              
@property(nonatomic,copy) NSString *text;                  
@property(nonatomic,copy) NSString *prompt;                
@property(nonatomic,copy) NSString *placeholder;           
@property(nonatomic) BOOL showsBookmarkButton;   
@property(nonatomic) BOOL showsCancelButton;     
@property(nonatomic,retain) UIColor *tintColor;             
@property(nonatomic,assign,getter=isTranslucent) BOOL translucent;
@property(nonatomic) UITextAutocapitalizationType autocapitalizationType;  
@property(nonatomic) UITextAutocorrectionType autocorrectionType;      
@property(nonatomic) UIKeyboardType keyboardType;
@property(nonatomic,copy) NSArray *scopeButtonTitles;
@property(nonatomic) NSInteger selectedScopeButtonIndex;
@property(nonatomic) BOOLshowsScopeBar;
#else  /* OBJC2 */
// TODO
#endif /* OBJC2 */

@end

@protocol UISearchBarDelegate <NSObject>

@optional

- (BOOL)searchBarShouldBeginEditing:(UISearchBar *)searchBar;                      
- (void)searchBarTextDidBeginEditing:(UISearchBar *)searchBar;                     
- (BOOL)searchBarShouldEndEditing:(UISearchBar *)searchBar;                        
- (void)searchBarTextDidEndEditing:(UISearchBar *)searchBar;                       
- (void)searchBar:(UISearchBar *)searchBar textDidChange:(NSString *)searchText;   
- (BOOL)searchBar:(UISearchBar *)searchBar shouldChangeTextInRange:(NSRange)range replacementText:(NSString *)text;
- (void)searchBarSearchButtonClicked:(UISearchBar *)searchBar;
- (void)searchBarBookmarkButtonClicked:(UISearchBar *)searchBar;
- (void)searchBarCancelButtonClicked:(UISearchBar *) searchBar; 
- (void)searchBar:(UISearchBar *)searchBar selectedScopeButtonIndexDidChange:(NSInteger)selectedScope;

@end
