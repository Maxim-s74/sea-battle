#include "mainHeader.h"
#include "Global.h"
#include "BattleField.h"
#include "Processing.h"
#include "Menu.h"
#include "ConsoleControl.h"
#include "MessagesText.h"


void arrayInit(int array[][2], int rowSize) {
	for (int i = 0; i < rowSize; i++) {
		for (int j = 0; j < 2; j++)array[i][j] = 0;
	}
}

int main() {
	ConsoleReSize();
	setlocale(LC_ALL, "Russian");
	setlocale(LC_ALL, ".866");
	GameRules();

	char answer[5];

	int CPUField[fieldSize][fieldSize];
	int userField[fieldSize][fieldSize];

	int* pptrCPUField[fieldSize];
	int* pptrUserField[fieldSize];

	for (int i = 0; i < fieldSize; i++) {
		pptrCPUField[i] = CPUField[i];
		pptrUserField[i] = userField[i];
	}

	ptrCPUField = &pptrCPUField[0];
	ptrUserField = &pptrUserField[0];

	int CPUShips[TotalTonnageOfShips][2];	//координаты палуб корабля в форме
	int userShips[TotalTonnageOfShips][2];	//координаты палуб корабля в форме

	int* pCPUShips[TotalTonnageOfShips];
	int* pUserShips[TotalTonnageOfShips];

	for (int i = 0; i < TotalTonnageOfShips; i++) {
		pCPUShips[i] = CPUShips[i];
		pUserShips[i] = userShips[i];
	}

	int** ptrCPUShips = &pCPUShips[0];
	int** ptrUserShips = &pUserShips[0];

	bool newGame = false;

	do {
		do {
			newGame = false;
			int beginGamePosition = CursorCurrentPosition();
			CODEModify("\tБудете играть по правилам Милтона Брэдли?  (Да/Yes)/(Нет/No)\t");
			gets_s(answer);
			version = TextOfAnswers(&answer[0]);
			if (version)fleet = 5;
			else fleet = 10;

			StartMenu(setOfAnswers);

			srand(time(NULL));
			BattleFieldInit(ptrCPUField);
			BattleFieldInit(ptrUserField);

			arrayInit(CPUShips, TotalTonnageOfShips);
			arrayInit(userShips, TotalTonnageOfShips);

			BattleFieldCreate(ptrCPUField, ptrCPUShips);

			if (setOfAnswers.placement)BattleFieldCreate(ptrUserField, ptrUserShips);
			else {
				int beginManualCreation = CursorCurrentPosition();

				do {
					cout << "\n\n";
					BattleFieldManualCreation(ptrUserField, ptrUserShips);
					CODEModify("\tУдалить какой-либо корабль?  (Да/Yes)/(Нет/No)\t");
					gets_s(answer);
					bool erasure = TextOfAnswers(&answer[0]);

					while (erasure) erasure = ShipErasure(ptrUserField, ptrUserShips);

					if (NewGameStart()) {
						newGame = true;
						break;
					}
				} while (Muster(ptrUserShips) < fleet);

				ConsoleTextEraser(beginGamePosition);
				if (newGame)continue;
			}

			int beginCurrentGamePosition = CursorCurrentPosition();
			BattleFieldsShow(ptrCPUField, ptrUserField);

			do {

				if (setOfAnswers.gameMode) {
					bool hit = false;

					do {
						CODEModify("\tВаш выстрел. Введите координату\t");
						gets_s(answer);
						hit = ManualGunning(ptrCPUField, TextToNumber(answer), ptrCPUShips);
						BattleFieldsShow(ptrCPUField, ptrUserField);
						if (!(gameContin(ptrCPUShips) && gameContin(ptrUserShips))) break;
					} while (hit);
				}
				else Gunning(ptrCPUField, 0, ptrCPUShips);

				if (!(gameContin(ptrCPUShips) && gameContin(ptrUserShips)))break;
				Gunning(ptrUserField, 0, ptrUserShips);

				if (setOfAnswers.gameMode) {
					switch (ContextMenu()) {
					case 0:
						break;
					case 1:
						BattleFieldInit(ptrUserField);
						RangeClosure(ptrUserField, ptrUserShips);
						BattleFieldInit(ptrCPUField);
						RangeClosure(ptrCPUField, ptrCPUShips);
						ConsoleTextEraser(beginCurrentGamePosition);
						BattleFieldsShow(ptrCPUField, ptrUserField);
						break;
					case 2:
						CODEModify("\t\t\t\tВы позорно бежали\n");
						CODEModify("\t\t\t\tКОНЕЦ ИГРЫ\n");
						system("pause");
						return 0;
						break;
					case 3:
						newGame = true;
						ConsoleTextEraser(beginGamePosition);
						break;
					}
				}
			} while ((gameContin(ptrCPUShips) && gameContin(ptrUserShips)) && !newGame);
		} while (newGame);

		CODEModify("\t\t\t\tКОНЕЦ ИГРЫ\n");

		if (gameContin(ptrCPUShips)) {
			CODEModify("\t\t\t\tПобедил ");
			textcolor(BLUE);
			CODEModify("КОМПЬЮТЕР");
			textcolor(WHITE);
			CODEModify("!!!\n");
		}
		else if (setOfAnswers.gameMode) {
			textcolor(GREEN);
			CODEModify("\t\t\t\tВЫ победили!!!\n\t\t\t\t");
			textcolor(RED);
			CODEModify("ПОЗДРАВЛЯЕМ!!!\n");
			textcolor(WHITE);
		}
		else {
			CODEModify("\t\t\t\tПобедил ");
			textcolor(GREEN);
			CODEModify("ИСКУССТВЕННЫЙ ИНТЕЛЛЕКТ");
			textcolor(WHITE);
			CODEModify("!!!\n");
		}

		FinalShow(ptrCPUField, ptrUserField);
	} while ((bool)NewGameStart());

	return 0;
}