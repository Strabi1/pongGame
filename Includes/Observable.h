
#pragma once

#include <vector>
#include "Observer.h"

class Observable
{
private:
	std::vector<Observer*> observers;
	
protected:
	void NotifyObsrver();

public:
	void AddObserver(Observer& observer);

};

