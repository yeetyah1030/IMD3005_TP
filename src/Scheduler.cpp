#pragma once
#include "Scheduler.h"

Scheduler::Scheduler() {
    timer.setPeriodicEvent(1000000000); //in nanoseconds
    startThread();
    m_moodeng = NULL;
    m_poopCounter = 0;
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
            
            /*m_poopCounter++;

            if (m_poopCounter % 30 == 0) {
                if (m_moodeng->m_tookPoop == true) {
                    m_moodeng->m_poopSize--;
                    if (m_moodeng->m_poopSize == 0) {
                        m_moodeng->m_poopSize = 1; 
                    }
                }
                else {
                    m_moodeng->m_poopSize = 10;
                }
            m_moodeng->m_tookPoop = true;
            m_moodeng->m_poopSound.play();
            }*/
        }
        
    }
}

//destructor so it all doesnt break
Scheduler::~Scheduler() {
    ofThread::waitForThread(true);
}