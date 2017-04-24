#include "pch.h"

//#include <vcl.h>
#include "Field.h"
//#include "Form.h"
#include "MainPage.xaml.h"
#include "Game.h"
//extern Game *game;
using namespace Windows::Foundation;

Field::Field()
{
	cl = game->cl;  // comand list zîmçðanai
borderWidth = 800/20;//mainpage->FieldImage->Height / 20;
	fieldRect = new Rect(borderWidth, borderWidth,   
		800,
		500);// izmçrus òemt no mainpage xaml
	lineColor = Colors::AntiqueWhite;

	h = fieldRect->Height;
	w = fieldRect->Width;
	x_c = w / 2+borderWidth;
	y_c = h / 2+borderWidth;

	goalWidth = h / 8;
	goalAreaH = goalWidth * 2;
	goalAreaW = goalWidth*0.75;

}

void Field::draw()
{
	CanvasDrawingSession^ 	clds = cl->CreateDrawingSession();

	//TColor currPenColor = aCanvas->Pen->Color;
	//TColor currBrushColor = aCanvas->Brush->Color;
	//TBrushStyle currBrushStyle = aCanvas->Brush->Style;

	//aCanvas->Brush->Color = clBlack;
	//aCanvas->Brush->Style = bsSolid;
	//aCanvas->FillRect(Rect(0, 0, FG_Frm->FieldImage->Width, FG_Frm->FieldImage->Height));
	clds->FillRectangle(Rect(0, 0, fieldRect->Width + borderWidth*2, fieldRect->Height + borderWidth*2),Colors::Black);
	//aCanvas->Brush->Color = clGreen;
	//aCanvas->Brush->Style = bsSolid;
	//aCanvas->FillRect(*fieldRect);
	clds->FillRectangle(*fieldRect, Colors::Green);
	//aCanvas->Brush->Style = currBrushStyle;
	//aCanvas->Pen->Color = currPenColor;
	//aCanvas->Brush->Color = currBrushColor;
	
	//TColor currPenColor = aCanvas->Pen->Color;
//	TColor currBrushColor = aCanvas->Brush->Color;
	//TBrushStyle currBrushStyle = aCanvas->Brush->Style;
	//aCanvas->Brush->Style = bsClear;
	//aCanvas->Pen->Color = clWhite;
	//aCanvas->Rectangle(*fieldRect);
	clds->DrawRectangle(*fieldRect, Colors::Wheat, 5);
	clds->DrawLine(x_c, fieldRect->Bottom, x_c, fieldRect->Top, Colors::AntiqueWhite, 5);
	clds->DrawCircle(x_c, y_c, 100, Colors::AntiqueWhite , 5);
	clds->DrawRectangle(fieldRect->Left, y_c - goalAreaH / 2, goalAreaW,  goalAreaH,lineColor);
	clds->DrawRectangle(fieldRect->Right - goalAreaW, y_c - goalAreaH / 2, goalAreaW, goalAreaH, lineColor);

	
	/*aCanvas->MoveTo(x_c, fieldRect->bottom - 1);
	aCanvas->LineTo(x_c, fieldRect->top);
	aCanvas->Ellipse(x_c - 45, y_c - 45, x_c + 45, y_c + 45);
	aCanvas->Brush->Color = clWhite;
	aCanvas->Ellipse(x_c - 2, y_c - 2, x_c + 2, y_c + 2);

	aCanvas->Brush->Color = clWhite;
	aCanvas->Brush->Style = bsDiagCross;
	aCanvas->FillRect(Rect(0, y_c - goalWidth / 2, fieldRect->left, y_c + goalWidth / 2));
	aCanvas->FillRect(Rect(fieldRect->right, y_c - goalWidth / 2, fieldRect->right + borderWidth, y_c + goalWidth / 2));
	aCanvas->Rectangle(0, y_c - goalWidth / 2, fieldRect->left, y_c + goalWidth / 2);
	aCanvas->Rectangle(fieldRect->right, y_c - goalWidth / 2, fieldRect->right + borderWidth, y_c + goalWidth / 2);
	aCanvas->Brush->Style = bsClear;
	aCanvas->Rectangle(fieldRect->left, y_c - goalAreaH / 2, fieldRect->left + goalAreaW, y_c + goalAreaH / 2);
	aCanvas->Rectangle(fieldRect->right - goalAreaW, y_c - goalAreaH / 2, fieldRect->right, y_c + goalAreaH / 2);

	aCanvas->Brush->Style = currBrushStyle;
	aCanvas->Pen->Color = currPenColor;
	aCanvas->Brush->Color = currBrushColor;*/
	//Brushes::ICanvasBrush^ brush() ;               vârtu tîklu uzzimeet
	//brush-
	

	
	//clds->DrawImage(rtGoalNetTile);
	delete clds;
	rtGoalNetTile = ref new Microsoft::Graphics::Canvas::CanvasCommandList(game->cac);       //create res

	CanvasDrawingSession^ 	clds1 = rtGoalNetTile->CreateDrawingSession();
	clds1->DrawRoundedRectangle(4, 4, 10, 10, 1, 1, Colors::WhiteSmoke, 1);
	clds1->DrawLine(0, 4, 5, 3, Colors::WhiteSmoke, 1);
	clds1->DrawLine(4, 0, 3, 5, Colors::AntiqueWhite, 1);
	delete clds1;
	goalNetBrush = ref new  Microsoft::Graphics::Canvas::Brushes::CanvasImageBrush(game->cac, rtGoalNetTile);
	goalNetBrush->SourceRectangle = Rect(0, 0, 7, 7);
	goalNetBrush->ExtendX = Microsoft::Graphics::Canvas::CanvasEdgeBehavior::Mirror;
	goalNetBrush->ExtendY = Microsoft::Graphics::Canvas::CanvasEdgeBehavior::Mirror;
}

