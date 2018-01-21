#pragma once

#include "ofMain.h"
#include "FboSource.h"

class SolarSystemSource : public ofx::piMapper::FboSource{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		void drawPlanet(int x, int y, int radius, ofColor color, bool isShining);
        void starsSetup();
        void starsDraw();
        void reset();
    
        float x1 = 150, x2 = 225, x3 = 300, x4 = 375, x5 = 450, x6 = 525, x7 = 600;
  
        float angle;
        float phase;
        float speed = 1;
        float sunScale = 1;
    
        float spacingX, spacingY;
        float startingX, startingY;
        float stepSize;
        static const int numX = 25;
        static const int numY = 25;
        float noiseSeeds[numX][numY];
};
