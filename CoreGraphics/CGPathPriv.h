/* Copyright 2010 Smartmobili SARL
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef CGPATHPRIV_H_
#define CGPATHPRIV_H_

#include <CoreFoundation/CFRuntime.h>

#include "CGMacros.h"

CF_EXTERN_C_BEGIN


//struct CGPathElement {
//    CGPathElementType type;
//    CGPoint *points;
//};
//typedef struct CGPathElement CGPathElement;

/////////////////////////////////////////////
// PathChunk - sizeof = 0x98(152)
/////////////////////////////////////////////
typedef struct _PathChunks {

  struct _PathChunks *nextChunk;	//0x00
  int count;						//0x04
  CGPathElementType type; 			//0x08
  CGPoint start;					//0x0C .x 0x10 .y
  CGPoint current;					//0x14 .x 0X18 .y
  float chunk[16];

} PathChunks, *PathChunksRef;

/////////////////////////////////////////////
// CGPath - sizeof = 0xB8(184)
/////////////////////////////////////////////
typedef struct CGPath {

	CFRuntimeBase obj;				//0x00
	bool bIsEmpty;					//0x08
	CGPoint start;					//0x0C .x 0x10 .y
	CGPoint current;				//0x14 .x 0X18 .y
	CGPoint previous; 				//0x1C ?? not sure it's previous
	PathChunksRef lastChunk;		//0xB4

} *CGMutablePathRef;

void CGPathDestroy(CFTypeRef ctf);

CF_EXTERN_C_END

#endif /* CGPATHPRIV_H_ */


