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
#include "CGGStatePriv.h"

#include "CGBasePriv.h"
#include "CGPathPriv.h"
#include "CGColorSpacePriv.h"
#include "CGSoftMaskPriv.h"




CGGStackRef CGGStackCreate()
{
	return CGGStackCreateWithGState(NULL);
}


CGGStackRef	CGGStackCreateWithGState(CGGStateRef stateSrc)
{
	CGGStackRef stack;

	stack = (CGGStackRef)calloc(1, sizeof(CGGStack));
	if (!stack)
		return NULL;

	stack->refcount = 1;
	stack->capacity = 8;
	stack->count = 0;

	stack->gstate = (CGGStateRef *) malloc( sizeof(CGGStateRef) * stack->capacity);
	if (stack->gstate == NULL) {
		CGGStackRelease(stack);
		return NULL;
	}

	if (stateSrc == NULL)
		stack->gstate[stack->count] = CGGStateCreate();
	else
		stack->gstate[stack->count] = CGGStateCreateCopy(stateSrc);

	stack->count++;

	return stack;
}

CGGStateRef	CGGStackSave(CGGStackRef stack)
{
	CGGStateRef gStateCopy;

	gStateCopy = CGGStateCreateCopy(stack->gstate[stack->count - 1]);
	return push(stack, gStateCopy);
}

CGGStateRef push(CGGStackRef stack, CGGStateRef agState)
{
	CGGStateRef *gStateTmp;
	long lCapacity;

	if (stack->count == 0) {
		// TODO : error stack->count must be > 0
		return NULL;
	}

	if (stack->count == stack->capacity) {

		lCapacity = stack->capacity + 8;
		gStateTmp = (CGGStateRef *)realloc(stack->gstate, sizeof(CGGStateRef) * lCapacity);
		if (gStateTmp == NULL) { return NULL; }

		stack->capacity = lCapacity;
		stack->gstate = gStateTmp;
	}
	
	stack->gstate[stack->count++] = agState;

	return agState;
}


CGGStateRef	CGGStackRestore(CGGStackRef gstack)
{
	if (gstack->count == 0) {
		// TODO : error stack->count must be > 0
		return NULL;
	}
	
	if (gstack->count == 1) {
		CGPostError("%s: gstack count must be > 1.", "CGGStackRestore");
		return gstack->gstate[0];
	}

	gstack->count--;
	CGGStateRelease(gstack->gstate[gstack->count]);

	return (gstack->gstate[gstack->count - 1]);
}


void CGGStackReset(CGGStackRef gstack)
{
	int i;

	if (gstack->count > 0) {

		/* Release all states except first one */
		for (i = gstack->count; i > 1; i--) {
			gstack->count--;
			CGGStateRelease(gstack->gstate[gstack->count]);
		}

		CGGStateSetCTM(gstack->gstate[0], CGAffineTransformIdentity);
		CGGStateResetClip(gstack->gstate[0]);
		CGGStateReset(gstack->gstate[0]);
	}
}

CGGStateRef	CGGStateCreateCopy(CGGStateRef stateSrc)
{
	CGGStateRef stateCopy;

	stateCopy = (CGGStateRef)calloc(1, sizeof(CGGState));
	if (!stateCopy) 
		return NULL;

	stateCopy->refcount = 1;

	CGGStateClipCopy(stateCopy, stateSrc);
	CGGStateDeviceCopy(stateCopy, stateSrc);
	CGGStateRenderingCopy(stateCopy, stateSrc);
	CGGStateStrokeCopy(stateCopy, stateSrc);
	CGGStateTextCopy(stateCopy, stateSrc);

	stateCopy->CTM = stateSrc->CTM;
	stateCopy->fillColor = CGColorRetain(stateSrc->fillColor);

	return stateCopy;
}


void CGGStateClipCopy(CGGStateRef state, CGGStateRef stateSrc)
{
	state->clipStack = CGClipStackRetain(stateSrc->clipStack);
	stateSrc->hasClipping = TRUE;
	state->hasClipping = TRUE;
	state->clipRect = stateSrc->clipRect;
}

