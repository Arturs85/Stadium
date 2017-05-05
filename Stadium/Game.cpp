#include "pch.h"
//#include "Ball.h"
#include "Game.h"
#include "Referee.h"
#include "Forward.h"
#include "HalfBack.h"
#include "FullBack.h"
#include "Goalkeeper.h"
#include "Girl.h"
#include "Lights.h"
#include <vector>
#include "Mainpage.xaml.h"
using namespace concurrency;
using namespace Windows::Storage;
using namespace Windows::Storage::Streams;
using namespace Windows::Media::Playback;
using namespace Windows::Media::Core;
using namespace Windows::UI::Xaml::Media;

using namespace Windows::ApplicationModel::Core;
using namespace Windows::UI::Xaml::Controls;

MediaElement^ mysong2;

Game::Game(CanvasCommandList^ offscreen,CanvasCommandList^ cl, Microsoft::Graphics::Canvas::UI::Xaml::CanvasAnimatedControl^ cac, Windows::UI::Xaml::Controls::MediaElement^ mysong_p) {

	this->offscreen = offscreen;
	this->cl = cl;
	this->cac = cac;
	mysong2 = mysong_p;
	
	gameState = sStop;
	scoreL = scoreR = 0;
	time = 0;



}
Game::~Game() {delete field; delete ball; }

void Game::initialize()
{
	coment = "Ready";
	field = new Field;
	ball = new Ball(offscreen); // pârtaisît bez parametriem
	assRef1 = new AssReferee;
	assRef2 = new AssReferee();
	referee = new Referee();

	Player* p;
	// Make Team1
	int n = 0;
	p = new Forward(1, ++n);
	Team1.push_back(p);
	p = new Forward(1, ++n);
	Team1.push_back(p);
	p = new Forward(1, ++n);
	Team1.push_back(p);
	p = new HalfBack(1, ++n);
	Team1.push_back(p);
	p = new FullBack(1, ++n);
	Team1.push_back(p);
	p = new FullBack(1, ++n);
	Team1.push_back(p);
	p = new Goalkeeper(1, ++n);
	Team1.push_back(p);
	// Make Team2
	n = 0;
	p = new Forward(2, ++n);
	Team2.push_back(p);
	p = new Forward(2, ++n);
	Team2.push_back(p);
	p = new Forward(2, ++n);
	Team2.push_back(p);
	p = new HalfBack(2, ++n);
	Team2.push_back(p);
	p = new FullBack(2, ++n);
	Team2.push_back(p);
	p = new FullBack(2, ++n);
	Team2.push_back(p);
	p = new Goalkeeper(2, ++n);
	Team2.push_back(p);
	for (int i = 0; i<5; ++i) girl[i] = new Girl;
	lights[0] = new Lights(0, 0, 250, PI / 32, -PI / 12, -PI / 2 + PI / 12, PI / 12, PI / 3);
	lights[1] = new Lights(game->field->fieldRect->Width, 0, 250, PI / 32, -PI / 2 - PI / 8, -PI + PI / 8, PI / 12, PI / 3);
	position0();
	//drawAll();
	for (int i = 0; i < Team2.size(); i++) Team2[i]->setEnergy(rand() % 2000 + 2000);
	for (int i = 0; i < Team1.size(); i++) Team1[i]->setEnergy(rand() % 2000 + 2000);

	//field->drawLines(); //initialize goal net Brush
}

void Game::position0()
{
	int y, xc, yc;
	field->getCentre(xc, yc);
	referee->moveTo(xc, yc - 50);
	ball->moveTo(xc, yc - 45);
	assRef1->moveTo(xc - 10, yc - 50);
	assRef2->moveTo(xc + 10, yc - 50);
	y = yc - 10 * Team1.size() / 2;
	for (int i = 0; i < Team1.size(); i++)
	{
		Team1[i]->moveTo(xc - 20, y);
		y += 10;
	}
	y = yc - 10 * Team2.size() / 2;
	for (int i = 0; i < Team2.size(); i++)
	{
		Team2[i]->moveTo(xc + 20, y);
		y += 10;
	}
	for (int i = 0; i<5; ++i) girl[i]->moveTo(xc - 2 * 6 + i * 6, 4);



}

