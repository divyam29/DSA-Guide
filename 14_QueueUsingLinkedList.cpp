#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }

    Node()
    {
        next = NULL;
    }
};

class Queue
{
public:
    Node *f;
    Node *b;

    bool isFull()
    {
        Node *ptr = new Node();
        return (ptr == NULL);
    }

    bool isEmpty()
    {
        return (f == NULL);
    }

    void enqueue(int data)
    {
        if (isFull())
        {
            cout << "Queue Overflow!\n";
        }
        else
        {
            Node *ptr = new Node(data);
            if (isEmpty())
            {
                f = ptr;
                b = ptr;
            }
            else
            {
                b->next = ptr;
                b = ptr;
            }
        }
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow!\n";
            return -1;
        }
        else
        {
            Node *temp = f;
            f = f->next;
            int x = temp->data;
            free(temp);
            return x;
        }
    }

    void display()
    {
        Node *ptr = f;
        while (ptr != NULL)
        {
            cout << ptr->data << endl;
            ptr = ptr->next;
        }
    }
};

int main()
{
    Queue *q = new Queue();

    cout << q->isEmpty() << endl;
    cout << q->isFull() << endl;
    cout << endl;

    q->enqueue(1);
    q->enqueue(2);
    q->enqueue(3);
    q->enqueue(4);
    q->enqueue(5);
    cout << endl;

    q->display();
    cout<<endl;

    cout << q->dequeue() << endl;
    cout << q->dequeue() << endl;
    cout << q->dequeue() << endl;
    cout << q->dequeue() << endl;
    cout << q->dequeue() << endl;
    cout << q->dequeue() << endl;
    cout << endl;

    q->enqueue(1);
    q->enqueue(2);
    q->enqueue(3);
    cout << endl;

    cout << q->dequeue() << endl;
    cout << q->dequeue() << endl;
    return 0;
}