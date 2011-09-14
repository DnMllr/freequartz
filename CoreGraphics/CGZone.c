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
#include <pthread.h>

#include "CGBasePriv.h"
#include "CGZonePriv.h"

static pthread_once_t	gzone_create_once = PTHREAD_ONCE_INIT;
static CGZoneRef gZone = NULL;

static pthread_once_t	checked_once = PTHREAD_ONCE_INIT;
static bool checked_b = false;
static size_t memory_size = 0;

size_t CGSystemGetMemorySize()
{
	if ( !checked_b )
		pthread_once(&checked_once, check_capabilities);

  return memory_size;
}


void check_capabilities()
{ 
 /* v1 = 0;
  len = 4;
  v2 = 6;
  v3 = 13;*/

	//sysctl(int *name, u_int namelen, void *oldp, size_t *oldlenp, void *newp, size_t newlen);
  
	/*int mib[] = {CTL_HW, HW_PHYSMEM};
  size_t len = sizeof(int);
  int physmem;
  !sysctl(mib, 2, &physmem, &len, NULL, 0);
 ;
 */

#ifdef WIN32
	MEMORYSTATUSEX statex;
	statex.dwLength = sizeof (statex);
	if (GlobalMemoryStatusEx(&statex))
	{
		memory_size = statex.ullTotalPhys/1024;
	}
#endif

  checked_b = TRUE;

  return;
}


CGZoneRef CGSZoneGetMallocZone(int zoneID)
{
  return CGSZoneCreate();
}

CGZoneRef CGSZoneCreate()
{
  if ( !gZone )
	  pthread_once(&gzone_create_once, zone_create);
  
  return gZone;
}

void zone_create()
{
  CGZoneRef zone;

  zone = (CGZoneRef)malloc(sizeof(CGZone));
  if ( zone )
  {
	  zone->version		= 0;
	  zone->malloc		= zone_malloc;
	  zone->calloc		= zone_calloc;
	  zone->realloc		= zone_realloc;
	  zone->free		= zone_free;
	  zone->barrier		= zone_barrier;
	  zone->allocate	= zone_allocate;
	  zone->deallocate	= zone_deallocate;
	  zone->purge		= zone_purge;
	  
	  gZone = zone;
  }

  return;
}

void* zone_malloc(void* na, size_t size)
{
	return malloc(size);
}


void* zone_calloc(void* na, size_t num, size_t size)
{
	return calloc(num, size);
}

void* zone_realloc(void* na, void * ptr, size_t size)
{
	return realloc(ptr, size);
}

void zone_free(void* na, void * ptr)
{
	return free(ptr);
}

void zone_barrier(void* na, void * ptr)
{
	return free(ptr);
}


void* zone_allocate(void* na, size_t size)
{
	return malloc(size);
}


void zone_deallocate(void* na, void * ptr)
{
	return free(ptr);
}

void* zone_purge(void* na)
{
	return NULL;
}