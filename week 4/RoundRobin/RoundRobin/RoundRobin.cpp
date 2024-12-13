

#include <iostream>
#include <string>
using namespace std;


class Node {

public:
    int data;
    string name;
    Node* next; 
    Node* prev;

    Node() {
        data = NULL;
        next = nullptr;
        prev = nullptr;
    }
    Node(int d, string s) {
        data = d;
        name = s;
        next = nullptr;
        prev = nullptr;
    }
};


class CircularQueue {
public:
    Node* head;
    CircularQueue() {
        head = nullptr;
    }

    void inqueue(int data , string s) {
        Node* temp = new Node(data, s);
        if (head == nullptr) {
            head = temp;
            head->next = head->prev = head;
        }
        else {
            temp->next = head;
            temp->prev = head->prev;
            head->prev->next = temp;
            head->prev = temp;
        }
    }
    void dequeue() {
        if (head == nullptr) {
            cout << "given Queue is Empty" << endl;
        }
        else if (head ->next == head) {
            head = nullptr;
        }
        else {
            Node* temp = head;
            head = head->next;
            head->prev->prev->next = head;
            head->prev = head->prev->prev;
            delete temp;
        }
    }

    void display() {
        if (head == nullptr) {
            cout << "given Queue is Empty" << endl;
        }
        else {
            Node* temp = head;
            int i = 1;
            while (temp->next != head) {
                cout << i << ". " << temp->name << " is busttime of process" << endl;
                temp = temp->next;
                i++;
            }
            cout << i << ". " << temp->name << " is busttime of process" << endl;
        }
    }
};

class RoundRobin {
    int timeQuantum;
    CircularQueue cqueue;
public:
    RoundRobin(int d, CircularQueue& node) {
        cqueue = node;
        timeQuantum = d;
    }

    void startProcess() {
        if (cqueue.head == nullptr) {
            cout << "All Process are Completed" << endl;
        }
        else {
            while (cqueue.head != nullptr) {
                if (cqueue.head->data <= timeQuantum) {
                    cout << cqueue.head->name << " is completed  --------------------" << endl;
                    cqueue.dequeue();
                }
                else {
                    cqueue.head->data -= timeQuantum;
                    cout << cqueue.head->name << " executed for "<< timeQuantum<<" units" << endl;
                    cqueue.head = cqueue.head->next;
                }

            }
        }
    }

};
int main()
{
    std::cout << "---------- Round Robin -----------"<<endl<<endl;

    CircularQueue queue;
    queue.inqueue(12, "Task Manager");
    queue.inqueue(17, "Google");
    queue.inqueue(11, "VS Code");
    queue.inqueue(7, "Whatsapp");
    queue.inqueue(21, "Telegram");
    //queue.dequeue();
    //queue.display();
    RoundRobin roundrobin(3, queue);
    roundrobin.startProcess();
}

