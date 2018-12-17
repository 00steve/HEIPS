// HEIPS.cpp : Defines the exported functions for the DLL application.
//
#include "stdafx.h"
#include "HEIPS.h"


HEIPS::HEIPS() :
	fileName(""),
	fileName_cstr(NULL),
	gdiBitmap(NULL),
	validImage(false) {
}

HEIPS::~HEIPS() {
	delete fileName_cstr;
	delete gdiBitmap;
}





__declspec(dllexport) const char* HEIPSGetImageData() {
	//Gdiplus::BitmapData *lockdat = NULL;
	//Gdiplus::Rect *r = new Gdiplus::Rect(0,0, heips.gdiBitmap->GetWidth(), heips.gdiBitmap->GetHeight());
	//heips.gdiBitmap->LockBits(r, Gdiplus::ImageLockModeRead, PixelFormatDontCare, lockdat);
	return "wefwef\0";
}

__declspec(dllexport) const char* HEIPSImageFileName() {
	char* szSampleString = (char*)heips.fileName.c_str();
	ULONG ulSize = strlen(szSampleString) + sizeof(char);
	char* pszReturn = (char*)::CoTaskMemAlloc(ulSize);
	strcpy_s(pszReturn, ulSize, szSampleString);
	return pszReturn;
}



__declspec(dllexport) unsigned int HEIPSImageHeight() {
	if (!heips.validImage) return 0;
	return heips.gdiBitmap->GetHeight();
}



__declspec(dllexport) bool HEIPSImageLoaded() {
	return heips.validImage;
}




__declspec(dllexport) unsigned int HEIPSImageWidth() {
	if (!heips.validImage) return 0;
	return heips.gdiBitmap->GetWidth();
}




__declspec(dllexport) bool HEIPSLoad(char* path) {

	heips.fileName = string(path); 
	wstring widestr = wstring(heips.fileName.begin(), heips.fileName.end());
	heips.gdiBitmap = new Gdiplus::Bitmap(widestr.c_str());
	//heips.gdiImage = Gdiplus::Image::FromFile(widestr.c_str());
	//make sure image loaded successfully
	return heips.validImage = heips.gdiBitmap->GetLastStatus() == Gdiplus::Ok && heips.gdiBitmap;
}
