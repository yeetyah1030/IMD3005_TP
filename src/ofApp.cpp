#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
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
void ofApp::update(){
    if (m_moo.m_startDecrease == true) {
        m_happiness.decrease();
        m_thirst.decrease();
        m_hunger.decrease();
        m_moo.checkLevels();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(ofColor::white);
    m_background.draw(0.0f, 0.0f, ofGetWindowWidth(), ofGetWindowHeight());
    m_moo.draw();
    m_happiness.draw(10.0f);
    m_hunger.draw(ofGetWindowWidth()/2.0f - ofGetWindowWidth()/8.0f);
    m_thirst.draw(ofGetWindowWidth() - ofGetWindowWidth() / 4.0f - 10.0f);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
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

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
