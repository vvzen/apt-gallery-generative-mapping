#pragma once

#include "ofMain.h"
#include "ofClock.h"
#include "FboSource.h"

class ClockGridSource : public ofx::piMapper::FboSource{

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
        void reset();
    
        vector <ofClock> clocks;
        int amountOfClocks;
        int numOfXTiles, numOfYTiles;
        int locX, locY;
        int startingX, startingY;
        int spacingX, spacingY;
};
