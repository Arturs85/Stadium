#include <pch.h>
#include <math.h>
#include "Referee.h"
#include "Field.h"
#include "Ball.h"
#include "MainPage.xaml.h"
#include "functions.h"
#include "Game.h"
//extern TFG_Frm *FG_Frm;
//using namespace Stadium;

Referee::Referee()
{
	//aCanvas = FG_Frm->FieldImage->Canvas;
	type = tReferee;
	color = Colors::Yellow;
	speed = 0;
}

void Referee::move()
{
	int xb, yb;
	game->ball->getCoord(xb, yb);
	dir = direction(x, y, xb, yb);
	dir = disperse(dir, PI / 8);
	if (distance(x, y, xb, yb)<50) { speed = 3 + rand()%3; dir = -dir; }  //?rand?
	else speed = 3 + rand()%3;					//?rand?
	x += speed*cos(dir);
	y -= speed*sin(dir);

}
