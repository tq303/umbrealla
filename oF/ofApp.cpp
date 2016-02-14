#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetLogLevel(OF_LOG_VERBOSE);
	ofSetFrameRate(60);

	h = 480;
	w = 640;
	angle = 0;
	screenSectionWidth = floor(w/3);

	allowSaveMesh = false;

	kinect.setRegistration(true);
	kinect.init(false, false); // disable video image (faster fps)

	kinect.open();		// opens first available kinect

	// print the intrinsic IR sensor values
	if(kinect.isConnected()) {
		ofLogNotice() << "sensor-emitter dist: "   << kinect.getSensorEmitterDistance() << "cm";
		ofLogNotice() << "sensor-camera dist:  "   << kinect.getSensorCameraDistance() 	<< "cm";
		ofLogNotice() << "zero plane pixel size: " << kinect.getZeroPlanePixelSize() 	<< "mm";
		ofLogNotice() << "zero plane dist: " 	   << kinect.getZeroPlaneDistance() 	<< "mm";
	}

	kinectAngle.addListener(this, &ofApp::angleChange);
	saveMeshBtn.addListener(this, &ofApp::saveMesh);

	cameraUpDwn.addListener(this, &ofApp::cameraUpDwnChange);

	topLimit.addListener(this, &ofApp::topLimitChange);
	botLimit.addListener(this, &ofApp::botLimitChange);
	leftLimit.addListener(this, &ofApp::leftLimitChange);
	rightLimit.addListener(this, &ofApp::rightLimitChange);

	nearThreshold.addListener(this, &ofApp::nearThresholdChange);
	farThreshold.addListener(this, &ofApp::farThresholdChange);

	// ui
	gui.setup();

	gui.add(cameraUpDwn.setup( "Camera Up/Dwn", 0, -500, 500 ));
	gui.add(cameraInOut.setup( "Camera In/Out", 670, 0, 1000 ));

	gui.add(nearThreshold.setup( "Near Threshold", 0, 0, KINECT_MAX_THRESHOLD ));
	gui.add(farThreshold.setup( "Far Threshold", KINECT_MAX_THRESHOLD, 0, KINECT_MAX_THRESHOLD ));

	gui.add(topLimit.setup("top", 0, 0, 480));
	gui.add(botLimit.setup("bot", 480, 0, 480));
	gui.add(leftLimit.setup("left", 0, 0, 640));
	gui.add(rightLimit.setup("right", 640, 0, 640));
	gui.add(kinectAngle.setup("angle", 0, -15, 15));
	gui.add(pointStep.setup("point step", 1, 1, h/2));
	gui.add(saveMeshBtn.setup("SAVE"));

	// mesh
	mesh.setMode(OF_PRIMITIVE_POINTS);

	// camera
	cam.setPosition(ofVec3f(0,0,0));
	centreNode.setPosition(ofVec3f(0,0,0));
	cam.lookAt(centreNode);

	// serial
	AD1.listDevices();
	AD1.setup("COM6", BAUD_RATE);

	resetDetectionVariables();
}

//--------------------------------------------------------------
void ofApp::update() {
	ofBackground(0, 0, 0);
	kinect.update();
}

//--------------------------------------------------------------
void ofApp::exit() {
	kinect.setCameraTiltAngle(0); // zero the tilt on exit
	kinect.close();
}

void ofApp::resetDetectionVariables() {
	hasLeft = false;
	hasRight = false;
	hasCenter = false;

	leftDensity = 0;
	rightDensity = 0;
	centerDensity = 0;

	leftProximity = 0;
	rightProximity = 0;
	centerProximity = 0;
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofSetColor(255, 255, 255);

	cam.setPosition(ofVec3f(0, cameraUpDwn, cameraInOut));
	cam.begin();

	centreNode.draw();
	cam.draw();

	// draw line from cam to its lookat
	ofSetColor(0, 255, 255);
	ofVec3f v1 = cam.getGlobalPosition();
	ofVec3f v2 = centreNode.getGlobalPosition();
    ofLine(v1,v2);

	// points cloud
	drawPointCloud();

	cam.end();

	ofSetColor(255, 255, 255);

    gui.setPosition(1068, 10);
	gui.draw();

	ofSetColor(255, 255, 0);
}

