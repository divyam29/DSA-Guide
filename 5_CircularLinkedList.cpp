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
};

Node *head;
//? Head is a global variable here

Node *createCLL(int arr[], int n)
{
    Node *tail, *ptr;
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
            head->next = head;
        }
        else
        {
            tail->next = ptr;
            ptr->next = head;
        }
        tail = ptr;
    }
    return head;
}

void displayCLL()
{
    Node *ptr = head;
    do
    {
        cout << ptr->data << " ";
        // cout<<ptr<<" "<<ptr->next<<" "<<ptr->data<<endl;
        ptr = ptr->next;
    } while (ptr != head);
}

void insertBeforeFirst(int data)
{
    Node *ptr = new Node(data);
    Node *temp = head;
    do
    {
        temp = temp->next;
    } while (temp->next != head);
    temp->next = ptr;
    ptr->next = head;
    head = ptr;
}

void insertAtGivenIndex(int index, int data)
{
    Node *ptr = new Node(data);
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

void insertInLL(int index, int data)
{
    Node *ptr = new Node(data);
    Node *temp = head;
    if (index == 0)
    {
        do
        {
            temp = temp->next;
        } while (temp->next != head);
        temp->next = ptr;
        ptr->next = head;
        head = ptr;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            // cout<<temp<<" "<<temp->next<<" "<<temp->data<<endl;
            temp = temp->next;
        }
        if (temp)
        {
            ptr->next = temp->next;
            temp->next = ptr;
        }
    }
}

void deleteNodeCLL(int index)
{
    Node *curr = head;
    if (index == 0)
    {
        do
        {
            curr = curr->next;
        } while (curr->next != head);
        curr->next = head->next;
        delete head;
        head = curr->next;
    }
    else
    {
        Node *prev;
        for (int i = 0; i <= index - 1; i++)
        {
            prev = curr;
            curr = curr->next;
        }
        if (curr)
        {
            prev->next = curr->next;
            delete curr;
        }
    }
}

int main()
{
    int CLL[] = {1, 2, 3, 4, 5};
    int size = sizeof(CLL) / sizeof(int);
    head = createCLL(CLL, size);

    cout << "Original Circular Linked List:\n";
    displayCLL();
    cout << endl;

    // insertBeforeFirst(45);

    // insertAtGivenIndex(6, 45);

    // insertInLL(0,65);
    // insertInLL(2,651);
    // insertInLL(7,652);

    deleteNodeCLL(2);

    cout << "New Linked List:" << endl;
    displayCLL();
    cout << endl;
    return 0;
}