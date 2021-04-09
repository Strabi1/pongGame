
#pragma once
#include <windows.h>

class Pos
{
private:
	
protected:
	UINT32 x = 0, y = 0;

public:
	Pos();
	Pos(UINT32 x, UINT32 y);
	~Pos();

	void SetX(UINT32 x);
	void SetY(UINT32 y);
	void SetXY(UINT32 x, UINT32 y);
	UINT32 GetX(void);
	UINT32 GetY(void);
};
