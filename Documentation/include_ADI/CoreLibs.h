#if !defined(__CORELIBS__)
#define __CORELIBS__ 1


#include <stdbool.h>
#include <stdint.h>

#define TARGET_OS_WIN32 1
#define __i386__ 1
#define __LITTLE_ENDIAN__ 1

    typedef unsigned char           Boolean;
    typedef unsigned char           UInt8;
    typedef signed char             SInt8;
    typedef unsigned short          UInt16;
    typedef signed short            SInt16;
    typedef unsigned int            UInt32;
    typedef signed int              SInt32;
    typedef uint64_t		            UInt64;
    typedef int64_t		              SInt64;
    typedef SInt32                  OSStatus;
    typedef float                   Float32;
    typedef double                  Float64;
    typedef unsigned short          UniChar;
    typedef unsigned long           UniCharCount;
    typedef unsigned char *         StringPtr;
    typedef const unsigned char *   ConstStringPtr;
    typedef unsigned char           Str255[256];
    typedef const unsigned char *   ConstStr255Param;
    typedef SInt16                  OSErr;
    typedef SInt16                  RegionCode;
    typedef SInt16                  LangCode;
    typedef SInt16                  ScriptCode;
    typedef UInt32                  FourCharCode;
    typedef FourCharCode            OSType;
    typedef UInt32                  UTF32Char;
    typedef UInt16                  UTF16Char;
    typedef UInt8                   UTF8Char;
    
    
  
#include "CoreFoundation_SIMPLE.h"
#include "CoreGraphics_SIMPLE.h"

#endif /* __CORELIBS__ */