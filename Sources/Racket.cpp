
#include <stdio.h>
#include "Racket.h"


Racket::Racket() : pos{0,0} {}
Racket::Racket(Pos pos) : pos{pos} {}
Racket::Racket(Pos pos, UINT16 height) : pos{pos}, height{height} {}
Racket::Racket(Pos pos, UINT16 height, UINT8 width, UINT32 color) : pos{pos}, height{height}, width{width}, color{color} {}


Racket::~Racket()
{
}

void Racket::MoveUp(UINT32 step)
{
	pos.y += step;
	// TODO: redraw request
	printf("MoveUp\n");
}

void Racket::MoveDown(UINT32 step)
{
	pos.y -= step;
	// TODO: redraw request
	printf("MoveDown\n");
}

void Racket::MoveUp()
{
	Racket::MoveUp(defaultMove);
}

void Racket::MoveDown()
{
	Racket::MoveDown(defaultMove);
}
