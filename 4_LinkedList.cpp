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

int maxElementInLL(Node* head){
    int max=0;
    Node* temp=head;
    while(temp!=NULL){
        if(max<temp->data){
            max=temp->data;
        }
        temp=temp->next;
    }
    return max;
}

int main()
{
    int LL[] = {-2221, -324232, 3, 329642974, 5, 32432146, 7, 8, 4325249, 0};
    int size = sizeof(LL) / sizeof(int);
    Node *head = createLL(LL, size);

    cout << "Original Linked List:\n";
    displayLL(head);
    cout << endl;
    // recursiveDisplayLL(head);

    // cout << "No. of Nodes in LL: " << countNodesLL(head);
    // cout << "No. of Nodes in LL: " << recursiveCountNodesLL(head);

    // cout << "Sum of Nodes in LL: " << sumOfElementsLL(head);
    // cout << "Sum of Nodes in LL: " << recursiveSumofElementsLL(head);

    cout<<"Max Element in LL: "<<maxElementInLL(head);

    return 0;
}