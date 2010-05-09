#import <Foundation/Foundation.h>
#import <UIKit/UIResponder.h>
#import <UIKit/UIInterface.h>
#import <UIKit/UIKitDefines.h>

typedef enum {

    UIViewAnimationCurveEaseInOut,         
    UIViewAnimationCurveEaseIn,            
    UIViewAnimationCurveEaseOut,           
    UIViewAnimationCurveLinear
} UIViewAnimationCurve;

typedef enum {

    UIViewContentModeScaleToFill,
    UIViewContentModeScaleAspectFit,      
    UIViewContentModeScaleAspectFill,     
    UIViewContentModeRedraw,              
    UIViewContentModeCenter,              
    UIViewContentModeTop,
    UIViewContentModeBottom,
    UIViewContentModeLeft,
    UIViewContentModeRight,
    UIViewContentModeTopLeft,
    UIViewContentModeTopRight,
    UIViewContentModeBottomLeft,
    UIViewContentModeBottomRight,
} UIViewContentMode;

typedef enum {
    UIViewAnimationTransitionNone,
    UIViewAnimationTransitionFlipFromLeft,
    UIViewAnimationTransitionFlipFromRight,
    UIViewAnimationTransitionCurlUp,
    UIViewAnimationTransitionCurlDown,
} UIViewAnimationTransition;

enum {
    UIViewAutoresizingNone                 = 0,
    UIViewAutoresizingFlexibleLeftMargin   = 1 << 0,
    UIViewAutoresizingFlexibleWidth        = 1 << 1,
    UIViewAutoresizingFlexibleRightMargin  = 1 << 2,
    UIViewAutoresizingFlexibleTopMargin    = 1 << 3,
    UIViewAutoresizingFlexibleHeight       = 1 << 4,
    UIViewAutoresizingFlexibleBottomMargin = 1 << 5
};
typedef NSUInteger UIViewAutoresizing;

@class UIEvent, UIWindow, UIColor, CALayer;

UIKIT_EXTERN_CLASS @interface UIView : UIResponder<NSCoding> {

    struct {

    } _uiviewFlags;
}

+ (Class)layerClass;                        

- (id)initWithFrame:(CGRect)frame;          

#ifdef OBJC2
@property(nonatomic,getter=isUserInteractionEnabled) BOOL userInteractionEnabled;  
@property(nonatomic)                                 NSInteger tag;               
@property(nonatomic,readonly,retain)                 CALayer  *layer;             
#else
- (BOOL)isUserInteractionEnabled;
- (void)setUserInteractionEnabled:(BOOL)i;
- (NSInteger)tag;
- (void)setTag:(NSInteger)tag;
- (CALayer  *)layer;
#endif /* OBJC2 */

@end

@interface UIView(UIViewGeometry)

// Properties
#ifdef OBJC2
@property(nonatomic) CGRect            frame;
@property(nonatomic) CGRect            bounds;      
@property(nonatomic) CGPoint           center;      
@property(nonatomic) CGAffineTransform transform; 
@property(nonatomic,getter=isMultipleTouchEnabled) BOOL multipleTouchEnabled;   
@property(nonatomic,getter=isExclusiveTouch) BOOL       exclusiveTouch;         
@property(nonatomic) BOOL               autoresizesSubviews; 
@property(nonatomic) UIViewAutoresizing autoresizingMask;
#else /* OBJC2 */
- (CGRect)frame;
- (void)setFrame:(CGRect)theFrame;
- (CGRect)bounds;
- (void)setBounds:(CGRect)theBounds;
- (CGPoint)center;
- (void)setCenter:(CGPoint)theCenter;
- (CGAffineTransform)transform;
- (void)setTransform:(CGAffineTransform)theTransform;
- (BOOL)isMultipleTouchEnabled;
- (void)setMultipleTouchEnabled:(BOOL)enableMultiTouch;
- (BOOL)isExclusiveTouch;
- (void)setExclusiveTouch:(BOOL)theExclusiveTouch;
- (BOOL)autoresizesSubviews;
- (void)setAutoresizesSubviews:(BOOL)allowSubViewResize;
- (UIViewAutoresizing)autoresizingMask;
- (void)setAutoresizingMask:(UIViewAutoresizing)theResizingMask;
#endif /* OBJC2 */

- (UIView *)hitTest:(CGPoint)point withEvent:(UIEvent *)event;   
- (BOOL)pointInside:(CGPoint)point withEvent:(UIEvent *)event;   
- (CGPoint)convertPoint:(CGPoint)point toView:(UIView *)view;
- (CGPoint)convertPoint:(CGPoint)point fromView:(UIView *)view;
- (CGRect)convertRect:(CGRect)rect toView:(UIView *)view;
- (CGRect)convertRect:(CGRect)rect fromView:(UIView *)view;
- (CGSize)sizeThatFits:(CGSize)size;     
- (void)sizeToFit;
                       


