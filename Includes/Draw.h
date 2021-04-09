
#pragma once

#include "Render.h"

class Draw : public Render
{
private:
	
public:
	Draw(Window *wnd);
	~Draw();
	void MakeBorder(UINT8 size, UINT32 color);
};

