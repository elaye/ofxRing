#include "ofxRing.h"

ofxRing::ofxRing(){}

ofxRing::ofxRing(float x, float y, float _r_int, float _r_ext, int resolution){
	p = ofPoint(x, y);
	r_int = _r_int;
	r_ext = _r_ext;

	n = resolution;

	initMesh();
}

ofPoint ofxRing::getPosition(){
	return p;
}
float ofxRing::getInnerRadius(){
	return r_int;
}
float ofxRing::getOuterRadius(){
	return r_ext;
}
int ofxRing::getResolution(){
	return n;
}

void ofxRing::setPosition(float x, float y){
	p = ofPoint(x, y);
	updateIntVertices();
	updateExtVertices();
}

void ofxRing::setInnerRadius(float r){
	r_int = r;
	updateIntVertices();
}

void ofxRing::setOuterRadius(float r){
	r_ext = r;
	updateExtVertices();
}

void ofxRing::setResolution(int resolution){
	n = resolution;
	initMesh();
}

void ofxRing::draw(){
	vboMesh.getVbo().drawElements(GL_TRIANGLES, 6*n);
}

void ofxRing::initMesh(){
	mesh.clear();
	mesh.addVertex(ofVec3f(p.x + r_int*cos((float)M_PI/n), p.y + r_int*sin((float)M_PI/n), 0));
	mesh.addVertex(ofVec3f(p.x + r_ext, p.y, 0));

	for(int i = 1; i < n; ++i){
		float a1 = (float)(2*i+1)/n*M_PI;
		float a2 = (float)2*i/n*M_PI;

		mesh.addVertex(ofVec3f(p.x + r_int*cos(a1), p.y + r_int*sin(a1), 0));
		mesh.addVertex(ofVec3f(p.x + r_ext*cos(a2), p.y + r_ext*sin(a2), 0));

		mesh.addIndex(2*(i-1));
		mesh.addIndex(2*i-1);
		mesh.addIndex(2*i+1);

		mesh.addIndex(2*(i-1));
		mesh.addIndex(2*i);
		mesh.addIndex(2*i+1);

	}

	mesh.addIndex(1);
	mesh.addIndex(2*n-1);
	mesh.addIndex(2*n-2);

	mesh.addIndex(0);
	mesh.addIndex(1);
	mesh.addIndex(2*n-2);

	vboMesh.getVbo().setMesh(mesh, GL_DYNAMIC_DRAW);
}

void ofxRing::updateIntVertices(){
	mesh.setVertex(0, ofVec3f(p.x + r_int*cos((float)M_PI/n), p.y + r_int*sin((float)M_PI/n), 0));

	for(int i = 1; i < n; ++i){
		float a = (float)(2*i+1)/n*M_PI;
		mesh.setVertex(2*i, ofVec3f(p.x + r_int*cos(a), p.y + r_int*sin(a), 0));
	}
	updateVbo();
}

void ofxRing::updateExtVertices(){
	mesh.setVertex(1, ofVec3f(p.x + r_ext, p.y, 0));

	for(int i = 1; i < n; ++i){
		float a = (float)2*i/n*M_PI;
		mesh.setVertex(2*i+1, ofVec3f(p.x + r_ext*cos(a), p.y + r_ext*sin(a), 0));
	}
	updateVbo();
}

void ofxRing::updateVbo(){
	vboMesh.getVbo().updateMesh(mesh);
}