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

	kCGColorSpaceTypeDeviceUnknown = -1,
	kCGColorSpaceTypeDeviceGray,
	kCGColorSpaceTypeDeviceRGB,
	kCGColorSpaceTypeDeviceCMYK,
	kCGColorSpaceTypeCalibratedGray,
	kCGColorSpaceTypeCalibratedRGB,
	kCGColorSpaceTypeLab,
	kCGColorSpaceTypeICC,
	kCGColorSpaceTypeIndexed,
	kCGColorSpaceTypeDeviceN,
	kCGColorSpaceTypePattern,
	kCGColorSpaceTypeSystemDefaultGray,
	kCGColorSpaceTypeSystemDefaultRGB,
	kCGColorSpaceTypeSystemDefaultCMYK,

};
typedef enum CGColorSpaceType CGColorSpaceType;


typedef bool (*CGColorSpaceEqual)(CGColorSpaceRef cs1, CGColorSpaceRef cs2);

typedef void (*CGColorSpaceFinalize)(CFTypeRef ctf);

typedef void (*CGColorSpaceGetMD5)(unsigned char* md5);

typedef CGFloat* (*CGColorSpaceGetDefaultColorComponents2)(CGColorSpaceRef cs);

typedef CGColorRef (*CGColorSpaceCreateDefaultColor)(CGColorSpaceRef cs);

typedef CGColorSpaceRef (*CGColorSpaceResolved)(CGColorSpaceRef cs);


struct CGColorSpaceCallbacks {
    unsigned int version;
    CGColorSpaceEqual equal;
	CGColorSpaceFinalize finalize;
    CGColorSpaceGetMD5 getMD5;
    CGColorSpaceGetDefaultColorComponents2 getDefaultColorComponents;
    CGColorSpaceCreateDefaultColor createDefaultColor;
	CGColorSpaceResolved resolved;
};
typedef struct CGColorSpaceCallbacks
    CGColorSpaceCallbacks;

//CGColorSpaceCallBacks

typedef struct CGColorSpaceState {
	size_t refcount;						//0x00
	bool isPattern;							//0x04
	bool isUncalibrated;					//0x05
	bool supportsOuput;						//0x06
	bool unknown07;							//0x07
	bool unknown08;							//0x08
	CGColorSpaceType spaceType;				//0x0C
	CGColorSpaceModel spaceModel;			//0x10
	CGColorSpaceModel processColorModel;	//0x14
	size_t numberOfComponents;				//0x18
	//int index;								//0x28 ? maybe float* components instead ??
	float* components;						//0x28
	CGColorSpaceCallbacks* callbacks;		//0x2C
	void* associate;						//0x30
	
	/////////////// below maybe inherited struct
	//CGColorSpaceRef baseColorSpace;			//0x34
	//size_t baseColorSpaceCount;				//0x38
	//int id;									//0x40
	//...
} CGColorSpaceState, *CGColorSpaceStateRef;

typedef struct CGColorSpaceStatePattern {
	CGColorSpaceState state;				//0x00
	CGColorSpaceRef baseColorSpace;			//0x34

} CGColorSpaceStatePattern, *CGColorSpaceStatePatternRef;


typedef struct CGColorSpaceStateIndexed {
	CGColorSpaceState state;				//0x00
	CGColorSpaceRef baseColorSpace;			//0x34   
	size_t lastIndex;						//0x38
	uint8_t* indexes;						//0x3C

} CGColorSpaceStateIndexed, *CGColorSpaceStateIndexedRef;


typedef struct CGColorSpaceStateICC {
	CGColorSpaceState state;				//0x00
	size_t numberOfComponents;				//0x34 ???? numberOfComponents is already inside state
	int id;									//0x40
	CGColorSpaceRef colorSpace;				//0x58

} CGColorSpaceStateICC, *CGColorSpaceStateICCRef;

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
CG_EXTERN const CFStringRef kCGColorSpaceCalibratedGray;
CG_EXTERN const CFStringRef kCGColorSpaceCalibratedRGB;
CG_EXTERN const CFStringRef kCGColorSpaceUncalibratedGray;
CG_EXTERN const CFStringRef kCGColorSpaceUncalibratedRGB;
CG_EXTERN const CFStringRef kCGColorSpaceUncalibratedCMYK;
CG_EXTERN const CFStringRef kCGColorSpaceGenericHDR;
CG_EXTERN const CFStringRef kCGColorSpaceGenericRGBHDR;
CG_EXTERN const CFStringRef kCGColorSpaceUndo601;
CG_EXTERN const CFStringRef kCGColorSpaceColoredPattern;

CG_EXTERN const CFStringRef kCGColorSpaceLAB;
CG_EXTERN const CFStringRef kCGColorSpaceIndexed;
CG_EXTERN const CFStringRef kCGColorSpaceDeviceN;

	



/* Notifications */
CG_EXTERN const CFStringRef kCGColorSpaceWillDeallocate;




/* functions */
void	cs_finalize(CFTypeRef ctf);

Boolean cs_equal(CFTypeRef cf1, CFTypeRef cf2);

CFHashCode cs_hash(CFTypeRef cf);

CFStringRef cs_copy_debug_description(CFTypeRef cf);

void csNotificationCenterCreate(void);

CGNotificationCenterRef getNotificationCenter(bool notFinalize);

bool CGColorSpaceEqualToColorSpace(CGColorSpaceRef cs1, CGColorSpaceRef cs2);

CGColorRef CGColorSpaceCopyDefaultColor(CGColorSpaceRef space);

CGColorSpaceType CGColorSpaceGetType(CGColorSpaceRef space);

CGColorSpaceRef CGColorSpaceCreate(CGColorSpaceType type, size_t numberOfComponents);

CGColorSpaceRef CGColorSpaceCreateDisplayGrayWithID(int id);

CGColorSpaceRef CGColorSpaceCreateDisplayRGBWithID(int id);

CGColorSpaceRef CGColorSpaceCreateWithIndex(int index);

CGColorSpaceRef create_display_color_space(size_t numComponents);

CGColorSpaceRef create_device_color_space(size_t numComponents);

CGColorSpaceRef create_generic_color_space(size_t numComponents);

CGColorSpaceRef create_uncalibrated_color_space(size_t numComponents);

CGColorSpaceRef create_color_space_with_path(CFStringRef path);

CGColorSpaceRef create_display_space_with_id(size_t numComponents, int id);

CFIndex CGColorSpaceGetIndexForName(CFStringRef name);

CGColorSpaceRef CGColorSpaceCreateWithState(CGColorSpaceStateRef colorSpaceState);

void color_space_state_release(CGColorSpaceStateRef colorSpaceState);

bool color_space_state_equal(CGColorSpaceStateRef state1, CGColorSpaceStateRef state2);

CGColorSpaceStateRef color_space_state_retain(CGColorSpaceStateRef colorSpaceState);

void device_gray_get_md5(unsigned char* md5);

void device_rgb_get_md5(unsigned char* md5);

CGFloat* device_get_default_color_components(CGColorSpaceRef cs);

CGColorSpaceRef device_create_resolved(CGColorSpaceRef cs);

CF_EXTERN_C_END

#endif /* CGCOLORPSPACERIV_H_ */


