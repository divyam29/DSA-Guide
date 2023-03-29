#include <bits/stdc++.h>
using namespace std;

class CircularQueue
{
public:
    int size;
    int f;
    int b;
    int *arr;

    CircularQueue(int size)
    {
        this->size = size;
        f = 0;
        b = 0;
        arr = new int(size);
    }

    bool isEmpty()
    {
        return (b == f);
    }

    bool isFull()
    {
        return ((b + 1) % size == f);
    }

    void enqueue(int data)
    {
        if (isFull())
        {
            cout << "Queue Overflow!";
        }
        else
        {
            b = (b + 1) % size;
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
            f = (f + 1) % size;
            int x = arr[f];
            return x;
        }
    }

    int peek(int pos)
    {
        return arr[(f + pos) % size];
    }

    // void display()
    // {
    //     for (int i = f + 1; i <= b; i = (i + 1) % size)
    //     {
    //         cout << arr[i] << endl;
    //     }
    // }
};

int main()
{
    CircularQueue *q = new CircularQueue(6);

    cout << q->isEmpty() << endl;
    cout << q->isFull() << endl;
    cout << endl;

    q->enqueue(1);
    q->enqueue(2);
    q->enqueue(3);
    q->enqueue(4);
    q->enqueue(5);
    q->enqueue(6);
    cout << endl;

    cout << q->peek(1) << endl;
    cout << endl;

    // q->display();
    // cout << endl;

    cout << q->dequeue() << endl;
    // cout << q->peek(2) << endl;
    // cout << endl;
    cout << q->dequeue() << endl;
    // cout << q->peek(2) << endl;
    // cout << endl;
    cout << q->dequeue() << endl;
    cout << q->dequeue() << endl;
    // q->display();
    // cout << endl;
    cout << q->dequeue() << endl;
    cout << q->dequeue() << endl;
    cout << endl;

    q->enqueue(1);
    q->enqueue(2);
    q->enqueue(3);

    cout << q->peek(3) << endl;
    cout << endl;
    return 0;
}