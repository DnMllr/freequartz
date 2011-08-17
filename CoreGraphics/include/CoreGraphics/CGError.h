/* Copyright 2010 Smartmobili SARL
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef __CGERROR_H__
#define __CGERROR_H__ 1

#include <CoreGraphics/CGBase.h>


enum _CGError {
    
	kCGErrorSuccess = 0,
    kCGErrorFailure = 1000,
    kCGErrorIllegalArgument = 1001,
    kCGErrorInvalidConnection = 1002,
    kCGErrorInvalidContext = 1003,
    kCGErrorCannotComplete = 1004,
    kCGErrorNameTooLong = 1005,
    kCGErrorNotImplemented = 1006,
    kCGErrorRangeCheck = 1007,
    kCGErrorTypeCheck = 1008,
    kCGErrorNoCurrentPoint = 1009,
    kCGErrorInvalidOperation = 1010,
    kCGErrorNoneAvailable = 1011,
	kCGErrorApplicationRequiresNewerSystem = 1015,
	kCGErrorApplicationNotPermittedToExecute = 1016,
	kCGErrorApplicationIncorrectExecutableFormatFound = 1023,
	kCGErrorApplicationIsLaunching = 1024,
	kCGErrorApplicationAlreadyRunning = 1025,
	kCGErrorApplicationCanOnlyBeRunInOneSessionAtATime = 1026,
	kCGErrorClassicApplicationsMustBeLaunchedByClassic = 1027,
	kCGErrorForkFailed = 1028,
	kCGErrorRetryRegistration = 1029,

    kCGErrorLast = kCGErrorRetryRegistration
};
typedef enum _CGError CGError;

#endif /* __CGERROR_H__ */
