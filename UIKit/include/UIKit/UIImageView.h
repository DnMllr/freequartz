#import <Foundation/Foundation.h>
#import <UIKit/UIView.h>
#import <UIKit/UIKitDefines.h>

@class UIImage;

UIKIT_EXTERN_CLASS @interface UIImageView : UIView {

}
- (id)initWithImage:(UIImage *)image;
- (id)initWithImage:(UIImage *)image highlightedImage:(UIImage *)highlightedImage;

- (void)startAnimating;
- (void)stopAnimating;
- (BOOL)isAnimating;

#ifdef OBJC2
@property(nonatomic,retain) UIImage *image;                                      
@property(nonatomic,retain) UIImage *highlightedImage;
@property(nonatomic,getter=isUserInteractionEnabled) BOOL userInteractionEnabled;
@property(nonatomic,getter=isHighlighted) BOOL highlighted;
@property(nonatomic,copy) NSArray *animationImages;
@property(nonatomic,copy) NSArray *highlightedAnimationImages;
@property(nonatomic) NSTimeInterval animationDuration;         
@property(nonatomic) NSInteger animationRepeatCount;
#else  /* OBJC2 */
// TODO
#endif /* OBJC2 */


@end
