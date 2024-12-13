
#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;

class MarioGame {
    vector<vector<char>> road;
    int level;
    bool flag = true;
    int mariIndex = 0;
    bool win = true;
   

public:
    int map = 0;
    MarioGame(int level) {
        this->level = level;
        road.resize(level);
        for (int i = 0; i < level; i++) {
            cout << " Enter size of level one : ";
            int num;
            cin >> num;
            road[i].resize(num);
            cout << endl;
        }

    }

    void addMap() {
        for (int i = 0; i < level; i++) {

            for (int j = 0; j < road[i].size(); j++) {
                cout << "Enter Obstacle : ";
                char ch;
                cin >> ch;
                road[i][j] = ch;
                cout << endl;
            }
        }
    }

    void displayMap() {
        
            for (int j = 0; j < road[map].size(); j++) {
                cout << road[map][j];
                cout << " ";
            }
            cout << endl;
        
    }
    void eMove(int index) {

        if (index + 1 >= road[map].size() || index - 1 < 0) {
            cout << " Invalide Code  "<<endl;
            return;
        }

        if (flag) {
            if (road[map][index+1] == '#') {
                road[map][index] = '<';
                flag = false;
                
            }
            else {
                road[map][index] = '_';
                road[map][index+1] = '>';
                index++;
            }

        }
        else {
            if (road[map][index - 1] == '#') {
                road[map][index] = '>';
                flag = true;
                
            }
            else {
                road[map][index] = '_';
                road[map][index -1] = '<';
                index--;
            }
        }

        if (mariIndex == index) {
            cout << "-----  Sorry You Lose The Game -----" << endl;
            mariIndex = 0;
            road[map][0] = 'i';
            win = false;
        }
        
    }

    void eFind() {
        for (int i = 0; i < road[map].size(); i++) {
            if (road[map][i] == '>' || road[map][i] == '<') {
                eMove(i);
                break;
            }
        }
    }

    void moveFront() {
        eFind();
        
        if (win) {
            if (mariIndex + 1 == road[map].size()) {
                cout << "-----  Congratulation You Win The Game -----" << endl;
                road[map][mariIndex] = '_';

                mariIndex = 0;
                road[map][0] = 'i';

            }
            else {
                if (road[map][mariIndex + 1] == '>' || road[map][mariIndex + 1] == '<') {
                    cout << "-----  Sorry You Lose The Game -----" << endl;
                    road[map][mariIndex] = '_';

                    mariIndex = 0;
                    road[map][0] = 'i';
                }
                if (road[map][mariIndex + 1] == '#') {
                    cout << "-----  Cannot move Forward -----" << endl;
                }
                else {
                    road[map][mariIndex] = '_';
                    road[map][++mariIndex] = 'i';
                }
            }
        }
        else {
            win = true;
            road[map][mariIndex] = '_';
            mariIndex = 0;
            road[map][0] = 'i';
        }
        
        
    }
    void moveBack() {
        eFind();
        if (win) {
            if (mariIndex == 0 || road[map][mariIndex - 1] == '#') {
                cout << "-----  Can not Go Back  ----- " << endl;
            }
            else if (road[map][mariIndex - 1] == '<' || road[map][mariIndex - 1] == '>') {
                cout << "-----  Sorry You Lose The Game -----" << endl;
                road[map][mariIndex] = '_';

                mariIndex = 0;
                road[map][0] = 'i';
            }
            else {
                road[map][mariIndex] = '_';
                road[map][--mariIndex] = 'i';
            }
        }
        else {
            win = true;
            road[map][mariIndex] = '_';
            mariIndex = 0;
            road[map][0] = 'i';
        }
        
        
    }

    void jump() {
        eFind();


        if (mariIndex + 2 >= road[map].size() || road[map][mariIndex + 2] == '#') {
            cout << "-----  Can not Jump  ----- " << endl;
        }
        else if (road[map][mariIndex + 2] == '<' || road[map][mariIndex + 2] == '>') {
            cout << "-----  Sorry You Lose The Game -----" << endl;
            road[map][mariIndex] = '_';

            mariIndex = 0;
            road[map][0] = 'i';
        }
        else {
            road[map][mariIndex] = '_';
            road[map][mariIndex+2] = 'i';
            mariIndex += 2;
        }
        

    }
    
};

int main()
{
    std::cout <<"----------    Welcome To Mario Word    ------------"<<endl<<endl;

    int move = 1;

    MarioGame mobj(1);
    mobj.addMap();
    mobj.displayMap();
    while (move) {
        cout << endl;
        cout << "Enter your choice 1.MoveFront  2.MoveBack  3.Jump  4.Exit     :  ";

        int yourMove = 0;
        cin >> yourMove;
        switch (yourMove) {
        case 1:
            mobj.moveFront();
            mobj.displayMap();
            break;
        case 2:
            mobj.moveBack();
            mobj.displayMap();
            break;
        case 3:
            mobj.jump();
            mobj.displayMap();
            break;
        case 4:
            move = 0;
        }

    }
}

