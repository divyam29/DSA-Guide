#include <bits/stdc++.h>
#define SIZE 10
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

// We store address of heads of hash indexes in the hash table
// Thats why Node** head
void insertLL(Node **head, int data)
{
    Node *ptr = new Node(data);
    // *head accesses the data on address of hashindex
    // We require address of hashindex as we need to assign value at that index as well
    if (*head == NULL)
    {
        *head = ptr;
    }
    else
    {
        Node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = ptr;
    }
}

// Here without **head can also work
void displayLL(Node **head)
{
    Node *temp = *head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node *searchLL(Node **head, int key)
{
    Node *temp = *head;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

int deleteLL(Node **head, int key)
{
    int x = -1;
    Node *ptr = searchLL(head, key);
    if (ptr)
    {
        if (ptr == *head)
        {
            *head = ptr->next;
        }
        else
        {
            Node *prev = *head;
            while (prev->next != ptr)
            {
                prev = prev->next;
            }
            prev->next = ptr->next;
        }
        x = ptr->data;
        delete ptr;
    }
    return x;
}

// Linked list functions end
// -------------------------------------------------------------------------------

// Hash function
int hash_func(int key)
{
    return key % SIZE;
}

// Insertion in hash table
void hashInsert(Node *H[], int key)
{
    int index = hash_func(key);
    insertLL(&H[index], key);
}

void hashDisplay(Node *H[])
{
    for (int i = 0; i < SIZE; i++)
    {
        cout << i << "-> ";
        displayLL(&H[i]);
        cout << endl;
    }
}

Node *hashSearch(Node *H[], int key)
{
    int index = hash_func(key);
    Node *ptr = searchLL(&H[index], key);
    return ptr;
}

int hashDelete(Node *H[], int key)
{
    int index = hash_func(key);
    int x = deleteLL(&H[index], key);
    return x;
}

int main()
{
    // Initialize hash table
    Node *HT[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        HT[i] = NULL;
    }

    hashInsert(HT, 16);
    hashInsert(HT, 12);
    hashInsert(HT, 25);
    hashInsert(HT, 39);
    hashInsert(HT, 6);
    hashInsert(HT, 122);
    hashInsert(HT, 5);
    hashInsert(HT, 68);
    hashInsert(HT, 75);

    hashDisplay(HT);

    cout << endl;

    for (int i = 0; i < SIZE; i++)
    {
        cout << typeid(HT[i]).name() << " " << HT[i] << endl;
    }

    cout << endl;

    cout << hashSearch(HT, 39) << endl;
    cout << hashSearch(HT, 30) << endl;
    cout << hashSearch(HT, 122) << endl;

    cout << endl;

    cout << hashDelete(HT, 75) << endl;
    cout << hashDelete(HT, 69) << endl;
    cout << hashDelete(HT, 5) << endl;
    cout << hashDelete(HT, 122) << endl;
    cout << hashDelete(HT, 6) << endl;
    cout << hashDelete(HT, 49) << endl;

    cout << endl;

    hashDisplay(HT);
    return 0;
}