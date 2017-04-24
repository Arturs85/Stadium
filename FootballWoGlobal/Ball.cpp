#pragma once
//#include <Windows.h>
#include <iostream>
//#include <sstream>
#include "pch.h"
#include <math.h>
#include "Field.h"
#include "MainPage.xaml.h"
#include "Ball.h"
#include "Game.h"
using namespace std;
using namespace FootballWoGlobal;

//extern  MainPage^ mainpagee;
//Ball::Ball(Microsoft::Graphics::Canvas::CanvasRenderTarget^ ofscreen, int r):Ball(offscreen, game->field,r) {


//}



 Ball::Ball(Microsoft::Graphics::Canvas::CanvasRenderTarget^ ofscreen, Field* field, int r)
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
 Ball::Ball(Microsoft::Graphics::Canvas::CanvasRenderTarget^ ofscreen) {
	//Ball(offscreen, (game->field), r);
	this->offscreen = ofscreen;
	//this->game = gam;
	this->field = game->field;
	this->r = 13;
	x = 200;
	y = 200;

	//color = Colors::Yellow;
	speed = 0;
	slowdown = 1;
	dir = 0;
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
	if (speed == 0) return;
	bool is_in = field->isInside(x, y, r);

	x += speed*cos(dir);
	y -= speed*sin(dir);
	speed = speed<slowdown ? 0 : speed - slowdown;

	bool will_be_in = field->isInside(x, y, r);

	char buf[256];
	/*sprintf_s(buf, "X=  %d ", x);
	OutputDebugStringA(buf);
	sprintf_s(buf, "Y=  %d \n",y);
	OutputDebugStringA(buf);*/



	if (is_in && !will_be_in) {
		double dirTemp = dir;

		if (field->isOutRight(x, y, r) || field->isOutLeft(x, y, r)) dir = 3.1415 - dir;

		if (field->isOutSide(x, y, r)) dir = -dir;
		x -= speed*cos(dirTemp); //paiet soli atpakal, ja ir jau aiz malas
		y += speed*sin(dirTemp);
		if (!field->isInside(x, y, r)) {
			x -= speed*cos(dirTemp); //paiet soli atpakal, ja ir jau aiz malas- otra pârbaude --partaisit
			y += speed*sin(dirTemp);
		}
		sprintf_s(buf, "Robeza X=  %d ", x);
		OutputDebugStringA(buf);
		sprintf_s(buf, "Y=  %d \n", y);
		OutputDebugStringA(buf);
	}
}

bool Ball::isColided(int x, int y, int r) //vai blakus ir kermenis ar dotajam koordinatam
{
	int k1 = pow(this->x - x, 2);
	int k2 = pow(this->y - y, 2);
	if (sqrt(k1 + k2) > this->r + r)
		return false;
	else
		return true;
}
