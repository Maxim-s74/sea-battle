#pragma once
#include "mainHeader.h"
#include "Global.h"

int LocationSearch(int** ships, int cellule);
void BoundsSearch(int deck, int& leftBound, int& rightBound);
void BattleFieldInit(int** field);
int Muster(int** ships);						//ѕодсчЄт количества кораблей
void RangeClosure(int** field, int** ships);	 //запираем граничащие с кораблЄм €чейки, в €чейку, зан€тую кораблЄм, ставим количество палуб
bool ShipErasure(int** field, int** ships);
void BattleFieldCreate(int** field,int** ships);
void BattleFieldsShow(int** CPUField, int** userField);
void ExcludingCells(int** field);
bool BattleFieldManualCreation(int** field, int** ships);
void UserBattleFieldShow(int** field);
void FinalShow(int** CPUField, int** userField);
