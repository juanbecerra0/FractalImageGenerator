// Headers
#include "FractalCreator.h"

using namespace Hoowan;

int main() {

	cout << "Generating fractal..." << endl;

	// Define width and height of bitmap image
	int const WIDTH = 800;
	int const HEIGHT = 600;

	// Create a fractal creator object
	FractalCreator fractalCreator(WIDTH, HEIGHT);

	// Zoom into a portion of the fractal
	fractalCreator.addZoom(Zoom(295, HEIGHT - 202, 0.1));
	fractalCreator.addZoom(Zoom(312, HEIGHT - 304, 0.1));

	// Calculate iterations and their stored totals
	fractalCreator.calculateIterations();
	fractalCreator.calculateTotalIterations();

	// Draw the fractal
	fractalCreator.drawFractal();

	// Write the fractal to a bitmap image
	fractalCreator.writeBitmap("test.bmp");

	cout << "Finished!" << endl;

	return 0;
}