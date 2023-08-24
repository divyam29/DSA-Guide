#include <bits/stdc++.h>
using namespace std;

void display(stack<int> s)
{
    while (!s.empty())
    {
        cout << "| " << s.top() << " |" << endl;
        cout << "-----" << endl;
        s.pop();
    }
    cout << endl;
}

// Insert at bottom of stack
void solve(stack<int> &s, int x)
{
    if (s.empty())
    {
        s.push(x);
        return;
    }
    int t = s.top();
    s.pop();
    solve(s, x);
    s.push(t);
}

stack<int> pushAtBottom(stack<int> &myStack, int x)
{
    solve(myStack, x);
    return myStack;
}

// Reverse a stack
void reverseStack(stack<int> &s)
{
    if (s.empty())
    {
        return;
    }
    int x = s.top();
    s.pop();
    reverseStack(s);
    solve(s, x);
}

// Sort a Stack
void sortedInsert(stack<int> &s, int x)
{
    if (s.empty() || (!s.empty() && s.top() <= x))
    {
        s.push(x);
        return;
    }
    int t = s.top();
    s.pop();
    sortedInsert(s, x);
    s.push(t);
}

void sortStack(stack<int> &s)
{
    if (s.empty())
    {
        return;
    }
    int x = s.top();
    s.pop();
    sortStack(s);
    sortedInsert(s, x);
}

// Next/Prev Smaller/Greater Element
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];
        while (s.top() >= curr)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(curr);
    }
    return ans;
}

int main()
{
    stack<int> s;
    vector<int> v = {5, 2, 9, 7, 3};
    for (auto i : v)
    {
        s.push(i);
    }

    // //add at bottom of stack
    // display(s);
    // pushAtBottom(s, 64);
    // display(s);

    // display(s);
    // reverseStack(s);
    // display(s);

    // display(s);
    // sortStack(s);
    // display(s);


    for(auto it:v){
        cout<<it<<" ";
    }
    cout<<endl;
    vector<int> ans = nextSmallerElement(v, v.size());
    for(auto it:ans){
        cout<<it<<" ";
    }

    return 0;
}