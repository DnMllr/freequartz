#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIView.h>
#import <UIKit/UIGeometry.h>
#import <UIKit/UIKitDefines.h>

typedef enum {
    UIScrollViewIndicatorStyleDefault,     
    UIScrollViewIndicatorStyleBlack,       
    UIScrollViewIndicatorStyleWhite        
} UIScrollViewIndicatorStyle;

UIKIT_EXTERN const float UIScrollViewDecelerationRateNormal;
UIKIT_EXTERN const float UIScrollViewDecelerationRateFast ;

@class UIEvent, UIImageView;
@protocol UIScrollViewDelegate;

UIKIT_EXTERN_CLASS @interface UIScrollView : UIView <NSCoding> {
  
    struct {
  
    } _uiscrollViewFlags;
}

- (void)setContentOffset:(CGPoint)contentOffset animated:(BOOL)animated;  
- (void)scrollRectToVisible:(CGRect)rect animated:(BOOL)animated;         
- (void)flashScrollIndicators;             
- (BOOL)touchesShouldBegin:(NSSet *)touches withEvent:(UIEvent *)event inContentView:(UIView *)view;   
- (BOOL)touchesShouldCancelInContentView:(UIView *)view;                                               
- (void)setZoomScale:(float)scale animated:(BOOL)animated;
- (void)zoomToRect:(CGRect)rect animated:(BOOL)animated;

#ifdef OBJC2
@property(nonatomic) CGSize contentSize;                    
@property(nonatomic) UIEdgeInsets contentInset;
@property(nonatomic) CGPoint contentOffset;                  
@property(nonatomic) BOOL bounces;                        
@property(nonatomic) BOOL alwaysBounceVertical;           
@property(nonatomic) BOOL alwaysBounceHorizontal;
@property(nonatomic,assign) id<UIScrollViewDelegate>      delegate;               
@property(nonatomic,getter=isDirectionalLockEnabled) BOOL directionalLockEnabled; 
@property(nonatomic,getter=isPagingEnabled) BOOL pagingEnabled;          
@property(nonatomic,getter=isScrollEnabled) BOOL scrollEnabled;          
@property(nonatomic) BOOL showsHorizontalScrollIndicator; 
@property(nonatomic) BOOL showsVerticalScrollIndicator;   
@property(nonatomic) UIEdgeInsets scrollIndicatorInsets;          
@property(nonatomic) UIScrollViewIndicatorStyle indicatorStyle;  
@property(nonatomic) float decelerationRate;
@property(nonatomic,readonly,getter=isTracking) BOOL tracking;
@property(nonatomic,readonly,getter=isDragging) BOOL dragging;
@property(nonatomic,readonly,getter=isDecelerating) BOOL decelerating;    
@property(nonatomic) BOOL delaysContentTouches;    
@property(nonatomic) BOOL canCancelContentTouches; 
@property(nonatomic) float minimumZoomScale;     
@property(nonatomic) float maximumZoomScale;     
@property(nonatomic) float zoomScale;
@property(nonatomic) BOOL  bouncesZoom;          
@property(nonatomic,readonly,getter=isZooming) BOOL zooming;       
@property(nonatomic,readonly,getter=isZoomBouncing) BOOL zoomBouncing;  
@property(nonatomic) BOOL  scrollsToTop;
#else  /* OBJC2 */
// TODO
#endif /* OBJC2 */

@end

@protocol UIScrollViewDelegate<NSObject>

@optional

- (void)scrollViewDidScroll:(UIScrollView *)scrollView;               
- (void)scrollViewWillBeginDragging:(UIScrollView *)scrollView;                              
- (void)scrollViewDidEndDragging:(UIScrollView *)scrollView willDecelerate:(BOOL)decelerate; 
- (void)scrollViewWillBeginDecelerating:(UIScrollView *)scrollView;   
- (void)scrollViewDidEndDecelerating:(UIScrollView *)scrollView;      
- (void)scrollViewDidEndScrollingAnimation:(UIScrollView *)scrollView; 
- (UIView *)viewForZoomingInScrollView:(UIScrollView *)scrollView;     
- (void)scrollViewDidEndZooming:(UIScrollView *)scrollView withView:(UIView *)view atScale:(float)scale; 
- (BOOL)scrollViewShouldScrollToTop:(UIScrollView *)scrollView;
- (void)scrollViewDidScrollToTop:(UIScrollView *)scrollView;

@end
