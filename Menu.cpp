#include "mainHeader.h"
#include "Global.h"
#include <stdlib.h>
#include "ConsoleControl.h"
#include "MessagesText.h"

void StartMenu(question& setOfAnswers) {
	char answer[5];
	CODEModify("\tЖелаете сыграть лично? (Да/Yes)/(Нет/No)\t");	//Режимы игры: (Человек – компьютер)/(Компьютер – компьютер)
	gets_s(answer);
	setOfAnswers.gameMode = TextOfAnswers(&answer[0]);

	if (setOfAnswers.gameMode) {
		CODEModify("\tДоверите расстановку эскадры Искусственному Интелекту? (Да/Yes)/(Нет/No)\t");	//Расстановка кораблей: (Компьютер расставляет за игрока)/(Игрок расставляет вручную)
		gets_s(answer);
		setOfAnswers.placement = TextOfAnswers(&answer[0]);
		CODEModify("\tЖелаете сразиться с опытным адмиралом? (Да/Yes)/(Нет/No)\t");	// (Интеллектуальная игра)/(Случайный выстрел)
		gets_s(answer);
		setOfAnswers.level = TextOfAnswers(&answer[0]);
	}
	else {
		CODEModify("\n\t\tЗапуск демонстрационной игры!\n");
		setOfAnswers.placement = true;
		setOfAnswers.level = true;
	}
}

bool NewGameStart() {
	char answer[5];
	CODEModify("\tНачать новую игру? (Да/Yes)/(Нет/No)\t");
	gets_s(answer);
	return TextOfAnswers(&answer[0]);
}

bool ReStartGame() {
	char answer[5];
	CODEModify("\tНачать игру заново? (Да/Yes)/(Нет/No)\t");
	gets_s(answer);
	return TextOfAnswers(&answer[0]);
}

bool Capitulation() {
	CursorUp();
	char answer[5];
	CODEModify("\tЖелаете сдаться? (Да/Yes)/(Нет/No)\t");
	gets_s(answer);
	return TextOfAnswers(&answer[0]);
}

int ContextMenu() {
	if (Capitulation()) {
		if (ReStartGame()) return 1;
		else return (int)NewGameStart() + 2;
	}
	else return 0;
}
