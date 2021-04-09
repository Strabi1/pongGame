
#pragma once

#include "Pos.h"

class Ball
{
private:

protected:

public:
	UINT8 size = 8;
	Pos pos;
	UINT32 color = 0xFFFFFF;

	Ball();
	Ball(Pos pos);
	Ball(UINT8 size);
	Ball(Pos pos, UINT8 size);
	Ball(Pos pos, UINT8 size, UINT32 color);

	~Ball();
};

