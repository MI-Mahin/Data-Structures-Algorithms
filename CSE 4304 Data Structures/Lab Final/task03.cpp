#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isValidBST(TreeNode *root)
{
    if (root == NULL)
        return true;
    if (root->left != NULL && root->left->val >= root->val)
        return false;
    if (root->right != NULL && root->right->val <= root->val)
        return false;
    return isValidBST(root->left) && isValidBST(root->right);
}

int main()
{
    // TreeNode *root = new TreeNode(2);
    // root->left = new TreeNode(1);
    // root->right = new TreeNode(3);

    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(6);

    if (isValidBST(root))
        cout << "True" << endl;
    else
        cout << "False" << endl;
}
