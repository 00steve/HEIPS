// HEIPS.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "HEIPS.h"



__declspec(dllexport) bool HEIPSLoad(char* path) {
	BOOL WINAPI AllocConsole(void);
	printf("load an image\n");

	string n = string(path);
	int i = 0;
	while (path[i] != '\0') {
		++i;
	}
	if (i < 6) return false;

	return true;
}



__declspec(dllexport) int HEIPSs(char* path) {
	string n = string(path);
	return n.length();
}