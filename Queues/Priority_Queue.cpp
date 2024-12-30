#include <iostream>

using namespace std;
class node
{
public:
    int data;
    int priority;
    node* next;
    node(int d, int p) : data(d), priority(p), next(nullptr) {}
    friend class priority_queue;
};
class priority_queue
{
private:
    node* head;
public:
    priority_queue() : head(nullptr) {}
    void add(int d, int p)
    {
        node* new_node = new node(d, p);
        if(!head || p < head->priority)
        {
            new_node->next = head;
            head = new_node;
        }
        else
        {
            node* current = head;
            while(current->next && current->next->priority <= p)
            {
                current = current->next;
            }
            new_node->next = current->next;
            current->next = new_node;
        }
    }
    bool is_empty()
    {
        return head == nullptr;
    }
    int remove()
    {
        if(!head)
        {
            cerr << "queue is empty" << endl;
            return -1;
        }
        node* temp = head;
        head = head->next;
        int val = head->data;
        delete temp;
        return val;
    }
    void display()
    {
        node* temp = head;
        while(temp != nullptr)
        {
            cout << "data: " << temp->data << endl;
            cout << "priority: " << temp->priority << endl;
            temp = temp->next;
        }
    }
};
int main()
{
    priority_queue pq;
    pq.add(1, 2);
    pq.add(3, 2);
    pq.add(33, -1);
    pq.display();
    pq.remove();
    cout << endl;
    pq.display();
    return 0;
}