void CGGStateDeviceCopy(CGGStateRef state, CGGStateRef stateSrc)
{
	if (stateSrc->device) {
		stateSrc->device->refcount++;
	}
	state->device = stateSrc->device;
	state->hasDevice = TRUE;
	stateSrc->hasDevice = TRUE;
}

void CGGStateRenderingCopy(CGGStateRef state, CGGStateRef stateSrc)
{
	if (stateSrc->rendering) {
		stateSrc->device->refcount++;
	}
	state->rendering = stateSrc->rendering;
	state->hasDevice = TRUE;
	stateSrc->hasDevice = TRUE;
}

void CGGStateStrokeCopy(CGGStateRef state, CGGStateRef stateSrc)
{
	if (stateSrc->stateStroke) {
		stateSrc->stateStroke->refcount++;
	}
	state->stateStroke = stateSrc->stateStroke;
	state->hasStroke = TRUE;
	stateSrc->hasStroke = TRUE;
}

void CGGStateTextCopy(CGGStateRef state, CGGStateRef stateSrc)
{
	textStateRelease(state->stateText);
	if (stateSrc->stateText) {
		stateSrc->stateText->refcount++;
	}
	state->stateText = stateSrc->stateText;
	state->hasText = TRUE;
	stateSrc->hasText = TRUE;
}

void textStateRelease(CGStateTextRef textState)
{
	if (!textState)
		return;
	
	textState->refcount--;
	if (textState->refcount) {
		CGFontRelease(textState->font);
		free(textState);
	}
}

CGGStateRef	CGGStackGetGState(CGGStackRef stack)
{
	if (!stack->gstate) { return NULL; }

	return stack->gstate[stack->count - 1];
}

CGGStateRef	CGGStateCreate()
{
	CGGStateRef state;

	state = (CGGStateRef) calloc(1, sizeof(CGGState));
	if (!state) { return NULL; }

	state->refcount = 1;
	state->CTM = CGAffineTransformIdentity;

	CGGStateClipReset(state);
	CGGStateReset(state);

	return state;
}



void CGGStateReset(CGGStateRef agstate)
{
	CGGStateDeviceReset(agstate);
	CGGStateTextReset(agstate);
	CGGStateRenderingReset(agstate);
	CGGStateStrokeReset(agstate);
	CGGStateSetFillColor(agstate, 0);
	
	return;
}

void CGGStateClipReset(CGGStateRef agstate)
{
	CGGStateResetClip(agstate);
	return;
}

void CGGStateResetClip(CGGStateRef state)
{
	//CGClipStackRef clipStack;

	CGClipStackRelease(state->clipStack);
	state->clipStack = CGClipStackCreateMutable();
	
	state->clipRect = CGRectInfinite;
	state->hasClipping = FALSE;
}


void CGGStateDeviceReset(CGGStateRef agstate)
{
	CGDeviceRef device;

	if (agstate->device == NULL) {
		device = (CGDeviceRef) calloc(1, sizeof(CGDevice));
		if (device == NULL) {
			agstate->hasDevice = FALSE;
			return;
		}
		device->refcount = 1;
		deviceStateReset(device);
	}
	else {
		maybeCopyDeviceState(agstate);
		deviceStateReset(agstate->device);
	}
}



void deviceStateReset(CGDeviceRef device)
{
	CGFunctionRelease(device->blackGeneration);
	device->blackGeneration = NULL;

	CGFunctionRelease(device->underColorRemoval);
	device->underColorRemoval = NULL;
}	

void maybeCopyDeviceState(CGGStateRef state)
{
	CGDeviceRef device;

	if( state->hasDevice == FALSE)
		return;

	device = (CGDeviceRef) calloc(1, sizeof(CGDevice));
	if (!device) {

		deviceStateRelease(state->device);
		state->hasDevice = FALSE;
	}
	else {
		device->refcount = 1;
		CGFunctionRetain(device->blackGeneration);
		CGFunctionRetain(device->underColorRemoval);
	}

}