void Field::drawLines()  //atseviðíi zîmç vârtu tîklu,lai to varçtu uzzîmçt virs spçletâjiem 
{
	CanvasDrawingSession^ 	clds =game->offscreen->CreateDrawingSession();
	clds->DrawRectangle(Rect(0, y_c - goalWidth / 2, borderWidth, goalWidth ), Colors::AntiqueWhite);
	clds->FillRectangle(Rect(0, y_c - goalWidth / 2, borderWidth, goalWidth ),goalNetBrush);
	clds->DrawRectangle(Rect(fieldRect->Right, y_c - goalWidth / 2, borderWidth, goalWidth ),Colors::AntiqueWhite);
	clds->FillRectangle(Rect(fieldRect->Right, y_c - goalWidth / 2, borderWidth, goalWidth), goalNetBrush);
	delete clds;
	/*aCanvas->Brush->Style = bsClear;
	aCanvas->Pen->Color = clWhite;
	aCanvas->Rectangle(*fieldRect);
	aCanvas->MoveTo(x_c, fieldRect->bottom - 1);
	aCanvas->LineTo(x_c, fieldRect->top);
	aCanvas->Ellipse(x_c - 45, y_c - 45, x_c + 45, y_c + 45);
	aCanvas->Brush->Color = clWhite;
	aCanvas->Ellipse(x_c - 2, y_c - 2, x_c + 2, y_c + 2);*/
}

bool Field::isInside(int x, int y,int& r)
{
	return x >= fieldRect->Left+r && x <= fieldRect->Right-r && y >= fieldRect->Top+r && y <= fieldRect->Bottom-r;
}

bool Field::isOutSide(int x, int y, int& r)
{
	return y < fieldRect->Top+r || y > fieldRect->Bottom-r;
}
bool Field::isInside(int x, int y)
{
	return x >= fieldRect->Left && x <= fieldRect->Right && y >= fieldRect->Top && y <= fieldRect->Bottom;
}

bool Field::isOutSide(int x, int y)
{
	return y < fieldRect->Top || y > fieldRect->Bottom;
}

bool Field::isOutLeft(int x, int y, int& r)
{
	return x < fieldRect->Left+r;
}

bool Field::isOutRight(int x, int y, int& r)
{
	return x > fieldRect->Right-r;
}

bool Field::isOutLeft(int x, int y)  /// vai izmantot funkcijas bez radiusa paarbaudes?
{
	return x < fieldRect->Left ;
}

bool Field::isOutRight(int x, int y)
{
	return x > fieldRect->Right;
}


bool Field::isGoalRight(int x, int y)
{
	return isOutRight(x, y) && (y > (y_c - goalWidth / 2)) && (y < (y_c + goalWidth / 2));
}

bool Field::isGoalLeft(int x, int y)
{
	return isOutLeft(x, y) && (y >(y_c - goalWidth / 2)) && (y < (y_c + goalWidth / 2));
}
