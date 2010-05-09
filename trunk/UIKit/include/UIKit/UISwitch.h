#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIControl.h>
#import <UIKit/UIKitDefines.h>

UIKIT_EXTERN_CLASS @interface UISwitch : UIControl <NSCoding> {

}

- (id)initWithFrame:(CGRect)frame;              
- (void)setOn:(BOOL)on animated:(BOOL)animated; 

#ifdef OBJC2
@property(nonatomic,getter=isOn) BOOL on;
#else  /* OBJC2 */
// TODO
#endif /* OBJC2 */


@end
