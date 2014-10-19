#pragma once

#include "ofMain.h"
#include "ofxFaceShift.h"
#include "expression.h"

using namespace std;


class smoothfloat{
public:
    smoothfloat();
    float get();
    void set(float toSmooth);
    
private:
    vector<float> ringbuffer;
};

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
    float pointone;
    smoothfloat cheek;
    smoothfloat cheekb;
    float horizontalMovement;
    float depthMovement;
    float heightMovement;
    smoothfloat height;
    int lastBlinkTrigger;

};

