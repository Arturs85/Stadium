#include <pch.h>
#include <math.h>
#include "Forward.h"
#include "Field.h"
#include "Ball.h"
#include "MainPage.xaml.h"
#include "Referee.h"
#include "Game.h"

//extern TFG_Frm *FG_Frm;

Forward::Forward(int t, int n) : Player(t, n)
{
	speed = 10;
	area = *(game->field->fieldRect);
	type = tForward;
}

/*
void Forward::kick()
{
int xb, yb, xc, yc;
FG_Frm->ball->getCoord(xb, yb);
FG_Frm->field->getCentre(xc, yc);

if (teamNo==1) xc = FG_Frm->field->fieldRect->left;
else  xc = FG_Frm->field->fieldRect->right;
int deltaX = xc-xb;
int deltaY = yc-yb;
if (deltaX==0) dir = PI/2;
else dir = atan(double(deltaY)/ deltaX);
if (xc>xb) dir += PI;
dir += 1.0/(random(90)+10);
FG_Frm->ball->setDir(dir);
FG_Frm->ball->setSpeed(30);
}
*/

