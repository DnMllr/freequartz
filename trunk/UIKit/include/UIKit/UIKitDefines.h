#ifndef __UIKitDefines_INCLUDE
#define __UIKitDefines_INCLUDE
#import <GNUstepBase/GSVersionMacros.h>

#ifdef GNUSTEP_WITH_DLL 

#if BUILD_libgnustep_uikit_DLL
#
# if defined(__MINGW32__)
  /* On Mingw, the compiler will export all symbols automatically, so
   * __declspec(dllexport) is not needed.
   */
#  define UIKIT_EXTERN_CLASS 
#  define UIKIT_EXTERN  extern
#  define UIKIT_EXPORT  extern
#  define UIKIT_DECLARE 
# else
#  define UIKIT_EXTERN_CLASS 
#  define UIKIT_EXTERN  __declspec(dllexport)  
#  define UIKIT_EXPORT  __declspec(dllexport)
#  define UIKIT_DECLARE __declspec(dllexport)
# endif
#else
#  define UIKIT_EXTERN_CLASS 
#  define UIKIT_EXTERN  extern __declspec(dllimport)
#  define UIKIT_EXPORT  extern __declspec(dllimport)
#  define UIKIT_DECLARE __declspec(dllimport)
#endif

#else /* GNUSTEP_WITH[OUT]_DLL */

#  define UIKIT_EXTERN_CLASS  extern
#  define UIKIT_EXTERN  extern
#  define UIKIT_EXPORT extern
#  define UIKIT_DECLARE

#endif

#endif /* __UIKitDefines_INCLUDE */
