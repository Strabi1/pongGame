
#pragma once

#include <Windows.h>
#include "Observable.h"
#include "KeySensor.h"


class Window : public Observable
{
public:
	void* buffer_memory = NULL;
	
	Window();
	//Initialize the window
	bool init();
	bool broadcast(MSG *msg);
	//Release the window
	bool release();
	bool isRun();

	//EVENTS
	virtual void onCreate();
	virtual void onUpdate();
	virtual void onDestroy();
	void onResize(HWND hwnd);

	int getWindowWidth();
	int getWindowHeight();

	~Window();
protected:
	HWND m_hwnd;
	bool m_is_run;
	BITMAPINFO buffer_bitmap_info;
	int buffer_width = 0;
	int buffer_height = 0;
	HDC hdc;
};

