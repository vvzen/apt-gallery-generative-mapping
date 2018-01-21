#include "Circles.h"

// I think this is the most interesting of the three parts
// I began with soem work i had made in programming for artists in
// term one, which had a grid of circles that changed in side and slid
// around. That version used an audio file to control the movement
// this version just updates itself instead.

//--------------------------------------------------------------
void Circles::setup(){
    name = "circles";
    allocate(768,768);
    
    cResolution = 39;
    dec = 245;
    decTwo = 245;
    br = 245;
    bg = 245;
    bb = 245;
    ofSetCircleResolution(cResolution);
    startTime = ofGetElapsedTimeMillis();
    circleCount = 256;
    circleSize = 10;
    focalPoint = ofRandom(circleCount);
    spacing = fbo->getWidth()/(circleSize*1.5);
    starting = spacing/2;
    inc = 0;
    incTwo = 0;
    // initiate the vectors with values
    // use sqrt to make a square grid, equal count
    // of items in each direction
    for(int x = 0; x < sqrt(circleCount)-1; x++){
        for(int y = 0; y < sqrt(circleCount)-1; y++){
            // initiate the grid
            int xPos = (x*spacing)+starting;
            int yPos = (y*spacing)+starting;
            if(y % 2 != 0){
                xPos += starting;
            }
            circlePositionsX.push_back(xPos);
            circlePositionsY.push_back(yPos);
            circleSizes.push_back(0);
        }
    }
}

void Circles::setName(string _name){
    name = _name;
}

void Circles::reset(){
    // if reset put everythign back to the beggining
    startTime = ofGetElapsedTimeMillis();
    inc = 0;
    incTwo = 0;
    dec = 245;
    decTwo = 245;
    br = 245;
    bg = 245;
    bb = 245;
    circleSize = 10;
    int resetCount = 0;
    // reset the grid
    for(int x = 0; x < sqrt(circleCount)-1; x++){
        for(int y = 0; y < sqrt(circleCount)-1; y++){
            int xPos = (x*spacing)+starting;
            int yPos = (y*spacing)+starting;
            if(y % 2 != 0){
                xPos += starting;
            }
            circlePositionsX[resetCount] = xPos;
            circlePositionsY[resetCount] = yPos;
            circleSizes[resetCount] = circleSize;
            resetCount++;
        }
    }
}

