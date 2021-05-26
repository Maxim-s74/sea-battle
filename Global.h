#pragma once

#define fieldSize 12	/*Размер игрового поля
						(рамка в 1 элемент для упрощения проверки пространства вокруг выбранной ячейки)*/
#define TotalTonnageOfShips 25

//Milton Bradley version
#define Carrier 5		//Авианосец	>	Carrier
#define Battleship 4	//Линкор	>	Battleship
#define Cruiser 3		//Крейсер	>	Cruiser
#define Destroyer 2		//Эсминец	>	Destroyer
//Russian version (additive)
#define PatrolBoat 1	//Патрульный катер	>	PatrolBoat

//Состояние ячейки
#define	BLANK 0			//ПУСТО
#define CLOSED -1		//ЗАКРЫТО
#define WOUNDED 300		//РАНЕН
#define KILLED 200		//УБИТ
#define LOST -10		//ПОТЕРЯННЫЙ
#define EXCEPTION -15	//ИСКЛЮЧЕНИЕ

//Цвет ячейки
#define	BLACK 0
#define	BLUE 9
#define	GREEN 10
#define	CYAN 11
#define	RED 12
#define	YELLOW 14
#define	WHITE 15

struct question {
	bool gameMode;
	bool placement;
	bool level;
	question() : gameMode(false), placement(true), level(true) {};
};

extern int** ptrCPUField;
extern int** ptrUserField;
extern question setOfAnswers;
extern int fleet;
extern bool version;


