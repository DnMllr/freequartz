#import <UIKit/UIView.h>
#import <UIKit/UIKitDefines.h>

typedef enum {
    UIActivityIndicatorViewStyleWhiteLarge,
    UIActivityIndicatorViewStyleWhite,
    UIActivityIndicatorViewStyleGray,
} UIActivityIndicatorViewStyle;

UIKIT_EXTERN_CLASS @interface UIActivityIndicatorView : UIView <NSCoding>
{ 
  //TODO
}

- (id)initWithActivityIndicatorStyle:(UIActivityIndicatorViewStyle)style;
- (void)startAnimating;
- (void)stopAnimating;
- (BOOL)isAnimating;

#ifdef OBJC2
@property(nonatomic) UIActivityIndicatorViewStyle activityIndicatorViewStyle; 
@property(nonatomic) BOOL hidesWhenStopped;           
#else /* OBJC2 */
- (UIActivityIndicatorViewStyle)activityIndicatorViewStyle;
- (void)setActivityIndicatorViewStyle:(UIActivityIndicatorViewStyle)theActivityIndicatorViewStyle;
- (BOOL)hidesWhenStopped;
- (void)setHidesWhenStopped:(BOOL)hidesWhenStoppedFlag;
#endif /* OBJC2 */

@end
