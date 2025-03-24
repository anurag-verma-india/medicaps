// Expression -> Term | + Term }
// Term -> Factor | * Factor }
// Factor -> Number

#include <iostream>
#include <vector>
#include <sstream>

int parseFactor(const std::vector<std::string>& tokens, int& index);
int parseTerm(const std::vector<std::string>& tokens, int& index);
int parseExpression(const std::vector<std::string>& tokens, int& index);

// Factor -> Number
int parseFactor(const std::vector<std::string>& tokens, int& index) {
    int value = std::stoi(tokens[index]);
    index++;
    return value;
}

// Term -> Factor | * Factor }
int parseTerm(const std::vector<std::string>& tokens, int& index) {
    int value = parseFactor(tokens, index);
    while (index < tokens.size() && tokens[index] == "*") {
        index++;
        int factorValue = parseFactor(tokens, index);
        value *= factorValue;
    }
    return value;
}

// Expression -> Term | + Term
int parseExpression(const std::vector<std::string>& tokens, int& index) {
    int value = parseTerm(tokens, index);
    while (index < tokens.size() && tokens[index] == "+") {
        index++;
        int termValue = parseTerm(tokens, index);
        value += termValue;
    }
    return value;
}

int evaluateExpression(const std::string& expression) {
    std::vector<std::string> tokens;
    std::stringstream ss(expression);
    std::string token;
    while (ss >> token) {
        tokens.push_back(token);
    }

    int index = 0;
    return parseExpression(tokens, index);
}

int main() {
    std::string expression1 = "6 + 9 * 2";
    std::string expression2 = "42 * 5 + 5";
    std::string expression3 = "1 + 2 + 3";

    std::cout << "The result of '" << expression1 << "' is: " << evaluateExpression(expression1) << std::endl;
    std::cout << "The result of '" << expression2 << "' is: " << evaluateExpression(expression2) << std::endl;
    std::cout << "The result of '" << expression3 << "' is: " << evaluateExpression(expression3) << std::endl;

    return 0;
}