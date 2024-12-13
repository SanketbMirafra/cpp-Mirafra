

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class BookMyShow {

    int row;
    vector<int> sizeRow;
    int **seat;

public:
    BookMyShow(int row1) : row(row1){
        seat = new int*[row1];
        sizeRow.resize(row1);
    }

    void addRowSize() {
        for (int i = 0; i < sizeRow.size(); i++) {
            int num;
            cout << "Enter total seats in rows : " << endl;
            cin >> num;
            seat[i] = new int[num];
            for (int j = 0; j < num; j++) {
                seat[i][j] = 0;
            }
            sizeRow[i] = num;
        }
    }

    void showScreen() {
        cout << endl << endl;
        cout << "--------------------- Welcome to Book My Show ----------------------------\n\n";
        auto max = max_element(sizeRow.begin(), sizeRow.end());
        cout << "      ";
        cout << "- - - ";
        for (int i = 0; i < *max-6; i++) {
            cout << "$ ";
        }
        cout << "- - -"<<endl<<endl;

        for (int i = 0; i < sizeRow.size(); i++) {
            cout << "      ";
            int num = *max - sizeRow[i];

            for (int j = 0; j < num / 2; j++) {
                cout << ": ";
            }
            for (int j = 0; j < sizeRow[i]; j++) {
                cout << seat[i][j] << " ";
            }
            for (int j = 0; j < num / 2 + num % 2; j++) {
                cout << " :";
            }
            cout << endl;
        }
    }

    void bookTicket(int row, int col) {
        if (row >= sizeRow.size() || row < 0 || col >= sizeRow[row] || col < 0) {
            cout << " Invalide Seat Index " << endl;
            
        }
        else if (seat[row][col] == 1) {
            cout << " Seat Already Booked " << endl;
            
        }
        else {
            seat[row][col] = 1;

            cout << " Seat Book Successfully " << endl;
        }


    }

    ~BookMyShow() {
        for (int i = 0; i < sizeRow.size(); i++) {
            delete seat[i];
        }
        delete seat;
    }


};

int main()
{
    std::cout << "--------------------- Welcome to Book My Show ----------------------------\n\n";

    BookMyShow bs(8);
    bs.addRowSize();
    bs.showScreen();
    bs.bookTicket(1, 2);
    bs.bookTicket(3, 5);
    bs.bookTicket(4, 6);
    bs.bookTicket(6, 7);

    bs.showScreen();
}
