
#include <iostream>
using namespace std;

template <typename T>
class Node {
    T data;

public:
    Node* next;

    Node() {
        data = NULL;
        next = nullptr;
    }

    Node(T d) {
        data = d;
        next = nullptr;
    }

    T getData() {
        return data;
    }

};

template<typename T>
class Queue {
    Node<T>* head;

public:
    Queue() {
        head = nullptr;
    }

    ~Queue() {
        Node<T>* temp = head;
        while (temp != nullptr) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void inQueue(T d) {
        Node<T>* temp = new Node<T>(d);

        if (head == nullptr) {
            head = temp;
        }
        else {
            Node<T>* temp1 = head;

            while (temp1->next != nullptr) {
                temp1 = temp1->next;
            }
            temp1->next = temp;
        }

        cout << d << "  Added in Queue" << endl;
    }

    void deQueue() {
        if (head == nullptr) {
            cout << "Given Queue is Empty Queue" << endl;
        }
        else {
            Node<T>* temp = head;
            head = head->next;
            cout << temp->getData() << " Element is deleted" << endl;
            delete temp;
            
        }
    }

    void top() {
        if (head == nullptr) {
            cout << "Given Queue is Empty Queue" << endl;
        }
        else {
            cout << head->getData() << " Top of the Queue" << endl;
        }
    }

    void displays() {
        if (head == nullptr) {
            cout << "Given Queue is Empty Queue" << endl;
        }
        else {
            Node<T>* temp = head;
            while (temp != nullptr) {
                cout << temp->getData() << "  ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};
int main()
{
    std::cout << "-----------  Queue single Linked List  -------------"<<endl<<endl;

    Queue<int> queue;
    queue.deQueue();
    queue.inQueue(10);
    queue.inQueue(20);
    queue.inQueue(30);
    queue.deQueue();
    queue.displays();
}

