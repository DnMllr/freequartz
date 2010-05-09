#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIView.h>
#import <UIKit/UIKitDefines.h>

@protocol UIPickerViewDataSource, UIPickerViewDelegate;

UIKIT_EXTERN_CLASS @interface UIPickerView : UIView <NSCoding>
{ 

    struct {

    } _uipickerViewFlags;
}

- (NSInteger)numberOfRowsInComponent:(NSInteger)component;
- (CGSize)rowSizeForComponent:(NSInteger)component;
- (UIView *)viewForRow:(NSInteger)row forComponent:(NSInteger)component;
- (void)reloadAllComponents;
- (void)reloadComponent:(NSInteger)component;
- (void)selectRow:(NSInteger)row inComponent:(NSInteger)component animated:(BOOL)animated;  
- (NSInteger)selectedRowInComponent:(NSInteger)component;

#ifdef OBJC2
@property(nonatomic,assign) id<UIPickerViewDataSource> dataSource;                
@property(nonatomic,assign) id<UIPickerViewDelegate>   delegate;                  
@property(nonatomic)        BOOL                       showsSelectionIndicator;   
@property(nonatomic,readonly) NSInteger numberOfComponents;
#else  /* OBJC2 */
// TODO
#endif /* OBJC2 */

@end


@protocol UIPickerViewDataSource<NSObject>
@required

- (NSInteger)numberOfComponentsInPickerView:(UIPickerView *)pickerView;
- (NSInteger)pickerView:(UIPickerView *)pickerView numberOfRowsInComponent:(NSInteger)component;

@end


@protocol UIPickerViewDelegate<NSObject>
@optional

 - (CGFloat)pickerView:(UIPickerView *)pickerView widthForComponent:(NSInteger)component;
- (CGFloat)pickerView:(UIPickerView *)pickerView rowHeightForComponent:(NSInteger)component;
- (NSString *)pickerView:(UIPickerView *)pickerView titleForRow:(NSInteger)row forComponent:(NSInteger)component;
- (UIView *)pickerView:(UIPickerView *)pickerView viewForRow:(NSInteger)row forComponent:(NSInteger)component reusingView:(UIView *)view;
- (void)pickerView:(UIPickerView *)pickerView didSelectRow:(NSInteger)row inComponent:(NSInteger)component;

@end
