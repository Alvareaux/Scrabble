#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <fstream>
#include <string>

#include "dictionary.h"

void fin(dictionary *&head)
{
	for (char x = 'A'; x <= 'Z'; x++)
	{
		stringstream ss;
		ss << "C:\\CPrj\\Scrabble\\dictionary\\txt\\" << x << ".txt";

		ifstream file(ss.str());
		string line;

		if (!file.is_open())
		{
			cout << "Open error: " << x << ".txt" << endl;
		}
		else
		{
			while (file)
			{
				getline(file, line);
                PushToDict(head, line);
			}

			file.close();

		}
	}
}

void PushToDict(dictionary *&head, string temp)
{
	int i;
	dictionary *p = new dictionary;
	dictionary *q;

	for (i = 0; i < temp.size() && temp[i] != ' '; i++)
	{
		p -> word += toupper(temp[i]);
	}
	for (i; i < temp.size(); i++)
	{
		p -> mean += temp[i];
	}

	p -> next = NULL;

	if (!head)
	{
		head = p;
		return;
	}

	q = head;
	while (q -> next)
	{
		q = q -> next;
	}
	q -> next = p;
}

void fin(letters *&head)
{
	string letter;
	int count, multiplier;

	ifstream f("C:\\CPrj\\Scrabble\\dictionary\\letters.txt", ios::in);

	if (!f.is_open())
	{
		cout << "Open error: letters.txt" << endl;
	}
	else
	{
		while (f)
		{
		    f >> letter;
			f >> count;
			f >> multiplier;

			for (int i = 0; i < count; i++)
			{
                PushToLetters(head, letter, multiplier);
			}
		}

		f.close();
	}
}

void PushToLetters(letters *&head, string word, int n)
{
	letters *p = new letters;
	letters *q;

	p -> word = word;
	p -> factor = n;
	p -> next = NULL;

	if (!head)
	{
		head = p;
		return;
	}

	q = head;
	while (q -> next)
	{
		q = q -> next;
	}
	q -> next = p;
}

int LetterScore(string letter)
{
    return 1;
}
