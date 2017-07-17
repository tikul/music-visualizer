#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	music.load("example3.mp3");
	folderIcon.load("folder-icon.png");
	//folderIcon.setColor(ofColor::white);

	fftSmooth = new float[8192];
	for (int i = 0; i < 8192; i++) {
		fftSmooth[i] = 0;
	}
	bands = 64;
	barColors = new ofColor[bands];
	ofColor prevBar;
	prevBar.set(0, 255, 255);
	for (int i = 0; i < bands; i++) {
		barColors[i] = Gradient::GradientGetColor(i, prevBar, bands);
		prevBar.set(barColors[i]);
	}
	music.setLoop(true);
	music.setVolume(0.2);
	musicIsPaused = false;
}

//--------------------------------------------------------------
void ofApp::update(){
	ofSoundUpdate();
	float *value = ofSoundGetSpectrum(bands);
	for (int i = 0; i < bands; i++) {
		fftSmooth[i] *= 0.96f;
		if (value[i] > fftSmooth[i]) {
			fftSmooth[i] = value[i];
		}
	}
	folderIcon.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0, 0, 0);
	ofSetColor(255);
	ofPoint v1, v2;
	float sleft = (ofGetWidth() - 8 * bands) / 2;
	float sright = sleft + 8 * (bands / 2);
	v1.x = sleft;
	v1.y = ofGetHeight() / 2 + 200;
	v2.x = v1.x + 5;
	v2.y = v1.y;
	for (int i = 0; i < bands; i++) {
		ofSetColor(barColors[i]);
		ofDrawLine(v1, v2);
		v1.x += 8;
		v2.x += 8;
	}
	for (int i = 0, j = bands / 2; i < bands/2; i++, j--) {
		ofSetColor(barColors[i]);
		ofDrawRectangle(sleft + 8*i, ofGetHeight() / 2 + 200, 5, -fftSmooth[j] * 300 * scaleBar(j));
	}
	for (int i = 0; i < bands/2; i++) {
		ofSetColor(barColors[i + bands / 2]);
		ofDrawRectangle(8*i+sright, ofGetHeight()/2 + 200, 5, -fftSmooth[i]*300*scaleBar(i));
	}

	float pos = music.getPosition();
	float totWidth = 0.75 * (8 * bands);
	ofSetColor(204, 204, 204, 50);
	ofDrawRectRounded((ofGetWidth() - totWidth) / 2, ofGetHeight() / 2 + 225, totWidth, 3, 5);
	ofSetColor(255, 255, 255);
	ofDrawRectRounded((ofGetWidth() - totWidth) / 2, ofGetHeight()/2 + 225, pos*totWidth, 3, 5);
	
	//folderIcon.draw(ofGetWidth() - 80, 50, 3, 30, 30);

	//int mouseX = ofGetMouseX();
	//int mouseY = ofGetMouseY();

	//if (mouseX > ofGetWidth() - 80 && mouseX < ofGetWidth() - 50 && mouseY > 50 && mouseY < 80) {
	//		background glow
	//}

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch (key) {
	case 'z':
		music.play();
		musicIsPaused = false;
		break;
	case 'x':
		music.stop();
		musicIsPaused = true;
		break;
	case ' ':
		if (music.isPlaying()) {
			toggleMusicPause();
		}
		break;
	}
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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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

void ofApp::toggleMusicPause() {
	musicIsPaused = !musicIsPaused;
	music.setPaused(musicIsPaused);
}

float ofApp::scaleBar(int bar) {
	//Good heights based on trial and error
	return 0.75 * atan(bar - 5) + 1.6;
}

void ofApp::drawGlow(int x, int y, float radius) {
	
}