
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
	MessageHandler messageHnd(&app, &keySensor);
	Game game(&keySensor, &draw);

	printf("Window->height: %d, Window->width: %d\n", app.getWindowHeight(), app.getWindowWidth());
	
	game.Init();

	while (app.isRun())
	{
		Sleep(100);
		game.ball.Move(100);
		messageHnd.PollMessages();		
	}

	return 0;
}