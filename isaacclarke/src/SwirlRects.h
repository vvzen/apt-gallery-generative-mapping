#pragma once
#include "ofMain.h"
#include "FboSource.h"

class SwirlRects: public ofx::piMapper::FboSource {
    
public:
    void setup();
    void update();
    void draw();
    void setName(string _name);
    void drawSquare(int x, int y, int w, int h, int inc);
    int shapeCount, inc, shapeSize, startTime, cTime;
    vector<ofPoint> pointsOne;
    vector<ofPoint> pointsTwo;
    vector<ofPoint> pointsThree;
    vector<ofPoint> pointsFour;
    ofColor movingColor;
};


