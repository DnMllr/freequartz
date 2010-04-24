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

typedef struct CGImageDestination *CGImageDestinationRef;

const CFStringRef kCGImageDestinationLossyCompressionQuality
const CFStringRef kCGImageDestinationBackgroundColor



void CGImageDestinationAddImage (
  CGImageDestinationRef idst,
  CGImageRef image,
  CFDictionaryRef properties
);

void CGImageDestinationAddImageFromSource (
  CGImageDestinationRef idst,
  CGImageSourceRef isrc,
  size_t index,
  CFDictionaryRef properties
);

CFArrayRef CGImageDestinationCopyTypeIdentifiers (void);

CGImageDestinationRef CGImageDestinationCreateWithData (
  CFMutableDataRef data,
  CFStringRef type,
  size_t count,
  CFDictionaryRef options
);

CGImageDestinationRef CGImageDestinationCreateWithDataConsumer (
  CGDataConsumerRef consumer,
  CFStringRef type,
  size_t count,
  CFDictionaryRef options
);

CGImageDestinationRef CGImageDestinationCreateWithURL (
  CFURLRef url,
  CFStringRef type,
  size_t count,
  CFDictionaryRef options
);

bool CGImageDestinationFinalize (CGImageDestinationRef idst);

CFTypeID CGImageDestinationGetTypeID (void);

void CGImageDestinationSetProperties (
  CGImageDestinationRef idst,
  CFDictionaryRef properties
);




