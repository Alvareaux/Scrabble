// ConsoleApplication53.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
using namespace std;



int str_len(char *s)
{
	int i;
	for (i = 0; s[i]; i++)
	{

	}
	
	return i;
}
void sort_bubl(char *s, int N)     // sortirovka puzirkom
{
	int i, j;
	char buf;

	for (i = 0; i < N; i++)              // cikl sortirovki
		for (j = N - 1; j > i; j--)
			if (s[j] < s[j - 1])
			{
				buf = s[j]; //zamena
				s[j] = s[j - 1];
				s[j - 1] = buf;
			}

}

int main()
{
	char s[10], buf;
	int i, j, N, k, q;
	
	cout<<"Vuvesti vse perestanovki\nVvedite stroku s: ";

	cin>>s;
	N = str_len(s);
	cout<<"Dlina stroki N="<< N;
	cout<<endl<<"Vse vozmozhnuye perestenovki: ";

	sort_bubl(s, N);

	while (1) {   // nachinaem perebirat' vse vozmozhnuye perestanovki
		cout<<endl<< s;  // vuvod ocherednoy perestanovki

		for (i = N - 2; i >= 0 && s[i] >= s[i + 1]; i--);  // nahodim samoe pravoe mesto, gde s[i] < s[i+1]
		if (i < 0) break; // uze poluchili vse perestanovki
		for (j = N - 1; s[i] >= s[j]; j--); // nahodim s[j] - naimenshuy element spravo ot s[i] i bolshe ego
			// menyaem s[i] -  s[j]
		buf = s[j];
		s[j] = s[i];
		s[i] = buf;

		// obraschaem el-ntu spravo ot s[i]
		for (k = i + 1, q = N - 1; k < q; k++, q--)
		{
			buf = s[k];
			s[k] = s[q];
			s[q] = buf;
		}

	}


	
	
	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
