#include"pch.h"
#include "SmartBall.h"
#include <math.h>
#include "Ball.h"
# include "MainPage.xaml.h" 
//extern MainPage^ mainPage;
SmartBall::SmartBall(Microsoft::Graphics::Canvas::CanvasRenderTarget^ rt, Field* field, int r, Ball* ball) : Ball(rt, field, r)
{
	slowdown = 0;
	speed = 4;
	this->ball = ball;
	//ball->getCoord(ba, ballY);
	x = 100;
	y = 400;
}

SmartBall::~SmartBall()
{
}

void SmartBall::move() {

	if (speed == 0) return;
	bool isColided = ball->isColided(x, y, r);

	dir = atan2(y - ball->getY(), ball->x - x); // virziens uz bumbu
	x += speed*cos(dir);
	y -= speed*sin(dir);
	speed = speed < slowdown ? 0 : speed - slowdown;

	bool willColide = ball->isColided(x, y, r);

	char buf[256];
	/*sprintf_s(buf, "X=  %d ", x);
	OutputDebugStringA(buf);
	sprintf_s(buf, "Y=  %d \n",y);
	OutputDebugStringA(buf);*/



	if (willColide) {

		x -= speed*cos(dir);
		y += speed*sin(dir);
		ball->setDir(dir + 0.2);
		ball->setSpeed(40);

	}



}