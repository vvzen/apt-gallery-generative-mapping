//
//  ofClock.hpp
//  Scene1
//
//  Created by Tommy GRAVEN on 28/12/2017.
//

#pragma once

#include <ofMain.h>

class ofClock{
public:
    void setup(int x, int y, int width, int height);
    void update();
    void draw(ofColor color);
    void drawClock(int x, int y, int width, int height);
    void reset();
    
    int posX, posY;
    int width, height;
    float angle = 0;
    float phase = 0;
    ofColor color;
    float speed = 1;
    //ofClock clock;
};
