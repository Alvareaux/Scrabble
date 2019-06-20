#include <fstream>
#include <iostream>
#include <string>

#include "misc_func.h"

using namespace std;

int **CreateMatrixInt(int n)
{
    int **arr = new int*[n];
    for (int i = 0; i < n; i++)
    {
        *(arr + i) = new int[n];
    }

    return arr;
}

string **CreateMatrixString(int n)
{
    string **arr = new string*[n];
    for (int i = 0; i < n; i++)
    {
        *(arr + i) = new string[n];
    }

    return arr;
}


int InputFromFile(int **arr, int n, string path)
{
    ifstream fin(path, ios_base::in);

    if (!fin.is_open())
    {
        cout << "File cannot be opened" << endl;
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fin >> *(*(arr + i) + j);
        }
    }

    fin.close();
    return 1;
}