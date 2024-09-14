#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int m) : data(m), left(nullptr), right(nullptr) {}
};

void inOrderTraversal(Node *root)
{
    if (root)
    {
        inOrderTraversal(root->left);
        cout << root->data << " ";
        inOrderTraversal(root->right);
    }
}

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

Node *search(Node *root, int data)
{
    if (root == nullptr || root->data == data)
    {
        return root;
    }
    if (data < root->data)
    {
        return search(root->left, data);
    }
    return search(root->right, data);
}

bool canReserve(Node *root, int data)
{
    for (int i = data - 3; i <= data + 3; ++i)
    {
        if (search(root, i) != nullptr)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    Node *root = nullptr;
    int reservation;

    while (true)
    {
        cin >> reservation;
        if (reservation == -1)
        {
            break;
        }

        if (canReserve(root, reservation))
        {
            root = insert(root, reservation);
            inOrderTraversal(root);
            cout << endl;
        }
        else
        {
            cout << "Reservation failed" << endl;
        }
    }

    return 0;
}