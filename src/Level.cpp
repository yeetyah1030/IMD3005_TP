#include "Level.h"

Level::Level() {
    m_level = 100.0f;
    m_decreaseAmount = 0.0f;
    m_increaseAmount = 25.0f;
}

void Level::setDecrease(float amount) {
    m_decreaseAmount = amount;
}

void Level::decrease() {
    m_level -= m_decreaseAmount;

    if (m_level < 0.0f) {
        m_level = 0.0f;
    }
}

void Level::increase() {
    m_level += m_increaseAmount;

    if (m_level > 100.0f) {
        m_level = 100.0f;
    }
}

void Level::draw(int x) {
    ofSetColor(ofColor::black);
    ofDrawRectangle(0.0f +x, 0.0f, 110.0f, 30.0f);

    if (m_level > 60.0f) {
        ofSetColor(ofColor::green);
    }
    else if (m_level > 25.0f) {
        ofSetColor(ofColor::yellow);
    }
    else {
        ofSetColor(ofColor::red);
    }

    ofDrawRectangle(5.0f +x, 5.0f, m_level, 20.0f);
}