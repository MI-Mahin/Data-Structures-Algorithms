#include <iostream>

using namespace std;

struct TreeNode
{
    int value;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) : value(value), left(nullptr), right(nullptr) {}
};

bool isSymmetric(TreeNode *leftSubtree, TreeNode *rightSubtree)
{
    if (leftSubtree == nullptr && rightSubtree == nullptr)
    {
        return true;
    }

    if (leftSubtree == nullptr || rightSubtree == nullptr)
    {
        return false;
    }

    return (leftSubtree->value == rightSubtree->value) &&
           isSymmetric(leftSubtree->left, rightSubtree->right) &&
           isSymmetric(leftSubtree->right, rightSubtree->left);
}

bool isSymmetricTree(TreeNode *root)
{
    if (root == nullptr)
    {
        return true;
    }

    return isSymmetric(root->left, root->right);
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    if (isSymmetricTree(root))
    {
        cout << "Symmetric." << endl;
    }
    else
    {
        cout << "Not symmetric." << endl;
    }

    return 0;
}
