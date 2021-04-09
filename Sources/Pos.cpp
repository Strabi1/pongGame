
#include "Pos.h"

Pos::Pos()
{
}

Pos::Pos(UINT32 x, UINT32 y)
{
	this->x = x;
	this->y = y;
}

Pos::~Pos()
{
}

void Pos::SetX(UINT32 x)
{
	this->x = x;
}
void Pos::SetY(UINT32 x)
{
	this->y = y;
}

void Pos::SetXY(UINT32 x, UINT32 y)
{
	this->x = x;
	this->y = y;
}

UINT32 Pos::GetX(void)
{
	return x;
}

UINT32 Pos::GetY(void)
{
	return y;
}
