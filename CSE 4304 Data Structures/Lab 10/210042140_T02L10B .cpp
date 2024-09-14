#include <iostream>

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

int findSecondLargest(Node *root)
{
    Node *current = root;

    if (current == nullptr || (current->left == nullptr && current->right == nullptr))
    {
        cout << "Tree is empty or has only one node" << endl;
    }

    if (current->right == nullptr && current->left != nullptr)
    {
        current = current->left;

        while (current->right != nullptr)
        {
            current = current->right;
        }

        return current->data;
    }

    // For general case
    while (current->right->right != nullptr)
    {
        current = current->right;
    }

    return current->data;
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

    cout << findSecondLargest(root) << endl;

    return 0;
}