/*	NSAutoreleasePool.h
	Copyright (c) 1994-2007, Apple Inc. All rights reserved.
*/

#import <Foundation/NSObject.h>

@interface NSAutoreleasePool : NSObject {

}

+ (void)addObject:(id)anObject;
- (void)addObject:(id)anObject;
- (void)drain;


@end

