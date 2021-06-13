
#pragma once

#include "Pos.h"
#include "Draw.h"
#include "Rechtangle.h"

class Ball
{
private:
	Draw *draw;

public:
	Rechtangle image;
	UINT8 size = 8;
	Pos pos;
	UINT32 color = 0xFFFFFF;

	Ball(Draw* draw);
	Ball(Draw* draw, Pos pos);
	Ball(Draw* draw, UINT8 size);
	Ball(Draw* draw, Pos pos, UINT8 size);
	Ball(Draw* draw, Pos pos, UINT8 size, UINT32 color);

	~Ball();

	void Init();
};

