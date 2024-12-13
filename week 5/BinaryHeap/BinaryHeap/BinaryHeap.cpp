
#include <iostream>
#include<vector>
using namespace std;

class BinaryHeap {

    vector<int> heap;
    vector<int> temp;

public:
    BinaryHeap() {

    }
    BinaryHeap(vector<int> t) {
        temp = t;
    }

    void maxHeap() {
        int index = 0;
        while (true) {

            int left = (index * 2 + 1);
            int right = (index * 2 + 2);
            int parents = index;

            if (left<temp.size() && temp[left]<temp[parents]) {
                parents = left;
            }
            if (right<temp.size() && temp[right]<temp[parents]) {
                parents = right;
            }

            if (parents != index) {
                swap(temp[index], temp[parents]);
                heapifyUp1(index);
                index++;
            }
            else {   
                heapifyUp1(index);
                index++;
            }
            if(index>=temp.size()){
                break;
            }
            

        }
    }
    void heapifyUp1(int index) {

        while (index > 0) {
            int parents = (index - 1) / 2;
            if (temp[index] < temp[parents]) {
                swap(temp[index], temp[parents]);
                index = parents;
            }
            else {
                break;
            }
        }
    }
    void heapifyUp(int index) {

        while (index > 0) {
            int parents = (index - 1) / 2;
            if (heap[index] > heap[parents]) {
                swap(heap[index], heap[parents]);
                index = parents;
            }
            else {
                break;
            }
        }
    }

    void heapifyDown(int index) {

        while(true){

            int left = (index * 2 + 1);
            int right = (index * 2 + 2);
            int parents = index;
            if (left<heap.size() && heap[left]>heap[parents]) {
                parents = left;
            }

            if (right<heap.size() && heap[right]>heap[parents]) {
                parents =  right;
            }

            if (parents != index) {
                swap(heap[index], heap[parents]);
                index = parents;
            }
            else {
                break;
            }
        }
    }

    void push(int num) {
        heap.push_back(num);
        heapifyUp(heap.size() - 1);
    }

    void pop() {
        if (heap.empty()) return;

        swap(heap[0], heap[heap.size() - 1]);
        heap.pop_back();
        heapifyDown(0);
    }
    void display1() {
        if (temp.empty()) {
            cout << "Heap is empty" << endl;
        }
        else {
            for (int i = 0; i < temp.size(); i++) {
                cout << temp[i] << " ";
            }
            cout << endl;
        }
    }
    void display() {
        if (heap.empty()) {
            cout << "Heap is empty" << endl;
        }
        else {
            for (int i = 0; i < heap.size(); i++) {
                cout << heap[i] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    std::cout << "--------------- Binary Heap -------------" << endl << endl; {

        vector<int> temp{ 12, 15, 2, 7, 20, 1, 9, 3, 4};
        BinaryHeap bh(temp);
        bh.push(12);
        bh.push(9);
        bh.push(5);
        bh.push(13);
        bh.push(8);

        //bh.pop();

        bh.maxHeap();
        bh.display();
        bh.display1();
    }
}

