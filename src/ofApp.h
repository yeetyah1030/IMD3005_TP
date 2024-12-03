#pragma once

#include "ofMain.h"
#include "TP.h"
#include "Scheduler.h"
#include "moodeng.h"
#include "Level.h"


class ofApp : public ofBaseApp{

	public:
		// serial port stuff
		ofSerial serial;
		ofBuffer serialReadBuffer;
		//
		vector <ofSerialDeviceInfo> deviceList;

		// store all of the received messages
		vector<string> receivedSerialMessages;

		// device to connect
		string serialDevicePathToConnectTo = "";

		// keep a history of the bytes read from the serial device so we can split it based on a character
		string serialReadString = "";

		moodeng m_moo;
		Scheduler m_timer;
		Level m_happiness;
		Level m_hunger;
		Level m_thirst;

		ofImage m_background;

		void setup();
		void update();
		void draw();

		void keyPressed(int key);
};
