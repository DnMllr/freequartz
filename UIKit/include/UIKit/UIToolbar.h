#import <Foundation/Foundation.h>
#import <UIKit/UIKitDefines.h>
#import <UIKit/UIView.h>
#import <UIKit/UIInterface.h>

@class UIBarButtonItem, UIColor;

UIKIT_EXTERN_CLASS @interface UIToolbar : UIView {

    struct {

    } _uitoolbarFlags;
        
}
- (void)setItems:(NSArray *)items animated:(BOOL)animated;

#ifdef OBJC2
@property(nonatomic)        UIBarStyle barStyle;    
@property(nonatomic,copy)   NSArray   *items;       
@property(nonatomic,retain) UIColor   *tintColor;   
@property(nonatomic,assign,getter=isTranslucent) BOOL translucent;
#else  /* OBJC2 */
// TODO
#endif /* OBJC2 */
   

@end
