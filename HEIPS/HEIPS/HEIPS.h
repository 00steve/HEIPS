#pragma once
#include "stdafx.h"

#include <windows.h> 
#include <gdiplus.h>
#include <string>

using namespace std;

int x = 0;


class HEIPS {
public:

	HEIPS();
	~HEIPS();

	string fileName;
	const char* fileName_cstr;
	Gdiplus::Bitmap* gdiBitmap;
	bool validImage;
};

HEIPS heips;




extern "C" {
	__declspec(dllexport) const char* HEIPSGetImageData();
	__declspec(dllexport) const char* HEIPSImageFileName();
	__declspec(dllexport) unsigned int HEIPSImageHeight();
	__declspec(dllexport) bool HEIPSImageLoaded();
	__declspec(dllexport) unsigned int HEIPSImageWidth();
	__declspec(dllexport) bool HEIPSLoad(char* path);
}