#import <Foundation/Foundation.h>
#import <UIKit/UIGeometry.h>
#import <UIKit/UIKitDefines.h>

@class UIImage;

UIKIT_EXTERN_CLASS @interface UIBarItem : NSObject {
}

#ifdef OBJC2
@property(nonatomic,getter=isEnabled) BOOL        enabled;      
@property(nonatomic,copy)             NSString    *title;        
@property(nonatomic,retain)           UIImage     *image;        
@property(nonatomic)                  UIEdgeInsets imageInsets;  
@property(nonatomic)                  NSInteger    tag;
#else /* OBJC2 */
//TODO
#endif /* OBJC2 */

         
@end
