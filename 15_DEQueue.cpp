#include <bits/stdc++.h>
using namespace std;

class DEQueue
{
public:
    int size;
    int f;
    int b;
    int *arr;

    DEQueue(int size)
    {
        this->size = size;
        f = -1;
        b = -1;
        arr = new int(size);
    }

    bool isEmpty()
    {
        return (b == f);
    }

    bool isFull()
    {
        return (b == size - 1);
    }

    void enqueueF(int data)
    {
        if (f == -1)
        {
            cout << "Not Possible!\n";
        }
        else
        {
            arr[f] = data;
            f--;
        }
    }

    void enqueueR(int data)
    {
        if (isFull())
        {
            cout << "Queue Overflow!\n";
        }
        else
        {
            b++;
            arr[b] = data;
        }
    }

    int dequeueF()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow!\n";
            return -1;
        }
        else
        {
            f++;
            int x = arr[f];
            return x;
        }
    }

    int dequeueR()
    {
        if (b == -1)
        {
            cout << "Not Possible!\n";
            return -1;
        }
        else
        {
            int x = arr[b];
            b--;
            return x;
        }
    }

    int peek(int pos)
    {
        return arr[f + pos];
    }

    void display()
    {
        cout << "F: " << f << " B: " << b << endl;
        for (int i = f + 1; i <= b; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl
             << endl;
    }
};

int main()
{
    DEQueue *q = new DEQueue(5);

    cout << q->isEmpty() << endl;
    cout << q->isFull() << endl;
    cout << endl;

    q->enqueueR(1);
    q->enqueueR(2);
    q->enqueueR(3);
    q->enqueueR(4);
    q->enqueueR(5);

    q->display();

    q->dequeueR();
    q->dequeueR();
    q->dequeueR();
    q->dequeueR();
    q->dequeueR();
    q->dequeueR();

    q->display();

    // q->dequeueF();
    // q->dequeueF();
    // q->dequeueF();
    // q->dequeueF();
    // q->dequeueF();


    // q->display();

    // q->enqueueF(1);
    // q->enqueueF(2);
    // q->enqueueF(3);
    // q->enqueueF(4);
    // q->enqueueF(4);
    // q->enqueueF(4);

    // q->display();

    return 0;
}