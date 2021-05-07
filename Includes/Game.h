
#pragma once

#include "KeySensor.h"
#include "Racket.h"

class Game
{
private:
	KeySensor *keySensor;
	Racket rackets[2] = {Pos(100,100), Pos(500,500)};

public:
	Game(KeySensor *key);
	~Game();

	void teszt();
};


