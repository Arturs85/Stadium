#pragma once

using namespace Windows::Foundation;
//class Game;
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
	Microsoft::Graphics::Canvas::CanvasCommandList^ cl;
	Windows::UI::Color lineColor; 
	Microsoft::Graphics::Canvas::CanvasCommandList^ rtGoalNetTile;
	Microsoft::Graphics::Canvas::Brushes::CanvasImageBrush^ goalNetBrush;
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

	bool isInside(int x, int y);
	bool isOutSide(int x, int y);

	bool isOutLeft(int x, int y);
	bool isOutRight(int x, int y);
	
	
	int getBorderW() { return borderWidth; }
	void getGoalArea(int& w, int& h) { w = goalAreaW; h = goalAreaH; }
	
	bool isGoalLeft(int x, int y);
	bool isGoalRight(int x, int y);
	
};
