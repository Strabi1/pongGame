
#include "Racket.h"


Racket::Racket() : pos{0,0} {}
Racket::Racket(Pos pos) : pos{pos} {}
Racket::Racket(Pos pos, UINT16 height) : pos{pos}, height{height} {}
Racket::Racket(Pos pos, UINT16 height, UINT8 width, UINT32 color) : pos{pos}, height{height}, width{width}, color{color} {}



Racket::~Racket()
{
}