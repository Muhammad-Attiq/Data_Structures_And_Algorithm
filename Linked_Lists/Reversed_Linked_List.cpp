#include <iostream>

struct Node
{
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};
class LinkedList
{
public:
    Node* head;

    LinkedList() : head(nullptr) {}
    void display()
    {
        Node* temp = head;
        while (temp)
        {
            std::cout << temp->data << std::endl;
            temp = temp->next;
        }
    }
    void append(int val)
    {
        Node* newNode = new Node(val);
        if (!head)
        {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    Node* reverse()
    {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;
        while(current)
        {
            next = current->next;
            current->next = prev;
            prev  = current;
            current = next;
        }
        head = prev;
        return head;
    }
};

int main()
{
    LinkedList list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.append(5);
    std::cout << "Original List: ";
    std::cout << std::endl;
    list.display();
    list.reverse();
    std::cout << "Reversed List: ";
    std::cout << std::endl;
    list.display();

    return 0;
}