void CGGStateTextReset(CGGStateRef gstate)
{

}

void CGGStateRenderingReset(CGGStateRef agstate)
{
	CGGStateRenderingRef gStateRendering;

	if (agstate->rendering == NULL) {
		gStateRendering = (CGGStateRenderingRef) calloc(1, sizeof(CGGStateRendering));
		if (gStateRendering == NULL) {
			agstate->hasStroke = FALSE;
			return;
		}
		gStateRendering->refcount = 1;
		renderingStateReset(gStateRendering);
		agstate->rendering = gStateRendering;
		agstate->hasRendering = FALSE;
	}
	else {
		maybeCopyRenderingState(agstate); 
		renderingStateReset(agstate->rendering);
	}
}

void maybeCopyRenderingState(CGGStateRef state)
{
	CGGStateRenderingRef gStateRendering;

	if (state->hasRendering == FALSE)
		return;

	gStateRendering = (CGGStateRenderingRef) calloc(1, sizeof(CGGStateRendering));
	if (!gStateRendering) {

		renderingStateRelease(state->rendering);
		state->rendering = NULL;
		state->hasRendering = FALSE;
	}
	else {
		gStateRendering->refcount = 1;

	}

}

void renderingStateReset(CGGStateRenderingRef gStateRendering)
{
	if (gStateRendering->style) {
		CGStyleRelease(gStateRendering->style);
		gStateRendering->style = NULL;
	}

	if (gStateRendering->softMask) {
		CGSoftMaskRelease(gStateRendering->softMask);
		gStateRendering->softMask = NULL;
	}

}

void renderingStateRelease(CGGStateRenderingRef gStateRendering)
{

}


void CGGStateStrokeReset(CGGStateRef agstate)
{
	CGStateStrokeRef stateStroke;

	if (agstate->stateStroke == NULL) {
		stateStroke = (CGStateStrokeRef) calloc(1, sizeof(CGStateStroke));
		if (stateStroke == NULL) {
			agstate->hasStroke = FALSE;
			return;
		}
		stateStroke->refcount = 1;
		strokeStateReset(stateStroke);
		agstate->stateStroke = stateStroke;
		agstate->hasStroke = FALSE;
	}
	else {
		maybeCopyStrokeState(agstate); 
		strokeStateReset(agstate->stateStroke);
	}
}

void maybeCopyStrokeState(CGGStateRef state)
{
	CGStateStrokeRef stroke;

	stroke = (CGStateStrokeRef) calloc(1, sizeof(CGStateStroke));
	if (!stroke) {
		strokeStateRelease(state->stateStroke);
		state->stateStroke = NULL;
		state->hasStroke = FALSE;
		
	}
	else {
		stroke->dash = CGDashRetain(state->stateStroke->dash);
		stroke->color = CGColorRetain(state->stateStroke->color);
	}
}

void strokeStateReset(CGStateStrokeRef stateStroke)
{
	CGDashRelease(stateStroke->dash);
	stateStroke->dash = NULL;
	
	CGColorRelease(stateStroke->color);
	stateStroke->color = NULL;
}

void strokeStateRelease(CGStateStrokeRef stateStroke)
{
	if (!stateStroke)
		return;

	stateStroke->refcount--;
	if (stateStroke->refcount == 0) {

		CGDashRelease(stateStroke->dash);
		CGColorRelease(stateStroke->color);
		free(stateStroke);
	}
}

void CGGStateSetCompositeOperation(CGGStateRef gstate, CGCompositeMode compositeMode)
{

}

CGColorRef CGGStateGetFillColor(CGGStateRef state)
{
	CGColorSpaceRef colorSpace;

	if (state->fillColor) { return state->fillColor; }
	
	colorSpace = CGColorSpaceCreateDeviceGray();
	state->fillColor = CGColorSpaceCopyDefaultColor(colorSpace); 
	CGColorSpaceRelease(colorSpace);

	return state->fillColor;
}



