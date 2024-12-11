
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Insert at the beginning of the list
    void insertAtHead(int value)
    {
        Node* newNode = new Node(value);
        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAtTail(int value)
    {
        Node* newNode = new Node(value);
        if (tail == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Delete a node by value
    void deleteNode(int value)
    {
        Node* current = head;
        while (current != nullptr && current->data != value)
        {
            current = current->next;
        }
        if (current == nullptr)
        {
            cout << "Value not found in the list.\n";
            return;
        }

        if (current == head)
        {
            head = head->next;
            if (head) head->prev = nullptr;
        }
        else if (current == tail)
        {
            tail = tail->prev;
            if (tail) tail->next = nullptr;
        }
        else
        {
            current->prev->next = current->next;
            current->next->prev = current->prev;
        }
        delete current;
        cout << "Node with value " << value << " deleted.\n";
    }

    // Search for a node by value
    bool search(int value)
    {
        Node* current = head;
        while (current != nullptr)
        {
            if (current->data == value)
            {
                cout << "Value " << value << " found in the list.\n";
                return true;
            }
            current = current->next;
        }
        cout << "Value " << value << " not found in the list.\n";
        return false;
    }

    // Sort the list (Bubble Sort)
    void sortList()
    {
        if (head == nullptr) return;

        bool swapped;
        Node* ptr;
        do {
            swapped = false;
            ptr = head;
            while (ptr->next != nullptr)
            {
                if (ptr->data > ptr->next->data)
                {
                    swap(ptr->data, ptr->next->data);
                    swapped = true;
                }
                ptr = ptr->next;
            }
        } while (swapped);
    }

    // Reverse the list
    void reverse()
    {
        Node* current = head;
        Node* temp = nullptr;
        while (current != nullptr)
        {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }

        if (temp != nullptr)
        {
            head = temp->prev;
        }
    }

    // Display the list from the head to the tail
    void displayForward() {
        Node* current = head;
        cout << "List (Head to Tail): ";
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Display the list from the tail to the head
    void displayBackward() {
        Node* current = tail;
        cout << "List (Tail to Head): ";
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }

    // Destructor to free memory
    ~DoublyLinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

int main() {
    DoublyLinkedList list;

    list.insertAtHead(5);
    list.insertAtHead(3);
    list.insertAtTail(7);
    list.insertAtTail(10);

    list.displayForward();
    list.displayBackward();

    list.search(7); // Search for a node

    list.deleteNode(5); // Delete a node
    list.displayForward();

    list.insertAtHead(15);
    list.insertAtHead(20);
    list.sortList(); // Sort the list
    list.displayForward();

    list.reverse(); // Reverse the list
    list.displayForward();

    return 0;
}
