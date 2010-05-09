#import <Foundation/Foundation.h>
#import <UIKit/UINavigationController.h>
#import <UIKit/UIKitDefines.h>

@class UIImage;
@protocol UIImagePickerControllerDelegate;

enum {
    UIImagePickerControllerSourceTypePhotoLibrary,
    UIImagePickerControllerSourceTypeCamera,
    UIImagePickerControllerSourceTypeSavedPhotosAlbum
};
typedef NSUInteger UIImagePickerControllerSourceType;

enum {
    UIImagePickerControllerQualityTypeHigh,
    UIImagePickerControllerQualityTypeMedium,
    UIImagePickerControllerQualityTypeLow
};
typedef NSUInteger UIImagePickerControllerQualityType;


UIKIT_EXTERN NSString *const UIImagePickerControllerMediaType;      
UIKIT_EXTERN NSString *const UIImagePickerControllerOriginalImage;  
UIKIT_EXTERN NSString *const UIImagePickerControllerEditedImage;    
UIKIT_EXTERN NSString *const UIImagePickerControllerCropRect;       
UIKIT_EXTERN NSString *const UIImagePickerControllerMediaURL;       

UIKIT_EXTERN_CLASS @interface UIImagePickerController : UINavigationController <NSCoding> {
    
    struct {
  
    } _uiimagePickerFlags;
}

+ (BOOL)isSourceTypeAvailable:(UIImagePickerControllerSourceType)sourceType;                 
+ (NSArray *)availableMediaTypesForSourceType:(UIImagePickerControllerSourceType)sourceType; 

- (void)takePicture;

#ifdef OBJC2
@property(nonatomic,assign)    id <UINavigationControllerDelegate, UIImagePickerControllerDelegate> delegate;
@property(nonatomic)           UIImagePickerControllerSourceType     sourceType;                                                        
@property(nonatomic,copy)      NSArray                              *mediaTypes;                                                        
@property(nonatomic)           BOOL                                  allowsEditing;     
@property(nonatomic)           BOOL                                  allowsImageEditing;
@property(nonatomic)           NSTimeInterval                        videoMaximumDuration;
@property(nonatomic)           UIImagePickerControllerQualityType    videoQuality;
@property(nonatomic)           BOOL                                  showsCameraControls; 
@property(nonatomic,retain)    UIView                                *cameraOverlayView;
@property(nonatomic)           CGAffineTransform                     cameraViewTransform;
#else  /* OBJC2 */
// TODO
#endif /* OBJC2 */
                                                   


@end

@protocol UIImagePickerControllerDelegate<NSObject>
@optional

- (void)imagePickerController:(UIImagePickerController *)picker didFinishPickingImage:(UIImage *)image editingInfo:(NSDictionary *)editingInfo;
- (void)imagePickerController:(UIImagePickerController *)picker didFinishPickingMediaWithInfo:(NSDictionary *)info;
- (void)imagePickerControllerDidCancel:(UIImagePickerController *)picker;

@end

UIKIT_EXTERN void UIImageWriteToSavedPhotosAlbum(UIImage *image, id completionTarget, SEL completionSelector, void *contextInfo);
UIKIT_EXTERN BOOL UIVideoAtPathIsCompatibleWithSavedPhotosAlbum(NSString *videoPath);
UIKIT_EXTERN void UISaveVideoAtPathToSavedPhotosAlbum(NSString *videoPath, id completionTarget, SEL completionSelector, void *contextInfo);


