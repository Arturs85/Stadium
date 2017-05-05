
#pragma once
//#include <Windows.h>
#include <iostream>
//#include <sstream>
#include "pch.h"
#include <math.h>
#include "Field.h"
//#include "MainPage.xaml.h"
#include "Ball.h"
#include "AssReferee.h"
using namespace std;
//using namespace FootballWoGlobal;
enum state { sStop, sRunning, sPause, sGoal, sRestartGame, sFirstKick };
class Referee;
class Player;
class Girl;
class Lights;

class Game
{
public:
	Game(CanvasCommandList^ offscreen,CanvasCommandList^ cl, Microsoft::Graphics::Canvas::UI::Xaml::CanvasAnimatedControl^ cac, Windows::UI::Xaml::Controls::MediaElement^ mysong);
	~Game();
	//MainPage^ mainpage;
	int scoreL;
	int scoreR;
	Platform::String^ coment;

	Ball* ball;
	Field* field;
	Referee* referee;
	AssReferee *assRef1;
	AssReferee *assRef2;

	Girl *girl[5];
	Lights *lights[2];

	vector<Player*> Team1;
	vector<Player*> Team2;
	state gameState;
	//MediaElement^ mysong;
	CanvasDrawingSession^ 	clds;

	CanvasCommandList^ offscreen;
	Microsoft::Graphics::Canvas::CanvasCommandList^ cl;
	Microsoft::Graphics::Canvas::UI::Xaml::CanvasAnimatedControl^ cac;
	void initialize();
	void position0();
	void drawAll();
	void moveAll();
	void position1();
	void startGame();
	void position2();
	void simulationStep();
	void energyControl();
	void sound(Platform::String ^ fileName);
int time;
int enL = 0, enR = 0;
bool pShowChecked = false;
bool soundChecked = false;
private:
	//std::unique_ptr<DirectX::AudioEngine> m_audEngine;


	//SmartBall* smartball;
	//Referee* referee;
	//	Microsoft::Graphics::Canvas::CanvasCommandList^ cl;
	//CanvasDevice^ device;
	//vector<Player*> Team1;
	//vector<Player*> Team2;
	//		state gameState;

};
//extern  Game* game;

