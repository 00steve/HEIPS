// HEIPS.cpp : Defines the exported functions for the DLL application.
//
#include "stdafx.h"
#include "HEIPS.h"



__declspec(dllexport) char* HEIPSImageFileName() {
	return (char*)heips.fileName.c_str();
}



__declspec(dllexport) bool HEIPSLoad(char* path) {

	heips.fileName = string(path); 
	wstring widestr = wstring(heips.fileName.begin(), heips.fileName.end());
	heips.gdiImage = Gdiplus::Image::FromFile(widestr.c_str());

	//make sure image loaded successfully
	return heips.validImage = heips.gdiImage->GetLastStatus() == Gdiplus::Ok;
}



__declspec(dllexport) int HEIPSStringLength(char* path) {
	string n = string(path);
	return n.length() + x++;
}