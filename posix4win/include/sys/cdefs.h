#ifndef _SYS_CDEFS_H
#define _SYS_CDEFS_H    1

/* We are almost always included from features.h. */
#ifndef _FEATURES_H
# include <features.h>
#endif

# define __inline               /* No inline functions.  */

# define __THROW
# define __NTH(fct)     fct

# define __const        const
# define __signed       signed
//# define __volatile     volatile

/* These two macros are not used in glibc anymore.  They are kept here
   only because some other projects expect the macros to be defined.  */
#define __P(args)       args
#define __PMT(args)     args

/* For these things, GCC behaves the ANSI way normally,
   and the non-ANSI way under -traditional.  */

#define __CONCAT(x,y)   x ## y
#define __STRING(x)     #x

/* This is not a typedef so `const __ptr_t' does the right thing.  */
#define __ptr_t void *
#define __long_double_t  long double


/* C++ needs to know that types and declarations are C, not C++.  */
#ifdef  __cplusplus
# define __BEGIN_DECLS  extern "C" {
# define __END_DECLS    }
#else
# define __BEGIN_DECLS
# define __END_DECLS
#endif

#endif   /* sys/cdefs.h */
