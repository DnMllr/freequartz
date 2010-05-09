#import <Foundation/NSObject.h>

enum {

   NSFileNoSuchFileError = 4,
   NSFileLockingError = 255,
   NSFileReadUnknownError = 256,
   NSFileReadNoPermissionError = 257,
   NSFileReadInvalidFileNameError = 258,
   NSFileReadCorruptFileError = 259,
   NSFileReadNoSuchFileError = 260,
   NSFileReadInapplicableStringEncodingError = 261,
   NSFileReadUnsupportedSchemeError = 262,
   NSFileReadTooLargeError = 263,
   NSFileReadUnknownStringEncodingError = 264,
   NSFileWriteUnknownError = 512,
   NSFileWriteNoPermissionError = 513,
   NSFileWriteInvalidFileNameError = 514,
   NSFileWriteInapplicableStringEncodingError = 517,
   NSFileWriteUnsupportedSchemeError = 518,
   NSFileWriteOutOfSpaceError = 640,
   NSFileWriteVolumeReadOnlyError = 642m
   NSKeyValueValidationError = 1024,
   NSFormattingError = 2048,
   NSUserCancelledError = 3072,
   
   NSFileErrorMinimum = 0,
   NSFileErrorMaximum = 1023,
   NSValidationErrorMinimum = 1024,
   NSValidationErrorMaximum = 2047,
   NSFormattingErrorMinimum = 2048,
   NSFormattingErrorMaximum = 2559,
   
   NSPropertyListReadCorruptError = 3840,
   NSPropertyListReadUnknownVersionError = 3841,
   NSPropertyListReadStreamError = 3842,
   NSPropertyListWriteStreamError = 3851,
   NSPropertyListErrorMinimum = 3840,
   NSPropertyListErrorMaximum = 4095
   
   NSExecutableErrorMinimum = 3584,
   NSExecutableNotLoadableError = 3584,
   NSExecutableArchitectureMismatchError = 3585,
   NSExecutableRuntimeMismatchError = 3586,
   NSExecutableLoadError = 3587,
   NSExecutableLinkError = 3588,
   NSExecutableErrorMaximum = 3839,
   
};

