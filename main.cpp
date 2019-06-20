#include <iostream>
#include <string>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <fstream>

#include "dictionary/dictionary.h"
#include "lib/misc_func.h"
#include "lib/game_func.h"
#include "lib/additional_func.h"

using namespace std;

const int N = 15;

struct player
{
	int id;
	string name;

	letters *list;

	int score;
};

int main()
{
    srand(time(0));

	string path = "C:\\CPrj\\Scrabble\\area.txt";

	string **playground = CreateMatrixString(N);

	for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            *(*(playground + i) + j) = " ";
        }
    }

	int **area = CreateMatrixInt(N);

	if (InputFromFile(area, N, path))
	{
		cout << "SCRABBLE" << endl;
        cout << "TP-82" << endl;

        cout << "Loading\n" << endl;

        dictionary *dictHead = NULL;
        fin(dictHead);
        letters *letterHead = NULL;
        fin(letterHead);

        player first;
        player second;

        first.id = 1;
        second.id = 2;
        first.score = 0;
        second.score = 0;

        cout << "Input player 1 name: ";
        cin >> first.name;

        cout << "Input player 2 name: ";
        cin >> second.name;

        int step = 0;
        do
        {
            system("CLS");

            cout << "\n\n\n\n";
            DisplayPlayground(playground, area);


        }
        while (true);


	}
	
	letters *listHead = NULL;

	// for (int i = 0;i < 7;i++)
    //	{
    //        RandLetter(listHead, letterHead);
    //	}
    //    MakeMove(listHead, letterHead, dicHead);

	system("pause");
	return 0;
}




