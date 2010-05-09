#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIKitDefines.h>

UIKIT_EXTERN_CLASS @interface UIScreen : NSObject {

}

+ (UIScreen *)mainScreen;

#ifdef OBJC2
@property(nonatomic,readonly) CGRect bounds;    
@property(nonatomic,readonly) CGRect applicationFrame;
#else  /* OBJC2 */
// TODO
#endif /* OBJC2 */

@end
