#include <bits/stdc++.h>
using namespace std;

void print(set<double> &m)
{
    cout << m.size() << endl;
    for (auto &pr : m)
    {
        cout << pr << endl;
    }
}
int main()
{
    stack<int> s;
    s.push(5);
    s.push(6);
    s.push(53);
    s.push(52);
    s.push(51);
    cout<<s.top();
    // cout<<s.pop();
    cout<<s.top();
    cout<<s.empty();
    cout<<s.end()
    // cout<<s.full();
}