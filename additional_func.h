#include <string>
#include "dictionary.h"
using namespace std;
#ifndef ADDITIONAL_FUNC_H
#define ADDITIONAL_FUNC_H
void delete_letter(letters *&head, letters *x);
void letters_output(letters *head);
int list_counter(letters *head);
int check(dictionary *head, letters *wordHead);
int check(dictionary *head, string word);
#endif


