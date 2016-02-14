#pragma once

#include "ofMain.h"

#include "ofxKinect.h"
#include "ofxGui.h"

#include "Format.h"

#define KINECT_MAX_THRESHOLD 6000

class ofApp : public ofBaseApp {
public:

	void setup();
	void update();
	void exit();

	void resetDetectionVariables();

	void draw();

	void drawPointCloud();

	void saveMesh();
	void outputMeshToFile();

	void angleChange(int & _angle);
	void topLimitChange(int & _top);
	void botLimitChange(int & _bot);
	void leftLimitChange(int & _left);
	void rightLimitChange(int & _right);
	void nearThresholdChange(int & _near);
	void farThresholdChange(int & _far);
	void cameraUpDwnChange(float & _position);

	void buildArduinoComms();

	int screenSectionWidth;

	bool hasLeft;
	bool hasRight;
	bool hasCenter;

	int leftDensity;
	int rightDensity;
	int centerDensity;

	int leftProximity;
	int rightProximity;
	int centerProximity;

	void keyPressed(int key);

	ofxKinect kinect;

	bool allowSaveMesh;

	int angle,
		h,
		w;

	ofCamera cam;
	ofNode centreNode;

	ofMesh mesh;

	// ui
	ofxPanel gui;

	ofxIntSlider nearThreshold,
				 farThreshold,
				 topLimit,
				 botLimit,
				 leftLimit,
				 rightLimit,
				 kinectAngle,
				 pointStep;

	ofxFloatSlider cameraUpDwn,
				   cameraInOut;

	ofxButton saveMeshBtn;

	Format format;

	ofSerial	AD1,
				AD2,
				AD3;
};
