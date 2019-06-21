#include <fstream>
#include <iostream>
#include <string>
#include <Windows.h>

#include "game_func.h"
#include "additional_func.h"
#include "misc_func.h"
#include "../dictionary/dictionary.h"

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
            if ((*(*(playground + i) + j)) == " ")
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
                SetConsoleTextAttribute(hConsole, 6);
                cout << *(*(playground + i) + j);
                SetConsoleTextAttribute(hConsole, 7);
                cout << " |";
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

void GiveHand(player &p, letters *&letterHead)
{
    letters *q = p.list;
    int count = 0;

    while (q)
    {
        q = q -> next;
        count++;
    }

    for (int i = 0; i < 7 - count; i++)
    {
        RandLetter(p.list, letterHead);
    }

}

void OutputHand(player *p)
{
    letters *q = p -> list;

    cout << "\t\t";
    while (q)
    {
        cout << q -> factor << " ";
        q = q -> next;
    }
    cout << endl;

    q = p -> list;

    cout << "\t\t";
    while (q)
    {
        cout << q -> word << " ";
        q = q -> next;
    }
    cout << endl;

}

void InputWord(letters *listHead, string &word)
{
    string letter;
    string temp;
    int ind;

    do
    {
        ind = 0;
        cout << "Make a word: ";
        cin >> word;
        if ((word.size() < 1) || (word.size() > 8))
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

void MakeMove(string **playground, int **area, letters *&listHead, dictionary *dictHead, player *&p)
{
    int choice;
    string word;
    string temp;

    string direction;
    int x, y;
    int ind, ind0;
    int score;

    cout << "Make your move" << endl;
    cout << "Want to pick a word manually(1), change hand(-1) or call an assistant(0): ";
    cin >> choice;

    if (choice == 0)
    {
        // Тут будет открываться помощник в другом окне
        system ("start C:\\CPrj\\Scrabble\\helper\\helper.exe");
    }

    if (choice == -1)
    {
        cout << "Write letters to swap like \'ABCDC\': ";
        cin >> temp;
        SwapHand(p, listHead, temp);
    }
    else
    {

        ind0 = 1;
        do
        {

            do
            {
                InputWord(p -> list, word);
                if (Check(dictHead, word))
                {
                    cout << "There is no such word in your dictionary" << endl;
                }
            }
            while (Check(dictHead, word));

            ind = 1;
            do
            {
                cout << "Input coordinates of first letter: ";
                cin >> y >> x;

                if (((x >= 0) && (y >= 0)) && ((x <= 14) && (y <= 14)))
                {
                    ind = 0;
                } else
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

                if (((direction == "r") || (direction == "l")) || ((direction == "t") || (direction == "b")))
                {
                    if (CheckDirection(word.size(), x, y, direction))
                    {
                        ind = 0;
                    } else
                    {
                        cout << "Word don`t fit" << endl;
                    }
                } else
                {
                    cout << "Wrong direction" << endl;
                }
            }
            while (ind);

            score = PullWord(playground, area, x, y, direction, word);
            if (score == -1)
            {
                cout << "Letter collision" << endl;
            } else
            {
                p -> score += score;
                ind0 = 0;
            }
        }
        while (ind0);

        for (int i = 0; i < word.size(); i++)
        {
            temp = word[i];
            DeleteLetter(p -> list, temp);
        }
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
    int multiplier = 0;
    string **backup = CreateMatrixString(15);

    Clone(backup, playground, 15);

    int count = 0;
    int score = 0;

    string temp;

    if (direction == "r")
    {
        for (int i = x; i < x + word.size(); i++)
        {
            temp = word[count];

            cout << "| " << *(*(playground + y) + i) << " - " << word[count] << " |" << endl;

            if ((*(*(playground + y) + i) != " ") && ((*(*(playground + y) + i))[0] != word[count]))
            {
                Clone(playground, backup, 15);
                //DeleteMatrix(backup, 15);

                return -1;
            }

            if (*(*(playground + y) + i) == " ")
            {
                *(*(playground + y) + i) = temp;

                if ((*(*(area + y) + i)) > 0)
                {
                    score += LetterScore(temp) * (*(*(area + y) + i));
                }
                else
                {
                    score += LetterScore(temp);
                    multiplier += -(*(*(area + y) + i));
                }
            }

            count++;
        }

        //DeleteMatrix(backup, 15);
        if (multiplier == 0)
        {
            multiplier = 1;
        }

        return score * multiplier;
    }

    if (direction == "l")
    {
        for (int i = x; i > x - word.size(); i--)
        {
            temp = word[count];

            cout << "| " << *(*(playground + y) + i) << " - " << word[count] << " |" << endl;

            if ((*(*(playground + y) + i) != " ") && ((*(*(playground + y) + i))[0] != word[count]))
            {
                Clone(playground, backup, 15);
                //DeleteMatrix(backup, 15);

                return -1;
            }

            if (*(*(playground + y) + i) == " ")
            {
                *(*(playground + y) + i) = temp;

                if ((*(*(area + y) + i)) > 0)
                {
                    score += LetterScore(temp) * (*(*(area + y) + i));
                }
                else
                {
                    score += LetterScore(temp);
                    multiplier += -(*(*(area + y) + i));
                }
            }

            count++;
        }

        //DeleteMatrix(backup, 15);
        if (multiplier == 0)
        {
            multiplier = 1;
        }

        return score * multiplier;
    }

    if (direction == "t")
    {
        for (int i = y; i > y - word.size(); i--)
        {
            temp = word[count];

            cout << "| " << *(*(playground + i) + x) << " - " << word[count] << " |" << endl;

            if ((*(*(playground + i) + x) != " ") && ((*(*(playground + i) + x))[0] != word[count]))
            {
                Clone(playground, backup, 15);
                //DeleteMatrix(backup, 15);

                return -1;
            }

            if (*(*(playground + i) + x) == " ")
            {
                *(*(playground + i) + x) = temp;

                if ((*(*(area + i) + x)) > 0)
                {
                    score += LetterScore(temp) * (*(*(area + i) + x));
                }
                else
                {
                    score += LetterScore(temp);
                    multiplier += -(*(*(area + i) + x));
                }
            }

            count++;
        }

        //DeleteMatrix(backup, 15);
        if (multiplier == 0)
        {
            multiplier = 1;
        }

        return score * multiplier;
    }

    if (direction == "b")
    {
        for (int i = y; i < y + word.size(); i++)
        {
            temp = word[count];

            cout << "| " << *(*(playground + i) + x) << " - " << word[count] << " |" << endl;

            if ((*(*(playground + i) + x) != " ") && ((*(*(playground + i) + x))[0] != word[count]))
            {
                Clone(playground, backup, 15);
                //DeleteMatrix(backup, 15);

                return -1;
            }

            if (*(*(playground + i) + x) == " ")
            {
                *(*(playground + i) + x) = temp;

                if ((*(*(area + i) + x)) > 0)
                {
                    score += LetterScore(temp) * (*(*(area + i) + x));
                }
                else
                {
                    score += LetterScore(temp);
                    multiplier += -(*(*(area + i) + x));
                }
            }

            count++;
        }

        //DeleteMatrix(backup, 15);
        if (multiplier == 0)
        {
            multiplier = 1;
        }

        return score * multiplier;
    }
}

void ChangePlayer(player *&active, player *first, player *second)
{
    if (active -> id == first -> id)
    {
        active = second;
        return;
    }

    if (active -> id == second -> id)
    {
        active = first;
    }
}

void SwapHand(player *&active, letters *&letterList, string swap)
{
    string temp;

    for (int i = 0; i < swap.size(); i++)
    {
        temp = swap[i];
        PushToLetters(letterList, temp, LetterScore(temp));
        DeleteLetter(active -> list, temp);
    }

    GiveHand(*active, letterList);
}