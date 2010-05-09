#import <Foundation/Foundation.h>
#import <UIKit/UIKitDefines.h>

UIKIT_EXTERN_CLASS @interface UILocalizedIndexedCollation : NSObject
{
}

+ (id)currentCollation;

- (NSInteger)sectionForSectionIndexTitleAtIndex:(NSInteger)indexTitleIndex;
- (NSInteger)sectionForObject:(id)object collationStringSelector:(SEL)selector;
- (NSArray *)sortedArrayFromArray:(NSArray *)array collationStringSelector:(SEL)selector;

#ifdef OBJC2
@property(nonatomic, readonly) NSArray *sectionTitles;
@property(nonatomic, readonly) NSArray *sectionIndexTitles;
#else  /* OBJC2 */
// TODO
#endif /* OBJC2 */

@end


