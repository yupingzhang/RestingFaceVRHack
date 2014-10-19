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
    
    vector<string> shapeNames = faceShift.getBlendshapeNames();
    for(int i=0; i<shapeNames.size(); i++) {
        blendShapes[shapeNames[i]] = i;
    }
    ///// init pattern ////
    int patternNum = 4;
//    expressionPatterns.resize(patternNum);
//    patternNames.resize(patternNum);
//    patternScale.resize(patternNum);
    
    ///////////////////////////
    // create a new pattern  //
    /////  example   //////////
   
    //push to the list
    patternNames.push_back("digust");
    patternNames.push_back("sad");
    patternNames.push_back("happy");
    patternNames.push_back("bitch resting");
    
    for (int k=0; k<patternNum; k++) {
         patternScale.push_back(0.0);
    }
   
    //defalut pattern
    //digust
    vector<Shape> v;
    v.push_back(make_pair(string("MouthFrown_L"), 0.5));
    v.push_back(make_pair(string("MouthFrown_L"), 0.5));
    v.push_back(make_pair(string("Sneer_L"), 0.5));
    v.push_back(make_pair(string("Sneer_R"), 0.5));
    v.push_back(make_pair(string("CheekSquint_L"), 0.5));
    v.push_back(make_pair(string("CheekSquint_R"), 0.5));
    
    Expression digustPattern;
    digustPattern.init("digust", v);
    expressionPatterns.push_back(digustPattern);
    
    //sad
    v.clear();
    v.push_back(make_pair("EyeSquint_L", 0.4));
    v.push_back(make_pair("EyeSquint_R", 0.4));
    v.push_back(make_pair("BrowsU_C", 0.5));
    v.push_back(make_pair("BrowsU_L", 0.5));
    v.push_back(make_pair("BrowsU_R", 0.5));
    v.push_back(make_pair("MouthFrown_L", 0.4));
    v.push_back(make_pair("MouthFrown_R", 0.4));
    v.push_back(make_pair("ChinLowerRaise", 0.4));
    v.push_back(make_pair("ChinUpperRaise", 0.4));

    Expression sadPattern;
    sadPattern.init("sad", v);
    expressionPatterns.push_back(sadPattern);
    
    //happiness
    v.clear();
    v.push_back(make_pair("EyeSquint_L", 0.4));
    v.push_back(make_pair("EyeSquint_R", 0.4));
    v.push_back(make_pair("EyeUp_L", 0.2));
    v.push_back(make_pair("EyeUp_R", 0.2));
    v.push_back(make_pair("BrowsU_C", 0.5));
    v.push_back(make_pair("BrowsU_L", 0.5));
    v.push_back(make_pair("BrowsU_R", 0.5));
    v.push_back(make_pair("MouthSmile_L", 0.6));
    v.push_back(make_pair("MouthSmile_R", 0.6));
    v.push_back(make_pair("LipStretch_L", 0.3));
    v.push_back(make_pair("LipStretch_R", 0.3));
    v.push_back(make_pair("MouthLeft", 0.3));
    v.push_back(make_pair("MouthRight", 0.3));
    
    Expression happyPattern;
    happyPattern.init("happy", v);
    expressionPatterns.push_back(happyPattern);
    
    
    //bitch resting face
    v.clear();
    v.push_back(make_pair("EyeBlink_L", 0.2));
    v.push_back(make_pair("EyeBlink_R", 0.2));
    v.push_back(make_pair("EyeSquint_L", 0.45));
    v.push_back(make_pair("EyeSquint_R", 0.45));
    v.push_back(make_pair("BrowsD_L", 0.2));
    v.push_back(make_pair("BrowsD_R", 0.2));
    v.push_back(make_pair("MouthSmile_L", 0.2));
    v.push_back(make_pair("MouthSmile_R", 0.2));
    v.push_back(make_pair("LipStretch_L", 0.35));
    v.push_back(make_pair("LipStretch_R", 0.35));
    v.push_back(make_pair("ChinLowerRaise", 0.5));
    
    Expression bitchPattern;
    bitchPattern.init("bitch resting", v);
    expressionPatterns.push_back(bitchPattern);

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
    int mainPatternIndex = 0;
    float maxPattern = 0.0;
    for (int i=0; i<patternNames.size(); i++) {
        patternScale[i] = expressionPatterns[i].xpatternDetection(faceShift.getBlendshapeWeights(), blendShapes);
        
        if (patternScale[i] > maxPattern) {
            maxPattern = patternScale[i];
            mainPatternIndex = i;
        }
    }
    
    string str = "You have a " + patternNames[mainPatternIndex] + " face!!!";
    
    cout << str << endl;
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
