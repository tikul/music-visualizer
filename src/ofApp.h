#pragma once

#include "ofMain.h"
#include "Gradient.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		void toggleMusicPause();
		float scaleBar(int bar);
		void drawGlow(int x, int y, float radius);

		ofSoundPlayer music;
		ofColor *barColors;
		ofImage folderIcon;

		float *fftSmooth;
		int bands;
		bool musicIsPaused;
};
