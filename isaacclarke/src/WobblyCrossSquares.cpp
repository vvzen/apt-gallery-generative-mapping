#include "WobblyCrossSquares.h"

void WobblyCrossSquares::setup(){
	// Give our source a decent name
    name = "Wobbly Cross Squares Source";
	// Allocate our FBO source, decide how big it should be
    allocate(768, 768);
    // Sticking to blue colors as i like the depth
    r = ofColor::blueSteel;
    b = ofColor::cornflowerBlue;
    counttwo = 0.0;
    count = 0.0;
    flip = true;
    size = 30;
    rectCount = 5;
    spacing = fbo->getWidth()/rectCount;
    starting = 50;
}

void WobblyCrossSquares::setName(string _name){
    name = _name;
}

// this allows the colors to be reset, useful when there are a few versions
// of this being used so they can alternate
void WobblyCrossSquares::setColor(ofColor c, ofColor c2){
    r = c;
    b = c2;
}


void WobblyCrossSquares::update(){
    // keep track of the counters
    // the counter update the positions of the
    // vertices of the shape allowing it to
    // change over time
    counttwo+=0.02;
    if(flip){
        count += 0.05;
        if(count > size){
            flip = false;
        }
    }else{
        count -= 0.1;
        if(count < 0){
            flip = true;
        }
    }
}

// No need to take care of fbo.begin() and fbo.end() here.
// All within draw() is being rendered into fbo;
void WobblyCrossSquares::draw(){
    ofClear(0); //clear the buffer
    ofBackground(0, 1, 35);
    ofPushMatrix();
    ofTranslate(fbo->getWidth()/2, fbo->getHeight()/2);
    // start out drawing in a grid
    for(int x = -2; x < rectCount+2; x++){
        for(int y = -2; y < (rectCount+2)*2; y++){
            // call the custom shape function here
            drawXSquare((x*spacing)-fbo->getWidth()/2, (y*(spacing/2))-fbo->getHeight()/2, x, y);
        }
    }
    ofPopMatrix();
    
}

void WobblyCrossSquares::drawXSquare(float x, float y, float offset, float offsetTwo){
    // lerp the colors
    float lerpAmount = ofMap(offset, -2, rectCount+2, 0, 1);
    b.lerp(r, lerpAmount);
    b.a=ofMap(ofNoise(counttwo+offsetTwo),0,1,20,255);
    ofSetColor(b);
    ofFill();
    // purposefully rotating before the individuall translations
    // using the 0.009 multiplier to make this a very gradual
    // smooth drift across the surface
    ofRotate(counttwo*0.009);
    ofPushMatrix();
    ofTranslate(x - size/2, y - size/2);
    
    float noisy = ofMap(sin(counttwo+offset+offsetTwo),-1,1,0,30);
    float countNoise = ofMap(ofNoise(counttwo+(x * fbo->getWidth() + y)),0,1,0,-size+1);
    float counta = count + countNoise;
    
    // draw our shape that can move between being a square and a cross
    // like this: [] X [] + [] X
    ofRotate(ofMap(sin((count+noisy)*0.01),-1,1,-180,360));
    ofBeginShape();
    ofVertex(-size-counta,-size-counta);
    ofVertex(-size-counta,-(size*2));
    ofVertex(size+counta,-(size*2));
    ofVertex(size+counta,-size-counta);
    ofVertex((size*2),-size-counta);
    ofVertex((size*2),size+counta);
    ofVertex(size+counta,size+counta);
    ofVertex(size+counta,(size*2));
    ofVertex(-size-counta,(size*2));
    ofVertex(-size-counta,size+counta);
    ofVertex(-(size*2),size+counta);
    ofVertex(-(size*2),-size-counta);
    ofVertex(-size-counta,-size-counta);
    ofEndShape();
    ofPopMatrix();
}

