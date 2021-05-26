#include "mainHeader.h"
#include "Global.h"
#include "BattleField.h"
#include "ConsoleControl.h"
#include "MessagesText.h"

void BattleFieldInit(int** field) {
	for (int i = 0; i < fieldSize; i++) {
		for (int j = 0; j < fieldSize; j++) {
			if (i == 0 or i == (fieldSize - 1) or j == 0 or j == (fieldSize - 1))
				field[i][j] = LOST;
			else field[i][j] = BLANK;
		}
	}
}

int LocationSearch(int** ships, int cellule) {
	for (int i = 0; i < TotalTonnageOfShips; i++) {
		if (cellule == ships[i][1]) {
			return i;
		}
	}

	return 0;
}

int Muster(int** ships) {
	int rollCall = 0;
	if (ships[0][1] > 0) rollCall++;	//PatrolBoat
	if (ships[1][1] > 0) rollCall++;	//PatrolBoat
	if (ships[2][1] > 0) rollCall++;	//PatrolBoat
	if (ships[3][1] > 0) rollCall++;	//PatrolBoat
	if (ships[4][1] > 0) rollCall++;	//Destroyer
	if (ships[6][1] > 0) rollCall++;	//Destroyer
	if (ships[8][1] > 0) rollCall++;	//Destroyer
	if (ships[10][1] > 0) rollCall++;	//Cruiser
	if (ships[13][1] > 0) rollCall++;	//Cruiser
	if (ships[16][1] > 0) rollCall++;	//Battleship
	if (ships[20][1] > 0) rollCall++;	//Carrier
	return rollCall;
}

void BoundsSearch(int deck, int& leftBound, int& rightBound) {
	if (deck >= PatrolBoat * 4 + Destroyer * 3 + Cruiser * 2 + Battleship) {
		leftBound = PatrolBoat * 4 + Destroyer * 3 + Cruiser * 2 + Battleship;
		rightBound = PatrolBoat * 4 + Destroyer * 3 + Cruiser * 2 + Battleship + Carrier;
	}
	else if (deck >= PatrolBoat * 4 + Destroyer * 3 + Cruiser * 2) {
		leftBound = PatrolBoat * 4 + Destroyer * 3 + Cruiser * 2;
		rightBound = PatrolBoat * 4 + Destroyer * 3 + Cruiser * 2 + Battleship;
	}
	else if (deck >= PatrolBoat * 4 + Destroyer * 3 + Cruiser) {
		leftBound = PatrolBoat * 4 + Destroyer * 3 + Cruiser;
		rightBound = PatrolBoat * 4 + Destroyer * 3 + Cruiser * 2;
	}
	else if (deck >= PatrolBoat * 4 + Destroyer * 3) {
		leftBound = PatrolBoat * 4 + Destroyer * 3;
		rightBound = PatrolBoat * 4 + Destroyer * 3 + Cruiser;
	}
	else if (deck >= PatrolBoat * 4 + Destroyer * 2) {
		leftBound = PatrolBoat * 4 + Destroyer * 2;
		rightBound = PatrolBoat * 4 + Destroyer * 3;
	}
	else if (deck >= PatrolBoat * 4 + Destroyer) {
		leftBound = PatrolBoat * 4 + Destroyer;
		rightBound = PatrolBoat * 4 + Destroyer * 2;
	}
	else if (deck >= PatrolBoat * 4) {
		leftBound = PatrolBoat * 4;
		rightBound = PatrolBoat * 4 + Destroyer;
	}
}

bool ShipErasure(int** field, int** ships) {
	UserBattleFieldShow(field);
	CODEModify("\tУкажите координату палубы удаляемого корабля:\t");
	char cXcY[5];
	char answer[5];
	gets_s(cXcY);
	int cellule = TextToNumber(cXcY);

	if (field[cellule / fieldSize][cellule % fieldSize] >= PatrolBoat && field[cellule / fieldSize][cellule % fieldSize] <= Carrier) {
		int deck = LocationSearch(ships, cellule);
		int leftBound = deck;
		int rightBound = deck + 1;
		BoundsSearch(deck, leftBound, rightBound);
		for (int i = leftBound; i < rightBound; i++)ships[i][1] = 0;
		BattleFieldInit(field);
		RangeClosure(field, ships);
		UserBattleFieldShow(field);
		CODEModify("\tПродолжить удаление? (Да/Yes)/(Нет/No)\t");
		gets_s(answer);
		if (TextOfAnswers(&answer[0]))return true;
		else return false;
	}
	else {
		CODEModify("\tВы ввели неправильный адрес палубы.\n\tПопробовать ещё раз? (Да/Yes)/(Нет/No)\t");
		gets_s(answer);
		if (TextOfAnswers(&answer[0]))return true;
		else return false;
	}
}

