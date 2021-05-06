
#pragma once

#include <windows.h>
#include "Observer.h"
//#include "Game.h"

class KeySensor
{
private:
	
public:
	KeySensor();
	~KeySensor();

	void broadcast(MSG *msg);

	void *game;
};


