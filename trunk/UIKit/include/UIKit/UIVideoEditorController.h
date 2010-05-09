#import <Foundation/Foundation.h>
#import <UIKit/UINavigationController.h>
#import <UIKit/UIKitDefines.h>
#import <UIKit/UIImagePickerController.h>

@protocol UIVideoEditorControllerDelegate;

UIKIT_EXTERN_CLASS @interface UIVideoEditorController : UINavigationController {

    
    struct {

    } _uivideoEditorControllerFlags;
}

+ (BOOL)canEditVideoAtPath:(NSString *)videoPath;

#ifdef OBJC2
@property(nonatomic,assign) id <UINavigationControllerDelegate, UIVideoEditorControllerDelegate> delegate;
@property(nonatomic) NSTimeInterval videoMaximumDuration; 
@property(nonatomic) UIImagePickerControllerQualityType videoQuality;        
@property(nonatomic, copy) NSString *videoPath;
#else  /* OBJC2 */
// TODO
#endif /* OBJC2 */

@end

@protocol UIVideoEditorControllerDelegate<NSObject>
@optional

- (void)videoEditorController:(UIVideoEditorController *)editor didSaveEditedVideoToPath:(NSString *)editedVideoPath; // edited video is saved to a path in app's temporary directory
- (void)videoEditorController:(UIVideoEditorController *)editor didFailWithError:(NSError *)error;
- (void)videoEditorControllerDidCancel:(UIVideoEditorController *)editor;

@end

#endif
