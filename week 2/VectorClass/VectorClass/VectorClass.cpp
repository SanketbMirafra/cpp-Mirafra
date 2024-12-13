

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class VectorClass {

private:

    int size;
    int capacity = 0;
    T* ptrData;

public:

    void resize(int num) {

        if (num == 1) {
            capacity = 1;
        }
        else {
            int a = 2;
            while (true) {
                if (a >= num) {
                    capacity = a;
                    break;
                }
                a = a * 2;
            }
        }

        T* newPtr = new T[capacity];
        int i = 0;
        for ( ; i < size; i++) {
            if (i < num) {
                newPtr[i] = ptrData[i];
            }
            else { break; }
        }

        size = num;
     
        delete[] ptrData;
        ptrData = newPtr;

        

    }



    VectorClass() {
        size = 0;
        capacity = 0;
        ptrData = nullptr;
    }

    VectorClass(int num, int num2=0) {
        size = num;
        ptrData = new T[10];
        int i = 0;
        for (i = 0; i < num; i++) {
            ptrData[i] = num2;
        }
        
        if (num == 1) {
            capacity = 1;
        }
        else {
            int a = 2;
            while (true) {
                if (a >= num) {
                    capacity = a;
                    break;
                }
                a = a*2;
            }
        }
    }


    void push_back(T value) {
        
        if (size == capacity) {
            resize(size + 1);
            ptrData[size-1] = value;
        }
        else {
            ptrData[size++] = value;
        }
        
    }

    void pop_back() {
        if (size > 0) {
            size--;
        }
        else {
            cout << "Run Time Error : Vector is empty you can not pop any element" << endl;
        }
    }

    void erase(int startIndex, int endIndex = 0) {
        

        if (startIndex >= size) {
            cout << "Run Time Error : Vector Index Out of Bound" << endl;
            return;
        }

        if (endIndex == 0) { endIndex = startIndex + 1; }

        if (startIndex > endIndex) { cout << "Run Time Error : Start Index is Greater that End Index" << endl; return;  }

        int j = startIndex;
        for (int i = endIndex; i < size; i++) {
            ptrData[j++] = ptrData[i];
        }

        size = size - (endIndex-startIndex);
    }

    void insert(int index, int value) {

        if (index > size) {
            cout << "Run Time Error : Index is more than Size" << endl; return;
        }

        if (size == capacity) { resize(size + 1); size--; }

        for (int i = size; i > index; i--) {
            ptrData[i] = ptrData[i - 1];
        }

        ptrData[index] = value;

        size++;
 
    }

    void clear() {
        size = 0;
    }

    int mysize() {
        return size;
    }

    int mycapacity() {
        return capacity;
    }

    T& operator[](int index){
        if (index < 0 || index >= size) {
            cout << "Run Time Error : Index Out of Bound" << endl;
            throw std::out_of_range("Index out of bounds");
        }

        return ptrData[index];
    }

    const T& operator[](int index)const {
        if (index < 0 || index >= size) {
            cout << "Run Time Error : Index Out of Bound" << endl;
            throw std::out_of_range("Index out of bounds");
        }

        return ptrData[index];
    }
};

int main()
{
    std::cout << "Hello World!\n";

    
    VectorClass<int> myvector;

    cout << "Size of myvector : " << myvector.mysize()<<endl;
    cout << "Capacity myvector : " << myvector.mycapacity() << endl;
    myvector.resize(7);
    cout << "Size of myvector : " << myvector.mysize() << endl;
    cout << "Capacity myvector : " << myvector.mycapacity() << endl;
    //myvector.push_back(10);
    //cout << "Size of myvector : " << myvector.mysize() << endl;
    //cout << "Capacity myvector : " << myvector.mycapacity() << endl;
    //myvector.erase(1);
    //myvector.erase(1, 4);
    //cout << "Size of myvector : " << myvector.mysize() << endl;
    //cout << "Capacity myvector : " << myvector.mycapacity() << endl;
    cout << endl << endl;
    myvector.insert(2, 10);
    cout << "Size of myvector : " << myvector.mysize() << endl;
    cout << "Capacity myvector : " << myvector.mycapacity() << endl;
    myvector[7] = 7;
    cout<<myvector[7]<<endl;

    const VectorClass<int>  myvector1(4, 10);

    cout << myvector1[1] << endl;

   
    /*
    vector<int> vec(4);
    vec.pop_back();
    vec.pop_back();
    vec.pop_back();
    vec.pop_back();

    cout << vec.size()<<"  "<<vec.capacity()<<endl;
     */

}

