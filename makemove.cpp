#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <fstream>
#include <string>
#include "dictionary.h"
#include "additional_func.h"
using namespace std;

void give_list(letters *&head, string word, int factor)
{
	letters *p = new letters;
	letters *q = new letters;
	q->word = word;
	q->factor = factor;
	q->next = NULL;
	if (!head)
	{
		head = q;

		return;
	}
	p = head;

	while (p->next)
	{
		p = p->next;
	}
	p->next = q;

}
void rand_letter(letters *&listHead, letters *&letterHead)
{
	if (!letterHead)
	{
		cout << "letters ended\n";
	}
	int i = 0;
	int ind = 1;
	letters *p = letterHead;
	letters *q = new letters;
	while (p && ind)
	{
		if (rand() % 14 == 8)
		{
			q->word = p->word;
			q->factor = p->factor;
			q->next = NULL;
			ind = 0;
		}
		p = p->next;
	}
	delete_letter(letterHead, p);
	give_list(listHead, q->word, q->factor);

}
void input_letters(letters *listHead, letters *&wordHead)
{
	letters *p = listHead;
	int num, ind = 0;
	cout << "select letter number\n";
	letters_output(listHead);
	do
	{
		cin >> num;
		if (num < 0 || num >= list_counter(listHead))
		{
			ind = 1;
		}
	} while (ind);
	for (int i = 0;i < num;i++)
	{
		p = p->next;
	}
	give_list(wordHead, p->word, p->factor);
}

void make_move(letters *&listHead, letters *&letterHead, dictionary *dicHead)
{
	int ind = 1, choice;
	letters *wordHead = NULL;
	coords *coordHead = NULL;
	letters *p;

	cout << "make your move\n";
	cout << "want to pick a word manually, or call an assistant\n";
	cin >> choice;
	if (choice)
	{
		do
		{
			do
			{
				input_letters(listHead, wordHead);
				give_coords(coordHead);
				cout << "would you like to continue,0 - yes, 1 - no?\n";
				cin >> choice;
				if (choice || !listHead)
				{
					ind = 0;
				}
			} while (ind);
			if (check(dicHead, wordHead))
			{
				cout << "there is no such word in your dictionary\n";
			}
		} while (check(dicHead, wordHead));

		p = wordHead;
		while (p)
		{
			delete_letter(listHead, p);
			p = p->next;
		}
		for (int i = list_counter(listHead) - 1;i < 7;i++)
		{
			rand_letter(listHead, letterHead);
		}
	}
	else
	{

	}

}
