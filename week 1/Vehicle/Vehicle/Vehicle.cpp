// Vehicle.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

//            Vehicle Class

class Vehicle {

    string name;
    int year;

public:
    Vehicle(string name, int year) {
        this->name = name;
        this->year = year;
        cout << "Vehicle Constructor is Call" << endl;
    }

    Vehicle(Vehicle& vehicle) {
        name = vehicle.name;
        year = vehicle.year;
        cout << "Vehicle Copy Constructor" << endl;
    }

    Vehicle& operator=(Vehicle& other) {
        if (this != &other) {
            name = other.name;
            year = other.year;
        }

        cout << "Vehicle Assignment operatoe is Call" << endl;

        return *this;
    }



    string getName() {
        return name;
    }

    int getYear() {
        return year;
    }

    void displayInfo() {
        cout << "name of vehicle is : " << name << endl;
        cout << "year : " << year << endl;
    }

    friend class Garage;
    friend void displayCondition(string s, int y);

    virtual ~Vehicle(){
        cout << "Vehicle Detructor is call " << endl;
    }

};

//           Bike class inherited Vehicle class  

class Bike : public Vehicle {

private:

    string model;

public:

    Bike(string s, string name, int year) : Vehicle(name, year) {
        model = s;
        cout << "Bike Constructor is call " << endl;
    }

    Bike(Bike& other) : Vehicle(other) {
        model = other.model;
        cout << "Bike copy constructor" << endl;
    }

    Bike& operator=(Bike& other) {
        if (this != &other) {
            model = other.model;
            Vehicle::operator=(other);
        }
        cout << "Bike Assignment operatoe is Call" << endl;
        return *this;
    }

    void bikeInfo() {
        cout << "This is Bike class bike Info ----" << endl;
        cout << "Name : " << getName()<<endl;
        cout << "Year : " << endl;
        cout << "Model : " << model << endl;
    }


    ~Bike() {
        cout << "Bike Destructor is call" << endl;
    }

};


//         Garage class

class Garage {

public:

    Garage() {
        cout << "Garage Constructor is call" << endl;
    }

    void condition(Vehicle& v1) {
        cout << "We are in friends garage class " << endl;
        cout << "Name : " << v1.name<<endl;
        cout << "Year : " << v1.year << endl;

    }
};

//       friend DisplayCondition Function

void displayCondition(string s, int y) {

    Vehicle v1(s, y);

    cout << "We are in friends displayCondition Function " << endl;
    cout << "Name : " << v1.name << endl;
    cout << "Year : " << v1.year << endl;
}


int main()
{
    Vehicle v1("bmw", 2022);
    v1.displayInfo();

    cout << endl << endl;

    Vehicle *v2 = new Bike("AQS", "Splender", 2016);
    v2->displayInfo();

    cout << endl << endl;

    cout << "Copy Vehicle Object" << endl;
    Vehicle* v3 = new Bike("AQS", "Splender", 2016);
    *v3 = *static_cast<Bike*>(v2);
    cout <<"Address at v3 : "<< v3<<endl;
    cout << "Address at v2 : " << v2 << endl;
    



    cout << endl << endl;

    Garage g1;
    g1.condition(v1);

    cout << endl << endl;

    displayCondition("Audi", 2019);

    cout << endl << endl;

    delete v2;

    cout << endl << endl;
}
