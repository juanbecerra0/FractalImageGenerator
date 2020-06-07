#ifndef BITMAPFILEHEADER_H_
#define BITMAPFILEHEADER_H_

#include <cstdint>

using namespace std;

// Allign struct data to two-byte boundaries
#pragma pack(2)

struct BitmapFileHeader {
	char header[2]{ 'B', 'M' };
	int32_t fileSize;
	int32_t reserved{ 0 };
	int32_t dataOffset;
};



#endif