//--------------------------------------------------------------
void Circles::update(){
    // for the first 30 seconds do this
    if(ofGetElapsedTimeMillis() - startTime < 30000){
        for(int i = 0; i < circlePositionsX.size(); i++){
            // for all of the items move rigidly every 1.5 seconds go left or right
            if(ofGetElapsedTimeMillis() % 1500 <= 1000 && ofGetElapsedTimeMillis() % 3500 >= 1000 ){
                // depending on if the item is in an odd or even row
                if(i % 2 == 0){
                    circlePositionsX[i] -= 0.5;
                }else{
                    circlePositionsX[i] += 0.5;
                }
            }
            // then go up or down with the same rule on the off beat.
            if(ofGetElapsedTimeMillis() % 3500 <= 1000){
                if(i % 2 == 0){
                    circlePositionsY[i] -= 0.5;
                }else{
                    circlePositionsY[i] += 0.5;
                }
            }
            // wrap the circles around the edges of the screen/surface
            // top to bottom, left to right.
            if(circlePositionsX[i] < 0+circleSizes[i]/2){
                circlePositionsX[i] = fbo->getWidth()-circleSizes[i];
            }else if(circlePositionsX[i] > fbo->getWidth()-circleSizes[i]/2){
                circlePositionsX[i] = 0+circleSizes[i];
            }
            if(circlePositionsY[i] < 0+circleSizes[i]/2){
                circlePositionsY[i] = fbo->getHeight()-circleSizes[i];
            }else if(circlePositionsY[i] > fbo->getHeight()-circleSizes[i]/2){
                circlePositionsY[i] = 0+circleSizes[i];
            }
            // if this circles size is less than it should be then grow
            // until correct
            if(circleSizes[i] < circleSize){
                circleSizes[i] += ofRandom(0.1);
            }
        }
        
    }
    
    // after 30 fade the background to this dark color
    if(ofGetElapsedTimeMillis() - startTime > 25000){
        //0,1,25
        // i liked this color, it was used a black by nintendo instead of
        // 0,0,0 as older screens couldnt display 0,0,0. it has a blue
        // tinge to it that gives it depth.
        if(br > 0){
            br-=1;
        }
        if(bg > 1){
            bg-=1;
        }
        if(bb > 35){
            bb-=1;
        }
    }
    
    // then start getting a bit noisy in the movement
    if(ofGetElapsedTimeMillis() - startTime > 28000){
        // this is similar to before but now we are using a noise based
        // increment instead of a fixed value, so it goes a bit wobbly
        for(int i = 0; i < circlePositionsX.size(); i++){
            if(i % 2 == 0){
                circlePositionsX[i] -= ofNoise(i+inc);
            }else{
                circlePositionsX[i] += ofNoise(i+inc);
            }
            if(ofGetElapsedTimeMillis() - startTime > 40000){
                circleSizes[i] -= ofMap(ofNoise(i+0.05),0,1,0,0.1);
            }
            if(i % 2 == 0){
                circlePositionsY[i] -= ofNoise(i+inc);
            }else{
                circlePositionsY[i] += ofNoise(i+inc);
            }
            if(ofGetElapsedTimeMillis() - startTime > 50000){
                circleSizes[i] += ofMap(ofNoise(i+0.05),0,1,0,0.1);
            }
            
            if(circlePositionsX[i] < 0+circleSizes[i]/2){
                circlePositionsX[i] = fbo->getWidth()-circleSizes[i];
            }else if(circlePositionsX[i] > fbo->getWidth()-circleSizes[i]/2){
                circlePositionsX[i] = 0+circleSizes[i];
            }
            if(circlePositionsY[i] < 0+circleSizes[i]/2){
                circlePositionsY[i] = fbo->getHeight()-circleSizes[i];
            }else if(circlePositionsY[i] > fbo->getHeight()-circleSizes[i]/2){
                circlePositionsY[i] = 0+circleSizes[i];
            }
            // update the decrementing counter which is used in the color below.
            if(dec > 0){
                dec -=0.5;
            }
        }
        // if the time is within 500ms of a 4 second period the increment this counter
        if(ofGetElapsedTimeMillis() % 4000 <= 500){
            inc +=0.05;
        }
    }
    //update the decrementing counter which is used in the color below.
    if(ofGetElapsedTimeMillis() - startTime > 50000){
        if(decTwo > 0){
            decTwo -=0.5;
        }
    }
    
}

//--------------------------------------------------------------
void Circles::draw(){
    // set the background with variables as it will change over time.
    ofBackground(br,bg,bb);
    // for each item in the vector
    for(int i = 0; i < circlePositionsX.size(); i++){
        //go to the stored location
        ofPushMatrix();
        ofTranslate(circlePositionsX[i],circlePositionsY[i]);
        // if in first half of scene then use this color
        if(ofGetElapsedTimeMillis() - startTime < 26000){
            ofSetColor(0,1,35);
            ofNoFill();
            ofSetLineWidth(3);
            ofDrawCircle(0,0,circleSizes[i]);
        }else{
        // else use the other color
            // not the dist color has lots of variables, these begin to change
            // at different times to fade the items out at the end of the scene
            int dist = ofClamp(ofMap(i, 0, circleCount, dec, decTwo),0,255);
            ofSetColor(dist);
            ofNoFill();
            ofSetLineWidth(3);
            ofDrawCircle(0,0,circleSizes[i]);
        }
        ofPopMatrix();
    }
    
}

