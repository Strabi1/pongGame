
#pragma once

#include "Pos.h"
#include "Draw.h"
#include "Rechtangle.h"

class Racket
{
private:
	const UINT32 defaultMove = 5; 
	Rechtangle image;
	Draw *draw;
	
public:
	UINT8 width = 15;
	UINT16 height = 70;
	Pos pos;
	UINT32 color = 0xFFFFFF;

	Racket(Draw* draw);
	Racket(Draw* draw, Pos pos);
	Racket(Draw* draw, Pos pos, UINT16 height);
	Racket(Draw* draw, Pos pos, UINT16 height, UINT8 width, UINT32 color);
	~Racket();

	void MoveUp(UINT32 step);
	void MoveDown(UINT32 step);
	void MoveUp();
	void MoveDown();
};

