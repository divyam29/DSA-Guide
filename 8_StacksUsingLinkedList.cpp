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

class Stack
{
public:
    Node *top;

    Stack()
    {
        top = NULL;
    }

    bool isEmpty()
    {
        return (top == NULL);
    }
    bool isFull()
    {
        Node *temp = new Node();
        return (temp == NULL);
    }

    void push(int data)
    {
        if (isFull())
        {
            cout << "Stack Overflow!" << endl;
        }
        else
        {
            Node *ptr = new Node(data);
            ptr->next = top;
            top = ptr;
        }
    }

    int pop()
    {
        int x;
        if (isEmpty())
        {
            cout << "Stack Underflow!" << endl;
            x = -1;
        }
        else
        {
            Node *temp = top;
            x = top->data;
            top = top->next;
            delete (temp);
        }
        return x;
    }

    int peek(int pos)
    {
        Node *temp = top;
        for (int i = 0; i < pos - 1 && temp; i++)
        {
            temp = temp->next;
        }
        if (temp)
        {
            return temp->data;
        }
        else
        {
            return -1;
        }
    }

    int stackTop()
    {
        return top->data;
    }

    int stackBottom()
    {
        Node *temp = top;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        return temp->data;
    }

    void display()
    {
        int i=1;
        Node* temp=top;
        while(temp!=NULL)
        {
            cout << "|\t" << peek(i++) << "\t|\n";
            cout << "-----------------\n";
            temp=temp->next;
        }
    }
};

int main()
{
    Stack *s = new Stack();

    cout << s->isEmpty() << endl;
    cout << s->isFull() << endl;
    cout << endl;

    s->push(1);
    s->push(2);
    s->push(3);
    s->push(4);
    s->push(5);
    s->push(6);
    cout << endl;

    cout << s->peek(1) << endl;
    cout << endl;

    s->display();
    cout << endl;

    cout << s->stackBottom() << endl;
    cout << s->stackTop() << endl;
    cout << endl;

    cout << s->pop() << endl;
    cout << s->pop() << endl;
    cout << s->pop() << endl;
    cout << s->pop() << endl;
    cout << s->pop() << endl;
    cout << s->pop() << endl;
    cout << endl;

    return 0;
}