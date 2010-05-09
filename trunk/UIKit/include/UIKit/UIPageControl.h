#import <Foundation/Foundation.h>
#import <UIKit/UIControl.h>
#import <UIKit/UIKitDefines.h>

UIKIT_EXTERN_CLASS @interface UIPageControl : UIControl {

    struct {
        
    } _uipageControlFlags;
}

- (void)updateCurrentPageDisplay;                      
- (CGSize)sizeForNumberOfPages:(NSInteger)pageCount;   

#ifdef OBJC2
@property(nonatomic) NSInteger numberOfPages;          
@property(nonatomic) NSInteger currentPage;            
@property(nonatomic) BOOL hidesForSinglePage;          
@property(nonatomic) BOOL defersCurrentPageDisplay;    
#else  /* OBJC2 */
// TODO
#endif /* OBJC2 */

@end
