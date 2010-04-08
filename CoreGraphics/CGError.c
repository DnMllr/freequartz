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
#include <CoreGraphics/CGError.h>

#include "CGBasePriv.h"
#include "CGErrorPriv.h"


void CGPostError(const char *format, ...)
{
	va_list args;
	char buff[1024];

	va_start(args, format);
	_vsnprintf(buff, sizeof(buff) - 1, format, args);
	va_end(args);
	
	printf(buff);
}