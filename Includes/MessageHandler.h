
#pragma once;

#include <windows.h>
#include "KeySensor.h"
#include "Window.h"

class MessageHandler
{
private:
	Window *window;
	KeySensor *keySensor;

public:
	MessageHandler(Window *wind, KeySensor *key);
	~MessageHandler();

	void PollMessages();
};
