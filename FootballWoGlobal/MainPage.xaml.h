
#pragma once
	using namespace std;
#include "MainPage.g.h"
#include "Ball.h"
#include "Field.h"
#include "SmartBall.h"
#include "Game.h"
//#include "Player.h"
//#include "Referee.h"
#include <vector>

class Field;   //??
//class Ball;
class Game;
//class Referee;
//class Player;

#define PI 3.1415926535897932385

namespace FootballWoGlobal {
	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	public ref class MainPage sealed
	{
	public:
		MainPage();
		//MainPage^ mainpage;
	

		

	private:
//Ball* ball;
	//	Field* field;
		SmartBall* smartball;
		//Referee* referee;
		Microsoft::Graphics::Canvas::CanvasCommandList^ cl;
		CanvasDevice^ device;
		CanvasRenderTarget^ offscreen;
		//Game* game;
		//vector<Player*> Team1;
		//vector<Player*> Team2;
		//state gameState;
		static	int radius1;
		void inputButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void canvas_Draw(Microsoft::Graphics::Canvas::UI::Xaml::CanvasControl^ sender, Microsoft::Graphics::Canvas::UI::Xaml::CanvasDrawEventArgs^ args);
		void Page_Unloaded(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void canvas_Draw_1(Microsoft::Graphics::Canvas::UI::Xaml::ICanvasAnimatedControl^ sender, Microsoft::Graphics::Canvas::UI::Xaml::CanvasAnimatedDrawEventArgs^ args);
		void canvas_CreateResources(Microsoft::Graphics::Canvas::UI::Xaml::CanvasAnimatedControl^ sender, Microsoft::Graphics::Canvas::UI::CanvasCreateResourcesEventArgs^ args);
		void canvas_Update(Microsoft::Graphics::Canvas::UI::Xaml::ICanvasAnimatedControl^ sender, Microsoft::Graphics::Canvas::UI::Xaml::CanvasAnimatedUpdateEventArgs^ args);

	};
}extern  Game *game;

