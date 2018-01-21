#pragma once

#include "ofMain.h"
#include "FboSource.h"

class HypnotizeSource : public ofx::piMapper::FboSource{

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
        void switchColors(ofColor color1, ofColor color2);
        void drawRing(int p, float size, float _offset);
        void colorTransition();
        void drawYoyo();
        void reset();
        
        float angle;
        float phase;
        ofColor color1;
        ofColor color2;
        int timer;
        float modulatingSpeed = 1;
		
};
