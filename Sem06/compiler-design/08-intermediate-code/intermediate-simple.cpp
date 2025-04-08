// Not working correctly

#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

int tempVarCount = 1;

void generateCode(char op, char a, char b) {
    cout << "t" << tempVarCount << " = " << a << " " << op << " " << b << endl;
    tempVarCount++;
}

void generateIntermediateCode(string expr) {
    stack<char> operands;
    stack<char> operators;
    
    for (char ch : expr) {
        if (isalnum(ch)) {
            operands.push(ch);
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%') {
            operators.push(ch);
        }
    }
    
    while (!operators.empty()) {
        char b = operands.top(); operands.pop();
        char a = operands.top(); operands.pop();
        char op = operators.top(); operators.pop();
        generateCode(op, a, b);
        operands.push('t' + to_string(tempVarCount - 1)[0]);
    }
}

int main() {
    string expr;
    cout << "Enter an arithmetic expression: ";
    cin >> expr;
    generateIntermediateCode(expr);
    return 0;
}
