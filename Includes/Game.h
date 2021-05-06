
#pragma once

#include "KeySensor.h"

class Game
{
private:
	KeySensor *keySensor;

public:
	Game(KeySensor *key);
	~Game();

	void teszt();
};


