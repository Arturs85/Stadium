# pragma once

#include <pch.h>
#include <math.h>
#include "Player.h"
#include "Field.h"
#include "Ball.h"
//#include "mainpage.h"
#include "Referee.h"
#include "functions.h"
//#include <mmsystem.hpp>
#include "MainPage.xaml.h"
#include "Game.h"
using namespace std;
//using namespace Stadium;

//extern TFG_Frm *FG_Frm;
//extern MainPage^ mainpage;
Player::Player(CanvasRenderTarget^ offScreen,int t, int n):Human(offScreen)
{
	//offscreen = offScreen;
	teamNo = t;
	No = n;
	color = t == 1 ? Colors::White : Colors::Red;
	speed = 0;
	sound = 0;
	//font = new TFont;
	//font->Name = "Courier New";
	//font->Height = 2 * r + 1;
	inGame = true;
	char buf[256];
	sprintf_s(buf, " krasa %d ", color.ToString());
	OutputDebugStringA(buf);
	sprintf_s(buf, "Y=  %d \n",y);
	OutputDebugStringA(buf);

}
Player::Player( int t, int n) 
{
	
	teamNo = t;
	No = n;
	color = t == 1 ? Colors::White : Colors::Red;
	speed = 0;
	sound = 0;
	//font = new TFont;
	//font->Name = "Courier New";
	//font->Height = 2 * r + 1;
	inGame = true;
	char buf[256];
	sprintf_s(buf, " krasa %d ", color.ToString());
	OutputDebugStringA(buf);
	sprintf_s(buf, "Y=  %d \n", y);
	OutputDebugStringA(buf);

}
void Player::draw()
{
	Human::draw();
	//aCanvas->Font = font;
	//aCanvas->Brush->Style = bsClear;
	//aCanvas->TextOutA(x - r + 1, y - r, IntToStr(No));
	CanvasDrawingSession^ clds = offscreen->CreateDrawingSession();
	clds->DrawText((No.ToString()),x-r+1, y-r,Colors::Black);

	delete clds;
	
//	switch (sound) {
	//case 0: break;
	//case 1: FG_Frm->sound("kick1.wav", SND_ASYNC); break;
	//case 2: FG_Frm->sound("kick2.wav", SND_ASYNC); break;
	//case 3: FG_Frm->sound("kick3.wav", SND_ASYNC); break;
		
	//};
	if (sound) {
		game->coment = "Team " + teamNo +
			", No. " + No;
	}
	sound = 0;

}
void Player::move()
{
	if (!inGame) { moveToBench(); return; }
	int close = 2 * r + 2;
	int xc, yc, xb, yb, xd, yd;
	game->field->getCentre(xc,yc);
	//FG_Frm->field->getCentre(xc, yc);
	//FG_Frm->ball->getCoord(xb, yb);
	game->ball->getCoord(xb,yb);
	xd = xb; yd = yb;
	bool ownSide = (teamNo == 1 && x<xc) || (teamNo == 2 && x>xc);
	if (ownSide && distance(x, y, xb, yb)>150) yd = disperse(y, 50);
	energy = energy>0 ? --energy : 0;
	speed = 2 + rand() % 4;//(energy / 1000);          //?? pareizs diapazons?

	dir = direction(x, y, xd, yd);
	dir = disperse(dir, PI / 12);

	x += speed*cos(dir);
	y -= speed*sin(dir);

	//avoidCollision();

	if (distance(x, y, xb, yb)<close) kick();
}

