#include <iostream>
#include <string>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <fstream>

#include "dictionary/dictionary.h"
#include "lib/misc_func.h"
#include "lib/game_func.h"
#include "lib/additional_func.h"

using namespace std;

int CheckCost(letters *head, string s)
{
	letters *p = head;
	while (p)
	{
		if (p->word == s)
		{
			return p->factor;
		}
		p = p->next;
	}
	return -1;
}

string CheckMeaning(dictionary *head, string s)
{
	dictionary *p = head;
	while (p)
	{
		if (p->word == s)
		{
			return p->mean;
		}
		p = p->next;
	}
	return "error";
}
string Minus(string s)
{
	string temp;
	for (int i = 0; i < s.size() - 1; i++)
	{
		temp += s[i];
	}
	return temp;
}

void sort_bubl(string s, int n)
{
	int i, j;
	char buf;

	for (i = 0; i < n; i++)
	{
		for (j = n - 1; j > i; j--)
		{
			if (s[j] < s[j - 1])
			{
				buf = s[j];
				s[j] = s[j - 1];
				s[j - 1] = buf;
			}
		}
	}

}

void display(string s, int n)
{
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout << s[i];
	}
}

void HelperDisplay(letters *helpHead, dictionary *dictHead)
{
	if (!helpHead)
	{
		cout << "It is impossible to add a word from these letters\n";
		return;
	}
	letters *p = helpHead;
	while (p)
	{
		cout << p->word << "(" << p->factor << ")  " << CheckMeaning << endl;
		p = p->next;
	}

}

void helpList(string s, letters *listHead, letters *&helpHead)
{
	letters *p = listHead;
	string temp;
	int count = 0;
	int i = 0;
	while (p)
	{
		temp = s[i];
		count += CheckCost(listHead, temp);
		p = p->next;
	}
	PushToLetters(helpHead, s, count);
}

void mix(string s, int n, letters *listHead, dictionary *dictHead, letters*&helpHead)
{
	char buf;
	int k, q, j, i;

	while (true)
	{
		if (!Check(dictHead, s))
		{
			helpList(s, listHead, helpHead);
		}
		for (i = n - 2; i >= 0 && s[i] >= s[i + 1]; i--)
		{

		}
		if (i < 0)
		{
			break;
		}
		for (j = n - 1; s[i] >= s[j]; j--)
		{

		}
		buf = s[j];
		s[j] = s[i];
		s[i] = buf;

		for (k = i + 1, q = n - 1; k < q; k++, q--)
		{
			buf = s[k];
			s[k] = s[q];
			s[q] = buf;
		}
	}


}
void assisstant(string s, letters *listHead, dictionary *dictHead)
{
	letters *helpHead = NULL;
	cout << "Loading...\n";
	do
	{
		sort_bubl(s, s.size());
		mix(s, s.size(), listHead, dictHead, helpHead);

		s = Minus(s);


	} while (s.size());

	HelperDisplay(helpHead, dictHead);
}


