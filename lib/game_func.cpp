#include <fstream>
#include <iostream>
#include <string>
#include <Windows.h>

#include "game_func.h"
#include "misc_func.h"
#include "../dictionary/dictionary.h"
#include "additional_func.h"

using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
const int RANDNUM = 666;

void DisplayPlayground(string **playground, int **area, int n)
{
	cout << "\t\t    -";
	for (int i = 0; i < n; i++)
	{
		cout << "----";
	}
	cout << endl;


	cout << "\t\t    | ";
	for (int i = 0; i < n; i++)
	{
		if (i < 10)
		{
			SetConsoleTextAttribute(hConsole, 2);
			cout << "" << i;
			SetConsoleTextAttribute(hConsole, 7);
			cout << " |";
		}
		else
		{
			SetConsoleTextAttribute(hConsole, 2);
			cout << i;
			SetConsoleTextAttribute(hConsole, 7);
			cout << "|";
		}

		cout << " ";
	}
	cout << endl;

	cout << "\t\t-";
	for (int i = 0; i < n + 1; i++)
	{
		cout << "----";
	}
	cout << endl;

	for (int i = 0; i < n; i++)
	{
		if (i < 10)
		{
			cout << "\t\t| ";
			SetConsoleTextAttribute(hConsole, 2);
			cout << i;
			SetConsoleTextAttribute(hConsole, 7);
			cout << " | ";
		}
		else
		{
			cout << "\t\t| ";
			SetConsoleTextAttribute(hConsole, 2);
			cout << i;
			SetConsoleTextAttribute(hConsole, 7);
			cout << "| ";
		}

		for (int j = 0; j < n; j++)
		{
			if ((*(*(playground + i) + j)) == " ")
			{
				if (*(*(area + i) + j) == 1)
				{
					cout << "  |";
				}
				else
				{
					if (*(*(area + i) + j) < 0)
					{
						SetConsoleTextAttribute(hConsole, 1);
						cout << -(*(*(area + i) + j));
						SetConsoleTextAttribute(hConsole, 7);
						cout << " |";
					}
					else
					{
						cout << (*(*(area + i) + j)) << " |";
					}
				}
			}
			else
			{
				SetConsoleTextAttribute(hConsole, 6);
				cout << *(*(playground + i) + j);
				SetConsoleTextAttribute(hConsole, 7);
				cout << " |";
			}

			cout << " ";
		}

		cout << endl;
		cout << "\t\t-";
		for (int i = 0; i < n + 1; i++)
		{
			cout << "----";
		}
		cout << endl;

	}
}

void RandLetter(letters *&listHead, letters *&letterHead)
{
	if (!letterHead)
	{
		cout << "Letters ended\n";
	}

	letters *p = letterHead;

	int count = 0;

	int r = rand() % RANDNUM;
	for (int i = 0; i < r; i++)
	{
		p = p->next;
		count++;

		if (!p->next)
		{
			p = letterHead;
		}
	}

	PushToLetters(listHead, p->word, p->factor);
	DeleteLetter(letterHead, p->word);
}

void GiveHand(player &p, letters *&letterHead)
{
	letters *q = p.list;
	int count = 0;

	while (q)
	{
		q = q->next;
		count++;
	}

	for (int i = 0; i < 7 - count; i++)
	{
		RandLetter(p.list, letterHead);
	}

}

void OutputHand(player *p)
{
	letters *q = p->list;

	cout << "\t\t";
	while (q)
	{
		if (q->factor >= 10)
		{
			cout << q->factor << " ";
		}
		else
		{
			cout << q->factor << "  ";
		}

		q = q->next;
	}
	cout << endl;

	q = p->list;

	cout << "\t\t";
	while (q)
	{
		cout << q->word << "  ";
		q = q->next;
	}
	cout << endl;

}

void InputWord(letters *listHead, string &word)
{
	letters *tempHead = NULL;
	string letter;
	string temp;
	int ind;

	do
	{
		Clone(listHead, tempHead);

		ind = 0;
		cout << "Make a word or write \'*\' to swap or \'-\' to cancel: ";
		cin >> word;
		if ((word == "*") || (word == "-"))
        {
		    return;
        }

		if ((word.size() < 1) || (word.size() > 8))
		{
			cout << "Wrong number of letters\n";
			ind = 1;
		}

		for (int i = 0; i < word.size(); i++)
		{
			temp = word[i];
			if (Check(tempHead, temp))
			{
				cout << "You used forbidden letters\n";
				ind = 1;
			}
			DeleteLetter(tempHead, temp);
		}

	} while (ind);
}

