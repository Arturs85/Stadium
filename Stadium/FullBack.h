#pragma once
#include "Player.h"
class FullBack : public Player
{
protected:

public:
	FullBack(int t, int n);
	void move();
	void kick();
};

