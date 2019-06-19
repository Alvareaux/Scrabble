#include <iostream>
#include <string>

using namespace std;

int **CreateMatrix(int n);

int main()
{
    int **playground = CreateMatrix(15);
    int **area = CreateMatrix(15);
    return 0;
}

int **CreateMatrix(int n)
{
    int **arr = new int*[n];
    for (int i = 0; i < n; i++)
    {
        *(arr + i) = new int[n];
    }

    return arr;
}