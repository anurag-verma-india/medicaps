#include <bits/stdc++.h>
using namespace std;

class LexicalAnalyzer {
    /*
    Gets a string as input
    Returns a vector of all the keywords found in the input string
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
        vector<string> foundKeywords;
        stringstream ss(inputString);
        string word;

        // Helper lambda to remove punctuation from a word
        auto cleanWord = [](string& w) {
            w.erase(remove_if(w.begin(), w.end(),
                              [](char c) { return ispunct(c); }),
                    w.end());
        };

        // Process each word in the input string
        while (ss >> word) {
            // Clean the word of any punctuation
            cleanWord(word);

            // Check if the word is a keyword
            if (find(keywords.begin(), keywords.end(), word) != keywords.end()) {
                foundKeywords.push_back(word);
            }
        }

        return foundKeywords;
    }
};

int main() {
    string sourceCode = R"(
int main() {
    printf("Hello world");
}
)";

    LexicalAnalyzer analyzer;
    vector<string> found = analyzer.analyze(sourceCode);

    // Print results
    cout << "Keywords found in the source code:" << endl;
    for (const auto& keyword : found) {
        cout << "- " << keyword << endl;
    }

    // Additional test case
    //     cout << "\nTesting with another example:" << endl;
    //     string testCode = R"(
    // void function() {
    //     int x = 0;
    //     while (x < 10) {
    //         if (x % 2 == 0) {
    //             printf("Even number");
    //         }
    //         x++;
    //     }
    //     return;
    // }
    // )";
    cout << "\nTesting with another example:" << endl;
    string testCode = R"(void function() {
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

    found = analyzer.analyze(testCode);
    cout << "Keywords found in the test code:" << endl;
    for (const auto& keyword : found) {
        cout << "- " << keyword << endl;
    }

    return 0;
}