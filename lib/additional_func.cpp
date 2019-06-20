#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <fstream>
#include <string>

#include "additional_func.h"

using namespace std;

void DeleteLetter(letters *&head, string x)
{
	if (!head)
	{
		cout << "List is empty\n";
	}
	letters *p = head;
	letters *q;

	if (head -> word == x)
	{
		head = head -> next;
		delete p;
		return;
	}

	q = p -> next;
	while (q -> word != x && q -> next)
	{
		p = p -> next;
		q = p -> next;
	}

	if (!q -> next)
	{
		p -> next = NULL;
		delete q;
		return;
	}

	p = head;

	while (p)
	{
		if (p -> next -> word == q -> word)
		{
			p -> next = p -> next -> next;
			delete q;
			return;
		}
		p = p -> next;
	}
}

void LettersOutput(letters *head)
{
	letters *p = head;
	while (p)
	{
		cout << p -> word << " " << p -> factor << " ";
		p = p -> next;
	}
	cout << endl;
}

int ListCounter(letters *head)
{
	int i = 1;
	letters *p = head;
	while (p)
	{
		i++;
		p = p -> next;
	}

	return i;
}

int Check(dictionary *head, string word)
{
	dictionary *p = head;
	while (p)
	{
		if (p -> word == word)
		{
			return 0;
		}
		p = p -> next;
	}
	return 1;
}

int Check(letters *head, string word)
{
	letters *p = head;
	while (p)
	{
		if (p -> word == word)
		{
			return 0;
		}
		p = p -> next;
	}
	return 1;
}

