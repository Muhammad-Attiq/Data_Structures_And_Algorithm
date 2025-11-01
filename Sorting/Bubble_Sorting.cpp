#include <iostream>

using namespace std;
class Node {
public:
    int data;
    Node* next;

    Node(int d) : data(d), next(nullptr) {}
};
class LinkedList
{
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void insert(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            return;
        }
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
    void bubble_sort()
    {
        if(!head)
        {
            return;
        }
        bool swapped;
        do
        {
            swapped = false;
            Node* current = head;
            while(current && current->next)
            {
                if(current->data > current->next->data)
                {
                    swap(current->data, current->next->data);
                    swapped = true;
                }
                current = current->next;
            }
        }
        while(swapped);
    }
    void display() const
    {
        Node* current = head;
        while (current)
        {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
     ~LinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};
int main()
{
    LinkedList list;
    list.insert(40);
    list.insert(10);
    list.insert(30);
    list.insert(50);
    list.insert(20);

    cout << "Original list: ";
    list.display();

    list.bubble_sort();

    cout << "Sorted list: ";
    list.display();

    return 0;
}
