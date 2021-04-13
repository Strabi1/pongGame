
#pragma once

#include "Render.h"
#include "Observer.h"

class Draw : public Render, public Observer
{
private:
	UINT32 background = 0xFF0000;
	
public:
	Draw(Window *wnd);
	~Draw();
	void MakeBorder(UINT8 size, UINT32 color);
	virtual void ValueChanged(int argc, void** argv) override;
};

