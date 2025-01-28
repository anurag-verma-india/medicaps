#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class LexicalAnalyzer {
   private:
    // List of C keywords
    std::vector<std::string> keywords = {
        "auto", "break", "case", "char", "const", "continue", "default",
        "do", "double", "else", "enum", "extern", "float", "for", "goto",
        "if", "int", "long", "register", "return", "short", "signed",
        "sizeof", "static", "struct", "switch", "typedef", "union",
        "unsigned", "void", "volatile", "while", "printf"};

    // Helper function to check if a string is a keyword
    bool isKeyword(const std::string& str) {
        return std::find(keywords.begin(), keywords.end(), str) != keywords.end();
    }
// Helper function to check if a character is part of an identifier
    bool isIdentifierChar(char c) {
        return std::isalnum(c) || c == '_';
    }

   public:
    void analyze(const std::string& input) {
        std::istringstream stream(input);
        std::string token;
        int lineNumber = 1;
        int position = 0;

        char c;
        std::string currentToken;

        while (stream.get(c)) {
            position++;

            // Handle newlines
            if (c == '\n') {
                lineNumber++;
                position = 0;
                continue;
            }

            // Skip whitespace
            if (std::isspace(c)) {
                if (!currentToken.empty()) {
                    if (isKeyword(currentToken)) {
                        std::cout << "Keyword found: " << currentToken
                                  << " at line " << lineNumber
                                  << ", position " << (position - currentToken.length())
                                  << std::endl;
                    }
                    currentToken.clear();
                }
                continue;
            }

            // Handle identifiers and keywords
            if (std::isalpha(c) || c == '_') {
                currentToken += c;
                continue;
            }

            // Check if we have a complete token when we hit a non-identifier character
            if (!currentToken.empty()) {
                if (isKeyword(currentToken)) {
                    std::cout << "Keyword found: " << currentToken
                              << " at line " << lineNumber
                              << ", position " << (position - currentToken.length())
                              << std::endl;
                }
                currentToken.clear();
            }
        }

        // Check the last token
        if (!currentToken.empty() && isKeyword(currentToken)) {
            std::cout << "Keyword found: " << currentToken
                      << " at line " << lineNumber
                      << ", position " << (position - currentToken.length())
                      << std::endl;
        }
    }
};

int main() {
    LexicalAnalyzer analyzer;

    // Example usage
    //     std::string sourceCode = R"(
    // int main() {
    //     while (true) {
    //         if (x > 0) {
    //             return 0;
    //         }
    //     }
    // }
    // )";
    std::string sourceCode = R"(
int main() {
    printf("Hello world");
}
)";

    std::cout << "Analyzing source code:\n"
              << sourceCode << std::endl;
    std::cout << "\nAnalysis results:\n";
    analyzer.analyze(sourceCode);

    return 0;
}