void CGGStateSetFillColor(CGGStateRef state, CGColorRef color)
{
	if (CGColorEqualToColor(state->fillColor, color))
		return;

	CGColorRelease(state->fillColor);
	state->fillColor = CGColorRetain(color);
}


void CGGStackRelease(CGGStackRef stack)
{
	int i;
	if (!stack) { return; }

	stack->refcount--;
	if (stack->refcount != 0)
		return;
	
	for (i = 0; i < stack->capacity; i++) {
		CGGStateRelease( stack->gstate[i] ); 
	}

	free(stack->gstate);
	free(stack);
}


void CGGStateRelease(CGGStateRef state)
{
	if (!state) { return; }
	state->refcount--;
	if (state->refcount != 0) { return;}

	CGGStateClipRelease(state);
	CGGStateDeviceRelease(state);
	CGGStateRenderingRelease(state);
	CGGStateStrokeRelease(state);
	CGGStateTextRelease(state);
	CGColorRelease(state->fillColor);
	
	free(state);
}

CGAffineTransform CGGStateGetCTM(CGGStateRef state)
{
	return state->CTM;
}

void CGGStateSetCTM(CGGStateRef state, CGAffineTransform ctm)
{
	state->CTM = ctm;
}


void CGGStateSetAlpha(CGGStateRef state, CGFloat alpha)
{
	if (state->rendering->alpha == alpha)
		return;

	maybeCopyRenderingState(state);
	state->rendering->alpha = alpha;

}

CGFloat	CGGStateGetLineWidth(CGGStateRef state)
{
	return state->stateStroke->lineWidth;
}

void CGGStateSetLineWidth(CGGStateRef state, CGFloat width)
{
	if (state->stateStroke->lineWidth == width)
		return;
	
	maybeCopyStrokeState(state);
	state->stateStroke->lineWidth = width;
}

void CGGStateSetLineCap(CGGStateRef state, CGLineCap cap)
{
	if (state->stateStroke->lineCap == cap)
		return;

	maybeCopyStrokeState(state);
	state->stateStroke->lineCap = cap;

}

void CGGStateSetLineJoin(CGGStateRef state, CGLineJoin join)
{
	if (state->stateStroke->lineJoin == join)
		return;

	maybeCopyStrokeState(state);
	state->stateStroke->lineJoin = join;
}

void CGGStateSetMiterLimit(CGGStateRef state, CGFloat miter)
{
	if (state->stateStroke->miterLimit == miter)
		return;

	maybeCopyStrokeState(state);
	state->stateStroke->miterLimit = miter;
}


void CGGStateSetLineDash(CGGStateRef state, CGDashRef dash)
{
	if (CGDashEqualToDash(state->stateStroke->dash, dash) == TRUE)
		return;
	
	maybeCopyStrokeState(state);
	CGDashRelease(state->stateStroke->dash);
	state->stateStroke->dash = CGDashRetain(dash);
}

void CGGStateSetFlatness(CGGStateRef state, CGFloat flatness)
{
	if (state->device->flatness == flatness)
		return;

	maybeCopyDeviceState(state);
	state->device->flatness = flatness;
}

void CGGStateSetStrokeAdjust(CGGStateRef state, CGFloat strokeAdjust)
{
	if (state->stateStroke->strokeAdjust == strokeAdjust)
		return;

	maybeCopyStrokeState(state);
	state->stateStroke->strokeAdjust = strokeAdjust;
}


CGFloat	CGGStateGetFlatness(CGGStateRef state)
{
	return state->device->flatness;
}



void CGGStateSetBlackGeneration(CGGStateRef gstate, CGFunctionRef blackGeneration)
{

}

void CGGStateSetUndercolorRemoval(CGGStateRef gstate, CGFunctionRef underColorRemoval)
{

}

