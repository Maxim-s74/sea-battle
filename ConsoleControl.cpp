#include "mainHeader.h"

void textcolor(int color)
{
	static int __BACKGROUND;

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);	//Получить идентификатор окна консоли
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;

	GetConsoleScreenBufferInfo(hConsole, &csbiInfo);   //Получить сведения об указанном буфере экрана консоли

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color + (__BACKGROUND << 4));
}

void ConsoleReSize() {
	HWND hwnd = GetConsoleWindow();
	RECT lpRect;
	GetWindowRect(hwnd, &lpRect);

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	GetConsoleScreenBufferInfo(hConsole, &csbiInfo);

	int resolutionX = (lpRect.right - lpRect.left) / (csbiInfo.srWindow.Right - csbiInfo.srWindow.Left);
	int resolutionY = (lpRect.bottom - lpRect.top) / (csbiInfo.srWindow.Bottom - csbiInfo.srWindow.Top);
	int newWindowRight = resolutionX * 115;
	int newWindowBottom = resolutionY * (csbiInfo.dwMaximumWindowSize.Y - 5);
	MoveWindow(hwnd, 200, 0, newWindowRight, newWindowBottom, true);
}

void CursorUp() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	GetConsoleScreenBufferInfo(hConsole, &csbiInfo);
	COORD position = csbiInfo.dwCursorPosition;

	position.Y -= 1;
	position.X = 0;
	SetConsoleCursorPosition(hConsole, position);
}


void CursorRevers() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	GetConsoleScreenBufferInfo(hConsole, &csbiInfo);
	COORD position = csbiInfo.dwCursorPosition;

	if (position.Y > 26) {
		position.Y -= 26;
		position.X = 0;
		SetConsoleCursorPosition(hConsole, position);

		for (int i = 0; i < 26; i++) {
			for (int j = 0; j < 107; j++) cout << " ";
			cout << endl;
		}

		SetConsoleCursorPosition(hConsole, position);
	}
}

int CursorCurrentPosition() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	GetConsoleScreenBufferInfo(hConsole, &csbiInfo);
	return csbiInfo.dwCursorPosition.Y;
}

void ConsoleTextEraser(int oldYPosition) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	GetConsoleScreenBufferInfo(hConsole, &csbiInfo);

	int newYPosition = csbiInfo.dwCursorPosition.Y;
	COORD newPosition = csbiInfo.dwCursorPosition;
	newPosition.Y = oldYPosition;

	SetConsoleCursorPosition(hConsole, newPosition);

	for (int i = oldYPosition; i < newYPosition; i++) {
		for (int j = 0; j < 107; j++) cout << " ";
		cout << endl;
	}

	SetConsoleCursorPosition(hConsole, newPosition);
}
