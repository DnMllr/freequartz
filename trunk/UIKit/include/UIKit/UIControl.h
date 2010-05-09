#import <Foundation/Foundation.h>
#import <UIKit/UIView.h>
#import <UIKit/UIKitDefines.h>

enum {
    UIControlEventTouchDown           = 1 <<  0,      
    UIControlEventTouchDownRepeat     = 1 <<  1,      
    UIControlEventTouchDragInside     = 1 <<  2,
    UIControlEventTouchDragOutside    = 1 <<  3,
    UIControlEventTouchDragEnter      = 1 <<  4,
    UIControlEventTouchDragExit       = 1 <<  5,
    UIControlEventTouchUpInside       = 1 <<  6,
    UIControlEventTouchUpOutside      = 1 <<  7,
    UIControlEventTouchCancel         = 1 <<  8,

    UIControlEventValueChanged        = 1 << 12,     

    UIControlEventEditingDidBegin     = 1 << 16,     
    UIControlEventEditingChanged      = 1 << 17,
    UIControlEventEditingDidEnd       = 1 << 18,
    UIControlEventEditingDidEndOnExit = 1 << 19,     

    UIControlEventAllTouchEvents      = 0x00000FFF,  
    UIControlEventAllEditingEvents    = 0x000F0000,  
    UIControlEventApplicationReserved = 0x0F000000,  
    UIControlEventSystemReserved      = 0xF0000000,  
    UIControlEventAllEvents           = 0xFFFFFFFF
};
typedef NSUInteger UIControlEvents;

typedef enum {
    UIControlContentVerticalAlignmentCenter  = 0,
    UIControlContentVerticalAlignmentTop     = 1,
    UIControlContentVerticalAlignmentBottom  = 2,
    UIControlContentVerticalAlignmentFill    = 3,
} UIControlContentVerticalAlignment;

typedef enum {
    UIControlContentHorizontalAlignmentCenter = 0,
    UIControlContentHorizontalAlignmentLeft   = 1,
    UIControlContentHorizontalAlignmentRight  = 2,
    UIControlContentHorizontalAlignmentFill   = 3,
} UIControlContentHorizontalAlignment;

enum {
    UIControlStateNormal       = 0,                       
    UIControlStateHighlighted  = 1 << 0,                 
    UIControlStateDisabled     = 1 << 1,
    UIControlStateSelected     = 1 << 2,                 
    UIControlStateApplication  = 0x00FF0000,             
    UIControlStateReserved     = 0xFF000000              
};
typedef NSUInteger UIControlState;

@class UITouch;
@class UIEvent;

UIKIT_EXTERN_CLASS @interface UIControl : UIView {
    
    struct {
        //TODO
    } _uicontrolFlags;
}

- (BOOL)beginTrackingWithTouch:(UITouch *)touch withEvent:(UIEvent *)event;
- (BOOL)continueTrackingWithTouch:(UITouch *)touch withEvent:(UIEvent *)event;
- (void)endTrackingWithTouch:(UITouch *)touch withEvent:(UIEvent *)event;
- (void)cancelTrackingWithEvent:(UIEvent *)event;   
- (void)addTarget:(id)target action:(SEL)action forControlEvents:(UIControlEvents)controlEvents;
- (void)removeTarget:(id)target action:(SEL)action forControlEvents:(UIControlEvents)controlEvents;
- (NSSet *)allTargets;                                                                     
- (UIControlEvents)allControlEvents;                                                       
- (NSArray *)actionsForTarget:(id)target forControlEvent:(UIControlEvents)controlEvent; 
- (void)sendAction:(SEL)action to:(id)target forEvent:(UIEvent *)event;
- (void)sendActionsForControlEvents:(UIControlEvents)controlEvents;

// Properties
#ifdef OBJC2
@property(nonatomic,getter=isEnabled) BOOL enabled;                                  
@property(nonatomic,getter=isSelected) BOOL selected;                                
@property(nonatomic,getter=isHighlighted) BOOL highlighted;                          
@property(nonatomic) UIControlContentVerticalAlignment contentVerticalAlignment;     
@property(nonatomic) UIControlContentHorizontalAlignment contentHorizontalAlignment; 
@property(nonatomic,readonly) UIControlState state;                  
@property(nonatomic,readonly,getter=isTracking) BOOL tracking;
@property(nonatomic,readonly,getter=isTouchInside) BOOL touchInside;
#else /* OBJC2 */
//enabled
BOOL enabled;
- (BOOL)isEnabled;
- (void)setEnabled:(BOOL)enabledFlag;
//selected; 
- (BOOL)isSelected;
- (void)setSelected:(BOOL)selectedFlag;
//highlighted
BOOL highlighted;
- (BOOL)isHighlighted;
- (void)sethighlighted:(BOOL)highlightedFlag;
//contentVerticalAlignment
UIControlContentVerticalAlignment contentVerticalAlignment;
- (UIControlContentVerticalAlignment)contentVerticalAlignment;
- (void)setContentVerticalAlignment:(UIControlContentVerticalAlignment) ucvAlign;
//contentHorizontalAlignment
UIControlContentHorizontalAlignment contentHorizontalAlignment; 
- (UIControlContentHorizontalAlignment)contentHorizontalAlignment;
- (void)setContentHorizontalAlignment:(UIControlContentHorizontalAlignment) uchAlign;
//state
UIControlState state;
- (UIControlState)state;
//tracking
BOOL tracking;
- (BOOL)isTracking;
//touchInside
BOOL touchInside;
- (BOOL)isTouchInside;
#endif /* OBJC2 */

@end
