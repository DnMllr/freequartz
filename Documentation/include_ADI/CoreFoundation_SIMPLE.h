#if !defined(__COREFOUNDATION_SIMPLE__)
#define __COREFOUNDATION_SIMPLE__ 1

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
// CFBase
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

#define AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER 

#if !defined(CF_EXTERN_C_BEGIN)
#if defined(__cplusplus)
#define CF_EXTERN_C_BEGIN extern "C" {
#define CF_EXTERN_C_END   }
#else
#define CF_EXTERN_C_BEGIN
#define CF_EXTERN_C_END
#endif
#endif

#define CF_EXPORT extern
#define CF_INLINE static __inline__

CF_EXPORT double kCFCoreFoundationVersionNumber;

typedef unsigned long CFTypeID;
typedef unsigned long CFOptionFlags;
typedef unsigned long CFHashCode;
typedef signed long CFIndex;


typedef const void * CFTypeRef;
typedef const struct __CFString * CFStringRef;
typedef struct __CFString * CFMutableStringRef;

typedef CFTypeRef CFPropertyListRef;

enum {
    kCFCompareLessThan = -1,
    kCFCompareEqualTo = 0,
    kCFCompareGreaterThan = 1
};
typedef CFIndex CFComparisonResult;

typedef CFComparisonResult (*CFComparatorFunction)(const void *val1, const void *val2, void *context);

enum {
    kCFNotFound = -1
};

typedef struct {
    CFIndex location;
    CFIndex length;
} CFRange;

#define CFRangeMake(LOC, LEN) __CFRangeMake(LOC, LEN)


/* Private; do not use */
CF_EXPORT
CFRange __CFRangeMake(CFIndex loc, CFIndex len);




typedef const struct __CFAllocator * CFAllocatorRef;

CF_EXPORT
const CFAllocatorRef kCFAllocatorDefault;

CF_EXPORT
const CFAllocatorRef kCFAllocatorSystemDefault;

CF_EXPORT
const CFAllocatorRef kCFAllocatorMalloc;

CF_EXPORT
const CFAllocatorRef kCFAllocatorMallocZone;

CF_EXPORT
const CFAllocatorRef kCFAllocatorNull;

CF_EXPORT
const CFAllocatorRef kCFAllocatorUseContext;

typedef const void *	(*CFAllocatorRetainCallBack)(const void *info);
typedef void		(*CFAllocatorReleaseCallBack)(const void *info);
typedef CFStringRef	(*CFAllocatorCopyDescriptionCallBack)(const void *info);
typedef void *		(*CFAllocatorAllocateCallBack)(CFIndex allocSize, CFOptionFlags hint, void *info);
typedef void *		(*CFAllocatorReallocateCallBack)(void *ptr, CFIndex newsize, CFOptionFlags hint, void *info);
typedef void		(*CFAllocatorDeallocateCallBack)(void *ptr, void *info);
typedef CFIndex		(*CFAllocatorPreferredSizeCallBack)(CFIndex size, CFOptionFlags hint, void *info);
typedef struct {
    CFIndex				version;
    void *				info;
    CFAllocatorRetainCallBack		retain;
    CFAllocatorReleaseCallBack		release;        
    CFAllocatorCopyDescriptionCallBack	copyDescription;
    CFAllocatorAllocateCallBack		allocate;
    CFAllocatorReallocateCallBack	reallocate;
    CFAllocatorDeallocateCallBack	deallocate;
    CFAllocatorPreferredSizeCallBack	preferredSize;
} CFAllocatorContext;

CF_EXPORT
CFTypeID	CFAllocatorGetTypeID(void);

CF_EXPORT
void CFAllocatorSetDefault(CFAllocatorRef allocator);

CF_EXPORT
CFAllocatorRef CFAllocatorGetDefault(void);

CF_EXPORT
CFAllocatorRef CFAllocatorCreate(CFAllocatorRef allocator, CFAllocatorContext *context);

CF_EXPORT
void *CFAllocatorAllocate(CFAllocatorRef allocator, CFIndex size, CFOptionFlags hint);

CF_EXPORT
void *CFAllocatorReallocate(CFAllocatorRef allocator, void *ptr, CFIndex newsize, CFOptionFlags hint);

CF_EXPORT
void CFAllocatorDeallocate(CFAllocatorRef allocator, void *ptr);

CF_EXPORT
CFIndex CFAllocatorGetPreferredSizeForSize(CFAllocatorRef allocator, CFIndex size, CFOptionFlags hint);

CF_EXPORT
void CFAllocatorGetContext(CFAllocatorRef allocator, CFAllocatorContext *context);

CF_EXPORT
CFTypeID CFGetTypeID(CFTypeRef cf);

CF_EXPORT
CFStringRef CFCopyTypeIDDescription(CFTypeID type_id);

