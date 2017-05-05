#pragma once
using namespace Microsoft::Graphics::Canvas::Geometry;
using namespace Windows::Foundation::Numerics;
//class float2;
class Lights
{
private:

	int x;
	int y;
	double dir;
	double dirStart, dirEnd;
	double dirSpeed;
	double focus;
	int towerHeight;
	double tilt;
	double tiltStart, tiltEnd;
	double tiltSpeed;
	//TCanvas *aCanvas;
	// Platform::Array<float2>^ poly2;
public:
	Platform::Array<float2>^ 	poly2;
	bool on;
	Lights(int xp, int yp, int towerH,
		double foc,
		double dir1, double dir2,
		double tilt1, double tilt2);
	void draw();
	void move();
	void moveTo(int xTo, int yTo) { x = xTo; y = yTo; }
};
