
#include <stdio.h>
#include "Ball.h"
#include "math.h"

#define PI 3.14159265

Ball::Ball(Draw* draw) : draw{draw}, pos{0, 0}, image{draw, pos, size, size, color}{}
//Ball::Ball(Draw* draw, Pos pos) : draw{draw}, pos{pos}, image{draw, pos, size, size, color} {}
Ball::Ball(Draw* draw, Pos pos) : draw{draw}, image{draw, pos, 8, 8, 0xFFFFFF}, pos{pos} {}

Ball::Ball(Draw* draw, UINT8 size) : draw{draw}, size {size}, pos{0, 0}, image{draw, pos, size, size, color} {}
Ball::Ball(Draw* draw, Pos pos, UINT8 size) :draw{draw}, pos{pos}, size{size}, image{draw, pos, size, size, color} {}
Ball::Ball(Draw* draw, Pos pos, UINT8 size, UINT32 color) : draw{draw}, pos{pos}, size{size}, color{color}, image{draw, pos, size, size, color} {}

Ball::~Ball()
{
}

void Ball::Init()
{
	printf("Ball  Init---\n");
	this->image._Notify(NULL);
}

void Ball::Move(UINT16 time_ms)
{
	pos.x += UINT32(cos(speedDir * PI / 180.0) * speedAbs * time_ms / 1000);   
	pos.y += UINT32(sin(speedDir * PI / 180.0) * speedAbs * time_ms / 1000);   


	printf("p.x = %u p.x = %u\n", pos.x, pos.y);
	image.Move(pos);
}
