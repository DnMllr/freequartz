#import <Foundation/Foundation.h>
#import <UIKit/UIKitDefines.h>
#import <UIKit/UIEvent.h>

UIKIT_EXTERN_CLASS @interface UIResponder : NSObject {    
}

- (UIResponder*)nextResponder;

- (BOOL)canBecomeFirstResponder;    
- (BOOL)becomeFirstResponder;
- (BOOL)canResignFirstResponder;    
- (BOOL)resignFirstResponder;
- (BOOL)isFirstResponder;
- (void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event;
- (void)touchesMoved:(NSSet *)touches withEvent:(UIEvent *)event;
- (void)touchesEnded:(NSSet *)touches withEvent:(UIEvent *)event;
- (void)touchesCancelled:(NSSet *)touches withEvent:(UIEvent *)event;
- (void)motionBegan:(UIEventSubtype)motion withEvent:(UIEvent *)event;
- (void)motionEnded:(UIEventSubtype)motion withEvent:(UIEvent *)event;
- (void)motionCancelled:(UIEventSubtype)motion withEvent:(UIEvent *)event;

- (BOOL)canPerformAction:(SEL)action withSender:(id)sender;

#ifdef OBJC2
@property(nonatomic,readonly) NSUndoManager *undoManager;
#else  /* OBJC2 */
- (NSUndoManager*) undoManager;
#endif /* OBJC2 */
@end

@interface NSObject(UIResponderStandardEditActions)

- (void)cut:(id)sender;
- (void)copy:(id)sender;
- (void)paste:(id)sender;
- (void)select:(id)sender;
- (void)selectAll:(id)sender;

@end
