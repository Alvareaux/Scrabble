#include <iostream>
#include <string>
#include <windows.h>

#include "misc_func.h"
#include "game_func.h"

using namespace std;

const int N = 15;

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    string path = "C:\\CPrj\\Scrabble\\area.txt";

    string **playground = CreateMatrixString(N);
    int **area = CreateMatrixInt(N);

    if (InputFromFile(area, N, path))
    {
        DisplayPlayground(playground, area);
    }

    system("pause");
    return 0;
}