bool BattleFieldManualCreation(int** field, int** ships) {
	UserBattleFieldShow(field);
	CODEModify("\tРасставьте корабли на поле\n");

	int direct, ship;
	int shipX, shipY;
	int X, Y;
	int deck = TotalTonnageOfShips;
	int arrow;
	char cXcY[5];
	char answer[5];
	bool ifENGAGED = true;

	while (Muster(ships) < fleet) {
		for (;;) {
			deck = TotalTonnageOfShips;
			CODEModify("\tПрервать расстановку? (Да/Yes)/(Нет/No)\t");
			gets_s(answer);
			if (TextOfAnswers(&answer[0]))return false;

			do {
				CODEModify("\tВведите количество палуб\t");
				gets_s(answer);
				ship = atoi(answer);
			} while (IfIncorrectInput(ship, PatrolBoat, Carrier));

			int rightBound = TotalTonnageOfShips - 1;
			int leftBound = 0;

			switch (ship) {
			case Carrier:
				if (version) leftBound = rightBound + 1 - Carrier;
				else {
					CODEModify("\tПятипалубный корабль не предусмотрен правилами!\nВведите другую палубность!\n");
					continue;
				}
				break;
			case Battleship:
				rightBound = rightBound - Carrier;
				leftBound = rightBound + 1 - Battleship;
				break;
			case Cruiser:
				rightBound = rightBound - Carrier - Battleship;
				leftBound = rightBound + 1 - Cruiser * 2;
				break;
			case Destroyer:
				rightBound = rightBound - Carrier - Battleship - Cruiser * 2;
				leftBound = rightBound + 1 - Destroyer * (1 + (int)(!version) * 2);
				break;
			case PatrolBoat:
				if (version) {
					CODEModify("\tОднопалубный корабль не предусмотрен правилами!\nВведите другую палубность!\n");
					continue;
				}
				else rightBound = PatrolBoat * 4 - 1;
				break;
			}

			for (int i = rightBound; i >= leftBound; i--) {	//проверяем палубы кораблей
				if (ships[i][1] == 0) {
					deck = i;
					break;
				}
			}

			if (deck == TotalTonnageOfShips) {
				if (ship == 5)CODEModify("\tПятипалубный корабль уже поставлен!\nВведите другую палубность!\n");
				else if (ship == 4)CODEModify("\tЧетырёхпалубный корабль уже поставлен!\nВведите другую палубность!\n");
				else if (ship == 3)CODEModify("\tТрёхпалубные корабли уже все поставлены!\nВведите другую палубность!\n");
				else if (ship == 2)CODEModify("\tДвухпалубные корабли уже все поставлены!\nВведите другую палубность!\n");
				else if (ship == 1)CODEModify("\tОднопалубные корабли уже все поставлены!\nВведите другую палубность!\n");
			}
			else break;
		}

		do {
			CODEModify("\tВведите координату ячейки носа корабля\t");
			gets_s(cXcY);
			shipX = TextToNumber(cXcY) / fieldSize;
			shipY = TextToNumber(cXcY) % fieldSize;

			if (ship == PatrolBoat) {
				direct = 0;
			}
			else {
				CODEModify("\tУкажите стрелкой на клавиатуре направление построения корабля \t");
				arrow = _getch();
				arrow = _getch();
				direct = ArrowDirection(arrow);
			}

			ifENGAGED = false;

			// Проверка попадания корабля на занятые ячейки
			for (int l = 0; l < ship; l++) {	//Перебираем палубы корабля
				switch (direct) {
				case 0:
					X = shipX - l;
					Y = shipY;
					break;
				case 1:
					X = shipX + l;
					Y = shipY;
					break;
				case 2:
					X = shipX;
					Y = shipY - l;
					break;
				case 3:
					X = shipX;
					Y = shipY + l;
					break;
				}

				if (!ifENGAGED)ifENGAGED = (bool)field[X][Y];
			}
			if (ifENGAGED)CODEModify("\tНелзя разместить корабль.\n\tПопробуйте ещё раз.\n");
		} while (ifENGAGED);

		// Размещение корабля на поле, очерчивание границ
		int begin;	//Закрепляемая координата палубы на поле
		int cX, cY;	//Координата палубы на поле

		switch (direct) {
		case 0:
		case 1:
			begin = shipX;
			break;
		case 2:
		case 3:
			begin = shipY;
			break;
		}

		int stern = begin - (ship - 1) * (int)pow(-1, direct);

		for (int j = min(begin, stern); j <= max(begin, stern); j++) {	//Перебираем палубы корабля
			switch (direct) {
			case 0:
			case 1:
				cX = j;
				cY = shipY;
				break;
			case 2:
			case 3:
				cX = shipX;
				cY = j;
				break;
			}

			ships[deck--][1] = cX * fieldSize + cY;	//записываем координаты палуб кораблей
			BattleFieldInit(field);
			RangeClosure(field, ships);
		}

		UserBattleFieldShow(field);
	}

	return true;
}

