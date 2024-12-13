

#include <iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

 
class Restaurants {

public:
    Restaurants* prev;
    Restaurants* next;

    string name;
    int size=0;
    pair<string, double>* menu;

    Restaurants(string s) {
        name = s;
        menu = nullptr;
        prev = nullptr;
        next = nullptr;

    }
};

class Modification {

    Restaurants* head = nullptr;
public:
    void addRestaurants(string name) {
        Restaurants* temp = new Restaurants(name);
        if (head == nullptr) {
            head = temp;
            head->prev = head->next = head;
        }
        else {
            Restaurants* demo = head;
            while (demo->next != head) {
                demo = demo->next;
            }
            temp->next = demo->next;
            temp->prev = demo;
            demo->next = temp;
            head->prev = temp;
        }
    }

    void addMenu(string name) {
        Restaurants* demo = head;
        bool flag = true;
        while (demo->next != head) {
            if (demo->name == name) {
                cout << "Restaurants fount in the list : " << name << endl;
                flag = false;
                break;
            }
            demo = demo->next;
        }
        if (demo->name == name) {
            flag = false;
        }
        if (flag) {
            cout << "Restaurants fount not in the list : " << name << endl;
            
        }
        else {
            cout << "Enter Food Item Name To Add and Price : ";
            string s;
            double price;
            cin >> s;
            cin >> price;
            pair<string, double> item = { s,price };

            if( demo->menu == nullptr) {

                demo->menu = new pair<string, double>[demo->size + 1];
                demo->menu[demo->size] = item;
                demo->size += 1;
            }
            else {
                pair<string, double>* mm = new pair<string, double>[demo->size + 1];
                for (int i = 0; i < demo->size; i++) {
                    mm[i] = demo->menu[i];
                }
                mm[demo->size] = item;
                demo->size += 1;

                demo->menu = mm;
            }
        }
        


    }

    void deleteMenuItem(string name) {
        if (head == nullptr) {
            cout << "No restaurants available.\n";
            return;
        }
        Restaurants* demo = head;
        bool flag = true;
        while (demo->next != head) {
            if (demo->name == name) {
                cout << "Restaurants fount in the list : " << name << endl;
                flag = false;
                break;
            }
            demo = demo->next;
        }
        if (demo->name == name) {
            flag = false;
        }
        if (flag) {
            return;
        }
        cout << "Entem item No to delete: ";
        int i;
        cin >> i;
        if (i >= demo->size) {
            cout << endl << "Invalide Item No" << endl;
            return;
        }
        demo->menu[i] = demo->menu[demo->size - 1];
        demo->size -= 1;
        
    }

    void deleteRes(string name) {
        if (head == nullptr) {
            cout << "No restaurants available.\n";
            return;
        }
        Restaurants* demo = head;
        while (demo->next != head) {
            if (demo->name == name) {
                cout << "Restaurants deleted successfully" << endl;
                break;
            }
            demo = demo->next;
        }
        if (demo->name == name) {
            cout << "Restaurants deleted successfully" << endl; 
            demo->prev->next = demo->next;
            demo->next->prev = demo->prev;
            if (head->next == head) {
                head = nullptr;
            }
            else {
                delete demo;
            }
            return;
        }   
        cout << "Restaurants Not found" << endl;
    }

    Restaurants* getHead() {
        return head;
    }

    ~Modification() {
        Restaurants* temp = head;
        while (temp != nullptr) {
            head = head->next;
            delete temp;
            temp = head;
        }
        delete temp;
    }

};

class Display {

public:
    void display(Modification mdf) {
      
        Restaurants* demo = mdf.getHead();
        if (demo == nullptr) {
            cout << "Restaurant is not present " << endl;
        }
        else {
            while (demo->next != mdf.getHead()) {
                cout << endl << demo->name<<endl;
                for (int i = 0; i < demo->size; i++) {
                    cout <<i+1<<". "<< demo->menu[i].first<<"  "<< demo->menu[i].second<<endl;
                }
                demo = demo->next;
            }
            cout << endl << demo->name << endl;
            for (int i = 0; i < demo->size; i++) {
                cout << i+1 << ". " << demo->menu[i].first << "  " << demo->menu[i].second << endl;
            }
            

        }
    }


};

class ManageRes {
    Modification mdf;
    Display dsp;

public:
    void addRestaurants(string name) {
        mdf.addRestaurants(name);
    }
    void addMenu(string name) {
        mdf.addMenu(name);
    }
    void deleteItem(string name) {
        mdf.deleteMenuItem(name);
    }
    void deleteRes(string name) {
        mdf.deleteRes(name);
    }

    void displayMenu() {
        dsp.display(mdf);
    }

    Modification getObj() {
        return mdf;
    }

    pair<string, double> findItem(string name, int index) {
        Restaurants* head = mdf.getHead();
        if (head == nullptr) {
            cout << "No restaurants available.\n";
            return { "NA", 00 };
        }
        while (head->next != head) {
            if (head->name == name) {
                break;
            }
            head = head->next;
        }
        //if (head->name == name) {
        //    cout << "Restaurants fount in the list : " << name << endl;
        //}

        if (index < 0 || index >= head->size) {
            cout << "Menu index is not found"<< endl;
            return {"NA", 00};
        }
        else {
            return head->menu[index];
        }

    }
};


class User {
    vector<pair<string, double>> cart;
    ManageRes mr;
    double total;


public:
    User(ManageRes m) {
        mr = m;
    }

    void displayMenu() {
        mr.displayMenu();
    }

    void addToCart(string name, int index) {
        pair<string, double> demo = mr.findItem(name, index);
        if (demo.first != "NA") {
            cart.push_back(demo);
            total += demo.second;
        }
        
    }

    void viewCart() {
        if (cart.size() == 0) {
            cout << endl<<"Cart is Empty" << endl;
            return;
        }
        cout << endl;
        for (int i = 0; i < cart.size(); i++) {
            cout << cart[i].first << "  " << cart[i].second << endl;
        }
        cout << "Total price of Cart is : " << total << endl;
    }

    void deleteFromCart(int index) {
        if (index < 0 || index >= cart.size()) {
            cout << "Invalide Index To Delete in Cart" << endl;
            return;
        }
        total -= cart[index].second;
        cart.erase(cart.begin()+index);
    }

    void placeOrder() {
        cout << "Amout to pay : " << total<<endl;
        cout << "Item in cart is " << endl;
        viewCart();
        cout << "Your order is placed" << endl;
    }

};

int main()
{
    std::cout << "-------------  WellCome To Zomato  ---------------"<<endl<<endl;

    ManageRes mr;
    mr.addRestaurants("Dominos");
    mr.addMenu("Dominos");

    //mr.addRestaurants("Nawab");
    //mr.addMenu("Nawab");
    mr.addRestaurants("Hari Om");
    mr.addMenu("Hari Om");
    mr.addMenu("Hari Om");
 /*   mr.addRestaurants("Reddys");
    mr.addMenu("Reddys");*/
    //mr.addRestaurants("Camp Burger");
    //mr.addMenu("Camp Burger");
    mr.displayMenu();

    User ur(mr);
    ur.viewCart();
    ur.displayMenu();
    ur.addToCart("Dominos", 0);
    ur.addToCart("Hari Om", 1);
    ur.viewCart();
    ur.placeOrder();
}

