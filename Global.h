#pragma once

#define fieldSize 12	/*������ �������� ����
						(����� � 1 ������� ��� ��������� �������� ������������ ������ ��������� ������)*/
#define TotalTonnageOfShips 25

//Milton Bradley version
#define Carrier 5		//���������	>	Carrier
#define Battleship 4	//������	>	Battleship
#define Cruiser 3		//�������	>	Cruiser
#define Destroyer 2		//�������	>	Destroyer
//Russian version (additive)
#define PatrolBoat 1	//���������� �����	>	PatrolBoat

//��������� ������
#define	BLANK 0			//�����
#define CLOSED -1		//�������
#define WOUNDED 300		//�����
#define KILLED 200		//����
#define LOST -10		//����������
#define EXCEPTION -15	//����������

//���� ������
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


