#import <Foundation/Foundation.h>
#import <UIKit/UIView.h>
#import <UIKit/UIKitDefines.h>

typedef enum {
    UIProgressViewStyleDefault,     
    UIProgressViewStyleBar,         
} UIProgressViewStyle;

UIKIT_EXTERN_CLASS @interface UIProgressView : UIView <NSCoding>
{ 
  
}

- (id)initWithProgressViewStyle:(UIProgressViewStyle)style; 

#ifdef OBJC2
@property(nonatomic) UIProgressViewStyle progressViewStyle; 
@property(nonatomic) float progress;                        
#else  /* OBJC2 */
// TODO
#endif /* OBJC2 */

@end
