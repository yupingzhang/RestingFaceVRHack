#pragma once

#include "ofMain.h"
#include "ofxFaceShift.h"
#include "expression.h"

using namespace std;

class ofApp : public ofBaseApp{
public:
    vector<Expression> expressionPatterns;
     
    vector<string> patternNames;
    vector<float>  patternScale;
    
    map<string, int> blendShapes;
    
public:
	void setup();
	void update();
	void draw();
	
	ofxFaceShift faceShift;
	
	ofEasyCam cam;
	ofLight light;
};

