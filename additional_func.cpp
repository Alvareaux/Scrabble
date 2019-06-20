#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <fstream>
#include <string>
#include "dictionary.h"
#include "additional_func.h"
using namespace std;

void delete_letter(letters *&head, letters *x)
{
	if (!head)
	{
		cout << "list is empty\n";
	}
	letters *p = head;
	letters *q;

	if (head->word == x->word)
	{
		head = head->next;
		delete p;
		return;
	}

	q = p->next;
	while (q->word != x->word && q->next)
	{
		p = p->next;
		q = p->next;
	}



	if (!q->next)
	{
		p->next = NULL;
		delete q;
		return;
	}

	p = head;

	while (p)
	{
		if (p->next->word == q->word)
		{
			p->next = p->next->next;
			delete q;
			return;
		}
		p = p->next;
	}
}

void letters_output(letters *head)
{
	letters *p = head;
	while (p)
	{
		cout << p->word << " " << p->factor << " ";
		p = p->next;
	}
	cout << endl;
}

int list_counter(letters *head)
{
	int i = 0;
	letters *p = head;
	while (p)
	{
		i++;
		p = p->next;
	}
	return i++;
}

int check(dictionary *head, letters *wordHead)
{
	letters *q = wordHead;
	dictionary *p = head;
	string word;
	while (q)
	{
		word += q->word;
		q = q->next;
	}
	while (p)
	{
		if (p->word == word)
		{
			return 0;
		}
		p = p->next;
	}
	return 1;
}