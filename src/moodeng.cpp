#pragma once
#include "moodeng.h"

moodeng::moodeng() {
    //load images
    m_sleep1.load(TP::SLEEPING1_PATH);
    m_sleep2.load(TP::SLEEPING2_PATH);
    m_sleep3.load(TP::SLEEPING3_PATH);
    m_rest1.load(TP::RESTING1_PATH);
    m_rest2.load(TP::RESTING2_PATH);
    m_bite1.load(TP::BITING1_PATH);
    m_bite2.load(TP::BITING2_PATH);
    m_dead.load(TP::DEAD_PATH);

    //currently printing which images
    m_currMoo = m_sleeping;
    m_currIndex = 0;
    m_sleepingCounter = 0;

    m_happiness = NULL;
    m_thirst = NULL;
    m_hunger = NULL;
    m_startDecrease = false;
}

void moodeng::addHappy() {

}

void moodeng::addFood() {

}

void moodeng::addWater() {

}

//draws the immage
void moodeng::draw() {
    ofSetColor(ofColor::white);
    m_currMoo[m_currIndex]->draw(ofGetWindowWidth()/2.0f - ofGetWindowWidth() / 4.0f, ofGetWindowHeight() / 2 - ofGetWindowWidth() / 4.0f, ofGetWindowWidth()/2.0f, ofGetWindowWidth()/2.0f);
}

//loops throught the photos
void moodeng::nextPicture() {
    if (m_sleepingCounter > 2 && m_sleepingCounter < 4) {
        m_currMoo = m_awake;
    }
    if (m_sleepingCounter == 4) {
        m_currMoo = m_resting;
        m_startDecrease = true;
    }

    if (m_currIndex == 0) {
        m_currIndex++;
    }
    else {
        m_currIndex = 0;
    }
    m_sleepingCounter++;
}

void moodeng::checkLevels() {
    if (m_happiness != NULL) {
        if (m_happiness->m_level == 0.0f || m_thirst->m_level == 0.0f || m_hunger->m_level == 0.0f) {
            m_currMoo = m_dying;
        }
        else if (m_happiness->m_level < 20.0f || m_thirst->m_level < 20.0f || m_hunger->m_level < 20.0f) {
            m_currMoo = m_biting;
        }
    }
}