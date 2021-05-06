
#include <stdio.h>
#include "Game.h"

Game::Game(KeySensor *key) : keySensor{key} {
	keySensor->game = (void*)this;
}

Game::~Game()
{
}

void Game::teszt()
{
	printf("dfdfd\n");
}