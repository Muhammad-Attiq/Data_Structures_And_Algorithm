#include <iostream>
#include <cstring>
using namespace std;

class Node
{
public:
    char character;
    Node* next;
    Node(char val) : character(val), next(nullptr) {}
};

class Stack
{
private:
    Node* head;
public:
    Stack() : head(nullptr) {}

    void push(char value)
    {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    char pop()
    {
        if (isEmpty())
        {
            return '\0';
        }
        char value = head->character;
        Node* temp = head;
        head = head->next;
        delete temp;
        return value;
    }

    bool isEmpty()
    {
        return head == nullptr;
    }

    ~Stack()
    {
        while (!isEmpty())
        {
            pop();
        }
    }
};

void reverse_char_array(char* char_array)
{
    Stack object;
    for (int i = 0; char_array[i] != '\0'; i++)
    {
        object.push(char_array[i]);
    }
    for (int i = 0; char_array[i] != '\0'; i++)
    {
        char_array[i] = object.pop();
    }
}

bool isBalanced(const char* ptr_array)
{
    Stack obj;
    for (int i = 0; ptr_array[i] != '\0'; i++)
    {
        if (ptr_array[i] == '(' || ptr_array[i] == '{' || ptr_array[i] == '[')
        {
            obj.push(ptr_array[i]);
        }
        else if (ptr_array[i] == ')' || ptr_array[i] == '}' || ptr_array[i] == ']')
        {
            if (obj.isEmpty())
                return false;

            char top = obj.pop();
            if ((ptr_array[i] == ')' && top != '(') ||
                (ptr_array[i] == '}' && top != '{') ||
                (ptr_array[i] == ']' && top != '['))
            {
                return false;
            }
        }
    }
    return obj.isEmpty();
}

int main()
{
    char char_array[50];
    cout << "Enter the string: ";
    cin.getline(char_array, 50);

    char temp[50];
    strcpy(temp, char_array);
    reverse_char_array(temp);
    cout << "Reversed array: " << temp << endl;

    if (isBalanced(char_array))
    {
        cout << "The original string is balanced." << endl;
    }
    else
    {
        cout << "The original string is not balanced." << endl;
    }

    return 0;
}
