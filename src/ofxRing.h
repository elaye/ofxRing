#pragma once

#include "ofMain.h"

class ofxRing {

	ofPoint p;

	ofParameter<float> r_int;
	ofParameter<float> r_ext;

	int n;

	ofMesh mesh;

	ofVboMesh vboMesh;

	public:
		ofxRing();
		ofxRing(float x, float y, float r_int, float r_ext, int resolution=32);
		
		void draw();
		void setPosition(float x, float y);
		void setInnerRadius(float r);
		void setOuterRadius(float r);
		void setResolution(int resolution);

		ofPoint getPosition();
		float getInnerRadius();
		float getOuterRadius();
		int getResolution();

	private:
		void initMesh();
		void updateIntVertices();
		void updateExtVertices();
		void updateVbo();
};

inline void ofxDrawRing(float x, float y, float innerRadius, float outerRadius){
	ofxRing ring(x, y, innerRadius, outerRadius);
	ring.draw();
}

inline void ofxDrawRing(ofPoint pos, float innerRadius, float outerRadius){
	ofxDrawRing(pos.x, pos.y, innerRadius, outerRadius);
}