@end

@interface UIView(UIViewHierarchy)

// Properties
#ifdef OBJC2
@property(nonatomic,readonly) UIView       *superview;
@property(nonatomic,readonly,copy) NSArray *subviews;
@property(nonatomic,readonly) UIWindow     *window;
#else /* OBJC2 */
- (UIView *)superview;
- (void)setSuperview:(UIView *)theSuperview;
- (NSArray *)subviews;
- (UIWindow *)window;
#endif /* OBJC2 */

- (void)removeFromSuperview;
- (void)insertSubview:(UIView *)view atIndex:(NSInteger)index;
- (void)exchangeSubviewAtIndex:(NSInteger)index1 withSubviewAtIndex:(NSInteger)index2;

- (void)addSubview:(UIView *)view;
- (void)insertSubview:(UIView *)view belowSubview:(UIView *)siblingSubview;
- (void)insertSubview:(UIView *)view aboveSubview:(UIView *)siblingSubview;

- (void)bringSubviewToFront:(UIView *)view;
- (void)sendSubviewToBack:(UIView *)view;

- (void)didAddSubview:(UIView *)subview;
- (void)willRemoveSubview:(UIView *)subview;

- (void)willMoveToSuperview:(UIView *)newSuperview;
- (void)didMoveToSuperview;
- (void)willMoveToWindow:(UIWindow *)newWindow;
- (void)didMoveToWindow;

- (BOOL)isDescendantOfView:(UIView *)view;  
- (UIView *)viewWithTag:(NSInteger)tag;     
- (void)setNeedsLayout;
- (void)layoutIfNeeded;
- (void)layoutSubviews;

@end

@interface UIView(UIViewRendering)

- (void)drawRect:(CGRect)rect;
- (void)setNeedsDisplay;
- (void)setNeedsDisplayInRect:(CGRect)rect;

#ifdef OBJC2
@property(nonatomic)                 BOOL              clipsToBounds;              
@property(nonatomic,copy)            UIColor          *backgroundColor;            
@property(nonatomic)                 CGFloat           alpha;                      
@property(nonatomic,getter=isOpaque) BOOL              opaque;                     
@property(nonatomic)                 BOOL              clearsContextBeforeDrawing; 
@property(nonatomic,getter=isHidden) BOOL              hidden;                     
@property(nonatomic)                 UIViewContentMode contentMode;                
@property(nonatomic)                 CGRect            contentStretch;
#else /* OBJC2 */
- (BOOL)clipsToBounds;
- (void)setClipsToBounds:(BOOL)allowClipsToBound;
- (UIColor *)backgroundColor;
- (void)setBackgroundColor:(UIColor *)theBackgroundColor;
- (CGFloat)alpha;
- (void)setAlpha:(CGFloat)theAlpha;
- (BOOL)isOpaque;
- (void)setOpaque:(BOOL)allowOpaque;
- (BOOL)clearsContextBeforeDrawing;
- (void)setClearsContextBeforeDrawing:(BOOL)clearCtxBeforeDraw;
- (BOOL)isHidden;
- (void)setHidden:(BOOL)hiddenFlag;
- (UIViewContentMode)contentMode;
- (void)setContentMode:(UIViewContentMode)theContentMode;
#endif /* OBJC2 */

@end

@interface UIView(UIViewAnimation)

+ (void)beginAnimations:(NSString *)animationID context:(void *)context;  
+ (void)commitAnimations;                                                 
+ (void)setAnimationDelegate:(id)delegate;                          
+ (void)setAnimationWillStartSelector:(SEL)selector;                
+ (void)setAnimationDidStopSelector:(SEL)selector;                  
+ (void)setAnimationDuration:(NSTimeInterval)duration;              
+ (void)setAnimationDelay:(NSTimeInterval)delay;                    
+ (void)setAnimationStartDate:(NSDate *)startDate;                  
+ (void)setAnimationCurve:(UIViewAnimationCurve)curve;              
+ (void)setAnimationRepeatCount:(float)repeatCount;                 
+ (void)setAnimationRepeatAutoreverses:(BOOL)repeatAutoreverses;    
+ (void)setAnimationBeginsFromCurrentState:(BOOL)fromCurrentState;  

+ (void)setAnimationTransition:(UIViewAnimationTransition)transition forView:(UIView *)view cache:(BOOL)cache;  

+ (void)setAnimationsEnabled:(BOOL)enabled;                         
+ (BOOL)areAnimationsEnabled;

@end
