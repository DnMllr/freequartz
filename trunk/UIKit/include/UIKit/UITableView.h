#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIScrollView.h>
#import <UIKit/UITableViewCell.h>
#import <UIKit/UIKitDefines.h>

typedef enum {

    UITableViewStylePlain,              
    UITableViewStyleGrouped             
} UITableViewStyle;

typedef enum {

    UITableViewScrollPositionNone,        
    UITableViewScrollPositionTop,    
    UITableViewScrollPositionMiddle,   
    UITableViewScrollPositionBottom
} UITableViewScrollPosition;       

typedef enum {

    UITableViewRowAnimationFade,
    UITableViewRowAnimationRight,       
    UITableViewRowAnimationLeft,
    UITableViewRowAnimationTop,
    UITableViewRowAnimationBottom,
    UITableViewRowAnimationNone,        
} UITableViewRowAnimation;

UIKIT_EXTERN NSString *const UITableViewIndexSearch;

@protocol UITableViewDataSource, UITableViewDelegate;

UIKIT_EXTERN_CLASS @interface UITableView : UIScrollView <NSCoding> {

    struct {

    } _uitableViewFlags;
    
    
}

- (id)initWithFrame:(CGRect)frame style:(UITableViewStyle)style;                

#ifdef OBJC2
@property(nonatomic,readonly) UITableViewStyle           style;
@property(nonatomic,assign)   id <UITableViewDataSource> dataSource;
@property(nonatomic,assign)   id <UITableViewDelegate>   delegate;
@property(nonatomic) CGFloat rowHeight;
@property(nonatomic) CGFloat sectionHeaderHeight;   
@property(nonatomic) CGFloat sectionFooterHeight;   
#else  /* OBJC2 */
// TODO
#endif /* OBJC2 */


- (void)reloadData;                 
- (void)reloadSectionIndexTitles;
- (NSInteger)numberOfSections;
- (NSInteger)numberOfRowsInSection:(NSInteger)section;
- (CGRect)rectForSection:(NSInteger)section;                                    
- (CGRect)rectForHeaderInSection:(NSInteger)section;
- (CGRect)rectForFooterInSection:(NSInteger)section;
- (CGRect)rectForRowAtIndexPath:(NSIndexPath *)indexPath;

- (NSIndexPath *)indexPathForRowAtPoint:(CGPoint)point;                         
- (NSIndexPath *)indexPathForCell:(UITableViewCell *)cell;                      
- (NSArray *)indexPathsForRowsInRect:(CGRect)rect;                               

- (UITableViewCell *)cellForRowAtIndexPath:(NSIndexPath *)indexPath;            
- (NSArray *)visibleCells;
- (NSArray *)indexPathsForVisibleRows;

- (void)scrollToRowAtIndexPath:(NSIndexPath *)indexPath atScrollPosition:(UITableViewScrollPosition)scrollPosition animated:(BOOL)animated;
- (void)scrollToNearestSelectedRowAtScrollPosition:(UITableViewScrollPosition)scrollPosition animated:(BOOL)animated;
- (void)beginUpdates;   
- (void)endUpdates;     
- (void)insertSections:(NSIndexSet *)sections withRowAnimation:(UITableViewRowAnimation)animation;
- (void)deleteSections:(NSIndexSet *)sections withRowAnimation:(UITableViewRowAnimation)animation;
- (void)reloadSections:(NSIndexSet *)sections withRowAnimation:(UITableViewRowAnimation)animation;
- (void)insertRowsAtIndexPaths:(NSArray *)indexPaths withRowAnimation:(UITableViewRowAnimation)animation;
- (void)deleteRowsAtIndexPaths:(NSArray *)indexPaths withRowAnimation:(UITableViewRowAnimation)animation;
- (void)reloadRowsAtIndexPaths:(NSArray *)indexPaths withRowAnimation:(UITableViewRowAnimation)animation ;
- (void)setEditing:(BOOL)editing animated:(BOOL)animated;
- (NSIndexPath *)indexPathForSelectedRow;                                       
- (void)selectRowAtIndexPath:(NSIndexPath *)indexPath animated:(BOOL)animated scrollPosition:(UITableViewScrollPosition)scrollPosition;
- (void)deselectRowAtIndexPath:(NSIndexPath *)indexPath animated:(BOOL)animated;
- (UITableViewCell *)dequeueReusableCellWithIdentifier:(NSString *)identifier;  

