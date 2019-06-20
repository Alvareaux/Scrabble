#include <iostream>
#include <string>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <fstream>
#include "dictionary.h"
#include "misc_func.h"
#include "game_func.h"
#include "additional_func.h"
#include "makemove.h"

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
	dictionary *dicHead = NULL;
	fin(dicHead);
	letters *letterHead = NULL;
	fin(letterHead);

	string path = "C:\\CPrj\\Scrabble\\area.txt";

	string **playground = CreateMatrixString(N);
	int **area = CreateMatrixInt(N);

	if (InputFromFile(area, N, path))
	{
		cout << "\n\n\n\n";
		DisplayPlayground(playground, area);
	}
	
	letters *listHead = NULL;
	srand(time(0));
	for (int i = 0;i < 7;i++)
	{
		rand_letter(listHead, letterHead);
	}
	make_move(listHead,letterHead, dicHead);
	system("pause");
	return 0;
}




