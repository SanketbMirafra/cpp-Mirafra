
#include <iostream>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node():data(NULL), next(nullptr){}

    Node(T d) :data(d), next(nullptr) {}
};

template <typename T>
class Stack {

    Node<T>* top;

public:
    Stack() {
        top = nullptr;
    }

    void push(T d) {
        Node<T>* temp = new Node<T>(d);
        if (top == nullptr) {
            top = temp;
        }
        else {
            temp->next = top;
            top = temp;
        }
        cout << d << " is added in stack" << endl;
    }

    void pop() {
        if (top == nullptr) {
            cout << "Given stack is empty stack" << endl;
        }
        else {
            Node<T>* temp = top;
            top = top->next;
            delete temp;
        }
    }

    void size() {
        int i = 0;
        Node<T>* temp = top;
        while (temp != nullptr) {
            i++;
            temp = temp->next;
        }

        cout << "size of stack is " << i << endl;
    }

    void display() {
        Node<T>* temp = top;
        while (temp != nullptr) {
            cout << temp->data<< "  ";
            temp = temp->next;
        }
        cout << endl;
    }

    void peek() {
        if (top == nullptr) {
            cout<< "Given stack is empty stack" << endl;
        }
        else {
            cout << "peek of stack is "<<top->data << endl;
        }
    }
    ~Stack() {

        while (top != nullptr) {
            Node<T>* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int main()
{
    std::cout << "---------- Hello Stack in LinkedList ------------"<<endl<<endl;

    Stack<int> stack;
    stack.pop();
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);
    stack.display();
    stack.pop();
    stack.display();  
    /*cout << sizeof(stack)<<endl;*/
    /*cout << sizeof(Node<Node<int>>) << endl;*/

}
