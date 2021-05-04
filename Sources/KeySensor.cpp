
#include <stdio.h>
#include "KeySensor.h"
#include "Window.h"

#define BUTTON_PRESSED		0x01
#define BUTTON_RELEASED		0x02

typedef enum
{
	BTN_UP,
	BTN_DOWN,
}ButtonState;


KeySensor::KeySensor()
{
}

KeySensor::~KeySensor()
{
}

void KeySensor::ValueChanged(int argc, void** argv)
{
	static UINT8 upKey = 0;
	
	if(argc < 1)
		return;

	MSG *msg;

	msg = (MSG*)argv[0];

	UINT32 vk = (UINT32)msg->wParam;
	ButtonState buttonState =  ((msg->lParam & (1 << 31)) == 0) ? BTN_DOWN : BTN_UP;
	printf("Buttonstte: %d\n", buttonState);

	switch(vk)
	{
		case VK_UP:
		{
			upKey = ((upKey & 0x01) << 1) | buttonState;
			printf("VK_UP: %d\n", upKey);
		} break;

		default:
		{		
		}
	}

	if(upKey == BUTTON_PRESSED)
	{
		printf("press\n");
	}	
}