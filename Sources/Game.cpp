
#include <stdio.h>
#include "Game.h"

Game::Game(KeySensor *key, Draw *draw) : keySensor{key}, draw{draw}
{
	keySensor->game = (void*)this;
}

Game::~Game()
{
}

void Game::teszt()
{
	printf("dfdfd\n");
}