#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Max heap by default
    priority_queue<int> maxHeap;
    maxHeap.push(50);
    maxHeap.push(40);
    maxHeap.push(60);
    maxHeap.push(30);
    maxHeap.push(20);

    cout << maxHeap.top() << endl;
    maxHeap.pop();
    cout << maxHeap.top() << endl;

    cout << maxHeap.size() << endl;

    if (maxHeap.empty())
    {
        cout << "Empty\n";
    }
    else
    {
        cout << "Not Empty\n\n";
    }

    // To make minHeap
    priority_queue<int, vector<int>, greater<int>> minHeap;

    minHeap.push(50);
    minHeap.push(40);
    minHeap.push(60);
    minHeap.push(30);
    minHeap.push(20);

    cout << minHeap.top() << endl;
    minHeap.pop();
    cout << minHeap.top() << endl;

    cout << minHeap.size() << endl;

    if (minHeap.empty())
    {
        cout << "Empty\n";
    }
    else
    {
        cout << "Not Empty\n\n";
    }

    return 0;
}