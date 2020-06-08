// Headers
#include "FractalCreator.h"

using namespace Hoowan;

int main() {

	cout << "Generating fractal..." << endl;

	// Create a fractal object, passing in resolution
	FractalCreator fractalCreator(2560, 1440);

	// Define RGB ranges of fractal
	fractalCreator.addRange(0.0, RGB(255, 0, 255));
	fractalCreator.addRange(0.33, RGB(0, 191, 255));
	fractalCreator.addRange(0.66, RGB(230, 230, 230));
	fractalCreator.addRange(1.0, RGB(255, 255, 255));

	// Zoom into a portion of the fractal
	fractalCreator.addZoom(Zoom(1189, 1136, 0.1));
	fractalCreator.addZoom(Zoom(1070, 796, 0.1));
	fractalCreator.addZoom(Zoom(1255, 764, 0.1));

	// Generate fractal and output to a file
	fractalCreator.generateFractal("test.bmp");

	cout << "Finished!" << endl;

	return 0;
}