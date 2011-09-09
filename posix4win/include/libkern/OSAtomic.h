#ifndef _OSATOMIC_H_
#define _OSATOMIC_H_

#include    <stddef.h>
#include    <sys/cdefs.h>
#include    <stdint.h>
#include    <stdbool.h>

#define OS_SPINLOCK_INIT 0


__BEGIN_DECLS

typedef int32_t OSSpinLock;

bool    OSSpinLockTry(volatile OSSpinLock *_lock);
void    OSSpinLockLock(volatile OSSpinLock *_lock);
void    OSSpinLockUnlock(volatile OSSpinLock *_lock);


__END_DECLS


#endif /* _OSATOMIC_H_ */
