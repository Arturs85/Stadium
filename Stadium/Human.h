#pragma once

//#include "MainPage.xaml.h"

using namespace Windows::UI;
using namespace Microsoft::Graphics::Canvas;
using namespace Windows::Foundation;

//#ifndef HUMAN_H
//#define HUMAN_H

enum htype {
	tReferee, tAssReferee,
	tGoalkeeper, tForward,
	tHalfBack, tQuarterBack, tFullBack, tGirl
};
class Game;
class Human
{
protected:
	int x;
	int y;
	int r;
	Color color;
	int speed;
	int energy;
	double dir;
	CanvasRenderTarget^ offscreen;
public:
	Human(CanvasRenderTarget^);
	Human();
	htype type;
	void setSpeed(int s) { speed = s; }
	void setDir(double d) { dir = d; }
	void setEnergy(int e) { energy = e; };
	int getEnergy() { return energy; };
	Point getPos() { return Point(x, y); }
	double getDir() { return dir; }
	int getSpeed() { return speed; }
	virtual void draw();
	virtual void move() = 0;
	void moveTo(int x, int y);
};
//#endif