void ofApp::drawPointCloud() {

	int z = 0;

	for(int y = 0; y < h; y += pointStep) {
		for(int x = 0; x < w; x += pointStep) {

			z = kinect.getDistanceAt(x, y);

			if (y > topLimit && y < botLimit &&
				x > leftLimit && x < rightLimit &&
				z > 0 && z > nearThreshold && z < farThreshold) {

				if (x >= 0 && x <= screenSectionWidth) {
					hasLeft = true;
					leftDensity += pointStep;
					if (z > leftProximity) {
						leftProximity = z;
					}
				}

				if (x > screenSectionWidth && x <= (screenSectionWidth * 2)) {
					hasCenter = true;
					centerDensity += pointStep;
					if (z > centerProximity) {
						centerProximity = z;
					}
				}

				if (x > (screenSectionWidth * 2) && x <= w) {
					hasRight = true;
					rightDensity += pointStep;
					if (z > rightProximity) {
						rightProximity = z;
					}
				}

				mesh.addColor(ofColor(255,255,255));
				mesh.addVertex(kinect.getWorldCoordinateAt(x, y));

			}

		}
	}

	ofPushMatrix();
	{
		// the projected points are 'upside down' and 'backwards'
		glPointSize(1);
		ofScale(1, -1, -1);
		ofTranslate(0, 0, -1000); // center the points a bit
		ofEnableDepthTest();
		mesh.drawVertices();
		ofDisableDepthTest();
	}
	ofPopMatrix();

	if (allowSaveMesh) {
		outputMeshToFile();
		allowSaveMesh = false;
	}

	mesh.clear();

	buildArduinoComms();
}

//--------------------------------------------------------------
void ofApp::buildArduinoComms() {

	format.setUmbrella(23);
    format.setAnimation(45);
    // format.setSpeed(4000 - ofMap(rightDensity, 0, ((h * screenSectionWidth)), 0, 4000));
    // format.setColour(ofMap(rightProximity, nearThreshold, farThreshold, 0, 255), 100, 100);
    format.setSpeed(200);
	format.setColour(255,255,255);

	AD1.writeBytes(format.encode(), TRANSMIT_ELEMENT_COUNT);

	resetDetectionVariables();
}

//--------------------------------------------------------------
void ofApp::angleChange(int & _angle){
	kinect.setCameraTiltAngle(_angle);
}

void ofApp::topLimitChange(int & _top) {
	if (_top >= botLimit) {
		_top = botLimit;
	}
}

void ofApp::botLimitChange(int & _bot) {
	if (_bot <= topLimit) {
		_bot = topLimit;
	}
}

void ofApp::leftLimitChange(int & _left) {
	if (_left >= rightLimit) {
		_left = rightLimit;
	}
}

void ofApp::rightLimitChange(int & _right) {
	if (_right <= leftLimit) {
		_right = leftLimit;
	}
}

void ofApp::nearThresholdChange(int & _near) {
	if (_near >= farThreshold)	{
		_near = farThreshold;
	}
}
void ofApp::farThresholdChange(int & _far) {
	if (_far <= nearThreshold)	{
		_far = nearThreshold;
	}
}

//--------------------------------------------------------------
void ofApp::cameraUpDwnChange(float & _position) {
	cam.lookAt(centreNode);
}

//--------------------------------------------------------------
void ofApp::saveMesh(){
	allowSaveMesh = true;
}

void ofApp::outputMeshToFile() {
	ofstream obj;

    obj.open("data/output.obj");

    obj << "#  ========================================================================== \n"
    << "#  OBJ exported by James Alliban \n"
    << "#  Application built using openFrameworks \n"
    << "#  ========================================================================== \n";

    if (obj.is_open()) {

    	ofLogNotice() << "obj is open " << mesh.getVertices().size();

        for (int i = 0; i < mesh.getVertices().size(); i++) {
            obj << "v " << mesh.getVertex(i).x << " " << mesh.getVertex(i).y << " " << mesh.getVertex(i).z << endl;
        }

        for (int i = 0; i < mesh.getIndices().size() / 3; i++) {

            obj << "f " << mesh.getIndex(i*3) + 1 << " " << mesh.getIndex(i*3+1) + 1 << " " << mesh.getIndex(i*3+2) + 1 << endl;
        }

        for (int i = 0; i < mesh.getVertices().size(); i++)   {
        	obj << "vn " << mesh.getVertex(i).x << " " << mesh.getVertex(i).y << " " << mesh.getVertex(i).z << endl;
        }


        if (mesh.getVertices().size() == 0 || mesh.getIndices().size() == 0) {
            obj << "v " << 0 << " " << 1 << " " << 2 << endl;
            obj << "v " << 2 << " " << 3 << " " << 4 << endl;
            obj << "v " << 4 << " " << 5 << " " << 6 << endl;
            obj << "f " << 1 << " " << 2 << " " << 3 << endl;
        }
    }

    obj.close();
    mesh.save("output.ply");
}

//--------------------------------------------------------------
void ofApp::keyPressed (int key) {
	switch (key) {

		case 'w':
			kinect.enableDepthNearValueWhite(!kinect.isDepthNearValueWhite());
			break;

		case 'o':
			kinect.setCameraTiltAngle(angle); // go back to prev tilt
			kinect.open();
			break;

		case 'c':
			kinect.setCameraTiltAngle(0); // zero the tilt
			kinect.close();
			break;

		case '0':
			kinect.setLed(ofxKinect::LED_OFF);
			break;

		case OF_KEY_UP:
			angle++;
			if(angle>30) angle=30;
			kinect.setCameraTiltAngle(angle);
			break;

		case OF_KEY_DOWN:
			angle--;
			if(angle<-30) angle=-30;
			kinect.setCameraTiltAngle(angle);
			break;

	}
}
