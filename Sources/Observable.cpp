
#include "Observable.h"

void Observable::AddObserver(Observer& observer)
{
	observers.push_back(&observer);
}

void Observable::NotifyObsrver(int argc, void** argv)
{
	for (auto observer : observers)
	{
		observer->ValueChanged(argc, argv);
	}
	
} 