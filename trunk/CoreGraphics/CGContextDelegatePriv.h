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
#ifndef CGCONTEXTDELEGATEPRIV_H_
#define CGCONTEXTDELEGATEPRIV_H_

#include <CoreFoundation/CFRuntime.h>
#include <Coregraphics/CGError.h>
#include "CGTypesPriv.h"
#include "CGPathPriv.h"
#include "CGGStatePriv.h"
#include "CGColorSpacePriv.h"
#include "CGRenderingStatePriv.h"
#include "CGColorTransformPriv.h"

CF_EXTERN_C_BEGIN

// Forward declaration
typedef struct CGContextDelegate *CGContextDelegateRef;


enum CGContextDelegateType {

    kCGContextDelegateFinalize = 0,
	kCGContextDelegateGetColorTransform,
	kCGContextDelegateGetBounds,
	kCGContextDelegateDrawLines,
	kCGContextDelegateDrawRects,
	kCGContextDelegateDrawPath,
	kCGContextDelegateDrawImage,
	kCGContextDelegateDrawGlyphs,
	kCGContextDelegateDrawShading,
	kCGContextDelegateDrawDisplayList,
	kCGContextDelegateDrawImages,
	kCGContextDelegateBeginPage,
	kCGContextDelegateEndPage,
	kCGContextDelegateOperation,
	kCGContextDelegateDrawWindowContents,
	kCGContextDelegateDirtyWindowContents,
	kCGContextDelegateBeginLayer,
	kCGContextDelegateEndLayer,
	kCGContextDelegateGetLayer,
	kCGContextDelegateDrawLayer
};
typedef enum CGContextDelegateType CGContextDelegateType;

// Callbacks

typedef int (*CGFunctionPtr)();

typedef CGColorTransformRef (*CGCallbackGetColorTransform) (CGContextDelegateRef ctxDelegate, 
															CGRenderingStateRef rendering, 
															CGGStateRef state);

typedef CGError (*CGCallbackDrawPath) (CGContextDelegateRef ctxDelegate, 
									   CGRenderingStateRef rendering, 
									   CGGStateRef state, 
									   CGPathDrawingMode mode,
									   CGMutablePathRef path);

typedef CGError (*CGCallbackDrawLines) (CGContextDelegateRef ctxDelegate, 
										CGRenderingStateRef rendering, 
										CGGStateRef state,
										const CGPoint points[],
										size_t count);

typedef CGError (*CGCallbackDrawRects) (CGContextDelegateRef ctxDelegate, 
										CGRenderingStateRef rendering, 
										CGGStateRef state,
										const CGRect rects[],
										size_t count);

typedef CGError (*CGCallbackDrawImage) (CGContextDelegateRef ctxDelegate, 
										CGRenderingStateRef rendering, 
										CGGStateRef state,
										CGRect rect,
										CGImageRef image);

typedef CGError (*CGCallbackDrawGlyphs) (CGContextDelegateRef ctxDelegate,
										 CGRenderingStateRef rendering,
										 CGGStateRef state,
										 CGAffineTransform ctm);

typedef CGError (*CGCallbackOperation) (CGContextDelegateRef ctxDelegate,
										CGRenderingStateRef rendering,
										CGGStateRef state,
										CFStringRef op,
										void* tmp);

typedef CGError (*CGCallbackDrawShading) (CGContextDelegateRef ctxDelegate, 
										  CGRenderingStateRef rendering,
										  CGGStateRef state,
										  CGShadingRef shading);


typedef struct CGCallback {

	CGContextDelegateType type;
	void* delegateAddr;
} CGCallback, *CGCallbackRef;

extern CGCallback _kCGCallbacks[];


struct CGContextDelegateInfo {

	CGContextDelegateRef ctxDelegate;	//0x00
										//0x24
	Boolean allowDithering;				//0x35
	Boolean shouldAntialias;			//0x36
	Boolean allowAcceleration;			//0x37

