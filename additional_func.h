#include <string>
#include "dictionary.h"
using namespace std;

void delete_letter(letters *&head, letters *x);
void letters_output(letters *head);
int list_counter(letters *head);
int check(dictionary *head, letters *wordHead);