// practice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Animal {
private:
    string name;

public:
    Animal( string name) {
        this->name = name;
        cout << "Constructor is call Animal " << endl;
    }

public:

    static Animal giveObj(string name) {
        Animal animal(name);
        return animal;
    }

    string getName() {
        return name;
    }

    void printName() {
        cout << "Animal name is : " << name << endl;

    }

    /*virtual void makeSound() = 0;*/

    virtual ~Animal() {
        cout << "Animal Destructor is called" << endl;
    }
};

class Tiger : public Animal {

    string type;

public:

    Tiger(string name, string type) :Animal(name) {
        this->type = type;
        cout << "Constructor is call Tiger " << endl;
    }

    void information() {
        cout << "Name of Tiger is " << getName() << " and " << type << endl;;
    }

    /*void makeSound()*/

    ~Tiger() {
        cout << "Tiger Destructor is called"<<endl;
    }

};

void display(string s) {
    cout << "I'am globle Function" << endl;
}

int main()
{
    int* arr[3];

    for (int i = 0, j=2; i < sizeof(arr) / sizeof(arr[0]); i++, j++) {
        arr[i] = new int[j];
    }
    int num = 1;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        for (int j = 0; j < sizeof(arr[i]) / sizeof(arr[i][0]); j++) {
             
            cout << "Enter num element : " << endl;
            
            arr[i][j] = num;
            num++;
        }
    }
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        for (int j = 0; j < sizeof(arr[i]) / sizeof(arr[i][0]); j++) {

            cout <<" " << arr[i][j];
         
       
        }
    }
    /*cout << " " << arr[1][2];*/

    //std::cout << "Hello World!\n";

    //Animal animal = Animal::giveObj("Sanket");

    //Tiger* tiger = new Tiger("Vasant", "Bengal Tiger");
    /*Animal animal("Tiger");*/

    /*animal->printName();
    static_cast<Tiger*>(animal2)->information();
    delete animal;

    display();*/


   /*   -----------------------------------  Function Pointer  --------------------------------
   void(*functionDisplay)(string);
    functionDisplay = &display;
    string s;
    cout << "Enter String";
    cin >> s;
    display(s);
     ----------------------------------------- end -----------------------------------*/




      /*  -------------------------------  3D Vector  --------------------------------------

    vector<vector<vector<int>>> myvector(2, (vector<vector<int>>(3, vector<int>(3, 4))));

    for (auto v1 : myvector) {
        for (auto v2 : v1) {
            for (auto v3 : v2) {
                cout << v3 << " ";
            }
            cout << endl;
        }
        cout << endl;

    }
    cout << endl; cout << endl;
    for (auto i = myvector.begin(); i != myvector.end(); i++) {
        for (auto j = i->begin(); j != i->end(); j++) {
            for (auto z = j->begin(); z != j->end(); z++) {
                cout << *z<<" ";
           }
            cout << endl;
        }
        cout << endl;
    }
    
       ----------------------------------------- end ------------------------     */



    /*  -------------------------  2D 3D pointer array   --------------------------

    int row = 3;
    int col = 4;

    int** arr = new int*[row];

    for (int i = 0; i < row; i++) {
        arr[i] = new int[col];
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            
            arr[i][j] = i * j + j+1;
        }
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << arr[i][j] << "  ";
        }
        cout << endl;
    }


    cout << endl; cout << endl; cout << endl;

    int*** ptr = new int** [2];

    for (int i = 0; i < 2; i++) {
        ptr[i] = new int* [3];
        for (int j = 0; j < 3; j++) {
            ptr[i][j] = new int[4];
        }
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            for (int z = 0; z < 4; z++) {
                ptr[i][j][z] = i + j + z + i * j * z;
            }
        }
    }

    for (int i = 0; i < 2; i++) {
       
        for (int j = 0; j < 3; j++) {
            cout << "Memory of " << i <<"  " << j;
            cout << "                 ";
            for (int z = 0; z < 4; z++) {
                cout << ptr[i][j][z] << " ";
            }
            cout << endl;
            delete ptr[i][j];
        }
        cout << endl;
        delete ptr[i];
    }   
    cout << ptr << endl;
    delete ptr;
    cout << ptr << endl;

              --------------------------- end -----------------------   */

}
