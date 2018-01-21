#pragma once

#include "ofMain.h"
#include "FboSource.h"

class DorukSource : public ofx::piMapper::FboSource {
	public:
        void setup();
		void update();
		void draw();

        void setName(string);
        void reset();

        void wave(float speed);

		float shift = 10;
};