void Game::drawAll()
{
	//field->draw();
	
		ball->draw();

	lights[0]->draw();
	lights[1]->draw();
	
	assRef1->draw();
	assRef2->draw();
	referee->draw();
	for (int i = 0; i < Team1.size(); i++)
		Team1[i]->draw();
	for (int i = 0; i < Team2.size(); i++)
		Team2[i]->draw();
	field->drawLines();
	for (int i = 0; i<5; ++i) girl[i]->draw();

}

void Game::moveAll()
{
	if (gameState == sPause) {
		for (int i = 0; i<5; ++i) {
			girl[i]->move();
		}
		lights[0]->move();
		lights[1]->move();
		return;
	}

	int xp = (int)Team1[0]->getPos().X;
	int yp = (int)Team1[0]->getPos().Y;
	int speeedp = Team1[0]->getSpeed();
	

	ball->move();
	assRef1->move();
	assRef2->move();
	referee->move();
	for (int i = 0; i < Team1.size(); i++)
		Team1[i]->move();
	for (int i = 0; i < Team2.size(); i++)
		Team2[i]->move();
	char buf[256];
	if (xp + 30 < (int)Team1[0]->getPos().X || xp - 30 > (int)Team1[0]->getPos().X) {
			char buf[256];

				sprintf_s(buf, "Player 1 pri x %d y %d sp %d \n", xp,yp,speeedp);
				OutputDebugStringA(buf);

		sprintf_s(buf, "Player 1 post x %d y %d sp %d \n", (int)Team1[0]->getPos().X, (int)Team1[0]->getPos().Y, Team1[0]->getSpeed());
		OutputDebugStringA(buf);

	}
	//sprintf_s(buf, "x=  %d ", (int)Team1[0]->getPos().X);
	//	OutputDebugStringA(buf);
//sprintf_s(buf, "Y=  %d \n", (int)Team1[0]->getPos().Y);
}

void Game::position1()
{

	int xc, yc;
	field->getCentre(xc, yc);
	referee->moveTo(xc + 50, yc - 50);
	Team1[0]->moveTo(xc - 5, yc);
	for (int i = 1; i < Team1.size(); i++)
	{
		if (!Team1[i]->inGame) continue;
		if (Team1[i]->type == tGoalkeeper) Team1[i]->moveTo(field->fieldRect->Left, yc);
		else Team1[i]->moveTo(xc - rand()%(field->getW() / 2 - 30), rand()%(field->getH() - 20) + 20);
	}

	for (int i = 0; i < Team2.size(); i++)
	{
		if (!Team2[i]->inGame) continue;
		if (Team2[i]->type == tGoalkeeper) Team2[i]->moveTo(field->fieldRect->Right, yc);
		else Team2[i]->moveTo(xc + rand()%(field->getW() / 2 - 30), rand()%(field->getH() - 20) + 20);
	}

}

void Game::startGame()
{
	int xc, yc;
	field->getCentre(xc, yc);
	ball->moveTo(xc, yc);
	ball->setSpeed(0);
	assRef1->moveTo(xc, field->getBorderW() / 2 + 2);
	assRef2->moveTo(xc, 3 * field->getBorderW() / 2 + field->getH() - 2);
	for (int i = 0; i<5; ++i) girl[i]->moveTo(xc - 2 * 6 + i * 6, 4);
	if (rand()%2) position1(); else position2();
	sound("whistle.wav");
	gameState = sFirstKick;

}

