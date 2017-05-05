#pragma once
#include "Field.h"
using namespace Windows::UI;
using namespace Microsoft::Graphics::Canvas;



//namespace Stadium
//{ 
class Ball
{
protected:
	//int x;
	int y;
	int r;
	//Colors^ color;
	int speed;
	int slowdown;
	double dir;
	Microsoft::Graphics::Canvas::UI::Xaml::CanvasAnimatedControl^ mCanvasControl;
	//CanvasDevice ^ comandList;
	//CanvasDrawingSession^ 	clds;
	CanvasCommandList^ offscreen;
	//TCanvas *aCanvas;
public:
	Field* field;

	virtual ~Ball() {  delete offscreen; }
	int x;
	Ball();
	Ball(Microsoft::Graphics::Canvas::CanvasCommandList^ );
	void setSpeed(int s) { speed = s; }
	int getSpeed() { return speed; }
	void setDir(double d) { dir = d; }
	double getDir() { return dir; }
	void draw();
	virtual void move();
	void moveTo(int xTo, int yTo) { x = xTo; y = yTo; }
	void getCoord(int& xb, int& yb) { xb = x; yb = y; }
	int& getY(){ return y; }
	bool isColided(int x, int y, int r);
};
//}