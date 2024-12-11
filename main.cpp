#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    Node* next;
    int contact;
    string name;

    Node(int contact, string name) : contact(contact), name(name), next(nullptr) {}
};

class Linked_list {
private:
    Node* head;
    Node* search_history_head;
    int search_history_size;

public:
    Linked_list() : head(nullptr), search_history_head(nullptr), search_history_size(0) {}

    void insert(int contact, string name) {
        Node* new_node = new Node(contact, name);

        if (!head || head->name > name) {
            new_node->next = head;
            head = new_node;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr && temp->next->name < name) {
            temp = temp->next;
        }

        new_node->next = temp->next;
        temp->next = new_node;
    }

    void display() {
        if (!head) {
            cout << "Contact List is empty" << endl;
            return;
        }

        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->name << " , " << temp->contact << endl;
            temp = temp->next;
        }
    }

    void delete_contact(string name) {
        if (head && head->name == name) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* temp = head;
        while (temp != nullptr && temp->next != nullptr) {
            if (temp->next->name == name) {
                Node* to_delete = temp->next;
                temp->next = temp->next->next;
                delete to_delete;
                return;
            }
            temp = temp->next;
        }
    }

    void search_contact(string name) {
        Node* temp = head;
        bool found = false;

        while (temp != nullptr) {
            if (temp->name == name) {
                found = true;
                break;
            }
            temp = temp->next;
        }

        if (found) {
            cout << name << " is in the contact list." << endl;
        } else {
            cout << name << " is not in the contact list." << endl;
        }

        add_to_search_history(name);
    }

void add_to_search_history(string name)
{
    Node* new_node = new Node(0, name);
    if (search_history_size == 10) {
        Node* temp = search_history_head;
        search_history_head = search_history_head->next;
        delete temp;
        search_history_size--;
    }

    if (search_history_size == 0)
    {
        search_history_head = new_node;
    }
    else
    {
        Node* temp = search_history_head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }

    search_history_size++;
}

    void display_search_history() {
        if (!search_history_head) {
            cout << "Search History is empty" << endl;
            return;
        }

        Node* temp = search_history_head;
        cout << "Search History (Last 10 searches):" << endl;
        while (temp != nullptr) {
            cout << temp->name << endl;
            temp = temp->next;
        }
    }
};

int main() {
    Linked_list object;

    object.insert(43434373, "Alan");
    object.insert(12121212, "Eric");
    object.insert(65355999, "Hensel");
    object.insert(77777777, "Tyler");
    object.insert(21992199, "Nicolas");
    object.insert(91211211, "David");

    object.display();

    object.delete_contact("Alan");
    cout << endl << "After deletion:" << endl;
    object.display();

    object.search_contact("Alex");
    object.search_contact("Gerald");
    object.search_contact("CHris");
    object.search_contact("Bale");
    object.search_contact("Jericho");
    object.search_contact("David");
    object.search_contact("Eric");
    object.search_contact("Hensel");
    object.search_contact("Issac");
    object.search_contact("Zack");
    object.search_contact("William");

    object.display_search_history();

    return 0;
}
