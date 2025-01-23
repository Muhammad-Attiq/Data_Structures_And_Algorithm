#include <iostream>

using namespace std;
class Node
{
private:
    int data;
    Node* next;
public:
    Node(int d) : data(d) {}
    friend class STACK;
};
class STACK
{
private:
    Node* top;
    int count = 0;
public:
    STACK() : top(nullptr) {}
    void push(int value)
    {
        Node* temp = new Node(value);
        temp->next = top;
        top = temp;
        count++;
    }
    int pop()
    {
        if(Is_empty())
        {
            cout << "stack overflow" << endl;
            return -1;
        }
        else
        {
            Node* temp = top;
            int value;
            value = top->data;
            top = top->next;
            delete temp;
            --count;
            return value;
        }
    }
    int peek()
    {
        if(Is_empty())
        {
            cout << "stack overflow" << endl;
            return -1;
        }
        else
        {
            cout << "top value " << top->data << endl;
        }
    }
    bool Is_empty()
    {
        return top == nullptr;
    }
    int size()
    {
        return count;
    }
    ~STACK() {}
    void display()
    {
        if(Is_empty())
        {
            cout << "stack overflow" << endl;
            return;
        }
        Node* temp = top;
        cout << "stack values " << endl;
        while(temp != nullptr)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }

    void reverse_order()
    {
        if(Is_empty())
        {
            cout << "stack overflow" << endl;
            return;
        }
        STACK obj;
        while(!Is_empty())
        {
            obj.push(pop());
        }
        top = obj.top;
    }
};
int main()
{
    STACK obj;
    obj.push(1);
    obj.push(2);
    obj.push(3);
    obj.display();
    obj.reverse_order();
    obj.display();
    return 0;
}
