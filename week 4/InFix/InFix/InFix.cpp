#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Expression {

    string exp;

public:
    Expression(string s) {
        exp = s;
    }

    int precedance(char ch) {
        if (ch == '+' || ch == '-') return 1;
        if (ch == '*' || ch == '/') return 2;
        return 0;
    }

    double operations(int a, int b, char ch) {
        switch(ch) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        default:
            return 0;
        }
    }


    double infixResult() {
        stack<int> operants;
        stack<char> operators;

        for (int i=0; i < exp.length(); i++) {

            if (isspace(exp[i])) continue;

            if (isdigit(exp[i])) {
                int num = 0;
                while (isdigit(exp[i])) {
                    num = num * 10 + (exp[i] - '0');
                    i++;
                }
                operants.push(num);
                i--;
            }
            else if (exp[i] == '(') {
                operators.push(exp[i]);
            }
            else if (exp[i] == ')') {
                while (!operators.empty() && operators.top() != '(') {
                    int b = operants.top(); operants.pop();
                    int a = operants.top(); operants.pop();

                    operants.push(operations(a, b, operators.top())); operators.pop();
                }

                operators.pop();
            }
            else {
                while (!operators.empty() && precedance(operators.top()) >= precedance(exp[i])) {
                    int b = operants.top(); operants.pop();
                    int a = operants.top(); operants.pop();

                    operants.push(operations(a, b, operators.top())); operators.pop();
                }
                operators.push(exp[i]);
            }
        }

        while (!operators.empty()) {
            int b = operants.top(); operants.pop();
            int a = operants.top(); operants.pop();
            operants.push(operations(a, b, operators.top()));
            operators.pop();
        }

        return operants.top();
    }

};
int main() {
    string expression = "3 + 5 * ( 2*2-1)";
    cout<< "3 + 5 * ( 2*2-1)"<<endl;
    Expression ex(expression);
    cout<<ex.infixResult()<<endl;
    return 0;
}
