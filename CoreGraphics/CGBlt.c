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
#include "CGBltPriv.h"


// Not sure yet how to decode this
//blt_depth[] = {
//	{ 2, 8, 16, 0		},		//A8_depth
//	{ 2, 8, 17, 4		},		//W8_depth
//	{ 8, 8, 0x33, 0x88	},		//RGBA32_depth
//	{ 8, 8, 0x33, 0x98	},		//rgba32_depth
//	{ 8, 8, 0x33, 0x48	},		//ARGB32_depth
//	{ 8, 8, 0x33, 0x48	},		//argb32_depth
//	{ 4, 5, 0x33, 0x44	},		//RGB555_depth
//	{ 4, 5, 0x33, 0x54	},		//rgb555_depth
//	{ 0, 0, 0x00, 0x00  }
//};


void* 
CGBlt_depth(const char *format)
{
	if (!format || !strlen(format))
		return NULL;


	return NULL;
}