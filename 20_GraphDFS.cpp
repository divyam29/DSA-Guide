#include <bits/stdc++.h>
using namespace std;

int a[7][7] = {
    {0, 1, 1, 1, 0, 0, 0},
    {1, 0, 1, 0, 0, 0, 0},
    {1, 0, 0, 1, 1, 0, 0},
    {1, 1, 1, 0, 1, 0, 0},
    {0, 0, 1, 1, 0, 1, 1},
    {0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0, 0},
};
int visited[7] = {0, 0, 0, 0, 0, 0, 0};

// Graph

//  0 -- 1
//  | \  |
//  |  \ |
//  3 -- 2
//  \   /
//  \ /
//   4
//  / \
// 5  6

// This is a recurssive approach
// As recurssion is based on stacks so we dont need to define a stack ADT
// Directly use recurssion to implement stack
void DFS(int start)
{
    cout << start << " ";
    visited[start] = 1;
    for (int j = 0; j < 7; j++)
    {
        if (a[start][j] == 1 && visited[j] == 0)
        {
            DFS(j);
        }
    }
}

int main()
{
    DFS(0);
    return 0;
}