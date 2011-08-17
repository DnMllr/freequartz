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
#include <CoreGraphics/CGContext.h>

#include "CGBasePriv.h"
#include "CGContextPriv.h"
#include "CGDashPriv.h"


CGDashRef CGDashCreate(CGFloat phase, const CGFloat lengths[], size_t count)
{
	int nFixed;
	CGDashRef dash;
	
	if (!count || !lengths)
		return NULL;
	
	nFixed = sizeof(CGDash) - sizeof(CGFloat*);
	dash = (CGDashRef) calloc(1, nFixed + count*sizeof(CGFloat));
	if (dash) {
		memcpy(dash->lengths, lengths, count * sizeof(CGFloat));
	}

	return dash;
}

const CGFloat* CGDashGetPattern(CGDashRef dash, float* phase, size_t* count)
{
	if (!dash)
		return NULL;

	if (phase)
		*phase = dash->phase;
	if (count)
		*count = dash->count;
	
	return dash->lengths;
}

Boolean CGDashEqualToDash(CGDashRef dash1, CGDashRef dash2)
{
	Boolean bRet = FALSE;
	int cmp;

	/*if ((dash1 == dash2) ||
		(dash1 && dash2)  
		(dash1->phase != dash2->phase) &&
		(dash1->count != dash2->count) &&
		!memcmp(dash1->lengths, dash2->lengths, dash1->count * sizeof(CGFloat)))
		bRet = TRUE;*/

	if (dash1 == dash2)
		return TRUE;
	if (!dash1 || !dash2)
		return FALSE;
	if ((dash1->phase != dash2->phase) || 
		(dash1->count != dash2->count))
		return FALSE;
	
	cmp = memcmp(dash1->lengths, dash2->lengths, dash1->count * sizeof(CGFloat));
	if (cmp == 0) 
		bRet =  TRUE; 

	return bRet;
}

CGDashRef CGDashRetain(CGDashRef dash)
{
	if (!dash) { return NULL; }
	
	dash->refcount++;
	
	return dash;
}

void CGDashRelease(CGDashRef dash)
{
	if (!dash) { return; }
	
	dash->refcount--;

	if (dash->refcount == 0) {
		free(dash->lengths);
	}
}


    







