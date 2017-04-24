#include "pch.h"

//#include <vcl.h>
#include "Field.h"
//#include "Form.h"

//extern TForm1 *Form1;
using namespace Windows::Foundation;

Field::Field()
{
	//aCanvas = Form1->FieldImage->Canvas;

	fieldRect = new Rect(0, 0,
		800,
		500);// izmçrus òemt no mainpage xaml
	borderWidth = 800 / 20;//mainpage->FieldImage->Height / 20;

	h = fieldRect->Height;
	w = fieldRect->Width;
	x_c = w / 2;
	y_c = h / 2;


	goalWidth = h / 8;
	goalAreaH = goalWidth * 2;
	goalAreaW = goalWidth*0.75;

}

void Field::draw()
{
	//aCanvas->Brush->Color = clGreen;
	//aCanvas->Brush->Style = bsSolid;
	//aCanvas->FillRect(*fieldRect);
	//drawLines();
}

void Field::drawLines()
{
	/*aCanvas->Brush->Style = bsClear;
	aCanvas->Pen->Color = clWhite;
	aCanvas->Rectangle(*fieldRect);
	aCanvas->MoveTo(x_c, fieldRect->bottom - 1);
	aCanvas->LineTo(x_c, fieldRect->top);
	aCanvas->Ellipse(x_c - 45, y_c - 45, x_c + 45, y_c + 45);
	aCanvas->Brush->Color = clWhite;
	aCanvas->Ellipse(x_c - 2, y_c - 2, x_c + 2, y_c + 2);*/
}

bool Field::isInside(int x, int y, int& r)
{
	return x >= fieldRect->Left + r && x <= fieldRect->Right - r && y >= fieldRect->Top + r && y <= fieldRect->Bottom - r;
}

bool Field::isOutSide(int x, int y, int& r)
{
	return y < fieldRect->Top + r || y > fieldRect->Bottom - r;
}

bool Field::isOutLeft(int x, int y, int& r)
{
	return x < fieldRect->Left + r;
}

bool Field::isOutRight(int x, int y, int& r)
{
	return x > fieldRect->Right - r;
}

