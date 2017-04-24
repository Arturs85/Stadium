#include <pch.h>
#include <math.h>
#include "FullBack.h"
#include "Field.h"
#include "Ball.h"
#include "MainPage.xaml.h"
#include "Referee.h"
#include "functions.h"
#include <game.h>
//extern Tgame *game;

FullBack::FullBack(int t, int n) : Player(t, n)
{
	speed = 5;
	int xc, yc;
	game->field->getCentre(xc, yc);
	if (teamNo == 1)  area = Rect(game->field->fieldRect->Left, game->field->fieldRect->Top,
		(game->field->fieldRect->Width)/2, game->field->fieldRect->Height);
	else            area = Rect(xc, game->field->fieldRect->Top,
		(game->field->fieldRect->Width) / 2, game->field->fieldRect->Height);
	type = tFullBack;
}

void FullBack::move()
{
	if (!inGame) {
		moveToBench(); return;
	}
	int close = 2 * r;
	int xb, yb, xc, yc, xd, yd;
	game->ball->getCoord(xb, yb);
	game->field->getCentre(xc, yc);

	energy = energy>0 ? --energy : 0;
	speed = 3;// + rand(energy / 1000);

	xd = xb; yd = yb;
	if (teamNo == 1 && xb>xc) { xd = disperse(xc / 2, xc / 4); yd = random(2 * yc); }
	if (teamNo == 2 && xb<xc) { xd = disperse(xc + xc / 2, xc / 4);  yd = random(2 * yc); }

	dir = direction(x, y, xd, yd);
	//dir = disperse(dir, PI/6);

	x += speed*cos(dir);
	y -= speed*sin(dir);
	if (x<area.Left) x = area.Left + 2 * r;
	if (x>area.Right) x = area.Right - 2 * r;

	avoidCollision();

	if (distance(x, y, xb, yb)<close) kick();
}

void FullBack::kick()
{
	int xb, yb, xc, yc;
	game->ball->getCoord(xb, yb);
	game->field->getCentre(xc, yc);

	if (teamNo == 1) xc = game->field->fieldRect->Right;
	else  xc = game->field->fieldRect->Left;
	double dirb = direction(xb, yb, xc, yc);
	dirb = disperse(dirb, PI / 8);
	game->ball->setDir(dirb);
	game->ball->setSpeed(30);
	sound = 1;
}


