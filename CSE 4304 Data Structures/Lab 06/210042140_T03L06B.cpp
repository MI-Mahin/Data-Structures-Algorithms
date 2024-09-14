#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
    int value;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) : value(value), left(nullptr), right(nullptr) {}
};

void printPaths(TreeNode *root, vector<int> &path, int pathLength)
{
    if (root == nullptr)
    {
        return;
    }

    path.push_back(root->value);
    pathLength += 1;

    if (root->left == nullptr && root->right == nullptr)
    {
        cout << "Path: ";
        for (int i = 0; i < path.size(); i++)
        {
            if (i > 0)
            {
                cout << " -> ";
            }
            cout << path[i];
        }
        cout << ", Length: " << pathLength << endl;
    }
    else
    {
        printPaths(root->left, path, pathLength);
        printPaths(root->right, path, pathLength);
    }

    path.pop_back();
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    vector<int> path;
    int pathLength = 0;

    cout << "Paths :" << endl;
    printPaths(root, path, pathLength);

    return 0;
}