CF_EXPORT
CFTypeRef CFRetain(CFTypeRef cf);

CF_EXPORT
void CFRelease(CFTypeRef cf);

CF_EXPORT
CFIndex CFGetRetainCount(CFTypeRef cf);

CF_EXPORT
CFTypeRef CFMakeCollectable(CFTypeRef cf) AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER;

CF_EXPORT
Boolean CFEqual(CFTypeRef cf1, CFTypeRef cf2);

CF_EXPORT
CFHashCode CFHash(CFTypeRef cf);

CF_EXPORT
CFStringRef CFCopyDescription(CFTypeRef cf);

CF_EXPORT
CFAllocatorRef CFGetAllocator(CFTypeRef cf);

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//CFRuntime
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
CF_EXPORT 
void _CFRuntimeInitStaticInstance(void *memory, CFTypeID typeID);


//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//CFData
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

typedef const struct __CFData * CFDataRef;
typedef struct __CFData * CFMutableDataRef;

CF_EXPORT
CFTypeID CFDataGetTypeID(void);
CF_EXPORT
CFDataRef CFDataCreate(CFAllocatorRef allocator, const UInt8 *bytes, CFIndex length);
CF_EXPORT
CFDataRef CFDataCreateWithBytesNoCopy(CFAllocatorRef allocator, const UInt8 *bytes, CFIndex length, CFAllocatorRef bytesDeallocator);
CF_EXPORT
CFDataRef CFDataCreateCopy(CFAllocatorRef allocator, CFDataRef theData);
CF_EXPORT
CFMutableDataRef CFDataCreateMutable(CFAllocatorRef allocator, CFIndex capacity);
CF_EXPORT
CFMutableDataRef CFDataCreateMutableCopy(CFAllocatorRef allocator, CFIndex capacity, CFDataRef theData);
CF_EXPORT
CFIndex CFDataGetLength(CFDataRef theData);
CF_EXPORT
const UInt8 *CFDataGetBytePtr(CFDataRef theData);
CF_EXPORT
UInt8 *CFDataGetMutableBytePtr(CFMutableDataRef theData);
CF_EXPORT
void CFDataGetBytes(CFDataRef theData, CFRange range, UInt8 *buffer); 
CF_EXPORT
void CFDataSetLength(CFMutableDataRef theData, CFIndex length);
CF_EXPORT
void CFDataIncreaseLength(CFMutableDataRef theData, CFIndex extraLength);
CF_EXPORT
void CFDataAppendBytes(CFMutableDataRef theData, const UInt8 *bytes, CFIndex length);
CF_EXPORT
void CFDataReplaceBytes(CFMutableDataRef theData, CFRange range, const UInt8 *newBytes, CFIndex newLength);
CF_EXPORT
void CFDataDeleteBytes(CFMutableDataRef theData, CFRange range);

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
// CFArray
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
typedef const void *	(*CFArrayRetainCallBack)(CFAllocatorRef allocator, const void *value);
typedef void		(*CFArrayReleaseCallBack)(CFAllocatorRef allocator, const void *value);
typedef CFStringRef	(*CFArrayCopyDescriptionCallBack)(const void *value);
typedef Boolean		(*CFArrayEqualCallBack)(const void *value1, const void *value2);
typedef struct {
    CFIndex				version;
    CFArrayRetainCallBack		retain;
    CFArrayReleaseCallBack		release;
    CFArrayCopyDescriptionCallBack	copyDescription;
    CFArrayEqualCallBack		equal;
} CFArrayCallBacks;

CF_EXPORT
const CFArrayCallBacks kCFTypeArrayCallBacks;

typedef void (*CFArrayApplierFunction)(const void *value, void *context);

typedef const struct __CFArray * CFArrayRef;

typedef struct __CFArray * CFMutableArrayRef;

CF_EXPORT
CFTypeID CFArrayGetTypeID(void);

CF_EXPORT
CFArrayRef CFArrayCreate(CFAllocatorRef allocator, const void **values, CFIndex numValues, const CFArrayCallBacks *callBacks);

CF_EXPORT
CFArrayRef CFArrayCreateCopy(CFAllocatorRef allocator, CFArrayRef theArray);

CF_EXPORT
CFMutableArrayRef CFArrayCreateMutable(CFAllocatorRef allocator, CFIndex capacity, const CFArrayCallBacks *callBacks);

CF_EXPORT
CFMutableArrayRef CFArrayCreateMutableCopy(CFAllocatorRef allocator, CFIndex capacity, CFArrayRef theArray);

CF_EXPORT
CFIndex CFArrayGetCount(CFArrayRef theArray);

CF_EXPORT
CFIndex CFArrayGetCountOfValue(CFArrayRef theArray, CFRange range, const void *value);

