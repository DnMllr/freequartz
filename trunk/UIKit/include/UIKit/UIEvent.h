#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIKitDefines.h>

@class UIWindow, UIView;

typedef enum {
    UIEventTypeTouches,
    UIEventTypeMotion,
} UIEventType;

typedef enum {
    UIEventSubtypeNone        = 0,  
    UIEventSubtypeMotionShake = 1,
} UIEventSubtype;

UIKIT_EXTERN_CLASS @interface UIEvent : NSObject
{
  @private
    NSTimeInterval _timestamp;
}

#ifdef OBJC2
@property(nonatomic,readonly) UIEventType     type;
@property(nonatomic,readonly) UIEventSubtype  subtype;
@property(nonatomic,readonly) NSTimeInterval  timestamp;
#else  /*OBJC2*/
- (UIEventType)type;
- (UIEventType)subtype;
- (NSTimeInterval)timestamp;
#endif /*OBJC2*/

- (NSSet *)allTouches;
- (NSSet *)touchesForWindow:(UIWindow *)window;
- (NSSet *)touchesForView:(UIView *)view;

@end
