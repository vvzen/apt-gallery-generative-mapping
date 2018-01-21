#include "dorukSource.h"

//--------------------------------------------------------------
void DorukSource::wave(float speed) {

	shift = shift * speed;
	int spacing = 50;
	int totalRects = 2 * ofGetWidth() / spacing;
	for (int i = 0; i < totalRects; i++)
	{
		for (int ii = 0; ii < totalRects; ii++)
		{
			if (shift >= 1080) //shift reset is needed or program runs out of memory - crashes after a point.
			{
				shift = 0;
			}
			ofPushMatrix();
			ofSetColor(255);
			shift = shift + 0.0001; //the speed of changes.
			ofTranslate(-spacing + i * spacing, -spacing + ii * spacing);
			ofRotate(sin(ofDegToRad(shift + i + ii)) * 120);
			ofScale(sin(ofDegToRad(shift + i)), sin(ofDegToRad(shift + ii)) * 20);
			ofTranslate(sin(ofDegToRad(shift + i))*i, sin(ofDegToRad(shift + ii))*ii);
			ofSetColor(i * 20, ii + i, ii * 20);
			ofDrawRectangle(0, 0, 15, 15);
			ofPopMatrix();
		}

	}

}

//--------------------------------------------------------------
void DorukSource::reset(){
	ofClear(0);
}

//--------------------------------------------------------------
void DorukSource::setup(){
    ofBackground(0);

	// Give our source a decent name
    name = "Doruk Source";

	// Allocate our FBO source
    allocate(1024, 768);

	// clear fbo
    this->beginFbo();
        ofClear(255,0,0);
    this->endFbo();
}

//--------------------------------------------------------------
void DorukSource::setName(string _name){
    name = _name;
}

//--------------------------------------------------------------
// Don't do any drawing here
void DorukSource::update(){
    
}

//--------------------------------------------------------------
void DorukSource::draw(){
	ofBackground(0);
    wave(1.0f);
}