//// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
//// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
//// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
//// PARTICULAR PURPOSE.
////
//// Copyright (c) Microsoft Corporation. All rights reserved

#pragma once
//#include "DirectXBase.h" 

#include "mmreg.h" 
#include <vector> 
#include <memory> 
 #include "DirectXMath.h"

ref class Audio
{
public:
	Audio();

	void Initialize();
	void CreateDeviceIndependentResources();
	IXAudio2* MusicEngine();
	IXAudio2* SoundEffectEngine();
	void SuspendAudio();
	void ResumeAudio();

protected:
	bool                                m_audioAvailable;
	Microsoft::WRL::ComPtr<IXAudio2>    m_musicEngine;
	Microsoft::WRL::ComPtr<IXAudio2>    m_soundEffectEngine;
	IXAudio2MasteringVoice*             m_musicMasteringVoice;
	IXAudio2MasteringVoice*             m_soundEffectMasteringVoice;

};
