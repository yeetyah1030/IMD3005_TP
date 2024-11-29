#pragma once

#include "ofMain.h"
#include "TP.h"
#include "Scheduler.h"
#include "moodeng.h"
#include "Level.h"


class ofApp : public ofBaseApp{

	public:
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
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};
