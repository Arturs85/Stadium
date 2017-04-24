﻿//
// MainPage.xaml.cpp
// Implementation of the MainPage class.
//

#include "pch.h"
#include "MainPage.xaml.h"
#include "Ball.h"
#include "Field.h"
#include "Game.h"
#include <math.h>


using namespace Stadium;
using namespace std;
using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;
using namespace Windows::UI;
using namespace Microsoft::Graphics::Canvas;
using namespace Microsoft::Graphics::Canvas::Effects;
using namespace Windows::Foundation::Numerics;

// The Blank Page item template is documented at http://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x409

int MainPage::radius1 = 100;
bool dirFWd = true;
//Ball^ MainPage::ball; 
//MainPage^ mainpage;
Game* game;
MainPage::MainPage()
{
	InitializeComponent();
	//mainpage = this;
	prescaler = 4;
	//mainpage = this;
}
 
void Stadium::MainPage::inputButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	//game->gameState = sRunning;
	//game->ball->setSpeed(30);
	//game->ball->setDir(PI /5- 0.1);
	//game->assRef1->moveTo(500, game->field->getBorderW() / 2 + 2);
	//game->assRef2->moveTo(550, 3 * game->field->getBorderW() / 2 + game->field->getH() - 2);
	game->startGame();
	game->coment = "Started";
}


void Stadium::MainPage::canvas_Draw(Microsoft::Graphics::Canvas::UI::Xaml::CanvasControl^ sender, Microsoft::Graphics::Canvas::UI::Xaml::CanvasDrawEventArgs^ args)
{	

}


void Stadium::MainPage::Page_Unloaded(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	this->canvas->RemoveFromVisualTree();
	delete this->canvas;
		delete smartball;

	//delete ball;
	//delete field;
		delete game;
}


void Stadium::MainPage::canvas_Draw_1(Microsoft::Graphics::Canvas::UI::Xaml::ICanvasAnimatedControl^ sender, Microsoft::Graphics::Canvas::UI::Xaml::CanvasAnimatedDrawEventArgs^ args)
{
	args->DrawingSession->DrawImage(cl,30,150); // iznest kaa statiskos const mainiigos
	
	//args->DrawingSession->FillCircle(ball->x,300,22,Colors::Crimson );
	/*game->ball->draw();
	game->referee->draw();
	game->assRef1->draw();
	game->assRef2->draw();
	for (int i = 0; i < game->Team1.size(); i++)
		game->Team1[i]->draw();
	for (int i = 0; i < game->Team2.size(); i++)
		game->Team2[i]->draw();

	smartball->draw();*/
	game->drawAll();
	args->DrawingSession->DrawImage(offscreen,30,150); //kustiigo objektu bilde jaaziimee 50 px nobiidiita
	CanvasDrawingSession^ 	clds=offscreen->CreateDrawingSession();
	clds->Clear(Colors::Transparent);
	delete clds;
	//Core::CoreDispatcher::RunAsync()
	
	Windows::ApplicationModel::Core::CoreApplication::MainView->CoreWindow->Dispatcher->RunAsync(
		Core::CoreDispatcherPriority::Normal,
		ref new Windows::UI::Core::DispatchedHandler([this]()
	{
		int time = game->time;
	textBlockTime->Text = " " + time;
	textScoreTeam1->Text = ""+game->scoreL;
	textScoreTeam2->Text = "" + game->scoreR;
	textEnergyTeam1->Text = "" + game->enL;
	textEnergyTeam2->Text = "" + game->enR;
	textBlockComent->Text = game->coment;
	// do stuff
	}));
}


