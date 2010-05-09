#import <Foundation/Foundation.h>
#import <UIKit/UIKitDefines.h>

UIKIT_EXTERN NSString *const UIPasteboardNameGeneral;
UIKIT_EXTERN NSString *const UIPasteboardNameFind;

@class UIColor, UIImage;

UIKIT_EXTERN_CLASS @interface UIPasteboard : NSObject { 
  
}

+ (UIPasteboard *)generalPasteboard;
+ (UIPasteboard *)pasteboardWithName:(NSString *)pasteboardName create:(BOOL)create;
+ (UIPasteboard *)pasteboardWithUniqueName;
+ (void)removePasteboardWithName:(NSString *)pasteboardName;

- (NSArray *)pasteboardTypes;
- (BOOL)containsPasteboardTypes:(NSArray *)pasteboardTypes;
- (NSData *)dataForPasteboardType:(NSString *)pasteboardType;
- (id)valueForPasteboardType:(NSString *)pasteboardType;
- (void)setValue:(id)value forPasteboardType:(NSString *)pasteboardType;
- (void)setData:(NSData *)data forPasteboardType:(NSString *)pasteboardType;
- (NSArray *)pasteboardTypesForItemSet:(NSIndexSet*)itemSet;		
- (BOOL)containsPasteboardTypes:(NSArray *)pasteboardTypes inItemSet:(NSIndexSet *)itemSet;	
- (NSIndexSet *)itemSetWithPasteboardTypes:(NSArray *)pasteboardTypes;
- (NSArray *)valuesForPasteboardType:(NSString *)pasteboardType inItemSet:(NSIndexSet *)itemSet;	
- (NSArray *)dataForPasteboardType:(NSString *)pasteboardType inItemSet:(NSIndexSet *)itemSet;
- (void)addItems:(NSArray *)items;

#ifdef OBJC2
@property(readonly,nonatomic) NSString *name;
@property(getter=isPersistent,nonatomic) BOOL persistent;
@property(readonly,nonatomic) NSInteger changeCount;
@property(readonly,nonatomic) NSInteger numberOfItems;
@property(nonatomic,copy) NSArray *items;
#else  /* OBJC2 */
// TODO
#endif /* OBJC2 */

@end


UIKIT_EXTERN NSString *const UIPasteboardChangedNotification;
UIKIT_EXTERN NSString *const UIPasteboardChangedTypesAddedKey;
UIKIT_EXTERN NSString *const UIPasteboardChangedTypesRemovedKey;
UIKIT_EXTERN NSString *const UIPasteboardRemovedNotification;

UIKIT_EXTERN NSArray *UIPasteboardTypeListString;
UIKIT_EXTERN NSArray *UIPasteboardTypeListURL;
UIKIT_EXTERN NSArray *UIPasteboardTypeListImage;
UIKIT_EXTERN NSArray *UIPasteboardTypeListColor;

@interface UIPasteboard(UIPasteboardDataExtensions)

#ifdef OBJC2
@property(nonatomic,copy) NSString *string;
@property(nonatomic,copy) NSArray *strings;
@property(nonatomic,copy) NSURL *URL;
@property(nonatomic,copy) NSArray *URLs;
@property(nonatomic,copy) UIImage *image;
@property(nonatomic,copy) NSArray *images;
@property(nonatomic,copy) UIColor *color;
@property(nonatomic,copy) NSArray *colors;
#else  /* OBJC2 */
// TODO
#endif /* OBJC2 */

@end

#endif
