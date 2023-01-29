#include "ofApp.h"	

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(30);
	ofSetWindowTitle("openFrameworks");

	ofBackground(255);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWindowSize() * 0.5);

	auto numberOfActor = 300;
	ofColor color;

	ofSeedRandom(39);
	for (int i = 0; i < numberOfActor; i++) {

		auto noise_seed = glm::vec2(ofRandom(1000), ofRandom(1000));
		auto len = ofMap(i, 0, numberOfActor, 80, 750);
		color.setHsb(ofMap(ofNoise(ofRandom(255), ofGetFrameNum() * 0.001), 0, 1, 0, 255), 100, 255);
		
		ofSetColor(39);
		for (int k = 0; k < 100; k++) {

			auto location = glm::vec3(
				ofMap(ofNoise(noise_seed.x, k * 0.001 + ofGetFrameNum() * 0.0018), 0, 1, -350, 350),
				ofMap(ofNoise(noise_seed.y, k * 0.001 + ofGetFrameNum() * 0.0018), 0, 1, -350, 350), 0);

			ofDrawCircle(glm::normalize(location) * len, 12);
		}
		
		ofSetColor(color);
		for (int k = 0; k < 100; k++) {

			auto location = glm::vec3(
				ofMap(ofNoise(noise_seed.x, k * 0.001 + ofGetFrameNum() * 0.0018), 0, 1, -350, 350),
				ofMap(ofNoise(noise_seed.y, k * 0.001 + ofGetFrameNum() * 0.0018), 0, 1, -350, 350), 0);

			ofDrawCircle(glm::normalize(location) * len, 10);
		}
	}
}


//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}