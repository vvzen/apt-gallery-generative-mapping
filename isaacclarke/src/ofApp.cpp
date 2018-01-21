#include "ofApp.h"

void ofApp::setup(){
	ofBackground(0);
	// Enable or disable audio for video sources globally
	// Set this to false to save resources on the Raspberry Pi
	ofx::piMapper::VideoSource::enableAudio = true;
	ofx::piMapper::VideoSource::useHDMIForAudio = false;
    
    wobblyCrossSquares = new WobblyCrossSquares();
    wobblyCrossSquares->setup();
    piMapper.registerFboSource(wobblyCrossSquares);
    wobblyCrossSquares->setName("wcs");
    wobblyCrossSquaresTwo = new WobblyCrossSquares();
    wobblyCrossSquaresTwo->setup();
    piMapper.registerFboSource(wobblyCrossSquaresTwo);
    wobblyCrossSquares->setName("wcs2");
    ofColor c = ofColor::white;
    ofColor c2 = ofColor:: gold;
    wobblyCrossSquaresTwo->setColor(c, c2);
    circlesOne = new Circles();
    circlesOne->setup();
    piMapper.registerFboSource(circlesOne);
    circlesOne->setName("c1");
    circlesTwo = new Circles();
    circlesTwo->setup();
    piMapper.registerFboSource(circlesTwo);
    circlesOne->setName("c2");
    
    swirlRectsOne = new SwirlRects();
    swirlRectsOne->setup();
    piMapper.registerFboSource(swirlRectsOne);
    swirlRectsOne->setName("sw1");
    piMapper.setup();
    
	// The info layer is hidden by default, press <i> to toggle
	// piMapper.showInfo();
	
	ofSetFullscreen(Settings::instance()->getFullscreen());
	ofSetEscapeQuitsApp(false);

    dummyObjects.load("accordion_reference.png");

    //setup sceneManager to handle scene/present changes automatically
    sceneManager.setup("scenes.json", &piMapper);
}

void ofApp::update(){
	piMapper.update();
    sceneManager.update();
    
    int numberOfSeconds = 2*60;
    if (ofGetElapsedTimeMillis()>numberOfSeconds*1000) ofExit(0);
}

void ofApp::draw(){
    // dummyObjects.draw(50,50);
    piMapper.draw();
}

void ofApp::keyPressed(int key){
    //press 5 to go to previous preset (scene)
    if (key=='5') {
        if (piMapper.getNumPresets()>1){
            int targetScene = piMapper.getActivePresetIndex() - 1;
            if (targetScene<0) targetScene = piMapper.getNumPresets()-1;
            piMapper.setPreset(targetScene);
            cout << "Switched to preset: " << piMapper.getActivePresetIndex() << endl;
        } else cout << "only one preset available" << endl;
    }
    //press 6 to go to next preset (scene)
    else if (key=='6') {
        if (piMapper.getNumPresets()>1){
            piMapper.setNextPreset();
            cout << "Switched to preset: " << piMapper.getActivePresetIndex() << endl;
        } else cout << "only one preset available" << endl;
    }
    else if (key == '7'){
        piMapper.cloneActivePreset();
        piMapper.setPreset(piMapper.getNumPresets()-1);
        cout << "Cloned and switched to preset: " << piMapper.getActivePresetIndex() << endl;
    }

	piMapper.keyPressed(key);
}

void ofApp::keyReleased(int key){
	piMapper.keyReleased(key);
}

void ofApp::mousePressed(int x, int y, int button){
	piMapper.mousePressed(x, y, button);
}

void ofApp::mouseReleased(int x, int y, int button){
	piMapper.mouseReleased(x, y, button);
}

void ofApp::mouseDragged(int x, int y, int button){
	piMapper.mouseDragged(x, y, button);
}
