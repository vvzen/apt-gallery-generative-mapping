#pragma once

#include "ofMain.h"
#include "FboSource.h"

class WobblyCrossSquares : public ofx::piMapper::FboSource {
	public:
        void setup();
		void update();
        void draw();
        void drawXSquare(float x, float y, float offset, float offsetTwo);
    
        void setName(string _name);
        void setColor(ofColor c, ofColor c2);
        ofColor r, b;
        bool flip;
        float count, counttwo, size, spacing, starting, rectCount;
    
};
