#include "SolarSystemSource.h"

//--------------------------------------------------------------
void SolarSystemSource::setup(){
    // Give our source a decent name
    name = "Solar System FBO Source";
    // Allocate our FBO source, decide how big it should be
    allocate(800, 800);

    ofBackground(0, 0, 0);
    ofSetBackgroundAuto(false);
    starsSetup();
}

//--------------------------------------------------------------
void SolarSystemSource::update(){

    angle += 0.2 * speed;
    phase += 1.5 * speed;
    
    if (ofGetFrameNum() % (10 * 60) == 0)
        speed+= 0.2;
        
}

//--------------------------------------------------------------
void SolarSystemSource::draw(){
    starsDraw();


    ofPushMatrix();
        ofSetColor(0, 0, 0, 20);
        ofDrawRectangle(0, 0, 0, fbo->getWidth(), fbo->getHeight());
    ofPopMatrix();
    
    ofPushMatrix();
        int startPosX = fbo->getWidth()/2;
        int startPosY = fbo->getHeight()/2;
        ofTranslate(startPosX, startPosY);
    
        ofRotate(5*angle);
        // Earth
        float gravity = 0.2;
    
        ofPushMatrix();
            ofColor colorEarth;
            //float dist1 = ofDist(x1, 0, startPosX, startPosY);
            //float value = ofMap(dist1, 0, 999, 255, 0);
            colorEarth.r = 150;
            colorEarth.g = 150;
            colorEarth.b = 255;
            x1 -= gravity * speed;
            x1 = ofClamp(x1, 0, 9999);
            drawPlanet(x1, 0, 20, colorEarth, false);
        ofPopMatrix();
    
        // Earth 2
        ofPushMatrix();
            ofColor colorEarth2;
            colorEarth2.r = 255;
            colorEarth2.g = 175;
            colorEarth2.b = 50;
            x2 -= gravity * speed;
            x2 = ofClamp(x2, 0, 9999);
            drawPlanet(x2, 0, 30, colorEarth2, false);
    
        ofPopMatrix();
    
        // Earth 3
        ofPushMatrix();
            ofColor colorEarth3;
            colorEarth3.r = 180;
            colorEarth3.g = 180;
            colorEarth3.b = 255;
            x3 -= gravity * speed;
            x3 = ofClamp(x3, 0, 9999);
            drawPlanet(x3, 0, 20, colorEarth3, false);
    
            ofRotate(30*angle);
            ofColor colorMoon(220,220,60);
            drawPlanet(30, 0, 10, colorMoon, false);
        ofPopMatrix();
    
        // Earth 4
        ofPushMatrix();
            ofColor colorEarth4;
            colorEarth4.r = 255;
            colorEarth4.g = 150;
            colorEarth4.b = 100;
            x4 -= gravity * speed;
            x4 = ofClamp(x4, 0, 9999);
            drawPlanet(x4, 0, 20, colorEarth4, false);
    
        ofPopMatrix();
    
        // Earth 5
        ofPushMatrix();
            ofColor colorEarth5;
            colorEarth5.r = 255;
            colorEarth5.g = 255;
            colorEarth5.b = 180;
            x5 -= gravity * speed;
            x5 = ofClamp(x5, 0, 9999);
            drawPlanet(x5, 0, 50, ofColor(255, 255, 0), false);
    
             ofSetColor(0);
            ofDrawCircle(0, 0, 40);
    
            ofSetColor(colorEarth5);
            ofDrawCircle(0, 0, 30);
        ofPopMatrix();
    
        // Earth 6
        ofPushMatrix();
            ofColor colorEarth6;
            colorEarth6.r = 255;
            colorEarth6.g = 255;
            colorEarth6.b = 130;
            x6 -= gravity * speed;
            x6 = ofClamp(x6, 0, 9999);
            drawPlanet(x6, 0, 20, colorEarth6, false);
        ofPopMatrix();
    
         // Earth 7
        ofPushMatrix();
            ofColor colorEarth7;
            colorEarth7.r = 150;
            colorEarth7.g = 255;
            colorEarth7.b = 70;
            x7 -= gravity * speed;
            x7 = ofClamp(x7, 0, 9999);
            drawPlanet(x7, 0, 20, colorEarth7, true);
        ofPopMatrix();
    
    
    
         // Sun
        ofRotate(-4* angle);
        ofPushMatrix();
            if (x7 <= 10){
            sunScale = 1.5;
            ofScale(sunScale, sunScale);
            }
            ofColor colorSun;
            colorSun.r = 255;
            colorSun.g = 255;
            colorSun.b = 0;
            drawPlanet(0, 0, 70, colorSun, true);
        ofPopMatrix();
    
    ofPopMatrix();
}

