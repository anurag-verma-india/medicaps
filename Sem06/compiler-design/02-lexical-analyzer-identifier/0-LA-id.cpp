#include <algorithm>
#include <iostream>
#include <set>
#include <sstream>
#include <vector>

class IdentifierAnalyzer {
   private:
    // Keywords to exclude from identifiers
    std::vector<std::string> keywords = {
        "auto", "break", "case", "char", "const", "continue", "default",
        "do", "double", "else", "enum", "extern", "float", "for", "goto",
        "if", "int", "long", "register", "return", "short", "signed",
        "sizeof", "static", "struct", "switch", "typedef", "union",
        "unsigned", "void", "volatile", "while", "printf"};

    // Check if a string is a valid identifier
    bool isValidIdentifier(const std::string& str) {
        if (str.empty()) return false;

        // First character must be letter or underscore
        if (!std::isalpha(str[0]) && str[0] != '_') return false;

        // Rest can be letters, numbers, or underscores
        return std::all_of(str.begin() + 1, str.end(),
                           [](char c) { return std::isalnum(c) || c == '_'; });
    }

    // Clean a word of punctuation and special characters
    std::string cleanWord(const std::string& word) {
        std::string result;
        bool inQuotes = false;

        for (size_t i = 0; i < word.length(); i++) {
            char c = word[i];

            // Skip string literals
            if (c == '"') inQuotes = !inQuotes;
            if (inQuotes) continue;

            // Keep alphanumeric characters and underscores
            if (std::isalnum(c) || c == '_') {
                result += c;
            }
        }
        return result;
    }

   public:
    std::set<std::string> analyze(const std::string& sourceCode) {
        std::set<std::string> identifiers;  // Using set to avoid duplicates
        std::stringstream ss(sourceCode);
        std::string word;

        while (ss >> word) {
            std::string cleaned = cleanWord(word);

            // Check if it's a valid identifier and not a keyword
            if (!cleaned.empty() &&
                isValidIdentifier(cleaned) &&
                std::find(keywords.begin(), keywords.end(), cleaned) == keywords.end()) {
                identifiers.insert(cleaned);
            }
        }

        return identifiers;
    }
};

int main() {
    // Input code
    std::string sourceCode = R"(
    void calculateSum() {
        int firstNumber = 5;
        int secondNumber = 10;
        int result = firstNumber + secondNumber;
    
        if (result > 10) {
            printf("Sum is greater than 10\n");
        }
    
        return result;
    }
    )";

    // Print source code
    std::cout << std::string(30, '-') << "SOURCE CODE"
              << std::string(30, '-') << "\n";
    std::cout << sourceCode << "\n\n";

    // Analyze the code
    IdentifierAnalyzer analyzer;
    std::set<std::string> identifiers = analyzer.analyze(sourceCode);

    // Print results
    std::cout << "Identifiers found in the source code:" << std::endl;
    for (const auto& identifier : identifiers) {
        std::cout << "- " << identifier << std::endl;
    }
    std::cout << "Number of unique identifiers found: " << identifiers.size() << "\n";

    return 0;
}