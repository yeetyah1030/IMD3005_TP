#pragma once
#include "moodeng.h"

moodeng::moodeng() {
    //load images
    m_sleep1.load(TP::SLEEPING1_PATH_COLOUR);
    m_sleep2.load(TP::SLEEPING2_PATH_COLOUR);
    m_sleep3.load(TP::SLEEPING3_PATH_COLOUR);
    m_rest1.load(TP::RESTING1_PATH_COLOUR);
    m_rest2.load(TP::RESTING2_PATH_COLOUR);
    m_bite1.load(TP::BITING1_PATH_COLOUR);
    m_bite2.load(TP::BITING2_PATH_COLOUR);

    //currently printing which images
    m_currMoo = m_sleeping;
    m_currIndex = 0;

    m_happiness = 100;
    m_thirst = 100;
    m_hunger = 100;



}

void moodeng::addHappy() {

}

void moodeng::addFood() {

}

void moodeng::addWater() {

}

void moodeng::draw() {
    m_currMoo[m_currIndex]->draw(0.0f, 0.0f);
}

void moodeng::nextPicture() {
    if (m_currIndex == 0) {
        m_currIndex++;
    }
    else {
        m_currIndex = 0;
    }
}