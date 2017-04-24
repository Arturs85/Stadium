#pragma once
//#include <Windows.h>
#include <iostream>
//#include <sstream>
#include "pch.h"
#include <math.h>
#include "Field.h"
//#include "MainPage.xaml.h"
#include "Ball.h"
using namespace std;
//using namespace FootballWoGlobal;
class Game
{	
public:
	Game(CanvasRenderTarget^ offscreen);
	~Game();
	//MainPage^ mainpage;

		
Ball* ball;
		Field* field;
	
private:
		
		
		//SmartBall* smartball;
		//Referee* referee;
	//	Microsoft::Graphics::Canvas::CanvasCommandList^ cl;
		//CanvasDevice^ device;
		CanvasRenderTarget^ offscreen;

		//vector<Player*> Team1;
		//vector<Player*> Team2;
//		state gameState;
		
	};
	//extern  Game* game;

