/*  gnu4wince: Windows CE C Runtime Library "compatibility" library.
 *
 *  Copyright (C) 2007-2008 smartmobili.com.  All rights reserved.
 *  http://www.smartmobili.com
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */


#ifndef _GNU4WINCE_TIMEB_H
#define _GNU4WINCE_TIMEB_H


#ifdef __cplusplus
extern "C" {
#endif


#include <time.h>



struct timeb
{
	time_t			time;
	unsigned short	millitm;
	short			timezone;
	short			dstflag;
};


int __cdecl _ftime(struct timeb *tp);

#define ftime _ftime



#ifdef __cplusplus
}
#endif


#endif // _GNU4WINCE_TIMEB_H
