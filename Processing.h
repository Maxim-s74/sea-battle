#pragma once
#include "mainHeader.h"
#include "Global.h"

// Логические действия компьютера
bool gameContin(int** ships);
int scanning(int** field, int cXcY, int& direction);
int CheckingCellStatus(int** field, int** ships, int leftBound, int rightBound, int deck);
int Response(int cellule, int** field, int** ships);
void Gunning(int** field, int cellule, int** ships);	//Стрельба
														/*Производство выстрела.
														* Генерация случайного выстрела с последующей проверкой попадания/промаха.
														* Преследование в случае попадания, добивание.
														*/
bool ManualGunning(int** field, int cellule, int** ships);
