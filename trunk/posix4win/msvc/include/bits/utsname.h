#ifndef _SYS_UTSNAME_H
# error "Never include <bits/utsname.h> directly; use <sys/utsname.h> instead."
#endif

/* Length of the entries in `struct utsname' is 65.  */
#define _UTSNAME_LENGTH 65

/* Linux provides as additional information in the `struct utsname'
   the name of the current domain.  Define _UTSNAME_DOMAIN_LENGTH
   to a value != 0 to activate this entry.  */
#define _UTSNAME_DOMAIN_LENGTH _UTSNAME_LENGTH