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

bool isBST(Node *root)
{
    static Node *prev = NULL;
    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else
    {
        return true;
    }
}

Node *recurssiveSearch(Node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == key)
    {
        return root;
    }
    else if (root->data > key)
    {
        return recurssiveSearch(root->left, key);
    }
    else
    {
        return recurssiveSearch(root->right, key);
    }
}

int main()
{
    Node *root = new Node(5);
    Node *p1 = new Node(3);
    Node *p2 = new Node(7);
    Node *p11 = new Node(2);
    Node *p12 = new Node(4);
    Node *p22 = new Node(8);

    root->left = p1;
    root->right = p2;
    p1->left = p11;
    p1->right = p12;
    p2->right = p22;

    // Tree:
    //      5
    //     / \
    //    3   7
    //   / \   \
    //  2   4   8

    InOrder(root);
    cout << endl;

    cout << isBST(root) << endl;

    Node *ptr = recurssiveSearch(root, 9);
    if (ptr)
    {
        cout << "Node: " << ptr << " Data: " << ptr->data << endl;
    }
    else
    {
        cout << "Not found!";
    }
    return 0;
}