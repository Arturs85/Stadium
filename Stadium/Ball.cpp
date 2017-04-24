#pragma once
//#include <Windows.h>
#include <iostream>
//#include <sstream>
#include "pch.h"
#include <math.h>
#include "Field.h"
#include "MainPage.xaml.h"
#include "Ball.h"
#include "game.h"
using namespace std;
//using namespace Stadium;

//extern  MainPage^ mainpagee;

Ball::Ball(Microsoft::Graphics::Canvas::CanvasRenderTarget^ ofscreen,Field* field,int r)
{
	
	this->offscreen = ofscreen;
	this->field = field;
	this->r = r;
	x = 200;
	y = 200;

	//color = Colors::Yellow;
	speed = 0;
	slowdown = 1;
	dir = 0;
	//comandList = ref new CanvasCommandList(sender);
	 	//clds = offscreen->CreateDrawingSession();
}



void Ball::draw()
{
	clds = offscreen->CreateDrawingSession();
	clds->FillCircle(x, y, r, Colors::Crimson);
	//clds->(IDisposable)Dispose();
	delete clds;

	//return offscreen;
	//aCanvas->Pen->Color = color;
	//aCanvas->Brush->Color = color;
	//aCanvas->Brush->Style = bsSolid;
	//aCanvas->Ellipse(x - r, y - r, x + r, y + r);
}

void Ball::move()
{
	//if (speed == 0) return;
	//bool is_in = field->isInside(x, y,r);

	//x += speed*cos(dir);
	//y -= speed*sin(dir);
	//speed = speed<slowdown ? 0 : speed - slowdown;

	//bool will_be_in = field->isInside(x, y,r);
	//
	//char buf[256];
	///*sprintf_s(buf, "X=  %d ", x);
	//	OutputDebugStringA(buf);
	//sprintf_s(buf, "Y=  %d \n",y);
	//	OutputDebugStringA(buf);*/



	//if (is_in && !will_be_in) {
	//	double dirTemp = dir;

	//	if (field->isOutRight(x, y, r) || field->isOutLeft(x, y, r)) dir = 3.1415 - dir;

	//	if (field->isOutSide(x, y, r)) dir = -dir;
	//	x -= speed*cos(dirTemp); //paiet soli atpakal, ja ir jau aiz malas
	//	y += speed*sin(dirTemp);
	//	if (!field->isInside(x, y, r)) {
	//	x -= speed*cos(dirTemp); //paiet soli atpakal, ja ir jau aiz malas- otra pârbaude --partaisit
	//	y += speed*sin(dirTemp);
	//}
	//	sprintf_s(buf, "Robeza X=  %d ", x);
	//	OutputDebugStringA(buf);
	//	sprintf_s(buf, "Y=  %d \n",y);
	//	OutputDebugStringA(buf);
	//}

	if (speed == 0) return;
	bool is_in = game->field->isInside(x, y);
	x += speed*cos(dir);
	y -= speed*sin(dir);
	bool willbe_in = game->field->isInside(x, y);

	speed = speed<slowdown ? 0 : speed - slowdown;

	int xc, yc, wg, hg;
	game->field->getCentre(xc, yc);
	game->field->getGoalArea(wg, hg);

	if (game->field->isGoalLeft(x, y)) { x = game->field->fieldRect->Left - 4 * r; return; }
	if (game->field->isGoalRight(x, y)) { x = game->field->fieldRect->Right + 4 * r; return; }
	if (is_in && !willbe_in) {
		if (game->field->isOutSide(x, y)) dir = 2 * PI - dir;
		if (game->field->isOutRight(x, y)) {
			moveTo(game->field->fieldRect->Right - wg, yc);
			speed = 0;
		}
		if (game->field->isOutLeft(x, y)) {
			moveTo(game->field->fieldRect->Left + wg, yc);
			speed = 0;
		}
	}

}

bool Ball::isColided(int x, int y, int r) //vai blakus ir kermenis ar dotajam koordinatam
{
	int k1 = pow(this->x-x,2);
	int k2 = pow(this->y - y,2);
	if (sqrt(k1 + k2) > this->r + r)
		return false;
	else
		return true;
}
