#pragma once

#include "ofMain.h"
#include "FboSource.h"

class DoorLightsSource : public ofx::piMapper::FboSource {

public:
    void setup();
    void update();
    void draw();
    void atom(float posX, float posY, float radius, float p, ofColor r1, ofColor r2);
    void setName(string _name);

    float screenWidth, screenHeight;
    float savedTime, intervalTime;

    bool isFinished;

    float atomRadius, atomSpacing, atomScale;
    float phase;

    ofColor innerRingC, outerRingC ;
    float life;
};
