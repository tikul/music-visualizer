#include "Gradient.h"


ofColor Gradient::GradientGetColor(int bar, ofColor prevColor, int numBars) {
	int segmentLength = ceil(numBars / 6.0);
	int delta = 6 * 256 / numBars;
	ofColor returnColor;
	int segment = bar / segmentLength;
	int r = prevColor.r;
	int g = prevColor.g;
	int b = prevColor.b;
	if (segment == 0) {
		returnColor.set(r, max(0, g - delta), b, 255);
	}
	else if (segment == 1) {
		returnColor.set(min(255, r + delta), g, b, 255);
	}
	else if (segment == 2) {
		returnColor.set(r, g, max(0, b - delta), 255);
	}
	else if (segment == 3) {
		returnColor.set(r, min(255, g + delta), b, 255);
	}
	else if (segment == 4) {
		returnColor.set(max(0, r - delta), g, b, 255);
	}
	else if (segment == 5) {
		returnColor.set(r, g, min(255, b + delta), 255);
	}
	else {
		cout << "Error";
	}
	return returnColor;
}