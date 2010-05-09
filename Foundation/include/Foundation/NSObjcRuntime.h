#import <objc/objc.h>
#include <stdarg.h>
#include <stdint.h>
#include <limits.h>
#include <AvailabilityMacros.h>
#include <TargetConditionals.h>


//FIXME : 64 bits !!!!!!!
typedef int NSInteger;
typedef unsigned int NSUInteger;


#define NSIntegerMax    LONG_MAX
#define NSIntegerMin    LONG_MIN
#define NSUIntegerMax   ULONG_MAX

#define NSINTEGER_DEFINED 1


enum {
   NSOrderedAscending = -1,
   NSOrderedSame,
   NSOrderedDescending
};
typedef NSInteger NSComparisonResult;

enum {
   NSNotFound = NSIntegerMax
};


@class NSString, Protocol;

NSString * NSStringFromClass (Class aClass);
Class NSClassFromString (NSString *aClassName);

NSString *NSStringFromSelector (SEL aSelector);
SEL NSSelectorFromString (NSString *aSelectorName);

NSString * NSStringFromProtocol (Protocol *proto);
Protocol *NSProtocolFromString (NSString *namestr);


const char * NSGetSizeAndAlignment (const char *typePtr, NSUInteger *sizep, NSUInteger *alignp);

void NSLog (NSString *format,...);
void NSLogv (NSString *format,va_list args);