void RangeClosure(int** field, int** ships) {
	for (int i = 0; i < TotalTonnageOfShips; i++) {
		if (ships[i][1] != 0) {
			for (int j = -1; j < 2; j++) {		//запираем граничащие с кораблём ячейки
				for (int k = -1; k < 2; k++) {
					if (field[ships[i][1] / fieldSize + j][ships[i][1] % fieldSize + k] == BLANK)
						field[ships[i][1] / fieldSize + j][ships[i][1] % fieldSize + k] = CLOSED;
				}
			}

			if (i < PatrolBoat * 4) field[ships[i][1] / fieldSize][ships[i][1] % fieldSize] = PatrolBoat;
			else if (i < PatrolBoat * 4 + Destroyer * 3) field[ships[i][1] / fieldSize][ships[i][1] % fieldSize] = Destroyer;
			else if (i < PatrolBoat * 4 + Destroyer * 3 + Cruiser * 2) field[ships[i][1] / fieldSize][ships[i][1] % fieldSize] = Cruiser;
			else if (i < PatrolBoat * 4 + Destroyer * 3 + Cruiser * 2 + Battleship) field[ships[i][1] / fieldSize][ships[i][1] % fieldSize] = Battleship;
			else field[ships[i][1] / fieldSize][ships[i][1] % fieldSize] = Carrier;

		}
	}
}


void ExcludingCells(int** field) {
	for (int i = 0; i < fieldSize; i++) {
		for (int j = 0; j < fieldSize; j++) {
			if (field[i][j] == KILLED) {
				for (int k = -1; k < 2; k++) {		//запираем граничащие с кораблём ячейки
					for (int l = -1; l < 2; l++) {
						if (field[i + k][j + l] != LOST && field[i + k][j + l] != KILLED)field[i + k][j + l] = EXCEPTION;
					}
				}
			}
		}
	}
}

void BattleFieldCreate(int** field, int** ships) {
	int direct, ship;
	int shipX, shipY;
	int X, Y;
	bool ifENGAGED;
	int deck = TotalTonnageOfShips;
	if (!version)deck -= Carrier;

	for (int i = 0; i < fleet; i++) {
		switch (i + (int)(!version)) {
		case 0:
			ship = Carrier;
			break;
		case 1:
			ship = Battleship;
			break;
		case 2:
		case 3:
			ship = Cruiser;
			break;
		case 4:
		case 5:
		case 6:
			ship = Destroyer;
			break;
		default:
			ship = PatrolBoat;
		}

		do {
			direct = rand() % 2; // Направление расположения корабля
			// Генерация координаты начала корабля
			shipX = rand() % (fieldSize - 2) + 1;
			shipY = rand() % (fieldSize - 2) + 1;

			ifENGAGED = false;
			// Проверка попадания корабля на занятые ячейки
			for (int l = 0; l < ship; l++) {	//Перебираем палубы корабля
				if (direct) {	//выбор горизонтального направления
					X = shipX;
					Y = shipY + l;
				}
				else {			//выбор вертикального направления
					X = shipX + l;
					Y = shipY;
				}

				if (!ifENGAGED)ifENGAGED = (bool)field[X][Y];
			}
		} while (ifENGAGED);

		// Размещение корабля на поле, очерчивание границ
		int begin;	//Закрепляемая координата палубы на поле
		int cX, cY;	//Координата палубы на поле

		if (direct) begin = shipY;
		else begin = shipX;

		for (int j = begin; j < begin + ship; j++) {	//Перебираем палубы корабля
			if (direct) {
				cX = shipX;
				cY = j;
			}
			else {
				cX = j;
				cY = shipY;
			}

			ships[--deck][1] = cX * fieldSize + cY;	//записываем координаты палуб кораблей
			BattleFieldInit(field);
			RangeClosure(field, ships);
		}
	}
}