/****************************************************************************
**
** Copyright (C) 2010 Smartmobili.
** All rights reserved.
** Contact: Smartmobili (contact@smartmobili.com)
**	
** This file is part of the CoreGraphics module of the freequartz Toolkit.
**
**
** GNU Lesser General Public License Usage	
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements	
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
****************************************************************************/
#ifndef CGCONTEXTDELEGATEPRIV_H_
#define CGCONTEXTDELEGATEPRIV_H_

#include <CoreFoundation/CFRuntime.h>
#include <Coregraphics/CGError.h>
#include "CGTypesPriv.h"
#include "CGPathPriv.h"
#include "CGGStatePriv.h"
#include "CGColorSpacePriv.h"
#include "CGRenderingStatePriv.h"

CF_EXTERN_C_BEGIN

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
typedef CGError (*CGCallbackDrawPath) (CGContextDelegateRef ctxDelegate, 
									   CGRenderingStateRef rendering, 
									   CGGStateRef state, CGPathDrawingMode mode,
									   CGMutablePathRef path);


typedef struct CGCallback {
	CGContextDelegateType type;
	//void (*CGCallbackFunc) (CGRenderingStateRef rendering, CGGStateRef state);
	void* delegateAddr;
} CGCallback, *CGCallbackRef;

extern CGCallback _kCGCallbacks[];


//sizeof(struct CGContext) = 0x60;
struct CGContextDelegate {
	CFRuntimeBase obj;				//0x00
	
	void* finalize;					//0x0C
	void* getColorTransform;		//0x10
	void* getBounds;				//0x14
	void* drawLines;				//0x18
	void* drawRects;				//0x1C
	void* drawPath;					//0x20
	void* drawImage;				//0x24
	void* drawGlyphs;				//0x28
	void* drawShading;				//0x2C
	void* drawDisplayList;			//0x30
	void* drawImages;				//0x34
	void* beginPage;				//0x38
	void* endPage;					//0x3C
	void* operation;				//0x40
	void* drawWindowContents;		//0x44
	void* dirtyWindowContents;		//0x48
	void* beginLayer;				//0x4C
	void* endLayer;					//0x50
	void* getLayer;					//0x54
	void* drawLayer;				//0x58
	void* info;						//0x5C
};
typedef struct CGContextDelegate CGContextDelegate, *CGContextDelegateRef;






CG_EXTERN CGContextDelegateRef CGContextDelegateCreate();
CG_EXTERN void delegate_finalize(CFTypeRef c);
CG_EXTERN CGContextDelegateRef CGContextDelegateRetain(CGContextDelegateRef ctxDelegate);
CG_EXTERN void CGContextDelegateRelease(CGContextDelegateRef ctxDelegate);
CG_EXTERN void CGContextSetDelegate(CGContextRef c, CGContextDelegateRef ctxDelegate);

CG_EXTERN void CGContextDelegateSetCallbacks(CGContextDelegateRef ctxDelegate, const CGCallback* dlArray, int count);
CG_EXTERN void CGContextDelegateSetCallback(CGContextDelegateRef ctxDelegate, CGContextDelegateType type, void* callback);
//CG_EXTERN void CGContextDelegateSetCallbacks(CGContextDelegateRef ctxDelegate, const CGCallback* dlArray, int count);


CG_EXTERN void CGContextDelegateOperation(void* delegate1, void* delegate2, CFStringRef op);
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


void* get_callback_address(CGContextDelegateRef ctxDelegate, CGContextDelegateType type);

CF_EXTERN_C_END

#endif /* CGCONTEXTDELEGATEPRIV_H_ */


