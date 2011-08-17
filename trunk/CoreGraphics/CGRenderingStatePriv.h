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
#ifndef CGRENDERINGSTATE_H_
#define CGRENDERINGSTATE_H_

#include <CoreGraphics/CGAffineTransform.h>
#include "CGMacros.h"
#include "CGStylePriv.h"
#include "CGSoftMaskPriv.h"



CF_EXTERN_C_BEGIN

////////////////////////////////////////////
//CGGStateRendering - sizeof = 0x34
typedef struct CGRenderingState {
	signed long refcount;		//0x00

	CGFloat hRes;				//0x04
	CGFloat vRes;				//0x04
	CGAffineTransform baseCTM;	//0x0C
	int	 minInterpolQuality;	//0x24
	int	 maxInterpolQuality;	//0x28 
	Boolean allowAcceleration;	//0x2C
	Boolean allowAntialias;		//0x2D
	Boolean allowDithering;		//0x2E
	Boolean allowFontAntialias;	//0x2F
	Boolean allowFontSmoothing;	//0x30
	Boolean allowFontSubPos;	//0x31
	Boolean allowFontSubQuant;	//0x32

} CGRenderingState, *CGRenderingStateRef;


CG_EXTERN CGRenderingStateRef		CGRenderingStateCreate();
CG_EXTERN CGRenderingStateRef		CGRenderingStateCreateCopy(CGRenderingStateRef rendering);
CG_EXTERN void						CGRenderingStateReset(CGRenderingStateRef rendering);
CG_EXTERN void						CGRenderingStateRelease(CGRenderingStateRef rendering);
CG_EXTERN void						CGRenderingStateSetRenderingResolution(CGRenderingStateRef rendering, CGFloat hRes, CGFloat vRes);

CF_EXTERN_C_END

#endif /* CGRENDERINGSTATE_H_ */


