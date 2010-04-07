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
#include <CoreGraphics/CGGeometry.h>

#include "CGBasePriv.h"
#include "CGPathPriv.h"


const CGPoint	CGPointZero = {0,0};
const CGRect	CGRectZero = {0,0,0,0};
const CGRect	CGRectInfinite = {-1.7014e38, -1.7014e38, 3.4028e38, 3.4028e38}; // TODO CHECK VALUES

CGFloat CGRectGetHeight(CGRect rect)
{
	return (rect.size.height);
}

CGFloat CGRectGetWidth(CGRect rect)
{
	return (rect.size.width);
}

CGFloat CGRectGetMinX(CGRect rect)
{
	return (rect.origin.x);
}

CGFloat CGRectGetMinY(CGRect rect)
{
	return (rect.origin.y);
}

CGFloat CGRectGetMidX(CGRect rect)
{
	return (rect.origin.x + rect.size.width/2);
}

CGFloat CGRectGetMidY(CGRect rect)
{
	return (rect.origin.y + rect.size.height/2);
}

CGFloat CGRectGetMaxX(CGRect rect)
{
	return (rect.origin.x + rect.size.width);
}

CGFloat CGRectGetMaxY(CGRect rect)
{
	return (rect.origin.y + rect.size.height);
}