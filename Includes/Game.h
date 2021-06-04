
#pragma once

#include "KeySensor.h"
#include "Racket.h"
#include "Draw.h"

class Game
{
private:
	KeySensor *keySensor;
	Draw *draw;

public:
	Game(KeySensor *key, Draw *draw);
	~Game();

	Racket rackets[2] = {{draw, Pos(100, 500)}, {draw, Pos(1000, 500)}};
	void teszt();
};


