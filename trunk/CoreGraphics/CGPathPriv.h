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
#ifndef CGPATHPRIV_H_
#define CGPATHPRIV_H_

#include <CoreFoundation/CFRuntime.h>

#include "CGMacros.h"

CF_EXTERN_C_BEGIN

/////////////////////////////////////////////
// CGPathElements - sizeof = 0x98(152)
/////////////////////////////////////////////
typedef struct CGPathElements {

  struct CGPathElements *nextChunk;	//0x00
  int count;						//0x04
  CGPathElementType type; 			//0x08

} CGPathElements, *CGPathElementsRef;

typedef struct CGPath {

	CFRuntimeBase obj;				//0x00
	bool bIsEmpty;					//0x08
	CGPoint start;					//0x0C .x 0x10 .y
	CGPoint current;				//0x14 .x 0X18 .y
	CGPathElements elements; 		//0x1C 
	CGPathElementsRef lastChunk;	//0xB4

} *CGMutablePathRef;

void CGPathDestroy(CFTypeRef ctf);

CF_EXTERN_C_END

#endif /* CGPATHPRIV_H_ */


