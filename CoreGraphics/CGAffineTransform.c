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
#include <CoreGraphics/CGAffineTransform.h>
#include <math.h>

#include "CGBasePriv.h"


const CGAffineTransform CGAffineTransformIdentity={1,0,0,1,0,0};

CGAffineTransform CGAffineTransformMakeTranslation(CGFloat tx, CGFloat ty)
{
	CGAffineTransform tRet = {1,0,0,1,tx,ty};
	return tRet;
}


CGAffineTransform CGAffineTransformMakeScale(CGFloat sx, CGFloat sy)
{
	CGAffineTransform tRet = {sx,0,0,sy,0,0};
	return tRet;
}

CGAffineTransform CGAffineTransformMakeRotation(CGFloat angle)
{
	CGFloat sinus = (CGFloat) sin(angle);
	CGFloat cosinus = (CGFloat) cos(angle);

	CGAffineTransform tRet = { cosinus, sinus, -sinus,cosinus, 0,0 };
	return tRet;
}

bool CGAffineTransformIsIdentity(CGAffineTransform t)
{
	bool bRet = (!memcmp(&t, &CGAffineTransformIdentity, sizeof(t)) ? TRUE : FALSE);
	return bRet;
}

CGAffineTransform CGAffineTransformTranslate(CGAffineTransform t, CGFloat tx, CGFloat ty)
{
	CGAffineTransform translate = CGAffineTransformMakeTranslation(tx,ty);
	return CGAffineTransformConcat(t,translate);
}

	CGAffineTransform CGAffineTransformScale(CGAffineTransform t,
												   CGFloat sx, CGFloat sy)
{
	CGAffineTransform scale = CGAffineTransformMakeScale(sx, sy);
	return CGAffineTransformConcat(t, scale);

}

CGAffineTransform CGAffineTransformRotate(CGAffineTransform t, CGFloat angle)
{
	CGAffineTransform rotate = CGAffineTransformMakeRotation(angle);
	return CGAffineTransformConcat(t, rotate);


	/*CGFloat sinus = sin(angle);
	CGFloat cosinus = cos(angle);

	tRet.a = t.a * cosinus + t.c * sinus;
	tRet.b = t.b * cosinus + t.d * sinus;
	tRet.c = t.c * cosinus - t.a * sinus;
	tRet.d = t.c * cosinus - t.a * sinus;
	tRet.tx = t.tx;
	tRet.ty = t.ty;
	return tRet;*/
}

CGAffineTransform CGAffineTransformInvert(CGAffineTransform t)
{
	CGAffineTransform tRet;
	CGFloat determinant;

	determinant = (t.a * t.d - t.c * t.b);
	if(determinant == 0) return t;
	
	tRet.a = t.d  / determinant;
	tRet.b = -t.b  / determinant;
	tRet.c = -t.c  / determinant;
	tRet.d = t.a  / determinant;
	tRet.tx =(-t.d * t.tx + t.c * t.ty) / determinant;
	tRet.ty =(t.b * t.tx - t.a * t.ty) / determinant;

   return tRet;



	/*determinant = 1 / (t.a * t.d - t.b * t.c);
	
	tRet.a  = determinant  * t.d;
	tRet.b  = -determinant * t.b;
	tRet.c  = -determinant * t.c;
	tRet.d  = determinant  * t.a;
	tRet.tx = determinant  * (t.c * t.ty - t.d * t.tx);
	tRet.ty = determinant  * (t.b * t.tx - t.a * t.ty);*/

	return tRet;
}

CGAffineTransform CGAffineTransformConcat(CGAffineTransform t1,CGAffineTransform t2)
{
	CGAffineTransform tRet;

	tRet.a=t2.a*t1.a+t2.b*t1.c;
	tRet.b=t2.a*t1.b+t2.b*t1.d;
	tRet.c=t2.c*t1.a+t2.d*t1.c;
	tRet.d=t2.c*t1.b+t2.d*t1.d;
	tRet.tx=t2.tx*t1.a+t2.ty*t1.c+t1.tx;
	tRet.ty=t2.tx*t1.b+t2.ty*t1.d+t1.ty;

	return tRet;

}