//--------------------------------------------------------------
void SolarSystemSource::reset(){
    x1 = 150, x2 = 225, x3 = 300, x4 = 375, x5 = 450, x6 = 525, x7 = 600;
    angle = 0.2 * speed;
    phase = 1.5 * speed;
    speed = 1;
}

//--------------------------------------------------------------
void SolarSystemSource::drawPlanet(int x, int y, int radius, ofColor color, bool isShining){
    float modulatingSize = (sin(ofDegToRad(phase))+1)/2;

   //ofPushMatrix();
        ofTranslate(x, y);
        ofRotate(angle);
        ofScale(1 - modulatingSize/3, 1 - modulatingSize/3);
        ofSetCircleResolution(100);
    
        if (isShining)
            ofSetColor(255, 200, 0);
        else ofSetColor(150, 0, 255);
        ofDrawCircle(0, 0, radius);
        ofSetColor(color);
        ofDrawCircle(0, 0, radius * 7/8);
    
    
    
    
        if (isShining)
        {
            int rot = 30;
            ofSetLineWidth(8);
            float lineWidthMultiplier;
            for (int i = 0; i < 360 / rot; i++)
            {
                if (i % 2 == 0){
                    lineWidthMultiplier = 1.7 -  modulatingSize;
                }
                else {
                    lineWidthMultiplier = 2 -  modulatingSize;
                }
                ofDrawLine(radius + 20, 0, lineWidthMultiplier * radius, 0);
                ofRotate(rot);
            }
        }
    
     //ofPopMatrix();
}



//--------------------------------------------------------------
void SolarSystemSource::starsSetup(){
    spacingX = fbo->getWidth() / numX;
    spacingY = fbo->getHeight() / numY;
    startingX = spacingX / 2;
    startingY = spacingY / 2;
    stepSize = 20;
    
    for (int i = 0; i < numX; i++)
    {
        for (int j = 0; j < numY; j++)
        {
            noiseSeeds[i][j] = ofRandom(1000);
        }
    }
}

//--------------------------------------------------------------
void SolarSystemSource::starsDraw(){
    ofPushMatrix();
    ofSetColor(0, 0, 0, 5);
    ofDrawRectangle(0, 0, fbo->getWidth(), fbo->getHeight());
    
    for (int i = 0; i < numX; i++)
    {
        for (int j = 0; j < numY; j++)
        {
            
                int locX = startingX + i * spacingX;
                int locY = startingY + j * spacingY;
                float coordX = noiseSeeds[i][j];
                float coordY = noiseSeeds[i][j] + 500;
            
            
                locX += stepSize * ofSignedNoise(coordX, ofGetFrameNum() / 100.);
                locY += stepSize * ofSignedNoise(coordY, ofGetFrameNum() / 100.);
            
                if (i % 2 == 0){
                    ofSetColor(100, 100, 100);
                    }
            
                    else {
                    ofSetColor(200, 200, 200);
                    }
            
                ofDrawEllipse(locX + 0.02, locY + 0.02, 5, 3);
            
        }
    }
    ofPopMatrix();
}

//--------------------------------------------------------------
void SolarSystemSource::keyPressed(int key){

}

//--------------------------------------------------------------
void SolarSystemSource::keyReleased(int key){

}

//--------------------------------------------------------------
void SolarSystemSource::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void SolarSystemSource::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void SolarSystemSource::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void SolarSystemSource::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void SolarSystemSource::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void SolarSystemSource::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void SolarSystemSource::windowResized(int w, int h){

}

//--------------------------------------------------------------
void SolarSystemSource::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void SolarSystemSource::dragEvent(ofDragInfo dragInfo){ 

}
