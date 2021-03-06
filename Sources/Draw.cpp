
#include "Draw.h"
#include "Rechtangle.h"
#include <stdio.h>

Draw::Draw(Window *wnd) : Render(wnd)
{
}

Draw::~Draw()
{
}

void Draw::MakeBorder(UINT8 size, UINT32 color)
{
	Render::DrawRechtangle2(0, 0, size-1, window->getWindowHeight(), color);
	Render::DrawRechtangle2(0, 0, window->getWindowWidth(), size-1, color);
	Render::DrawRechtangle2(window->getWindowWidth()-size+1, 0, window->getWindowWidth()-1, window->getWindowHeight(), color);
	Render::DrawRechtangle2(0, window->getWindowHeight()-size+1, window->getWindowWidth(), window->getWindowHeight(), color);
}

void Draw::ValueChanged(int argc, void** argv)
{
	if(argc < 2)
	{
		return;
	}

	Rechtangle *oldRecht = (Rechtangle*)argv[0];
	Rechtangle *newRecht = (Rechtangle*)argv[1];

	if(oldRecht)
	{
		printf("vc 1\n");
		Render::DrawRechtangle(oldRecht->pos.x, oldRecht->pos.y, oldRecht->height, oldRecht->width, background);
	}

	if(newRecht)
	{
		printf("vc 2\n");
		Render::DrawRechtangle(newRecht->pos.x, newRecht->pos.y, newRecht->height, newRecht->width, newRecht->color);
	}
	
	printf("vc 3\n");
}