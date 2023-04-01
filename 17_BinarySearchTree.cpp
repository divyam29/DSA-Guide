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

Node *iterativeSearch(Node *root, int key)
{
    while (root != NULL)
    {
        if (key == root->data)
        {
            return root;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return NULL;
}

void insert(Node *root, int data)
{
    Node *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (root->data == data)
        {
            cout << "Element already present\n";
            return;
        }
        else if (root->data > data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    Node *ptr = new Node(data);
    if (prev->data > data)
    {
        prev->left = ptr;
    }
    else
    {
        prev->right = ptr;
    }
}

Node *inOrderPredecessor(Node *root)
{
    if (root->left != NULL)
    {
        root = root->left;
        while (root->right != NULL)
        {
            root = root->right;
        }
        return root;
    }
    else
    {
        return NULL;
    }
}

Node *inOrderSucessor(Node *root)
{
    if (root->right != NULL)
    {
        root = root->right;
        while (root->left != NULL)
        {
            root = root->left;
        }
        return root;
    }
    else
    {
        return NULL;
    }
}

Node *deleteNode(Node *root, int value)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL)
    {
        delete root;
        return NULL;
    }
    if (value < root->data)
    {
        deleteNode(root->left, value);
    }
    else if (value > root->data)
    {
        deleteNode(root->right, value);
    }
    // We reached the node
    else
    {
        Node *iPre = inOrderPredecessor(root);
        if (iPre)
        {
            root->data = iPre->data;
            root->left = deleteNode(root->left, iPre->data);
        }
        else
        {
            Node *iPost = inOrderSucessor(root);
            root->data = iPost->data;
            root->left = deleteNode(root->right, iPost->data);
        }
    }
    return root;
}

int main()
{

    Node *root = new Node(8);

    Node *p1 = new Node(3);
    Node *p11 = new Node(1);
    Node *p12 = new Node(6);
    Node *p121 = new Node(4);
    Node *p122 = new Node(7);

    Node *p2 = new Node(10);
    Node *p22 = new Node(14);
    Node *p221 = new Node(13);

    root->left = p1;
    root->right = p2;
    p1->left = p11;
    p1->right = p12;
    p12->left = p121;
    p12->right = p122;
    p2->right = p22;
    p22->left = p221;

    // Tree:
    //        8
    //     /    \
    //    3     10
    //   / \     \
    //  1   6    14
    //     / \   /
    //    4  7  13

    // Node *root = new Node(5);
    // Node *p1 = new Node(3);
    // Node *p2 = new Node(7);
    // Node *p11 = new Node(2);
    // Node *p12 = new Node(4);
    // Node *p22 = new Node(8);

    // root->left = p1;
    // root->right = p2;
    // p1->left = p11;
    // p1->right = p12;
    // p2->right = p22;

    // Tree:
    //      5
    //     / \
    //    3   7
    //   / \   \
    //  2   4   8

    InOrder(root);
    cout << endl;

    // cout << isBST(root) << endl;

    // Node *ptr = recurssiveSearch(root, 9);
    // if (ptr)
    // {
    //     cout << "Node: " << ptr << " Data: " << ptr->data << endl;
    // }
    // else
    // {
    //     cout << "Not found!";
    // }

    // Node *ptr = iterativeSearch(root, 5);
    // if (ptr)
    // {
    //     cout << "Node: " << ptr << " Data: " << ptr->data << endl;
    // }
    // else
    // {
    //     cout << "Not found!";
    // }

    // insert(root, 6);
    // cout << root->right->left->data << endl;
    // InOrder(root);

    // Node *p = recurssiveSearch(root, 10);
    // cout << inOrderPredecessor(p)->data << endl;

    deleteNode(root, 10);
    Node* ptr=recurssiveSearch(root,13);
    cout<<ptr->left<<endl;
    cout<<ptr->data<<endl;
    cout<<ptr->right->data<<endl;
    InOrder(root);

    return 0;
}