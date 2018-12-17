#pragma once
#include "stdafx.h"

#include <windows.h> 
#include <gdiplus.h>
#include <string>

using namespace std;

int x = 0;


class Data{
public:
	Data() :
		fileName(""),
		gdiImage(NULL),
		validImage(false){
	}


	string fileName;
	const char* fileName_cstr;
	Gdiplus::Image* gdiImage;
	bool validImage;
};

Data heips;


extern "C" {
	__declspec(dllexport) const char* HEIPSImageFileName();
	__declspec(dllexport) bool HEIPSImageLoaded();
	__declspec(dllexport) bool HEIPSLoad(char* path);
	__declspec(dllexport) int HEIPSStringLength(char* path);
}