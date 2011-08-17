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
#include "CGBasePriv.h"
#include "CGRenderingStatePriv.h"



CGRenderingStateRef CGRenderingStateCreate()
{
	CGRenderingStateRef rendering;

	rendering = (CGRenderingStateRef)calloc(1, sizeof(CGRenderingState));
	if (!rendering)
		return NULL;

	rendering->refcount = 1;
	
	CGRenderingStateReset(rendering);

	return rendering;
}

CGRenderingStateRef	CGRenderingStateCreateCopy(CGRenderingStateRef rendering)
{
	return NULL;
}

void CGRenderingStateRelease(CGRenderingStateRef rendering)
{
	if (!rendering) { return; }
	rendering->refcount--;

	if (rendering->refcount == 0) { 
		free(rendering);
	}
}

void CGRenderingStateReset(CGRenderingStateRef rendering)
{
	rendering->baseCTM = CGAffineTransformIdentity;
	rendering->minInterpolQuality = 0;
	rendering->maxInterpolQuality = 0;	
	rendering->allowAcceleration = true;		
	rendering->allowAntialias = true;		
	rendering->allowDithering = true;		
	rendering->allowFontAntialias = true;	
	rendering->allowFontSmoothing = true;	
	rendering->allowFontSubPos = true;		
	rendering->allowFontSubQuant = true;		
}

void 
CGRenderingStateSetRenderingResolution(CGRenderingStateRef rendering, CGFloat hRes, CGFloat vRes)
{
	rendering->hRes = hRes;
	rendering->vRes = vRes;
}

