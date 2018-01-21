#include "ClockGridSource.h"


//--------------------------------------------------------------
void ClockGridSource::setup(){
    // Give our source a decent name
    name = "Clock Grid FBO Source";
    // Allocate our FBO source, decide how big it should be
    allocate(800, 800);

    ofSetBackgroundAuto(true);
    ofBackground(0, 0, 0);
    
    //clocks.resize(50);
    
    
    float clockWidth = 35;
    float height = -1;
    numOfXTiles = 10;
    numOfYTiles = 10;
    spacingX = fbo->getWidth() / numOfXTiles;
    spacingY = fbo->getHeight() / numOfYTiles;
    startingX = spacingX / 2;
    startingY = spacingY / 2;
    
    
    
    for (int i = 0; i < numOfXTiles; i++)
    {
        for (int j = 0; j < numOfYTiles; j++)
        {
            ofClock clock;
            clocks.push_back(clock);
            locX = startingX + i * spacingX;
            locY = startingY + j * spacingY;
            clocks[amountOfClocks].setup(locX, locY, clockWidth, height);
            amountOfClocks++;
        }
        
    }
    
   
}

//--------------------------------------------------------------
void ClockGridSource::update(){
    //clock.update();
    for (int i=0; i<amountOfClocks; i++)
    {
        clocks[i].update();
    }
}

//--------------------------------------------------------------
void ClockGridSource::draw(){
    ofPushMatrix();
        ofSetColor(0, 0, 0);
        ofDrawRectangle(0, 0, 0, fbo->getWidth(), fbo->getHeight());
    ofPopMatrix();

    //clock.draw();
    for (int i=0; i<amountOfClocks; i++)
    {
        ofPushMatrix();
            float dist = ofDist(clocks[i].posX, clocks[i].posY, fbo->getWidth()/2, fbo->getHeight()/2);
            ofColor color;
            color.r = ofMap(dist, 0, 600, 255, 0);
            color.g = ofMap(dist, 0, 600, 0, 255);
            color.b = ofMap(dist, 0, 600, 0, 255);
            clocks[i].draw(color);
        ofPopMatrix();
    }
}

//--------------------------------------------------------------
void ClockGridSource::reset(){
    for (int i = 0; i < amountOfClocks; i++)
    {
        clocks[i].reset();
    }
}


//--------------------------------------------------------------
void ClockGridSource::keyPressed(int key){

}

//--------------------------------------------------------------
void ClockGridSource::keyReleased(int key){

}

//--------------------------------------------------------------
void ClockGridSource::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ClockGridSource::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ClockGridSource::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ClockGridSource::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ClockGridSource::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ClockGridSource::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ClockGridSource::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ClockGridSource::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ClockGridSource::dragEvent(ofDragInfo dragInfo){

}
