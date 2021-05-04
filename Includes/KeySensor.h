
#pragma once

#include "Observer.h"

class KeySensor : public Observer
{
private:
	
public:
	KeySensor();
	~KeySensor();

	virtual void ValueChanged(int argc, void** argv) override;
};