void MakeMove(string **playground, int **area, letters *&listHead, dictionary *dictHead, player *&p, player *&q)
{
	int choice;
	string word;
	string temp;

	string direction;
	int x, y;
	int ind, ind0;
	int score;
	int dscore = 1;

	cout << "Make your move" << endl;
    A:
	cout << "Want to pick a word manually(1), change hand(-1) or call an assistant(0): ";
	cin >> choice;

	if (choice == 0)
	{
		// Тут будет открываться помощник в другом окне
		system("start C:\\CPrj\\Scrabble\\helper\\helper.exe");
	}

	if (choice == -1)
	{
		cout << "Write letters to change like \'ABCDC\': ";
		cin >> temp;
		SwapHand(p, listHead, temp);
	}
	else
	{

		ind0 = 1;
		do
		{

			do
            {
				InputWord(p->list, word);

                if (word == "*")
                {
                    cout << "Write letters to change like \'ABCDC\': ";
                    cin >> temp;
                    SwapHand(p, listHead, temp);
                    return;
                }
                if (word == "-")
                {
                    goto A;
                }

				if (Check(dictHead, word))
				{
					cout << "There is no such word in your dictionary" << endl;
				}
			} while (Check(dictHead, word));

			ind = 1;
			do
			{
				cout << "Input coordinates of first letter or \'-1 -1\' to cancel: ";
				cin >> y >> x;

				if ((x == -1) || (y == -1))
                {
				    goto A;
                }

				if (((x >= 0) && (y >= 0)) && ((x <= 14) && (y <= 14)))
				{
					ind = 0;
				}
				if ((p -> score == 0) && (q -> score == 0))
				{
				    dscore = 0;
					if (x != 7 || y != 7)
                    {
                        for (int i = x; i < x + word.size(); i++)
                        {
                            if ((i == 7) && (y == 7))
                            {
                                ind = 0;
                            }
                        }

                        for (int i = y; i < y + word.size(); i++)
                        {
                            if ((i == 7) && (x == 7))
                            {
                                ind = 0;
                            }
                        }
					}
					else
                    {
					    ind = 0;
                    }
				}
				else
				{
					if (!CheckVoid(playground, y, x))
					{
						ind = 1;
					}
				}
				if (ind)
				{
					cout << "Wrong coordinates" << endl;
				}

		
			} while (ind);

			ind = 1;
			do
			{
				cout << "Input direction(h/v): ";
				cin >> direction;

				if ((direction == "v") || (direction == "h"))
				{
					if (CheckDirection(word.size(), x, y, direction))
					{
						ind = 0;
					}
					else
					{
						cout << "Word don`t fit" << endl;
					}
				}
				else
				{
					cout << "Wrong direction" << endl;
				}
			} while (ind);

			score = PullWord(dictHead, playground, area, x, y, direction, word, dscore);
			if (score == -1)
			{
				cout << "Letter collision" << endl;
			}
			else
			{
				p->score += score;
				ind0 = 0;
			}
		} while (ind0);

		if (word.size() == 7)
		{
			p->score += 50;
		}

		for (int i = 0; i < word.size(); i++)
		{
			temp = word[i];
			DeleteLetter(p->list, temp);
		}
	}
}

