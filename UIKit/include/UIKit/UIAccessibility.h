#import <CoreGraphics/CoreGraphics.h>
#import <Foundation/Foundation.h>
#import <UIKit/UIKitDefines.h>
#import <UIKit/UIAccessibilityConstants.h>
#import <UIKit/UIAccessibilityElement.h>


@interface NSObject (UIAccessibility)


- (BOOL)isAccessibilityElement;
- (void)setIsAccessibilityElement:(BOOL)isElement;
- (NSString *)accessibilityLabel;
- (void)setAccessibilityLabel:(NSString *)label;
- (NSString *)accessibilityHint;
- (void)setAccessibilityHint:(NSString *)hint;
- (NSString *)accessibilityValue;
- (void)setAccessibilityValue:(NSString *)value;
- (UIAccessibilityTraits)accessibilityTraits;
- (void)setAccessibilityTraits:(UIAccessibilityTraits)traits;
- (CGRect)accessibilityFrame;
- (void)setAccessibilityFrame:(CGRect)frame;

@end



@interface NSObject (UIAccessibilityContainer)

- (NSInteger)accessibilityElementCount;
- (id)accessibilityElementAtIndex:(NSInteger)index;
- (NSInteger)indexOfAccessibilityElement:(id)element;

@end

UIKIT_EXTERN void UIAccessibilityPostNotification(UIAccessibilityNotifications notification, id argument);