CF_EXPORT
Boolean CFArrayContainsValue(CFArrayRef theArray, CFRange range, const void *value);

CF_EXPORT
const void *CFArrayGetValueAtIndex(CFArrayRef theArray, CFIndex idx);

CF_EXPORT
void CFArrayGetValues(CFArrayRef theArray, CFRange range, const void **values);

CF_EXPORT
void CFArrayApplyFunction(CFArrayRef theArray, CFRange range, CFArrayApplierFunction applier, void *context);

CF_EXPORT
CFIndex CFArrayGetFirstIndexOfValue(CFArrayRef theArray, CFRange range, const void *value);

CF_EXPORT
CFIndex CFArrayGetLastIndexOfValue(CFArrayRef theArray, CFRange range, const void *value);

CF_EXPORT
CFIndex CFArrayBSearchValues(CFArrayRef theArray, CFRange range, const void *value, CFComparatorFunction comparator, void *context);

CF_EXPORT
void CFArrayAppendValue(CFMutableArrayRef theArray, const void *value);

CF_EXPORT
void CFArrayInsertValueAtIndex(CFMutableArrayRef theArray, CFIndex idx, const void *value);

CF_EXPORT
void CFArraySetValueAtIndex(CFMutableArrayRef theArray, CFIndex idx, const void *value);

CF_EXPORT
void CFArrayRemoveValueAtIndex(CFMutableArrayRef theArray, CFIndex idx);

CF_EXPORT
void CFArrayRemoveAllValues(CFMutableArrayRef theArray);

CF_EXPORT
void CFArrayReplaceValues(CFMutableArrayRef theArray, CFRange range, const void **newValues, CFIndex newCount);

CF_EXPORT
void CFArrayExchangeValuesAtIndices(CFMutableArrayRef theArray, CFIndex idx1, CFIndex idx2);

CF_EXPORT
void CFArraySortValues(CFMutableArrayRef theArray, CFRange range, CFComparatorFunction comparator, void *context);

CF_EXPORT
void CFArrayAppendArray(CFMutableArrayRef theArray, CFArrayRef otherArray, CFRange otherRange);

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
// CFBag
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

typedef const void *	(*CFBagRetainCallBack)(CFAllocatorRef allocator, const void *value);
typedef void		(*CFBagReleaseCallBack)(CFAllocatorRef allocator, const void *value);
typedef CFStringRef	(*CFBagCopyDescriptionCallBack)(const void *value);
typedef Boolean		(*CFBagEqualCallBack)(const void *value1, const void *value2);
typedef CFHashCode	(*CFBagHashCallBack)(const void *value);
typedef struct {
    CFIndex				version;
    CFBagRetainCallBack			retain;
    CFBagReleaseCallBack		release;
    CFBagCopyDescriptionCallBack	copyDescription;
    CFBagEqualCallBack			equal;
    CFBagHashCallBack			hash;
} CFBagCallBacks;

CF_EXPORT
const CFBagCallBacks kCFTypeBagCallBacks;
CF_EXPORT
const CFBagCallBacks kCFCopyStringBagCallBacks;

typedef void (*CFBagApplierFunction)(const void *value, void *context);

typedef const struct __CFBag * CFBagRef;
typedef struct __CFBag * CFMutableBagRef;

CF_EXPORT
CFTypeID CFBagGetTypeID(void);

CF_EXPORT
CFBagRef CFBagCreate(CFAllocatorRef allocator, const void **values, CFIndex numValues, const CFBagCallBacks *callBacks);

CF_EXPORT
CFBagRef CFBagCreateCopy(CFAllocatorRef allocator, CFBagRef theBag);

CF_EXPORT
CFMutableBagRef CFBagCreateMutable(CFAllocatorRef allocator, CFIndex capacity, const CFBagCallBacks *callBacks);

CF_EXPORT
CFMutableBagRef CFBagCreateMutableCopy(CFAllocatorRef allocator, CFIndex capacity, CFBagRef theBag);

CF_EXPORT
CFIndex CFBagGetCount(CFBagRef theBag);

CF_EXPORT
CFIndex CFBagGetCountOfValue(CFBagRef theBag, const void *value);

CF_EXPORT
Boolean CFBagContainsValue(CFBagRef theBag, const void *value);

CF_EXPORT
const void *CFBagGetValue(CFBagRef theBag, const void *value);

CF_EXPORT
Boolean CFBagGetValueIfPresent(CFBagRef theBag, const void *candidate, const void **value);

CF_EXPORT
void CFBagGetValues(CFBagRef theBag, const void **values);

CF_EXPORT
void CFBagApplyFunction(CFBagRef theBag, CFBagApplierFunction applier, void *context);

CF_EXPORT
void CFBagAddValue(CFMutableBagRef theBag, const void *value);

CF_EXPORT
void CFBagReplaceValue(CFMutableBagRef theBag, const void *value);

