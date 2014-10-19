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
    patternNames.push_back("unamused");
    
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
    
    horizontalMovement = 0;
    depthMovement = 0;
    lastBlinkTrigger =0;

}

void ofApp::update() {
	faceShift.update();
}

void ofApp::draw(){
	ofBackground(0);
	
	//cam.begin();
	glEnable(GL_DEPTH_TEST);
	//ofRotateX(180);

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
    
    
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2.+horizontalMovement,ofGetHeight()/2. + height.get(), depthMovement);
    ofEnableLighting();
	ofSetColor(255);
    ofRotateZ(180);
	faceShift.getBlendMesh().draw();
	
	ofDisableLighting();
	ofSetColor(120);
    
	faceShift.getBlendMesh().drawWireframe();
    glDisable(GL_DEPTH_TEST);
    ofNoFill();
    //ofCircle(faceShift.getBlendMesh().getVertices()[(int)pointone], 5);
    ofSetColor(30);
    ofLine(faceShift.getBlendMesh().getVertices()[5431], faceShift.getNeutralMesh().getVertices()[5431]);
    ofLine(faceShift.getBlendMesh().getVertices()[1810], faceShift.getNeutralMesh().getVertices()[1810]);
    ofDisableLighting();
    
    
    float cheek1 = ofDist(faceShift.getBlendMesh().getVertices()[5431].x,faceShift.getBlendMesh().getVertices()[5431].y,
                          faceShift.getNeutralMesh().getVertices()[5431].x,faceShift.getNeutralMesh().getVertices()[5431].y);
    ofPopMatrix();
    float cheek2 = ofDist(faceShift.getBlendMesh().getVertices()[1810].x,faceShift.getBlendMesh().getVertices()[1810].y,
                          faceShift.getNeutralMesh().getVertices()[1810].x,faceShift.getNeutralMesh().getVertices()[1810].y);
    ofPopMatrix();
	//cam.end();
    cheek.set(cheek1);
    cheekb.set(cheek2);
    if (cheek1>2.5){
        //cout<<cheek.get() <<endl;
        horizontalMovement += (cheek.get()-1.5);
    }
    if (cheek2>2.5){
        //cout<<cheekb.get() <<endl;
        horizontalMovement -= (cheekb.get()-1.5);
    }
    
    if ((faceShift.getBlendshapeWeights()[0] >= 0.9) && (faceShift.getBlendshapeWeights()[1] >= 0.9)){
        if (ofGetFrameNum()-20 > lastBlinkTrigger) {
            lastBlinkTrigger = ofGetFrameNum();
            cout << "blink" << endl;
        }
    }
    float xcenter = ofGetWidth()/2;
    
    //jaw-movement for forward/back
    if (faceShift.getBlendshapeWeights()[23] < 0.5) depthMovement -= (0.1 - faceShift.getBlendshapeWeights()[23]) *5;
    if (faceShift.getBlendshapeWeights()[23] > 0.5) depthMovement += (faceShift.getBlendshapeWeights()[23] * .3);
    //upper lip compression for up down.
    if (faceShift.getBlendshapeWeights()[28] < 0.15) heightMovement -= (0.1 - faceShift.getBlendshapeWeights()[23]) *5;
    if (faceShift.getBlendshapeWeights()[28] > 0.15) heightMovement += faceShift.getBlendshapeWeights()[23] * .5;
    height.set(heightMovement);
    
    if (faceShift.getBlendshapeWeights().size()!=0){
        for (int i = 0; i<faceShift.getBlendshapeNames().size(); i++) {
            ofSetColor(0);
            ofRect(10, 20*i, faceShift.getBlendshapeWeights()[i]*300, 10);
            ofSetColor(255);
            ofDrawBitmapString(faceShift.getBlendshapeNames()[i], ofPoint(10,10+ (20*i)));
        }
    }

    
}

smoothfloat::smoothfloat(){
    for(int i=0; i<20;i++){
        ringbuffer.push_back(0);
    }
}
void smoothfloat::set(float tosmooth){
    ringbuffer.erase(ringbuffer.begin());
    ringbuffer.push_back(tosmooth);
}
float smoothfloat::get(){
    float accum=0;
    for (int i=0; i<ringbuffer.size(); i++){
        accum+=ringbuffer[i];
    }
    return (accum/ringbuffer.size());
}
