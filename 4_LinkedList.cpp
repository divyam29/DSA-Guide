#include <bits/stdc++.h>
using namespace std;
#define MININT -2147483648

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
};

Node *createLL(int arr[], int n)
{
    Node *head, *tail, *ptr;
    head = NULL;
    if (n <= 0)
    {
        cout << "Insufficient Elements in array!!";
        return NULL;
    }
    for (int i = 0; i < n; i++)
    {
        ptr = new Node(arr[i]);
        if (head == NULL)
        {
            head = ptr;
        }
        else
        {
            tail->next = ptr;
        }
        tail = ptr;
    }
    return head;
}

void displayLL(Node *head)
{
    Node *temp;
    temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void recursiveDisplayLL(Node *head)
{
    if (head != NULL)
    {
        cout << head->data << " ";
        recursiveDisplayLL(head->next);
    }
}

int countNodesLL(Node *head)
{
    Node *temp;
    int count = 0;
    temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

int recursiveCountNodesLL(Node *head)
{
    if (head == NULL)
    {
        return 0;
    }
    else
    {
        return recursiveCountNodesLL(head->next) + 1;
    }
}

int sumOfElementsLL(Node *head)
{
    Node *temp;
    int sum = MININT;
    temp = head;
    while (temp != NULL)
    {
        sum += temp->data;
        temp = temp->next;
    }
    return sum;
}

int recursiveSumofElementsLL(Node *head)
{
    if (head == NULL)
    {
        return 0;
    }
    else
    {
        return recursiveSumofElementsLL(head->next) + head->data;
    }
}

int maxElementInLL(Node *head)
{
    int max = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        if (max < temp->data)
        {
            max = temp->data;
        }
        temp = temp->next;
    }
    return max;
}

Node *linearSearchLL(Node *head, int key)
{
    Node *ptr = head;
    while (ptr != NULL)
    {
        if (key == ptr->data)
        {
            return ptr;
        }
        ptr = ptr->next;
    }
    return NULL;
}

Node *insertBeforeFirst(Node *head, int data)
{
    Node *ptr = new Node(data);
    ptr->next = head;
    head = ptr;
    return head;
}

void insertAfterAnyNode(Node *head, int index, int data)
{
    Node *ptr = new Node(data);
    Node *temp = head;
    for (int i = 0; i < index - 1; i++)
    {
        temp = temp->next;
    }
    ptr->next = temp->next;
    temp->next = ptr;
}

Node *insertInLL(Node *head, int index, int data)
{
    Node *ptr = new Node(data);
    if (index == 0)
    {
        ptr->next = head;
        head = ptr;
        return head;
    }
    else
    {
        Node *temp = head;
        for (int i = 0; i < index - 1; i++)
        {
            temp = temp->next;
        }
        if (temp)
        {
            ptr->next = temp->next;
            temp->next = ptr;
        }
    }
    return head;
}

Node *insertInSortedLL(Node *head, int data)
{
    Node *ptr = new Node(data);
    Node *prev = NULL;
    Node *curr = head;
    if (curr == NULL)
    {
        head = ptr;
        return head;
    }
    else
    {
        while (curr && curr->data < data)
        {
            prev = curr;
            curr = curr->next;
        }
        if (curr == head)
        {
            ptr->next = head;
            head = ptr;
        }
        else
        {
            ptr->next = prev->next;
            prev->next = ptr;
        }
    }
    return head;
}

Node *deleteNodeLL(Node *head, int index)
{
    int x = -1;
    Node *curr = head;
    if (index == 0)
    {
        head = head->next;
        x = curr->data;
        delete curr;
    }
    else
    {
        Node *prev = NULL;
        for (int i = 0; i <= index - 1; i++)
        {
            prev = curr;
            curr = curr->next;
        }
        if (curr)
        {
            prev->next = curr->next;
            x = curr->data;
            delete curr;
        }
    }
    return head;
}

int main()
{
    // int LL[] = {1, 2, 3, 4, 5};
    // int size = sizeof(LL) / sizeof(int);
    // Node *head = createLL(LL, size);

    // cout << "Original Linked List:\n";
    // displayLL(head);
    // cout << endl;
    // recursiveDisplayLL(head);

    // cout << "No. of Nodes in LL: " << countNodesLL(head);
    // cout << "No. of Nodes in LL: " << recursiveCountNodesLL(head);

    // cout << "Sum of Nodes in LL: " << sumOfElementsLL(head);
    // cout << "Sum of Nodes in LL: " << recursiveSumofElementsLL(head);

    // cout<<"Max Element in LL: "<<maxElementInLL(head);

    // if (linearSearchLL(head, 52))
    // {
    //     cout << "Element found...";
    // }
    // else
    // {
    //     cout << "Element not found..";
    // }

    // head = insertBeforeFirst(head, 15);
    // cout << "New Linked List:\n";
    // displayLL(head);
    // cout << endl;

    // insertAfterAnyNode(head, 1, 15);
    // cout << "New Linked List:\n";
    // displayLL(head);
    // cout << endl;

    // head = insertInLL(head, 2, 15);
    // cout << "New Linked List:\n";
    // displayLL(head);
    // cout << endl;

    // head = insertInSortedLL(head, -436);
    // cout << "New Linked List:\n";
    // displayLL(head);
    // cout << endl;

    // head = deleteNodeLL(head, 4);
    // cout << "New Linked List:\n";
    // displayLL(head);
    // cout << endl;

    int LL[] = {4, 2, 2, 3};
    int size = sizeof(LL) / sizeof(int);
    Node *head = createLL(LL, size);

    vector<int> vct;
    Node *temp = head;
    while (temp != NULL)
    {
        vct.push_back(temp->data);
        temp = temp->next;
    }
    int j = 0;
    int l = vct.size();
    vector<int> ans(l);
    for (int i = 0; i <= (l / 2) - 1; i++)
    {
        int k=l-1-i;
        ans[j] = vct[i] + vct[k];
        cout << ans[j] << endl;
        j++;
    }

    return 0;
}