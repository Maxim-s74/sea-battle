#include "mainHeader.h"
#include "Global.h"
#include "BattleField.h"
#include "ConsoleControl.h"

// Âûâîä ïîëåé íà ıêğàí
void BattleFieldsShow(int** CPUField, int** userField) {
	cout << endl;
	cout << "                 ";
	textcolor(BLUE);
	CODEModify("ÊÎÌÏÜŞÒÅĞ");
	textcolor(WHITE);
	cout << "                 \t\t\t          ";
	textcolor(GREEN);
	if (setOfAnswers.gameMode)CODEModify("         ÈÃĞÎÊ\n");
	else CODEModify("ÈÑÊÓÑÑÒÂÅÍÍÛÉ ÈÍÒÅËËÅÊÒ\n");
	textcolor(WHITE);

	cout << "  | A | B | C | D | E | F | G | H | I | J |\t\t\t  | A | B | C | D | E | F | G | H | I | J |" << endl;

	cout << "  " << char(218);
	for (int i = 1; i < (fieldSize - 2); i++) cout << char(196) << char(196) << char(196) << char(194);
	cout << char(196) << char(196) << char(196) << char(191) << "\t\t\t";
	cout << "  " << char(218);
	for (int i = 1; i < (fieldSize - 2); i++) cout << char(196) << char(196) << char(196) << char(194);
	cout << char(196) << char(196) << char(196) << char(191) << endl;

	for (int i = 1; i < (fieldSize - 1); i++) {
		if (i == fieldSize - 2)cout << i;
		else cout << " " << i;

		for (int j = 1; j < (fieldSize - 1); j++) {
			cout << char(179);
			if (CPUField[i][j] >= PatrolBoat && CPUField[i][j] <= Carrier && !setOfAnswers.gameMode) {
				textcolor(BLUE);
				cout << char(178) << char(178) << char(178);
				textcolor(WHITE);
			}
			else if (CPUField[i][j] == KILLED) {
				textcolor(RED);
				cout << char(178) << char(178) << char(178);
				textcolor(WHITE);
			}
			else if (CPUField[i][j] == WOUNDED) {
				textcolor(YELLOW);
				cout << char(178) << char(178) << char(178);
				textcolor(WHITE);
			}
			else if (CPUField[i][j] == LOST) {
				textcolor(GREEN);
				cout << char(32) << char(88) << char(32);
				textcolor(WHITE);
			}
			else cout << "   ";
		}
		cout << char(179) << "\t\t\t";

		if (i == fieldSize - 2)cout << i;
		else cout << " " << i;

		for (int j = 1; j < (fieldSize - 1); j++) {
			cout << char(179);
			if (userField[i][j] >= PatrolBoat && userField[i][j] <= Carrier) {
				textcolor(GREEN);
				cout << char(178) << char(178) << char(178);
				textcolor(WHITE);
			}
			else if (userField[i][j] == KILLED) {
				textcolor(RED);
				cout << char(178) << char(178) << char(178);
				textcolor(WHITE);
			}
			else if (userField[i][j] == WOUNDED) {
				textcolor(YELLOW);
				cout << char(178) << char(178) << char(178);
				textcolor(WHITE);
			}
			else if (userField[i][j] == LOST) {
				textcolor(BLUE);
				cout << char(32) << char(88) << char(32);
				textcolor(WHITE);
			}
			else cout << "   ";
		}
		cout << char(179) << endl;

		if (i < (fieldSize - 2)) {
			cout << "  ";

			for (int j = 1; j < (fieldSize - 1); j++) {
				if (j == 1)cout << char(195);
				else cout << char(197);
				cout << char(196) << char(196) << char(196);
			}

			cout << char(180);
			cout << "\t\t\t  ";

			for (int j = 1; j < (fieldSize - 1); j++) {
				if (j == 1)cout << char(195);
				else cout << char(197);
				cout << char(196) << char(196) << char(196);
			}
			cout << char(180) << endl;
		}
	}

	cout << "  ";
	cout << char(192);
	for (int i = 1; i < (fieldSize - 2); i++) cout << char(196) << char(196) << char(196) << char(193);
	cout << char(196) << char(196) << char(196) << char(217) << "\t\t\t  ";
	cout << char(192);
	for (int i = 1; i < (fieldSize - 2); i++) cout << char(196) << char(196) << char(196) << char(193);
	cout << char(196) << char(196) << char(196) << char(217) << endl;

	cout << "\n\n";
	Sleep(1000);
}

