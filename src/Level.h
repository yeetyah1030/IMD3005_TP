#pragma once
#include "ofMain.h"
#include "TP.h"

class Level
{
public:
    float m_level;
    float m_decreaseAmount;
    float m_increaseAmount;
    
    Level();
    void setDecrease(float amount);
    void decrease();
    void increase();

    void draw(int x);



};