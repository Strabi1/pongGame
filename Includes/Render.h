
#pragma once

#include "Window.h"

class Render
{
private:
	Window *window;
	
public:
	Render(Window *wnd);
	~Render();
	void DrawRechtangle(UINT32 x, UINT32 y, UINT32 h, UINT32 w, UINT32 color);
	void ClearWindow(UINT32 color);
};


