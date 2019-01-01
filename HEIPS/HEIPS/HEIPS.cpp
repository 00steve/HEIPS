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
	Gdiplus::BitmapData *lockdat = NULL;
	Gdiplus::Rect *r = new Gdiplus::Rect(0,0, heips.gdiBitmap->GetWidth(), heips.gdiBitmap->GetHeight());
	heips.gdiBitmap->LockBits(r, Gdiplus::ImageLockModeRead, PixelFormatDontCare, lockdat);


	heips.gdiBitmap->UnlockBits(lockdat);

	//stupid shit to return a value that doesn't break the program
	char* szSampleString = (char*)heips.fileName.c_str();
	ULONG ulSize = strlen(szSampleString) + sizeof(char);
	char* pszReturn = (char*)::CoTaskMemAlloc(ulSize);
	strcpy_s(pszReturn, ulSize, szSampleString);
	return pszReturn;
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


/*
hope you have a valid image because apparently I don't understand Gdiplus
or the checking if a file is valid and checking if the last status is OK 
doesn't work, so just assume your image loads, bitch, cause ya basic.
*/

__declspec(dllexport) bool HEIPSLoad(char* path) {

	heips.fileName = string(path); 
	wstring widestr = wstring(heips.fileName.begin(), heips.fileName.end());
	heips.gdiBitmap = new Gdiplus::Bitmap(widestr.c_str());
	return heips.validImage = heips.gdiBitmap && (Gdiplus::Ok == heips.gdiBitmap->GetLastStatus());
	//return heips.validImage = heips.gdiBitmap->GetLastStatus() == Gdiplus::Ok && heips.gdiBitmap;
}
