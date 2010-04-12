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
#include "CGBasePriv.h"
#include "CGBltPriv.h"


// Not sure yet how to decode this
//blt_depth[] = {
//	{ 2, 8, 16, 0		},		//A8_depth
//	{ 2, 8, 17, 4		},		//W8_depth
//	{ 8, 8, 0x33, 0x88	},		//RGBA32_depth
//	{ 8, 8, 0x33, 0x98	},		//rgba32_depth
//	{ 8, 8, 0x33, 0x48	},		//ARGB32_depth
//	{ 8, 8, 0x33, 0x48	},		//argb32_depth
//	{ 4, 5, 0x33, 0x44	},		//RGB555_depth
//	{ 4, 5, 0x33, 0x54	},		//rgb555_depth
//	{ 0, 0, 0x00, 0x00  }
//};


void* 
CGBlt_depth(const char *format)
{
	if (!format || !strlen(format))
		return NULL;


	return NULL;
}