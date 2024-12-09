#include <iostream>
using namespace std;

class Product {
private:
    int SKU;
    int count;
    float retail_price;
    Product* left;
    Product* right;

public:
    Product(int SKU, int count, float retail_price)
        : SKU(SKU), count(count), retail_price(retail_price), left(nullptr), right(nullptr) {}

    friend class Warehouse_Inventory;
};

class Warehouse_Inventory {
private:
    Product* root;

    void insert_BST(Product*& root, int SKU, int count, float price) {
        if (root == nullptr) {
            root = new Product(SKU, count, price);
        } else if (SKU < root->SKU) {
            insert_BST(root->left, SKU, count, price);
        } else if (SKU > root->SKU) {
            insert_BST(root->right, SKU, count, price);
        } else {
            cout << "Product with SKU " << SKU << " already exists." << endl;
        }
    }

    Product* delete_BST(Product*& root, int SKU) {
        if (root == nullptr) {
            return nullptr;
        }

        if (SKU < root->SKU) {
            root->left = delete_BST(root->left, SKU);
        } else if (SKU > root->SKU) {
            root->right = delete_BST(root->right, SKU);
        } else {
            if (!root->left) {
                Product* temp = root->right;
                delete root;
                return temp;
            } else if (!root->right) {
                Product* temp = root->left;
                delete root;
                return temp;
            }

            Product* temp = in_order_successor(root->right);
            root->SKU = temp->SKU;
            root->count = temp->count;
            root->retail_price = temp->retail_price;
            root->right = delete_BST(root->right, temp->SKU);
        }
        return root;
    }

    Product* in_order_successor(Product* root) {
        while (root && root->left != nullptr) {
            root = root->left;
        }
        return root;
    }

    bool remove_BST(Product*& root, int SKU) {
        if (!root) {
            return false;
        }

        root = delete_BST(root, SKU);
        return true;
    }

    void add_item_in_BST(Product* root, int SKU, int count) {
        if (count < 0) {
            cout << "Cannot add a negative count." << endl;
            return;
        }

        if (!root) {
            cout << "Product with SKU " << SKU << " not found." << endl;
            return;
        }

        if (SKU < root->SKU) {
            add_item_in_BST(root->left, SKU, count);
        } else if (SKU > root->SKU) {
            add_item_in_BST(root->right, SKU, count);
        } else {
            root->count += count;
            cout << "Added " << count << " items to SKU " << SKU << ". Total count: " << root->count << endl;
        }
    }

    bool remove_item_in_BST(Product* root, int SKU, int count) {
        if (count < 0) {
            cout << "Cannot remove a negative count." << endl;
            return false;
        }

        if (!root) {
            cout << "Product with SKU " << SKU << " not found." << endl;
            return false;
        }

        if (SKU < root->SKU) {
            return remove_item_in_BST(root->left, SKU, count);
        } else if (SKU > root->SKU) {
            return remove_item_in_BST(root->right, SKU, count);
        } else {
            if (root->count < count) {
                cout << "Cannot remove more items than available. Current count: " << root->count << endl;
                return false;
            } else {
                root->count -= count;
                cout << "Removed " << count << " items from SKU " << SKU << ". Remaining count: " << root->count << endl;
                return true;
            }
        }
    }

    void display_BST(Product* root) {
        if (root) {
            display_BST(root->left);
            cout << "SKU: " << root->SKU << ", Count: " << root->count << ", Price: " << root->retail_price << endl;
            display_BST(root->right);
        }
    }

    int height(Product* node) {
        if (node == nullptr) return 0;
        return 1 + max(height(node->left), height(node->right));
    }

    bool isBalancedUtil(Product* node) {
        if (node == nullptr) return true;

        int leftHeight = height(node->left);
        int rightHeight = height(node->right);

        if (abs(leftHeight - rightHeight) > 1) return false;

        return isBalancedUtil(node->left) && isBalancedUtil(node->right);
    }

public:
    Warehouse_Inventory() : root(nullptr) {}

    void insertProduct(int SKU, int count, float price) {
        insert_BST(root, SKU, count, price);
    }

    bool deleteProduct(int SKU) {
        bool deleted = remove_BST(root, SKU);
        if (!deleted) {
            cout << "Product with SKU " << SKU << " not found." << endl;
        } else {
            cout << "Product with SKU " << SKU << " deleted." << endl;
        }
        return deleted;
    }

    bool removeItem(int SKU, int count) {
        bool removed = remove_item_in_BST(root, SKU, count);
        if (!removed) {
            cout << "Failed to remove items for SKU " << SKU << "." << endl;
        }
        return removed;
    }

    void addItem(int SKU, int count) {
        add_item_in_BST(root, SKU, count);
    }

    void displayInventory() {
        display_BST(root);
    }

    bool isBalanced() {
        return isBalancedUtil(root);
    }
    Product* findProductInBST(Product* root, int SKU) {
        if (!root) {
            return nullptr;
        }

        if (SKU < root->SKU) {
            return findProductInBST(root->left, SKU);
        } else if (SKU > root->SKU) {
            return findProductInBST(root->right, SKU);
        } else {
            return root;
        }
    }

    Product* findProduct(int SKU) {
        return findProductInBST(root, SKU);
    }

};

int main() {
    Warehouse_Inventory inventory;

    inventory.insertProduct(101, 50, 25.5);
    inventory.insertProduct(102, 30, 15.0);
    inventory.displayInventory();

    inventory.addItem(101, 10);
    inventory.removeItem(102, 5);

    inventory.displayInventory();

    if (inventory.deleteProduct(101)) {
        cout << "Product 101 successfully removed from inventory." << endl;
    }
    inventory.displayInventory();

    if (inventory.isBalanced()) {
        cout << "The inventory BST is balanced." << endl;
    } else {
        cout << "The inventory BST is not balanced." << endl;
    }
    Product* product = inventory.findProduct(102);
    if (product)
    {
        cout << "Found product " << endl;
    } else {
        cout << "Product not found." << endl;
    }
    return 0;
}
