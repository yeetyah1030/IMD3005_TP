#pragma once
#include "ofMain.h"
#include "TP.h"
#include "Level.h"

class moodeng {

public:
    ofImage m_sleep1;
    ofImage m_sleep2;
    ofImage m_sleep3;
    ofImage m_rest1;
    ofImage m_rest2;
    ofImage m_bite1;
    ofImage m_bite2;
    ofImage m_dead;
    ofImage m_drink1;
    ofImage m_drink2;
    ofImage m_eat1;
    ofImage m_eat2;
    ofImage m_happy1;
    ofImage m_happy2;
    ofImage m_poop;

    ofImage* m_sleeping[2] = { &m_sleep1,&m_sleep2};
    ofImage* m_resting[2] = { &m_rest1, &m_rest2 };
    ofImage* m_biting[2] = { &m_bite1, &m_bite2 };
    ofImage* m_awake[2] = { &m_sleep3,&m_sleep3 };
    ofImage* m_dying[2] = { &m_dead, &m_dead };
    ofImage* m_eating[2] = { &m_eat1, &m_eat2 };
    ofImage* m_drinking[2] = { &m_drink1, &m_drink2 };
    ofImage* m_happy[2] = { &m_happy1, &m_happy2 };

    int m_counter;
    bool m_startDecrease;
    bool m_wakingUp;
    bool m_inAction;
    bool m_tookPoop;
    int m_poopSize;

    ofImage** m_currMoo;
    int m_currIndex;

    Level* m_happiness;
    Level* m_hunger;
    Level* m_thirst;

    moodeng();

    void nextPicture();
    void addHappy();
    void addFood();
    void addWater();
    void cleanPoop();
    void checkLevels();
    void draw();
};
