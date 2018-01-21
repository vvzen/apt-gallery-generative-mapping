#include "SwirlRects.h"
void SwirlRects::setup(){
    //match the background to partTwo
    name = "swirl rects";
    allocate(768,768);
    movingColor = ofColor(245,245,245);
    inc = 0;
    shapeSize = 200;
    // get the number of shapes from how many fit in the area
    shapeCount = (fbo->getWidth()/shapeSize)*(fbo->getHeight()/shapeSize);
    // set the counters
    startTime = ofGetElapsedTimeMillis();
    cTime = ofGetElapsedTimeMillis();
}

//--------------------------------------------------------------
void SwirlRects::update(){
    //increment the main counter
    inc++;
}


void SwirlRects::setName(string _name){
    name = _name;
}

//--------------------------------------------------------------
void SwirlRects::draw(){
    // use the same background colors as the other scenes.
    ofBackground(0,1,35);
    int a = 0;
    //draw out the grid
    for(int x = 0; x < sqrt(shapeCount); x++){
        for(int y = 0; y < sqrt(shapeCount); y++){
            // call the custom shape
            drawSquare(x*shapeSize+(shapeSize/2),y*shapeSize+(shapeSize/2),shapeSize,shapeSize,inc+a);
            //increment the secondary counter with every shape
            //this is the delay between the squares, the bigger the number the bigger
            //the difference between the first square and the last
            a++;
        }
    }
}

void SwirlRects::drawSquare(int x, int y, int w, int h, int inc){
    ofPushStyle();
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofPushMatrix();
    //translat to the location
    ofTranslate(x,y);
    //check the result of the sin
    float sinResult = sin(inc*0.01);
    // if it is at the end or beggining of the sin wave then do this
    if(sinResult <= -0.99999 || sinResult >=0.99999){
        // if it hasnt done this for the past 3 seconds (so it doesnt
        // flicker loads)
        //
        // What i wanted here was for the colors to change at the biggest and
        // smallest points.
        if(ofGetElapsedTimeMillis() - cTime > 3000){
            // reset the timer
            cTime = ofGetElapsedTimeMillis();
            // change the red of the color
            movingColor = ofColor(ofRandom(10,860), 64, 126);
        }
    }
    ofFill();
    ofRotate(ofMap(sin(inc*0.01),-1,1,-180,360)+ofNoise(inc));
    // as it scales i am hoping the squares fall in and out of overlapping our /\/\ shape
    // this way it will seem to switch between being one image across the concertina
    // to being separate panels.
    ofScale(ofMap(sin(inc*0.01),-1,1,0.5,1),ofMap(sin(inc*0.01),-1,1,0.5,1));
    ofSetColor(movingColor);
    ofDrawRectangle(0,0,w,h);
    ofPopMatrix();
    ofPopStyle();
}

