
#pragma once

#include "Pos.h"
#include "Observable.h"
#include "Draw.h"

class Rechtangle : public Observable
{
private:

	void _Move(Rechtangle *old, Pos newPos);
	void _Resize(Rechtangle *old, UINT16 w, UINT16 h);

public:
	Pos pos{100,100};
	UINT16 width = 70, height = 70;
	UINT32 color = 0x0055FF;

	Rechtangle(Draw &draw);
	Rechtangle(Draw *draw);
	Rechtangle(Draw *draw, Pos pos, UINT32 color);
	Rechtangle(Draw *draw, Pos pos, UINT16 w, UINT16 h, UINT32 color);
	~Rechtangle();

	Rechtangle* Clone();

	void Move(Pos newPos);
	void Resize(UINT16 w, UINT16 h);
	void MoveAndResize(Pos newPos, UINT16 w, UINT16 h);
	
	void _Notify(Rechtangle *old);
};