void Player::kick()
{
	int xb, yb, xc, yc, xd, yd, speedb;
	game->ball->getCoord(xb, yb);
	game->field->getCentre(xc, yc);
	yd = yc;
	if (teamNo == 1)  xd = game->field->fieldRect-> Right;
	else            xd = game->field->fieldRect->Left;

	speedb = disperse(20, 10);

	bool ownSide = (teamNo == 1 && x<xc) || (teamNo == 2 && x>xc);

	Point p = partner();
	if (p.X >= 0) {  //is partner ?
		int speedp = sqrt(2 * distance(x, y, p.X, p.Y) + 0.25) - 0.5;

		//        if (ownSide) {
		//                xd = p.x; yd = p.y; speedb = speedp;
		//        }
		//        else {
		if ((teamNo == 1 && p.X>x + 10) || (teamNo == 2 && p.X<x - 10)) {
			xd = p.X; yd = p.Y;
			speedb = speedp + disperse(10, 5);
		}
		//        }

		if (game->gameState == sFirstKick) {
			xd = p.X; yd = p.Y; speedb = speedp + disperse(10, 3);
			game->gameState = sRunning;
		}
	} //if is partner

	double dirb;
	dirb = direction(xb, yb, xd, yd);
	dirb = disperse(dirb, PI / 24);
	game->ball->setDir(dirb);
	game->ball->setSpeed(speedb/4); //edit
	sound = 2;
}

void Player::avoidCollision()
{
	int lim = 5 * r;
	int nPos = game->Team1.size() + game->Team2.size();
	Point* occupiedPos = new Point[nPos];

	int j = 0;
	for (int i = 0; i < game->Team1.size(); i++) {
		if (game->Team1[i] == this) continue;
		if (!game->Team1[i]->inGame) continue;
		occupiedPos[j].X = game->Team1[i]->x;
		occupiedPos[j].Y = game->Team1[i]->y;
		++j;
	}
	for (int i = 0; i < game->Team2.size(); i++) {
		if (game->Team2[i] == this) continue;
		if (!game->Team2[i]->inGame) continue;
		occupiedPos[j].X = game->Team2[i]->x;
		occupiedPos[j].Y = game->Team2[i]->y;
		++j;
	}
	occupiedPos[j].X = game->referee->getPos().X;
	occupiedPos[j].Y = game->referee->getPos().Y;

	int attempts = 10000;
	bool tooClose;
	int xa = x, ya = y, speeda = speed;
	double dira = dir;
	int dist;
	nPos = j + 1;
	do {
		for (int i = 0; i < nPos; i++) {
			tooClose = distance(xa, ya, occupiedPos[i].X, occupiedPos[i].Y)<lim;
			dist = distance(xa, ya, occupiedPos[i].Y, occupiedPos[i].Y);
			if (tooClose) {
				--attempts;
				speeda = speeda + dist - lim;//disperse(speed, lim);
				dira = disperse(dir, PI / 12);
				xa = x + speeda*cos(dira);
				ya = y - speeda*sin(dira);
				break;
			}
		}
	} while (tooClose && attempts>0);
	x = xa;
	y = ya;
	speed = speeda;
	dir = dira;
	delete occupiedPos;
}

void Player::moveToBench()
{
	int xc, yc;
	game->field->getCentre(xc, yc);
	if (teamNo == 1)
		moveTo(xc - 20 - No * 3 * r,
			game->field->fieldRect->Top - game->field->getBorderW() + r);
	else
		moveTo(xc + 20 + No * 3 * r,
			game->field->fieldRect->Top - game->field->getBorderW() + r);
}

Point& Player::partner()
{
	int dist[7];
	Point p[6];
	int n = 0;

	if (teamNo == 1) {
		for (int i = 0; i < game->Team1.size(); i++) {
			if (game->Team1[i] == this) continue;
			if (!game->Team1[i]->inGame) continue;
			if (game->Team1[i]->type == tGoalkeeper) continue;
			p[n].X = game->Team1[i]->x;
			p[n].Y = game->Team1[i]->y;
			++n;
		}
	}
	else {
		for (int i = 0; i < game->Team2.size(); i++) {
			if (game->Team2[i] == this) continue;
			if (!game->Team2[i]->inGame) continue;
			if (game->Team2[i]->type == tGoalkeeper) continue;
			p[n].X = game->Team2[i]->x;
			p[n].Y= game->Team2[i]->y;
			++n;
		}
	}
	if (n == 0) { p[0].X = -1; return p[0]; } // no partners
	int d, mindist = distance(x, y, p[0].X, p[0].Y);
	int np = 0;
	for (int i = 0; i < n; i++) {
		d = distance(x, y, p[i].X, p[i].Y);
		if (d<mindist) {
			mindist = d;
			np = i;
		}
	}
	return p[np];
}
