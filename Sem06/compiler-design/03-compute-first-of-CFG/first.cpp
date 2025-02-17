#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

const char EPSILON = '#';

struct Rule {
    char nonTerminal;
    string production;
};

class CFGFirstCalculator {
   private:
    unordered_map<char, unordered_set<char>> firstSets;
    vector<Rule> rules;
    unordered_set<char> nonTerminals;

    bool isTerminal(char symbol) {
        return !isupper(symbol) && symbol != EPSILON;
    }

    void calculateFirstForSymbol(char symbol) {
        if (isTerminal(symbol)) {
            firstSets[symbol].insert(symbol);
            return;
        }

        for (const Rule& rule : rules) {
            if (rule.nonTerminal != symbol) continue;

            // Handle empty production (epsilon)
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

   public:
    void addRule(char nonTerminal, string production) {
        rules.push_back({nonTerminal, production});
        nonTerminals.insert(nonTerminal);
    }

    void calculateFirst() {
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
    }

    void printFirstSets() {
        for (char nonTerminal : nonTerminals) {
            cout << "FIRST(" << nonTerminal << ") = { ";
            for (char symbol : firstSets[nonTerminal]) {
                cout << symbol << " ";  // Print the actual symbol, including '#' for epsilon
            }
            cout << "}\n";
        }
    }
};

int main() {
    CFGFirstCalculator cfg;

    // Example grammar:
    // S -> AB | #
    // A -> aA | #
    // B -> bB | #
    cfg.addRule('S', "AB");
    cfg.addRule('S', "#");
    cfg.addRule('A', "aA");
    cfg.addRule('A', "#");
    cfg.addRule('B', "bB");
    cfg.addRule('B', "#");

    cfg.calculateFirst();
    cfg.printFirstSets();

    return 0;
}