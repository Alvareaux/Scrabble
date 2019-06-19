#include <fstream>
#include <iostream>
#include <string>
#include <math.h>

#include "game_func.h"

using namespace std;

void DisplayPlayground(string **playground, int **area, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((*(*(playground + i) + j)).empty())
            {
                if (*(*(area + i) + j) == 1)
                {
                    cout << "  ";
                }
                else
                {
                    if (*(*(area + i) + j) < 0)
                    {
                        cout << *(*(area + i) + j);
                    }
                    else
                    {
                        cout << " " << *(*(area + i) + j);
                    }
                }
            }
            else
            {
                cout << *(*(playground + i) + j);
            }

            cout << "  ";
        }

        cout << "\n\n";
    }
}
