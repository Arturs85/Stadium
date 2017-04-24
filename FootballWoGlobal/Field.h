#pragma once

using namespace Windows::Foundation;

class Field
{
private:
	float h;
	float w;
	int x_c;
	int y_c;
	int borderWidth;

	int goalWidth;
	int goalAreaW;
	int goalAreaH;

	//	TCanvas *aCanvas;

public:
	Rect *fieldRect;
	Field();
	void getCentre(int& x, int& y) { x = x_c; y = y_c; }
	int getH() { return h; }
	int getW() { return w; }
	void draw();
	void drawLines();
	bool isInside(int x, int y, int& r);
	bool isOutSide(int x, int y, int& r);
	bool isOutLeft(int x, int y, int& r);
	bool isOutRight(int x, int y, int& r);
	int getBorderW() { return borderWidth; }

};
