
#pragma once

#include <windows.h>
#include "Observer.h"

class KeySensor
{
private:
	
public:
	KeySensor();
	~KeySensor();

	void broadcast(MSG *msg);
};