int CheckDirection(int len, int x, int y, string direction)
{
	if (direction == "h")
	{
		x += (len - 1);

		if ((x >= 0) && (x <= 14))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	if (direction == "h")
	{
		y += (len - 1);

		if ((y >= 0) && (y <= 14))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
}

int PullWord(dictionary *head, string **playground, int **area, int x, int y, string direction, string word, int dscore)
{
	int multiplier = 1;
	int ind = 0;
	string **backup = CreateMatrixString(15);

	Clone(backup, playground, 15);

	int count = 0;
	int score = 0;

	string temp;

	if (direction == "h")
	{
		for (int i = x; i < x + word.size(); i++)
		{
			temp = word[count];

			//cout << "| " << *(*(playground + y) + i) << " - " << word[count] << " |" << endl;

			if ((*(*(playground + y) + i) != " ") && ((*(*(playground + y) + i))[0] != word[count]))
			{
				Clone(playground, backup, 15);
				//DeleteMatrix(backup, 15);

				return -1;
			}

            if (((*(*(playground + y) + i))[0] == word[count]) || (dscore == 0))
            {
                ind = 1;
            }
		
			if (*(*(playground + y) + i) == " ")
			{
			
				*(*(playground + y) + i) = temp;
				//if()
				if (VerticalCheck(head, playground,direction, y, i))
				{
                    Clone(playground, backup, 15);
                    //DeleteMatrix(backup, 15);

					return -1;
				}
				
				if ((*(*(area + y) + i)) > 0)
				{
					score += LetterScore(temp) * (*(*(area + y) + i));
				}
				else
				{
					score += LetterScore(temp);
					multiplier *= -(*(*(area + y) + i));
				}
			}

			count++;
		}
		if (HorizontalCheck(head, playground,direction, y, x))
		{
            Clone(playground, backup, 15);
            //DeleteMatrix(backup, 15);
			return -1;
		}

		if (ind == 0)
        {
            Clone(playground, backup, 15);
            //DeleteMatrix(backup, 15);
            return -1;
        }

		return score * multiplier;
	}

	if (direction == "v")
	{
		for (int i = y; i < y + word.size(); i++)
		{
			temp = word[count];

			//cout << "| " << *(*(playground + i) + x) << " - " << word[count] << " |" << endl;

			if ((*(*(playground + i) + x) != " ") && ((*(*(playground + i) + x))[0] != word[count]))
			{
				Clone(playground, backup, 15);
				//DeleteMatrix(backup, 15);

				return -1;
			}

            if (((*(*(playground + i) + x))[0] == word[count]) || (dscore == 0))
            {
                ind = 1;
            }
			
			if (*(*(playground + i) + x) == " ")
			{
				*(*(playground + i) + x) = temp;
				if (HorizontalCheck(head, playground, direction, i, x))
				{
                    Clone(playground, backup, 15);
                    //DeleteMatrix(backup, 15);

					return -1;
				}
				if ((*(*(area + i) + x)) > 0)
				{
					score += LetterScore(temp) * (*(*(area + i) + x));
				}
				else
				{
					score += LetterScore(temp);
					multiplier *= -(*(*(area + i) + x));
				}
			}

			count++;
		}
		if (VerticalCheck(head, playground, direction, y, x))
		{
            Clone(playground, backup, 15);
            //DeleteMatrix(backup, 15);

			return -1;
		}

        if (ind == 0)
        {
            Clone(playground, backup, 15);
            //DeleteMatrix(backup, 15);
            return -1;
        }

		return score * multiplier;
	}
}

void ChangePlayer(player *&active, player *&passive, player *first, player *second)
{
	if (active->id == first->id)
	{
		active = second;
		passive = first;
		return;
	}

	if (active->id == second->id)
	{
		active = first;
		passive = second;
	}
}

void SwapHand(player *&active, letters *&letterList, string swap)
{
	string temp;

	for (int i = 0; i < swap.size(); i++)
	{
		temp = swap[i];
		PushToLetters(letterList, temp, LetterScore(temp));
		DeleteLetter(active->list, temp);
	}

	GiveHand(*active, letterList);
}


int CheckVoid(string **arr, int y, int x)
{
    int i = 0;
	if ((y - 1 >= 0) && (arr[y - 1][x] != " "))
	{
		i = 1;
	}
	if ((y + 1 < 15) && (arr[y + 1][x] != " "))
	{
        i = 1;
	}
	if ((x - 1 >= 0) && (arr[y][x-1] != " "))
	{
        i = 1;
	}
	if ((x + 1 < 15) && (arr[y][x+1] != " "))
	{
        i = 1;
	}

	return i;
}
int VerticalCheck(dictionary *head, string **arr, string direction, int y, int x)
{
	int y1, y2, i;
	i = y;
	string word;
	while (arr[i][x] != " " && i >= 0)
	{
		i--;
	}
	y1 = i;
	i = y;
	while (arr[i][x] != " " && i < 15)
	{
		i++;
	}
	y2 = i;
	if (y2 > y1 + 2)
	{

		for (i = y1 + 1;i < y2;i++)
		{
			word += arr[i][x];
		}
		if (direction == "t")
		{
			reverse(word.begin(), word.end());
		}
		if (Check(head, word))
		{
			cout << "There is no such word in your dictionary\n";
			return 1;
		}
	}
	
	return 0;
}
int HorizontalCheck(dictionary *head, string **arr, string direction, int y, int x)
{
	
	int x1, x2, i;
	i = x;
	string word;
	while (arr[y][i] != " " && i >= 0)
	{
		i--;
	}
	x1 = i;
	i = x;
	while (arr[y][i] != " " && i < 15)
	{
		i++;
	}
	x2 = i;

	if (x2 > x1 + 2)
	{

		for (i = x1 + 1;i < x2;i++)
		{
			word += arr[y][i];
		}
		if (direction == "l")
		{
			reverse(word.begin(), word.end());
		}
		if (Check(head, word))
		{
			cout << "there is no such word in your dictionary\n";
			return 1;
		}
	}

	return 0;
}

