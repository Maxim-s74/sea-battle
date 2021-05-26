#include "mainHeader.h"
#include "Global.h"
#include <stdlib.h>
#include "ConsoleControl.h"
#include "MessagesText.h"

void StartMenu(question& setOfAnswers) {
	char answer[5];
	CODEModify("\t������� ������� �����? (��/Yes)/(���/No)\t");	//������ ����: (������� � ���������)/(��������� � ���������)
	gets_s(answer);
	setOfAnswers.gameMode = TextOfAnswers(&answer[0]);

	if (setOfAnswers.gameMode) {
		CODEModify("\t�������� ����������� ������� �������������� ���������? (��/Yes)/(���/No)\t");	//����������� ��������: (��������� ����������� �� ������)/(����� ����������� �������)
		gets_s(answer);
		setOfAnswers.placement = TextOfAnswers(&answer[0]);
		CODEModify("\t������� ��������� � ������� ���������? (��/Yes)/(���/No)\t");	// (���������������� ����)/(��������� �������)
		gets_s(answer);
		setOfAnswers.level = TextOfAnswers(&answer[0]);
	}
	else {
		CODEModify("\n\t\t������ ���������������� ����!\n");
		setOfAnswers.placement = true;
		setOfAnswers.level = true;
	}
}

bool NewGameStart() {
	char answer[5];
	CODEModify("\t������ ����� ����? (��/Yes)/(���/No)\t");
	gets_s(answer);
	return TextOfAnswers(&answer[0]);
}

bool ReStartGame() {
	char answer[5];
	CODEModify("\t������ ���� ������? (��/Yes)/(���/No)\t");
	gets_s(answer);
	return TextOfAnswers(&answer[0]);
}

bool Capitulation() {
	CursorUp();
	char answer[5];
	CODEModify("\t������� �������? (��/Yes)/(���/No)\t");
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
