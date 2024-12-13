

#include <iostream>
using namespace std;

class Node {

public:
    int data;
    Node* node;

public:
    Node(int d, Node* n = nullptr){
        data = d;
        node = n;
    }

    int getData() {
        return data;
    }

    Node getNode() {
        return *node;
    }

    Node* getNext() {
        return node;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    void insertAtEnd(int data) {

        Node* newNode = new Node(data);
        if (head == nullptr) {
            cout << "List is Empty : " << data << endl;
            head = newNode;
        }
        else {
            
            Node* temp = head;
            while (temp->node != nullptr) {
                temp = temp->node;
            }

            temp->node = newNode;
            cout << "node added successfully : " << data << endl;
        }
    }

    void deleteNode(int data) {
        Node* temp = head;
        Node* prev = head;
        if (temp == nullptr) {
            cout << "linkedList is empty "<<endl;
            return;
        }
        else {
            if (temp->data == data) {
                head = temp->node;
                cout << "Element Deleted successfully : " << data << endl;
                delete temp;
                return;
            }
            else {
                
                while (temp->node != nullptr) {
                    if (temp->data == data) {
                        prev->node = temp->node;
                        delete temp;

                        cout << "Element Deleted successfully : " << data << endl;
                        return;
                    }
                    prev = temp;
                    temp = temp->node;
                }
            }

            if (temp->data == data) {
                prev->node = nullptr;
                delete temp;
                cout << "Element Deleted successfully : "<<data << endl;
            }
            else {
                cout << "Element is not found in LinkedList" << endl;
            }

        }

    }

    void reverseLinkedList() {
        Node* current = head;
        Node* prev = nullptr;
        Node* next = nullptr;

        while (current != nullptr) {
            next = current->node;
            current->node = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    Node* reverseLinkedList1( Node* head) {
        Node* current = head;
        Node* prev = nullptr;
        Node* next = nullptr;

        while (current != nullptr) {
            next = current->node;
            current->node = prev;
            prev = current;
            current = next;
        }
        head = prev;

        return head;
    }


    Node* reverseListInGroup(Node* head, int k)
    {
        
        if (!head)
            return nullptr;
        Node* current = head;
        Node* prev = nullptr;
        Node* nnext = nullptr;
        int count = 0;
        while (current != nullptr && count < k)
        {
            nnext = current->node;
            current->node = prev;
            prev = current;
            current = nnext;
            count++;
        }

        if (nnext != nullptr)
        {
            cout << "Nnext " << nnext->data << " Head next " << head->data << endl;
            head->node = reverseListInGroup(nnext, k);
        }
        if (count != k) {
            return  reverseLinkedList1(prev);
        }
        return prev;
    }

    void reverseData() {
        Node* temp = head;
        Node* first = head;
        Node* second = head;
        Node* prev = nullptr;

        while(second != nullptr && second->node != nullptr) {
            temp = first;
            while (temp->node != prev) {
                temp = temp->node;
                         
            }
            int data = first->data;
            first->data = temp->data;
            temp->data = data;
            first = first->node;
            second = second->node;
            second = second->node;
            prev = temp;
        }
    }

    void reverseInGroups(int k)
    {
        head = reverseListInGroup(head, k);
    }


    void display() {
        Node* temp = head;
        if (temp == nullptr) {
            cout << "linkedList is empty" << endl;
            return;
        }
        
        while (temp->node != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->node;
        }
        cout << temp->data << endl;
    }

    ~LinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->node;
            delete temp;
        }
    }

};

int main()
{
    std::cout << "------------------  Welcome to LinkedList  ---------------"<<endl<<endl;

    LinkedList list;
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);
    list.insertAtEnd(50);
    list.insertAtEnd(60);
    list.insertAtEnd(70);
    list.insertAtEnd(80);
    /*list.deleteNode(80);*/

    list.display();
    /*list.reverseLinkedList();*/
    //list.reverseInGroups(3);
    //list.display();
    list.reverseData();
    list.display();

}

