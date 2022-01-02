// 1-1 Test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// 
// prepocessor declaration for header files
#include <iostream>

// prototypes to let the compiler know funtions will eventually be defined
bool quickFind(int* p, int* q, int* id);
bool quickUnion(int* p, int* q, int* id);
bool weightedQuickUnion(int* p, int* q, int* id, int* sz);

// allows using shortened names from the std namespace (i.e. cin vs std::cin)
using namespace std;

// Size of the arrays
static const int N = 10;

int main()
{
    int i, p, q, id[N], sz[N];
    char algorithm;
    cout << "QuickFind(f), QuickUnion(u), WeightedQuickUnion(w)? ";
    cin >> algorithm;
    for (i = 0; i < N; i++)
    {
        id[i] = i;
        sz[i] = 1;
    }
    while (cin >> p >> q)
    {
        if (algorithm == 'f')
        {
            if (!quickFind(&p, &q, id)) continue;
        }
        else if (algorithm == 'u')
        {
            if (!quickUnion(&p, &q, id)) continue;
        }
        else
        {
            if (!weightedQuickUnion(&p, &q, id, sz)) continue;
        }
        cout << " " << p  << " " << q  << endl;
        for (int j = 0; j < N; j++) cout << id[j] << " ";
        cout << endl;
    }
}

bool quickFind(int* p, int* q, int* id)
{
    int t = id[*p];
    if (t == id[*q]) return false;
    for (int i = 0; i < N; i++)
        if (id[i] == t) id[i] = id[*q];
    return true;
}

bool quickUnion(int* p, int* q, int* id)
{
    int i, j;
    for ( i = *p;  i != id[i]; i = id[i]);
    for ( j = *q;  j != id[j]; j = id[j]);
    if (i == j) return false;
    id[i] = j;
    return true;
}

bool weightedQuickUnion(int* p, int* q, int* id, int* sz)
{
    int i, j;
    for (i = *p; i != id[i]; i = id[i]);
    for (j = *q; j != id[j]; j = id[j]);
    if (i == j) return false;
    if (sz[i] < sz[j])
    {
        id[i] = j; sz[j] += sz[i];
    }
    else { id[j] = i; sz[i] += sz[j]; }
    return true;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
