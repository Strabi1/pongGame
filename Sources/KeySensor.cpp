
#include <stdio.h>
#include "KeySensor.h"
#include "Window.h"
#include "Game.h"

#define BUTTON_PRESSED		0x01
#define BUTTON_RELEASED		0x02

#define VK_W_KEY	0X57
#define VK_S_KEY	0X53

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


void KeySensor::broadcast(MSG *msg)
{
	static UINT8 upKey = 0;
	
	UINT32 vk = (UINT32)msg->wParam;
	ButtonState buttonState =  ((msg->lParam & (1 << 31)) == 0) ? BTN_DOWN : BTN_UP;
	printf("Buttonstte: %d\n", buttonState);

	switch(vk)
	{
		case VK_UP:
		{
			((Game*)game)->rackets[0].MoveUp();
		} break;

		case VK_DOWN:
		{
			((Game*)game)->rackets[0].MoveDown();

		} break;

		case VK_W_KEY:
		{
			((Game*)game)->rackets[1].MoveUp();

		} break;
		
		case VK_S_KEY:
		{
			((Game*)game)->rackets[1].MoveDown();
		} break;

		default:
		{		
		}
	}
}