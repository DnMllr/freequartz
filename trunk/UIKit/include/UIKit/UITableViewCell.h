#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIView.h>
#import <UIKit/UIStringDrawing.h>
#import <UIKit/UIKitDefines.h>

@class UIImage, UIColor, UILabel, UIImageView, UIButton, UITextField;

typedef enum {

    UITableViewCellStyleDefault,	
    UITableViewCellStyleValue1,		
    UITableViewCellStyleValue2,		
    UITableViewCellStyleSubtitle	

} UITableViewCellStyle;           

typedef enum {

    UITableViewCellSeparatorStyleNone,
    UITableViewCellSeparatorStyleSingleLine
} UITableViewCellSeparatorStyle;

typedef enum {

    UITableViewCellSelectionStyleNone,
    UITableViewCellSelectionStyleBlue,
    UITableViewCellSelectionStyleGray
} UITableViewCellSelectionStyle;

typedef enum {

    UITableViewCellEditingStyleNone,
    UITableViewCellEditingStyleDelete,
    UITableViewCellEditingStyleInsert
} UITableViewCellEditingStyle;

typedef enum {

    UITableViewCellAccessoryNone,                   
    UITableViewCellAccessoryDisclosureIndicator,    
    UITableViewCellAccessoryDetailDisclosureButton, 
    UITableViewCellAccessoryCheckmark               
} UITableViewCellAccessoryType;

enum {

    UITableViewCellStateDefaultMask                     = 0,
    UITableViewCellStateShowingEditControlMask          = 1 << 0,
    UITableViewCellStateShowingDeleteConfirmationMask   = 1 << 1
};
typedef NSUInteger UITableViewCellStateMask;        

#define UITableViewCellStateEditingMask UITableViewCellStateShowingEditControlMask

UIKIT_EXTERN_CLASS @interface UITableViewCell : UIView <NSCoding> {
  
    struct {
  
    } _uitableViewCellFlags;
    
    
}

- (id)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier;
- (void)prepareForReuse;
- (void)setSelected:(BOOL)selected animated:(BOOL)animated;                     
- (void)setHighlighted:(BOOL)highlighted animated:(BOOL)animated;               
- (void)setEditing:(BOOL)editing animated:(BOOL)animated;
- (void)willTransitionToState:(UITableViewCellStateMask)state;
- (void)didTransitionToState:(UITableViewCellStateMask)state;

#ifdef OBJC2
@property(nonatomic,readonly,retain) UIImageView  *imageView; 
@property(nonatomic,readonly,retain) UILabel      *textLabel; 
@property(nonatomic,readonly,retain) UILabel      *detailTextLabel; 
@property(nonatomic,readonly,retain) UIView       *contentView;
@property(nonatomic,retain) UIView                *backgroundView;
@property(nonatomic,retain) UIView                *selectedBackgroundView;
@property(nonatomic,readonly,copy) NSString       *reuseIdentifier;
@property(nonatomic) UITableViewCellSelectionStyle  selectionStyle;             
@property(nonatomic,getter=isSelected) BOOL         selected;                   
@property(nonatomic,getter=isHighlighted) BOOL      highlighted;                
@property(nonatomic,readonly) UITableViewCellEditingStyle editingStyle;         
@property(nonatomic) BOOL                           showsReorderControl;        
@property(nonatomic) BOOL                           shouldIndentWhileEditing;   
@property(nonatomic) UITableViewCellAccessoryType   accessoryType;              
@property(nonatomic,retain) UIView                 *accessoryView;              
@property(nonatomic) UITableViewCellAccessoryType   editingAccessoryType;       
@property(nonatomic,retain) UIView                 *editingAccessoryView;       
@property(nonatomic) NSInteger                      indentationLevel;           
@property(nonatomic) CGFloat                        indentationWidth;           
@property(nonatomic,getter=isEditing) BOOL          editing;                    
@property(nonatomic,readonly) BOOL                  showingDeleteConfirmation;  
#else  /* OBJC2 */
// TODO
#endif /* OBJC2 */

@end
