
#pragma once

#include "Pos.h"

class Racket
{
private:
	const UINT32 defaultMove = 5; 
	
public:
	UINT8 width = 15;
	UINT16 height = 70;
	Pos pos;
	UINT32 color = 0x00FFFF;

	Racket();
	Racket(Pos pos);
	Racket(Pos pos, UINT16 height);
	Racket(Pos pos, UINT16 height, UINT8 width, UINT32 color);
	~Racket();

	void MoveUp(UINT32 step);
	void MoveDown(UINT32 step);
	void MoveUp();
	void MoveDown();
};

