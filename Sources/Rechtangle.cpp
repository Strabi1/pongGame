
#include "Rechtangle.h"

Rechtangle::Rechtangle()
{
}

Rechtangle::~Rechtangle()
{
}

void Rechtangle::Move(Pos newPos)
{
	old->pos = pos;
	pos = newPos;
}

void Rechtangle::Resize(UINT16 w, UINT16 h)
{
	old->width = width;
	old->height = height;

	width = w;
	height = h;
}

void Rechtangle::MoveAndResize(Pos newPos, UINT16 w, UINT16 h)
{
	Move(newPos);
	Resize(w, h);
}
