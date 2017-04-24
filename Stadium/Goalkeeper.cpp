
#include <pch.h>
#include <math.h>
#include "Goalkeeper.h"
#include "Field.h"
#include "Ball.h"
#include "MainPage.xaml.h"
#include "Referee.h"
#include "functions.h"
#include "Game.h"
//extern TFG_Frm *FG_Frm;

Goalkeeper::Goalkeeper(int t, int n) : Player(t, n)
{
	speed = 1;
	color = t == 1 ? Colors::LightGray : Colors::Maroon;
	int xc, yc;
	game->field->getCentre(xc, yc);
	int gw, gh;
	game->field->getGoalArea(gw, gh);
	if (teamNo == 1)  area = Rect(game->field->fieldRect->Left, yc - gh / 2,
		 gw, gh );
	else            area = Rect(game->field->fieldRect->Right - gw, yc - gh / 2,
		gw,  gh );
	type = tGoalkeeper;
}

void Goalkeeper::move()
{
	int close = 2 * r;
	int xb, yb;
	game->ball->getCoord(xb, yb);

	speed = 5;// + random(5);          //

	dir = direction(x, y, xb, yb);
	dir = disperse(dir, PI / 8);

	x += speed*cos(dir);
	y -= speed*sin(dir);

	if (x<area.Left) x = area.Left + 2 * r;
	if (x>area.Right) x = area.Right - 2 * r;
	if (y<area.Top) y = area.Top + 2 * r;
	if (y>area.Bottom) y = area.Bottom - 2 * r;

	avoidCollision();

	if (distance(x, y, xb, yb)<close) kick();
}

void Goalkeeper::kick()
{
	int xb, yb, xc, yc;
	game->ball->getCoord(xb, yb);
	game->field->getCentre(xc, yc);

	if (teamNo == 1) xc = game->field->fieldRect->Right;
	else  xc = game->field->fieldRect->Left;
	double dirb = direction(xb, yb, xc, yc);
	dirb = disperse(dirb, PI / 4);
	game->ball->setDir(dirb);
	game->ball->setSpeed(40);
	sound = 3;
}



