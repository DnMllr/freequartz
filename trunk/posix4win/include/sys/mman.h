/*  gnu4wince: Windows CE C Runtime Library "compatibility" library.
 *
 *  Copyright (C) 2007-2008 smartmobili.com.  All rights reserved.
 *  Author : Vincent Richomme - http://www.smartmobili.com
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

#ifndef _SYS_MMAN_H
#define _SYS_MMAN_H     1

//#include <features.h>

//#include "../posix4win.h"


/*
 * Inheritance for minherit()
 */
#define INHERIT_SHARE		0
#define INHERIT_COPY		1
#define INHERIT_NONE		2

/*
 * Protections are chosen from these bits, or-ed together
 */
#define	PROT_NONE			0x00	/* no permissions */
#define	PROT_READ			0x01	/* pages can be read */
#define	PROT_WRITE			0x02	/* pages can be written */
#define	PROT_EXEC			0x04	/* pages can be executed */

/*
 * Flags contain sharing type and options.
 * Sharing types; choose one.
 */
#define	MAP_SHARED			0x0001		/* share changes */
#define	MAP_PRIVATE			0x0002		/* changes are private */
#define	MAP_COPY			MAP_PRIVATE	/* Obsolete */

/*
 * Other flags
 */
#define	MAP_FIXED			0x0010	/* map addr must be exactly as requested */
#define	MAP_RENAME			0x0020	/* Sun: rename private pages to file */
#define	MAP_NORESERVE		0x0040	/* Sun: don't reserve needed swap area */
#define	MAP_INHERIT			0x0080	/* region is retained after exec */
#define	MAP_NOEXTEND		0x0100	/* for MAP_FILE, don't change file size */
#define	MAP_HASSEMAPHORE	0x0200	/* region may contain semaphores */
#define	MAP_STACK			0x0400	/* region grows down, like a stack */
#define	MAP_NOSYNC			0x0800 /* page to but do not sync underlying file */

/*
 * Extended flags
 */
#define	MAP_NOCORE			0x00020000 /* dont include these pages in a coredump */

#ifdef _P1003_1B_VISIBLE
/*
 * Process memory locking
 */
#define MCL_CURRENT			0x0001	/* Lock only current memory */
#define MCL_FUTURE			0x0002	/* Lock all future memory as well */

#endif /* _P1003_1B_VISIBLE */

/*
 * Error return from mmap()
 */
#define MAP_FAILED	((void *)-1)

/*
 * msync() flags
 */
#define	MS_SYNC				0x0000	/* msync synchronously */
#define MS_ASYNC			0x0001	/* return immediately */
#define MS_INVALIDATE		0x0002	/* invalidate all cached data */


/*
 * Mapping type
 */
#define	MAP_FILE			0x0000	/* map from file (default) */
#define	MAP_ANON			0x1000	/* allocated from memory, swap space */

/*
 * Advice to madvise
 */
#define	MADV_NORMAL			0	/* no further special treatment */
#define	MADV_RANDOM			1	/* expect random page references */
#define	MADV_SEQUENTIAL		2	/* expect sequential page references */
#define	MADV_WILLNEED		3	/* will need these pages */
#define	MADV_DONTNEED		4	/* dont need these pages */
#define	MADV_FREE			5	/* dont need these pages, and junk contents */
#define	MADV_NOSYNC			6	/* try to avoid flushes to physical media */
#define	MADV_AUTOSYNC		7	/* revert to default flushing strategy */
#define	MADV_NOCORE			8	/* do not include these pages in a core file */
#define	MADV_CORE			9	/* revert to including pages in a core file */

/*
 * Return bits from mincore
 */
#define	MINCORE_INCORE	 	 0x1 /* Page is incore */
#define	MINCORE_REFERENCED	 0x2 /* Page has been referenced by us */
#define	MINCORE_MODIFIED	 0x4 /* Page has been modified by us */
#define	MINCORE_REFERENCED_OTHER 0x8 /* Page has been referenced */
#define	MINCORE_MODIFIED_OTHER	0x10 /* Page has been modified */

//__BEGIN_DECLS
extern "C" {

int    __cdecl mlock(const void *, size_t);

int   __cdecl  mlockall(int);


void * __cdecl mmap(void *, size_t, int, int, int, off_t);


int    __cdecl mprotect(void *, size_t, int);


int    __cdecl msync(void *, size_t, int);


int    __cdecl munlock(const void *, size_t);

int    __cdecl munlockall(void);

int   __cdecl  munmap(void *, size_t);

}
//__END_DECLS


#endif //_SYS_MMAN_H