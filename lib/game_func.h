#ifndef SCRABBLE_GAME_FUNC_H
#define SCRABBLE_GAME_FUNC_H

using namespace std;

#include "../dictionary/dictionary.h"
#include "additional_func.h"
#include "misc_func.h"

struct player
{
	int id;

	letters *list;
	int passTime;

	int score;
};

void DisplayPlayground(string **playground, int **area, int n = 15);
void RandLetter(letters *&listHead, letters *&letterHead);
void GiveHand(player &p, letters *&letterHead);
void OutputHand(player *p);
void InputWord(letters *listHead, string &word);
void MakeMove(string **playground, int **area, letters *&listHead, dictionary *dictHead, player *&p, player *&q);
int CheckDirection(int len, int x, int y, string direction);
int PullWord(dictionary *head, string **playground, int **area, int x, int y, string direction, string word,
        int dscore);
void ChangePlayer(player *&active, player *&passive, player *first, player *second);
void SwapHand(player *&active, letters *&letterList, string swap);
int CheckVoid(string **arr, int y, int x);
int VerticalCheck(dictionary *head, string **arr, string direction, int y, int x);
int HorizontalCheck(dictionary *head, string **arr, string direction, int y, int x);

#endif //SCRABBLE_GAME_FUNC_H
