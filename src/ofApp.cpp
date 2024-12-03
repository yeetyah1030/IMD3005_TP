#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

    // serial comms setup
    ofLogToConsole(); // ensure logs go to console
    ofSetLogLevel(OF_LOG_VERBOSE);


    // serial port setup
    serial.listDevices();
    deviceList = serial.getDeviceList();

    int baud = 9600;
    serial.setup("COM3", baud);

    // check if serial is initialized
    if (serial.isInitialized()) {
        ofLog() << "Serial port OPENED successfully!";
    }
    else {
        ofLog() << "FAILED to open serial port!";
    }


    // moodeng setup
    m_timer.setMoo(&m_moo);

    m_happiness.setDecrease(0.1f);
    m_hunger.setDecrease(0.2f);
    m_thirst.setDecrease(0.05f);
    m_background.load(TP::BACKGROUND_PATH);

    m_moo.m_happiness = &m_happiness;
    m_moo.m_thirst = &m_thirst;
    m_moo.m_hunger = &m_hunger;
}

//--------------------------------------------------------------
void ofApp::update() {

    // reading serial port messages
    if (serial.isInitialized()) {
        // # of bytes the serial has available for reading
        int numBytesToRead = serial.available();
        if (numBytesToRead > 512) {
            numBytesToRead = 512;
        }
        if (numBytesToRead > 0) {
            serialReadBuffer.clear();
            serial.readBytes(serialReadBuffer, numBytesToRead);
            serialReadString += serialReadBuffer.getText();

            string fullMessage = "";
            int eraseIndex = -1;
            for (int i = 0; i < serialReadString.length(); i++) {
                unsigned char character = serialReadString[i];
                if (character == '\n' || character == '\r' || character == '\t' || character == 13 || fullMessage.length() > 512) {
                    if (fullMessage.length() > 0) {
                        // trimming whitespace
                        fullMessage.erase(0, fullMessage.find_first_not_of(" \t\n\r"));
                        fullMessage.erase(fullMessage.find_last_not_of(" \t\n\r") + 1);

                        receivedSerialMessages.push_back(fullMessage);
                        eraseIndex = i;
                    }
                    fullMessage = "";
                }
                fullMessage += character;
            }
            if (eraseIndex > -1) {
                serialReadString = serialReadString.substr(eraseIndex + 1);
            }
        }
    }

    // processing received messages
    for (const auto& message : receivedSerialMessages) {
        ofLog() << "Received message: " << message;

        if (message == "water") {
            ofLog() << "Updating hydration levels...";
            m_moo.addWater();
        }
        if (message == "food") {
            ofLog() << "Updating hunger levels...";
            m_moo.addFood();
        }
        else if (message == "happiness") {
            ofLog() << "Updating happiness levels...";
            m_moo.addHappy();
        }
    }

    // clear messages after processing
    receivedSerialMessages.clear();

    // updating moodeng states
    if (m_moo.m_startDecrease == true) {
        m_happiness.decrease();
        m_thirst.decrease();
        m_hunger.decrease();
        m_moo.checkLevels();
    }
}

//--------------------------------------------------------------
void ofApp::draw() {
    ofSetColor(ofColor::white);
    m_background.draw(0.0f, 0.0f, ofGetWindowWidth(), ofGetWindowHeight());
    m_moo.draw();
    m_happiness.draw(10.0f);
    m_hunger.draw(ofGetWindowWidth() / 2.0f - ofGetWindowWidth() / 8.0f);
    m_thirst.draw(ofGetWindowWidth() - ofGetWindowWidth() / 4.0f - 10.0f);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    if (key == 32) {
        m_moo.addFood();
    }
    if (key == 3682) {
        m_moo.addHappy();
    }
    if (key == 3680) {
        m_moo.addWater();
    }
}