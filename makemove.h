#include <string>
#include "dictionary.h"
using namespace std;
#ifndef MAKEMOVE_H
#define MAKEMOVE_H

void give_list(letters *&, string, int);
void make_move(letters *&, letters *&, dictionary *);
void input_letters(letters *, letters *&);
void rand_letter(letters *&, letters *&);

#endif
