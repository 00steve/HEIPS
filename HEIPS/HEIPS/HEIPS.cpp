// HEIPS.cpp : Defines the exported functions for the DLL application.
//
#include "stdafx.h"
#include "HEIPS.h"



__declspec(dllexport) const char* HEIPSImageFileName() {
	char* szSampleString = (char*)heips.fileName.c_str();
	ULONG ulSize = strlen(szSampleString) + sizeof(char);
	char* pszReturn = (char*)::CoTaskMemAlloc(ulSize);
	strcpy_s(pszReturn, ulSize, szSampleString);
	return pszReturn;
}



__declspec(dllexport) unsigned int HEIPSImageHeight() {
	if (!heips.validImage) return 0;
	return heips.gdiImage->GetHeight();
}



__declspec(dllexport) bool HEIPSImageLoaded() {
	return heips.validImage;
}




__declspec(dllexport) unsigned int HEIPSImageWidth() {
	if (!heips.validImage) return 0;
	return heips.gdiImage->GetWidth();
}




__declspec(dllexport) bool HEIPSLoad(char* path) {

	heips.fileName = string(path); 
	wstring widestr = wstring(heips.fileName.begin(), heips.fileName.end());
	heips.gdiImage = Gdiplus::Image::FromFile(widestr.c_str());

	//make sure image loaded successfully
	return heips.validImage = heips.gdiImage->GetLastStatus() == Gdiplus::Ok;
}
