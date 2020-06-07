#include <fstream>

#include "Bitmap.h"
#include "BitmapInfoHeader.h"
#include "BitmapFileHeader.h"

using namespace Hoowan;
using namespace std;

namespace Hoowan{

	Bitmap::Bitmap(int width, int height) :
		m_width(width), 
		m_height(height), 
		m_pPixels(new uint8_t[width * height * 3]{})
	{

	}

	bool Bitmap::write(string filename) {
		// Create file and info header structs
		BitmapFileHeader fileHeader;
		BitmapInfoHeader infoHeader;

		// Set struct variables
		fileHeader.fileSize = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader) + (m_width * m_height * 3);
		fileHeader.dataOffset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);

		infoHeader.width = m_width;
		infoHeader.height = m_height;

		// Open the file
		ofstream file;
		file.open(filename, ios::out | ios::binary);

		if (!file)
			return false;

		// Write data to file
		file.write((char*)&fileHeader, sizeof(fileHeader));
		file.write((char*)&infoHeader, sizeof(infoHeader));
		file.write((char*)m_pPixels.get(), m_width * m_height * 3);
		
		// Close file
		file.close();

		if (!file)
			return false;

		// Writing successful
		return true;
	}

	void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue) {
		// Point to the correct pixel
		uint8_t* pPixel = m_pPixels.get();
		pPixel += (y * 3 * m_width) + (x * 3);

		// Set RGB value of pixel (little endian)
		pPixel[0] = blue;
		pPixel[1] = green;
		pPixel[2] = red;
	}

	Bitmap::~Bitmap() {

	}

}