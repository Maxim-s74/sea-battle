#pragma once
#include "mainHeader.h"
#include "Global.h"

int LocationSearch(int** ships, int cellule);
void BoundsSearch(int deck, int& leftBound, int& rightBound);
void BattleFieldInit(int** field);
int Muster(int** ships);						//������� ���������� ��������
void RangeClosure(int** field, int** ships);	 //�������� ���������� � ������� ������, � ������, ������� �������, ������ ���������� �����
bool ShipErasure(int** field, int** ships);
void BattleFieldCreate(int** field,int** ships);
void BattleFieldsShow(int** CPUField, int** userField);
void ExcludingCells(int** field);
bool BattleFieldManualCreation(int** field, int** ships);
void UserBattleFieldShow(int** field);
void FinalShow(int** CPUField, int** userField);
