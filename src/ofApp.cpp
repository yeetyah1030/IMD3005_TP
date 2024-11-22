#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    m_timer.setMoo(&m_moo);

    m_happiness.setDecrease(0.1f);
    m_hunger.setDecrease(0.2f);
    m_thirst.setDecrease(0.05f);
}

//--------------------------------------------------------------
void ofApp::update(){
    m_happiness.decrease();
    m_thirst.decrease();
    m_hunger.decrease();
}

//--------------------------------------------------------------
void ofApp::draw(){
    m_moo.draw();
    m_happiness.draw(0);
    m_hunger.draw(150);
    m_thirst.draw(300);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
