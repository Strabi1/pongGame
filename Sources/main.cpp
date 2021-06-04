
#include "AppWindow.h"
#include "Draw.h"
#include "Rechtangle.h"

#include "MessageHandler.h"
#include "Ball.h"
#include "Racket.h"
#include "Game.h"

#include <stdio.h>

int main()
{
	KeySensor keySensor;
	AppWindow app;

	if (!app.init())
		return -1;

	Draw draw(&app);
	Ball ball(Pos(500,500));
	MessageHandler messageHnd(&app, &keySensor);
	Game game(&keySensor, &draw);

	printf("Window->height: %d, Window->width: %d\n", app.getWindowHeight(), app.getWindowWidth());
	draw.ClearWindow(0xFF0000);
	draw.MakeBorder(10, 0x00FF11);
	draw.DrawRechtangle(ball.pos.x, ball.pos.y, ball.size, ball.size, ball.color);
	
	while (app.isRun())
	{
		Sleep(100);
		messageHnd.PollMessages();		
	}

	return 0;
}