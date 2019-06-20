#include <fstream>
#include <iostream>
#include <string>
#include <Windows.h>

#include "game_func.h"
#include "../dictionary/dictionary.h"
#include "additional_func.h"
#include "../main.cpp"

using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
const int RANDNUM = 666;

void DisplayPlayground(string **playground, int **area, int n)
{
    cout << "\t\t    -";
    for (int i = 0; i < n; i++)
    {
        cout << "----";
    }
    cout << endl;


    cout << "\t\t    | ";
    for (int i = 0; i < n; i++)
    {
        if (i < 10)
        {
            SetConsoleTextAttribute(hConsole, 2);
            cout << "" << i;
            SetConsoleTextAttribute(hConsole, 7);
            cout << " |";
        }
        else
        {
            SetConsoleTextAttribute(hConsole, 2);
            cout << i;
            SetConsoleTextAttribute(hConsole, 7);
            cout << "|";
        }

        cout << " ";
    }
    cout << endl;

    cout << "\t\t-";
    for (int i = 0; i < n + 1; i++)
    {
        cout << "----";
    }
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        if (i < 10)
        {
            cout << "\t\t| ";
            SetConsoleTextAttribute(hConsole, 2);
            cout << i;
            SetConsoleTextAttribute(hConsole, 7);
            cout << " | ";
        }
        else
        {
            cout << "\t\t| ";
            SetConsoleTextAttribute(hConsole, 2);
            cout << i;
            SetConsoleTextAttribute(hConsole, 7);
            cout << "| ";
        }

        for (int j = 0; j < n; j++)
        {
            if ((*(*(playground + i) + j)).empty())
            {
                if (*(*(area + i) + j) == 1)
                {
                    cout << "  |";
                }
                else
                {
                    if (*(*(area + i) + j) < 0)
                    {
                        SetConsoleTextAttribute(hConsole, 1);
                        cout << -(*(*(area + i) + j));
                        SetConsoleTextAttribute(hConsole, 7);
                        cout << " |";
                    }
                    else
                    {
                        cout << (*(*(area + i) + j)) << " |";
                    }
                }
            }
            else
            {
                cout << *(*(playground + i) + j);
            }

            cout << " ";
        }

        cout << endl;
        cout << "\t\t-";
        for (int i = 0; i < n + 1; i++)
        {
            cout << "----";
        }
        cout << endl;

    }
}

void RandLetter(letters *&listHead, letters *&letterHead)
{
    if (!letterHead)
    {
        cout << "Letters ended\n";
    }

    letters *p = letterHead;

    int count = 0;

    int r = rand() % RANDNUM;
    for (int i = 0; i < r; i++)
    {
        p = p -> next;
        count++;

        if (!p -> next)
        {
            p = letterHead;
        }
    }

    PushToLetters(listHead, p -> word, p -> factor);
    DeleteLetter(letterHead, p -> word);
}

void InputWord(letters *listHead, string &word)
{
    string letter;
    string temp;
    int ind;

    cout << "List of available letters:";
    LettersOutput(listHead);

    do
    {
        ind = 0;
        cout << "Make a word:\n";
        cin >> word;
        if (word.size() < 1 || word.size() > 8)
        {
            cout << "Wrong number of letters\n";
            ind = 1;
        }

        for (int i = 0; i < word.size(); i++)
        {
            temp = word[i];
            if (Check(listHead, temp))
            {
                cout << "You used forbidden letters\n";
                ind = 1;
            }
        }

    }
    while (ind);
}

void MakeMove(string **playground, int **area, letters *&listHead, dictionary *dictHead, player &p)
{
    int choice;
    string word;
    string temp;

    string direction;
    int x, y;
    int ind;

    cout << "Make your move" << endl;
    cout << "Want to pick a word manually(1), or call an assistant(0):";
    cin >> choice;

    if (!choice)
    {
        // Тут будет открываться помощник в другом окне
    }

    do
    {
        InputWord(listHead, word);
        if (Check(dictHead, word))
        {
            cout << "There is no such word in your dictionary\n";
        }
    }
    while (Check(dictHead, word));

    ind = 1;
    do
    {
        cout << "Input coordinates of first letter: ";
        cin >> x >> y;

        if (((x >= 0) && (y >= 0)) && ((x <= 14) && (y <= 14)))
        {
            ind = 0;
        }
        else
        {
            cout << "Wrong coordinates" << endl;
        }
    }
    while (ind);

    ind = 1;
    do
    {
        cout << "Input direction(r/l/t/b): ";
        cin >> direction;

        if (((direction == "r") && (direction == "l")) && ((direction == "t") && (direction == "b")))
        {
            if (CheckDirection(word.size(), x, y, direction))
            {
                ind = 0;
            }
            else
            {
                cout << "Wrong don`t fit" << endl;
            }
        }
        else
        {
            cout << "Wrong direction" << endl;
        }
    }
    while (ind);

    p.score += PullWord(playground, area, x, y, direction, word);

    for (int i = 0; i < word.size(); i++)
    {
        temp = word[i];
        DeleteLetter(listHead, temp);
    }

    for (int i = ListCounter(listHead) - 1; i < 7; i++)
    {
        RandLetter(listHead, p.list);
    }

}

int CheckDirection(int len, int x, int y, string direction)
{
    if (direction == "r")
    {
        x += (len - 1);

        if ((x >= 0) && (x <= 14))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    if (direction == "l")
    {
        x -= (len - 1);

        if ((x >= 0) && (x <= 14))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    if (direction == "t")
    {
        y += (len - 1);

        if ((y >= 0) && (y <= 14))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    if (direction == "b")
    {
        y += (len - 1);

        if ((y >= 0) && (y <= 14))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

int PullWord(string **playground, int **area, int x, int y, string direction, string word)
{
    int count = 0;
    int score = 0;

    string temp;

    if (direction == "r")
    {
        for (int i = x; i < x + word.size(); i++)
        {
            temp = word[count];

            *(*(playground + y) + i) = temp;
            score += LetterScore(temp) * (*(*(area + y) + i));
            count++;
        }

        return score;
    }

    if (direction == "l")
    {
        for (int i = x; i > x - word.size(); i--)
        {
            temp = word[count];

            *(*(playground + y) + i) = temp;
            score += LetterScore(temp) * (*(*(area + y) + i));
            count++;
        }

        return score;
    }

    if (direction == "t")
    {
        for (int i = y; i < y + word.size(); i++)
        {
            temp = word[count];

            *(*(playground + i) + x) = temp;
            score += LetterScore(temp) * (*(*(area + i) + x));
            count++;
        }

        return score;
    }

    if (direction == "b")
    {
        for (int i = y; i > y + word.size(); i--)
        {
            temp = word[count];

            *(*(playground + i) + x) = temp;
            score += LetterScore(temp) * (*(*(area + i) + x));
            count++;
        }

        return score;
    }
}