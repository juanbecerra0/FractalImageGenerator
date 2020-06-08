#ifndef FRACTALCREATOR_H_
#define FRACTALCREATOR_H_

#include <string>
#include <iostream>
#include <cstdint>
#include <memory>
#include <math.h>
#include <vector>
#include <cassert>

#include "Zoom.h"
#include "Bitmap.h"
#include "Mandelbrot.h"
#include "ZoomList.h"
#include "RGB.h"

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

		vector<int> m_ranges;
		vector<RGB> m_colors;
		vector<int> m_rangeTotals;

		bool m_bGotFirstRange{ false };

	public:
		FractalCreator(int width, int height);

		void addZoom(const Zoom& zoom);
		void addRange(double rangeEnd, const RGB& rgb);

		void generateFractal(string fileName);

	private:
		void calculateIterations();
		void calculateTotalIterations();
		void calculateRangeTotals();
		void drawFractal();
		int getRange(int iterations) const;
		void writeBitmap(string name);

	};
}


#endif