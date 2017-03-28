//
// MainPage.xaml.cpp
// Implementation of the MainPage class.
//

#include "pch.h"
#include "MainPage.xaml.h"
#include "Ball.h"
#include "Field.h"

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
MainPage^ mainpage;
MainPage::MainPage()
{
	InitializeComponent();
	 


}
 
void Stadium::MainPage::inputButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	greetingOutput->Text = "Hello " + nameInput->Text + "!";
	
	ball->setSpeed(30);
	ball->setDir(PI /5- 0.1);

}


void Stadium::MainPage::canvas_Draw(Microsoft::Graphics::Canvas::UI::Xaml::CanvasControl^ sender, Microsoft::Graphics::Canvas::UI::Xaml::CanvasDrawEventArgs^ args)
{
	

}


void Stadium::MainPage::Page_Unloaded(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	this->canvas->RemoveFromVisualTree();
	delete this->canvas;
		delete smartball;

	delete ball;
	delete field;
}


void Stadium::MainPage::canvas_Draw_1(Microsoft::Graphics::Canvas::UI::Xaml::ICanvasAnimatedControl^ sender, Microsoft::Graphics::Canvas::UI::Xaml::CanvasAnimatedDrawEventArgs^ args)
{
	args->DrawingSession->DrawImage(cl);
	
	//args->DrawingSession->FillCircle(ball->x,300,22,Colors::Crimson );
	ball->draw();
	smartball->draw();
	args->DrawingSession->DrawImage(offscreen,30,230);
	CanvasDrawingSession^ 	clds=offscreen->CreateDrawingSession();
	clds->Clear(Colors::Transparent);
	delete clds;
}


void Stadium::MainPage::canvas_CreateResources(Microsoft::Graphics::Canvas::UI::Xaml::CanvasAnimatedControl^ sender, Microsoft::Graphics::Canvas::UI::CanvasCreateResourcesEventArgs^ args)
{
	//device = CanvasDevice::GetSharedDevice();
	offscreen = ref new CanvasRenderTarget(sender,800, 500,96);
	field = new Field();
	ball = new Ball(offscreen,field,30);
	smartball = new SmartBall(offscreen, field, 20, ball);
	OutputDebugStringW(L"My output string--------------------------------.");
	 cl = ref new CanvasCommandList(sender);
	CanvasDrawingSession^ 	clds = cl->CreateDrawingSession();
	//CanvasBitmap^ bitmapBall = ref new CanvasBitmap();
	 
	try {
		OutputDebugStringW(L"ERR draw");

	
	clds->FillRectangle(30, 230, 800, 500, Colors::Green);
	clds->DrawRectangle(30, 230, 800, 500, Colors::Wheat,5);
	clds->DrawLine(430, 230, 430, 730, Colors::AntiqueWhite, 5);
	clds->DrawCircle(425, 480, 100, Colors::AntiqueWhite , 5);

	}
	catch (Exception ^e) 
	{
	}
	//finally{
	
		//if (clds != nullptr)
			// Call the object's Dispose method.
			delete clds;
	

	//}
	
}


void Stadium::MainPage::canvas_Update(Microsoft::Graphics::Canvas::UI::Xaml::ICanvasAnimatedControl^ sender, Microsoft::Graphics::Canvas::UI::Xaml::CanvasAnimatedUpdateEventArgs^ args)
{
//if (dirFWd)
	
//ball->x--;
//else
	//ball->x++;
	ball->move();
	smartball->move();
}