void CGGStateSetFontSize(CGGStateRef state, CGFloat size)
{
	if (state->stateText->size == size)
		return;

	maybeCopyTextState(state);
	state->stateText->size = size;
}


void maybeCopyTextState(CGGStateRef state)
{
	CGStateTextRef stateText;

	if (state->hasText == FALSE)
		return;

	stateText = (CGStateTextRef) calloc(1, sizeof(CGStateText));
	if (!stateText) {

		textStateRelease(state->stateText);
		state->hasText = FALSE;
	}
	else {
		stateText->refcount = 1;
		stateText->font = CGFontRetain(state->stateText->font);

	}
}

void CGGStateClipRelease(CGGStateRef state)
{
	//CGClipStackRelease(state->clipping);
}

void CGGStateDeviceRelease(CGGStateRef state)
{
	deviceStateRelease(state->device);
	return;
}

void deviceStateRelease(CGDeviceRef device)
{
	if (!device) return;

	device->refcount--;
	if (device->refcount == 0) {
		CGFunctionRelease(device->blackGeneration);
		CGFunctionRelease(device->underColorRemoval);
		free(device);
	}
}


void CGGStateRenderingRelease(CGGStateRef state)
{
}

void CGGStateStrokeRelease(CGGStateRef state)
{
}

void CGGStateTextRelease(CGGStateRef state)
{
}


void CGGStateClipToPath(CGGStateRef state, CGPathRef path, CGPathDrawingMode mode)
{
#if 0
	CGFloat flatness;
	CGClipRef clip, clipStroke;
	bool shouldAntialias;

	if (mode == kCGPathStroke) {
		
		clipStroke = CGClipStrokeCreateWithGState(state, path);
		clip = CGClipCreateWithStrokedPath(path, clipStroke);
		CGClipStrokeRelease(clipStroke);
	}
	else {
		flatness = CGGStateGetFlatness(state);
		shouldAntialias = CGGStateGetShouldAntialias(state);
		clip = CGClipCreateWithPath(path, mode, shouldAntialias ,flatness);
	}

	if (clip) {  
		maybeCopyClipState(state);
		CGClipStackAddClip(state->clipping, clip);
		CGClipRelease(clip);
	}
#endif
}

CGClipRef CGClipStrokeCreateWithGState(CGGStateRef state, CGPathRef path)
{
#if 0
	CGGStateGetCTM(state);
	CGGStateGetLineWidth(state);
	CGGStateGetLineCap(state);
	CGGStateGetLineJoin(state);
	CGGStateGetMiterLimit(state);
	CGGStateGetStrokeAdjust(state);
	CGGStateGetShouldAntialias(state);
	CGGStateGetLineDash();
	CGGStateGetFlatness();

	CGClipStrokeCreate();
#endif
	return NULL;
}


void CGClipRelease(CGClipRef clip)
{

}

CGClipStackRef CGClipStackCreateMutable()
{
	CGClipStackRef clipStack;

	clipStack = (CGClipStackRef)calloc(1, sizeof(CGClipStack));
	if (!clipStack)
		return NULL;
	
	clipStack->refcount = 1;
	clipStack->id = 0;
	clipStack->field3C = 0;
	clipStack->count = 0;
	clipStack->clips = NULL;
	clipStack->rect = CGRectInfinite;
	clipStack->rect2 = CGRectInfinite;
	clipStack->rect3 = CGRectInfinite;

	return clipStack;

}

void CGClipStackRelease(CGClipStackRef clipStack)
{
	size_t i;

	if (!clipStack)
		return;

	clipStack->refcount--;
	if (clipStack->refcount == 0) {
		
		for (i = 0; i < clipStack->count; i++) {
			CGClipRelease(clipStack->clips[i]);
		}

		free(clipStack->clips);
		free(clipStack);
	}
}

CGClipStackRef CGClipStackRetain(CGClipStackRef clipStack)
{
	if (!clipStack) { return NULL; }
	clipStack->refcount++;
	return clipStack;
}