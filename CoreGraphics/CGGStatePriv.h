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
#ifndef CGGSTATE_H_
#define CGGSTATE_H_

#include <CoreFoundation/CFRuntime.h>
#include <CoreGraphics/CoreGraphics.h>

//#include "CGContextPriv.h"
#include "CGDashPriv.h"
#include "CGColorSpacePriv.h"
#include "CGRenderingStatePriv.h"



CF_EXTERN_C_BEGIN

enum CGCompositeMode {
	// Thanks to cairo
	kCGCompositeSourceOver = 0,
	kCGCompositeSourceIn,
	kCGCompositeSourceOut,
	kCGCompositeSourceAtop,
	kCGCompositeCopy,
	kCGCompositeDestinationOver,
	kCGCompositeDestinationIn,
	kCGCompositeDestinationOut,
	kCGCompositeDestinationAtop, 
	kCGCompositeXOR,
	kCGCompositePlusLighter,
	kCGCompositePlusDarker,
};
typedef enum CGCompositeMode CGCompositeMode;

////////////////////////////////////////////
// CGClip
typedef struct __CGClip {
	
	signed long refcount;

} CGClip, *CGClipRef;

enum {
    kCGClipHasMask = 1
};
typedef uint32_t CGClipInfo;



////////////////////////////////////////////
//CGDevice - sizeof = 0x1C
typedef struct CGDevice {
	
	signed long refcount;				//0x00
	CGFloat flatness;					//0x04
	uint32_t overprint;					//0x0C
	uint32_t overprintMode;				//0x10
	CGFunctionRef blackGeneration;		//0x14
	CGFunctionRef underColorRemoval;	//0x18


} CGDevice, *CGDeviceRef;


////////////////////////////////////////////
//CGStateStroke - sizeof = 0x24
typedef struct CGStateStroke {
	
	signed long refcount;		//0x00
	CGFloat lineWidth;			//0x04
	CGLineCap lineCap;			//0x08
	CGLineJoin lineJoin;		//0x0C
	CGFloat miterLimit;			//0x10
	CGFloat strokeAdjust;		//0x18
	CGDashRef dash;				//0x1C
	CGColorRef color;			//0x20

} CGStateStroke, *CGStateStrokeRef;

////////////////////////////////////////////
//CGDevice - sizeof = 0x28
typedef struct CGStateText {
	
	signed long refcount;		//0x00
	CGFontRef font;				//0x04
	CGFloat size;				//0x08
	CGFloat spacing;			//0x0C
	CGTextDrawingMode mode;		//0x10
	Boolean bUnknown1;			//0x18
	Boolean bUnknown2;			//0x24
	Boolean bUnknown3;			//0x25
	Boolean bUnknown4;			//0x26
	Boolean bUnknown5;			//0x27

} CGStateText, *CGStateTextRef;

////////////////////////////////////////////
//CGGStateRendering - sizeof = 0x2C
typedef struct CGGStateRendering {
	
	signed long refcount;		//0x00
	CGFloat alpha;				//0x04
	CGBlendMode mode;			//0x08 // Change with CGCompositeMode
	CGStyleRef style;			//0x0C
	CGSize size;				//0x10
	Boolean bUnknown1;			//0x24
	Boolean bUnknown2;			//0x25
	CGSoftMaskRef softMask;		//0x28


} CGGStateRendering, *CGGStateRenderingRef;



////////////////////////////////////////////
//CGClipStack
typedef struct CGClipStack {
	
	signed long refcount;		//0x00
	CFTypeID id;				//0x04
	CGClipInfo clipInfo;		//0x08
	CGRect rect;				//0x0C
	CGRect rect2;				//0x1C
	CGRect rect3;				//0x2C
	int field3C;				//0x3C			
	size_t count;				//0x40
	CGClipRef *clips;			//0x44

}	CGClipStack, *CGClipStackRef;


typedef struct CGGState {

	signed long refcount;			//0x00

	CGAffineTransform CTM;			//0x04
	CGFloat fontSize;				//0x08
	CGColorSpaceRef colorSpace;		//0x10
	CGColorRef fillColor;			//0x1C
	CGColorRef strokeColor;			//0x20 ???
	CGRect clipRect;				//0x20 ??? (see CGGStateResetClip)
	bool shouldAntialias;			//0x24
	CGBlendMode blendMode;
	
	CGFontRef font;					
	
	
	bool hasClipping;				//0x30
	CGClipStackRef clipStack;		//0x34
	Boolean hasRendering;			//0x38
	CGGStateRenderingRef rendering; //0x3C
	Boolean hasStroke;				//0x40
	CGStateStrokeRef stateStroke;	//0x44
	Boolean hasText;				//0x48
	CGStateTextRef stateText;		//0x4C
	Boolean hasDevice;				//0x50
	CGDeviceRef device;				//0x54

} CGGState, *CGGStateRef;


typedef struct __CGGStack {

	signed long refcount;	//0x00
	long capacity;			//0x04
	size_t count;			//0x08
	CGGStateRef *gstate;	//0x0C
	

} CGGStack, *CGGStackRef;


/* Private functions */

CGGStateRef push(CGGStackRef stack, CGGStateRef agState);

