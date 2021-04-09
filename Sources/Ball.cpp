
#include "Ball.h"


Ball::Ball() : pos{0, 0} {}
Ball::Ball(Pos pos) : pos{pos} {}
Ball::Ball(UINT8 size) : size {size}, pos{0, 0} {}
Ball::Ball(Pos pos, UINT8 size) : pos{pos}, size{size} {}
Ball::Ball(Pos pos, UINT8 size, UINT32 color) : pos{pos}, size{size}, color{color} {}

Ball::~Ball()
{
}
