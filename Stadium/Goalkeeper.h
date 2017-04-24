#pragma once
#include "Player.h"
class Game;
class Goalkeeper : public Player
{
protected:

public:
	Goalkeeper(int t, int n);
	void move();
	void kick();
};

