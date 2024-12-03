#pragma once
#include "ofMain.h"
#include "TP.h"
#include "moodeng.h"

class Scheduler :public ofThread {

public:
	Scheduler();
	~Scheduler();

	moodeng* m_moodeng;

	void setMoo(moodeng* moo);

	ofTimer timer;
	void threadedFunction();
};