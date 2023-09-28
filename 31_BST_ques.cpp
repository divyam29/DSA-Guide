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
        this->left = NULL;
        this->right = NULL;
    }
};

Node *insert(Node *root, int data)
{
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }
    if (data > root->data)
    {
        root->right = insert(root->right, data);
    }
    else
    {
        root->left = insert(root->left, data);
    }
    return root;
}

void levelOrder(Node *root)
{
    vector<vector<int>> ans;
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
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

int min_ele(Node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root->data;
}

int max_ele(Node *root)
{
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root->data;
}

Node *deleteFromBST(Node *root, int data)
{
    // base case
    if (root == NULL)
        return root;

    if (root->data == data)
    {
        // 0 child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // 1 child
        // left child
        if (root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        // right child
        if (root->left == NULL && root->right != NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }

        // 2 child
        // for this case:
        // 1. either find max element from left subtree or min element from right subtree. (here min from right)
        // 2. then replace root value with min or max value
        // 3. delete that min/max value from either subtrees
        if (root->left != NULL && root->right != NULL)
        {
            int mini = min_ele(root->right);
            root->data = mini;
            root->right = deleteFromBST(root->right, mini);
            return root;
        }
    }
    else if (root->data > data)
    {
        // left part me jao
        root->left = deleteFromBST(root->left, data);
        return root;
    }
    else
    {
        // right part me jao
        root->right = deleteFromBST(root->right, data);
        return root;
    }
}

bool isBST(Node *root, int mini, int maxi)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->data >= mini && root->data <= maxi)
    {
        bool left = isBST(root->left, mini, root->data);
        bool right = isBST(root->right, root->data, maxi);
        return left && right;
    }
    else
    {
        return false;
    }
}

Node *bstFromPreorderUtil(vector<int> &preorder, int mini, int maxi, int &i)
{
    if (i >= preorder.size())
    {
        return NULL;
    }
    if (preorder[i] < mini || preorder[i] > maxi)
    {
        return NULL;
    }
    Node *ptr = new Node(preorder[i]);
    i++;
    ptr->left = bstFromPreorderUtil(preorder, mini, ptr->data, i);
    ptr->right = bstFromPreorderUtil(preorder, ptr->data, maxi, i);
    return ptr;
}
Node *bstFromPreorder(vector<int> &preorder)
{
    int mini = INT_MIN;
    int maxi = INT_MAX;
    int i = 0;
    return bstFromPreorderUtil(preorder, mini, maxi, i);
}

Node *bstFromInorderUtil(int start, int end, vector<int> &inorder)
{
    if (start > end)
    {
        return NULL;
    }
    int mid = (start + end) / 2;
    Node *ptr = new Node(inorder[mid]);
    ptr->left = bstFromInorderUtil(start, mid - 1, inorder);
    ptr->right = bstFromInorderUtil(mid + 1, end, inorder);
    return ptr;
}

Node *bstFromInorder(vector<int> &inorder)
{
    return bstFromInorderUtil(0, inorder.size() - 1, inorder);
}

int main()
{
    // Node *root = NULL;
    // root = insert(root, 10);
    // root = insert(root, 8);
    // root = insert(root, 21);
    // root = insert(root, 7);
    // root = insert(root, 27);
    // root = insert(root, 5);
    // root = insert(root, 4);
    // root = insert(root, 3);
    // levelOrder(root);
    // cout << endl;
    // cout << min_ele(root) << " " << max_ele(root);
    // cout << endl
    //      << endl;
    // deleteFromBST(root, 4);
    // levelOrder(root);
    // cout << endl;
    // cout << isBST(root, INT_MIN, INT_MAX);

    vector<int> preorder{8, 5, 1, 7, 10, 12};
    Node *rootpreorder = bstFromPreorder(preorder);
    levelOrder(rootpreorder);
    cout << endl;

    vector<int> inorder{1, 5, 7, 8, 10, 12};
    Node *rootinorder = bstFromInorder(inorder);
    levelOrder(rootinorder);

    return 0;
}