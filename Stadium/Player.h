#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include "human.h"
//#include "MainPage.xaml.h"
class Game;
class Player : public Human
{
protected:
	int teamNo;
	int No;
	Rect area;
	//Font *font;
	int sound;
	//CanvasRenderTarget^ offscreen;
public:
	Player(CanvasRenderTarget^ offScreen, int t, int n);
	Player(int t, int n);
	virtual void move();
	virtual void draw();
	virtual void kick();
	void avoidCollision();
	bool inGame;
	void moveToBench();
	Point& partner();
};
#endif
