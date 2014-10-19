#include "ofApp.h"

#include <iostream>

void ofApp::setup() {
	ofSetVerticalSync(true);
	faceShift.setup();
	faceShift.import("export");
	
	light.enable();
	light.setPosition(+500, +500, +500);
    
    /////////
//    cout << faceShift.getBlendshapeNames().size();
//    for(int j=0; j<faceShift.getBlendshapeNames().size(); j++) {
//        std::cout << faceShift.getBlendshapeName(j) << "\n";
//    }
    
    ///// init pattern ////
    int patternNum = 1;
    expressionPatterns.resize(patternNum);
    patternNames.resize(patternNum);
    patternScale.resize(patternNum);
    
    ///////////////////////////
    // create a new pattern  //
    /////  example   //////////
    Expression examplePattern;
    string patternName = "digust";
    examplePattern.init(patternName, faceShift.getBlendshapeNames());
    
    float digust_scale = 0.0;
    //push to the list
    patternNames.push_back(patternName);
    patternScale.push_back(digust_scale);
    expressionPatterns.push_back(examplePattern);
    

}

void ofApp::update() {
	faceShift.update();
}

void ofApp::draw(){
	ofBackground(128);
	
	cam.begin();
	glEnable(GL_DEPTH_TEST);
	ofRotateX(180);

    ///////////////////////
    patternScale[0] = expressionPatterns[0].xpatternDetection(faceShift.getBlendshapeWeights());
    
    
    /////////////////////////////////////////
    //    add code to render the measurement
    
    /////////////////////////////////////////
    
	ofTranslate(faceShift.getPosition());
	ofScale(-1, 1, 1); // for some reason the rotation matrix x is flipped
	glMultMatrixf((GLfloat*) faceShift.getRotationMatrix().getPtr());
	ofScale(-1, 1, 1); // then we flip it back
	
	ofEnableLighting();
	ofSetColor(255);
	faceShift.getBlendMesh().draw();
	
	ofDisableLighting();
	ofSetColor(0);
	faceShift.getBlendMesh().drawWireframe();
	
	cam.end();
    
}
