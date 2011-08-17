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
#ifndef CGLIBRARYPRIV_H_
#define CGLIBRARYPRIV_H_



CG_EXTERN void initialize_dylib_paths(void);

CG_EXTERN void* open_handle_to_dylib_path(const char* libname);

CG_EXTERN void* load_function(CFArrayRef paths, const char* fullLibName, const char* symName);

CG_EXTERN void* CGLibraryLoadFunction(const char* libName, const char* symName);



#endif /* CGLIBRARYPRIV_H_ */