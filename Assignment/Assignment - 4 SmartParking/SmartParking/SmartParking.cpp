

#include <iostream>
#include <vector>
#include <chrono>
#include <queue>
#include <thread>
using namespace std;

class WaitingArea;

//       vehicle class
class vehicle{

public:
    double time;
    int id;
    int priority;
    string type;

    vehicle(int i, int p, string t) {
        auto now = std::chrono::system_clock::now();
        auto duration = now.time_since_epoch();
        double seconds = std::chrono::duration<double>(duration).count();
        time = seconds;
        id = i;
        priority = p;
        type = t;
    }
    
    bool operator<(const vehicle& other) const {
        return priority > other.priority;
    }
};


//     if parking is full vehicle is added in waiting area
class WaitingArea {
public:
    priority_queue<vehicle> pq;

    void addVehicleInWaiting(vehicle v) {
        pq.push(v);
    }
};


//      parking class
class ParkingSlot {
public:
    int size;
    vector<vehicle> parking;
    vector<vehicle> emgParking;
    int emgSize;
    int totalPrice = 0;
    WaitingArea w;

    ParkingSlot(int size1, int size2) {
        size = size1;
        emgSize = size2;
    }


    //        added vehicle in parking 
    void addVehicle(int i, int p, string s) {
        vehicle v(i, p, s);
        if (size == parking.size()) {

            if ((s == "Emergency" || s == "Vip") && emgSize != emgParking.size()) {
                emgParking.push_back(v);
                cout << i << "  Vehicle is added into the Emergency parking" << endl;
            }
            else {
                cout << i << "  Vehicle Parking is Full added in waiting area" << endl;
                w.addVehicleInWaiting(v);
            }

        }
        else {
            parking.push_back(v);
            cout << i << "  Vehicle is added into the parking" << endl;
        }
    }

    void removeVehicle(int id) {

        if (parking.size() == 0) return;
        int i = 0;
        bool flag = false;
        for (; i < parking.size(); i++) {
            if (id == parking[i].id) {
                flag = true;
                break;
            }
        }
        if (flag) {

            auto now = std::chrono::system_clock::now();
            auto duration = now.time_since_epoch();
            double seconds = std::chrono::duration<double>(duration).count();
            
            int value = 0;
            if (parking[i].type == "Normal") value = 20;
            else if (parking[i].type == "Vip") value = 40;
            else if (parking[i].type == "Bike") value = 10;

            totalPrice = totalPrice + value * (seconds - parking[i].time);
            parking.erase(parking.begin() + i);
            size--;
            if (!w.pq.empty()) {
                vehicle v(w.pq.top().id, w.pq.top().priority, w.pq.top().type);
                size++;
                parking.push_back(v);
                w.pq.pop();
            }

        }
        else {
            cout << "Vehicle id is not found" << endl;
        }
    }

    // removing vehicle from emergency parking area
    void removeEmg(int id) {
        if (emgParking.size() == 0) return;
        int i = 0;
        bool flag = false;
        for (; i < emgParking.size(); i++) {
            if (id == emgParking[i].id) {
                flag = true;
                break;
            }
        }

        if (flag) {
            
            if (emgParking[i].type == "Vip") {
                auto now = std::chrono::system_clock::now();
                auto duration = now.time_since_epoch();
                double seconds = std::chrono::duration<double>(duration).count();

                totalPrice = totalPrice + 40 * (seconds - parking[i].time);
                emgParking.erase(emgParking.begin() + i);
            }
            else {
                emgParking.erase(emgParking.begin() + i);
            }

            if (!w.pq.empty() && (w.pq.top().type == "Vip" || w.pq.top().type == "Emergency")) {
                addVehicle(w.pq.top().id, w.pq.top().priority, w.pq.top().type);
            }
        }
        else {
            cout << "Vehicle id is not found Emg Parking" << endl;
        }
   
    }

    void display() {
        cout << "Vehicle in Normal Parking" << endl;
        for (int i = 0; i < parking.size(); i++) {
            cout << parking[i].id << " " << parking[i].type << endl;
        }
        cout << "Vehicle in Emergency Parking" << endl;
        for (int i = 0; i < emgParking.size(); i++) {
            cout << emgParking[i].id << " " << emgParking[i].type << endl;
        }
        cout << endl;
    }

    void getTotalPrice() {
        cout << "Total Price is : " << totalPrice << endl;
    }
};


int main() {

    // there are two parking Emg and normal 
    // if normal parking is not full then emg and vip vehicle added in that
    // if normal parking is full then emg and vip vehicle added in Emg parking

    ParkingSlot ps(5, 2);
    ps.addVehicle(101, 7, "Bike");
    ps.addVehicle(102, 7, "Normal");
    ps.addVehicle(103, 7, "Normal");
    this_thread::sleep_for(std::chrono::seconds(3));

    ps.addVehicle(104, 7, "Bike");
    ps.addVehicle(105, 7, "Bike");
    ps.addVehicle(106, 3, "Vip");
    this_thread::sleep_for(std::chrono::seconds(3));
    ps.addVehicle(107, 4, "Emergency");
    ps.addVehicle(108, 1, "Vip");
    ps.display();
    ps.removeVehicle(101);
    ps.display();
    ps.getTotalPrice();
    this_thread::sleep_for(std::chrono::seconds(3));
    ps.removeVehicle(108);
    ps.removeEmg(106);
    ps.getTotalPrice();

    cout << endl;
    ps.display();

    return 0;
}