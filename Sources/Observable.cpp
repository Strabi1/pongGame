
#include "Observable.h"

void Observable::AddObserver(Observer& observer)
{
	observers.push_back(&observer);
}

void Observable::NotifyObsrver()
{
	for (auto observer : observers)
	{
		observer->ValueChanged();
	}
	
}