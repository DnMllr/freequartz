#import <CoreGraphics/CoreGraphics.h>
#import <Foundation/Foundation.h>
#import <UIKit/UIBarItem.h>
#import <UIKit/UIKitDefines.h>

typedef enum {
    UIBarButtonItemStylePlain,   
    UIBarButtonItemStyleBordered,
    UIBarButtonItemStyleDone,
} UIBarButtonItemStyle;

typedef enum {
    UIBarButtonSystemItemDone,
    UIBarButtonSystemItemCancel,
    UIBarButtonSystemItemEdit,  
    UIBarButtonSystemItemSave,  
    UIBarButtonSystemItemAdd,
    UIBarButtonSystemItemFlexibleSpace,
    UIBarButtonSystemItemFixedSpace,
    UIBarButtonSystemItemCompose,
    UIBarButtonSystemItemReply,
    UIBarButtonSystemItemAction,
    UIBarButtonSystemItemOrganize,
    UIBarButtonSystemItemBookmarks,
    UIBarButtonSystemItemSearch,
    UIBarButtonSystemItemRefresh,
    UIBarButtonSystemItemStop,
    UIBarButtonSystemItemCamera,
    UIBarButtonSystemItemTrash,
    UIBarButtonSystemItemPlay,
    UIBarButtonSystemItemPause,
    UIBarButtonSystemItemRewind,
    UIBarButtonSystemItemFastForward,
    UIBarButtonSystemItemUndo,		
    UIBarButtonSystemItemRedo,		
} UIBarButtonSystemItem;

@class UIImage, UIView;

UIKIT_EXTERN_CLASS @interface UIBarButtonItem : UIBarItem {
 
    struct {
      //TODO
    } _uibarButtonItemFlags;
}

- (id)initWithImage:(UIImage *)image style:(UIBarButtonItemStyle)style target:(id)target action:(SEL)action;
- (id)initWithTitle:(NSString *)title style:(UIBarButtonItemStyle)style target:(id)target action:(SEL)action;
- (id)initWithBarButtonSystemItem:(UIBarButtonSystemItem)systemItem target:(id)target action:(SEL)action;
- (id)initWithCustomView:(UIView *)customView;

#ifdef OBJC2
@property(nonatomic)         UIBarButtonItemStyle style;            
@property(nonatomic)         CGFloat              width;            
@property(nonatomic,copy)    NSSet               *possibleTitles;   
@property(nonatomic,retain)  UIView              *customView;       
@property(nonatomic)         SEL                  action;           
@property(nonatomic,assign)  id                   target;           
#else /* OBJC2 */
//TODO
#endif /* OBJC2 */

@end
