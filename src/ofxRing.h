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
		void setRInt(float r);
		void setRExt(float r);
		void setResolution(int resolution);

	private:
		void initMesh();
		void updateIntVertices();
		void updateExtVertices();
		void updateVbo();
};