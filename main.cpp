#include <iostream>
#include <string>
#include <windows.h>

#include "misc_func.h"
#include "game_func.h"

using namespace std;

const int N = 15;

struct player
{
    int id;
    string name;

    int score;
    
};

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    string path = "C:\\CPrj\\Scrabble\\area.txt";

    string **playground = CreateMatrixString(N);
    int **area = CreateMatrixInt(N);

    if (InputFromFile(area, N, path))
    {
        cout << "\n\n\n\n";
        DisplayPlayground(playground, area);
    }

    system("pause");
    return 0;
}



