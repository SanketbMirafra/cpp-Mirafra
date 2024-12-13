

#include <iostream>
using namespace std;

template <typename T>
class Stack {
    int size;
    int capacity;
    T *arr;

public:

    Stack() {
        size = 0;
        capacity = 1;
        arr = new T[capacity];
    }

    Stack(int size) {
        if (size < 0) {
            cout << "Invalide Size"<<endl;
            return;
        }
 
        while (capacity<size) {
            capacity *= 2;
        }
        arr = new T[capacity];
        this->size = 0;
    }

    bool isFull() {
        if (size == capacity) {
            return true;
        }
        return false;
    }
    
    bool isEmpty() {
        if (size == 0) {
            return true;
        }
        return false;
    }

    void push(T value) {
        if (!isFull()) {
            arr[size++] = value;
        }
        else {
            T* temp = new T[capacity * 2];
            for (int i = 0; i < size; i++) {
                temp[i] = arr[i];
            }
            delete[] arr;
            temp[size++] = value;
            capacity = capacity * 2;
            arr = temp;
        }
        cout << value << "  added in stack" << endl;
    }

    void pop() {
        if (!isEmpty()) {
            size--;
            cout << "pop operation is successfull" << endl;
        }
        else {
            cout << "Given stack is Empty stack" << endl;
        }
    }

    void stackSize() {
        cout << "Size of Given stack is " << size << endl;
    }

    void stackCapacity() {
        cout << "capacity of Given stack is " << capacity << endl;
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << "  ";
        }
    }

    ~Stack() {
        delete[] arr;
    }
};

int main()
{
    std::cout << "---------------- Hello Stack ---------------" << endl << endl;

    Stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    //stack.push(5);
    stack.stackSize();
    stack.pop();
    stack.stackSize();
    stack.stackCapacity();


    stack.display();
}
