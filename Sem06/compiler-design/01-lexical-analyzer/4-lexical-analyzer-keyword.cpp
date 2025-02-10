#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

class LexicalAnalyzer {
   private:
    std::vector<std::string> keywords = {
        "auto", "break", "case", "char", "const", "continue", "default",
        "do", "double", "else", "enum", "extern", "float", "for", "goto",
        "if", "int", "long", "register", "return", "short", "signed",
        "sizeof", "static", "struct", "switch", "typedef", "union",
        "unsigned", "void", "volatile", "while", "printf"};

   public:
    // Helper function to clean a word of punctuation and special characters
    std::string cleanWord(const std::string& word) {
        std::string result;
        for (char c : word) {
            if (!std::ispunct(c)) {
                result += c;
            }
        }
        return result;
    }

    std::vector<std::string> analyze(const std::string& inputString) {
        std::vector<std::string> foundKeywords;
        std::stringstream ss(inputString);
        std::string word;

        while (ss >> word) {
            // Clean the word and check if it's a keyword
            std::string cleaned = cleanWord(word);
            if (!cleaned.empty()) {
                if (std::find(keywords.begin(), keywords.end(), cleaned) != keywords.end()) {
                    foundKeywords.push_back(cleaned);
                }
            }
        }

        return foundKeywords;
    }
};

int main(int argc, char* argv[]) {
    // Input code
    std::string sourceCode = R"(
    void function() {
        int a = 5;
        while (a > 0) {
            if (a % 2 == 0) {
                printf("Even: %d\n", a);
            } else {
                printf("Odd: %d\n", a);
            }
            a--;
        }
        return 0;
    }
)";
    std::cout << std::string(7, '-');
    std::cout << "SOURCE CODE";
    std::cout << std::string(7, '-') << "\n";
    std::cout << sourceCode << "\n";

    LexicalAnalyzer analyzer;
    std::vector<std::string> found = analyzer.analyze(sourceCode);

    std::cout << "\nKeywords found in the source code:" << std::endl;
    for (const auto& keyword : found) {
        std::cout << "- " << keyword << std::endl;
    }
    std::cout << "Number of keywords found: " << found.size() << "\n";

    return 0;
}
