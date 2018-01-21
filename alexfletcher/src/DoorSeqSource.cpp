#include "DoorSeqSource.h"
void DoorSeqSource:: strobeDoor(float x, float y, float w, float h, float roundness, float rotY, ofColor c){
    ofPushMatrix();
    ofPushStyle();
    ofSetCircleResolution(400);
    ofSetColor(c);
    ofNoFill();
    ofSetLineWidth(10);

    ofSetRectMode(OF_RECTMODE_CENTER);
    ofTranslate(x, y);
    ofRotateY(rotY);
    ofDrawRectRounded(0,0,w,h,roundness);

    ofPopMatrix();
    ofPopStyle();

}
//--------------------------------------------------------------
void DoorSeqSource::setup(){
    // Give our source a decent name
    name = "Door Seq FBO Source";
    // Allocate our FBO source, decide how big it should be
    allocate(1500, 1000);

    ofBackground(0);
    ofSetBackgroundAuto(false);

    // screen size variables
    screenWidth = fbo->getWidth();
    screenHeight = fbo->getHeight();

    // initialise timers ( main and rotating doors)
    int timers = 2;
    for(int t = 0; t < timers; t++){
        //timers
        savedTime.assign(t,ofGetElapsedTimeMillis());
        intervalTime.assign(t,1000);
    }
    //reverse door timer
    intervalTime[1] = 1000*30;

    // event booleans
    isFinished = false;
    reverseDoors = false;

    //color alpha linked to life (3 mins sequence)
    alpha = 255;
    life = 180;

    // initialise all variables and grid spacing for stobepanels
    doorWidth = screenWidth/4;
    doorHeight = screenHeight;
    doorSpacing = doorWidth/2;
    doorRoundness = 0;

    // initialise phase variables;
    phase = 360;
    pSpeed = 0;
}
void DoorSeqSource::setName(string _name){
    name = _name;
}

//--------------------------------------------------------------
void DoorSeqSource::update(){
    if(isFinished == false){

        // timers passed time
        int passedTime = ofGetElapsedTimeMillis() - savedTime[0];
        int doorspassedTime = ofGetElapsedTimeMillis() - savedTime[1];

        // map alpha to life (countdown of 3min)
        alpha = ofMap(life,180,0,255,0);

        // start backward door rotation and roundness
        if(reverseDoors == false){
            if(phase >= 357){
                pSpeed = pSpeed - 0.00012;
                phase = phase - pSpeed;
                doorRoundness = doorRoundness + pSpeed;
            }
            // once 10 secs has gone start forward door rotation and roundness
            if(doorspassedTime > intervalTime[1]){
                reverseDoors = true;
            }
        } else if(reverseDoors == true){
            if(pSpeed < 2.5)pSpeed = pSpeed + 0.00012;
            phase = phase + pSpeed;
            doorRoundness = doorRoundness + pSpeed;
        }

        // every second decrease life(180) = 3min totaltime and finish scene
        if(passedTime > intervalTime[0]){
            if(life <= 0){
                isFinished = true;
            }else
                life--;
            savedTime[0] = ofGetElapsedTimeMillis();
        }
    }
}

//--------------------------------------------------------------
void DoorSeqSource::draw(){
    ofClear(0); // clear the buffer

    if(isFinished == false){
        // background
        ofPushStyle();
        ofSetColor(0,255);
        ofDrawRectangle(0,0,screenWidth,screenHeight);
        ofPopStyle();

        // colour changes over sequence
        if(reverseDoors == false){
            ofPushStyle();
            c1 = ofColor(170, 220, 255,alpha);
            c2 = ofColor(220, 255, 70, alpha);
            float c = ofMap(cos(phase * pSpeed),-1,1,255,0);
            panelC = ofColor(c,c,c,alpha);
            ofPopStyle();
        } else if (reverseDoors == true && life > 120){
            ofPushStyle();
            c1 = ofColor(220, 255, 170, alpha);
            c2 = ofColor(70, 220, 255,alpha);
            panelC = ofColor(0,0,0,0);
            ofPopStyle();
        } else if (life < 120 && life > 75){
            ofPushStyle();
            c1 = ofColor(170, 220, 255,alpha);
            c2 = ofColor(220, 255, 70, alpha);
            float c = ofMap(sin(phase/10),-1,1,255,0);
            panelC = ofColor(c,c,c,alpha) ;
            ofPopStyle();
        } else if (life < 75){
            ofPushStyle();
            c1 = ofColor(70, 170, 255, alpha);
            c2 = ofColor(170, 255, 220,alpha);
            float c = ofMap(ofSignedNoise(phase / pSpeed),-1,1,255,0);
            panelC = ofColor(c,c,c,alpha);
            ofPopStyle();
        }


        // Make a grid for panels to sit in (4 panels to match object)
        for(int x = 0; x < screenWidth; x += doorSpacing*2){

            // position panels in grid
            int locX = x + doorSpacing;

            // draw panels
            strobeDoor(locX, screenHeight/2, doorWidth, doorHeight, doorRoundness, 0, panelC);

            // innner rotating doors
            int numOfDoors = 4;
            for (int i = 0; i < numOfDoors; i++){
                ofPushStyle();
                ofColor c = c1.getLerped(c2, ofMap(i, 0, 4, 0, 1));
                ofPopStyle();
                // movement variables
                float localPhase = phase  + i * 180/numOfDoors;
                float widthDiff = phase - i * ofMap(sin(ofDegToRad(localPhase)), -1,1,0,doorWidth);
                float HeightDiff = phase - i* ofMap(sin(ofDegToRad(localPhase)), -1,1,0,doorHeight);
                // draw rotating doors
                strobeDoor(locX,screenHeight/2, doorWidth+90- widthDiff, doorHeight - 180 - HeightDiff, doorRoundness, localPhase, c);

            }
        }
    }
}

//--------------------------------------------------------------



