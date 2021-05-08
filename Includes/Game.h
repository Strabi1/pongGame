
#pragma once

#include "KeySensor.h"
#include "Racket.h"

class Game
{
private:
	KeySensor *keySensor;

public:
	Game(KeySensor *key);
	~Game();

	Racket rackets[2] = {Pos(100,100), Pos(500,500)};
	void teszt();
};


