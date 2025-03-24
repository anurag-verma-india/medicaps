#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <vector>

using namespace std;

map<pair<string, char>, string> parsingTable;
set<char> terminals = {'a', 'b', 'c', '$'};  // Terminals and EOF
// Function to construct the LL(1) parsing table
void constructParsingTable() {
    parsingTable[{"S", 'a'}] = "aAB";
    parsingTable[{"A", 'c'}] = "cA";
    parsingTable[{"A", 'b'}] = "@";  // A → ε(when follow(A) has 'b' or '$')
    parsingTable[{"B", 'b'}] = "b";
}
// Function to perform predictive parsing
bool predictiveParse(string input) {
    input += "$";  // Append end-of-input marker
    stack<string> parseStack;
    parseStack.push("$");
    parseStack.push("S");  // Start symbol
    size_t index = 0;
    while (!parseStack.empty()) {
        string top = parseStack.top();
        char current = input[index];
        // If top of stack is a terminal
        if (top.size() == 1 && islower(top[0])) {
            if (top[0] == current) {
                parseStack.pop();
                index++;
            } else {
                return false;  // Mismatch
            }
        }
        // If top of stack is '$' (end of stack)
        else if (top == "$") {
            return (current == '$');  // Accept if input is also at end
        }
        // If top of stack is a non-terminal
        else {
            parseStack.pop();
            if (parsingTable.count({top, current})) {
                string production = parsingTable[{top, current}];
                if (production != "@") {
                    for (int i = production.size() - 1; i >= 0; i--) {
                        parseStack.push(string(1, production[i]));
                    }
                }
            } else {
                return false;  // No valid rule, reject input
            }
        }
    }
    return false;
}

int main() {
    constructParsingTable();
    string input;
    cout << "Enter string to parse: ";
    cin >> input;
    if (predictiveParse(input)) {
        cout << "Accepted!\n";
    } else {
        cout << "Rejected!\n";
    }
    return 0;
}