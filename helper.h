
using namespace std;
#include <iostream>
#include <string>
#include "dictionary/dictionary.h"
#include "lib/additional_func.h"
#ifndef HELPER_H
#define HELPER_H
void helpList(string s, letters *listHead, letters *&helpHead);
void assisstant(string s, letters *listHead, dictionary *dictHead);
void sort_bubl(string s, int n);
void mix(string s, int n, letters *listHead, dictionary *dictHead, letters*&helpHead);
string Minus(string s);
void display(string s, int n);
int CheckCost(letters *head, string s);

#endif //HELPER_H

