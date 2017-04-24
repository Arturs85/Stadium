#include <pch.h>
#include <math.h>
#include "AssReferee.h"
#include "Ball.h"
#include "MainPage.xaml.h"
#include "Game.h"

//extern TFG_Frm *FG_Frm;

AssReferee::AssReferee()
{
	//aCanvas = FG_Frm->FieldImage->Canvas;
	type = tAssReferee;
	color = Colors::Lime;
	speed = 2;
}

void AssReferee::move()
{
	int xb, yb;
	game->ball->getCoord(xb, yb);
	int delta = (abs(xb - x));
	delta = delta > 0 ? delta : 1;
	delta = rand() % delta;
	delta = delta>5 ? 5 : delta;
	if (x < xb) x += speed + delta;
	if (x > xb) x -= speed + delta;
}
