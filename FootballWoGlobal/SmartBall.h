#pragma once
#include "Ball.h"

class SmartBall : public Ball
{
public:
	SmartBall(Microsoft::Graphics::Canvas::CanvasRenderTarget^ rt, Field* field, int r, Ball* ball);
	virtual ~SmartBall();
	virtual void move();

private:
	Ball* ball;
	//int& ballX;
	//int& ballY;
};

#pragma once
