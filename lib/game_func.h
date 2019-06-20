#ifndef SCRABBLE_GAME_FUNC_H
#define SCRABBLE_GAME_FUNC_H

using namespace std;

#include "../dictionary/dictionary.h"
#include "additional_func.h"
#include "../main.cpp"

void DisplayPlayground(string **playground, int **area, int n = 15);
void RandLetter(letters *&listHead, letters *&letterHead);
void InputWord(letters *listHead, string &word);
void MakeMove(string **playground, int **area, letters *&listHead, dictionary *dictHead, player &p);
int CheckDirection(int len, int x, int y, string direction);
int PullWord(string **playground, int **area, int x, int y, string direction, string word);

#endif //SCRABBLE_GAME_FUNC_H