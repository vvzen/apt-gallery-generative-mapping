#pragma once

#include "ofMain.h"
#include "FboSource.h"

class DoorSeqSource : public ofx::piMapper::FboSource {

public:
    void setup();
    void update();
    void draw();
// custom shape function
    void strobeDoor(float x, float y, float w, float h, float roundness, float rotY, ofColor c);
    void setName(string _name);
    // screen size variables
    float screenWidth, screenHeight;
// timers and bool variables to trigger events over time
    vector<float> savedTime, intervalTime;
    bool isFinished, reverseDoors;
// stobeDoor variables
    float doorWidth, doorHeight, doorSpacing, doorRoundness;
// colours + alpha linked to life(3min sequence) variables
    ofColor c1, c2, panelC;
    float alpha,life;
// movement variables
    float phase, pSpeed;
};
