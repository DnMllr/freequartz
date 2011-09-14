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
#ifndef CGZONERIV_H_
#define CGZONERIV_H_


//sizeof = 0x28
typedef struct _CGZone {
	
	unsigned int version;													//0x00
	void 	*(*malloc)		(void *zone, size_t size);						//0x04
    void 	*(*calloc)		(void *zone, size_t num_items, size_t size);	//0x08
    void 	*(*realloc)		(void *zone, void *ptr, size_t size);			//0x0C
	void 	(*free)			(void *zone, void *ptr);						//0x10
	void 	(*barrier)		(void *zone, void *ptr);						//0x14
	void 	*(*allocate)	(void *zone, size_t size);						//0x18
	void 	(*deallocate)	(void *zone, void *ptr);						//0x1C
	void 	*(*purge)		(void *zone);									//0x20
    void	(*reference)	(void *zone);									//0x24

} CGZone, *CGZoneRef;


CG_EXTERN size_t CGSystemGetMemorySize();

CG_PRIVATE_EXTERN void check_capabilities();

CG_EXTERN CGZoneRef CGSZoneGetMallocZone(int zoneID);

CG_EXTERN CGZoneRef CGSZoneCreate();

CG_EXTERN void zone_create();

CG_EXTERN void* zone_malloc(void* na, size_t size);

CG_EXTERN void* zone_calloc(void* na, size_t num, size_t size);

CG_EXTERN void* zone_realloc(void* na, void * ptr, size_t size);

CG_EXTERN void zone_free(void* na, void * ptr);

CG_EXTERN void zone_barrier(void* na, void * ptr);

CG_EXTERN void* zone_allocate(void* na, size_t size);

CG_EXTERN void zone_deallocate(void* na, void * ptr);

CG_EXTERN void* zone_purge(void* na);




#endif /* CGZONERIV_H_ */