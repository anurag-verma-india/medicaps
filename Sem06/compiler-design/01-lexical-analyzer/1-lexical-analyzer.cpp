#include <bits/stdc++.h>
using namespace std;

class LexicalAnalyzer {
    /*
    Gets a string as input

    Returns a vector of all the
    */
   private:
    vector<string> keywords = {
        "auto", "break", "case", "char", "const", "continue", "default",
        "do", "double", "else", "enum", "extern", "float", "for", "goto",
        "if", "int", "long", "register", "return", "short", "signed",
        "sizeof", "static", "struct", "switch", "typedef", "union",
        "unsigned", "void", "volatile", "while", "printf"};

   public:
    vector<string> analyze(string& inputString) {
    }
};

int main() {
    std::string sourceCode = R"(
int main() {
    printf("Hello world");
}
)";

    return 0;
}