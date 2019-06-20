#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <fstream>
#include <string>
#include "dictionary.h"
#include "additional_func.h"
using namespace std;

void delete_letter(letters *&head, string x)
{
	if (!head)
	{
		cout << "list is empty\n";
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

int check(dictionary *head,string word)
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

int check(letters *head, string word)
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
int check_location(dictionary *head, string **arr, int x, int y)
{
	int i = x;
	int j = y;
	int k, l;
	string str = " ";
	string word;
	while (arr[i][j] != str && i >= 0)
	{
		i--;
	}
	k = i;
	while (arr[i][j] != str && i < 15)
	{
		i++;
	}
	l = i;
	for (i = k + 1;i < l;i++)
	{
		word += arr[i][j];
	}
	if (check(head, word))
	{
		cout << "there is no such word in your dictionary\n";
		return 0;
	}
	word.clear();
	i = x;
	while (arr[i][j] != str && j >= 0)
	{
		j--;
	}
	k = j;
	while (arr[i][j] != str && j < 15)
	{
		j++;
	}
	l = j;
	for (j = k + 1;j < l;j++)
	{
		word += arr[i][j];
	}
	if (check(head, word))
	{
		cout << "there is no such word in your dictionary\n";
		return 0;
	}
	return 1;
}
