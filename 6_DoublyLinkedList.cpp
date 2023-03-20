#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *prev, *next;

    Node(int data)
    {
        this->data = data;
        prev = NULL;
        next = NULL;
    }
};

Node *head;

Node *createDLL(int arr[], int size)
{
    Node *ptr, *tail;
    head = NULL;
    if (size <= 0)
    {
        cout << "Insufficient Elements in array!!";
        return NULL;
    }
    for (int i = 0; i < size; i++)
    {
        ptr = new Node(arr[i]);
        if (head == NULL)
        {
            head = ptr;
        }
        else
        {
            tail->next = ptr;
            ptr->prev = tail;
        }
        tail = ptr;
    }
    return head;
}

void displayCLL()
{
    Node *temp;
    temp = head;
    int i = 0;
    while (temp != NULL)
    {
        cout << i++ << ". " << temp << ": " << temp->prev << " " << temp->data << " " << temp->next << " " << endl;
        // cout << temp->data << " ";
        temp = temp->next;
    }
}

void insertBeforeFirst(int data)
{
    Node *ptr = new Node(data);
    head->prev = ptr;
    ptr->next = head;
    head = ptr;
}

void insertatGivenIndex(int index, int data)
{
    Node *ptr = new Node(data);
    Node *temp = head;
    for (int i = 0; i < index - 1; i++)
    {
        temp = temp->next;
    }
    if (temp)
    {
        ptr->prev = temp;
        ptr->next = temp->next;
        if (temp->next)
        {
            temp->next->prev = ptr;
        }
        temp->next = ptr;
    }
}

void insertInLL(int index, int data)
{
    Node *ptr = new Node(data);
    if (index == 0)
    {
        head->prev = ptr;
        ptr->next = head;
        head = ptr;
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
            ptr->prev = temp;
            ptr->next = temp->next;
            if (temp->next)
            {
                temp->next->prev = ptr;
            }
            temp->next = ptr;
        }
    }
}

void deleteNodeLL(int index) {
    Node* temp=head;
    if(index<0){
        cout<<"Unsupported Value!";
    }
    else if(index==0){
        temp=temp->next;
        temp->prev=NULL;
        delete head;
        head=temp;
    }
    else{
        for(int i=0;i<=index-1;i++){
            if(temp)
            temp=temp->next;
            else
            return;
        }
        if(temp){
            temp->prev->next=temp->next;
            if(temp->next){
            temp->next->prev=temp->prev;
            }
            delete temp;
        }
    }
}

int main()
{
    int DLL[] = {1, 2, 3, 4, 5};
    int size = sizeof(DLL) / sizeof(int);
    head = createDLL(DLL, size);

    cout << "Original Doubly Linked List:\n";
    displayCLL();
    cout << endl;

    // insertBeforeFirst(45);

    // insertatGivenIndex(2, 45);

    // insertInLL(0,65);
    // insertInLL(2,651);
    // insertInLL(7,652);

    deleteNodeLL(0);
    deleteNodeLL(2);
    deleteNodeLL(4);

    cout << "New Linked List:" << endl;
    displayCLL();
    cout << endl;
    return 0;
}