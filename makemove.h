#include <string>
#include "dictionary.h"
using namespace std;

void give_list(letters *&listHead, string word, int factor);
void make_move(letters *&listHead, letters *&letterHead, dictionary *dicHead);
void input_letters(letters *listHead, letters *&wordHead);
void rand_letter(letters *&listHead, letters *&letterHead);
