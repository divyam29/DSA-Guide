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

void MorrisTraversalInorder(Node *root)
{
    Node *current, *pre;

    if (root == NULL)
        return;

    current = root;
    while (current != NULL)
    {
        if (current->left == NULL)
        {
            cout << current->data << " ";
            current = current->right;
        }
        else
        {
            pre = current->left;
            while (pre->right != NULL && pre->right != current)
                pre = pre->right;

            if (pre->right == NULL)
            {
                pre->right = current;
                current = current->left;
            }

            else
            {
                pre->right = NULL;
                cout << current->data << " ";
                current = current->right;
            }
        }
    }
}

vector<vector<int>> levelOrder(Node *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
        return ans;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        vector<int> lvl;
        int sz = q.size();
        while (sz--)
        {
            Node *temp = q.front();
            q.pop();
            lvl.push_back(temp->data);
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
        ans.push_back(lvl);
    }
    return ans;
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
    cout << endl;
    postOrder(root);
    cout << endl;
    InOrder(root);
    cout << endl;
    MorrisTraversalInorder(root);
    cout << endl;
    vector<vector<int>> lvlOrder = levelOrder(root);
    for (auto i : lvlOrder)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}