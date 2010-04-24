/****************************************************************************
**
** Copyright (C) 2010 Smartmobili.
** All rights reserved.
** Contact: Smartmobili (contact@smartmobili.com)
**	
** This file is part of the ImageIO module of the freequartz Toolkit.
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

typedef struct CGImageSource *CGImageSourceRef;

enum CGImageSourceStatus {
   kCGImageStatusUnexpectedEOF = -5,
   kCGImageStatusInvalidData = -4,
   kCGImageStatusUnknownType = -3,
   kCGImageStatusReadingHeader = -2,
   kCGImageStatusIncomplete = -1,
   kCGImageStatusComplete = 0
};
typedef enum CGImageSourceStatus CGImageSourceStatus;


//CFStringRef kCGImageSourceTypeIdentifierHint;
//CFStringRef kCGImageSourceShouldAllowFloat;
//CFStringRef kCGImageSourceShouldCache;
//CFStringRef kCGImageSourceCreateThumbnailFromImageIfAbsent;
//CFStringRef kCGImageSourceCreateThumbnailFromImageAlways;
//CFStringRef kCGImageSourceThumbnailMaxPixelSize;
//CFStringRef kCGImageSourceCreateThumbnailWithTransform


CFDictionaryRef CGImageSourceCopyProperties (
   CGImageSourceRef isrc,
   CFDictionaryRef options
);


CFDictionaryRef CGImageSourceCopyPropertiesAtIndex (
   CGImageSourceRef isrc,
   size_t index,
   CFDictionaryRef options
);

CFArrayRef CGImageSourceCopyTypeIdentifiers (
   void
);

CGImageRef CGImageSourceCreateImageAtIndex (
   CGImageSourceRef isrc,
   size_t index,
   CFDictionaryRef options
);

CGImageSourceRef CGImageSourceCreateIncremental (
   CFDictionaryRef options
);

CGImageRef CGImageSourceCreateThumbnailAtIndex (
   CGImageSourceRef isrc,
   size_t index,
   CFDictionaryRef options
);

CGImageSourceRef CGImageSourceCreateWithData (
   CFDataRef data,
   CFDictionaryRef options
);

CGImageSourceRef CGImageSourceCreateWithDataProvider (
   CGDataProviderRef provider,
   CFDictionaryRef options
);

CGImageSourceRef CGImageSourceCreateWithURL (
   CFURLRef url,
   CFDictionaryRef options
);

size_t CGImageSourceGetCount (
   CGImageSourceRef isrc
);

CGImageSourceStatus CGImageSourceGetStatus (
   CGImageSourceRef isrc
);

CGImageSourceStatus CGImageSourceGetStatusAtIndex (
   CGImageSourceRef isrc,
   size_t index
);

CFStringRef CGImageSourceGetType (
   CGImageSourceRef isrc
);

CFTypeID CGImageSourceGetTypeID (
   void
);

void CGImageSourceUpdateData (
   CGImageSourceRef isrc,
   CFDataRef data,
   bool final
);

void CGImageSourceUpdateDataProvider (
   CGImageSourceRef isrc,
   CGDataProviderRef provider,
   bool final
);

