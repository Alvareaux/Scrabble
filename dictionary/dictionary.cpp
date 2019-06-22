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
    if (letter == "A")
    {
        return 1;
    }
    if (letter == "B")
    {
        return 3;
    }
    if (letter == "C")
    {
        return 3;
    }
    if (letter == "D")
    {
        return 2;
    }
    if (letter == "E")
    {
        return 1;
    }
    if (letter == "F")
    {
        return 4;
    }
    if (letter == "G")
    {
        return 2;
    }
    if (letter == "H")
    {
        return 4;
    }
    if (letter == "I")
    {
        return 1;
    }
    if (letter == "J")
    {
        return 8;
    }
    if (letter == "K")
    {
        return 5;
    }
    if (letter == "L")
    {
        return 1;
    }
    if (letter == "M")
    {
        return 3;
    }
    if (letter == "N")
    {
        return 1;
    }
    if (letter == "O")
    {
        return 1;
    }
    if (letter == "P")
    {
        return 3;
    }
    if (letter == "Q")
    {
        return 10;
    }
    if (letter == "R")
    {
        return 1;
    }
    if (letter == "S")
    {
        return 1;
    }
    if (letter == "T")
    {
        return 1;
    }
    if (letter == "U")
    {
        return 1;
    }
    if (letter == "V")
    {
        return 4;
    }
    if (letter == "W")
    {
        return 4;
    }
    if (letter == "X")
    {
        return 8;
    }
    if (letter == "Y")
    {
        return 4;
    }
    if (letter == "Z")
    {
        return 10;
    }
    return 0;
}
