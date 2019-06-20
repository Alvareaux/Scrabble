#ifndef SCRABBLE_ADDITIONAL_FUNC_H
#define SCRABBLE_ADDITIONAL_FUNC_H

#include <string>
#include "../dictionary/dictionary.h"

using namespace std;

void DeleteLetter(letters *&head, string x);
void LettersOutput(letters *head);
int ListCounter(letters *head);

int Check(letters *head, string word);
int Check(dictionary *head, string word);

#endif //SCRABBLE_ADDITIONAL_FUNC_H