void Game::position2()
{
	int xc, yc;
	field->getCentre(xc, yc);
	referee->moveTo(xc - 50, yc - 50);
	for (int i = 0; i < Team1.size(); i++)
	{
		if (!Team1[i]->inGame) continue;
		if (Team1[i]->type == tGoalkeeper) Team1[i]->moveTo(field->fieldRect->Left, yc);
		else Team1[i]->moveTo(xc - rand()%(field->getW() / 2 - 30), rand()%(field->getH() - 20) + 20);
	}

	Team2[0]->moveTo(xc + 5, yc);
	for (int i = 1; i < Team2.size(); i++)
	{
		if (!Team2[i]->inGame) continue;
		if (Team2[i]->type == tGoalkeeper) Team2[i]->moveTo(field->fieldRect->Right, yc);
		else Team2[i]->moveTo(xc + rand()%(field->getW() / 2 - 30), rand()%(field->getH() - 20) + 20);
	}

}

void Game::simulationStep()
{
	//done = false;  //keeps loop going

	//MainPage textBlockT TimeTxt->Caption = IntToStr(++time);
	++time;
	int xc, yc, xb, yb;
	field->getCentre(xc, yc);
	ball->getCoord(xb, yb);

	//drawAll();

	switch (gameState) {
			

	case sGoal:
		//::Sleep(1000);
		coment = "***** GOAL!!! *****";
	

		//::String^ mencheer = "mencheer.wav";

		sound("whistle.wav");
		sound("mencheer.wav");
		//ScoreLeft->Caption = IntToStr(scoreL);
		//ScoreRight->Caption = IntToStr(scoreR);
		if (pShowChecked) {
			gameState = sPause;
		lights[0]->on = lights[1]->on = true;
			sound("successtada.wav");
		}
		else 
		gameState = sRestartGame;
		
		return;
	case sRestartGame:
		//::Sleep(1000);
		for (int i = 0; i<5; ++i) girl[i]->moveTo(xc - 2 * 6 + i * 6, 4);
		lights[0]->on = lights[1]->on = false;
		sound("whistle.wav");
		gameState = sFirstKick;
		return;

	}

	if (field->isGoalLeft(xb, yb))
	{
		scoreR += 1;
		gameState = sGoal;
		ball->moveTo(xc, yc);
		ball->setSpeed(0);
		position1();
		return;
	}

	if (field->isGoalRight(xb, yb))
	{
		scoreL += 1;
		gameState = sGoal;
		ball->moveTo(xc, yc);
		ball->setSpeed(0);
		position2();
		return;
	}

	//::Sleep(500 - 50 * TrackBar->Position);  //slows down action

	moveAll();

	energyControl();

}

void Game::energyControl()
{
	enL = enR = 0;
	for (int i = 0; i < Team1.size(); i++) enL += Team1[i]->getEnergy();
	for (int i = 0; i < Team2.size(); i++) enR += Team2[i]->getEnergy();
	//EnergyLeft->Caption = IntToStr(enL);
	//SpinEnergyLeft->Position = enL;
	//EnergyRight->Caption = IntToStr(enR);
	//SpinEnergyRight->Position = enR;

}

 void Game::sound(Platform::String^ fileName)
	
		  {
	  if (soundChecked) {
		  //  return create_async([fileName] {

		  StorageFolder^ storageFolder = ApplicationData::Current->LocalFolder;
		  auto fileUri = ref new Uri("ms-appx:///Assets/" + fileName);
		  auto file = StorageFile::GetFileFromApplicationUriAsync(fileUri);

		  create_task((file)).then([](StorageFile^ sampleFile)
		  {

			  create_task(sampleFile->OpenAsync(FileAccessMode::Read)).then([sampleFile](IRandomAccessStream^ stream)
			  {

				  CoreApplication::MainView->CoreWindow->Dispatcher->RunAsync(Core::CoreDispatcherPriority::Normal, ref new Windows::UI::Core::DispatchedHandler([stream]()
				  {
					  //while (mysong2->CurrentState != MediaElementState::Closed &&  mysong2->CurrentState != MediaElementState::Paused &&  mysong2->CurrentState != MediaElementState::Stopped) {
						//  Sleep(10);
					 // }
					  mysong2->Stop();
					  mysong2->SetSource(stream, "audio/x-ms-wma");
					  mysong2->Play();
				  }));

			  });
		  });
		  // });
	  }
		  
}
