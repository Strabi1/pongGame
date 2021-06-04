
#include "MessageHandler.h"


MessageHandler::MessageHandler(Window *wind, KeySensor *key) : keySensor{key}, window{wind} {}

MessageHandler::~MessageHandler()
{
}

void MessageHandler::PollMessages()
{
	MSG msg;

	while (::PeekMessage(&msg, NULL, 0, 0, PM_REMOVE) > 0)
	{
		switch(msg.message)
		{
			//case WM_KEYUP:
			case WM_KEYDOWN:
			{
				keySensor->broadcast(&msg);
			} break;
				
			
			default:
			{
				window->broadcast(&msg);
			}
		}
	}
}