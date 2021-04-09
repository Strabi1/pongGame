
#include "Draw.h"
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