#ifdef OBJC2
@property(nonatomic,getter=isEditing) BOOL editing;      
@property(nonatomic) BOOL allowsSelection;
@property(nonatomic) BOOL allowsSelectionDuringEditing;                         
@property(nonatomic) NSInteger sectionIndexMinimumDisplayRowCount;              
@property(nonatomic) UITableViewCellSeparatorStyle separatorStyle;              
@property(nonatomic,retain) UIColor               *separatorColor;              
@property(nonatomic,retain) UIView *tableHeaderView;                            
@property(nonatomic,retain) UIView *tableFooterView;                            
#else  /* OBJC2 */
// TODO
#endif /* OBJC2 */


@end

@protocol UITableViewDataSource<NSObject>

@required

- (NSInteger)tableView:(UITableView *)table numberOfRowsInSection:(NSInteger)section;
- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath;

@optional

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView;              
- (NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section;    
- (NSString *)tableView:(UITableView *)tableView titleForFooterInSection:(NSInteger)section;
- (BOOL)tableView:(UITableView *)tableView canEditRowAtIndexPath:(NSIndexPath *)indexPath;
- (BOOL)tableView:(UITableView *)tableView canMoveRowAtIndexPath:(NSIndexPath *)indexPath;
- (NSArray *)sectionIndexTitlesForTableView:(UITableView *)tableView;                                                    
- (NSInteger)tableView:(UITableView *)tableView sectionForSectionIndexTitle:(NSString *)title atIndex:(NSInteger)index;  
- (void)tableView:(UITableView *)tableView commitEditingStyle:(UITableViewCellEditingStyle)editingStyle forRowAtIndexPath:(NSIndexPath *)indexPath;
- (void)tableView:(UITableView *)tableView moveRowAtIndexPath:(NSIndexPath *)sourceIndexPath toIndexPath:(NSIndexPath *)destinationIndexPath;

@end



@protocol UITableViewDelegate<NSObject, UIScrollViewDelegate>

@optional

- (void)tableView:(UITableView *)tableView willDisplayCell:(UITableViewCell *)cell forRowAtIndexPath:(NSIndexPath *)indexPath;
- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath;
- (CGFloat)tableView:(UITableView *)tableView heightForHeaderInSection:(NSInteger)section;
- (CGFloat)tableView:(UITableView *)tableView heightForFooterInSection:(NSInteger)section;
- (UIView *)tableView:(UITableView *)tableView viewForHeaderInSection:(NSInteger)section;   
- (UIView *)tableView:(UITableView *)tableView viewForFooterInSection:(NSInteger)section;   
- (UITableViewCellAccessoryType)tableView:(UITableView *)tableView accessoryTypeForRowWithIndexPath:(NSIndexPath *)indexPath;
- (void)tableView:(UITableView *)tableView accessoryButtonTappedForRowWithIndexPath:(NSIndexPath *)indexPath;
- (NSIndexPath *)tableView:(UITableView *)tableView willSelectRowAtIndexPath:(NSIndexPath *)indexPath;
- (NSIndexPath *)tableView:(UITableView *)tableView willDeselectRowAtIndexPath:(NSIndexPath *)indexPath ;
- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath;
- (void)tableView:(UITableView *)tableView didDeselectRowAtIndexPath:(NSIndexPath *)indexPath ;
- (UITableViewCellEditingStyle)tableView:(UITableView *)tableView editingStyleForRowAtIndexPath:(NSIndexPath *)indexPath;
- (NSString *)tableView:(UITableView *)tableView titleForDeleteConfirmationButtonForRowAtIndexPath:(NSIndexPath *)indexPath;
- (BOOL)tableView:(UITableView *)tableView shouldIndentWhileEditingRowAtIndexPath:(NSIndexPath *)indexPath;
- (void)tableView:(UITableView*)tableView willBeginEditingRowAtIndexPath:(NSIndexPath *)indexPath;
- (void)tableView:(UITableView*)tableView didEndEditingRowAtIndexPath:(NSIndexPath *)indexPath;
- (NSIndexPath *)tableView:(UITableView *)tableView targetIndexPathForMoveFromRowAtIndexPath:(NSIndexPath *)sourceIndexPath toProposedIndexPath:(NSIndexPath *)proposedDestinationIndexPath;               
- (NSInteger)tableView:(UITableView *)tableView indentationLevelForRowAtIndexPath:(NSIndexPath *)indexPath; 

@end

UIKIT_EXTERN NSString *const UITableViewSelectionDidChangeNotification;

@interface NSIndexPath (UITableView)

+ (NSIndexPath *)indexPathForRow:(NSUInteger)row inSection:(NSUInteger)section;

@property(nonatomic,readonly) NSUInteger section;
@property(nonatomic,readonly) NSUInteger row;

@end
