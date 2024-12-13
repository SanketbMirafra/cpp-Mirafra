
#include <iostream>
#include <string>
using namespace std;

class Node {

public:
    string text;
    Node* prev;
    Node* next;

    Node() {
        text = "";
        prev = nullptr;
        next = nullptr;
    }

    Node(string s) {
        text = s;
        prev = nullptr;
        next = nullptr;
    }

};

class TextManager {
    Node* head;
    Node* node;

public:
    TextManager() {
        node = nullptr;
        head = nullptr;
    }

    void addString(string s) {
        Node* temp = new Node(s);

        if (head == nullptr) {
            head = temp;
            node = head;
        }
        else {
            
            node->next = temp;
            temp->prev = node;
            node = temp;
        }
    }

    void undo() {
        if (node->next == head || node == nullptr) {
            cout << "Nothing to undo " << endl;
       }
        else if (node == head) {
            Node* temp = new Node();
            node = temp;
            node->next = head;
            /*delete temp;*/
        }
        else {
            node = node->prev;
        }
    }

    void redo() {

        if (node->next == head) {
            delete node;
            node = head;
            return;
        }

        if (node->next == nullptr) {
            cout << "Nothing to Redo" << endl;
        }
        else {
            node = node->next;
        }
    }

    void display() {
        if (node->next == head) {
            cout << "Nothing to Display in list" << endl;
            return;
        }
        if (head == nullptr) {
            cout << "Given Text Manager is Empty" << endl;
            return;
        }

        Node* temp = head;
        while (temp != node) {
            cout << temp->text << " ";
            temp = temp->next;
        }
        cout << temp->text <<endl;
    }

    virtual ~TextManager() {
        while (head->next != nullptr) {
            head = head->next;
            delete head->prev;
        }
        delete head;
    }
};

int main()
{
    std::cout << "----------  WELLCOME TO TEXT MANAGER  -------------"<<endl<<endl;

    TextManager text;
    text.addString("my");
    text.addString("hii");
    text.addString("kay");
    text.addString("bye");
    text.addString("rock");

    text.display();

    text.undo();
    text.undo();
    text.addString("rock");
    text.undo();
    text.undo();
    text.undo();
    text.undo();
    text.undo();
    text.redo();

    text.display();



}

