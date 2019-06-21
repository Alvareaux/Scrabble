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

	if (head->word == x)
	{
		head = head->next;
		delete p;
		return;
	}

	q = p->next;
	while (q->word != x && q->next)
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

int Check(dictionary *head, string word)
{
	dictionary *p = head;
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

int Check(letters *head, string word)
{
	letters *p = head;
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

void Clone(letters *head1, letters *&head2)
{
	letters *p = NULL;
	letters *q = NULL;
	head2 = new letters;
	head2->word = head1->word;
	head2->factor = head2->factor;
	p = head2;
	q = head1->next;
	letters*q = head2;
	while (q)
	{
		p->next = new letters;
		p = p->next;
		p->word = q->word;
		p->factor = q->factor;
		q = q->next;
	}
	p->next = NULL;
}
