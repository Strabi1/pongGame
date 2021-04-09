
#include "Render.h"
#include <math.h>
#include <stdio.h>

/*
*	A kepernyofelbontas le lett skalazva 160 x 90 -re
*/

#define MAX_LOGICAL_WIDTH	(160)
#define MAX_LOGICAL_HEIGHT	(90)

#define CONSTRAIN(x, min, max) (x < min ? min : x > max ? max : x)

Render::Render(Window *wnd)
{
	window = wnd;
}

void Render::DrawRechtangle(UINT32 x, UINT32 y, UINT32 h, UINT32 w, UINT32 color)
{
	UINT32 x_start, x_stop, y_start, y_stop;

	// x_mult = window->getWindowWidth() /  MAX_LOGICAL_WIDTH;
	// y_mult = window->getWindowHeight() /  MAX_LOGICAL_HEIGHT;

	// x_start = roundf(((float)x - (float)w / 2.0) * x_mult);
	// x_stop = roundf(((float)x + (float)w / 2.0) * x_mult);
	// y_start = roundf(((float)y - (float)h / 2.0) * y_mult);
	// y_stop = roundf(((float)y + (float)h / 2.0) * y_mult);
	
	// x_start = roundf(((float)x - (float)w / 2.0) );
	// x_stop = roundf(((float)x + (float)w / 2.0) );
	// y_start = roundf(((float)y - (float)h / 2.0) );
	// y_stop = roundf(((float)y + (float)h / 2.0) );

	x_start = x - w/2;
	x_stop = x + w/2;
	y_start = y - h/2;
	y_stop = y + h/2;

	printf("x_start: %d, x_stop: %d, y_start: %d, y_stop: %d\n", x_start, x_stop, y_start, y_stop);

	x_start = CONSTRAIN(x_start, 0, window->getWindowWidth());
	x_stop = CONSTRAIN(x_stop, 0, window->getWindowWidth());
	y_start = CONSTRAIN(y_start, 0, window->getWindowHeight());
	y_stop = CONSTRAIN(y_stop, 0, window->getWindowHeight());

	printf("x_start: %d, x_stop: %d, y_start: %d, y_stop: %d\n", x_start, x_stop, y_start, y_stop);


	UINT32* pixel = (UINT32*)window->buffer_memory;
	for(UINT32 y = y_start; y <= y_stop; y++)
	{
		for(UINT32 x = x_start; x <= x_stop; x++)
		{
			*(pixel + y * window->getWindowWidth() + x) = color;
		}
	}
}

void Render::ClearWindow(UINT32 color)
{
	UINT32* pixel = (UINT32*)window->buffer_memory;

	for(UINT32 y = 0; y < window->getWindowHeight(); y++)
	{
		for(UINT32 x = 0; x < window->getWindowWidth(); x++)
		{
			*pixel++ = color;
		}
	}
}

Render::~Render()
{
}
 