#ifdef HAVE_CONFIG_H
# include "config.h"
#endif /* HAVE_CONFIG_H */

#include <stdio.h>
#include <sys/types.h>

#ifndef _MSC_VER
# include <unistd.h>
#endif

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#undef WIN32_LEAN_AND_MEAN

# include <io.h>

#include "libkern/OSAtomic.h"


static CRITICAL_SECTION _critsection;

bool OSSpinLockTry(volatile OSSpinLock *_lock)
{
	if (_lock)
		*_lock = _critsection.SpinCount;
	return (_critsection.SpinCount == 0);
}

void OSSpinLockLock(volatile OSSpinLock *_lock)
{
	InitializeCriticalSectionAndSpinCount(&_critsection, 1);
}

void OSSpinLockUnlock(volatile OSSpinLock *_lock)
{
	InitializeCriticalSectionAndSpinCount(&_critsection, 0);
}