#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;
    int height;
    Node(int value) : data(value), height(1), left(nullptr), right(nullptr) {}
};

class BST
{
private:
    Node* root;

    int getHeight(Node* node)
    {
        return node ? node->height : 0;
    }

    int getBalance(Node* node)
    {
        return node ? getHeight(node->left) - getHeight(node->right) : 0;
    }

    Node* leftRotate(Node* x)
    {
        Node* y = x->right;
        Node* T = y->left;

        y->left = x;
        x->right = T;

        x->height = 1 + max(getHeight(x->left), getHeight(x->right));
        y->height = 1 + max(getHeight(y->left), getHeight(y->right));

        return y;
    }

    Node* rightRotate(Node* y)
    {
        Node* x = y->left;
        Node* T = x->right;

        x->right = y;
        y->left = T;

        x->height = 1 + max(getHeight(x->left), getHeight(x->right));
        y->height = 1 + max(getHeight(y->left), getHeight(y->right));

        return x;
    }

    Node* insert(Node* current, int data)
    {
        if (current == nullptr)
        {
            return new Node(data);
        }

        if (data < current->data)
        {
            current->left = insert(current->left, data);
        }
        else if (data > current->data)
        {
            current->right = insert(current->right, data);
        }
        else
        {
            cout << "Duplicate value " << data << " not inserted." << endl;
            return current;
        }

        current->height = 1 + max(getHeight(current->left), getHeight(current->right));
        int balance = getBalance(current);

        if (balance > 1 && data < current->left->data)
        {
            return rightRotate(current);
        }
        if (balance < -1 && data > current->right->data)
        {
            return leftRotate(current);
        }
        if (balance > 1 && data > current->left->data)
        {
            current->left = leftRotate(current->left);
            return rightRotate(current);
        }
        if (balance < -1 && data < current->right->data)
        {
            current->right = rightRotate(current->right);
            return leftRotate(current);
        }

        return current;
    }

    Node* deleteNode(Node* current, int data)
    {
        if (current == nullptr)
        {
            return nullptr;
        }

        if (data < current->data)
        {
            current->left = deleteNode(current->left, data);
        }
        else if (data > current->data)
        {
            current->right = deleteNode(current->right, data);
        }
        else
        {
            if (current->left == nullptr && current->right == nullptr)
            {
                delete current;
                return nullptr;
            }
            else if (current->left == nullptr)
            {
                Node* temp = current->right;
                delete current;
                return temp;
            }
            else if (current->right == nullptr)
            {
                Node* temp = current->left;
                delete current;
                return temp;
            }
            else
            {
                Node* temp = findMin(current->right);
                current->data = temp->data;
                current->right = deleteNode(current->right, temp->data);
            }
        }

        current->height = 1 + max(getHeight(current->left), getHeight(current->right));
        int balance = getBalance(current);

        if (balance > 1 && getBalance(current->left) >= 0)
        {
            return rightRotate(current);
        }
        else if (balance < -1 && getBalance(current->right) <= 0)
        {
            return leftRotate(current);
        }
        else if (balance > 1 && getBalance(current->left) < 0)
        {
            current->left = leftRotate(current->left);
            return rightRotate(current);
        }
        else if (balance < -1 && getBalance(current->right) > 0)
        {
            current->right = rightRotate(current->right);
            return leftRotate(current);
        }

        return current;
    }

    bool search(Node* current, int value)
    {
        if (current == nullptr)
        {
            return false;
        }

        if (value == current->data)
        {
            return true;
        }
        else if (value < current->data)
        {
            return search(current->left, value);
        }
        else
        {
            return search(current->right, value);
        }
    }

    void inOrder(Node* current)
    {
        if (current != nullptr)
        {
            inOrder(current->left);
            cout << current->data << " ";
            inOrder(current->right);
        }
    }

    Node* findMin(Node* current)
    {
        while (current && current->left != nullptr)
        {
            current = current->left;
        }
        return current;
    }

public:
    BST() : root(nullptr) {}

    void insert(int value)
    {
        root = insert(root, value);
    }

    void deleteNode(int value)
    {
        root = deleteNode(root, value);
    }

    bool search(int value)
    {
        return search(root, value);
    }

    void inOrder()
    {
        inOrder(root);
        cout << endl;
    }
};

int main()
{
    BST tree;

    tree.insert(30);
    tree.insert(22);
    tree.insert(8);
    tree.insert(9);
    tree.insert(40);
    tree.insert(45);
    tree.insert(32);
    tree.insert(11);
    tree.insert(10);

    cout << "\nIn-order traversal of the BST: \n";
    tree.inOrder();

    int searchKey = 45;
    if (tree.search(searchKey))
    {
        cout << "\nValue " << searchKey << " found in the BST.\n" << endl;
        cout << "\nDeleting " << searchKey << "...";
        tree.deleteNode(searchKey);
        tree.deleteNode(22);
        cout << "\nIn-order traversal after deletion: \n";
        tree.inOrder();
    }
    else
    {
        cout << "Value " << searchKey << " not found in the BST." << endl;
    }

    return 0;
}
