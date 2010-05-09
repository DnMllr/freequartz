#import <Foundation/Foundation.h>


typedef enum {
    UITextAutocapitalizationTypeNone,
    UITextAutocapitalizationTypeWords,
    UITextAutocapitalizationTypeSentences,
    UITextAutocapitalizationTypeAllCharacters,
} UITextAutocapitalizationType;


typedef enum {
    UITextAutocorrectionTypeDefault,
    UITextAutocorrectionTypeNo,
    UITextAutocorrectionTypeYes,
} UITextAutocorrectionType;


typedef enum {
    UIKeyboardTypeDefault,                
    UIKeyboardTypeASCIICapable,           
    UIKeyboardTypeNumbersAndPunctuation,  
    UIKeyboardTypeURL,                    
    UIKeyboardTypeNumberPad,              
    UIKeyboardTypePhonePad,               
    UIKeyboardTypeNamePhonePad,           
    UIKeyboardTypeEmailAddress,           

    UIKeyboardTypeAlphabet = UIKeyboardTypeASCIICapable, 

} UIKeyboardType;


typedef enum {
    UIKeyboardAppearanceDefault,          
    UIKeyboardAppearanceAlert,            
} UIKeyboardAppearance;


typedef enum {
    UIReturnKeyDefault,
    UIReturnKeyGo,
    UIReturnKeyGoogle,
    UIReturnKeyJoin,
    UIReturnKeyNext,
    UIReturnKeyRoute,
    UIReturnKeySearch,
    UIReturnKeySend,
    UIReturnKeyYahoo,
    UIReturnKeyDone,
    UIReturnKeyEmergencyCall,
} UIReturnKeyType;


#ifdef OBJC2
@protocol UITextInputTraits <NSObject>

@optional

@property(nonatomic) UITextAutocapitalizationType autocapitalizationType; 
@property(nonatomic) UITextAutocorrectionType autocorrectionType;         
@property(nonatomic) UIKeyboardType keyboardType;                         
@property(nonatomic) UIKeyboardAppearance keyboardAppearance;             
@property(nonatomic) UIReturnKeyType returnKeyType;                       
@property(nonatomic) BOOL enablesReturnKeyAutomatically;                  
@property(nonatomic,getter=isSecureTextEntry) BOOL secureTextEntry;      

@end

#else /* OBJC2 */

//  I am declaring empty protocol for now just for UITextField
@protocol UITextInputTraits <NSObject>
@end

@interface NSObject (UITextInputTraits)

- (UITextAutocapitalizationType)autocorrectionType;
- (void)setAutocorrectionType:(UITextAutocapitalizationType)theAutocorrectionType;

- (UITextAutocorrectionType)autocapitalizationType;
- (void)setAutocapitalizationType:(UITextAutocorrectionType)theAutocapitalizationType;

- (UIKeyboardType)keyboardType;
- (void)setKeyboardType:(UIKeyboardType)theKeyboardType;

- (UIKeyboardAppearance)keyboardAppearance;
- (void)setKeyboardAppearance:(UIKeyboardAppearance)theKeyboardAppearance;

- (UIReturnKeyType)returnKeyType;
- (void)setReturnKeyType:(UIReturnKeyType)theReturnKeyType;

- (BOOL)enablesReturnKeyAutomatically;
- (void)setEnablesReturnKeyAutomatically:(BOOL)enablesReturnKeyAutoFlag;

@end

#endif /* OBJC2 */
