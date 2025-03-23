#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

// Structure to represent a production rule
struct Production {
    char nonTerminal;
    string rhs;
    Production(char nt, string r) : nonTerminal(nt), rhs(r) {}
};

class LL1Parser {
   private:
    vector<Production> productions;
    set<char> terminals;
    set<char> nonTerminals;
    map<char, set<char>> firstSets;
    map<char, set<char>> followSets;
    map<pair<char, char>, string> parsingTable;

    // Helper function to calculate FIRST set for a symbol
    set<char> calculateFirst(char symbol) {
        set<char> first;

        // If terminal, return the symbol itself
        if (terminals.find(symbol) != terminals.end() || symbol == '#') {
            first.insert(symbol);
            return first;
        }

        // For each production with this non-terminal
        for (const Production& prod : productions) {
            if (prod.nonTerminal == symbol) {
                // If empty production
                if (prod.rhs == "#") {
                    first.insert('#');
                    continue;
                }

                // Calculate FIRST for each symbol in RHS
                for (char c : prod.rhs) {
                    set<char> symbolFirst = calculateFirst(c);
                    first.insert(symbolFirst.begin(), symbolFirst.end());

                    // If symbol cannot derive empty, break
                    if (symbolFirst.find('#') == symbolFirst.end()) {
                        break;
                    }
                }
            }
        }
        return first;
    }

    // Helper function to calculate FOLLOW set
    void calculateFollow() {
        bool changed;
        // Initialize FOLLOW set of start symbol with $
        followSets[productions[0].nonTerminal].insert('$');

        do {
            changed = false;
            for (const Production& prod : productions) {
                for (size_t i = 0; i < prod.rhs.length(); i++) {
                    char current = prod.rhs[i];

                    // Skip terminals
                    if (terminals.find(current) != terminals.end()) continue;

                    set<char> toAdd;

                    // If this is the last symbol
                    if (i == prod.rhs.length() - 1) {
                        toAdd = followSets[prod.nonTerminal];
                    } else {
                        // Calculate FIRST of next symbol
                        char next = prod.rhs[i + 1];
                        set<char> firstOfNext = calculateFirst(next);

                        // Add all except epsilon
                        for (char f : firstOfNext) {
                            if (f != '#') toAdd.insert(f);
                        }

                        // If FIRST contains epsilon, add FOLLOW of LHS
                        if (firstOfNext.find('#') != firstOfNext.end()) {
                            set<char> followOfLHS = followSets[prod.nonTerminal];
                            toAdd.insert(followOfLHS.begin(), followOfLHS.end());
                        }
                    }

                    // Add new symbols to FOLLOW set
                    size_t originalSize = followSets[current].size();
                    followSets[current].insert(toAdd.begin(), toAdd.end());
                    if (followSets[current].size() > originalSize) {
                        changed = true;
                    }
                }
            }
        } while (changed);
    }

   public:
    // Function to add a production rule
    void addProduction(char nonTerminal, string rhs) {
        productions.push_back(Production(nonTerminal, rhs));
        nonTerminals.insert(nonTerminal);

        // Add all terminals from RHS
        for (char c : rhs) {
            if (isupper(c)) {
                nonTerminals.insert(c);
            } else if (c != '#') {
                terminals.insert(c);
            }
        }
    }

    // Function to construct the parsing table
    void constructParsingTable() {
        // Calculate FIRST and FOLLOW sets
        for (char nt : nonTerminals) {
            firstSets[nt] = calculateFirst(nt);
        }
        calculateFollow();

        // Construct parsing table
        for (const Production& prod : productions) {
            set<char> first = calculateFirst(prod.rhs[0]);

            // For each terminal in FIRST
            for (char t : first) {
                if (t != '#') {
                    parsingTable[{prod.nonTerminal, t}] = prod.rhs;
                }
            }

            // If epsilon is in FIRST, add production for each terminal in FOLLOW
            if (first.find('#') != first.end()) {
                for (char t : followSets[prod.nonTerminal]) {
                    parsingTable[{prod.nonTerminal, t}] = prod.rhs;
                }
            }
        }
    }

    // Function to print the parsing table with improved formatting
    void printParsingTable() {
        cout << "\nPredictive Parsing Table:\n\n";

        const int columnWidth = 8;  // Width for each column

        // Print top border
        cout << string(columnWidth, '-');
        // for (char t : terminals) {
        //     cout << "|" << string(columnWidth - 1, '-');
        // }
        for (int i = 0; i < (int)terminals.size(); i++)
            cout << "|" << string(columnWidth - 1, '-');
        cout << "|" << string(columnWidth - 1, '-') << "\n";

        // Print header
        cout << setw(columnWidth - 1) << "NT" << " ";
        for (char t : terminals) {
            cout << "| " << setw(columnWidth - 3) << t << " ";
        }
        cout << "| " << setw(columnWidth - 3) << "$" << " \n";

        // Print separator
        cout << string(columnWidth, '-');
        for (size_t i = 0; i < terminals.size() + 1; i++) {
            cout << "|" << string(columnWidth - 1, '-');
        }
        cout << "\n";

        // Print rows
        for (char nt : nonTerminals) {
            cout << setw(columnWidth - 1) << nt << " ";
            for (char t : terminals) {
                cout << "| ";
                if (parsingTable.find({nt, t}) != parsingTable.end()) {
                    cout << setw(columnWidth - 3) << parsingTable[{nt, t}] << " ";
                } else {
                    cout << setw(columnWidth - 3) << " " << " ";
                }
            }
            // Print $ column
            cout << "| ";
            if (parsingTable.find({nt, '$'}) != parsingTable.end()) {
                cout << setw(columnWidth - 3) << parsingTable[{nt, '$'}] << " ";
            } else {
                cout << setw(columnWidth - 3) << " " << " ";
            }
            cout << "\n";

            // Print separator after each row
            cout << string(columnWidth, '-');
            for (size_t i = 0; i < terminals.size() + 1; i++) {
                cout << "|" << string(columnWidth - 1, '-');
            }
            cout << "\n";
        }
    }
};

int main() {
    LL1Parser parser;

    // Example grammar:
    // E → TE'
    // E' → +TE' | ε
    // T → FT'
    // T' → *FT' | ε
    // F → (E) | id

    parser.addProduction('E', "TE'");
    parser.addProduction('E', "#");
    parser.addProduction('T', "FT'");
    parser.addProduction('F', "(E)");
    parser.addProduction('F', "i");

    parser.constructParsingTable();
    parser.printParsingTable();

    return 0;
}