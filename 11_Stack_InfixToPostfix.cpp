#include <bits/stdc++.h>
using namespace std;

class Stack
{
public:
    int size;
    int top;
    char *arr;

    Stack(int size)
    {
        this->size = size;
        top = -1;
        arr = new char(size);
    }

    bool isEmpty()
    {
        return (top == -1);
    }

    bool isFull()
    {
        return (top == size - 1);
    }

    void push(char data)
    {
        if (isFull())
        {
            cout << "Stack Overflow" << endl;
        }
        else
        {
            top++;
            arr[top] = data;
        }
    }

    char pop()
    {
        char x;
        // Element at the top
        if (isEmpty())
        {
            cout << "Stack UnderFlow" << endl;
            return -1;
        }
        else
        {
            x = arr[top];
            top--;
        }
        return x;
    }

    char peek(int pos)
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

    char stackTop()
    {
        return arr[top];
    }

    char stackBottom()
    {
        return arr[0];
    }
};

bool isOperator(char x)
{
    return (x == '+' || x == '-' || x == '*' || x == '/');
}

precedence(char x)
{
    if (x == '*' || x == '/')
    {
        return 3;
    }
    else if (x == '+' || x == '-')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

string infixToPosfix(string expr)
{
    Stack *s = new Stack(10000);
    string postfix;
    // cout<<postfix;
    int j = 0;
    // postfix string length counter
    int i = 0;
    while (i <= expr.length())
    {
        if (!isOperator(expr[i]))
        {
            postfix.push_back(expr[i]);
            j++;
            i++;
        }
        else
        {
            if (precedence(expr[i]) > precedence(s->stackTop()))
            {
                s->push(expr[i]);
                // s->display();
                // cout<<endl;
                i++;
            }
            else
            {
                postfix.push_back(s->pop());
                j++;
            }
        }
        // printf("%s\n",postfix);
        // cout<<endl;
        // cout<<postfix<<endl;
    }
    // s->display();
    while (!(s->isEmpty()))
    {
        char x = s->pop();
        printf("%c\n", x);
        postfix.push_back(x);
        j++;
    }
    // cout<<postfix;
    return postfix;
}

int main()
{
    string infix = "x-y/z-k*d";
    // infix[0]='3';
    // cout<<infix;
    // printf("%s", infixToPosfix(infix));
    cout<<infixToPosfix(infix);
    return 0;
}