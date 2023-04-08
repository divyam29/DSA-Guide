#include <bits/stdc++.h>
#define SIZE 10
using namespace std;

int hash_func(int key)
{
    return key % SIZE;
}

int probe(int H[], int key)
{
    int index = hash_func(key);
    int i = 0;
    while (H[hash_func(index + pow(i, 2))] != 0)
    {
        i++;
    }
    return hash_func(index + pow(i, 2));
}

void insert(int H[], int key)
{
    int index = hash_func(key);
    if (H[index] != 0)
    {
        index = probe(H, key);
    }
    H[index] = key;
}

int search(int H[], int key)
{
    int index = hash_func(key);
    int i = 0;
    while (H[hash_func(index + pow(i, 2))] != key && H[hash_func(index + pow(i, 2))] != 0)
    {
        i++;
    }
    if (H[hash_func(index + pow(i, 2))] == 0)
    {
        return -1;
    }
    return hash_func(index + pow(i, 2));
}

void display(int H[])
{
    for (int i = 0; i < SIZE; i++)
    {
        cout << i << "-> " << H[i] << endl;
    }
}

int main()
{
    // Initialize Hash table of size 10 and values 0
    int HT[SIZE] = {0};
    insert(HT, 23);
    insert(HT, 43);
    insert(HT, 13);
    insert(HT, 27);
    // insert(HT, 39);

    display(HT);
    cout << endl;

    cout << search(HT, 23) << endl;
    cout << search(HT, 43) << endl;
    cout << search(HT, 27) << endl;
    cout << search(HT, 13) << endl;
    cout << search(HT, 32) << endl;
    // cout << search(HT, 40) << endl;

    return 0;
}