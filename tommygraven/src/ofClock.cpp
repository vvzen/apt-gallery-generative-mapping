//
//  ofClock.cpp
//  Scene1
//
//  Created by Tommy GRAVEN on 28/12/2017.
//

#include "ofClock.h"

void ofClock::setup(int _x, int _y, int _width, int _height){
    posX = _x;
    posY = _y;
    width = _width;
    height = _height;
}

void ofClock::update() {
      angle += 3 * speed;
      phase += 2 * speed;
    
      if (ofGetFrameNum() % (10 * 60) == 0)
        speed+= 0.5;
}

void ofClock::draw(ofColor _color){
        //color = _color;
        drawClock(posX, posY, width, height);
}

    //--------------------------------------------------------------
void ofClock::reset()
    {
      angle == 3 * speed;
      phase == 2 * speed;
      speed = 1;
    }
  
  //--------------------------------------------------------------
  void ofClock::drawClock(int x, int y, int width, int height){
        // Wavy value between 0 and 1
        float modulatingSize = (sin(ofDegToRad(phase))+1)/2;
        color.r = ofMap(modulatingSize, 0, 1, 0, 255);
        color.a = 5 + 5*speed*speed*speed*speed;
         if (ofGetFrameNum() % (10 * 60) == 0)
         {
             color.g = ofRandom(0, 255);
             color.b = ofRandom(0, 255);
         }
        float circleRes = ofMap(modulatingSize, 0, 1, 4, 25);
      
        float newHeight = ofMap(width, 0, 999, 0, 30);
      
      
        ofPushMatrix();
            ofTranslate(x, y);
            ofScale(1 - modulatingSize/2, 1 - modulatingSize/2);
            //ofSetCircleResolution(100);
            ofSetCircleResolution(circleRes);
            float strokeSize = (width / 10);
      
            // Exterior Circle
            ofSetColor(0);
            ofDrawCircle(0, 0, width);
      
            // Interior Circle
            ofSetColor(color);
            ofDrawCircle(0, 0, width - strokeSize);
      
            // Stylet (seconds)
            ofPushMatrix();
                ofRotate(angle);
                ofSetColor(255, 0, 0);
                ofSetLineWidth(newHeight);
                ofDrawLine(0, 0, width - 1.5 * strokeSize, 0);
            ofPopMatrix();
      
            // Stylet (minutes)
            ofPushMatrix();
                int angleRounded = angle / 60;
                ofRotate(angleRounded);
                ofSetColor(0, 0, 0);
                ofSetLineWidth(newHeight*2);
                ofDrawLine(0, 0, width - 2*strokeSize, 0);
            ofPopMatrix();
      
            // Stylet (hours)
            ofPushMatrix();
                int angleRounded2 = angle / 3600;
                ofRotate(angleRounded2);
                ofSetColor(0, 0, 0);
                ofSetLineWidth(newHeight*3);
                ofDrawLine(0, 0, width - 6*strokeSize, 0);
            ofPopMatrix();
      
        ofPopMatrix();
    }

