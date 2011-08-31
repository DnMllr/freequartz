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
#ifndef CGDIRECTDISPLAY_H_
#define CGDIRECTDISPLAY_H_

#include <CoreGraphics/CGContext.h>
#include <CoreGraphics/CGError.h>


typedef uint32_t CGDirectDisplayID;
typedef uint32_t CGOpenGLDisplayMask;
typedef double CGRefreshRate;

typedef struct CGDisplayMode *CGDisplayModeRef;

#define kCGNullDirectDisplay ((CGDirectDisplayID)0)
#define kCGDirectMainDisplay CGMainDisplayID()

/* Return the display ID of the current main display. */

CG_EXTERN CGDirectDisplayID CGMainDisplayID(void)
  CG_AVAILABLE_STARTING(__MAC_10_2, __IPHONE_NA);

enum {
   kCGCaptureNoOptions = 0,
   kCGCaptureNoFill = (1 << 0)
};
typedef uint32_t CGCaptureOptions;

enum {
   kCGDisplayBeginConfigurationFlag = (1 << 0),
   kCGDisplayMovedFlag              = (1 << 1),
   kCGDisplaySetMainFlag            = (1 << 2),
   kCGDisplaySetModeFlag            = (1 << 3),
   kCGDisplayAddFlag                = (1 << 4),
   kCGDisplayRemoveFlag             = (1 << 5),
   kCGDisplayEnabledFlag            = (1 << 8),
   kCGDisplayDisabledFlag           = (1 << 9),
   kCGDisplayMirrorFlag             = (1 << 10),
   kCGDisplayUnMirrorFlag           = (1 << 11),
   kCGDisplayDesktopShapeChangedFlag = (1 << 12)
};
typedef uint32_t CGDisplayChangeSummaryFlags;

enum {
   kCGConfigureForAppOnly = 0,
   kCGConfigureForSession = 1,
   kCGConfigurePermanently = 2
};

#define kCGDisplayBlendNormal (0.0)
#define kCGDisplayBlendSolidColor (1.0)

#define kCGMaxDisplayReservationInterval (15.0)
#define kCGDisplayFadeReservationInvalidToken (0)

#define kCGNumReservedWindowLevels      (16)

enum _CGScreenUpdateOperation {
   kCGScreenUpdateOperationRefresh = 0,
   kCGScreenUpdateOperationMove = (1 << 0),
   kCGScreenUpdateOperationReducedDirtyRectangleCount = (1 <<  31)
};
typedef uint32_t CGScreenUpdateOperation;

enum _CGCommonWindowLevelKey {
   kCGBaseWindowLevelKey = 0,
   kCGMinimumWindowLevelKey,
   kCGDesktopWindowLevelKey,
   kCGBackstopMenuLevelKey,
   kCGNormalWindowLevelKey,
   kCGFloatingWindowLevelKey,
   kCGTornOffMenuWindowLevelKey,
   kCGDockWindowLevelKey,
   kCGMainMenuWindowLevelKey,
   kCGStatusWindowLevelKey,
   kCGModalPanelWindowLevelKey,
   kCGPopUpMenuWindowLevelKey,
   kCGDraggingWindowLevelKey,
   kCGScreenSaverWindowLevelKey,
   kCGMaximumWindowLevelKey,
   kCGOverlayWindowLevelKey,
   kCGHelpWindowLevelKey,
   kCGUtilityWindowLevelKey,
   kCGDesktopIconWindowLevelKey,
   kCGCursorWindowLevelKey,
   kCGNumberOfWindowLevelKeys
};
typedef int32_t CGWindowLevelKey;

#define kCGSessionUserIDKey CFSTR("kCGSSessionUserIDKey")
#define kCGSessionUserNameKey CFSTR("kCGSSessionUserNameKey")
#define kCGSessionConsoleSetKey CFSTR("kCGSSessionConsoleSetKey")
#define kCGSessionOnConsoleKey CFSTR("kCGSSessionOnConsoleKey")
#define kCGSessionLoginDoneKey CFSTR("kCGSessionLoginDoneKey")


CG_EXTERN CGContextRef CGDisplayGetDrawingContext (CGDirectDisplayID display);


#endif	/* CGDIRECTDISPLAY_H_ */
