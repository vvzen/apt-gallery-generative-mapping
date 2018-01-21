#include "ofApp.h"

//--------------------------------------------------------------
void HypnotizeSource::setup(){
     name = "Hypnotize FBO Source";
    // Allocate our FBO source, decide how big it should be
    allocate(800, 800);

    ofBackground(0);
    color1.r = 0;
    color1.g = 0;
    color1.b = 0;
    color1.a = 30;
    
    color2.r = 255;
    color2.g = 255;
    color2.b = 255;
    color2.a = 30;
    
    ofSetBackgroundAuto(true);
}

//--------------------------------------------------------------
void HypnotizeSource::update(){
    angle++;
    phase++;
}

//--------------------------------------------------------------
void HypnotizeSource::draw(){
    timer++;
     /*ofPushMatrix();
        ofSetColor(0, 0, 0);
        ofDrawRectangle(0, 0, 0, fbo->getWidth(), fbo->getHeight());
    ofPopMatrix();*/

    ofSetCircleResolution(100);
    
     // Background animation
    float numberOfCircles2 = 40;
    float circleNr = numberOfCircles2;
    float rad;
    
    
    
    if (timer % (10 * 60) == 0)
    {
        colorTransition();
        modulatingSpeed+= 0.5;
    }
    
    if (timer % 5 == 0)
        switchColors(color1, color2);
    
    if (fbo->getWidth() > fbo->getHeight())
        rad = fbo->getWidth();
    else rad = fbo->getHeight();
    
    for (int i = numberOfCircles2 ; i > 0; i--)
    {
        ofSetColor(color1.r / 2, color1.g / 2, color1.b / 2);
        if (i % 2 == 0)
            ofSetColor(color2.r / 2, color2.g / 2, color2.b / 2);
        ofDrawCircle(fbo->getWidth() / 2, fbo->getHeight() / 2, rad * circleNr/numberOfCircles2);
        circleNr--;
    }
    
    if (timer > (60 * 10))
    {
    ofPushMatrix();
        drawYoyo();
    ofPopMatrix();
    }
    
    if (timer > (60 * 20)  && timer < (60 * 30))
    {
    ofPushMatrix();
        ofTranslate(-200, 0);
        drawYoyo();
    ofPopMatrix();
    
     ofPushMatrix();
        ofTranslate(200, 0);
        drawYoyo();
    ofPopMatrix();
    }
}

//--------------------------------------------------------------
void HypnotizeSource::reset(){
    modulatingSpeed = 2;
    timer = 0;
}

//--------------------------------------------------------------
void HypnotizeSource::drawYoyo(){
    
    float modulatingSize = sin(ofDegToRad(modulatingSpeed*phase));
    

    float posX = fbo->getWidth() / 2;
    float posY = fbo->getHeight() / 2 - 300;
    float lineLength = 300;

    ofTranslate(posX, posY);
    ofRotate(modulatingSize * 30);
    if (timer > (60 * 30))
            ofScale(1.5, 1.5);
    
    // Line
    ofSetLineWidth(6);
    ofSetColor(0, 0, 0);
    ofDrawLine(0, 0, 0, lineLength);
    
    int size = 100;
    ofTranslate(0, lineLength + size/2);
    
    // Circle
    int numberOfCircles = 10;
    float offset = size / numberOfCircles;
    
     for (int i = 0; i < numberOfCircles; i++)
    {
        float uniquePhase = 10*phase - i * 31;
        drawRing(uniquePhase, size - i * (size / numberOfCircles)+1, offset);
    }
}

//--------------------------------------------------------------
void HypnotizeSource::switchColors(ofColor _color1, ofColor _color2){
    ofColor tempColor = _color1;
    color1= _color2;
    color2= tempColor;
}

//--------------------------------------------------------------
void HypnotizeSource::drawRing(int p, float size, float _offset){
    ofPushMatrix();
    //ofSetColor(255);
    ofSetColor(color1.r, color1.g, color1.b);
    
    ofSetCircleResolution(100);
    float modulatingSize = (sin(ofDegToRad(p))+1)/2;
    float offset = modulatingSize * _offset;
    ofDrawCircle(0, 0, size + offset+1);
    //ofSetColor(0);
    ofSetColor(color2.r, color2.g, color2.b);
    ofDrawCircle(0, 0, size);
    ofPopMatrix();
}

//--------------------------------------------------------------
void HypnotizeSource::colorTransition(){
    color1.r = ofRandom(0, 150);
    color1.g = ofRandom(0, 150);
    color1.b = ofRandom(0, 150);
    
    color2.r = ofRandom(200, 255);
    color2.g = ofRandom(200, 255);
    color2.b = ofRandom(200, 255);
}

//--------------------------------------------------------------
void HypnotizeSource::keyPressed(int key){

}

//--------------------------------------------------------------
void HypnotizeSource::keyReleased(int key){

}

//--------------------------------------------------------------
void HypnotizeSource::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void HypnotizeSource::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void HypnotizeSource::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void HypnotizeSource::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void HypnotizeSource::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void HypnotizeSource::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void HypnotizeSource::windowResized(int w, int h){

}

//--------------------------------------------------------------
void HypnotizeSource::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void HypnotizeSource::dragEvent(ofDragInfo dragInfo){ 

}
