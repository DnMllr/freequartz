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
//#include <mach/mach_time.h>
#include "RIP.h"
#include <libkern/OSAtomic.h>

static RIPStateRef	_ripc_globals = NULL;
static OSSpinLock	_ripc_globals_lock = OS_SPINLOCK_INIT;

#if 0
CGCallback _RIPCallbacks[] =
{
	{	kCGContextDelegateFinalize,				ripc_Finalize			},
	{	kCGContextDelegateGetColorTransform,	ripc_GetColorTransform	},
	{	kCGContextDelegateGetBounds,			ripc_GetBounds			},		
	{	kCGContextDelegateDrawLines,			ripc_DrawLines			},		
	{	kCGContextDelegateDrawRects,			ripc_DrawRects			},		
	{	kCGContextDelegateDrawPath,				ripc_DrawPath			},		
	{	kCGContextDelegateDrawImage,			ripc_DrawImage			},		
	{	kCGContextDelegateDrawImages,			ripc_DrawImages			},
	{	kCGContextDelegateDrawGlyphs,			ripc_DrawGlyphs			},		
	{	kCGContextDelegateDrawShading,			ripc_DrawShading		},
	{	kCGContextDelegateOperation,			ripc_Operation			},
	{	kCGContextDelegateDrawWindowContents,	ripc_DrawWindowContents	},
	{	kCGContextDelegateDirtyWindowContents,	ripc_DirtyWindowContents},		
	{	kCGContextDelegateBeginLayer,			ripc_BeginLayer			},		
	{	kCGContextDelegateEndLayer,				ripc_EndLayer			},		
	{	kCGContextDelegateGetLayer,				ripc_GetLayer			},		
	{	kCGContextDelegateDrawLayer,			ripc_DrawLayer			},		
															
};
#endif



RIPStateRef RIPGlobalState()
{
	RIPStateRef ripState;
	CGZoneRef zone;

	if (_ripc_globals == NULL)
	{
		OSSpinLockLock(&_ripc_globals_lock);
		if (_ripc_globals)
		{
			OSSpinLockUnlock(&_ripc_globals_lock);
			ripState = _ripc_globals;
		}
		else
		{
			zone = CGSZoneGetMallocZone(1);
			ripState = (RIPStateRef)zone->calloc(zone, 1, 0x78);

		}
	}
	else
	{
		
	}

	return ripState;
}

int CGBlt_depth(const char *encoding)
{
	return 0;
}













