
#include <stdio.h>
#include "Racket.h"


Racket::Racket(Draw* draw) : draw{draw}, image{draw, pos, 0xFFFFFF}, pos{0,0} {}
Racket::Racket(Draw* draw, Pos pos) : draw{draw}, image{draw, pos, 15, 70, 0xFFFFFF}, pos{pos} {}
Racket::Racket(Draw* draw, Pos pos, UINT16 height) : draw{draw}, image{draw}, pos{pos}, height{height} {}
Racket::Racket(Draw* draw, Pos pos, UINT16 height, UINT8 width, UINT32 color) : draw{draw}, image{draw}, pos{pos}, height{height}, width{width}, color{color} {}

Racket::~Racket()
{
}

void Racket::Init()
{
	printf("Init---\n");
	this->image._Notify(NULL);
}

void Racket::MoveUp(UINT32 step)
{
	pos.y += step;
	// TODO: redraw request
	printf("MoveUp\n");
	image.Move(pos);
}

void Racket::MoveDown(UINT32 step)
{
	pos.y -= step;
	// TODO: redraw request
	printf("MoveDown\n");
	image.Move(pos);
}

void Racket::MoveUp()
{
	Racket::MoveUp(defaultMove);
}

void Racket::MoveDown()
{
	Racket::MoveDown(defaultMove);
}
