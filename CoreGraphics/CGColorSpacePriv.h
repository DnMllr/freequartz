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
#ifndef CGCOLORPSPACERIV_H_
#define CGCOLORPSPACERIV_H_

#include <CoreFoundation/CFRuntime.h>

#include "CGMacros.h"
#include "CGColorPriv.h"

CF_EXTERN_C_BEGIN

typedef struct CGColorSpace *CGColorSpaceRef;
typedef struct CGCMSUtilsPlatformSet *CGCMSUtilsPlatformSetRef;

typedef struct CGNotificationCenter *CGNotificationCenterRef;

/* constants */
enum CGColorSpaceType {

	kCGColorSpaceTypeDeviceUnknown = 0,
	kCGColorSpaceTypeDisplayGray,
	kCGColorSpaceTypeDisplayRGB,
	kCGColorSpaceTypeDeviceGray,
	kCGColorSpaceTypeDeviceRGB,
	kCGColorSpaceTypeDeviceCMYK,
	kCGColorSpaceTypeSystemDefaultGray,
	kCGColorSpaceTypeSystemDefaultRGB,
	kCGColorSpaceTypeSystemDefaultCMYK,

	kCGColorSpaceTypePattern = 14

};
typedef enum CGColorSpaceType CGColorSpaceType;


typedef struct CGColorSpaceState {
	
	bool isUncalibrated;					//0x05
	bool supportsOuput;						//0x06
	CGColorSpaceType spaceType;				//0x0C
	CGColorSpaceModel spaceModel;			//0x10
	CGColorSpaceModel processColorModel;	//0x14
	size_t numberOfComponents;				//0x18
	void* associate;						//0x30
	CGColorSpaceRef baseColorSpace;			//0x34
	size_t baseColorSpaceCount;				//0x38
} CGColorSpaceState, *CGColorSpaceStateRef;



typedef struct CGColorSpace {
	CFRuntimeBase obj;						//0x00
	CGColorSpaceStateRef state;				//0x08
} CGColorSpace, *CGColorSpaceRef;


#if 0
//sizeof(struct CGColorSpace) = 0x64;
typedef struct CGColorSpace {
	CFRuntimeBase obj;						//0x00

	bool isSingleton;						//0x08
	CGColorSpaceType spaceType;				//0x0C
	CGColorSpaceModel spaceModel;			//0x10
	CGColorSpaceModel processColorModel;	//0x14
	size_t numberOfComponents;				//0x18
	CGColorRef defaultColor;				//0x1C
	CGDataProviderRef provider;				//0x3C
	CGCMSUtilsPlatformSetRef cmsPlatform40;	//0x40
	CGCMSUtilsPlatformSetRef cmsPlatform44;	//0x44
	CGColorSpaceRef *cs5C;					//0x5C
								
} CGColorSpace, *CGColorSpaceRef;
#endif

/* private colorspace constants */
CG_EXTERN const CFStringRef kCGColorSpaceDisplayGray;
CG_EXTERN const CFStringRef kCGColorSpaceDisplayRGB;
CG_EXTERN const CFStringRef kCGColorSpaceDeviceGray;
CG_EXTERN const CFStringRef kCGColorSpaceDeviceRGB;
CG_EXTERN const CFStringRef kCGColorSpaceDeviceCMYK;
CG_EXTERN const CFStringRef kCGColorSpaceSystemDefaultGray;
CG_EXTERN const CFStringRef kCGColorSpaceSystemDefaultRGB;
CG_EXTERN const CFStringRef kCGColorSpaceSystemDefaultCMYK;
CG_EXTERN const CFStringRef kCGColorSpaceUncalibratedGray;
CG_EXTERN const CFStringRef kCGColorSpaceUncalibratedRGB;
CG_EXTERN const CFStringRef kCGColorSpaceUncalibratedCMYK;
CG_EXTERN const CFStringRef kCGColorSpaceGenericHDR;
CG_EXTERN const CFStringRef kCGColorSpaceGenericRGBHDR;
CG_EXTERN const CFStringRef kCGColorSpaceUndo601;
CG_EXTERN const CFStringRef kCGColorSpaceColoredPattern;

/* Notifications */
CG_EXTERN const CFStringRef kCGColorSpaceWillDeallocate;




/* functions */
void csFinalize(CFTypeRef ctf);

void csNotificationCenterCreate(void);

CGNotificationCenterRef getNotificationCenter(bool notFinalize);

bool CGColorSpaceEqualToColorSpace(CGColorSpaceRef cs1, CGColorSpaceRef cs2);

CGColorRef CGColorSpaceCopyDefaultColor(CGColorSpaceRef space);

CGColorSpaceType CGColorSpaceGetType(CGColorSpaceRef space);

CGColorSpaceRef CGColorSpaceCreateWithIndex(int index);

CGColorSpaceRef create_display_color_space(CGColorSpaceModel spaceModel);

CGColorSpaceRef create_device_color_space(CGColorSpaceModel colorModel);

CFIndex CGColorSpaceGetIndexForName(CFStringRef name);

CGColorSpaceRef CGColorSpaceCreateWithState(CGColorSpaceStateRef colorSpaceState);

void color_space_state_release(CGColorSpaceStateRef colorSpaceState);

bool color_space_state_equal(CGColorSpaceStateRef state1, CGColorSpaceStateRef state2);

CGColorSpaceStateRef color_space_state_retain(CGColorSpaceStateRef colorSpaceState);



CF_EXTERN_C_END

#endif /* CGCOLORPSPACERIV_H_ */


