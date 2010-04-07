/****************************************************************************
**
** Copyright (C) 2010 Smartmobili.
** All rights reserved.
** Contact: Smartmobili (contact@smartmobili.com)
**	
** This file is part of the CoreGraphics module of the Coconuts Toolkit.
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
#ifndef CGDISPLAYLISTPRIV_H_
#define CGDISPLAYLISTPRIV_H_

#include <CoreFoundation/CFRuntime.h>
#include "CGContextPriv.h"

CF_EXTERN_C_BEGIN

//////////////////////////////////////////////////////////
//sizeof = 0x14(20)
//////////////////////////////////////////////////////////
typedef struct CGDisplayListData {
	size_t foo;
} CGDisplayListData, *CGDisplayListDataRef;






//////////////////////////////////////////////////////////
//sizeof = 0x1D4(468)
//////////////////////////////////////////////////////////
typedef struct CGDisplayList {

	CFRuntimeBase obj;					//0x00
	


} CGDisplayList, *CGDisplayListRef;


CG_EXTERN CFTypeID CGDisplayListGetTypeID(void);

CG_EXTERN CGDisplayListRef CGDisplayListCreateWithRect(CGRect rect);
CG_EXTERN void	dl_Finalize(CFTypeRef cf);
CG_EXTERN CGContextRef CGDisplayListContextCreate(void* dummy);
CG_EXTERN CGContextDelegateRef CGDisplayListContextDelegateCreate(void* dummy);



CG_EXTERN CGDisplayListDataRef	dlr_create(void* zobby);
CG_EXTERN void		dlr_InitializeDelegateCallbacks(CGContextDelegateRef ctxDelegate);
CG_EXTERN void		dlr_Finalize(CGContextDelegateRef ctxDelegate);
CG_EXTERN CGRect	dlr_GetBounds(CGContextDelegateRef ctxDelegate);
CG_EXTERN void		dlr_DrawLines(CGContextDelegateRef ctxDelegate);
CG_EXTERN void		dlr_DrawRects(CGContextDelegateRef ctxDelegate);
CG_EXTERN void		dlr_DrawPath(CGContextDelegateRef ctxDelegate);
CG_EXTERN void		dlr_DrawImage(CGContextDelegateRef ctxDelegate);
CG_EXTERN void		dlr_DrawGlyphs(CGContextDelegateRef ctxDelegate);
CG_EXTERN void		dlr_DrawShading(CGContextDelegateRef ctxDelegate);
CG_EXTERN void		dlr_DrawDisplayList(CGContextDelegateRef ctxDelegate);
CG_EXTERN void		dlr_BeginPage(CGContextDelegateRef ctxDelegate);
CG_EXTERN void		dlr_EndPage(CGContextDelegateRef ctxDelegate);
CG_EXTERN void		dlr_Operation(CGContextDelegateRef ctxDelegate);
CG_EXTERN void		dlr_BeginLayer(CGContextDelegateRef ctxDelegate);
CG_EXTERN void		dlr_EndLayer(CGContextDelegateRef ctxDelegate);
CG_EXTERN void		dlr_GetLayer(CGContextDelegateRef ctxDelegate);
CG_EXTERN void		dlr_DrawLayer(CGContextDelegateRef ctxDelegate);


CF_EXTERN_C_END

#endif /* CGDISPLAYLISTPRIV_H_ */


