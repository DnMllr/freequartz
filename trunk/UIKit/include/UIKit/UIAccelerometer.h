#import <Foundation/Foundation.h>
#import <UIKit/UIKitDefines.h>

typedef double UIAccelerationValue;

@protocol UIAccelerometerDelegate;

UIKIT_EXTERN_CLASS @interface UIAcceleration : NSObject {
  @private
    NSTimeInterval timestamp;
    UIAccelerationValue x, y, z;
}

#ifdef OBJC2
@property(nonatomic,readonly) NSTimeInterval timestamp;
@property(nonatomic,readonly) UIAccelerationValue x;
@property(nonatomic,readonly) UIAccelerationValue y;
@property(nonatomic,readonly) UIAccelerationValue z;
#else /* OBJC2 */

#endif /* OBJC2 */

@end

UIKIT_EXTERN_CLASS @interface UIAccelerometer : NSObject {

    struct {
        //TODO
    } _uiaccelerometerFlags;
}

+ (UIAccelerometer *)sharedAccelerometer;

#ifdef OBJC2
@property(nonatomic) NSTimeInterval updateInterval; 
@property(nonatomic,assign) id<UIAccelerometerDelegate> delegate;
#else /* OBJC2 */
#endif /* OBJC2 */

@end

@protocol UIAccelerometerDelegate<NSObject>
@optional

- (void)accelerometer:(UIAccelerometer *)accelerometer didAccelerate:(UIAcceleration *)acceleration;

@end
