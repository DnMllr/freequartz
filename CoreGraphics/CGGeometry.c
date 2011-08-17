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
#include <CoreGraphics/CGGeometry.h>
#include <float.h>
#include "CGBasePriv.h"
#include "CGPathPriv.h"


const CGPoint	CGPointZero		= {0, 0};
const CGRect	CGRectZero		= {0, 0, 0, 0};
const CGRect	CGRectNull		= {FLT_MAX, FLT_MAX, 0, 0};
const CGRect	CGRectInfinite	= {-FLT_MIN, -FLT_MIN, FLT_MAX, FLT_MAX};

CGFloat CGRectGetHeight(CGRect rect)
{
	return (rect.size.height);
}

CGFloat CGRectGetWidth(CGRect rect)
{
	return (rect.size.width);
}

CGFloat CGRectGetMinX(CGRect rect)
{
	return (rect.origin.x);
}

CGFloat CGRectGetMinY(CGRect rect)
{
	return (rect.origin.y);
}

CGFloat CGRectGetMidX(CGRect rect)
{
	return (rect.origin.x + rect.size.width/2);
}

CGFloat CGRectGetMidY(CGRect rect)
{
	return (rect.origin.y + rect.size.height/2);
}

CGFloat CGRectGetMaxX(CGRect rect)
{
	return (rect.origin.x + rect.size.width);
}

CGFloat CGRectGetMaxY(CGRect rect)
{
	return (rect.origin.y + rect.size.height);
}