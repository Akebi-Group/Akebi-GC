#pragma once

#include <Windows.h>
#include <iostream>
#include <fstream>
#include <string>

#include "util.h"

// #define MANUAL_MAP

bool InjectDLL(HANDLE hProc, const std::string& filepath);