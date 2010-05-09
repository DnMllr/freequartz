#import <Foundation/Foundation.h>
#import <UIKit/UIControl.h>
#import <UIKit/UIKitDefines.h>

typedef enum {
    UIDatePickerModeTime,           
    UIDatePickerModeDate,           
    UIDatePickerModeDateAndTime,    
    UIDatePickerModeCountDownTimer  
} UIDatePickerMode;

@class UIPickerView;

UIKIT_EXTERN_CLASS @interface UIDatePicker : UIControl <NSCoding>
{
  @private
    UIPickerView *_pickerView;
}

- (void)setDate:(NSDate *)date animated:(BOOL)animated;


#ifdef OBJC2
@property(nonatomic) UIDatePickerMode datePickerMode;             
@property(nonatomic,retain) NSLocale      *locale;               
@property(nonatomic,retain) NSTimeZone    *timeZone;             
@property(nonatomic,copy)   NSCalendar    *calendar;             
@property(nonatomic,retain) NSDate        *date;                 
@property(nonatomic,retain) NSDate        *minimumDate;          
@property(nonatomic,retain) NSDate        *maximumDate;          
@property(nonatomic)        NSTimeInterval countDownDuration;    
@property(nonatomic)        NSInteger      minuteInterval;       
#else /* OBJC2 */
//datePickerMode
UIDatePickerMode _datePickerMode;
- (UIDatePickerMode)datePickerMode;
- (void)setDatePickerMode:(UIDatePickerMode)theDatePickerMode;
//locale
NSLocale *_locale;
- (NSLocale *)locale;
- (void)setLocale:(NSLocale *)theLocale;
//timeZone
NSTimeZone *_timeZone;
- (NSTimeZone *)timeZone;
- (void)setTimeZone:(NSTimeZone *)theTimeZone;
//calendar
NSCalendar *_calendar;
- (NSCalendar *)calendar;
- (void)setCalendar:(NSCalendar *)theCalendar;
//date
NSDate *_date;
- (NSDate *)date;
- (void)setDate:(NSDate *)theDate;
//TODO ...

#endif /* OBJC2 */
          

@end
