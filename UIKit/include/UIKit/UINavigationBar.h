#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIView.h>
#import <UIKit/UIInterface.h>
#import <UIKit/UIFont.h>
#import <UIKit/UIKitDefines.h>
#import <UIKit/UIButton.h>

@class UINavigationItem, UIBarButtonItem, UIImage, UIColor;
@protocol UINavigationBarDelegate;

UIKIT_EXTERN_CLASS @interface UINavigationBar : UIView <NSCoding> {

    struct {

    } _uinavigationbarFlags;
}

- (void)pushNavigationItem:(UINavigationItem *)item animated:(BOOL)animated;
- (UINavigationItem *)popNavigationItemAnimated:(BOOL)animated; 
- (void)setItems:(NSArray *)items animated:(BOOL)animated; 

#ifdef OBJC2
@property(nonatomic,assign) UIBarStyle barStyle;
@property(nonatomic,assign) id delegate;
@property(nonatomic,retain) UIColor *tintColor;
@property(nonatomic,assign,getter=isTranslucent) BOOL translucent;
@property(nonatomic,readonly,retain) UINavigationItem *topItem;
@property(nonatomic,readonly,retain) UINavigationItem *backItem;
@property(nonatomic,copy) NSArray *items;
#else  /* OBJC2 */
// TODO
#endif /* OBJC2 */

@end

@protocol UINavigationBarDelegate <NSObject>

@optional

- (BOOL)navigationBar:(UINavigationBar *)navigationBar shouldPushItem:(UINavigationItem *)item; 
- (void)navigationBar:(UINavigationBar *)navigationBar didPushItem:(UINavigationItem *)item;    
- (BOOL)navigationBar:(UINavigationBar *)navigationBar shouldPopItem:(UINavigationItem *)item;  
- (void)navigationBar:(UINavigationBar *)navigationBar didPopItem:(UINavigationItem *)item;

@end

UIKIT_EXTERN_CLASS @interface UINavigationItem : NSObject <NSCoding> {

}

- (id)initWithTitle:(NSString *)title;
- (void)setHidesBackButton:(BOOL)hidesBackButton animated:(BOOL)animated;
- (void)setLeftBarButtonItem:(UIBarButtonItem *)item animated:(BOOL)animated;
- (void)setRightBarButtonItem:(UIBarButtonItem *)item animated:(BOOL)animated;

#ifdef OBJC2
@property(nonatomic,copy)   NSString *title;             
@property(nonatomic,retain) UIBarButtonItem *backBarButtonItem; 
@property(nonatomic,retain) UIView *titleView;         
@property(nonatomic,copy)   NSString *prompt;     
@property(nonatomic,assign) BOOL hidesBackButton; 
@property(nonatomic,retain) UIBarButtonItem *leftBarButtonItem;
@property(nonatomic,retain) UIBarButtonItem *rightBarButtonItem;
#else  /* OBJC2 */
// TODO
#endif /* OBJC2 */

@end
