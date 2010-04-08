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

#ifndef _SYS_IOCTL_H
#define _SYS_IOCTL_H    1

#include <features.h>

#include "../posix4win.h"
#include <io.h>

__BEGIN_DECLS

int __cdecl ioctl(int fd, int cmd, ...);

__END_DECLS


#endif //_SYS_IOCTL_H