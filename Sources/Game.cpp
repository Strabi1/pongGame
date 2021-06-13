
#include <stdio.h>
#include "Game.h"

Game::Game(KeySensor *key, Draw *draw) : keySensor{key}, draw{draw}
{
	keySensor->game = (void*)this;
}

Game::~Game()
{
}

void Game::Init()
{
	draw->ClearWindow(0xFF0000);
	draw->MakeBorder(10, 0x00FF11);
	rackets[0].Init();
	rackets[1].Init();
	ball.Init();
}