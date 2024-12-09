#include <iostream>
using namespace std;

class Node
{
public:
    int key;
    Node* left;
    Node* right;
    int height;

    Node(int value)
    {
        key = value;
        left = right = nullptr;
        height = 1;
    }
};

class AVLTree
{
public:
    int getHeight(Node* node)
    {
        return node ? node->height : 0;
    }

    int getBalanceFactor(Node* node)
    {
        return node ? getHeight(node->left) - getHeight(node->right) : 0;
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

    Node* insert(Node* node, int key)
    {
        if(!node)
        {
            return new Node(key);
        }
        else if(key < node->key)
        {
            node->left = insert(node->left, key);
        }
        else if(key > node->key)
        {
            node->right = insert(node->right, key);
        }

        node->height = getHeight(node);

        int balance = getBalanceFactor(node);

        if(balance > 1 && key < node->left->key)
        {
            return rightRotate(node);
        }
        else if(balance < -1 && key > node->right->key)
        {
            return leftRotate(node);
        }
        else if(balance > 1 && key > node->left->key)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        else if(balance < -1 && key < node->right->key)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    void inOrder(Node* root)
    {
        if (root)
        {
            inOrder(root->left);
            cout << root->key << " ";
            inOrder(root->right);
        }
    }
};

int main()
{
    AVLTree avl;
    Node* root = nullptr;

    root = avl.insert(root, 10);
    root = avl.insert(root, 9);
    root = avl.insert(root, 8);
    root = avl.insert(root, 6);
    root = avl.insert(root, 7);
    root = avl.insert(root, 12);
    root = avl.insert(root, 11);

    cout << "In-order traversal of the AVL tree:" << endl;
    avl.inOrder(root);
    cout << endl;

    return 0;
}
