#pragma once

#include "ofMain.h"
#include "FboSource.h"

class EceSource : public ofx::piMapper::FboSource {
	public:
        void setup();
		void update();
		void draw();

        void setName(string);
        void reset();

        int spacing;
	
        float sinValue = 100;
        float colorChange = 0;
        float redcolorchange = 200;
        float ballrolling = 0;
        float lineslim = 0;
        float colorChangeBigCircle = 0;
};
