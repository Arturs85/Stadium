#include <pch.h>
#include <math.h>
#include "HalfBack.h"
#include "Field.h"
#include "Ball.h"
#include "MainPage.xaml.h"
#include "Referee.h"
#include "functions.h"
#include <game.h>

//extern TFG_Frm *FG_Frm;

HalfBack::HalfBack(int t, int n) : Player(t, n)
{
	speed = 10;
	area = *(game->field->fieldRect);
	type = tHalfBack;
}

void HalfBack::kick()
{
	int xb, yb, xc, yc, xd, yd;
	double dirb, dirdisp = PI / 8;
	int kickSpeed = 20;
	game->ball->getCoord(xb, yb);
	game->field->getCentre(xc, yc);
	yd = yb;
	if (teamNo == 1) {
		xd = game->field->fieldRect->Right;
	}
	else {
		xd = game->field->fieldRect->Left;
	}
	if (distance(xb, yb, xd, yd) <= 3 * kickSpeed) {
		yd = yc;
		dirdisp = 0;
	}

	dirb = direction(xb, yb, xd, yd);
	dirb = disperse(dirb, dirdisp);
	game->ball->setDir(dirb);
	game->ball->setSpeed(disperse(kickSpeed, kickSpeed / 2));
	sound = 1;
}


