
#include "Render.h"
#include <stdio.h>


#define CONSTRAIN(x, min, max) (x < min ? min : x > max ? max : x)


Render::Render(Window *wnd)
{
	window = wnd;
}

Render::~Render()
{
}

void Render::DrawRechtangle(UINT32 x, UINT32 y, UINT32 h, UINT32 w, UINT32 color)
{
	UINT32 x_start, x_stop, y_start, y_stop;

	x_start = x - w/2;
	x_stop = x + w/2;
	y_start = y - h/2;
	y_stop = y + h/2;

	x_start = CONSTRAIN(x_start, 0, window->getWindowWidth());
	x_stop = CONSTRAIN(x_stop, 0, window->getWindowWidth());
	y_start = CONSTRAIN(y_start, 0, window->getWindowHeight());
	y_stop = CONSTRAIN(y_stop, 0, window->getWindowHeight());

	UINT32* pixel = (UINT32*)window->buffer_memory;
	for(UINT32 y = y_start; y <= y_stop; y++)
	{
		for(UINT32 x = x_start; x <= x_stop; x++)
		{
			*(pixel + y * window->getWindowWidth() + x) = color;
		}
	}
}

void Render::DrawRechtangle2(UINT32 x1, UINT32 y1, UINT32 x2, UINT32 y2, UINT32 color)
{
	//printf("x1: %d, y1: %d, x2: %d, y2: %d\n", x1, y1, x2, y2);

	x1 = CONSTRAIN(x1, 0, window->getWindowWidth()-1);
	x2 = CONSTRAIN(x2, 0, window->getWindowWidth()-1);
	y1 = CONSTRAIN(y1, 0, window->getWindowHeight()-1);
	y2 = CONSTRAIN(y2, 0, window->getWindowHeight()-1);

	//printf("x1: %d, y1: %d, x2: %d, y2: %d\n", x1, y1, x2, y2);

	UINT32* pixel = (UINT32*)window->buffer_memory;
	for(UINT32 y = y1; y <= y2; y++)
	{
		for(UINT32 x = x1; x <= x2; x++)
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
 