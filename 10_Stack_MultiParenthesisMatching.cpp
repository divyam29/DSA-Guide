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

    // int stackTop()
    // {
    //     return arr[top];
    // }

    // int stackBottom()
    // {
    //     return arr[0];
    // }
};

bool matchClosingBracket(char open,char close){
    if(open=='(' && close==')'){
        return true;
    }
    else if(open=='{' && close=='}'){
        return true;
    }
    else if(open=='[' && close==']'){
        return true;
    }
    else{
        return false;
    }
}

bool parenthesisMatch(string expr)
{
    Stack *s = new Stack(1000);
    for (int i = 0; i < expr.length(); i++)
    {
        if (expr[i] == '(' || expr[i] == '{' || expr[i] == '[')
        {
            s->push(expr[i]);
            // s->display();
            // cout<<endl;
        }
        else if (expr[i] == ')' || expr[i] == '}' || expr[i] == ']')
        {
            if (s->isEmpty())
            {
                return false;
            }
            char x = s->pop();
            if (!matchClosingBracket(x,expr[i]))
            {
                return false;
            }
            // s->display();
            // cout<<endl;
        }
    }
    return (s->isEmpty());
}

int main()
{
    string expr = "[4-6]((8){(9-8)})";
    if (parenthesisMatch(expr))
    {
        cout << "The parenthesis is matching\n";
    }
    else
    {
        cout << "The parenthesis is not matching\n";
    }
}