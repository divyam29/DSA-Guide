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
    while (H[hash_func(index + i)] != 0)
    {
        i++;
    }
    return hash_func(index + i);
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
    while (H[hash_func(index + i)] != key && H[hash_func(index + i)] != 0)
    {
        i++;
    }
    if (H[hash_func(index + i)] == 0)
    {
        return -1;
    }
    return hash_func(index + i);
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
    insert(HT, 12);
    insert(HT, 25);
    insert(HT, 35);
    insert(HT, 29);
    insert(HT, 39);

    display(HT);
    cout << endl;

    cout << search(HT, 25) << endl;
    cout << search(HT, 35) << endl;
    cout << search(HT, 12) << endl;
    cout << search(HT, 29) << endl;
    cout << search(HT, 39) << endl;
    cout << search(HT, 40) << endl;

    return 0;
}