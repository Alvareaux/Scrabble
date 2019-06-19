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
	letters *listHead = NULL;
	fin(listHead);
	letters *p = listHead;
	while (p)
	{
		cout << p->word << " " << p->factor << endl;
		p = p->next;
	}

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




