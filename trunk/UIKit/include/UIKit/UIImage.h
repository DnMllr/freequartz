#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIKitDefines.h>
#import <UIKit/UIColor.h>

typedef enum {
    UIImageOrientationUp,            
    UIImageOrientationDown,          
    UIImageOrientationLeft,          
    UIImageOrientationRight,         
    UIImageOrientationUpMirrored,    
    UIImageOrientationDownMirrored,  
    UIImageOrientationLeftMirrored,  
    UIImageOrientationRightMirrored, 
} UIImageOrientation;

UIKIT_EXTERN_CLASS @interface UIImage : NSObject {
  
    struct {
	
    } _uiimageFlags;
}

+ (UIImage *)imageNamed:(NSString *)name;      
+ (UIImage *)imageWithContentsOfFile:(NSString *)path;
+ (UIImage *)imageWithData:(NSData *)data;
+ (UIImage *)imageWithCGImage:(CGImageRef)imageRef;

- (id)initWithContentsOfFile:(NSString *)path;
- (id)initWithData:(NSData *)data;
- (id)initWithCGImage:(CGImageRef)imageRef;

- (void)drawAtPoint:(CGPoint)point;       
- (void)drawAtPoint:(CGPoint)point blendMode:(CGBlendMode)blendMode alpha:(CGFloat)alpha;
- (void)drawInRect:(CGRect)rect;                                                         
- (void)drawInRect:(CGRect)rect blendMode:(CGBlendMode)blendMode alpha:(CGFloat)alpha;
- (void)drawAsPatternInRect:(CGRect)rect; 



- (UIImage *)stretchableImageWithLeftCapWidth:(NSInteger)leftCapWidth topCapHeight:(NSInteger)topCapHeight;

#ifdef OBJC2
@property(nonatomic,readonly) CGSize size;             
@property(nonatomic,readonly) CGImageRef CGImage;          
@property(nonatomic,readonly) UIImageOrientation imageOrientation; 
@property(nonatomic,readonly) NSInteger leftCapWidth;   
@property(nonatomic,readonly) NSInteger topCapHeight; 
#else  /* OBJC2 */
// TODO
#endif /* OBJC2 */

@end

UIKIT_EXTERN NSData *UIImagePNGRepresentation(UIImage *image);  
UIKIT_EXTERN NSData *UIImageJPEGRepresentation(UIImage *image, CGFloat compressionQuality);
