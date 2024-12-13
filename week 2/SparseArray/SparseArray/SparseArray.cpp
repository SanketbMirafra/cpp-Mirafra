#include <iostream>
#include <vector>
using namespace std;

class SparseArr {
    int row;
    int col;

    vector<int> vecRow;   
    vector<int> vecCol;  
    vector<int> vecValue; 

public:

    SparseArr(int r, int c) : row(r), col(c) {}

    void addElement(int r, int c, int value) {
        if (r >= row || c >= col || r < 0 || c < 0) {
            cout << "Invalid position!\n";
            return;
        }
        if (value != 0) {
            vecRow.push_back(r);
            vecCol.push_back(c);
            vecValue.push_back(value);
        }
    }
    int getValue(int r, int c) const {
        for (size_t i = 0; i < vecRow.size(); ++i) {
            if (vecRow[i] == r && vecCol[i] == c) {
                return vecValue[i];
            }
        }
        return 0;
    }

    void displaySparse() const {
        cout << "Row\tCol\tValue\n";
        for (size_t i = 0; i < vecRow.size(); ++i) {
            cout << vecRow[i] << "\t" << vecCol[i] << "\t" << vecValue[i] << endl;
        }
    }

    void displayMatrix() const {
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                cout << getValue(i, j) << " ";
            }
            cout << endl;
        }
    }
};

int a; 

int main() {

    SparseArr sparseMatrix(3, 3);

    sparseMatrix.addElement(0, 0, 5);
    sparseMatrix.addElement(1, 2, 8);
    sparseMatrix.addElement(2, 1, 3);

    cout << "Sparse Matrix Representation:\n";
    sparseMatrix.displaySparse();

    cout << "\nFull Matrix Representation:\n";
    sparseMatrix.displayMatrix();

    cout << "\nGlobal variable 'a': " << a << endl;

    return 0;
}
