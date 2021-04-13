
#include "Rechtangle.h"


Rechtangle::Rechtangle(Draw &draw)
{
	this->AddObserver(draw);
}

Rechtangle::~Rechtangle()
{
}

void Rechtangle::Move(Pos newPos)
{
	_Move(newPos);
	NotifyObsrver();
}

void Rechtangle::Resize(UINT16 w, UINT16 h)
{
	_Resize(w, h);
	NotifyObsrver();
}

void Rechtangle::MoveAndResize(Pos newPos, UINT16 w, UINT16 h)
{
	_Move(newPos);
	_Resize(w, h);
	NotifyObsrver();
}


void Rechtangle::_Move(Pos newPos)
{
	old->pos = pos;
	pos = newPos;
}

void Rechtangle::_Resize(UINT16 w, UINT16 h)
{
	old->width = width;
	old->height = height;

	width = w;
	height = h;
}