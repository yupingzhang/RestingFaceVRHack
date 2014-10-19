#pragma once

#include "ofMain.h"
#include "ofxFaceShift.h"
//#include "ofxUI.h"


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
	void setup();
	void update();
	void draw();
    void exit();

	
	ofxFaceShift faceShift;
	
	ofEasyCam cam;
	ofLight light;
    //ofImage picker;
    //ofxUISuperCanvas *gui0;
    float pointone;
    smoothfloat cheek;
    smoothfloat cheekb;
    float horizontalMovement;
};

