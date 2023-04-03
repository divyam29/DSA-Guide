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
    return key % 10;
}

// Insertion in hash table
void hashInsert(Node *H[], int key)
{
    int index = hash_func(key);
    insertLL(&H[index], key);
}

void hashDisplay(Node *H[])
{
    for (int i = 0; i < 10; i++)
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
    Node *hash_table[10];

    for (int i = 0; i < 10; i++)
    {
        hash_table[i] = NULL;
    }

    hashInsert(hash_table, 16);
    hashInsert(hash_table, 12);
    hashInsert(hash_table, 25);
    hashInsert(hash_table, 39);
    hashInsert(hash_table, 6);
    hashInsert(hash_table, 122);
    hashInsert(hash_table, 5);
    hashInsert(hash_table, 68);
    hashInsert(hash_table, 75);

    hashDisplay(hash_table);

    cout << endl;

    for (int i = 0; i < 10; i++)
    {
        cout << typeid(hash_table[i]).name() << " " << hash_table[i] << endl;
    }

    cout << endl;

    cout << hashSearch(hash_table, 39) << endl;
    cout << hashSearch(hash_table, 30) << endl;
    cout << hashSearch(hash_table, 122) << endl;

    cout << endl;

    cout << hashDelete(hash_table, 75) << endl;
    cout << hashDelete(hash_table, 69) << endl;
    cout << hashDelete(hash_table, 5) << endl;
    cout << hashDelete(hash_table, 122) << endl;
    cout << hashDelete(hash_table, 6) << endl;
    cout << hashDelete(hash_table, 49) << endl;

    cout << endl;

    hashDisplay(hash_table);
    return 0;
}