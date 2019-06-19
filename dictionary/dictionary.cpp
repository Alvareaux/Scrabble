#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <fstream>
#include <string>
#include "dictionary.h"


void fin(dictionary *&head)
{
	dictionary *p;
	int i = 0;
	for (char x = 'A'; x <= 'Z'; x++)
	{
		stringstream ss;
		ss << x << ".txt";
		ifstream file(ss.str());
		string line;
		if (!file.is_open())
		{
			cout << "open error" << endl;
		}
		else
		{
			while (file)
			{
				getline(file, line);
				give_dictionary(head, line);
			}

			file.close();

		}

	}
}

void give_dictionary(dictionary *&head, string temp)
{
	int i;
	dictionary *p = new dictionary;
	dictionary *q;
	for (i = 0; i < temp.size() && temp[i] != ' ';i++)
	{
		p->word += temp[i];
	}
	for (i;i < temp.size();i++)
	{
		p->mean += temp[i];
	}
	p->next = NULL;
	if (!head)
	{
		head = p;
		return;
	}
	q = head;
	while (q->next)
	{
		q = q->next;
	}
	q->next = p;
}

void fin(letters *&head)
{
	string temp;
	int n, num;
	ifstream f1("letters.txt", ios::in);
	ifstream f2("factors.txt", ios::in);
	ifstream f3("count.txt", ios::in);
	if (!f1.is_open() || !f2.is_open() || !f3.is_open())
	{
		cout << "open error" << endl;
	}
	else
	{
		while (f1 && f2 && f3)
		{
			f3 >> n;
			getline(f1, temp);
			f2 >> num;
			for (int i = 0;i < n;i++)
			{
				give_letters(head, temp, num);
			}
		}

		f1.close();
		f2.close();
		f3.close();

	}
}
void give_letters(letters *&head, string temp, int n)
{
	letters *p = new letters;
	letters *q;
	p->word = temp;
	p->factor = n;
	p->next = NULL;
	if (!head)
	{
		head = p;
		return;
	}
	q = head;
	while (q->next)
	{
		q = q->next;
	}
	q->next = p;
}
