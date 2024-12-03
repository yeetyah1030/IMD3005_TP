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
    m_drink1.load(TP::DRINKNG1_PATH);
    m_drink2.load(TP::DRINKING2_PATH);
    m_eat1.load(TP::EATING1_PATH);
    m_eat2.load(TP::EATING2_PATH);
    m_happy1.load(TP::HAPPY1_PATH);
    m_happy2.load(TP::HAPPY2_PATH);
    m_poop.load(TP::POOP_PATH);

    //currently printing which images
    m_currMoo = m_sleeping;
    m_currIndex = 0;
    m_counter = 0;
    m_wakingUp = true;
    m_inAction = false;
    m_tookPoop = false;
    m_poopSize = 10;

    m_happiness = NULL;
    m_thirst = NULL;
    m_hunger = NULL;
    m_startDecrease = false;
}

void moodeng::addHappy() {
    if (m_wakingUp == false) {
        if (m_inAction == false) {
            m_startDecrease = false;
            m_inAction = true;
            m_currMoo = m_happy;
            m_happiness->increase();
            m_counter = 0;
        }
    }
}

void moodeng::addFood() {
    if (m_wakingUp == false) {
        if (m_inAction == false) {
            m_startDecrease = false;
            m_inAction = true;
            m_currMoo = m_eating;
            m_hunger->increase();
            m_counter = 0;
        }
    }
}

void moodeng::addWater() {
    if (m_wakingUp == false) {
        if (m_inAction == false) {
            m_startDecrease = false;
            m_inAction = true;
            m_currMoo = m_drinking;
            m_hunger->increase();
            m_counter = 0;
        }
    }
}

//draws the immage
void moodeng::draw() {
    ofSetColor(ofColor::white);
    m_currMoo[m_currIndex]->draw(ofGetWindowWidth()/2.0f - ofGetWindowWidth() / 4.0f, ofGetWindowHeight() / 2 - ofGetWindowWidth() / 4.0f, ofGetWindowWidth()/2.0f, ofGetWindowWidth()/2.0f);

    if (m_tookPoop == true) {
        ofSetRectMode(OF_RECTMODE_CENTER);
        m_poop.draw(ofGetWindowWidth() - ofGetWindowWidth() / 5.0f, ofGetWindowHeight() - ofGetWindowHeight() / 4.0f, ofGetWindowWidth() / m_poopSize, ofGetWindowWidth() / m_poopSize);
    }
    ofSetRectMode(OF_RECTMODE_CORNER);
}

//loops throught the photos
void moodeng::nextPicture() {

    if (m_wakingUp == true) {
        if (m_counter > 2 && m_counter < 4) {
            m_currMoo = m_awake;
        }
        else if (m_counter == 4) {
            m_currMoo = m_resting;
            m_startDecrease = true;
            m_wakingUp = false;
        }
    }
    
    if (m_wakingUp == false) {
        if(m_counter == 4){
            m_startDecrease = true;
            m_currMoo = m_resting;
            m_inAction = false;
        }
    }

    if (m_currIndex == 0) {
        m_currIndex++;
    }
    else {
        m_currIndex = 0;
    }
    m_counter++;
}

void moodeng::checkLevels() {
    if (m_happiness != NULL) {
        if (m_happiness->m_level == 0.0f || m_thirst->m_level == 0.0f || m_hunger->m_level == 0.0f||m_poopSize==1) {
            m_currMoo = m_dying;
            m_startDecrease = false;
        }
        else if (m_happiness->m_level < 40.0f || m_thirst->m_level < 40.0f || m_hunger->m_level < 40.0f||m_poopSize<3) {
            m_currMoo = m_biting;
        }
    }
}

void moodeng:: cleanPoop() {
    if (m_inAction == false) {
        m_tookPoop = false; 
    }
}