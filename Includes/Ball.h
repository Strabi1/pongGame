
#pragma once

#include "Pos.h"

class Ball
{
private:

protected:

public:
	UINT8 size = 8;
	Pos pos;

	Ball();
	Ball(Pos pos);
	Ball(UINT8 size);
	Ball(Pos pos, UINT8 size);

	~Ball();
};

