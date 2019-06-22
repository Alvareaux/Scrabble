#include <iostream>
#include <string>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <fstream>
#include <vector>

#include "dictionary/dictionary.h"
#include "lib/misc_func.h"
#include "lib/game_func.h"
#include "lib/additional_func.h"

using namespace std;
const int N = 15;

struct wordList
{
    string word;
    int score;

    wordList *next;
};

void PushToWList(wordList *&head, string word);
void GenWords(string letters);


int main()
{
    string letters;
    cout << "SCRABBLE WORD FINDER" << endl;
    cout << "Game by Anatolii Voitko and Ihor Nekhaienko" << endl;
    cout << "https://github.com/Alvareaux/Scrabble" << endl;
    cout << "\t[TP-82]" << endl;

    cout << "\t\nLoading...\n" << endl;

    dictionary *dictHead = NULL;
    fin(dictHead);

    do
    {
        cout << "\nEnter your letters: ";
        cin >> letters;
    }
    while (letters.size() >= 7);

    GenWords(letters);

    system("pause");
    return 0;
}

void PushToWList(wordList *&head, string word)
{
    int i;
    int score;
    string temp;
    wordList *p = new wordList;
    wordList *q;

    for (i = 0; i < word.size(); i++)
    {
        p -> word += toupper(word[i]);
        temp = toupper(word[i]);
        score = LetterScore(temp);
    }

    p -> score = score;
    p -> next = NULL;

    if (!head)
    {
        head = p;
        return;
    }

    q = head;
    while (q -> next)
    {
        q = q -> next;
    }
    q -> next = p;
}

void GenWords(string letters)
{
    return;
}

