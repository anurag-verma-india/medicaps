#include <bits/stdc++.h>
using namespace std;

class LexicalAnalyzer {
   private:
    vector<string> keywords = {
        "auto", "break", "case", "char", "const", "continue", "default",
        "do", "double", "else", "enum", "extern", "float", "for", "goto",
        "if", "int", "long", "register", "return", "short", "signed",
        "sizeof", "static", "struct", "switch", "typedef", "union",
        "unsigned", "void", "volatile", "while", "printf"};

   public:
    // Helper function to clean a word of punctuation and special characters
    string cleanWord(string word) {
        string cleanedWord = word;

        string result;
        for (char c : cleanedWord) {
            if (!ispunct(c)) {
                result += c;
            }
        }

        return result;
    }

    vector<string> analyze(string& inputString) {
        vector<string> foundKeywords;
        stringstream ss(inputString);
        string word;

        while (ss >> word) {
            // Clean the word and check if it's a keyword
            string cleaned = cleanWord(word);
            if (!cleaned.empty()) {
                if (find(keywords.begin(), keywords.end(), cleaned) != keywords.end()) {
                    foundKeywords.push_back(cleaned);
                }
            }
        }

        return foundKeywords;
    }
};

int main() {
    // Test cases to demonstrate the cleaning process
    string sourceCode = R"(void function() {
    int x = 0;
    while (x < 10) {
        if (x % 2 == 0) {
            printf("Even number");
        }
        x++;
    }
    return;
}
)";
    for (int i = 0; i < 10; i++) cout << "-";
    cout << "SOURCE CODE";
    for (int i = 0; i < 10; i++) cout << "-";
    cout << "\n";
    cout << sourceCode << "\n";

    LexicalAnalyzer analyzer;
    vector<string> found = analyzer.analyze(sourceCode);

    cout << "\nKeywords found in the source code:" << endl;
    for (const auto& keyword : found) {
        cout << "- " << keyword << endl;
    }
    cout << "Number of keywords found: " << found.size() << "\n";

    return 0;
}