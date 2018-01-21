#pragma once
#include "ofMain.h"
#include "FboSource.h"

class Circles : public ofx::piMapper::FboSource {
    
public:
    void setup();
    void update();
    void draw();
    void setName(string _name);
    void reset();
    float circleSize, spacing, starting, startTime, inc, incTwo, dec, decTwo;
    int circleCount, cResolution, focalPoint, br, bg, bb;
    vector<float> circlePositionsX;
    vector<float> circlePositionsY;
    vector<float> circleSizes;
};

