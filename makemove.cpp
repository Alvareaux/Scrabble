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
	int r = rand() % 148;
	for (int i = 0;i < r;i++)
	{
		p = p->next;
		if (!p->next)
		{
			p = letterHead;
		}
	}
	q->word = p->word;
	q->factor = p->factor;
	q->next = NULL;

	delete_letter(letterHead, p->word);
	give_list(listHead, q->word, q->factor);

}
void input_word(letters *listHead, string &word)
{
	string letter;
	string temp;
	int ind;
	cout << "list of available letters:\n";
	letters_output(listHead);
	do
	{
		ind = 0;
		cout << "make a word\n";
		cin >> word;
		if (word.size() < 1 || word.size() > 8)
		{
			cout << "wrong number of letters\n";
			ind = 1;
		}
		

		for (int i = 0; i < word.size(); i++)
		{
			temp = word[i];
			if (check(listHead, temp))
			{
				cout << "you used third-party letters\n";
				ind = 1;
			}
		}
			
	} while (ind);
	
}

void make_move(letters *&listHead, letters *&letterHead, dictionary *dicHead)
{
	int ind = 1, choice;
	string word;
	string temp;

	cout << "make your move\n";
	cout << "want to pick a word manually, or call an assistant\n";
	cin >> choice;
	if (choice)
	{
		do
		{
			input_word(listHead, word);
			if (check(dicHead, word))
			{
				cout << "there is no such word in your dictionary\n";
			}
		} while (check(dicHead, word));
		for (int i = 0;i < word.size();i++)
		{
			temp = word[i];
			delete_letter(listHead, temp);
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

