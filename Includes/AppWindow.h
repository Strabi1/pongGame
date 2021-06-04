
#pragma once
#include "Window.h"
#include "KeySensor.h"
#include "Game.h"

class AppWindow: public Window
{
public:
	AppWindow();
	~AppWindow();

	// Inherited via Window
	virtual void onCreate() override;
	virtual void onUpdate() override;
	virtual void onDestroy() override;

private:

};

