#include "eceSource.h"

//--------------------------------------------------------------
void EceSource::reset(){
	ofClear(0);
}

//--------------------------------------------------------------
void EceSource::setup(){
    ofBackground(0);

	// Give our source a decent name
    name = "Doruk Source";

	// Allocate our FBO source
    allocate(1024, 768);

	// clear fbo
    this->beginFbo();
        ofClear(255,0,0);
    this->endFbo();

    ofBackground(0);
	ofSetCircleResolution(60);
}

//--------------------------------------------------------------
void EceSource::setName(string _name){
    name = _name;
}

//--------------------------------------------------------------
// Don't do any drawing here
void EceSource::update(){
    
}

//--------------------------------------------------------------
void EceSource::draw(){

	spacing = 20;
    colorChange = colorChange + 0.1;
    redcolorchange = redcolorchange + 0.1;
    ballrolling = ballrolling + 0.1;
    lineslim = lineslim + 0.1;
    colorChangeBigCircle = colorChangeBigCircle + 0.1;

    for (int ii = 0; ii < 640; ii = ii + spacing * 2)	 //red shaking circles
    {
        ofPushMatrix();
        ofSetColor((sin(ofDegToRad(redcolorchange)) + 1) * 100, 0, 0); 
        ofTranslate(ofRandom(200, 250), (sin(ofDegToRad(ballrolling)) + 1) * 100);	//by using ofRandom, it gives the effect as if the red balls are shaking or glitching in x, but moving smoothly in y because of sin.
        ofDrawCircle(60, spacing + ii, 35 + ii / 30);
        ofPopMatrix();
    }

    for (int ii = 0; ii < 640; ii = ii + spacing * 2)	//red shaking circles
    {
        ofPushMatrix();
        ofSetColor((sin(ofDegToRad(redcolorchange)) + 1) * 100, 0, 0); 
        ofTranslate(ofRandom(200, 250), (sin(ofDegToRad(ballrolling)) + 1) * 100);
        ofDrawCircle(-58, spacing + ii, 25 + ii / 30);
        ofPopMatrix();
    }

    for (int ii = 0; ii < 640; ii = ii + spacing * 2)	//red shaking circles
    {
        ofPushMatrix();
        ofSetColor((sin(ofDegToRad(redcolorchange)) + 1) * 100, 0, 0);
        ofTranslate(ofRandom(200, 250), (sin(ofDegToRad(ballrolling)) + 1) * 100);
        ofDrawCircle(180, spacing + ii, 25 + ii / 30);
        ofPopMatrix();
    }

    for (int ii = 0; ii < 640; ii = ii + spacing * 2)	//red shaking circles
    {
        ofPushMatrix();
        ofSetColor((sin(ofDegToRad(redcolorchange)) + 1) * 100, 0, 0);
        ofTranslate(ofRandom(200, 250), (sin(ofDegToRad(ballrolling)) + 1) * 100);
        ofDrawCircle(300, spacing + ii, 18 + ii / 30);
        ofPopMatrix();
    }

    for (int ii = 0; ii < 640; ii = ii + spacing * 2)	//red shaking circles
    {
        ofPushMatrix();
        ofSetColor((sin(ofDegToRad(redcolorchange)) + 1) * 100, 0, 0);
        ofTranslate(ofRandom(200, 250), (sin(ofDegToRad(ballrolling)) + 1) * 100);
        ofDrawCircle(-180, spacing + ii, 18 + ii / 30);
        ofPopMatrix();
    }

    //big circle that first appears yellow and comes to center from top of the screen
    for (int ii = 0; ii < 600; ii = ii + spacing * 2)
    {
    if (ballrolling >= 50) //approximately when the big ball comes to the center this code starts to run. 
    {						//and then continues to change its color in green value, first ball seems yellow, after this if statement, it turns to orange,then red, then green, then yellow again...
        colorChangeBigCircle = colorChangeBigCircle -0.01;
    }
        ofPushMatrix();
        ofSetColor(ofColor((sin(ofDegToRad(colorChange)) + 1) * 100, (sin(ofDegToRad(colorChangeBigCircle)) + 1) * 100, 0));
        ofTranslate(220, (sin(ofDegToRad(ballrolling)) + 1) * 300);
        ofDrawCircle(60, -300, 250 );
        ofPopMatrix();
    }

    //smaller circles first appear red, then turns to black
    for (int ii = 0; ii < 600; ii = ii + spacing * 2)
    {
        ofPushMatrix();
        ofSetColor(ofColor((sin(ofDegToRad(colorChange)) + 1) * 100, 0, 0));
        ofTranslate(ofRandom(200, 250), (sin(ofDegToRad(ballrolling)) + 1) * 100);
        ofDrawCircle(60, spacing + ii, 5 + ii / 30);
        ofPopMatrix();
    }

    //smaller circles first appear red, then turns to black
    for (int ii = 0; ii < 1000; ii = ii + spacing * 2)
    {
        ofPushMatrix();
        ofSetColor(ofColor((sin(ofDegToRad(colorChange)) + 1) * 100, 0, 0));
        ofTranslate(ofRandom(200, 250), (sin(ofDegToRad(ballrolling)) + 1) * 100);
        ofDrawCircle(-58, spacing + ii, 5 + ii / 30);
        ofPopMatrix();
    }

    //smaller circles first appear red, then turns to black
    for (int ii = 0; ii < 1000; ii = ii + spacing * 2)
    {
        ofPushMatrix();
        ofSetColor(ofColor((sin(ofDegToRad(colorChange)) + 1) * 100, 0, 0));
        ofTranslate(ofRandom(200, 250), (sin(ofDegToRad(ballrolling)) + 1) * 100);
        ofDrawCircle(180, spacing + ii, 5 + ii / 30);
        ofPopMatrix();
    }

    //violet, more thick lines
    for (int i = 0; i < 1000; i = i + spacing * 2)	//to increase the feeling of tension in red shaking balls, I made lines moving smoothly so that movement between shaking balls and lines are separeted.
    {
        ofPushMatrix();
        ofSetColor(ofColor((sin(ofDegToRad(colorChange)) + 1) * 50, 0, 200 ));
        ofTranslate(0, (sin(ofDegToRad(ballrolling)) + 1) * 100);
        ofDrawRectangle(0, -200 + i, 575, (sin(ofDegToRad(lineslim)) + 1)*10 );
        ofPopMatrix();
    }

    //blue slim lines
    for (int i = 0; i < 1000; i = i + spacing * 2)
    {
        ofPushMatrix();
        ofSetColor(ofColor(0, 50, 200));
        ofTranslate(0, (sin(ofDegToRad(ballrolling)) + 1) * 200);
        ofDrawRectangle(0, -200 + i, 575, 1);
        ofPopMatrix();
    }

    //blue slim lines 
    for (int i = 0; i < 1000; i = i + spacing * 2)
    {
        ofPushMatrix();
        ofSetColor(ofColor(0, 50, 200));
        ofTranslate(0, (sin(ofDegToRad(ballrolling)) + 1) * 400);
        ofDrawRectangle(0, -200 + i, 575, 1);
        ofPopMatrix();
    }

    //cream clored slim lines
    for (int i = 0; i < 640; i = i + spacing * 2)
    {
        ofPushMatrix();
        ofSetColor(ofColor((sin(ofDegToRad(colorChange)) + 1) * 100,  (sin(ofDegToRad(colorChange)) + 1) * 100, (sin(ofDegToRad(colorChange)) + 1) * 100)); 
        ofTranslate(0, (sin(ofDegToRad(ballrolling)) - 1) * 200);
        ofDrawRectangle(0, spacing + i, 575, 1 + i / 100);
        ofPopMatrix();
    }

    //pink lines
    for (int i = 0; i < 2000; i = i + spacing * 2)
    {
        ofPushMatrix();
        ofSetColor(ofColor( (sin(ofDegToRad(colorChange)) + 1) * 100,0,(sin(ofDegToRad(colorChange)) + 1) * 100));
        ofTranslate(0, (sin(ofDegToRad(ballrolling)) - 1) * 400);
        ofDrawRectangle(0, 10 + i, 575, 1 + i / 100);
        ofPopMatrix();
    }
}