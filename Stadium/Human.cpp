#include <pch.h>
#include <math.h>
//#include "FG_Frm.h"
#include "Field.h"
#include "Human.h"
//#include <mmsystem.hpp>
//extern TFG_Frm *FG_Frm;
#include "MainPage.xaml.h"
#include "Game.h"

//using namespace Stadium;

Human::Human(CanvasRenderTarget^ offScreen)
{
	this->offscreen = offScreen;
	r = 3;
	speed = 0;
	energy = 0;
	dir = 0;

}
Human::Human() {
	this->offscreen = game->offscreen;
	color = Colors::Azure;
	r = 3;
	speed = 0;
	energy = 0;
	dir = 0;

}

void Human::moveTo(int xTo, int yTo)
{
	
	x = xTo; y = yTo;
}

void Human::draw()
{
	CanvasDrawingSession^ clds = offscreen->CreateDrawingSession();
	clds->FillCircle(x, y, r, color);
	
	delete clds;
	

}

