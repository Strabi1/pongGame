
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

void Draw::ValueChanged(void* param)
{
	Rechtangle *rechtangle = (Rechtangle*)param;

	Render::DrawRechtangle(rechtangle->old->pos.x, rechtangle->old->pos.y, rechtangle->old->height, rechtangle->old->width, background);
	Render::DrawRechtangle(rechtangle->pos.x, rechtangle->pos.y, rechtangle->height, rechtangle->width, rechtangle->color);
}