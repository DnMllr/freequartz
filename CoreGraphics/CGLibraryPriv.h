/****************************************************************************
**
** Copyright (C) 2010 Smartmobili.
** All rights reserved.
** Contact: Smartmobili (contact@smartmobili.com)
**	
** This file is part of the CoreGraphics module of the freequartz Toolkit.
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
#ifndef CGLIBRARYPRIV_H_
#define CGLIBRARYPRIV_H_




CG_EXTERN void initialize_dylib_paths(void);

CG_EXTERN void* open_handle_to_dylib_path(const char* libname);

CG_EXTERN void* load_function(CFArrayRef paths, const char* fullLibName, const char* symName);

CG_EXTERN void* CGLibraryLoadFunction(const char* libName, const char* symName);




#endif /* CGLIBRARYPRIV_H_ */