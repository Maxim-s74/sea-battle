#include "mainHeader.h"
#include "Global.h"
#include <stdlib.h>
#include "ConsoleControl.h"

bool IfIncorrectInput(int numberA, int rangeBeginning, int rangeEnd) {
	if (numberA<rangeBeginning || numberA>rangeEnd) {
		CODEModify("Некоректный ввод!\n");
		return true;
	}
	else return false;
}

void AddressShow(int cellule, int** field) {
	CursorRevers();
	char numberCODE[3];

	if (field == ptrUserField) {
		textcolor(BLUE);
		CODEModify("\t\tСтреляет КОМПЬЮТЕР: ");
	}
	else if (setOfAnswers.gameMode) {
		textcolor(GREEN);
		CODEModify("\t\tВаш выстрел: ");
	}
	else {
		textcolor(GREEN);
		CODEModify("\t\tСтреляет ИСКУССТВЕННЫЙ ИНТЕЛЛЕКТ: ");
	}

	cout << (char)(cellule % fieldSize + 64);
	_itoa_s(cellule / fieldSize, &numberCODE[0], 3, 10);
	puts(&numberCODE[0]);
	textcolor(WHITE);
}

int TextToNumber(char* text) {
	if (sizeof(text) == 0) {
		return 0;
	}
	else {
		_strupr_s(&text[0], 5);
		int column = (int)text[0] - 64;
		int row = atoi(&text[1]);
		return row * fieldSize + column;
	}
}

bool TextOfAnswers(char* text) {
	_strupr_s(&text[0], 5);
	int letter = (int)text[0];
	return (letter == 89 || letter == -124);
}

int ArrowDirection(int arrow) {
	if (arrow == 72)return 0;
	else if (arrow == 80)return 1;
	else if (arrow == 75)return 2;
	else if (arrow == 77)return 3;
}