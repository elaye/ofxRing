#include "ofApp.h"
#include "ofxRing.h"
//--------------------------------------------------------------
void ofApp::setup(){

	maxInnerRadius = 40;
	minInnerRadius = 20;
	maxOuterRadius = 80;
	minOuterRadius = 50;

	for(int i = 0; i < 5; ++i){
		ofxRing ring((i+1)*170, ofGetHeight()/2.0, 50.0, 80.0);
		rings.push_back(ring);
	}
}

//--------------------------------------------------------------
void ofApp::update(){
	for(int i = 0; i < rings.size(); ++i){
		float innerRadius = minInnerRadius + (maxInnerRadius - minInnerRadius)*(1 + sin(-ofGetElapsedTimef()*3.0 + i))/2.0;
		float outerRadius = minOuterRadius + (maxOuterRadius - minOuterRadius)*(1 + sin(-ofGetElapsedTimef()*3.0 + i + M_PI))/2.0;
		rings[i].setInnerRadius(innerRadius);
		rings[i].setOuterRadius(outerRadius);
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackgroundGradient(ofColor(15, 16, 37), ofColor(11, 11, 10));

	for(vector<ofxRing>::iterator r = rings.begin(); r != rings.end(); ++r){
		r->draw();
	}

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
