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
#ifndef CGDEFAULTSPRIV_H_
#define CGDEFAULTSPRIV_H_

CF_EXTERN_C_BEGIN


typedef CFTypeRef (*copyDefVal) (const char* propName);

CG_EXTERN const CFStringRef Yes;
CG_EXTERN const CFStringRef No;
CG_EXTERN const CFStringRef True;
CG_EXTERN const CFStringRef False;
CG_EXTERN const CFStringRef CGAllowDebuggingDefaults;

CFStringRef CGCFStringCreate(const char* cStr);



void loadAllowDebuggingDefaults(void);

CFTypeRef copyDefaultValue(const char* propName);

Boolean CGDefaultsGetBoolean(const char* propName, Boolean* boolean);

Boolean getBool(CFTypeRef preference, Boolean* boolean);

Boolean copyStringProperty(const char* cStr, copyDefVal fnCopyVal, CFStringRef* strDst);

Boolean CGDefaultsCopyString(const char* cStr, CFStringRef* strDst);

CF_EXTERN_C_END

#endif /* CGDEFAULTSPRIV_H_ */