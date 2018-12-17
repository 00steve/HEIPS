#pragma once

#include "stdafx.h"
#include "stdio.h"
#include <string>

using namespace std;



extern "C" __declspec(dllexport) bool HEIPSLoad(char* path);


extern "C" __declspec(dllexport) int HEIPSs(char* path);