#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIAccessibilityConstants.h>


UIKIT_EXTERN_CLASS @interface UIAccessibilityElement : NSObject
{
@private
    id _storage;
}

- (id)initWithAccessibilityContainer:(id)container;

#ifdef OBJC2
@property (nonatomic, assign) id accessibilityContainer;
@property (nonatomic, assign) BOOL isAccessibilityElement;
@property (nonatomic, retain) NSString *accessibilityLabel;
@property (nonatomic, retain) NSString *accessibilityHint;
@property (nonatomic, retain) NSString *accessibilityValue;
@property (nonatomic, assign) CGRect accessibilityFrame;
@property (nonatomic, assign) UIAccessibilityTraits accessibilityTraits;
#else /* OBJC2 */
- (id)accessibilityContainer;
- (void)setAccessibilityContainer:(id)theId;
- (BOOL)isAccessibilityElement;
- (void)setIsAccessibilityElement:(BOOL)theAccessElmtFlag;
- (NSString *)accessibilityLabel;
- (void)setAccessibilityLabel:(NSString *)theAccessibilityLabel;
- (NSString *)accessibilityHint;
- (void)setAccessibilityHint:(NSString *)theAccessibilityHint;
- (NSString *)accessibilityValue;
- (void)setAccessibilityValue:(NSString *)theAccessibilityValue;
- (CGRect)accessibilityFrame;
- (void)setAccessibilityFrame:(CGRect)theAccessibilityFrame;
- (UIAccessibilityTraits)accessibilityTraits;
- (void)setAccessibilityTraits:(CGRect)theAccessibilityTraits;
#endif /* OBJC2 */

@end

#endif
