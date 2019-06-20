#ifndef SCRABBLE_DICTIONARY_H
#define SCRABBLE_DICTIONARY_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

struct dictionary
{
	string word;
	string mean;
	dictionary *next;
};

struct letters
{
	string word;
	int factor;
	letters *next;
};


void fin(dictionary *&);
void PushToDict(dictionary *&head, string temp);
void fin(letters *&);
void PushToLetters(letters *&head, string word, int n);
int LetterScore(string letter);

#endif //SCRABBLE_DICTIONARY_H
