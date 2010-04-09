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
#ifndef CGBASEPRIV_H_
#define CGBASEPRIV_H_

#define HAVE_COREFOUNDATION 1

#if HAVE_COREFOUNDATION
#define CF_BUILDING_CF 1
#include <CoreFoundation/CoreFoundation.h>
#include "CFInternal.h"
#else
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#endif /* HAVE_COREFOUNDATION */




#include "CGTypesPriv.h"
#include "CGErrorPriv.h"


#define CHK( x ) do{ if( ( x ) == 0) { goto Cleanup; }} while( FALSE );

#endif /* CGBASEPRIV_H_ */