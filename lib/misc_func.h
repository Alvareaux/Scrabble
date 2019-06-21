#ifndef SCRABBLE_MISC_FUNC_H
#define SCRABBLE_MISC_FUNC_H

using namespace std;

int **CreateMatrixInt(int n);
string **CreateMatrixString(int n);
int InputFromFile(int **arr, int n, string path);

void DeleteMatrix(int **arr, int n);
void DeleteMatrix(string **arr, int n);
void Clone(string **arr1, string **arr2, int n);

#endif //SCRABBLE_MISC_FUNC_H