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
#include <CoreGraphics/CGContext.h>

#include "CGBasePriv.h"
#include "CGContextPriv.h"
#include "CGDashPriv.h"


CGDashRef CGDashCreate(CGFloat phase, const CGFloat lengths[], size_t count)
{
	int nFixed;
	CGDashRef dash;
	
	if (!count || !lengths)
		return NULL;
	
	nFixed = sizeof(CGDash) - sizeof(CGFloat*);
	dash = (CGDashRef) calloc(1, nFixed + count*sizeof(CGFloat));
	if (dash) {
		memcpy(dash->lengths, lengths, count * sizeof(CGFloat));
	}

	return dash;
}

const CGFloat* CGDashGetPattern(CGDashRef dash, float* phase, size_t* count)
{
	if (!dash)
		return NULL;

	if (phase)
		*phase = dash->phase;
	if (count)
		*count = dash->count;
	
	return dash->lengths;
}

Boolean CGDashEqualToDash(CGDashRef dash1, CGDashRef dash2)
{
	Boolean bRet = FALSE;
	int cmp;

	if (dash1 == dash2)
		return TRUE;
	if (!dash1 || !dash2)
		return FALSE;
	if ((dash1->phase != dash2->phase) || 
		(dash1->count != dash2->count))
		return FALSE;
	
	cmp = memcmp(dash1->lengths, dash2->lengths, dash1->count * sizeof(CGFloat));
	if (cmp == 0) 
		bRet =  TRUE; 

	return bRet;
}

CGDashRef CGDashRetain(CGDashRef dash)
{
	if (!dash) { return NULL; }
	
	dash->refcount++;
	
	return dash;
}

void CGDashRelease(CGDashRef dash)
{
	if (!dash) { return; }
	
	dash->refcount--;

	if (dash->refcount == 0) {
		free(dash->lengths);
	}
}


    







