#import <Foundation/Foundation.h>
#import <UIKit/UIKitDefines.h>

UIKIT_EXTERN NSString * const UINibExternalObjects;

@interface NSBundle(UINibLoadingAdditions)
- (NSArray *)loadNibNamed:(NSString *)name owner:(id)owner options:(NSDictionary *)options;
@end

@interface NSObject(UINibLoadingAdditions)
- (void)awakeFromNib;
@end

UIKIT_EXTERN NSString * const UINibProxiedObjectsKey;
