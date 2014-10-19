#pragma once

#include "ofMain.h"
#include "ofxFaceShift.h"

#include "expression.h"
#include "CatchCandy.h"
#include "vec3.h" 

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
    
    float time;
    
    bool mouthopen;
    bool dropCandy;
    int candyMax;
    ofImage img;
    vector<CatchCandy> candies;
    
    
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
    
    ofTrueTypeFont din;
    smoothfloat necktilt;

};

