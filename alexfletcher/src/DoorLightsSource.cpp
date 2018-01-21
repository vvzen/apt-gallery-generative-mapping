#include "DoorLightsSource.h"

void DoorLightsSource:: atom(float posX, float posY, float radius, float p, ofColor r1, ofColor r2) {
    int numOfRings = 6;
    for (int rings = 0; rings < numOfRings; rings++) {
        float oscillation = 100;
        float phaseDiff = 180 / numOfRings;
        p = p + rings * phaseDiff;
        float localPhaseY = p * ofMap(cos(oscillation ), -1, 1, 0.5, 2);
        float localPhaseX = p * ofMap(sin(oscillation ), -1, 1, 0.5, 2);

        ofPushStyle();
        ofNoFill();
        ofSetLineWidth(4);
        ofSetCircleResolution(50);

        ofPushMatrix();
        ofTranslate(posX, posY);
        ofRotateY(localPhaseY);
        ofSetColor(r1);
        ofDrawEllipse(0, 0, radius, radius);
        ofPopMatrix();
        ofPopStyle();

        ofPushStyle();
        ofNoFill();
        ofSetLineWidth(4);
        ofSetCircleResolution(50);

        ofPushMatrix();
        ofTranslate(posX, posY);
        ofRotateX(localPhaseX);
        ofSetColor(r2);
        ofDrawEllipse(0, 0, radius+20, radius+20);
        ofPopMatrix();
        ofPopStyle();
    }
}
//--------------------------------------------------------------
void DoorLightsSource::setup(){
    // Give our source a decent name
    name = "Door Lights FBO Source";
    // Allocate our FBO source, decide how big it should be
    allocate(1000, 1000);

    ofBackground(0);
    ofSetBackgroundAuto(false);

    // screen size variables
    screenWidth = fbo->getWidth();
    screenHeight = fbo->getHeight();

    // Timer
    savedTime = ofGetElapsedTimeMillis();
    intervalTime = 1000;
    isFinished = false;
    //life
    life = 180;

    // initialise all variables and grid spacing for atoms
    atomSpacing = screenHeight/4;
    atomRadius = atomSpacing/4;
    phase=0;
    outerRingC = ofColor(170, 220, 255);

}

//--------------------------------------------------------------
void DoorLightsSource::update(){
    if(isFinished == false){
        // timer passed time
        int passedTime = ofGetElapsedTimeMillis() - savedTime;
        phase = phase + 0.5;

        // every second decrease life(180) = 3min totaltime and finish scene
        if(passedTime > intervalTime){
            if(life <= 0){
                isFinished = true;
            }else
                life--;
            savedTime = ofGetElapsedTimeMillis();
        }

    }
}

//--------------------------------------------------------------
void DoorLightsSource::draw(){
    ofSetColor(0,255);
    ofDrawRectangle(0,0,screenWidth,screenHeight);

    if(isFinished == false){
        // atom lights
        for(int y = -atomRadius*2; y < screenHeight - atomRadius; y += atomSpacing){
            for(int x = -atomRadius; x < screenWidth-atomRadius; x += atomSpacing){
                int locY = y + atomSpacing;
                int locX = x + atomSpacing;

                if(life > 150 || life < 120){
                    atomScale = ofMap(sin(phase/2 + (locY/2 + locX/2)),-1,1,1,3);
                    innerRingC = ofMap(sin(phase/2 + (locY/2 + locX/2)),-1,1,255,0);
                } else if( life > 120 && life < 150){
                    atomScale = ofMap(sin(phase/2 - (locY/2 - locX/2)),-1,1,1,3);
                    innerRingC = ofMap(sin(phase/2 - (locY/2 - locX/2)),-1,1,255,0);
                }
                atom(locX, locY, atomRadius/atomScale, phase, innerRingC, outerRingC );
            }
        }
    }
}


//--------------------------------------------------------------
