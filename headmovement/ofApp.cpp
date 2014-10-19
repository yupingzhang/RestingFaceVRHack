#include "ofApp.h"

void ofApp::setup() {
	ofSetVerticalSync(true);
	faceShift.setup();
	faceShift.import("export");
	
	light.enable();
	light.setPosition(+500, -500, +500);
//    gui0 = new ofxUISuperCanvas("point picker");
//    gui0->addSpacer();
//    gui0->addLabel("location");
//    gui0->addSlider("point", 0.0, 7500., &pointone);
//    gui0->loadSettings("gui.xml");
    //rx, ry =0;
    //
    horizontalMovement = 0;

}

void ofApp::update() {
	faceShift.update();
}

void ofApp::draw(){

	ofBackground(128);
	
	//cam.begin();

    glEnable(GL_DEPTH_TEST);
  

	
	ofEnableLighting();
	ofSetColor(255);
    
   // faceShift.getBlendMesh().enableColors();



    vector<ofVec3f> verts;
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2.+horizontalMovement,ofGetHeight()/2.);
    ofScale(1,1,1);
    
    ofRotateZ(180);

    faceShift.getBlendMesh().draw();
  
    glDisable(GL_DEPTH_TEST);
    ofNoFill();
    ofCircle(faceShift.getBlendMesh().getVertices()[(int)pointone], 5);
    ofSetColor(0);
    ofLine(faceShift.getBlendMesh().getVertices()[5431], faceShift.getNeutralMesh().getVertices()[5431]);
    ofLine(faceShift.getBlendMesh().getVertices()[1810], faceShift.getNeutralMesh().getVertices()[1810]);
    ofDisableLighting();
	
    
    float cheek1 = ofDist(faceShift.getBlendMesh().getVertices()[5431].x,faceShift.getBlendMesh().getVertices()[5431].y,
                          faceShift.getNeutralMesh().getVertices()[5431].x,faceShift.getNeutralMesh().getVertices()[5431].y);
    ofPopMatrix();
    float cheek2 = ofDist(faceShift.getBlendMesh().getVertices()[1810].x,faceShift.getBlendMesh().getVertices()[1810].y,
                          faceShift.getNeutralMesh().getVertices()[1810].x,faceShift.getNeutralMesh().getVertices()[1810].y);
    ofPopMatrix();
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
   
//    ofCircle(faceShift.getBlendMesh().getVertices()[1580], 5);
    ofFill();
  
    ofRect(30, 300, cheek.get()*100, 30);
    
	
	
    float xcenter = ofGetWidth()/2;
   
    
    if (faceShift.getBlendshapeWeights().size()!=0){
    for (int i = 0; i<faceShift.getBlendshapeNames().size(); i++) {
        ofSetColor(0);
        ofRect(10, 20*i, faceShift.getBlendshapeWeights()[i]*300, 10);
        ofSetColor(255);
        ofDrawBitmapString(faceShift.getBlendshapeNames()[i], ofPoint(10,10+ (20*i)));
    }
    }
    
}


void ofApp::exit(){
   // gui0->saveSettings("gui.xml");
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
