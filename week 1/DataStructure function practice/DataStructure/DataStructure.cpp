// DataStructure.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
using namespace std;


int main()
{
    std::cout << "Hello World!\n";

    vector<int> num1;
    num1.reserve(100);
    cout << "capacity : " << num1.capacity() << "    size : " << num1.size() << endl<<endl;

    //
    vector<double> num(2);
    cout << "capacity : " << num.capacity() << "    size : " << num.size() << endl;
    num.push_back(10);
    cout << "capacity : " << num.capacity() << "    size : " << num.size() << endl;
    num.push_back(30);
    cout << "capacity : " << num.capacity() << "    size : " << num.size() << endl;
    num.push_back(20);
    cout << "capacity : " << num.capacity() << "    size : " << num.size() << endl;
    num.push_back(40);
    cout << "capacity : " << num.capacity() << "    size : " << num.size() << endl;
    num.push_back(5);
    cout << "capacity : " << num.capacity() << "    size : " << num.size() << endl;
    for (int v1 : num) {
        cout << v1 << endl;
    }

    /*num.push_back(50);
    num.insert(num.begin(), 60);*/

    /*num.resize(9);*/
    num.push_back(5);
    num.push_back(32);
    num.push_back(31);
    cout<<"capacity : "<<num.capacity()<<"    size : "<<num.size()<<endl;


    for (int v1 : num) {
        cout << v1 << endl;
    }

    num.clear();
    cout << "capacity : " << num.capacity() << "    size : " << num.size() << endl;

}

