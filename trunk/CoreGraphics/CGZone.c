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
#include <pthread.h>

#include "CGBasePriv.h"
#include "CGZonePriv.h"

static pthread_once_t	gzone_create_once = PTHREAD_ONCE_INIT;
static void* gZone = NULL;

void 
zone_create(void)
{
  return;
}

void* 
CGSZoneCreate()
{
  if ( !gZone )
	  pthread_once(&gzone_create_once, zone_create);
  
  return gZone;
}
