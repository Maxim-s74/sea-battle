#include "mainHeader.h"
#include "Global.h"
#include "Processing.h"
#include "BattleField.h"
#include "MessagesText.h"

//сканирование вокруг подбитой палубы в случае ранения
int scanning(int** field, int cXcY, int& direction) {
	//cXcY	- координата подбитой палубы корабля в форме (Row * fieldSize + Column)
	int steps[4] = { -fieldSize, -1, fieldSize, 1 };

	if (direction == -1 * fieldSize * fieldSize) {
		for (int i = 0; i < 4; i++) {
			if (field[(cXcY + steps[i]) / fieldSize][(cXcY + steps[i]) % fieldSize] == WOUNDED) {
				direction = steps[i];
				break;
			}
		}
	}

	if (direction != -1 * fieldSize * fieldSize) {
		if (field[(cXcY + direction) / fieldSize][(cXcY + direction) % fieldSize] > LOST &&
			field[(cXcY + direction) / fieldSize][(cXcY + direction) % fieldSize] < KILLED) return cXcY + direction;
		else if (field[(cXcY + direction) / fieldSize][(cXcY + direction) % fieldSize] == WOUNDED) {
			scanning(field, (cXcY + direction), direction);
		}
		else if (field[(cXcY + direction) / fieldSize][(cXcY + direction) % fieldSize] <= LOST) {
			direction = -direction;
			scanning(field, (cXcY + direction), direction);
		}
	}
	else {
		for (int i = 0; i < 4; i++) {
			if (field[(cXcY + steps[i]) / fieldSize][(cXcY + steps[i]) % fieldSize] > LOST &&
				field[(cXcY + steps[i]) / fieldSize][(cXcY + steps[i]) % fieldSize] < KILLED) {
				direction = steps[i];
				return cXcY + direction;	//возврат координаты, куда можно бить
			}
		}
	}
}

void Gunning(int** field, int cellule, int** ships) {
	int correction = 0;
	int direction = -1 * fieldSize * fieldSize;
	int targetHit = BLANK;

	if (cellule == 0 && (!setOfAnswers.gameMode || setOfAnswers.level)) {
		for (int i = 0; i < fieldSize * fieldSize; i++) {
			if (field[i / fieldSize][i % fieldSize] == WOUNDED) {
				cellule = scanning(field, i, direction);
				break;
			}
		}
	}

	if (cellule == 0) {
		do {
			cellule = rand() % (fieldSize * fieldSize);	//координаты выстрела в форме (Row * fieldSize + Column)
		} while (field[cellule / fieldSize][cellule % fieldSize] <= LOST || field[cellule / fieldSize][cellule % fieldSize] >= KILLED);
	}

	AddressShow(cellule, field);
	targetHit = Response(cellule, field, ships);

	switch (targetHit) {
	case KILLED:		// убил, следующий ход.
		field[cellule / fieldSize][cellule % fieldSize] = KILLED;
		ExcludingCells(field);
		cellule = 0;
		BattleFieldsShow(ptrCPUField, ptrUserField);
		if (gameContin(ships)) Gunning(field, cellule, ships);
		break;
	case WOUNDED:		// ранил, следующий ход.
		field[cellule / fieldSize][cellule % fieldSize] = WOUNDED;
		if (setOfAnswers.level || !setOfAnswers.gameMode)correction = scanning(field, cellule, direction);
		BattleFieldsShow(ptrCPUField, ptrUserField);
		Gunning(field, correction, ships);
		break;
	default:	//промах (переход хода)
		field[cellule / fieldSize][cellule % fieldSize] = LOST;
		BattleFieldsShow(ptrCPUField, ptrUserField);
		break;
	}
}

bool ManualGunning(int** field, int cellule, int** ships) {
	AddressShow(cellule, field);
	int targetHit = Response(cellule, field, ships);

	switch (targetHit) {
	case KILLED:		// убил, следующий ход.
		field[cellule / fieldSize][cellule % fieldSize] = KILLED;
		return true;
	case WOUNDED:		// ранил, следующий ход.
		field[cellule / fieldSize][cellule % fieldSize] = WOUNDED;
		return true;
	default:	//промах (переход хода)
		field[cellule / fieldSize][cellule % fieldSize] = LOST;
		return false;
	}
}

int Response(int cellule, int** field, int** ships) {
	if (field[cellule / fieldSize][cellule % fieldSize] >= PatrolBoat && field[cellule / fieldSize][cellule % fieldSize] <= Carrier) {		// ранил, следующий ход.
		CODEModify("Ранил.\n");
		int deck = LocationSearch(ships, cellule);
		int leftBound = deck;
		int rightBound = deck + 1;
		BoundsSearch(deck, leftBound, rightBound);
		return CheckingCellStatus(field, ships, leftBound, rightBound, deck);
	}
	else {
		CODEModify("Промах.\n");
		CODEModify("Переход хода.\n");
		return LOST;
	}
	return LOST;
}

bool gameContin(int** ships) {
	int leftBound = 0;
	int rightBound = TotalTonnageOfShips;

	if (version) leftBound = PatrolBoat * 4 + Destroyer * 2;
	else rightBound = TotalTonnageOfShips - Carrier;

	for (int i = leftBound; i < rightBound; i++) { if (ships[i][0] == 0)return true; }
	return false;
}

int CheckingCellStatus(int** field, int** ships, int leftBound, int rightBound, int deck) {
	for (int i = leftBound; i < rightBound; i++)
		if (ships[i][0] == 0 && i != deck) {
			ships[deck][0] = WOUNDED;
			return WOUNDED;
		}
	for (int i = leftBound; i < rightBound; i++) {
		ships[i][0] = KILLED;
		field[ships[i][1] / fieldSize][ships[i][1] % fieldSize] = KILLED;
	}
	CODEModify("Убил.\n");
	return KILLED;
}