	CGColorTransformRef colorTrans;		//0x3C
	CFTypeID colorTransformID;			//0x44
	//colorTransformMD5					//0x48 - 0x4B
};
typedef struct CGContextDelegateInfo CGContextDelegateInfo, *CGContextDelegateInfoRef;

//sizeof(struct CGContext) = 0x60;
struct CGContextDelegate {

	CFRuntimeBase obj;								//0x00

	CGColorTransformRef	colorTransform;				//0x08
	void* finalize;									//0x0C
	CGCallbackGetColorTransform getColorTransform;	//0x10
	void* getBounds;								//0x14
	CGCallbackDrawLines drawLines;					//0x18
	CGCallbackDrawRects drawRects;					//0x1C
	CGCallbackDrawPath drawPath;					//0x20
	CGCallbackDrawImage drawImage;					//0x24
	CGCallbackDrawGlyphs drawGlyphs;				//0x28
	CGCallbackDrawShading drawShading;				//0x2C
	void* drawDisplayList;							//0x30
	void* drawImages;								//0x34
	void* beginPage;								//0x38
	void* endPage;									//0x3C
	CGCallbackOperation operation;					//0x40
	void* drawWindowContents;						//0x44
	void* dirtyWindowContents;						//0x48
	void* beginLayer;								//0x4C
	void* endLayer;									//0x50
	void* getLayer;									//0x54
	void* drawLayer;								//0x58
	CGContextDelegateInfoRef info;					//0x5C
};
typedef struct CGContextDelegate CGContextDelegate, *CGContextDelegateRef;



//CG_EXTERN CGContextDelegateGetNext();

CG_EXTERN CGContextDelegateRef CGContextDelegateCreate(void* info);
CG_EXTERN void delegate_finalize(CFTypeRef c);
CG_EXTERN CGContextDelegateRef CGContextDelegateRetain(CGContextDelegateRef ctxDelegate);
CG_EXTERN void CGContextDelegateRelease(CGContextDelegateRef ctxDelegate);
CG_EXTERN void CGContextSetDelegate(CGContextRef c, CGContextDelegateRef ctxDelegate);

CG_EXTERN void CGContextDelegateSetCallbacks(CGContextDelegateRef ctxDelegate, const CGCallback* dlArray, int count);
CG_EXTERN void CGContextDelegateSetCallback(CGContextDelegateRef ctxDelegate, CGContextDelegateType type, void* callback);
//CG_EXTERN void CGContextDelegateSetCallbacks(CGContextDelegateRef ctxDelegate, const CGCallback* dlArray, int count);


CG_EXTERN CGContextDelegateInfoRef CGContextDelegateGetInfo(CGContextDelegateRef ctxDelegate);

CG_EXTERN CGError CGContextDelegateOperation(CGContextDelegateRef ctxDelegate,
											 CGRenderingStateRef rendering,
											 CGGStateRef state,
											 CFStringRef op,
											 void* tmp);

CG_EXTERN CGError CGContextDelegateDrawPath(CGContextDelegateRef ctxDelegate, 
											CGRenderingStateRef rendering, 
											CGGStateRef state,
											CGPathDrawingMode mode,
											CGMutablePathRef path);


CG_EXTERN CGError CGContextDelegateDrawRects(CGContextDelegateRef ctxDelegate, 
											 CGRenderingStateRef rendering, 
											 CGGStateRef state,
											 const CGRect rects[],
											 size_t count);

CG_EXTERN CGError CGContextDelegateDrawImage(CGContextDelegateRef ctxDelegate, 
											 CGRenderingStateRef rendering,
											 CGGStateRef state,
											 CGRect rect,
											 CGImageRef image);

CG_EXTERN CGError CGContextDelegateDrawShading(CGContextDelegateRef ctxDelegate, 
											   CGRenderingStateRef rendering,
											   CGGStateRef state,
											   CGShadingRef shading);


CGFunctionPtr* get_callback_address(CGContextDelegateRef ctxDelegate, CGContextDelegateType type, const char* callerName);

CF_EXTERN_C_END

#endif /* CGCONTEXTDELEGATEPRIV_H_ */


