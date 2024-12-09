#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    void insert(int val)
    {
        Node* newNode = new Node(val);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node* temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    void printList()
    {
        Node* temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    Node* split(Node* head)
    {
        if(head == nullptr || head->next == nullptr)
        {
            return head;
        }
        Node* slow = head;
        Node* fast = slow->next;
        while(fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = slow->next->next;
        }
        Node* secondHalf = slow->next;
        slow->next = nullptr;
        return secondHalf;
    }

    Node* merge(Node* first, Node* second)
    {
        if (first == nullptr)
            return second;
        if (second == nullptr)
            return first;

        if (first->data <= second->data)
        {
            first->next = merge(first->next, second);
            return first;
        }
        else
        {
            second->next = merge(first, second->next);
            return second;
        }
    }

    Node* mergeSort(Node* head)
    {
        if(head == nullptr || head->next == nullptr)
        {
            return head;
        }
        Node* secondHalf = split(head);
        head = mergeSort(head);
        secondHalf = mergeSort(secondHalf);

        return merge(head, secondHalf);
    }

    void sort()
    {
        head = mergeSort(head);
    }
};

int main() {
    LinkedList list;

    list.insert(5);
    list.insert(4);
    list.insert(3);

    cout << "Original list: ";
    list.printList();
    list.sort();

    cout << "Sorted list: ";
    list.printList();

    return 0;
}

