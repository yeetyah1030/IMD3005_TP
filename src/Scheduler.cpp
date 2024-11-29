#pragma once
#include "Scheduler.h"

Scheduler::Scheduler() {
    timer.setPeriodicEvent(1000000000); //in nanoseconds
    startThread();
    m_moodeng = NULL;
}

//getting the object
void Scheduler::setMoo(moodeng* moo) {
    m_moodeng = moo;
}

//do this after the timer
void Scheduler::threadedFunction() {
    while (isThreadRunning()) {
        timer.waitNext();
        // Do your thing here. It will run once per second.
        //object->setLocation();
        if (m_moodeng != NULL) {
            //change location and change colour
            m_moodeng->nextPicture();
        }
    }
}

//destructor so it all doesnt break
Scheduler::~Scheduler() {
    ofThread::waitForThread(true);
}