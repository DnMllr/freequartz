#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIControl.h>
#import <UIKit/UIKitDefines.h>

@class UIImageView, UIImage;

UIKIT_EXTERN_CLASS @interface UISlider : UIControl <NSCoding> {


    struct {

    } _uisliderFlags;

    
}

- (void)setValue:(float)value animated:(BOOL)animated; 
- (void)setThumbImage:(UIImage *)image forState:(UIControlState)state;
- (void)setMinimumTrackImage:(UIImage *)image forState:(UIControlState)state;
- (void)setMaximumTrackImage:(UIImage *)image forState:(UIControlState)state;
- (UIImage *)thumbImageForState:(UIControlState)state;
- (UIImage *)minimumTrackImageForState:(UIControlState)state;
- (UIImage *)maximumTrackImageForState:(UIControlState)state;
- (CGRect)minimumValueImageRectForBounds:(CGRect)bounds;
- (CGRect)maximumValueImageRectForBounds:(CGRect)bounds;
- (CGRect)trackRectForBounds:(CGRect)bounds;
- (CGRect)thumbRectForBounds:(CGRect)bounds trackRect:(CGRect)rect value:(float)value;

#ifdef OBJC2
@property(nonatomic) float value;                                 
@property(nonatomic) float minimumValue;                          
@property(nonatomic) float maximumValue;                          
@property(nonatomic,retain) UIImage *minimumValueImage;          
@property(nonatomic,retain) UIImage *maximumValueImage;          
@property(nonatomic,getter=isContinuous) BOOL continuous;
@property(nonatomic,readonly) UIImage* currentThumbImage;
@property(nonatomic,readonly) UIImage* currentMinimumTrackImage;
@property(nonatomic,readonly) UIImage* currentMaximumTrackImage;
#else  /* OBJC2 */
// TODO
#endif /* OBJC2 */



@end