void UserBattleFieldShow(int** field) {
	cout << endl;
	cout << "\t\t  | A | B | C | D | E | F | G | H | I | J |" << endl;

	cout << "\t\t  " << char(218);
	for (int i = 1; i < 10; i++) {
		cout << char(196) << char(196) << char(196);
		cout << char(194);
	}
	cout << char(196) << char(196) << char(196);
	cout << char(191) << endl;

	for (int i = 1; i < (fieldSize - 1); i++) {
		if (i == fieldSize - 2)cout << "\t\t" << i;
		else cout << "\t\t " << i;

		for (int j = 1; j < (fieldSize - 1); j++) {
			cout << char(179);
			if (field[i][j] >= PatrolBoat && field[i][j] <= Carrier) {
				textcolor(GREEN);
				cout << char(178) << char(178) << char(178);
				textcolor(WHITE);
			}
			else cout << "   ";
		}
		cout << char(179) << endl << "\t\t  ";

		if (i < (fieldSize - 2)) {
			for (int j = 1; j < (fieldSize - 1); j++) {
				if (j == 1)cout << char(195);
				else cout << char(197);
				cout << char(196) << char(196) << char(196);
			}
			cout << char(180) << endl;
		}
	}

	cout << char(192);
	for (int i = 1; i < (fieldSize - 2); i++) {
		cout << char(196) << char(196) << char(196);
		cout << char(193);
	}
	cout << char(196) << char(196) << char(196);
	cout << char(217) << endl;
}

void FinalShow(int** CPUField, int** userField) {
	cout << endl;
	cout << "                 ";
	textcolor(BLUE);
	CODEModify("ÊÎÌÏÜŞÒÅĞ");
	textcolor(WHITE);
	cout << "                 \t\t\t          ";
	textcolor(GREEN);
	if (setOfAnswers.gameMode)CODEModify("         ÈÃĞÎÊ\n");
	else CODEModify("ÈÑÊÓÑÑÒÂÅÍÍÛÉ ÈÍÒÅËËÅÊÒ\n");
	textcolor(WHITE);

	cout << "  | A | B | C | D | E | F | G | H | I | J |\t\t\t  | A | B | C | D | E | F | G | H | I | J |" << endl;

	cout << "  " << char(218);
	for (int i = 1; i < (fieldSize - 2); i++) cout << char(196) << char(196) << char(196) << char(194);
	cout << char(196) << char(196) << char(196) << char(191) << "\t\t\t";
	cout << "  " << char(218);
	for (int i = 1; i < (fieldSize - 2); i++) cout << char(196) << char(196) << char(196) << char(194);
	cout << char(196) << char(196) << char(196) << char(191) << endl;

	for (int i = 1; i < (fieldSize - 1); i++) {
		if (i == fieldSize - 2)cout << i;
		else cout << " " << i;

		for (int j = 1; j < (fieldSize - 1); j++) {
			cout << char(179);
			if (CPUField[i][j] >= PatrolBoat && CPUField[i][j] <= 4) {
				textcolor(BLUE);
				cout << char(178) << char(178) << char(178);
				textcolor(WHITE);
			}
			else if (CPUField[i][j] == KILLED) {
				textcolor(RED);
				cout << char(178) << char(178) << char(178);
				textcolor(WHITE);
			}
			else if (CPUField[i][j] == WOUNDED) {
				textcolor(YELLOW);
				cout << char(178) << char(178) << char(178);
				textcolor(WHITE);
			}
			else if (CPUField[i][j] == LOST) {
				textcolor(GREEN);
				cout << char(32) << char(88) << char(32);
				textcolor(WHITE);
			}
			else cout << "   ";
		}
		cout << char(179) << "\t\t\t";

		if (i == fieldSize - 2)cout << i;
		else cout << " " << i;

		for (int j = 1; j < (fieldSize - 1); j++) {
			cout << char(179);
			if (userField[i][j] >= PatrolBoat && userField[i][j] <= Carrier) {
				textcolor(GREEN);
				cout << char(178) << char(178) << char(178);
				textcolor(WHITE);
			}
			else if (userField[i][j] == KILLED) {
				textcolor(RED);
				cout << char(178) << char(178) << char(178);
				textcolor(WHITE);
			}
			else if (userField[i][j] == WOUNDED) {
				textcolor(YELLOW);
				cout << char(178) << char(178) << char(178);
				textcolor(WHITE);
			}
			else if (userField[i][j] == LOST) {
				textcolor(BLUE);
				cout << char(32) << char(88) << char(32);
				textcolor(WHITE);
			}
			else cout << "   ";
		}
		cout << char(179) << endl;

		if (i < (fieldSize - 2)) {
			cout << "  ";

			for (int j = 1; j < (fieldSize - 1); j++) {
				if (j == 1)cout << char(195);
				else cout << char(197);
				cout << char(196) << char(196) << char(196);
			}

			cout << char(180);
			cout << "\t\t\t  ";

			for (int j = 1; j < (fieldSize - 1); j++) {
				if (j == 1)cout << char(195);
				else cout << char(197);
				cout << char(196) << char(196) << char(196);
			}
			cout << char(180) << endl;
		}
	}

	cout << "  ";
	cout << char(192);
	for (int i = 1; i < (fieldSize - 2); i++) cout << char(196) << char(196) << char(196) << char(193);
	cout << char(196) << char(196) << char(196) << char(217) << "\t\t\t  ";
	cout << char(192);
	for (int i = 1; i < (fieldSize - 2); i++) cout << char(196) << char(196) << char(196) << char(193);
	cout << char(196) << char(196) << char(196) << char(217) << endl;

	cout << "\n\n";
}

