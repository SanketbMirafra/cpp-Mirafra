

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;




//   Product class

class Product {

private:

    string productName;
    int productId;
    int productPrice;
    int productQuantity;

public:

    Product(){
        productId = 0;
        productName = "";
        productPrice = 0;
        productQuantity = 0;
    }

    Product(string name, int price, int id, int quantity) {
        this->productName = name;
        productPrice = price;
        productId = id;
        this->productQuantity = quantity;
    }

    string getName() {
        return productName;
    }

    int getQuantity() {
        return productQuantity;
    }

    int getPrice() {
        return productPrice;
    }

    int getId() {
        return productId;
    }

    void addQuantity(int num) {

        productQuantity = productQuantity + num;
    }

    void addName(string s) {
        productName = s;
    }

    void addId(int id) {
        productId = id;
    }
    void addPrice(int price) {
        productPrice = price;
    }

    virtual ~Product(){

    }

};

//     Globle Inventory 
vector<vector<Product>> getProduct(3);

//     Add items in Inventory

void addInInventory(int id, Product pd) {

    if (getProduct[id].size() == 0) {

        getProduct[id].push_back(pd);

    }
    else {
        vector<Product> v1 = getProduct[id];
        bool flag = true;
        int i = 0;


        while (i < v1.size()) {

            if (v1[i].getId() == pd.getId()) {
                v1[i].addQuantity(pd.getQuantity());
                flag = false;
                cout << "succesfully added given quantity" << endl;
                break;
            }
            i++;
        }

        if (flag) {
            getProduct[id].push_back(pd);
            cout << "succesfully added new product" << endl;
        }

    }


}


//       Electronics Derived  Class

class Electronics : public Product{

private:
    Product pd;

public:

    Electronics(string name, int price, int id, int quantity){
        pd.addQuantity(quantity);
        pd.addId(id);
        pd.addName(name);
        pd.addPrice(price);
    }

    void addInventory() {
        addInInventory(0, pd);
    }
};


//          Clothing Derived Class

class Clothing : public Product {

private:
    Product pd;

public:

    Clothing(string name, int price, int id, int quantity){
        pd.addQuantity(quantity);
        pd.addId(id);
        pd.addName(name);
        pd.addPrice(price);
    }

    void addInventory() {
        addInInventory(1, pd);
    }
};


//      Food Derived class;

class Food : public Product {

private:
    Product pd;

public:

    Food(string name, int price, int id, int quantity){
        pd.addQuantity(quantity);
        pd.addId(id);
        pd.addName(name);
        pd.addPrice(price);
    }

    void addInventory() {
        addInInventory(2, pd);
    }
};



//   -------------------------- Payment Class -------------------------------------

class Payment {

public:
    virtual void makePayment(int a) = 0;
    virtual ~Payment() {}
};

class CreaditCard : Payment {

public:
    void makePayment(int num) override {
        cout << num << " Payment is Done";
    }
};


//      Customer Main Class

class Customer{

    int customerId;
    string customerName;
    Product pd;

public:
    vector<Product> product;

    Customer() {
        customerId = 0;
        customerName = "";
    }

    Customer(int id, string name) {
        customerId = id;
        customerName = name;
    }

    void addProduct(int id1, int id2) {
        vector<Product> v1 = getProduct[id1];
        bool flag = true;
        int i = 0;
        while (v1.size() != 0 && i < v1.size() && v1[i].getQuantity()>0) {
            if (v1[i].getId() == id2) {
                product.push_back(v1[i]);
                (getProduct[id1])[i].addQuantity(-1);
                flag = false;
            }
            i++;
        }
        if (flag) {
            cout << "Wrong Product Id TRY AGAIN" << endl;
        }
        else {
            cout << "Product Added succesfully" << endl;
        }
    }

    void shoppingCart() {
        for (int i = 0; i < product.size(); i++) {
            if (i == 0) {
                cout << "Electronics : " << endl;
                cout << product[i].getId() << " " << product[i].getName() << "     Price : " << product[i].getPrice()<< endl;
            }
            else if (i == 1) {
                cout << "Clothing :    " << endl;
                cout << product[i].getId() << " " << product[i].getName() << "     Price : " << product[i].getPrice() << endl;
            }
            else {
                cout << "Food :        " << endl;
                cout << product[i].getId() << " " << product[i].getName() << "      Price : " << product[i].getPrice() << endl;
            }
        }
    }

    void showProduct() {

        cout << customerId << "     "<<customerName<<endl<<endl;

        int i = 0;

        for ( ; i < getProduct.size(); i++) {
            int j = 0;
            while (getProduct[i].size() != 0 && j < getProduct[i].size()) {
                Product pdd = (getProduct[i])[j];
                if (i == 0) {
                    cout << "Electronics : " << endl;
                    cout << pdd.getId() << " " << pdd.getName() << "     Price : " << pdd.getPrice() << "       Quantity : " << pdd.getQuantity()<<endl;
                }
                else if(i == 1) {
                    cout << "Clothing :    " << endl;
                    cout << pdd.getId() << " " << pdd.getName() << "     Price : " << pdd.getPrice() << "        Quantity : " << pdd.getQuantity() << endl;
                }
                else{
                    cout << "Food :        " << endl;
                    cout << pdd.getId() << " " << pdd.getName() << "      Price : " << pdd.getPrice() << "       Quantity : " << pdd.getQuantity() << endl;
                }
                j++;
            }
        }
    }


    void checkout() {
        int total = 0;
        cout << customerName << "'s Final Purchase:\n";
        for (Product product1 : product) {
            cout << "Product: " << product1.getName() << " | Price: " << product1.getPrice() << endl;
            total += product1.getPrice();
        }
        cout << "Total Payment Due: " << total << endl;
        product.clear();

        cout << endl << " Enter Payment Method" << endl;
        cout << "   1.  Creadit card" << endl;

        CreaditCard cc;
        cc.makePayment(total);

    }

};





//       Main Function 

int main()
{
    std::cout << "\n";

    Electronics e1("Mobile", 10000, 123, 10);
    Clothing c1("T-Shirt", 350, 654, 6);
    Food f1("Drinks", 160, 8987, 37);

    e1.addInventory();
    c1.addInventory();
    f1.addInventory();

    Customer k1(12, "Sanket");
    cout << endl << "---------------------All product in my App--------------------" << endl;
    k1.showProduct();
    cout << endl<<"----------------------Product added in customer cart-------------------"<<endl;
    k1.addProduct(0, 123);
    cout << endl << "--------------------Customer shoppin cart---------------------"<<endl;
    k1.shoppingCart();
    cout << endl << "--------------------All product in my App---------------------"<<endl;
    k1.showProduct();
    cout << endl << "--------------------shopping cart checkout--------------------"<<endl;
    k1.checkout();



}


