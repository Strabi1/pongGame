
#pragma once

#include "Pos.h"
#include "Observable.h"
#include "Draw.h"

class Rechtangle : public Observable
{
private:

	void _Move(Pos newPos);
	void _Resize(UINT16 w, UINT16 h);

public:
	Rechtangle* old;
	Pos pos{100,100};
	UINT16 width = 70, height = 70;
	UINT32 color = 0x0055FF;

	Rechtangle(Draw &draw);
	~Rechtangle();

	void Move(Pos newPos);
	void Resize(UINT16 w, UINT16 h);
	void MoveAndResize(Pos newPos, UINT16 w, UINT16 h);
};
