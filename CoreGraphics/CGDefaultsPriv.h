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
#ifndef CGDEFAULTSPRIV_H_
#define CGDEFAULTSPRIV_H_

CF_EXTERN_C_BEGIN


typedef CFTypeRef (*copyDefVal) (const char* propName);

// NEED TO FIX THAT AND STOP DECLARE CF_BUILDING_CF=1
//_declspec(dllimport) const CFStringRef kCFPreferencesAnyApplication;
//_declspec(dllimport) const CFStringRef kCFPreferencesCurrentUser;
//_declspec(dllimport) const CFStringRef kCFPreferencesAnyHost;
//_declspec(dllimport) const CFStringRef kCFPreferencesCurrentApplication;
//_declspec(dllimport) const CFStringRef kCFTypeDictionaryKeyCallBacks;

CG_EXTERN const CFStringRef Yes;
CG_EXTERN const CFStringRef No;
CG_EXTERN const CFStringRef True;
CG_EXTERN const CFStringRef False;
CG_EXTERN const CFStringRef CGAllowDebuggingDefaults;

CFStringRef CGCFStringCreate(const char* cStr);

void loadAllowDebuggingDefaults(void);

CFTypeRef copyDefaultValue(const char* propName);

Boolean CGDefaultsGetBoolean(const char* propName, Boolean* boolean);

Boolean CGCFDictionaryGetBoolean(CFDictionaryRef theDict, CFStringRef key, Boolean* boolean);


Boolean getBool(CFTypeRef preference, Boolean* boolean);

Boolean copyStringProperty(const char* cStr, copyDefVal fnCopyVal, CFStringRef* strDst);

Boolean CGDefaultsCopyString(const char* cStr, CFStringRef* strDst);

CF_EXTERN_C_END

#endif /* CGDEFAULTSPRIV_H_ */