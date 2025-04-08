#include <iostream>
#include <stack>
#include <algorithm>

// Function to determine operator precedence
int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}

// Function to check if character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Convert infix to postfix
std::string infixToPostfix(const std::string& infix) {
    std::stack<char> stack;
    std::string postfix;
    
    for (char c : infix) {
        // Skip spaces
        if (c == ' ')
            continue;
        
        // If character is operand, add to output
        if (isalnum(c))
            postfix += c;
        
        // If character is '(', push to stack
        else if (c == '(')
            stack.push(c);
        
        // If character is ')', pop and add to output until matching '('
        else if (c == ')') {
            while (!stack.empty() && stack.top() != '(') {
                postfix += stack.top();
                stack.pop();
            }
            
            if (!stack.empty() && stack.top() == '(')
                stack.pop(); // Discard the '('
        }
        
        // If character is operator
        else if (isOperator(c)) {
            while (!stack.empty() && stack.top() != '(' 
                   && precedence(stack.top()) >= precedence(c)) {
                postfix += stack.top();
                stack.pop();
            }
            stack.push(c);
        }
    }
    
    // Pop remaining operators from stack
    while (!stack.empty()) {
        if (stack.top() == '(') {
            return "Invalid Expression"; // Unmatched opening bracket
        }
        postfix += stack.top();
        stack.pop();
    }
    
    return postfix;
}

// Convert infix to prefix
std::string infixToPrefix(const std::string& infix) {
    std::string reversedInfix = infix;
    std::reverse(reversedInfix.begin(), reversedInfix.end());
    
    // Replace brackets with opposite ones
    for (char& c : reversedInfix) {
        if (c == '(')
            c = ')';
        else if (c == ')')
            c = '(';
    }
    
    // Convert the reversed infix to postfix
    std::string postfix = infixToPostfix(reversedInfix);
    
    // Reverse the postfix to get the prefix
    std::reverse(postfix.begin(), postfix.end());
    return postfix;
}

int main() {
    std::string infix;
    std::cout << "Enter infix expression: ";
    std::getline(std::cin, infix);
    
    std::string prefix = infixToPrefix(infix);
    std::string postfix = infixToPostfix(infix);
    
    std::cout << "Prefix (Polish) notation: " << prefix << std::endl;
    std::cout << "Postfix (Reverse Polish) notation: " << postfix << std::endl;
    
    return 0;
}