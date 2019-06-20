using namespace std;

struct dictionary
{
	string word;
	string mean;
	dictionary *next;
};

struct letters
{
	string word;
	int factor;
	letters *next;
};
struct coords
{
	int x;
	int y;
	coords *next;
};
void fin(dictionary *&);
void give_dictionary(dictionary *&, string );
void fin(letters *&);
void give_letters(letters *&, string, int );
void give_coords(coords *&head);
