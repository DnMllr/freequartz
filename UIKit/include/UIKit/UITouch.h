#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIKitDefines.h>

@class UIView, UIWindow;

typedef enum {

    UITouchPhaseBegan,             
    UITouchPhaseMoved,             
    UITouchPhaseStationary,        
    UITouchPhaseEnded,             
    UITouchPhaseCancelled,         
} UITouchPhase;

UIKIT_EXTERN_CLASS @interface UITouch : NSObject
{
  
    struct {
  
    } _uitouchFlags;
}

- (CGPoint)locationInView:(UIView *)view;
- (CGPoint)previousLocationInView:(UIView *)view;

#ifdef OBJC2
@property(nonatomic,readonly) NSTimeInterval timestamp;
@property(nonatomic,readonly) UITouchPhase phase;
@property(nonatomic,readonly) NSUInteger tapCount;   
@property(nonatomic,readonly,retain) UIWindow *window;
@property(nonatomic,readonly,retain) UIView *view;
#else  /* OBJC2 */
// TODO
#endif /* OBJC2 */


@end
