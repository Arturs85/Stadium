#include <pch.h>
#include <math.h>
#include "Girl.h"
#include "MainPage.xaml.h"
#include "Field.h"
#include "Functions.h"
#include "Game.h"
//extern TFG_Frm *FG_Frm;

Girl::Girl()
{
	//aCanvas = FG_Frm->FieldImage->Canvas;
	type = tGirl;
	color = Colors::Fuchsia;
	speed = 5;
}

void Girl::move()
{
	int xc, yc;
	game->field->getCentre(xc, yc);
	if (speed>0 && y<100) speed = 3; else speed = -7;
	y += speed;
	if (y<5) {
		game->gameState = sRestartGame;
		r = 3;
		speed = 5;
	}
}
void Girl::draw()
{
	if (game->gameState == sPause) {
		r = (r == 3) ? 4 : 3;
	}
	Human::draw();

}