CF_EXPORT
void CFBagSetValue(CFMutableBagRef theBag, const void *value);

CF_EXPORT
void CFBagRemoveValue(CFMutableBagRef theBag, const void *value);

CF_EXPORT
void CFBagRemoveAllValues(CFMutableBagRef theBag);

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//CFDictionnary
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
typedef const void *	(*CFDictionaryRetainCallBack)(CFAllocatorRef allocator, const void *value);
typedef void		(*CFDictionaryReleaseCallBack)(CFAllocatorRef allocator, const void *value);
typedef CFStringRef	(*CFDictionaryCopyDescriptionCallBack)(const void *value);
typedef Boolean		(*CFDictionaryEqualCallBack)(const void *value1, const void *value2);
typedef CFHashCode	(*CFDictionaryHashCallBack)(const void *value);
typedef struct {
    CFIndex				version;
    CFDictionaryRetainCallBack		retain;
    CFDictionaryReleaseCallBack		release;
    CFDictionaryCopyDescriptionCallBack	copyDescription;
    CFDictionaryEqualCallBack		equal;
    CFDictionaryHashCallBack		hash;
} CFDictionaryKeyCallBacks;

CF_EXPORT
const CFDictionaryKeyCallBacks kCFTypeDictionaryKeyCallBacks;
CF_EXPORT
const CFDictionaryKeyCallBacks kCFCopyStringDictionaryKeyCallBacks;

typedef struct {
    CFIndex				version;
    CFDictionaryRetainCallBack		retain;
    CFDictionaryReleaseCallBack		release;
    CFDictionaryCopyDescriptionCallBack	copyDescription;
    CFDictionaryEqualCallBack		equal;
} CFDictionaryValueCallBacks;


CF_EXPORT
const CFDictionaryValueCallBacks kCFTypeDictionaryValueCallBacks;

typedef void (*CFDictionaryApplierFunction)(const void *key, const void *value, void *context);

typedef const struct __CFDictionary * CFDictionaryRef;
typedef struct __CFDictionary * CFMutableDictionaryRef;


CF_EXPORT
CFTypeID CFDictionaryGetTypeID(void);
CF_EXPORT
CFDictionaryRef CFDictionaryCreate(CFAllocatorRef allocator, const void **keys, const void **values, CFIndex numValues, const CFDictionaryKeyCallBacks *keyCallBacks, const CFDictionaryValueCallBacks *valueCallBacks);
CF_EXPORT
CFDictionaryRef CFDictionaryCreateCopy(CFAllocatorRef allocator, CFDictionaryRef theDict);
CF_EXPORT
CFMutableDictionaryRef CFDictionaryCreateMutable(CFAllocatorRef allocator, CFIndex capacity, const CFDictionaryKeyCallBacks *keyCallBacks, const CFDictionaryValueCallBacks *valueCallBacks);
CF_EXPORT
CFMutableDictionaryRef CFDictionaryCreateMutableCopy(CFAllocatorRef allocator, CFIndex capacity, CFDictionaryRef theDict);
CF_EXPORT
CFIndex CFDictionaryGetCount(CFDictionaryRef theDict);
CF_EXPORT
CFIndex CFDictionaryGetCountOfKey(CFDictionaryRef theDict, const void *key);
CF_EXPORT
CFIndex CFDictionaryGetCountOfValue(CFDictionaryRef theDict, const void *value);
CF_EXPORT
Boolean CFDictionaryContainsKey(CFDictionaryRef theDict, const void *key);
CF_EXPORT
Boolean CFDictionaryContainsValue(CFDictionaryRef theDict, const void *value);
CF_EXPORT
const void *CFDictionaryGetValue(CFDictionaryRef theDict, const void *key);
CF_EXPORT
Boolean CFDictionaryGetValueIfPresent(CFDictionaryRef theDict, const void *key, const void **value);
CF_EXPORT
void CFDictionaryGetKeysAndValues(CFDictionaryRef theDict, const void **keys, const void **values);
CF_EXPORT
void CFDictionaryApplyFunction(CFDictionaryRef theDict, CFDictionaryApplierFunction applier, void *context);
CF_EXPORT
void CFDictionaryAddValue(CFMutableDictionaryRef theDict, const void *key, const void *value);
CF_EXPORT
void CFDictionarySetValue(CFMutableDictionaryRef theDict, const void *key, const void *value);
CF_EXPORT
void CFDictionaryReplaceValue(CFMutableDictionaryRef theDict, const void *key, const void *value);
CF_EXPORT
void CFDictionaryRemoveValue(CFMutableDictionaryRef theDict, const void *key);
CF_EXPORT
void CFDictionaryRemoveAllValues(CFMutableDictionaryRef theDict);




#endif /* __COREFOUNDATION_SIMPLE__ */



