﻿//------------------------------------------------------------------------------
//     This code was generated by a tool.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
//------------------------------------------------------------------------------
#include "pch.h"

#if defined _DEBUG && !defined DISABLE_XAML_GENERATED_BINDING_DEBUG_OUTPUT
extern "C" __declspec(dllimport) int __stdcall IsDebuggerPresent();
#endif

#include "MainPage.xaml.h"

void ::Stadium::MainPage::InitializeComponent()
{
    if (_contentLoaded)
    {
        return;
    }
    _contentLoaded = true;
    ::Windows::Foundation::Uri^ resourceLocator = ref new ::Windows::Foundation::Uri(L"ms-appx:///MainPage.xaml");
    ::Windows::UI::Xaml::Application::LoadComponent(this, resourceLocator, ::Windows::UI::Xaml::Controls::Primitives::ComponentResourceLocation::Application);
}

void ::Stadium::MainPage::Connect(int __connectionId, ::Platform::Object^ __target)
{
    switch (__connectionId)
    {
        case 1:
            {
                ::Windows::UI::Xaml::Controls::Page^ element1 = safe_cast<::Windows::UI::Xaml::Controls::Page^>(__target);
                (safe_cast<::Windows::UI::Xaml::Controls::Page^>(element1))->Unloaded += ref new ::Windows::UI::Xaml::RoutedEventHandler(this, (void (::Stadium::MainPage::*)
                    (::Platform::Object^, ::Windows::UI::Xaml::RoutedEventArgs^))&MainPage::Page_Unloaded);
            }
            break;
        case 2:
            {
                this->contentPanel = safe_cast<::Windows::UI::Xaml::Controls::StackPanel^>(__target);
            }
            break;
        case 3:
            {
                this->canvas = safe_cast<::Microsoft::Graphics::Canvas::UI::Xaml::CanvasAnimatedControl^>(__target);
                (safe_cast<::Microsoft::Graphics::Canvas::UI::Xaml::CanvasAnimatedControl^>(this->canvas))->Draw += ref new ::Windows::Foundation::TypedEventHandler<::Microsoft::Graphics::Canvas::UI::Xaml::ICanvasAnimatedControl^, ::Microsoft::Graphics::Canvas::UI::Xaml::CanvasAnimatedDrawEventArgs^>(this, (void (::Stadium::MainPage::*)
                    (::Microsoft::Graphics::Canvas::UI::Xaml::ICanvasAnimatedControl^, ::Microsoft::Graphics::Canvas::UI::Xaml::CanvasAnimatedDrawEventArgs^))&MainPage::canvas_Draw_1);
                (safe_cast<::Microsoft::Graphics::Canvas::UI::Xaml::CanvasAnimatedControl^>(this->canvas))->CreateResources += ref new ::Windows::Foundation::TypedEventHandler<::Microsoft::Graphics::Canvas::UI::Xaml::CanvasAnimatedControl^, ::Microsoft::Graphics::Canvas::UI::CanvasCreateResourcesEventArgs^>(this, (void (::Stadium::MainPage::*)
                    (::Microsoft::Graphics::Canvas::UI::Xaml::CanvasAnimatedControl^, ::Microsoft::Graphics::Canvas::UI::CanvasCreateResourcesEventArgs^))&MainPage::canvas_CreateResources);
                (safe_cast<::Microsoft::Graphics::Canvas::UI::Xaml::CanvasAnimatedControl^>(this->canvas))->Update += ref new ::Windows::Foundation::TypedEventHandler<::Microsoft::Graphics::Canvas::UI::Xaml::ICanvasAnimatedControl^, ::Microsoft::Graphics::Canvas::UI::Xaml::CanvasAnimatedUpdateEventArgs^>(this, (void (::Stadium::MainPage::*)
                    (::Microsoft::Graphics::Canvas::UI::Xaml::ICanvasAnimatedControl^, ::Microsoft::Graphics::Canvas::UI::Xaml::CanvasAnimatedUpdateEventArgs^))&MainPage::canvas_Update);
            }
            break;
        case 4:
            {
                this->inputPanel = safe_cast<::Windows::UI::Xaml::Controls::StackPanel^>(__target);
            }
            break;
        case 5:
            {
                this->buttonPanel = safe_cast<::Windows::UI::Xaml::Controls::RelativePanel^>(__target);
            }
            break;
        case 6:
            {
                this->sliderPanel = safe_cast<::Windows::UI::Xaml::Controls::RelativePanel^>(__target);
            }
            break;
        case 7:
            {
                this->teamsControlPanel = safe_cast<::Windows::UI::Xaml::Controls::RelativePanel^>(__target);
            }
            break;
        case 8:
            {
                this->team1Panel = safe_cast<::Windows::UI::Xaml::Controls::RelativePanel^>(__target);
            }
            break;
        case 9:
            {
                this->Team2Panel = safe_cast<::Windows::UI::Xaml::Controls::RelativePanel^>(__target);
            }
            break;
        case 10:
            {
                this->PlayersInGameGrid = safe_cast<::Windows::UI::Xaml::Controls::Grid^>(__target);
            }
            break;
        case 11:
            {
                this->checkBoxT1P2 = safe_cast<::Windows::UI::Xaml::Controls::CheckBox^>(__target);
                (safe_cast<::Windows::UI::Xaml::Controls::CheckBox^>(this->checkBoxT1P2))->Click += ref new ::Windows::UI::Xaml::RoutedEventHandler(this, (void (::Stadium::MainPage::*)
                    (::Platform::Object^, ::Windows::UI::Xaml::RoutedEventArgs^))&MainPage::checkBoxT1P2_Click);
            }
            break;
        case 12:
            {
                this->checkBoxT1P3 = safe_cast<::Windows::UI::Xaml::Controls::CheckBox^>(__target);
                (safe_cast<::Windows::UI::Xaml::Controls::CheckBox^>(this->checkBoxT1P3))->Click += ref new ::Windows::UI::Xaml::RoutedEventHandler(this, (void (::Stadium::MainPage::*)
                    (::Platform::Object^, ::Windows::UI::Xaml::RoutedEventArgs^))&MainPage::checkBoxT1P3_Click);
            }
            break;
        case 13:
            {
                this->checkBoxT1P4 = safe_cast<::Windows::UI::Xaml::Controls::CheckBox^>(__target);
                (safe_cast<::Windows::UI::Xaml::Controls::CheckBox^>(this->checkBoxT1P4))->Click += ref new ::Windows::UI::Xaml::RoutedEventHandler(this, (void (::Stadium::MainPage::*)
                    (::Platform::Object^, ::Windows::UI::Xaml::RoutedEventArgs^))&MainPage::checkBoxT1P4_Click);
            }
            break;
        case 14:
            {
                this->checkBoxT1P5 = safe_cast<::Windows::UI::Xaml::Controls::CheckBox^>(__target);
                (safe_cast<::Windows::UI::Xaml::Controls::CheckBox^>(this->checkBoxT1P5))->Click += ref new ::Windows::UI::Xaml::RoutedEventHandler(this, (void (::Stadium::MainPage::*)
                    (::Platform::Object^, ::Windows::UI::Xaml::RoutedEventArgs^))&MainPage::checkBoxT1P5_Click);
            }
            break;
        case 15:
            {
                this->checkBoxT1P6 = safe_cast<::Windows::UI::Xaml::Controls::CheckBox^>(__target);
                (safe_cast<::Windows::UI::Xaml::Controls::CheckBox^>(this->checkBoxT1P6))->Click += ref new ::Windows::UI::Xaml::RoutedEventHandler(this, (void (::Stadium::MainPage::*)
                    (::Platform::Object^, ::Windows::UI::Xaml::RoutedEventArgs^))&MainPage::checkBoxT1P6_Click);
            }
            break;
        case 16:
            {
                this->checkBoxT2P2 = safe_cast<::Windows::UI::Xaml::Controls::CheckBox^>(__target);
                (safe_cast<::Windows::UI::Xaml::Controls::CheckBox^>(this->checkBoxT2P2))->Click += ref new ::Windows::UI::Xaml::RoutedEventHandler(this, (void (::Stadium::MainPage::*)
                    (::Platform::Object^, ::Windows::UI::Xaml::RoutedEventArgs^))&MainPage::checkBoxT2P2_Click);
            }
            break;
        case 17:
            {
                this->checkBoxT2P3 = safe_cast<::Windows::UI::Xaml::Controls::CheckBox^>(__target);
                (safe_cast<::Windows::UI::Xaml::Controls::CheckBox^>(this->checkBoxT2P3))->Click += ref new ::Windows::UI::Xaml::RoutedEventHandler(this, (void (::Stadium::MainPage::*)
                    (::Platform::Object^, ::Windows::UI::Xaml::RoutedEventArgs^))&MainPage::checkBoxT2P3_Click);
            }
            break;
        case 18:
            {
                this->checkBoxT2P4 = safe_cast<::Windows::UI::Xaml::Controls::CheckBox^>(__target);
                (safe_cast<::Windows::UI::Xaml::Controls::CheckBox^>(this->checkBoxT2P4))->Click += ref new ::Windows::UI::Xaml::RoutedEventHandler(this, (void (::Stadium::MainPage::*)
                    (::Platform::Object^, ::Windows::UI::Xaml::RoutedEventArgs^))&MainPage::checkBoxT2P4_Click);
            }
            break;
        case 19:
            {
                this->checkBoxT2P5 = safe_cast<::Windows::UI::Xaml::Controls::CheckBox^>(__target);
                (safe_cast<::Windows::UI::Xaml::Controls::CheckBox^>(this->checkBoxT2P5))->Click += ref new ::Windows::UI::Xaml::RoutedEventHandler(this, (void (::Stadium::MainPage::*)
                    (::Platform::Object^, ::Windows::UI::Xaml::RoutedEventArgs^))&MainPage::checkBoxT2P5_Click);
            }
            break;
        case 20:
            {
                this->checkBoxT2P6 = safe_cast<::Windows::UI::Xaml::Controls::CheckBox^>(__target);
                (safe_cast<::Windows::UI::Xaml::Controls::CheckBox^>(this->checkBoxT2P6))->Click += ref new ::Windows::UI::Xaml::RoutedEventHandler(this, (void (::Stadium::MainPage::*)
                    (::Platform::Object^, ::Windows::UI::Xaml::RoutedEventArgs^))&MainPage::checkBoxT2P6_Click);
            }
            break;
        case 21:
            {
                this->textEnergyTeam2 = safe_cast<::Windows::UI::Xaml::Controls::TextBox^>(__target);
            }
            break;
        case 22:
            {
                this->textScoreTeam2 = safe_cast<::Windows::UI::Xaml::Controls::TextBox^>(__target);
            }
            break;
        case 23:
            {
                this->textEnergyTeam1 = safe_cast<::Windows::UI::Xaml::Controls::TextBox^>(__target);
            }
            break;
        case 24:
            {
                this->textScoreTeam1 = safe_cast<::Windows::UI::Xaml::Controls::TextBox^>(__target);
            }
            break;
        case 25:
            {
                this->slider = safe_cast<::Windows::UI::Xaml::Controls::Slider^>(__target);
                (safe_cast<::Windows::UI::Xaml::Controls::Slider^>(this->slider))->ValueChanged += ref new ::Windows::UI::Xaml::Controls::Primitives::RangeBaseValueChangedEventHandler(this, (void (::Stadium::MainPage::*)
                    (::Platform::Object^, ::Windows::UI::Xaml::Controls::Primitives::RangeBaseValueChangedEventArgs^))&MainPage::slider_ValueChanged);
            }
            break;
        case 26:
            {
                this->textBlock = safe_cast<::Windows::UI::Xaml::Controls::TextBlock^>(__target);
            }
            break;
        case 27:
            {
                this->checkBoxPauseShow = safe_cast<::Windows::UI::Xaml::Controls::CheckBox^>(__target);
            }
            break;
        case 28:
            {
                this->checkBoxSound = safe_cast<::Windows::UI::Xaml::Controls::CheckBox^>(__target);
            }
            break;
        case 29:
            {
                this->startButton = safe_cast<::Windows::UI::Xaml::Controls::Button^>(__target);
                (safe_cast<::Windows::UI::Xaml::Controls::Button^>(this->startButton))->Click += ref new ::Windows::UI::Xaml::RoutedEventHandler(this, (void (::Stadium::MainPage::*)
                    (::Platform::Object^, ::Windows::UI::Xaml::RoutedEventArgs^))&MainPage::inputButton_Click);
            }
            break;
        case 30:
            {
                this->stopButton = safe_cast<::Windows::UI::Xaml::Controls::Button^>(__target);
                (safe_cast<::Windows::UI::Xaml::Controls::Button^>(this->stopButton))->Click += ref new ::Windows::UI::Xaml::RoutedEventHandler(this, (void (::Stadium::MainPage::*)
                    (::Platform::Object^, ::Windows::UI::Xaml::RoutedEventArgs^))&MainPage::stopButton_Click);
            }
            break;
        case 31:
            {
                this->textBlockTime = safe_cast<::Windows::UI::Xaml::Controls::TextBlock^>(__target);
            }
            break;
        case 32:
            {
                this->textBlockComent = safe_cast<::Windows::UI::Xaml::Controls::TextBlock^>(__target);
            }
            break;
    }
    _contentLoaded = true;
}

::Windows::UI::Xaml::Markup::IComponentConnector^ ::Stadium::MainPage::GetBindingConnector(int __connectionId, ::Platform::Object^ __target)
{
    __connectionId;         // unreferenced
    __target;               // unreferenced
    return nullptr;
}


