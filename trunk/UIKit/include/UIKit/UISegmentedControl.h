#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIControl.h>
#import <UIKit/UIKitDefines.h>

typedef enum {
    UISegmentedControlStylePlain,     
    UISegmentedControlStyleBordered,  
    UISegmentedControlStyleBar,       
} UISegmentedControlStyle;

enum {
    UISegmentedControlNoSegment = -1   
};

@class UIImage, UIColor;

UIKIT_EXTERN_CLASS @interface UISegmentedControl : UIControl <NSCoding>
{
  
    struct {
       
    } _uisegmentedControlFlags;
}

- (id)initWithItems:(NSArray *)items; 

- (void)insertSegmentWithTitle:(NSString *)title atIndex:(NSUInteger)segment animated:(BOOL)animated;
- (void)insertSegmentWithImage:(UIImage *)image  atIndex:(NSUInteger)segment animated:(BOOL)animated;
- (void)removeSegmentAtIndex:(NSUInteger)segment animated:(BOOL)animated;
- (void)removeAllSegments;
- (void)setTitle:(NSString *)title forSegmentAtIndex:(NSUInteger)segment;      
- (NSString *)titleForSegmentAtIndex:(NSUInteger)segment;
- (void)setImage:(UIImage *)image forSegmentAtIndex:(NSUInteger)segment;       
- (UIImage *)imageForSegmentAtIndex:(NSUInteger)segment;
- (void)setWidth:(CGFloat)width forSegmentAtIndex:(NSUInteger)segment;         
- (CGFloat)widthForSegmentAtIndex:(NSUInteger)segment;
- (void)setContentOffset:(CGSize)offset forSegmentAtIndex:(NSUInteger)segment; 
- (CGSize)contentOffsetForSegmentAtIndex:(NSUInteger)segment;
- (void)setEnabled:(BOOL)enabled forSegmentAtIndex:(NSUInteger)segment;        
- (BOOL)isEnabledForSegmentAtIndex:(NSUInteger)segment;

#ifdef OBJC2
@property(nonatomic) UISegmentedControlStyle segmentedControlStyle; 
@property(nonatomic,getter=isMomentary) BOOL momentary;             
@property(nonatomic,retain) UIColor *tintColor;                     
@property(nonatomic,readonly) NSUInteger numberOfSegments;
@property(nonatomic) NSInteger selectedSegmentIndex;
#else  /* OBJC2 */
// TODO
#endif /* OBJC2 */

@end

