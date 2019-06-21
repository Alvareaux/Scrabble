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
		cout << "Game by Anatolii Voitko and Ihor Nekhaienko" << endl;
		cout << "https://github.com/Alvareaux/Scrabble" << endl;
        cout << "\t[TP-82]" << endl;

        cout << "\t\nLoading\n" << endl;

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

        first.list = NULL;
        second.list = NULL;
        GiveHand(first, letterHead);
        GiveHand(second, letterHead);

        player *active = &first;

        cout << "Game features: " << endl;
        cout << "\tBlue numbers are word multipliers" << endl;
        cout << "\tWhite numbers are letter multipliers\n" << endl;

        system("pause");

        int turn = 1;
        do
        {
            system("CLS");

            cout << "SCRABBLE" << endl;
            cout << "Game by Anatolii Voitko and Ihor Nekhaienko" << endl;
            cout << "\n\tTurn " << turn << "\n";
            cout << "\tPlayer " << active -> id << "\n\n";

            cout << "\tPlayer 1 score: " << first.score << endl;
            cout << "\tPlayer 2 score: " << second.score << endl;

            cout << endl;

            DisplayPlayground(playground, area);

            cout << "\n\tYour hand:" << endl;
            OutputHand(active);

            MakeMove(playground, area, letterHead, dictHead, active);
            GiveHand(*active, letterHead);

            system("pause");

            ChangePlayer(active, &first, &second);
            turn++;
        }
        while (letterHead);

        system("CLS");

        cout << "SCRABBLE";
        cout << "\n\tTurn " << turn << "\n";
        cout << "\tPlayer " << active -> id << "\n\n";

        cout << "\tPlayer 1 score: " << first.score << endl;
        cout << "\tPlayer 2 score: " << second.score << endl;

        cout << endl;

        DisplayPlayground(playground, area);

        cout << endl;

        if (first.score > second.score)
        {
            cout << "\tPlayer 1 win!";
        }
        else if (first.score < second.score)
        {
            cout << "\tPlayer 2 win!";
        }
        else if (first.score == second.score)
        {
            cout << "\tDead heat!";
        }
	}

	system("pause");
	return 0;
}