void Stadium::MainPage::canvas_CreateResources(Microsoft::Graphics::Canvas::UI::Xaml::CanvasAnimatedControl^ sender, Microsoft::Graphics::Canvas::UI::CanvasCreateResourcesEventArgs^ args)
{
	//sender->TargetElapsedTime.Duration=(long long)9;
	canvasAnimatedControl = sender;
	//device = CanvasDevice::GetSharedDevice();
	cl = ref new CanvasCommandList(sender);
	offscreen = ref new CanvasRenderTarget(sender,880, 580,96);  //varbuut jaadzeess
	game = new Game(offscreen,cl,sender);
	game->initialize(); // rada dalībniekus
	



	//game->field = new Field();
	//game->ball = new Ball(offscreen,game->field,5);
	//game->referee = new Referee();
	//game->referee->moveTo(300, 300);
	//
	//game->assRef1 = new AssReferee();
	//game->assRef2 = new AssReferee();
	//


	//Player* p;
	//// Make Team1
	//int n = 0;
	//p = new Forward(1, ++n);
	//game->Team1.push_back(p);
	//p = new Forward(1, ++n);
	//game->Team1.push_back(p);
	//p = new Forward(1, ++n);
	//game->Team1.push_back(p);
	//p = new HalfBack(1, ++n);
	//game->Team1.push_back(p);
	//p = new FullBack(1, ++n);
	//game->Team1.push_back(p);
	//p = new FullBack(1, ++n);
	//game->Team1.push_back(p);
	//p = new Goalkeeper(1, ++n);
	//game->Team1.push_back(p);
	//// Make Team2
	//n = 0;
	//p = new Forward(2, ++n);
	//game->Team2.push_back(p);
	//p = new Forward(2, ++n);
	//game->Team2.push_back(p);
	//p = new Forward(2, ++n);
	//game->Team2.push_back(p);
	//p = new HalfBack(2, ++n);
	//game->Team2.push_back(p);
	//p = new FullBack(2, ++n);
	//game->Team2.push_back(p);
	//p = new FullBack(2, ++n);
	//game->Team2.push_back(p);
	//p = new Goalkeeper(2, ++n);
	//game->Team2.push_back(p);

	//for (int i = 0; i < game->Team1.size(); i++) game->Team1[i]->setEnergy(rand()%2000 + 2000);
	//for (int i = 0; i < game->Team2.size(); i++) game->Team2[i]->setEnergy(rand()%2000 + 2000);
	//game->gameState = sStop;

	//game->position0();
	//smartball = new SmartBall(offscreen, game->field, 20, game->ball);
	//
	//OutputDebugStringW(L"My output string--------------------------------.");
	
	//CanvasDrawingSession^ 	clds = cl->CreateDrawingSession();
	game->field->draw();
	

	
	//clds->FillRectangle(30, 230, 800, 500, Colors::Green);
	//clds->DrawRectangle(30, 230, 800, 500, Colors::Wheat,5);
	//clds->DrawLine(430, 230, 430, 730, Colors::AntiqueWhite, 5);
	//clds->DrawCircle(425, 480, 100, Colors::AntiqueWhite , 5);

	
	
	
			//delete clds;
	

	
}


void Stadium::MainPage::canvas_Update(Microsoft::Graphics::Canvas::UI::Xaml::ICanvasAnimatedControl^ sender, Microsoft::Graphics::Canvas::UI::Xaml::CanvasAnimatedUpdateEventArgs^ args)
{
	//if (dirFWd)

	//ball->x--;
	//else
		//ball->x++;
	
	//Core::CoreWindow::GetForCurrentThread()->Activate();
	//Core::CoreWindow::GetForCurrentThread()->Dispatcher->ProcessEvents(Core::CoreProcessEventsOption::ProcessUntilQuit);
	//if (prescaler++ >= 2) {
	//	prescaler = 0;
		if (game->gameState != sStop) { //pagaidu parbaude
		
			game->simulationStep();
			/*game->ball->move();
		game->referee->move();
		game->assRef1->move();
		game->assRef2->move();
		for (int i = 0; i < game->Team1.size(); i++)
			game->Team1[i]->move();
		for (int i = 0; i < game->Team2.size(); i++)
			game->Team2[i]->move();*/
	}

	//smartball->move();
}


void Stadium::MainPage::slider_ValueChanged(Platform::Object^ sender, Windows::UI::Xaml::Controls::Primitives::RangeBaseValueChangedEventArgs^ e)
{
	TimeSpan timeSpan = canvas->TargetElapsedTime;
	
	timeSpan.Duration = (101-e->NewValue) * 3000+8000;
		textBlock->Text = e->NewValue +" tS= "+timeSpan.Duration ;

	canvas->TargetElapsedTime = timeSpan; //->TargetElapsedTime.Duration = 12;
}


void Stadium::MainPage::stopButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	
	game->coment = "Pause...";
	textBlockComent->Text = game->coment;  //ja nepaspēj izsaukt onDraw ?
	game->gameState = sStop;
}


void Stadium::MainPage::checkBoxT1P2_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	game->Team1[1]->inGame = checkBoxT1P2->IsChecked->Value;
}


void Stadium::MainPage::checkBoxT1P3_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	game->Team1[2]->inGame = checkBoxT1P3->IsChecked->Value;
}


void Stadium::MainPage::checkBoxT1P4_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	game->Team1[3]->inGame = checkBoxT1P4->IsChecked->Value;
}


void Stadium::MainPage::checkBoxT1P5_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	game->Team1[4]->inGame = checkBoxT1P5->IsChecked->Value;
}


void Stadium::MainPage::checkBoxT1P6_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	game->Team1[5]->inGame = checkBoxT1P6->IsChecked->Value;
}


void Stadium::MainPage::checkBoxT2P2_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	game->Team2[1]->inGame = checkBoxT2P2->IsChecked->Value;
}


void Stadium::MainPage::checkBoxT2P3_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	game->Team2[2]->inGame = checkBoxT2P3->IsChecked->Value;
}


void Stadium::MainPage::checkBoxT2P4_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	game->Team2[3]->inGame = checkBoxT2P4->IsChecked->Value;
}


void Stadium::MainPage::checkBoxT2P5_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	game->Team2[4]->inGame = checkBoxT2P5->IsChecked->Value;
}


void Stadium::MainPage::checkBoxT2P6_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	game->Team2[5]->inGame = checkBoxT2P6->IsChecked->Value;
}

