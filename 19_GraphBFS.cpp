#include <bits/stdc++.h>
using namespace std;

class Queue
{
public:
    int graph_size;
    int f;
    int b;
    int *arr;

    Queue(int graph_size)
    {
        this->graph_size = graph_size;
        f = 0;
        b = 0;
        arr = new int(graph_size);
    }

    bool isEmpty()
    {
        return (b == f);
    }

    bool isFull()
    {
        return (b == graph_size - 1);
    }

    void enqueue(int data)
    {
        if (isFull())
        {
            cout << "Queue Overflow!";
        }
        else
        {
            b++;
            arr[b] = data;
        }
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow!";
            return -1;
        }
        else
        {
            f++;
            int x = arr[f];
            return x;
        }
    }

    int peek(int pos)
    {
        return arr[f + pos];
    }
};

// Graph

//  0 -- 1
//  | \  |
//  |  \ |
//  2 -- 3
//  \   /
//  \ /
//   4
//  / \
// 5  6

int main()
{
    Queue *q = new Queue(400);

    // Adjacency Matrix for graph
    int graph_size = 7;
    int a[graph_size][graph_size] = {
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 0, 1, 0, 0, 0},
        {1, 0, 0, 1, 1, 0, 0},
        {1, 1, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0},
    };

    // BFS Implementation

    // Initialize visited array
    int visited[graph_size] = {0, 0, 0, 0, 0, 0, 0};
    // node is the topmost of eq
    int node;

    // Starting node index
    int i = 1;
    cout << i << " ";

    // visited starting index
    visited[i] = 1;

    // Add i to exploration queue (enqueue)
    q->enqueue(i);

    while (!q->isEmpty())
    {
        node = q->dequeue();
        for (int j = 0; j < graph_size; j++)
        {
            // Iterate the adjacency matrix
            // Find the connected node
            // Check if visited
            // If not add to visited and print BFS
            if (a[node][j] == 1 && visited[j] == 0)
            {
                cout << j << " ";
                visited[j] = 1;
                q->enqueue(j);
            }
        }
    }

    return 0;
}