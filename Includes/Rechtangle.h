
#pragma once

#include "Pos.h"

class Rechtangle
{
private:
	Rechtangle* old;

public:
	Pos pos{100,100};
	UINT16 width = 70, height = 70;
	UINT32 color = 0x0055FF;

	Rechtangle();
	~Rechtangle();

	void Move(Pos newPos);
	void Resize(UINT16 w, UINT16 h);
	void MoveAndResize(Pos newPos, UINT16 w, UINT16 h);
};
