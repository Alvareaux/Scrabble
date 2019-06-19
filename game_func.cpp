#include <fstream>
#include <iostream>
#include <string>
#include <windows.h>

#include "game_func.h"

using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

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
