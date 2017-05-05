#include <pch.h>
#include "Lights.h"
#include "Field.h"
#include "Game.h"
#include "Functions.h"
#include "MainPage.xaml.h"
 
 

 //using namespace Numerics;
Lights::Lights(int xp, int yp, int towerH,
	double foc,
	double dir1, double dir2,
	double tilt1, double tilt2)
{
	//aCanvas = FG_Frm->FieldImage->Canvas;
	x = xp;
	y = yp;
	dir = dir1;
	dirStart = dir1;
	dirEnd = dir2;
	dirSpeed = PI / 64;
	focus = foc;
	towerHeight = towerH;
	tilt = tilt1;
	tiltStart = tilt1;
	tiltEnd = tilt2;
	tiltSpeed = PI / 48;
	on = false;
}

void Lights::draw()
{
	if (!on) return;
	 	poly2 = ref  new Platform::Array<float2>(3);
	//Point poly[3];
	poly2[0].x=x;
	poly2[0].y=y;
	int dist = towerHeight*tan(tilt);
	int xspot = x + dist*cos(dir);
	int yspot = y - dist*sin(dir);
	int d1 = dist / sin(tilt);

	int spotLength = towerHeight*tan(tilt - focus / 2) - towerHeight*tan(tilt + focus / 2);
	int spotWidth = 2 * d1*tan(focus / 2);

	int x1 = xspot - spotWidth / 2 * sin(dir);
	int y1 = yspot - spotWidth / 2 * cos(dir);
	int x2 = xspot + spotWidth / 2 * sin(dir);
	int y2 = yspot + spotWidth / 2 * cos(dir);

	poly2[1].x = x1;
	poly2[1].y = y1;
	poly2[2].x = x2;
	poly2[2].y = y2;



//	TColor currPenColor = aCanvas->Pen->Color;
//	TColor currBrushColor = aCanvas->Brush->Color;
	//TBrushStyle currBrushStyle = aCanvas->Brush->Style;

	//aCanvas->Brush->Color = clYellow;
//	aCanvas->Pen->Color = clYellow;
	//aCanvas->Brush->Style = bsSolid;
	CanvasDrawingSession^  clds = game->clds;//offscreen->CreateDrawingSession();
	//clds->Polygon(poly2, 2);
	
	//CanvasGeometry^ cgm = ref new CanvasGeometry();
	//CanvasGeometry::CreatePolygon(clds,poly2);
	clds->FillGeometry(CanvasGeometry::CreatePolygon(clds, poly2), Colors::YellowGreen);
	//aCanvas->Brush->Color = clLime;
	//aCanvas->Pen->Color = clLime;
	//aCanvas->Pen->Width = 1;
	//aCanvas->Brush->Style = bsSolid;

	angellipse(clds, xspot, yspot, spotLength / 2, 0, 2 * PI, dir, spotWidth*1.0 / spotLength);
//	delete clds;

}

void Lights::move()
{
	if (dir >= dirStart && dirSpeed>0) dirSpeed = -PI / 64;
	if (dir <= dirEnd && dirSpeed<0) dirSpeed = PI / 64;
	dir += dirSpeed;
	if (tilt <= tiltStart && tiltSpeed<0) tiltSpeed = PI / 48;
	if (tilt >= tiltEnd && tiltSpeed>0) tiltSpeed = -PI / 48;
	tilt += tiltSpeed;
}

