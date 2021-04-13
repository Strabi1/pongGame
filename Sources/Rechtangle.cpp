
#include <stdio.h>
#include "Rechtangle.h"


Rechtangle* Rechtangle::Clone()
{
	return new Rechtangle(*this);
}

Rechtangle::Rechtangle(Draw &draw)
{
	this->AddObserver(draw);
}

Rechtangle::~Rechtangle()
{
}

void Rechtangle::Move(Pos newPos)
{
	Rechtangle old(*this);
	_Move(&old, newPos);
	_Notify(&old);
}

void Rechtangle::Resize(UINT16 w, UINT16 h)
{
	Rechtangle old(*this);
	_Resize(&old, w, h);
	_Notify(&old);
}

void Rechtangle::MoveAndResize(Pos newPos, UINT16 w, UINT16 h)
{
	Rechtangle old(*this);
	_Move(&old, newPos);
	_Resize(&old, w, h);
	_Notify(&old);
}


void Rechtangle::_Move(Rechtangle *old, Pos newPos)
{
	old->pos = pos;
	pos = newPos;
}

void Rechtangle::_Resize(Rechtangle *old, UINT16 w, UINT16 h)
{
	old->width = width;
	old->height = height;

	width = w;
	height = h;
}

void Rechtangle::_Notify(Rechtangle *old)
{
	void* array[] = {old, this};
	NotifyObsrver(2, array);
}