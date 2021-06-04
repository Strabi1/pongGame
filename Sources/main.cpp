/*MIT License

C++ 3D Game Tutorial Series (https://github.com/PardCode/CPP-3D-Game-Tutorial-Series)

Copyright (c) 2019-2020, PardCode

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.*/

#include "AppWindow.h"
#include "Draw.h"
//#include "Game.h"
//#include "Game/Ball.h"
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
	//Racket rackets[] = {Pos(100, 500), Pos(1000, 500)};

	Rechtangle rechtangle(draw);
	MessageHandler messageHnd(&app, &keySensor);

	Game game(&keySensor, &draw);

	rechtangle.pos.x = 456;

	/*Rechtangle *clone = rechtangle.Clone();

	Rechtangle clone2(rechtangle);

	printf("Clone->pps.x: %d\n", clone->pos.x);
	printf("Clone2.pos.x: %d\n", clone2.pos.x);*/

	
	printf("Window->height: %d, Window->width: %d\n", app.getWindowHeight(), app.getWindowWidth());
	draw.DrawRechtangle(rechtangle.pos.x, rechtangle.pos.y, rechtangle.width, rechtangle.height, rechtangle.color);
	
	while (app.isRun())
	{
		draw.ClearWindow(0xFF0000);
		draw.MakeBorder(10, 0x00FF11);

		draw.DrawRechtangle(ball.pos.x, ball.pos.y, ball.size, ball.size, ball.color);

		//draw.DrawRechtangle(rackets[0].pos.x, rackets[0].pos.y, rackets[0].height, rackets[0].width, rackets[0].color);
		//draw.DrawRechtangle(rackets[1].pos.x, rackets[1].pos.y, rackets[1].height, rackets[1].width, rackets[1].color);

		rechtangle.Resize(rechtangle.width + 5, rechtangle.height + 5);
		Sleep(500);

		messageHnd.PollMessages();		
	}


	return 0;
}