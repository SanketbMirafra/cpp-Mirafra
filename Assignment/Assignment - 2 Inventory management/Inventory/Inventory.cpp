
#include <iostream>
#include<vector>
#include <string>
using namespace std;

class Product {
public:
    string productName;
    int productQuantity;
    double productPrice;


    Product(string name, int quantity, double price) {
        productName = name;
        productQuantity = quantity;
        productPrice = price;
    }

    void display() {
        cout << productName << "  Price : " << productPrice << endl;
    }

    void reduceQuantity(int num) {
        if (num > productQuantity) {
            cout << "  Quantity of Product is Invalide"<<endl;
            return;
        }
        productQuantity -= num;
    }

};


class Inventory {
public:
    vector<vector<vector<Product>>> product;
    vector<string> itemType;
    int blockNo=0;
    int rackNo=0;

    //Inventory(int rack, int block) : rackNo(rack), blockNo(block) {
    //    product.resize(rack);
    //    for (auto p : product) {
    //        p.resize(block);
    //        for (auto p1 : p) {
    //            p1.resize(2);
    //        }
    //    }
    //}

    Inventory() {
        product.resize(3, vector<vector<Product>>(2, vector<Product>()));
        itemType = { "Electronics", "Fashion", "Food" };
    }

    void addItemType(string type) {
        itemType.push_back(type);

    }

    void addProduct() {
        cout << "Enter Product Type : " << endl;
        cout << "      1. Electronics" << endl;
        cout << "      2. Fashion" << endl;
        cout << "      3. food" << endl;
        int a;
        cin >> a;
        int b=0;
        switch (a) {
            case 1:
                cout << "Enter Product Type : " << endl;
                cout << "      1. Mobile" << endl;
                cout << "      2. Laptop" << endl;

                cin >> b;
                cout << "Enter Product Details  : Name , Quantity, Price " << endl;
                break;
            case 2:
                cout << "Enter Product Type : " << endl;
                cout << "      1. Shirt" << endl;
                cout << "      2. Shoes" << endl;

                cin >> b;
                cout << "Enter Product Details  : Name , Quantity, Price " << endl;
                break;
            case 3:
                cout << "Enter Product Type : " << endl;
                cout << "      1. Biryani" << endl;
                cout << "      2. Pizza" << endl;

                cin >> b;
                cout << "Enter Product Details  : Name , Quantity, Price " << endl;
                break;
        }
        string s;
        int d, e;
        cin >> s >> d >> e;
        product[a][b].push_back(Product(s, d, e));


    }

    void removeProduct() {
        cout << "Enter Product Type : " << endl;
        cout << "      1. Electronics" << endl;
        cout << "      2. Fashion" << endl;
        cout << "      3. food" << endl;
        int a;
        cin >> a;
        int b=0;
        switch (a) {
        case 1:
            cout << "Enter Product Type : " << endl;
            cout << "      1. Mobile" << endl;
            cout << "      2. Laptop" << endl;

            cin >> b;
            cout << "Enter Product Details  : Name , Quantity, Price " << endl;
            break;
        case 2:
            cout << "Enter Product Type : " << endl;
            cout << "      1. Shirt" << endl;
            cout << "      2. Shoes" << endl;

            cin >> b;
            cout << "Enter Product Details  : Name , Quantity, Price " << endl;
            break;
        case 3:
            cout << "Enter Product Type : " << endl;
            cout << "      1. Biryani" << endl;
            cout << "      2. Pizza" << endl;

            cin >> b;
            break;
        }
        cout << "Enter Type : " << endl;
        for (auto c : product[a][b]) {
            c.display();
        }
        int cc=0;
        cin >> cc;
        //product[a][b][cc].reduceQuantity(product[a][b][cc].productQuantity);
        auto aa= product[a][b][cc];
        
        product[a][b][cc] = product[a][b][product[a][b].size()-1];
        product[a][b].pop_back();
        
    }
    void display() {
        int i = 0;
        for (auto p1 : product) {

            for (auto p2 : p1) {
                cout << itemType[i] << endl;
                i++;
                for (auto p3 : p2) {
                    p3.display();
                }
            }
        }
    }

    void ckeckStock(){
        cout << " which product want to check in stock" << endl;
        int rack, block, item;
        cin >> rack >> block >> item;


        if (rack < 0 || block < 0 || item < 0 || rack >= product.size() || block >= product[rack].size() || item >= product[rack][block].size())
        {
            cout << " Invalide Inventory or Item  item to checkStock" << endl;
            return;
        }

        product[rack][block][item].display();
        cout << " Quantity is :  " << product[rack][block][item].productQuantity << endl;

    }

    void transferItem() {
        cout << " which product want to transfer Enter Product Information rackNo, BlockNo and ItemNO" << endl;
        int a, b, c;
        cin >> a >> b >> c;

        cout << " where to transfer Enter Product Information rackNo, BlockNo and ItemNO" << endl;
        int x, y, z;
        cin >> x >> y >> z;

        auto zzz = product[a][b][c];
        product[a][b][c] = product[x][y][z];
        product[x][y][z] = zzz;
        cout << "Product Transfer is Successfull Thank You" << endl;
    }
   
};



int main()
{
    std::cout << "----------------  D-Mart  ----------------" << endl<<endl;

    Inventory inventory;

    int a = 1;
    while (a) {

        cout << "Enter Your choice : " << endl;
        cout << "      1. Display All Product" << endl;
        cout << "      2. Add Product in Inventory" << endl;
        cout << "      3. Remove Product" << endl;
        cout << "      4. Transfer Product" << endl;
        cout << "      5. Check Stock" << endl;
        cout << "      6. Exit" << endl;
        int b;
        cin >> b;

        

        switch (b)
        {
        case 1:
            inventory.display();
            break;
        case 2:
            inventory.addProduct();
            break;
        case 3:
            inventory.removeProduct();
            break;
        case 4:
            inventory.transferItem();
            break;
        case 5:
            inventory.ckeckStock();
            break;
        case 6:
            a = 0;
            break;
        }
    }
}

