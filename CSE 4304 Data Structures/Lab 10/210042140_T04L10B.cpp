#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node *insert(Node *root, int data)
{
    if (root == nullptr)
    {
        return new Node(data);
    }

    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }

    return root;
}

void findPath(Node *root, int x, int y, vector<int> &path)
{
    while (root != nullptr)
    {
        path.push_back(root->data);

        if (root->data > y)
        {
            root = root->left;
        }
        else if (root->data < x)
        {
            root = root->right;
        }
        else
        {
            break;
        }
    }
}

int countNodesInPath(const vector<int> &path, int x, int y)
{
    int count = 0;
    for (int node : path)
    {
        count++;
        if (node == x || node == y)
        {
            break;
        }
    }
    return count;
}

int main()
{
    Node *root = nullptr;
    int num;

    while (true)
    {
        cin >> num;
        if (num == -1)
        {
            break;
        }
        root = insert(root, num);
    }

    while (true)
    {
        int x, y;
        cin >> x >> y;
        if (x == -1 || y == -1)
        {
            break;
        }

        vector<int> path;
        findPath(root, x, y, path);

        for (int node : path)
        {
            cout << node << " ";
        }
        cout << endl;

        int distance = countNodesInPath(path, x, y);
        cout << distance << endl;
    }

    return 0;
}