#ifndef FRACTALCREATOR_H_
#define FRACTALCREATOR_H_

#include <string>
#include <iostream>
#include <cstdint>
#include <memory>
#include <math.h>

#include "Zoom.h"
#include "Bitmap.h"
#include "Mandelbrot.h"
#include "ZoomList.h"

using namespace std;

namespace Hoowan {
	class FractalCreator {
	private:
		int m_width;
		int m_height;
		unique_ptr<int[]> m_histogram;
		unique_ptr<int[]> m_fractal;
		Bitmap m_bitmap;
		ZoomList m_zoomList;
		int m_total{ 0 };

	public:
		FractalCreator(int width, int height);

		void calculateIterations();
		void calculateTotalIterations();
		void drawFractal();
		void addZoom(const Zoom& zoom);
		void writeBitmap(string name);
	};
}


#endif