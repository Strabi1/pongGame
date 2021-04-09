
#pragma once

#include "Window.h"

class Render
{
private:

protected:
	Window *window;

public:
	Render(Window *wnd);
	~Render();
	void DrawRechtangle(UINT32 x, UINT32 y, UINT32 h, UINT32 w, UINT32 color);
	void DrawRechtangle2(UINT32 x1, UINT32 y1, UINT32 x2, UINT32 y2, UINT32 color);
	void ClearWindow(UINT32 color);
};


