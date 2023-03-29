#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void preOrder(Node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(Node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}

void InOrder(Node *root)
{
    if (root != NULL)
    {
        InOrder(root->left);
        cout << root->data << " ";
        InOrder(root->right);
    }
}

int main()
{
    Node *root = new Node(4);
    Node *p1 = new Node(1);
    Node *p2 = new Node(6);
    Node *p11 = new Node(5);
    Node *p12 = new Node(2);

    root->left = p1;
    root->right = p2;
    p1->left = p11;
    p1->right = p12;

    // Tree:
    //      4
    //     / \
    //    1   6
    //   / \
    //  5   2

    preOrder(root);
    cout<<endl;
    postOrder(root);
    cout<<endl;
    InOrder(root);

    return 0;
}