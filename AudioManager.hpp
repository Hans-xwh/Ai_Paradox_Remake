#pragma once
#include <iostream>

using namespace System;
using namespace AxWMPLib;

ref class AudioMngr {
private:
	AxWindowsMediaPlayer^ Channel1;
	AxWindowsMediaPlayer^ Channel2;
	AxWindowsMediaPlayer^ Channel3;
	AxWindowsMediaPlayer^ Channel4;
	AxWindowsMediaPlayer^ Channel5;
	int generalVolume;				

public:
	AudioMngr() {
	}
	~AudioMngr() {
		if (Channel1) delete Channel1;
		if (Channel2) delete Channel2;
		if (Channel3) delete Channel3;
		if (Channel4) delete Channel4;
		if (Channel5) delete Channel5;
		generalVolume = 100;
	}

	void init_Channel1(System::String^ path) {
		if (Channel1) delete Channel1;
		Channel1 = gcnew AxWindowsMediaPlayer;
		Channel1->CreateControl();
		Channel1->URL = path;
		Channel1->Ctlcontrols->stop();
	}

	void init_Channel2(System::String^ path) {
		if (Channel2) delete Channel2;
		Channel2 = gcnew AxWindowsMediaPlayer;
		Channel2->CreateControl();
		Channel2->URL = path;
		Channel2->Ctlcontrols->stop();
	}

	void init_Channel3(System::String^ path) {
		if (Channel3) delete Channel3;
		Channel3 = gcnew AxWindowsMediaPlayer;
		Channel3->CreateControl();
		Channel3->URL = path;
		Channel3->Ctlcontrols->stop();
	}

	void init_Channel4(System::String^ path) {
		if (Channel4) delete Channel4;
		Channel4 = gcnew AxWindowsMediaPlayer;
		Channel4->CreateControl();
		Channel4->URL = path;
		Channel4->Ctlcontrols->stop();
	}

	void init_Channel5(System::String^ path) {
		if (Channel5) delete Channel5;
		Channel5 = gcnew AxWindowsMediaPlayer;
		Channel5->CreateControl();
		Channel5->URL = path;
		Channel5->Ctlcontrols->stop();
	}

	void Channel1_Play() { Channel1->Ctlcontrols->stop(); Channel1->Ctlcontrols->play(); }
	void Channel2_Play() { Channel2->Ctlcontrols->play(); }
	void Channel3_Play() { Channel3->Ctlcontrols->stop(); Channel3->Ctlcontrols->play(); }
	void Channel4_Play() { Channel4->Ctlcontrols->stop(); Channel4->Ctlcontrols->play(); }
	void Channel5_Play() { Channel5->Ctlcontrols->stop(); Channel5->Ctlcontrols->play(); }

	void Channel1_Stop() { Channel1->Ctlcontrols->stop(); }
	void Channel2_Stop() { Channel2->Ctlcontrols->stop(); }
	void Channel3_Stop() { Channel3->Ctlcontrols->stop(); }
	void Channel4_Stop() { Channel4->Ctlcontrols->stop(); }
	void Channel5_Stop() { Channel5->Ctlcontrols->stop(); }

	void Channel1_Volume(int V) { if (V < 0 || V > 100) V = 100; Channel1->settings->volume = V; }
	void Channel2_Volume(int V) { if (V < 0 || V > 100) V = 100; Channel2->settings->volume = V; }
	void Channel3_Volume(int V) { if (V < 0 || V > 100) V = 100; Channel3->settings->volume = V; }
	void Channel4_Volume(int V) { if (V < 0 || V > 100) V = 100; Channel4->settings->volume = V; }
	void Channel5_Volume(int V) { if (V < 0 || V > 100) V = 100; Channel5->settings->volume = V; }

	AxWindowsMediaPlayer^ getChannel(int C) {
		switch (C) {
		case 1:
			return Channel1;
		case 2:
			return Channel2;
		case 3:
			return Channel3;
		case 4:
			return Channel4;
		case 5:
			return Channel5;
		default:
			return Channel1;
		}
	}

	void setPlayerVolueme(int V) {
		generalVolume = V;

	}

};