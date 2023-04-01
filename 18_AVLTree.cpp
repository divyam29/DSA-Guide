#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    int height;

    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
        // While creating a node it becomes a leaf node and leaf nodes always have height =1
        height = 1;
    }
};

int getHeight(Node *ptr)
{
    if (ptr == NULL)
    {
        return 0;
    }
    else
    {
        return ptr->height;
    }
}

int getBalanceFactor(Node *ptr)
{
    if (ptr == NULL)
    {
        return 0;
    }
    return getHeight(ptr->left) - getHeight(ptr->right);
}

// Initially y was root node
Node *rightRotate(Node *y)
{
    // Before rotation
    Node *x = y->left;
    Node *T2 = x->right;

    // After Rotation
    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;

    //  New root node is x
    return x;
}

// Initially x was root node
Node *leftRotate(Node *x)
{
    // Before rotation
    Node *y = x->right;
    Node *T2 = y->left;

    // After Rotation
    y->left = x;
    x->right = T2;

    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;

    //  New root node is y
    return y;
}

Node *insertNode(Node *root, int data)
{
    Node *ptr = new Node(data);
    if (root == NULL)
    {
        return ptr;
    }

    if (data < root->data)
    {
        root->left = insertNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insertNode(root->right, data);
    }
    root->height = max(getHeight(root->right), getHeight(root->left)) + 1;

    int bf = getBalanceFactor(root);

    // Left Left Case
    if (bf > 1 && data < root->left->data)
    {
        return rightRotate(root);
    }

    // Right Right Case
    else if (bf < -1 && data > root->right->data)
    {
        return leftRotate(root);
    }

    // Left Right Case
    else if (bf > 1 && data > root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Left Case
    else if (bf < -1 && data < root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

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
    Node *root = NULL;

    root = insertNode(root, 8);
    root = insertNode(root, 3);
    root = insertNode(root, 1);
    root = insertNode(root, 6);
    root = insertNode(root, 4);
    root = insertNode(root, 7);
    root = insertNode(root, 10);
    root = insertNode(root, 14);
    root = insertNode(root, 13);

    preOrder(root);
    cout << endl;
    InOrder(root);
    return 0;
}