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
public:
    STACK() : top(nullptr) {}
    void push(int value)
    {
        Node* temp = new Node(value);
        temp->next = top;
        top = temp;
        cout << "pushed " << value << " in the stack" << endl;
    }
    void pop()
    {
        if(Is_empty())
        {
            cout << "stack overflow" << endl;
            return;
        }
        else
        {
            Node* temp = top;
            int value = top->data;
            top = top->next;
            cout << "stack with " << value << " deleted" << endl;
            value = 0;
            delete temp;
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
    ~STACK() {}
};
int main()
{
    STACK obj;
    obj.push(1);
    obj.push(2);
    obj.pop();
    obj.pop();

    return 0;
}
