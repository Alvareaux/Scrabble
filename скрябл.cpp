#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

struct dictionary
{
	string word;
	string mean;
	dictionary *next;
};

void fin(dictionary *&head);
void give_dictionary(dictionary *&head, string temp);
int main()
{
	dictionary *dicHead = NULL;
	fin(dicHead);
	string **board = create_matrix(15);
	
	system("pause");
	return 0;
}

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
		while (file)
		{
			getline(file, line);
			give_dictionary(head, line);		
		}

		file.close();
		system("CLS");
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
