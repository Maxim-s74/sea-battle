#pragma once

#include <iostream>
#include <math.h>
#include <time.h>
#include <cstdlib>
#include <cstdio>
#include <conio.h>
#include <Windows.h>

using namespace std;

inline void CODEModify(const char stringfPrint[]) {
	setlocale(LC_ALL, ".1251");
	cout << stringfPrint;
	setlocale(LC_ALL, ".866");
}