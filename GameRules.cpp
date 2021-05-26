#include "mainHeader.h"
#include <stdlib.h>

void GameRules() {
	cout << endl;
	CODEModify("\t\t\tПРАВИЛА ИГРЫ.\n");
	CODEModify("\tПеред началом игры каждый игрок тайно расставляет свои корабли на своей основной сетке.\n");
	CODEModify("Каждый корабль занимает ряд последовательных квадратов на сетке, расположенных либо\n");
	CODEModify("горизонтально, либо вертикально. Количество квадратов для каждого корабля определяется\n");
	CODEModify("типом корабля. Корабли не могут перекрываться (то есть только один корабль может занимать\n");
	CODEModify("любой заданный квадрат в сетке). Типы и количество разрешенных кораблей одинаковы для\n");
	CODEModify("каждого игрока. Они могут варьироваться в зависимости от правил.\n\n");

	cout << "\t" << char(201);		//	╔
	for (int i = 1; i < 13; i++) cout << char(205);	//	═
	cout << char(203);	//	╦
	for (int i = 1; i < 12; i++) cout << char(205);	//	═
	cout << char(203);	//	╦
	for (int i = 1; i < 24; i++) cout << char(205);	//	═
	cout << char(187) << endl;	//	╗

	cout << "\t" << char(186);	//	║
	for (int i = 1; i < 13; i++) cout << " ";
	cout << char(186);	//	║
	for (int i = 1; i < 12; i++) cout << " ";
	cout << char(186);	//	║
	CODEModify("  Количество кораблей  ");
	cout << char(186) << endl;	//	║

	cout << "\t" << char(186);	//	║
	CODEModify(" Количество ");
	cout << char(186);	//	║
	CODEModify("   Класс   ");
	cout << char(204);	// ╠
	for (int i = 1; i < 9; i++) cout << char(205);	//	═
	cout << char(203);	//	╦
	for (int i = 1; i < 15; i++) cout << char(205);	//	═
	cout << char(185) << endl;	//	╣

	cout << "\t" << char(186);	//	║
	CODEModify("    палуб   ");
	cout << char(186);	//	║
	CODEModify("  корабля  ");
	cout << char(186);	//	║
	CODEModify(" Милтон ");
	cout << char(186);	//	║
	CODEModify(" Общепринятые ");
	cout << char(186) << endl;	//	║

	cout << "\t" << char(186);	//	║
	for (int i = 1; i < 13; i++) cout << " ";
	cout << char(186);	//	║
	for (int i = 1; i < 12; i++) cout << " ";
	cout << char(186);	//	║
	CODEModify(" Брэдли ");
	cout << char(186);	//	║
	CODEModify("   правила    ");
	cout << char(186) << endl;	//	║

	cout << "\t" << char(186);	//	║
	for (int i = 1; i < 13; i++) cout << char(205);	//	═
	cout << char(186);	//	║
	for (int i = 1; i < 12; i++) cout << char(205);	//	═
	cout << char(186);	//	║
	for (int i = 1; i < 9; i++) cout << char(205);	//	═
	cout << char(186);	//	║
	for (int i = 1; i < 15; i++) cout << char(205);	//	═
	cout << char(186) << endl;	//	║

	cout << "\t" << char(186);	//	║
	CODEModify("      1     ");
	cout << char(186);	//	║
	CODEModify("   Катер   ");
	cout << char(186);	//	║
	CODEModify("    -   ");
	cout << char(186);	//	║
	CODEModify("       4      ");
	cout << char(186) << endl;	//	║

	cout << "\t" << char(186);	//	║
	for (int i = 1; i < 13; i++) cout << char(205);	//	═
	cout << char(186);	//	║
	for (int i = 1; i < 12; i++) cout << char(205);	//	═
	cout << char(186);	//	║
	for (int i = 1; i < 9; i++) cout << char(205);	//	═
	cout << char(186);	//	║
	for (int i = 1; i < 15; i++) cout << char(205);	//	═
	cout << char(186) << endl;	//	║

	cout << "\t" << char(186);	//	║
	CODEModify("      2     ");
	cout << char(186);	//	║
	CODEModify("  Эсминец  ");
	cout << char(186);	//	║
	CODEModify("    1   ");
	cout << char(186);	//	║
	CODEModify("       3      ");
	cout << char(186) << endl;	//	║

	cout << "\t" << char(186);	//	║
	for (int i = 1; i < 13; i++) cout << char(205);	//	═
	cout << char(186);	//	║
	for (int i = 1; i < 12; i++) cout << char(205);	//	═
	cout << char(186);	//	║
	for (int i = 1; i < 9; i++) cout << char(205);	//	═
	cout << char(186);	//	║
	for (int i = 1; i < 15; i++) cout << char(205);	//	═
	cout << char(186) << endl;	//	║

	cout << "\t" << char(186);	//	║
	CODEModify("      3     ");
	cout << char(186);	//	║
	CODEModify("  Крейсер  ");
	cout << char(186);	//	║
	CODEModify("    2   ");
	cout << char(186);	//	║
	CODEModify("       2      ");
	cout << char(186) << endl;	//	║

	cout << "\t" << char(186);	//	║
	for (int i = 1; i < 13; i++) cout << char(205);	//	═
	cout << char(186);	//	║
	for (int i = 1; i < 12; i++) cout << char(205);	//	═
	cout << char(186);	//	║
	for (int i = 1; i < 9; i++) cout << char(205);	//	═
	cout << char(186);	//	║
	for (int i = 1; i < 15; i++) cout << char(205);	//	═
	cout << char(186) << endl;	//	║

	cout << "\t" << char(186);	//	║
	CODEModify("      4     ");
	cout << char(186);	//	║
	CODEModify("  Линкор   ");
	cout << char(186);	//	║
	CODEModify("    1   ");
	cout << char(186);	//	║
	CODEModify("       1      ");
	cout << char(186) << endl;	//	║

	cout << "\t" << char(186);	//	║
	for (int i = 1; i < 13; i++) cout << char(205);	//	═
	cout << char(186);	//	║
	for (int i = 1; i < 12; i++) cout << char(205);	//	═
	cout << char(186);	//	║
	for (int i = 1; i < 9; i++) cout << char(205);	//	═
	cout << char(186);	//	║
	for (int i = 1; i < 15; i++) cout << char(205);	//	═
	cout << char(186) << endl;	//	║

	cout << "\t" << char(186);	//	║
	CODEModify("      5     ");
	cout << char(186);	//	║
	CODEModify(" Авианосец ");
	cout << char(186);	//	║
	CODEModify("    1   ");
	cout << char(186);	//	║
	CODEModify("       -      ");
	cout << char(186) << endl;	//	║

	cout << "\t" << char(200);	//	╚
	for (int i = 1; i < 13; i++) cout << char(205);	//	═
	cout << char(202);	//	╩
	for (int i = 1; i < 12; i++) cout << char(205);	//	═
	cout << char(202);	//	╩
	for (int i = 1; i < 9; i++) cout << char(205);	//	═
	cout << char(202);	//	╩
	for (int i = 1; i < 15; i++) cout << char(205);	//	═
	cout << char(188) << endl;	//	╝

	cout << "\n\n\n";

	setlocale(LC_ALL, ".866");
}