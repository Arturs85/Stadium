//
// MainPage.xaml.h
// Declaration of the MainPage class.
//

#pragma once
using namespace std;
#include "MainPage.g.h"
#include "Ball.h"
#include "Field.h"
#include "SmartBall.h"
#include "Player.h"
#include "Referee.h"
#include "Goalkeeper.h"
#include "Forward.h"
#include "HalfBack.h"
#include "FullBack.h"
#include <vector>

class Field;   //??
class Ball;
class Game;
class Referee;
class Player;
class Goalkeeper;


#define PI 3.1415926535897932385
//enum state { sStop, sRunning, sPause, sGoal, sRestartGame, sFirstKick };

namespace Stadium
{
	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	public ref class MainPage sealed
	{
	public:
		MainPage();
		//MainPage^ mainpage;

		// Ball* ball;
		//Field* field;
		
			
		

	
	private:
		Microsoft::Graphics::Canvas::UI::Xaml::CanvasAnimatedControl^ canvasAnimatedControl;
		SmartBall* smartball;
		Microsoft::Graphics::Canvas::CanvasCommandList^ cl;
		CanvasDevice^ device; 
		CanvasRenderTarget^ offscreen;	
		static	int radius1;
		
		void inputButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void canvas_Draw(Microsoft::Graphics::Canvas::UI::Xaml::CanvasControl^ sender, Microsoft::Graphics::Canvas::UI::Xaml::CanvasDrawEventArgs^ args);
		void Page_Unloaded(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void canvas_Draw_1(Microsoft::Graphics::Canvas::UI::Xaml::ICanvasAnimatedControl^ sender, Microsoft::Graphics::Canvas::UI::Xaml::CanvasAnimatedDrawEventArgs^ args);
		void canvas_CreateResources(Microsoft::Graphics::Canvas::UI::Xaml::CanvasAnimatedControl^ sender, Microsoft::Graphics::Canvas::UI::CanvasCreateResourcesEventArgs^ args);
		void canvas_Update(Microsoft::Graphics::Canvas::UI::Xaml::ICanvasAnimatedControl^ sender, Microsoft::Graphics::Canvas::UI::Xaml::CanvasAnimatedUpdateEventArgs^ args);
		int prescaler;
		void slider_ValueChanged(Platform::Object^ sender, Windows::UI::Xaml::Controls::Primitives::RangeBaseValueChangedEventArgs^ e);
		void stopButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void checkBoxT1P2_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void checkBoxT1P3_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void checkBoxT1P4_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void checkBoxT1P5_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void checkBoxT1P6_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void checkBoxT2P2_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void checkBoxT2P3_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void checkBoxT2P4_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void checkBoxT2P5_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void checkBoxT2P6_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};
	
}extern Game* game;
//extern MainPage^ mainpage;