void deviceStateRelease(CGDeviceRef device);
void maybeCopyDeviceState(CGGStateRef agstate);
void strokeStateReset(CGStateStrokeRef stateStroke);
void strokeStateRelease(CGStateStrokeRef stateStroke);
void maybeCopyStrokeState(CGGStateRef agstate);
void textStateRelease(CGStateTextRef textState);
void maybeCopyRenderingState(CGGStateRef agstate);
void renderingStateReset(CGGStateRenderingRef gStateRendering);
void renderingStateRelease(CGGStateRenderingRef gStateRendering);
void maybeCopyTextState(CGGStateRef agstate);

/* Stack for Graphic context */
CG_EXTERN CGGStackRef		CGGStackCreate();
CG_EXTERN CGGStackRef		CGGStackCreateWithGState(CGGStateRef gstate);
CG_EXTERN CGGStateRef		CGGStackGetGState(CGGStackRef stack);
CG_EXTERN CGGStateRef		CGGStackSave(CGGStackRef stack);
CG_EXTERN CGGStateRef		CGGStackRestore(CGGStackRef stack);

CG_EXTERN void				CGGStackReset(CGGStackRef stack);
CG_EXTERN void				CGGStackRelease(CGGStackRef stack);


CG_EXTERN CGGStateRef		CGGStateCreate();
CG_EXTERN CGGStateRef		CGGStateCreateCopy(CGGStateRef state);
CG_EXTERN void				CGGStateClipCopy(CGGStateRef state, CGGStateRef stateSrc);
CG_EXTERN void				CGGStateDeviceCopy(CGGStateRef state, CGGStateRef stateSrc);
CG_EXTERN void				CGGStateRenderingCopy(CGGStateRef state, CGGStateRef stateSrc);
CG_EXTERN void				CGGStateStrokeCopy(CGGStateRef state, CGGStateRef stateSrc);
CG_EXTERN void				CGGStateTextCopy(CGGStateRef state, CGGStateRef stateSrc);

/* reset */
CG_EXTERN void				CGGStateReset(CGGStateRef state);
CG_EXTERN void				CGGStateClipReset(CGGStateRef state);
CG_EXTERN void				deviceStateReset(CGDeviceRef device);
CG_EXTERN void				CGGStateResetClip(CGGStateRef state);


/* getters */
CG_EXTERN CGAffineTransform	CGGStateGetCTM(CGGStateRef state);
CG_EXTERN CGColorRef		CGGStateGetFillColor(CGGStateRef state);
CG_EXTERN CGColorRef		CGGStateGetStrokeColor(CGGStateRef state);
CG_EXTERN void				CGGStateSetAlpha(CGGStateRef state, CGFloat alpha);
CG_EXTERN CGFloat			CGGStateGetLineWidth(CGGStateRef state);
CG_EXTERN CGFloat			CGGStateGetFlatness(CGGStateRef state);

/* setters */
CG_EXTERN void				CGGStateSetCTM(CGGStateRef state, CGAffineTransform ctm);
CG_EXTERN void				CGGStateSetCompositeOperation(CGGStateRef gstate, CGCompositeMode compositeMode);
CG_EXTERN void				CGGStateSetLineWidth(CGGStateRef state, CGFloat width);
CG_EXTERN void				CGGStateSetLineCap(CGGStateRef state, CGLineCap cap);
CG_EXTERN void				CGGStateSetLineDash(CGGStateRef state, CGDashRef dash);
CG_EXTERN void				CGGStateSetLineJoin(CGGStateRef state, CGLineJoin join);
CG_EXTERN void				CGGStateSetMiterLimit(CGGStateRef state, CGFloat miter);
CG_EXTERN void				CGGStateSetFlatness(CGGStateRef state, CGFloat flatness);
CG_EXTERN void				CGGStateSetStrokeAdjust(CGGStateRef state, CGFloat strokeAdjust);
CG_EXTERN void				CGGStateSetFillColor(CGGStateRef agstate, CGColorRef color);
CG_EXTERN void				CGGStateSetFontSize(CGGStateRef agstate, CGFloat size);
CG_EXTERN void				CGGStateSetBlackGeneration(CGGStateRef gstate, CGFunctionRef blackGeneration);
CG_EXTERN void				CGGStateSetUndercolorRemoval(CGGStateRef gstate, CGFunctionRef underColorRemoval);

/* Reset states */
CG_EXTERN void				CGGStateDeviceReset(CGGStateRef agstate);
CG_EXTERN void				CGGStateTextReset(CGGStateRef agstate);
CG_EXTERN void				CGGStateRenderingReset(CGGStateRef agstate);
CG_EXTERN void				CGGStateStrokeReset(CGGStateRef agstate);


/* Release states */
CG_EXTERN void				CGGStateRelease(CGGStateRef state);
CG_EXTERN void				CGGStateClipRelease(CGGStateRef state);
CG_EXTERN void				CGGStateDeviceRelease(CGGStateRef state);
CG_EXTERN void				CGGStateRenderingRelease(CGGStateRef state);
CG_EXTERN void				CGGStateStrokeRelease(CGGStateRef state);
CG_EXTERN void				CGGStateTextRelease(CGGStateRef state);

/* Clipping */
CG_EXTERN void				CGClipRelease(CGClipRef clip);
CG_EXTERN CGClipStackRef	CGClipStackCreateMutable();
CG_EXTERN void				CGClipStackRelease(CGClipStackRef clipStack);
CG_EXTERN CGClipStackRef	CGClipStackRetain(CGClipStackRef clipStack);

CG_EXTERN void				CGGStateClipToPath(CGGStateRef state, CGPathRef path, CGPathDrawingMode mode);

CF_EXTERN_C_END

#endif /* CGGSTATE_H_ */


