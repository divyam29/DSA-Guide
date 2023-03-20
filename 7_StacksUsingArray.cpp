#include <bits/stdc++.h>
using namespace std;

class Stack
{
public:
    int size;
    int top;
    int *arr;

    Stack(int size)
    {
        this->size = size;
        top = -1;
        arr = new int(size);
    }

    bool isEmpty()
    {
        return (top == -1);
    }

    bool isFull()
    {
        return (top == size - 1);
    }

    bool push(int data)
    {
        if (isFull())
        {
            cout << "Stack Overflow" << endl;
            return false;
        }
        else
        {
            top++;
            arr[top] = data;
            return true;
        }
    }

    int pop()
    {
        int x;
        // Element at the top
        if (isEmpty())
        {
            cout << "Stack UnderFlow" << endl;
            x = -1;
        }
        else
        {
            x = arr[top];
            top--;
        }
        return x;
    }

    int peek(int pos)
    {
        if (top - pos + 1 < 0)
        {
            return -1;
        }
        else
        {
            return arr[top - pos + 1];
        }
    }

    void display()
    {
        for (int i = 1; top - i + 1 >= 0; i++)
        {
            cout << "|\t" << peek(i) << "\t|\n";
            cout << "-----------------\n";
        }
    }

    int stackTop(){
        return arr[top];
    }

    int stackBottom(){
        return arr[0]; 
    }
};

int main()
{
    Stack *s = new Stack(5);

    cout << s->isEmpty() << endl;
    cout << s->isFull() << endl;
    cout << endl;

    s->push(1);
    s->push(2);
    s->push(3);
    s->push(4);
    s->push(51);
    s->push(6);
    cout << endl;

    cout << s->peek(2) << endl;
    cout << endl;

    s->display();
    cout << endl;

    cout<<s->stackBottom()<<endl;
    cout<<s->stackTop()<<endl;
    cout<<endl;

    cout << s->pop() << endl;
    cout << s->pop() << endl;
    cout << s->pop() << endl;
    cout << s->pop() << endl;
    cout << s->pop() << endl;
    cout << s->pop() << endl;
    cout << endl;

    return 0;
}