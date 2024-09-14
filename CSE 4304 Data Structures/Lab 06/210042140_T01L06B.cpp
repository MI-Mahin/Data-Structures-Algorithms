#include <iostream>

using namespace std;

struct TreeNode
{
    int value;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) : value(value), left(nullptr), right(nullptr) {}
};

TreeNode *insert(TreeNode *root, int value, int parent, int child)
{
    if (root == nullptr)
    {
        return new TreeNode(value);
    }

    if (root->value == parent)
    {
        if (child == 1)
        {
            root->left = insert(root->left, value, parent, child);
        }
        else if (child == 2)
        {
            root->right = insert(root->right, value, parent, child);
        }
    }
    else if (root->value > parent)
    {
        root->left = insert(root->left, value, parent, child);
    }
    else
    {
        root->right = insert(root->right, value, parent, child);
    }

    return root;
}

void preorderTraversal(TreeNode *root)
{
    if (root)
    {
        cout << root->value << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

TreeNode *searchNode(TreeNode *root, int value)
{
    if (root == nullptr || root->value == value)
    {
        return root;
    }

    TreeNode *leftResult = searchNode(root->left, value);
    if (leftResult)
    {
        return leftResult;
    }

    return searchNode(root->right, value);
}

int height(TreeNode *root)
{
    if (root == nullptr)
    {
        return -1;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return max(leftHeight, rightHeight) + 1;
}

int main()
{
    TreeNode *root = nullptr;

    int n = 7;
    int value[] = {1, 2, 3, 5, 4, 6, 7};
    int parent[] = {0, 1, 1, 2, 2, 3, 3};
    int child[] = {0, 1, 2, 2, 1, 1, 2};

    for (int i = 0; i < n; i++)
    {
        root = insert(root, value[i], parent[i], child[i]);
    }

    cout << "Preorder traversal : " << endl;
    preorderTraversal(root);

    return 0;
}
