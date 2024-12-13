

#include <iostream>
using namespace std;

class Node {
public:

    int data;
    Node* next;
    Node* prev;

    Node() {
        data = 0;
        next = prev = nullptr;
    }

    Node(int d) {
        data = d;
        next = prev = nullptr;
    }
};

class CircularLinkedList {

    Node* head = nullptr;
    
public:
    void insertAtBack(int d) {
        Node* temp = new Node(d);
        if(head == nullptr) {
            head = temp;
            head->next = head;
            head->prev = head;
            
        }
        else {
            temp->next = head;
            temp->prev = head->prev;
            head->prev->next = temp;
            head->prev = temp;
            
        }
    }

    void insertAtFront(int d) {
        Node* temp = new Node(d);
        if (head == nullptr) {
            head = temp;
            head->next = head;
            head->prev = head;
        }
        else {
            temp->next = head;
            temp->prev = head->prev;
            head->prev->next = temp;
            head->prev = temp;
            head = temp;
        }
    }
    void display() {
        if (head == nullptr) {
            cout << "Given CircularLinkedList is Empty ";
        }
        else {
            Node* temp = head;
            do {
                cout << temp->data << " -> ";
                temp = temp->next;
            } while (temp != head);
                cout << "HEAD\n"; 
        
         
        }
    }
};

int main()
{
    std::cout << "Welcome to Circular LinkedList "<<endl<<endl;

    CircularLinkedList list;
    list.insertAtBack(10);
    list.insertAtBack(20);
    list.insertAtBack(30);
    list.insertAtBack(40);
    list.insertAtBack(50);

    list.display();

}
