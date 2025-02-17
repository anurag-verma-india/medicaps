#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

const char EPSILON = '#';
const char END_MARKER = '$';

struct Rule {
    char nonTerminal;
    string production;
};

class CFGCalculator {
   private:
    unordered_map<char, unordered_set<char>> firstSets;
    unordered_map<char, unordered_set<char>> followSets;
    vector<Rule> rules;
    unordered_set<char> nonTerminals;
    char startSymbol;

    bool isTerminal(char symbol) {
        return !isupper(symbol) && symbol != EPSILON && symbol != END_MARKER;
    }

    unordered_set<char> getFirstOfString(const string& str, size_t startPos = 0) {
        unordered_set<char> result;

        if (startPos >= str.length()) {
            result.insert(EPSILON);
            return result;
        }

        char symbol = str[startPos];
        if (isTerminal(symbol)) {
            result.insert(symbol);
            return result;
        }

        for (char c : firstSets[symbol]) {
            if (c != EPSILON) {
                result.insert(c);
            } else if (startPos + 1 < str.length()) {
                auto nextFirst = getFirstOfString(str, startPos + 1);
                result.insert(nextFirst.begin(), nextFirst.end());
            } else {
                result.insert(EPSILON);
            }
        }

        return result;
    }

    void calculateFirstForSymbol(char symbol) {
        if (isTerminal(symbol)) {
            firstSets[symbol].insert(symbol);
            return;
        }

        for (const Rule& rule : rules) {
            if (rule.nonTerminal != symbol) continue;

            if (rule.production.empty() || rule.production[0] == EPSILON) {
                firstSets[symbol].insert(EPSILON);
                continue;
            }

            char firstSymbol = rule.production[0];
            if (isTerminal(firstSymbol)) {
                firstSets[symbol].insert(firstSymbol);
            } else {
                if (firstSets[firstSymbol].empty()) {
                    calculateFirstForSymbol(firstSymbol);
                }
                for (char c : firstSets[firstSymbol]) {
                    firstSets[symbol].insert(c);
                }
            }
        }
    }

    void calculateFollow() {
        // Initialize FOLLOW set of start symbol with $
        followSets[startSymbol].insert(END_MARKER);

        bool changed;
        do {
            changed = false;
            for (const Rule& rule : rules) {
                char A = rule.nonTerminal;
                string production = rule.production;

                if (production.empty() || production[0] == EPSILON) continue;

                // For each symbol in the production
                for (size_t i = 0; i < production.length(); i++) {
                    char B = production[i];
                    if (!isupper(B)) continue;  // Skip terminals

                    size_t oldSize = followSets[B].size();

                    // Get everything that can come after B in this production
                    string beta = (i < production.length() - 1) ? production.substr(i + 1) : "";

                    if (beta.empty()) {
                        // If B is at the end, add FOLLOW(A) to FOLLOW(B)
                        followSets[B].insert(followSets[A].begin(), followSets[A].end());
                    } else {
                        // Add FIRST(beta) to FOLLOW(B)
                        auto firstBeta = getFirstOfString(beta);
                        for (char c : firstBeta) {
                            if (c != EPSILON) {
                                followSets[B].insert(c);
                            }
                        }

                        // If FIRST(beta) contains ε, add FOLLOW(A) to FOLLOW(B)
                        if (firstBeta.find(EPSILON) != firstBeta.end()) {
                            followSets[B].insert(followSets[A].begin(), followSets[A].end());
                        }
                    }

                    if (followSets[B].size() > oldSize) {
                        changed = true;
                    }
                }
            }
        } while (changed);
    }

   public:
    CFGCalculator(char start) : startSymbol(start) {}

    void addRule(char nonTerminal, string production) {
        rules.push_back({nonTerminal, production});
        nonTerminals.insert(nonTerminal);
    }

    void calculate() {
        // First calculate FIRST sets
        firstSets.clear();
        bool changed;
        do {
            changed = false;
            for (char nonTerminal : nonTerminals) {
                size_t oldSize = firstSets[nonTerminal].size();
                calculateFirstForSymbol(nonTerminal);
                if (firstSets[nonTerminal].size() > oldSize) {
                    changed = true;
                }
            }
        } while (changed);

        // Then calculate FOLLOW sets
        followSets.clear();
        calculateFollow();
    }

    void printSets() {
        cout << "\nFIRST Sets:\n";
        for (char nonTerminal : nonTerminals) {
            cout << "FIRST(" << nonTerminal << ") = { ";
            for (char symbol : firstSets[nonTerminal]) {
                cout << symbol << " ";
            }
            cout << "}\n";
        }

        cout << "\nFOLLOW Sets:\n";
        for (char nonTerminal : nonTerminals) {
            cout << "FOLLOW(" << nonTerminal << ") = { ";
            for (char symbol : followSets[nonTerminal]) {
                cout << symbol << " ";
            }
            cout << "}\n";
        }
    }
};

int main() {
    // Example grammar:
    // S -> AB | BC
    // A -> aA | #
    // B -> bB | #
    // C -> cC | #

    CFGCalculator cfg('S');  // S is the start symbol

    cfg.addRule('S', "AB");
    cfg.addRule('S', "BC");
    cfg.addRule('A', "aA");
    cfg.addRule('A', "#");
    cfg.addRule('B', "bB");
    cfg.addRule('B', "#");
    cfg.addRule('C', "cC");
    cfg.addRule('C', "#");

    cfg.calculate();
    cfg.printSets();

    return 0;
}