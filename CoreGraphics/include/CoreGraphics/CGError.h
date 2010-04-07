/****************************************************************************
**
** Copyright (C) 2010 Smartmobili.
** All rights reserved.
** Contact: Smartmobili (contact@smartmobili.com)
**	
** This file is part of the CoreGraphics module of the Coconuts Toolkit.
**
**
** GNU Lesser General Public License Usage	
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements	
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
****************************************************************************/
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
