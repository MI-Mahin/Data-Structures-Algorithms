#include <iostream>

using namespace std;

struct Node
{
    int data;
    int size;
    Node *left;
    Node *right;

    Node(int m) : data(m), size(1), left(nullptr), right(nullptr) {}
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
    root->size = 1 + (root->left ? root->left->size : 0) + (root->right ? root->right->size : 0);
    return root;
}

int countReservations(Node *root, int data)
{
    int count = 0;
    while (root != nullptr)
    {
        if (data <= root->data)
        {
            root = root->left;
        }
        else
        {
            count += 1 + (root->left ? root->left->size : 0);
            root = root->right;
        }
    }
    return count;
}

int main()
{
    Node *root = nullptr;
    int numQueries, reservation;

    cout << "Enter the reservations: ";
    while (true)
    {
        cin >> reservation;
        if (reservation == -1)
        {
            break;
        }

        root = insert(root, reservation);
    }

    cout << "Reservation complete. Enter the number of queries: ";
    cin >> numQueries;

    while (numQueries--)
    {
        cin >> reservation;
        int count = countReservations(root, reservation);
        cout << count << endl;
    }

    return 0;
}