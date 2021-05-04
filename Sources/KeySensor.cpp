
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

typedef void KeyFunciton(void);

typedef struct
{
	UINT8 key;
	KeyFunciton *function;
	UINT8 state;
}KeyAction;

void f1(void)
{
	printf("---- %s\n", __FUNCTION__);
}
void f2(void)
{
	printf("---- %s\n", __FUNCTION__);
}
void f3(void)
{
	printf("---- %s\n", __FUNCTION__);
}
void f4(void)
{
	printf("---- %s\n", __FUNCTION__);
}

KeyAction keyAction[] = 
{
	{VK_UP,		f1,		0},
	{VK_DOWN,	f2,		0},
	{VK_LEFT, 	f3,		0},
	{VK_RIGHT,	f4,		0}
};

void executeKeyAction(UINT8 key, ButtonState buttonState)
{
	for (auto &&i : keyAction)
	{
		if(i.key == key)
		{
			i.state = ((i.state & 0x01) << 1) | buttonState;

			if(i.state == BUTTON_PRESSED)
			{
				i.function();
			}

			return;
		}
	}
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
		case VK_DOWN:
		case VK_LEFT:
		case VK_RIGHT:
		{
			executeKeyAction(vk, buttonState);
			/*
			upKey = ((upKey & 0x01) << 1) | buttonState;
			printf("VK_UP: %d\n", upKey);

			if(upKey == BUTTON_PRESSED)
			{
				printf("press\n");
			}	
			*/
		} break;

		default:
		{		
		}
	}
}